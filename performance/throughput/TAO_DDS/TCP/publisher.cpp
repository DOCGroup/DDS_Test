// -*- C++ -*-
// ============================================================================
/**
 *  @file   publisher.cpp
 *
 *  $Id$
 *
 *
 */
// ============================================================================

#include "Writer.h"
#include "common.h"
#include "dds_config_file.h"

#include "dds/DCPS/Service_Participant.h"
#include "dds/DCPS/Marked_Default_Qos.h"
#include "dds/DCPS/Qos_Helper.h"
#include "dds/DCPS/PublisherImpl.h"
#include "dds/DCPS/transport/framework/EntryExit.h"

#include "BytesTypeSupportImpl.h"
#include "ComplexTypeSupportImpl.h"

#include "ace/Arg_Shifter.h"
#include "ace/Sched_Params.h"

ACE_Recursive_Thread_Mutex done_lock_;
ACE_Condition<ACE_Recursive_Thread_Mutex> done_condition_(done_lock_);

/* QoS settings */
bool isReliable = false;
bool QoS_KEEP_ALL = false;
bool usingUdp = false;
// Multiplier used for oversampling when using UDP
// Using precedence from NDDS.
const int OVERSAMPLEMULTIPLIER = 31;


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

/// parse the command line arguments
int
parse_args (int argc, char *argv[])
{
  ACE_Arg_Shifter arg_shifter (argc, argv);
  
  arg_shifter.ignore_arg (); // ignore the command - argv[0]
  
  while (arg_shifter.is_anything_left ()) 
  {
    // options:
    // -p  <num data writers>
    // -r  <num data readers>
    // -i  <data writer id>
    // -n  <network setting files>
    // -d  <data size>
    // -a  <transport address>
    // -t  <max blocking timeout in miliseconds>
    // -msi <max samples per instance>
    // -mxs <max samples>
    // -mxi <max instances>
    // -z  <verbose transport debug>

    const char *currentArg = 0;
   
    std::cerr << "Evaluating parameter (" << arg_shifter.get_current() <<
                 ")\n";
   
    //if ((currentArg = arg_shifter.get_the_parameter ("-w")) != 0) 
    //{
    //  num_datawriters = ACE_OS::atoi (currentArg);
    //  arg_shifter.consume_arg ();
    //}      
    //    else if ((currentArg = arg_shifter.get_the_parameter ("-r")) != 0) 
    // {
    //   num_datareaders = ACE_OS::atoi (currentArg);
    //   arg_shifter.consume_arg ();
    // }
    if ((currentArg = arg_shifter.get_the_parameter ("-d")) != 0) 
      {
        DATA_SIZE = ACE_OS::atoi (currentArg);
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-sub")) != 0)
      {
        num_datareaders = ACE_OS::atoi (currentArg);
        arg_shifter.consume_arg ();
      }
    else if (arg_shifter.cur_arg_strncasecmp ("-udp") == 0)
      {
        std::cerr << "UDP being used.\n";
        usingUdp = true;
        arg_shifter.consume_arg ();
      } 

    else if ((currentArg = arg_shifter.get_the_parameter ("-reliable")) != 0)
      {
        isReliable = true;
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-keep_all")) != 0)
      {
        QoS_KEEP_ALL = true;
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-p")) != 0) 
      {
        PRIMER_SAMPLES = ACE_OS::atoi (currentArg);
        std::cerr << "Processing -p (" << PRIMER_SAMPLES << " )...\n";

        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-s")) != 0) 
      {
        STATS_SAMPLES = ACE_OS::atoi (currentArg);

        std::cerr << "Processing -s (" << STATS_SAMPLES << " )...\n";
    std::cerr << "Next before consume (" << arg_shifter.get_current() <<
                     ")\n";

        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-a")) != 0) 
      {
        writer_address_str = currentArg;
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
    else if ((currentArg = arg_shifter.get_the_parameter ("-i")) != 0) 
      {
        id = ACE_OS::atoi (currentArg);
        std::cerr << "Processing -i (" << id << ")\n";
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-r")) != 0)
      {
        pub_output_file = currentArg;
        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-top")) != 0)
      {
        test_topic_name = currentArg;

        //DDS_Config_File config (network_config_file.c_str ());

        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-n")) != 0)
      {
        network_config_file = currentArg;

        //DDS_Config_File config (network_config_file.c_str ());

        arg_shifter.consume_arg ();
      }
    else if ((currentArg = arg_shifter.get_the_parameter ("-q")) != 0)
      {
        qos_config_file = currentArg;
        arg_shifter.consume_arg ();
      }

    else if ((currentArg = arg_shifter.get_the_parameter ("-t")) != 0) 
      {
        max_mili_sec_blocking = ACE_OS::atoi (currentArg);
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
                    arg_shifter.get_current()));
        arg_shifter.ignore_arg ();
        return 3;
      }
  }
  // Indicates sucessful parsing of the command line
  return 0;
}

int
main (int argc, char *argv[])
{
  // Try to set real-time scheduling class. Requires login as
  // superuser or administrator.
  //set_rt ();
  
  int status = 0;

  try
    {
      ::DDS::DomainParticipantFactory_var dpf =
        TheParticipantFactoryWithArgs (argc, argv);

      // let the Service_Participant (in above line) strip out
      // -DCPSxxx parameters and then get application specific parameters.
      status = parse_args (argc, argv);
      
      if (0 != status)
        {
          return status;
        }

      ::DDS::DomainParticipant_var dp = 
        dpf->create_participant (TEST_DOMAIN, 
                                 PARTICIPANT_QOS_DEFAULT, 
                                 ::DDS::DomainParticipantListener::_nil ());

      if (CORBA::is_nil (dp.in ()))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("%P|%t ERROR: create_participant ")
                             ACE_TEXT ("failed.\n")),
                            1);
        }

      DDS::ReturnCode_t ret_code = ::DDS::RETCODE_OK;

      BytesTypeSupportImpl* bytes_ts_servant =
        new BytesTypeSupportImpl ();
        
      PortableServer::ServantBase_var safe_servant =
        bytes_ts_servant;

      BytesTypeSupport_var bytes_ts = 
        TAO::DCPS::servant_to_reference_2<BytesTypeSupport> (
          bytes_ts_servant);
      
      ret_code = bytes_ts->register_type (dp.in (), TEST_TYPE);

      if (::DDS::RETCODE_OK != ret_code)
        {
          ACE_ERROR_RETURN ((LM_ERROR, 
                             ACE_TEXT ("%P|%t ERROR: Failed to register ")
                             ACE_TEXT ("type support.")
                             ACE_TEXT ("for data size %d\n"),
                             DATA_SIZE),
                            1);
        }

      ::DDS::TopicQos topic_qos
;
      dp->get_default_topic_qos (topic_qos);

      topic_qos.resource_limits.max_samples_per_instance =
        MAX_SAMPLES_PER_INSTANCE;
      topic_qos.resource_limits.max_instances = MAX_INSTANCES;
      topic_qos.resource_limits.max_samples = MAX_SAMPLES;

      if (isReliable)
        {
      
          topic_qos.reliability.kind = ::DDS::RELIABLE_RELIABILITY_QOS;
          topic_qos.reliability.max_blocking_time.sec = max_mili_sec_blocking / 1000;
      
          topic_qos.reliability.max_blocking_time.nanosec = 
            (max_mili_sec_blocking % 1000) * 1000*1000;
        }
      else
        {
          topic_qos.reliability.kind = ::DDS::BEST_EFFORT_RELIABILITY_QOS;          
        }

      if (QoS_KEEP_ALL)
        {
          topic_qos.history.kind = ::DDS::KEEP_ALL_HISTORY_QOS;
        }

      ::DDS::Topic_var topic = 
      dp->create_topic (test_topic_name.c_str (), 
                            TEST_TYPE, 
                            topic_qos, 
                            ::DDS::TopicListener::_nil ());

      ACE_DEBUG ((LM_DEBUG, "(%P|%t)The current topic is %s\n",
         test_topic_name.c_str()));
     
      if (CORBA::is_nil (topic.in ()))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("%P|%t ERROR: ")
                             ACE_TEXT ("create_topic failed.\n")),
                            1);
        }

      // Create the publisher
      ::DDS::Publisher_var pub =
        dp->create_publisher (PUBLISHER_QOS_DEFAULT,
                              ::DDS::PublisherListener::_nil ());
      
      if (CORBA::is_nil (pub.in ()))
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("%P|%t ERROR: ")
                             ACE_TEXT ("create_publisher failed.\n")),
                            1);
        }

      // Initialize the transport
      if (0 != ::init_writer_tranport ())
      {
        ACE_ERROR_RETURN ((LM_ERROR,
                           ACE_TEXT("%P|%t ERROR: ")
                           ACE_TEXT ("init_transport failed!\n")),
                          1);
      }

      // Attach the publisher to the transport.
      ::TAO::DCPS::PublisherImpl* pub_impl =
        ::TAO::DCPS::reference_to_servant< ::TAO::DCPS::PublisherImpl,
                                           ::DDS::Publisher_ptr> (
          pub.in ());

      if (0 == pub_impl)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             ACE_TEXT ("%P|%t ERROR: Failed ")
                             ACE_TEXT ("to obtain servant ")
                             ACE_TEXT ("::TAO::DCPS::PublisherImpl\n")),
                            1);
        }

      TAO::DCPS::AttachStatus attach_status =
        pub_impl->attach_transport (writer_transport_impl.in ());

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
                             status_str.c_str()),
                            1);
        }

      // Create the datawriters
      ::DDS::DataWriterQos dw_qos;
      pub->get_default_datawriter_qos (dw_qos);
      pub->copy_from_topic_qos (dw_qos, topic_qos);

      ::DDS::DataWriter_var * dws =
        new ::DDS::DataWriter_var[num_datawriters];

      // Create one or multiple datawriters belonging to the same 
      // publisher.
      for (int k = 0; k < num_datawriters; ++k)
        {
          dws[k] = pub->create_datawriter (topic.in () ,
                                          dw_qos,
                                          ::DDS::DataWriterListener::_nil ());

          if (CORBA::is_nil (dws[k].in ()))
            {
              ACE_ERROR_RETURN ((LM_ERROR,
                                ACE_TEXT ("%P|%t ERROR: ")
                                ACE_TEXT ("create_datawriter failed.\n")),
                                1);
            }
        }

      Writer** writers = new Writer* [num_datawriters] ;

      // If we're using UDP then oversend the number of samples
      if (usingUdp)
      {
        // Using the precedence here from NDDS publisher for determining
        // oversampling value.
        STATS_SAMPLES = (STATS_SAMPLES + PRIMER_SAMPLES) * OVERSAMPLEMULTIPLIER;
      }

      for (int p = 0; p < num_datawriters; ++p)
        {
          writers[p] = new Writer (dws[p].in (),
                                   pub_output_file.c_str (),
                                   PRIMER_SAMPLES,
                                   STATS_SAMPLES,
                                   DATA_SIZE,
                                   num_datareaders,
                                   id + p); 
          writers[p]->start ();
        }


      bool writers_finished = false;

      while (!writers_finished)
        {
          ACE_Guard<ACE_Recursive_Thread_Mutex> just_me (done_lock_);
          
          // wait for a writer to signal so we done spin
          // waiting to see if the publisher is done.
          done_condition_.wait ();
          writers_finished = true;
          
          for (int m = 0; m < num_datawriters; ++m)
            {
              writers_finished =
                writers_finished && writers[m]->is_finished ();
            }
        }
        
      ACE_OS::sleep (1);
        
      // Clean up publisher objects
      pub->delete_contained_entities ();

      delete [] dws;

      for (int q = 0; q < num_datawriters; ++q)
        {
          delete writers[q];
        }

      delete [] writers;

      dp->delete_publisher (pub.in ());     
      dp->delete_topic (topic.in ());      
      dpf->delete_participant (dp.in ());

      ACE_OS::sleep (2);
      TheTransportFactory->release ();

      TheServiceParticipant->shutdown (); 

      writer_transport_impl = 0;
    }
  catch (CORBA::Exception &ex)
    {
      ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                           "Exception caught in main.cpp:");
      return 1;
    }

  return status;
}
