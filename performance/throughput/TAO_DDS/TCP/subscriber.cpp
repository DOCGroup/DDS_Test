// -*- C++ -*-
// ============================================================================
/**
 *  @file   subscriber.cpp
 *
 *  $Id$
 *
 *
 */
// ============================================================================

#include "DataReaderListener.h"
#include "common.h"

#include "dds/DCPS/Service_Participant.h"
#include "dds/DCPS/Marked_Default_Qos.h"
#include "dds/DCPS/Qos_Helper.h"
#include "dds/DCPS/TopicDescriptionImpl.h"
#include "dds/DCPS/SubscriberImpl.h"
#include "dds/DCPS/transport/framework/EntryExit.h"

#include "../TypeNoKeyBounded/Bytes4TypeSupportImpl.h"
#include "../TypeNoKeyBounded/Bytes8TypeSupportImpl.h"
#include "../TypeNoKeyBounded/Bytes16TypeSupportImpl.h"
#include "../TypeNoKeyBounded/Bytes32TypeSupportImpl.h"
#include "../TypeNoKeyBounded/Bytes64TypeSupportImpl.h"
#include "../TypeNoKeyBounded/Bytes128TypeSupportImpl.h"
#include "../TypeNoKeyBounded/Bytes256TypeSupportImpl.h"
#include "../TypeNoKeyBounded/Bytes512TypeSupportImpl.h"
#include "../TypeNoKeyBounded/Bytes1024TypeSupportImpl.h"
#include "../TypeNoKeyBounded/Bytes2048TypeSupportImpl.h"
#include "../TypeNoKeyBounded/Bytes4096TypeSupportImpl.h"
#include "../TypeNoKeyBounded/Bytes8192TypeSupportImpl.h"
#include "../TypeNoKeyBounded/Bytes16384TypeSupportImpl.h"

#include "ace/Arg_Shifter.h"
#include "ace/Sched_Params.h"

// This can be changed to the desired value.
const int PRIORITY =
  (ACE_Sched_Params::priority_min (ACE_SCHED_FIFO)
   + ACE_Sched_Params::priority_max (ACE_SCHED_FIFO)) / 2;

// Attempt to set the real time priority and lock memory.
void
set_rt (void) 
{
  int rt_status =
    ACE_OS::sched_params (ACE_Sched_Params (ACE_SCHED_FIFO,
                                            PRIORITY,
                                            ACE_SCOPE_PROCESS));
  
  if (rt_status != 0)
    {
      if (ACE_OS::last_error () == EPERM)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "publisher (%P|%t): user is not superuser, "
                      "test runs in time-shared class\n"));
        }
      else
        {
          ACE_ERROR ((LM_ERROR,
                      "publisher (%P|%t): sched_params failed\n"));
        }
    }
}

int
parse_args (int argc, char *argv[])
{
  ACE_Arg_Shifter arg_shifter (argc, argv);
  
  arg_shifter.ignore_arg (); // ignore the command - argv[0]
  
  while (arg_shifter.is_anything_left ()) 
  {
    // options:
    // -w  <num data writers>
    // -p  <primer samples>
    // -s  <stats samples>
    // -d  <data size>
    // -a  <transport address>
    // -msi <max samples per instance>
    // -mxs <max samples>
    // -mxi <max instances>
    // -z  <verbose transport debug>

    const char *currentArg = 0;
    
    if ((currentArg = arg_shifter.get_the_parameter ("-w")) != 0) 
      {
        num_datawriters = ACE_OS::atoi (currentArg);
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-d")) != 0) 
      {
        DATA_SIZE = ACE_OS::atoi (currentArg);
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-p")) != 0) 
      {
        PRIMER_SAMPLES = ACE_OS::atoi (currentArg);
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-s")) != 0) 
      {
        STATS_SAMPLES = ACE_OS::atoi (currentArg);
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-o")) != 0)
      {
        sub_output_file = currentArg;
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-a")) != 0) 
      {
        reader_address_str = currentArg;
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-msi")) != 0) 
      {
        MAX_SAMPLES_PER_INSTANCE = ACE_OS::atoi (currentArg);
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-mxs")) != 0)
      {
        MAX_SAMPLES = ACE_OS::atoi (currentArg);
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-mxi")) != 0)
      {
        MAX_INSTANCES = ACE_OS::atoi (currentArg);
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-sd")) != 0) 
      {
        subscriber_delay_msec = ACE_OS::atoi (currentArg);
        arg_shifter.consume_arg ();
      }
    else if (arg_shifter.cur_arg_strncasecmp ("-z") == 0)
      {
        TURN_ON_VERBOSE_DEBUG;
        arg_shifter.consume_arg ();
      }
    else 
      {
        ACE_ERROR ((LM_ERROR,
                    "(%P|%t) unexpected parameter %s\n",
                    arg_shifter.get_current ()));
        arg_shifter.ignore_arg ();
        return 3;
      }
  }
  
  // Indicates sucessful parsing of the command line.
  return 0;
}

int
main (int argc, char *argv[])
{
  // Try to set real-time scheduling class. Requires login as
  // superuser or administrator.
  // set_rt ();
  
  int status = 0;

  ACE_TRY_NEW_ENV
    {
      ACE_DEBUG ((LM_INFO,
                  "%P|%t %T subscriber main\n"));

      ::DDS::DomainParticipantFactory_var dpf =
        TheParticipantFactoryWithArgs (argc, argv);

      // Let the Service_Participant (in above line)
      // strip out -DCPSxxx parameters
      // and then get application specific parameters.
      status = parse_args (argc, argv);
      
      if (status)
        {
          return status;
        }


      ::DDS::DomainParticipant_var dp = 
        dpf->create_participant (TEST_DOMAIN, 
                                 PARTICIPANT_QOS_DEFAULT, 
                                 ::DDS::DomainParticipantListener::_nil ()
                                 ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      
      if (CORBA::is_nil (dp.in ()))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("%P|%t ERROR: ")
                             ACE_TEXT ("create_participant failed.\n")),
                            1); 
        }

      DDS::ReturnCode_t ret_code = ::DDS::RETCODE_OK;

      // Register the type supports.
      switch (DATA_SIZE)
      {
      case 4:
        {
          ::Mine::Bytes4TypeSupportImpl* bytes4ts_servant =
            new ::Mine::Bytes4TypeSupportImpl ();
            
          PortableServer::ServantBase_var safe_servant =
            bytes4ts_servant;

          ::Mine::Bytes4TypeSupport_var bytes4ts = 
            TAO::DCPS::servant_to_reference<
                ::Mine::Bytes4TypeSupport
              > (bytes4ts_servant);
              
          ret_code = bytes4ts->register_type (dp.in (), TEST_TYPE);
        }
        break;
      case 8:
        {
          ::Mine::Bytes8TypeSupportImpl* bytes8ts_servant =
            new ::Mine::Bytes8TypeSupportImpl ();
            
          PortableServer::ServantBase_var safe_servant =
            bytes8ts_servant;

          ::Mine::Bytes8TypeSupport_var bytes8ts = 
            TAO::DCPS::servant_to_reference<
                ::Mine::Bytes8TypeSupport
              > (bytes8ts_servant);
              
          ret_code = bytes8ts->register_type (dp.in (), TEST_TYPE);
        }
        break;
      case 16:
        {
          ::Mine::Bytes16TypeSupportImpl* bytes16ts_servant =
            new ::Mine::Bytes16TypeSupportImpl ();
            
          PortableServer::ServantBase_var safe_servant =
            bytes16ts_servant;

          ::Mine::Bytes16TypeSupport_var bytes16ts = 
            TAO::DCPS::servant_to_reference<
                ::Mine::Bytes16TypeSupport
              > (bytes16ts_servant);
              
          ret_code = bytes16ts->register_type (dp.in (), TEST_TYPE);
        }
        break;
      case 32:
        {
          ::Mine::Bytes32TypeSupportImpl* bytes32ts_servant =
            new ::Mine::Bytes32TypeSupportImpl ();
            
          PortableServer::ServantBase_var safe_servant =
            bytes32ts_servant;

          ::Mine::Bytes32TypeSupport_var bytes32ts = 
            TAO::DCPS::servant_to_reference<
                ::Mine::Bytes32TypeSupport
              > (bytes32ts_servant);
              
          ret_code = bytes32ts->register_type (dp.in (), TEST_TYPE);
        }
        break;
      case 64:
        {
          ::Mine::Bytes64TypeSupportImpl* bytes64ts_servant =
            new ::Mine::Bytes64TypeSupportImpl ();
            
          PortableServer::ServantBase_var safe_servant =
            bytes64ts_servant;

          ::Mine::Bytes64TypeSupport_var bytes64ts = 
            TAO::DCPS::servant_to_reference<
                ::Mine::Bytes64TypeSupport
              > (bytes64ts_servant);
              
          ret_code = bytes64ts->register_type (dp.in (), TEST_TYPE);
        }
        break;
      case 128:
        {
          ::Mine::Bytes128TypeSupportImpl* bytes128ts_servant =
            new ::Mine::Bytes128TypeSupportImpl ();
            
          PortableServer::ServantBase_var safe_servant =
            bytes128ts_servant;

          ::Mine::Bytes128TypeSupport_var bytes128ts = 
            TAO::DCPS::servant_to_reference<
                ::Mine::Bytes128TypeSupport
              > (bytes128ts_servant);
              
          ret_code = bytes128ts->register_type (dp.in (), TEST_TYPE);
        }
        break;
      case 256:
        {
          ::Mine::Bytes256TypeSupportImpl* bytes256ts_servant =
            new ::Mine::Bytes256TypeSupportImpl ();
            
          PortableServer::ServantBase_var safe_servant =
            bytes256ts_servant;

          ::Mine::Bytes256TypeSupport_var bytes256ts = 
            TAO::DCPS::servant_to_reference<
                ::Mine::Bytes256TypeSupport
              > (bytes256ts_servant);
              
          ret_code = bytes256ts->register_type (dp.in (), TEST_TYPE);
        }
        break;
       case 512:
        {
          ::Mine::Bytes512TypeSupportImpl* bytes512ts_servant =
            new ::Mine::Bytes512TypeSupportImpl ();
            
          PortableServer::ServantBase_var safe_servant =
            bytes512ts_servant;

          ::Mine::Bytes512TypeSupport_var bytes512ts = 
            TAO::DCPS::servant_to_reference<
                ::Mine::Bytes512TypeSupport
              > (bytes512ts_servant);
              
          ret_code = bytes512ts->register_type (dp.in (), TEST_TYPE);
        }
        break;
      case 1024:
        {
          ::Mine::Bytes1024TypeSupportImpl* bytes1024ts_servant =
            new ::Mine::Bytes1024TypeSupportImpl ();
            
          PortableServer::ServantBase_var safe_servant =
            bytes1024ts_servant;

          ::Mine::Bytes1024TypeSupport_var bytes1024ts = 
            TAO::DCPS::servant_to_reference<
                ::Mine::Bytes1024TypeSupport
              > (bytes1024ts_servant);
              
          ret_code = bytes1024ts->register_type (dp.in (), TEST_TYPE);
        }
        break;
      case 2048:
        {
          ::Mine::Bytes2048TypeSupportImpl* bytes2048ts_servant =
            new ::Mine::Bytes2048TypeSupportImpl ();
            
          PortableServer::ServantBase_var safe_servant =
            bytes2048ts_servant;

          ::Mine::Bytes2048TypeSupport_var bytes2048ts = 
            TAO::DCPS::servant_to_reference<
                ::Mine::Bytes2048TypeSupport
              > (bytes2048ts_servant);
              
          ret_code = bytes2048ts->register_type (dp.in (), TEST_TYPE);
        }
        break;
      case 4096:
        {
          ::Mine::Bytes4096TypeSupportImpl* bytes4096ts_servant =
            new ::Mine::Bytes4096TypeSupportImpl ();
            
          PortableServer::ServantBase_var safe_servant =
            bytes4096ts_servant;

          ::Mine::Bytes4096TypeSupport_var bytes4096ts = 
            TAO::DCPS::servant_to_reference<
                ::Mine::Bytes4096TypeSupport
              > (bytes4096ts_servant);
              
          ret_code = bytes4096ts->register_type (dp.in (), TEST_TYPE);
        }
        break;
      case 8192:
        {
          ::Mine::Bytes8192TypeSupportImpl* bytes8192ts_servant =
            new ::Mine::Bytes8192TypeSupportImpl ();
            
          PortableServer::ServantBase_var safe_servant =
            bytes8192ts_servant;

          ::Mine::Bytes8192TypeSupport_var bytes8192ts = 
            TAO::DCPS::servant_to_reference<
                ::Mine::Bytes8192TypeSupport
              > (bytes8192ts_servant);
              
          ret_code = bytes8192ts->register_type (dp.in (), TEST_TYPE);
        }
        break;
      case 16384:
        {
          ::Mine::Bytes16384TypeSupportImpl* bytes16384ts_servant =
            new ::Mine::Bytes16384TypeSupportImpl ();
            
          PortableServer::ServantBase_var safe_servant =
            bytes16384ts_servant;

          ::Mine::Bytes16384TypeSupport_var bytes16384ts = 
            TAO::DCPS::servant_to_reference<
                ::Mine::Bytes16384TypeSupport
              > (bytes16384ts_servant);
              
          ret_code = bytes16384ts->register_type (dp.in (), TEST_TYPE);
        }
        break;
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("%P|%t ERROR: ")
                           ACE_TEXT ("bad data size.\n")),
                          1); 
      };

      if (::DDS::RETCODE_OK != ret_code)
        {
          ACE_ERROR_RETURN ((LM_ERROR, 
                             ACE_TEXT ("%P|%t ERROR: Failed to register ")
                             ACE_TEXT ("type support for data size %d\n"),
                             DATA_SIZE),
                            1); 
        }
              
      ::DDS::TopicQos topic_qos;
      dp->get_default_topic_qos (topic_qos);
        
//      topic_qos.resource_limits.max_samples_per_instance =
//        MAX_SAMPLES_PER_INSTANCE;
//      topic_qos.resource_limits.max_instances = MAX_INSTANCES;
//      topic_qos.resource_limits.max_samples = MAX_SAMPLES;

      topic_qos.reliability.kind = ::DDS::RELIABLE_RELIABILITY_QOS;
      topic_qos.reliability.max_blocking_time.sec = max_mili_sec_blocking / 1000;
      topic_qos.reliability.max_blocking_time.nanosec = 
        (max_mili_sec_blocking % 1000) * 1000*1000;
      topic_qos.history.kind = ::DDS::KEEP_ALL_HISTORY_QOS;

      ::DDS::Topic_var topic = 
        dp->create_topic (TEST_TOPIC, 
                          TEST_TYPE, 
                          topic_qos, 
                          ::DDS::TopicListener::_nil ()
                          ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      
      if (CORBA::is_nil (topic.in ()))
        {
          ACE_ERROR_RETURN ((LM_ERROR, 
                             ACE_TEXT ("%P|%t ERROR: Topic ")
                             ACE_TEXT ("creation failed\n")),
                            1); 
        }

      ::DDS::TopicDescription_var description =
        dp->lookup_topicdescription (TEST_TOPIC ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      
      if (CORBA::is_nil (description.in ()))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                            ACE_TEXT ("%P|%t ERROR: ")
                            ACE_TEXT ("lookup_topicdescription failed.\n")),
                            1);
        }

      // Create the subscriber.
      ::DDS::Subscriber_var sub =
        dp->create_subscriber (SUBSCRIBER_QOS_DEFAULT,
                               ::DDS::SubscriberListener::_nil ()
                               ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      
      if (CORBA::is_nil (sub.in ()))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT(" %P|%t ERROR: ")
                             ACE_TEXT ("create_subscriber failed.\n")),
                            1);
        }

      // Initialize the transport.
      if (0 != ::init_reader_tranport ())
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                            ACE_TEXT ("%P|%t ERROR: init_transport ")
                            ACE_TEXT ("failed!\n")),
                            1);
        }

      // Attach the subscriber to the transport.
      ::TAO::DCPS::SubscriberImpl* sub_impl =
        ::TAO::DCPS::reference_to_servant<
            ::TAO::DCPS::SubscriberImpl,
            ::DDS::Subscriber_ptr
          > (sub.in () ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (0 == sub_impl)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("%P|%t ERROR: Failed ")
                             ACE_TEXT ("to obtain servant ")
                             ACE_TEXT ("::TAO::DCPS::SubscriberImpl\n")),
                            1);
        }

      TAO::DCPS::AttachStatus attach_status =
        sub_impl->attach_transport (reader_transport_impl.in ());

      if (attach_status != TAO::DCPS::ATTACH_OK)
        {
          // We failed to attach to the transport for some reason.
          std::string status_str;

          switch (attach_status)
            {
              case TAO::DCPS::ATTACH_BAD_TRANSPORT:
                status_str = "ATTACH_BAD_TRANSPORT";
                break;
              case TAO::DCPS::ATTACH_ERROR:
                status_str = "ATTACH_ERROR";
                break;
              case TAO::DCPS::ATTACH_INCOMPATIBLE_QOS:
                status_str = "ATTACH_INCOMPATIBLE_QOS";
                break;
              default:
                status_str = "Unknown Status";
                break;
            }

          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("%P|%t ERROR: Failed to ")
                             ACE_TEXT ("attach to the transport. ")
                             ACE_TEXT ("AttachStatus == %s\n"),
                             status_str.c_str ()),
                            1);
        }

      // Create the Datareader.
      ::DDS::DataReaderQos dr_qos;
      sub->get_default_datareader_qos (dr_qos);
      sub->copy_from_topic_qos (dr_qos, topic_qos);
      
      dr_qos.liveliness.lease_duration.sec = 2 ;
      dr_qos.liveliness.lease_duration.nanosec = 0 ;

      DataReaderListenerImpl* dr_listener_impl =
        new DataReaderListenerImpl (num_datawriters,
                                    PRIMER_SAMPLES,
                                    STATS_SAMPLES,
                                    DATA_SIZE,
                                    sub_output_file.c_str ());

      PortableServer::ServantBase_var safe_servant = dr_listener_impl;

      ::DDS::DataReaderListener_var dr_listener = 
        TAO::DCPS::servant_to_reference<
            ::DDS::DataReaderListener
          > (dr_listener_impl);
      ACE_TRY_CHECK;
      
      if (CORBA::is_nil (dr_listener.in ()))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("%P|%t ERROR: get listener ")
                             ACE_TEXT ("reference failed.\n")),
                            1);
        }

      ::DDS::DataReader_var the_dr = 
        sub->create_datareader (description.in () ,
                                dr_qos,
                                dr_listener.in ()
                                ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      if (CORBA::is_nil (the_dr.in ()))
      {
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT ("%P|%t ERROR: ")
                           ACE_TEXT ("create_datareader failed.\n")),
                          1);
      }

      while (!dr_listener_impl->is_finished ())
        {
          ACE_OS::sleep (1);
        }

      // Clean up subscriber objects.
      sub->delete_contained_entities ();

      dp->delete_subscriber (sub.in () ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      dp->delete_topic (topic.in () ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;
      
      dpf->delete_participant (dp.in () ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      TheTransportFactory->release ();
      TheServiceParticipant->shutdown (); 

      reader_transport_impl = 0;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Exception caught in main.cpp:");
      return 1;
    }
  ACE_ENDTRY;

  return status;
}
