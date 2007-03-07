//========================================================
/**
 *
 *  @file sample_pub.cpp
 *
 *  @Id: sample_pub.cpp v1.1
 *
 */
//========================================================

#include "PubListener.h"
#include "PubMessageTypeSupportImpl.h"
#include "PubComplexMessageTypeSupportImpl.h"
#include "AckMessageTypeSupportImpl.h"

#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/PublisherImpl.h>
#include <dds/DCPS/transport/framework/TheTransportFactory.h>
#include <dds/DCPS/transport/simpleTCP/SimpleTcpConfiguration.h>
#include <dds/DCPS/transport/simpleUnreliableDgram/SimpleUdpConfiguration.h>
#include <ace/streams.h>

/*
#include <dds/DCPS/transport/simpleTCP/SimpleTcpFactory.h>
#include <dds/DCPS/transport/simpleTCP/SimpleTcpConfiguration_rch.h>
#include <dds/DCPS/transport/simpleTCP/SimpleTcpConfiguration.h>
#include <dds/DCPS/transport/simpleUnreliableDgram/SimpleUdpFactory.h>
#include <dds/DCPS/transport/simpleUnreliableDgram/SimpleUnreliableDgramConfiguration_rch.h>
#include <dds/DCPS/transport/simpleUnreliableDgram/SimpleUdpConfiguration.h>
*/

#include <ace/Log_Msg.h>
#include <ace/Get_Opt.h>
#include <ace/Sched_Params.h>

const TAO::DCPS::TransportIdType UDP_TYPE_ID = 10;
const TAO::DCPS::TransportIdType UDP_IMPL_ID = 10;
const TAO::DCPS::TransportIdType TCP_TYPE_ID = 20;
const TAO::DCPS::TransportIdType TCP_IMPL_ID = 20;

CORBA::ULong seq_len = 4UL;
CORBA::ULong primer_samples = 5UL;
CORBA::ULong stats_samples = 5UL;
CORBA::Boolean useTCP = true;
DDS::DomainId_t myDomain = 411;
CORBA::String_var output_file ("results");
TestType TEST_TYPE = BYTE_SEQ;

// This can be changed to the desired value.
const int PRIORITY =
  (ACE_Sched_Params::priority_min (ACE_SCHED_FIFO)
   + ACE_Sched_Params::priority_max (ACE_SCHED_FIFO)) / 2;

// Attempt to set the real time priority and lock memory.
void set_rt (void) 
{
  if (ACE_OS::sched_params (ACE_Sched_Params (ACE_SCHED_FIFO,
                                              PRIORITY,
                                              ACE_SCOPE_PROCESS)) != 0)
    {
      if (ACE_OS::last_error () == EPERM)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "sample_pub (%P|%t): user is not superuser, "
                      "test runs in time-shared class\n"));
        }
      else
        {
          ACE_ERROR ((LM_ERROR,
                      "sample_pub (%P|%t): sched_params failed\n"));
        }
    }
}

int parse_args (int argc, char *argv[])
{
  ACE_Get_Opt getopt (argc, argv, ACE_TEXT ("t:o:i:p:s:u"));
  int c;
  ACE_CString opt_string;

  while ((c = getopt ()) != -1)
    {
      switch (c)
        {
          case 't':
            opt_string = getopt.opt_arg ();
            
            if (opt_string == "byte_seq")
              {
                TEST_TYPE = BYTE_SEQ;
              }
            else if (opt_string == "complex")
              {
                TEST_TYPE = COMPLEX;
              }
            else
              {
                ACE_ERROR_RETURN ((LM_ERROR,
                                   "no such argument \"%s\" to -t option\n",
                                   opt_string.c_str ()),
                                  -1);
              }
              
            break;
          case 'o':
            output_file = CORBA::string_dup (getopt.opt_arg ());
            break;        
          case 'i':
            stats_samples = atoi (getopt.opt_arg ());

            if (stats_samples < 1)
              {
                ACE_ERROR_RETURN ((LM_ERROR,
                                   "sample_pub: bad sample number\n"),
                                  -1);
              }
                
            break;        
          case 'p':
            primer_samples = atoi (getopt.opt_arg ());

            if (primer_samples < 1)
              {
                ACE_ERROR_RETURN ((LM_ERROR,
                                   "sample_pub: bad primer number\n"),
                                  -1);
              }
                
            break;        
          case 's':
            seq_len = atoi (getopt.opt_arg ());
        
            if (seq_len < 4)
              {
                ACE_ERROR_RETURN ((
                    LM_ERROR,
                    "sample_pub: bad message sequence length\n"),
                  -1);
              }
        
            break;
          case 'u':
            useTCP = false;
            break;        
          default: /* no parameters */
          break;
        }    
    }
    
  return 0;
}

int
main (int argc, char *argv[])
{
  // Try to set real-time scheduling class. Requires login as
  // superuser or administrator.
  // set_rt ();
  
  if (parse_args (argc, argv) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                          "sample_pub: parse_args failed\n"),
                        -1);
    }
    
  switch (TEST_TYPE)
    {
      case BYTE_SEQ:
        ACE_DEBUG ((LM_DEBUG, "# Testing byte sequence,"));
        break;
      case COMPLEX:
        ACE_DEBUG ((LM_DEBUG, "Testing complex sequence,"));
        break;
      default:
        break;
    }
    
  ACE_DEBUG ((LM_DEBUG, " length = %d\n", seq_len));
              
  // Create participant.
  DDS::DomainParticipantFactory_var dpf =
    TheParticipantFactoryWithArgs (argc, argv);

  DDS::DomainParticipant_var dp =
    dpf->create_participant (myDomain,
                             PARTICIPANT_QOS_DEFAULT, 
                             DDS::DomainParticipantListener::_nil ());
                             
  if (CORBA::is_nil (dp.in ()))
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "SAMPLE_PUB: Create participant failed\n"),
                        -1);
    }
  
  // Create publisher.
  DDS::Publisher_var p =
    dp->create_publisher (PUBLISHER_QOS_DEFAULT,
                          DDS::PublisherListener::_nil ());
  
  // Initialize the transports for publisher.
  TAO::DCPS::TransportImpl_rch pub_tcp_impl;
  
  if (useTCP) {
         TheTransportFactory->create_transport_impl (TCP_IMPL_ID, 
                                                     "SimpleTcp", 
                                                     ::TAO::DCPS::AUTO_CONFIG);
        } else {
         TheTransportFactory->create_transport_impl (UDP_IMPL_ID, 
                                                     "SimpleUdp", 
                                                     TAO::DCPS::DONT_AUTO_CONFIG);
         TAO::DCPS::TransportConfiguration_rch config 
           = TheTransportFactory->create_configuration (UDP_IMPL_ID, "SimpleUdp");

         TAO::DCPS::SimpleUdpConfiguration* udp_config 
           = static_cast <TAO::DCPS::SimpleUdpConfiguration*> (config.in ());

         std::string addrStr(ACE_LOCALHOST);
         addrStr += ":1234";
         udp_config->local_address_.set(addrStr.c_str());
         pub_tcp_impl->configure (config.in ());
       }

  
  /* Attach the transport protocol with the publishing entity */
       TAO::DCPS::PublisherImpl* p_impl =
         ::TAO::DCPS::reference_to_servant <TAO::DCPS::PublisherImpl, DDS::Publisher_ptr> (p);
       p_impl->attach_transport (pub_tcp_impl.in ());


  PubMessageTypeSupportImpl *pubmessage_dt = 0;
  PubComplexMessageTypeSupportImpl *pubcomplexmessage_dt = 0;
  DDS::Topic_var pubmessage_topic;
  DDS::DataWriter_var dw;
  PubMessageDataWriter_var pubmessage_writer;
  PubComplexMessageDataWriter_var pubcomplexmessage_writer;
  
  // Create topic for datawriter.
  switch (TEST_TYPE)
    {
      case BYTE_SEQ:
        ACE_NEW_RETURN (pubmessage_dt,
                        PubMessageTypeSupportImpl,
                        -1);
                        
        pubmessage_dt->register_type (dp.in (), 
                                      "DDSPerfTest::PubMessage");
        pubmessage_topic =
          dp->create_topic ("pubmessage_topic", // topic name
                            "DDSPerfTest::PubMessage", // topic type
                            TOPIC_QOS_DEFAULT, 
                            DDS::TopicListener::_nil ());

        // Create PubMessage datawriter.
        dw =
          p->create_datawriter (pubmessage_topic.in (),
                                DATAWRITER_QOS_DEFAULT,
                                DDS::DataWriterListener::_nil ());
                                
        pubmessage_writer = 
          PubMessageDataWriter::_narrow (dw.in ());
          
        break;
      case COMPLEX:
        ACE_NEW_RETURN (pubcomplexmessage_dt,
                        PubComplexMessageTypeSupportImpl,
                        -1);
                      
        pubcomplexmessage_dt->register_type (
            dp.in (), 
            "DDSPerfTest::PubComplexMessage"
          );
        pubmessage_topic =
          dp->create_topic ("pubcomplexmessage_topic",
                            "DDSPerfTest::PubComplexMessage",
                            TOPIC_QOS_DEFAULT, 
                            DDS::TopicListener::_nil ());

        // Create PubComplexMessage datawriter.
        dw =
          p->create_datawriter (pubmessage_topic.in (),
                                DATAWRITER_QOS_DEFAULT,
                                DDS::DataWriterListener::_nil ());
                                
        pubcomplexmessage_writer = 
          PubComplexMessageDataWriter::_narrow (dw.in ());
          
        break;
      default:
        break;
}
  
  // Create the subscriber.
  DDS::Subscriber_var s =
    dp->create_subscriber (SUBSCRIBER_QOS_DEFAULT,
                           DDS::SubscriberListener::_nil ());

  // Initialize the transport for subscriber.
  TAO::DCPS::TransportImpl_rch sub_tcp_impl;
  
  if (useTCP) {
         sub_tcp_impl 
           = TheTransportFactory->create_transport_impl (TCP_IMPL_ID+1, 
                                                         "SimpleTcp", 
                                                         ::TAO::DCPS::AUTO_CONFIG);
       } else {
         sub_tcp_impl 
           = TheTransportFactory->create_transport_impl(UDP_IMPL_ID+1, 
                                                        "SimpleUdp", 
                                                        TAO::DCPS::DONT_AUTO_CONFIG);
         TAO::DCPS::TransportConfiguration_rch config 
           = TheTransportFactory->create_configuration (UDP_IMPL_ID+1, "SimpleUdp");

         TAO::DCPS::SimpleUdpConfiguration* udp_config 
           = static_cast <TAO::DCPS::SimpleUdpConfiguration*> (config.in ());

         std::string addrStr(ACE_LOCALHOST);
         addrStr += ":1235";

         udp_config->local_address_.set(addrStr.c_str ());
         sub_tcp_impl->configure(config.in());
       }

  /* Attach the transport protocol with the subscribing entity */
       TAO::DCPS::SubscriberImpl* sub_impl =
         ::TAO::DCPS::reference_to_servant< TAO::DCPS::SubscriberImpl,
                                            DDS::Subscriber_ptr> (s.in ());
       sub_impl->attach_transport(sub_tcp_impl.in());

  // Create topic for datareader.
  AckMessageTypeSupportImpl* ackmessage_dt = 0;
  ACE_NEW_RETURN (ackmessage_dt,
                  AckMessageTypeSupportImpl,
                  -1);
                  
  ackmessage_dt->register_type (dp.in (), 
                                "DDSPerfTest::AckMessage");
  DDS::Topic_var ackmessage_topic =
    dp->create_topic ("ackmessage_topic", // topic name
                      "DDSPerfTest::AckMessage", // topic type
                      TOPIC_QOS_DEFAULT, 
                      DDS::TopicListener::_nil ());

  // Create the listener for datareader.
  AckDataReaderListenerImpl listener_servant (seq_len,
                                              primer_samples,
                                              stats_samples,
                                              output_file.in (),
                                              TEST_TYPE);
  PortableServer::POA_var poa = TheServiceParticipant->the_poa ();
  CORBA::Object_var obj = poa->servant_to_reference (&listener_servant);
  DDS::DataReaderListener_var listener =
    DDS::DataReaderListener::_narrow (obj.in ());

  // Create AckMessage datareader.
  DDS::DataReader_var dr =
    s->create_datareader (ackmessage_topic.in (),
                          DATAREADER_QOS_DEFAULT,
                          listener.in ());

  listener_servant.init (dr.in (), dw.in (), TEST_TYPE);

  // Sleep here to wait for the connections.
  ACE_OS::sleep(1);

  AckMessageDataReader_var ackmessage_reader = 
    AckMessageDataReader::_narrow (dr.in ());
    
  DDS::InstanceHandle_t handle;

  switch (TEST_TYPE)
    {
      case BYTE_SEQ:
        {
          DDSPerfTest::PubMessage pubmessage_data;
          pubmessage_data.seqnum = 1;
          pubmessage_data.data.length (seq_len);

          handle =
            pubmessage_writer->_cxx_register (pubmessage_data);

          pubmessage_writer->write (pubmessage_data,
                                    handle);
                                    
          break;
        }
      case COMPLEX:
        {
          DDSPerfTest::PubComplexMessage pubcomplexmessage_data;
          pubcomplexmessage_data.seqnum = 1;
          pubcomplexmessage_data.data.length (seq_len);
          
          for (CORBA::ULong i = 0; i < seq_len; ++i)
            {
              pubcomplexmessage_data.data[i].length = 1;
              pubcomplexmessage_data.data[i].nested_member.length (1UL);
              pubcomplexmessage_data.data[i].nested_member[0UL].info = "nestinfo";
              pubcomplexmessage_data.data[i].nested_member[0UL].index = -1;
            }

          handle =
            pubcomplexmessage_writer->_cxx_register (pubcomplexmessage_data);

          pubcomplexmessage_writer->write (pubcomplexmessage_data,
                                           handle);
                                    
          break;
        }
      default:
        break;
    }

  while (listener_servant.done () == 0) 
    {
      ACE_OS::sleep (1);
    };

  // Shut down domain entities.
  ACE_DEBUG ((LM_DEBUG, "Publisher: shut down\n"));
  dp->delete_contained_entities ();
  dpf->delete_participant (dp.in ());
  TheTransportFactory->release ();
  TheServiceParticipant->shutdown ();
  
  return 0;
}
