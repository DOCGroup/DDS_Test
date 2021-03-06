//========================================================
/**
 *
 *  @file sample_pub.cpp
 *
 *  @Id: sample_pub.cpp v1.1
 *
 */
//========================================================

#include "SubListener.h"
#include "PubMessageTypeSupportImpl.h"
#include "PubComplexMessageTypeSupportImpl.h"
#include "AckMessageTypeSupportImpl.h"

#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/PublisherImpl.h>
#include <dds/DCPS/transport/framework/TheTransportFactory.h>
#include <ace/streams.h>

#include <ace/Log_Msg.h>
#include <ace/Get_Opt.h>
#include <ace/Sched_Params.h>

CORBA::Boolean useTCP = true;
DDS::DomainId_t myDomain = 411;
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
                      "sample_sub (%P|%t): user is not superuser, "
                      "test runs in time-shared class\n"));
        }
      else
        {
          ACE_ERROR ((LM_ERROR,
                      "sample_sub (%P|%t): sched_params failed\n"));
        }
    }
}


int parse_args (int argc, char *argv[])
{
  ACE_Get_Opt getopt (argc, argv, ACE_TEXT ("t:u"));
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
                ACE_DEBUG ((LM_INFO,
                            ACE_TEXT ("subscriber: test type is byte_seq.\n")));
                TEST_TYPE = BYTE_SEQ;
              }
            else if (opt_string == "complex")
              {
                ACE_DEBUG ((LM_INFO,
                            ACE_TEXT ("subscriber: test type is complex.\n")));
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
          case 'u':
            useTCP = false;
            break;        
          default:
          break;
        }    
    }
    
  return 0;
}



// Global Variables.
const TAO::DCPS::TransportIdType TRANSPORT_IMPL_ID_1 = 1;
const TAO::DCPS::TransportIdType TRANSPORT_IMPL_ID_2 = 2;

int main (int argc, char *argv[])
{
  //Try to set realtime scheduling class.
  set_rt ();

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
                         "sample_sub: Create participant failed\n"),
                        -1);
    }

  if (parse_args (argc, argv) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "subscriber: parse_args failed.\n"),
                        -1);
    }
  
  // Create publisher.
  DDS::Publisher_var p =
    dp->create_publisher (PUBLISHER_QOS_DEFAULT,
                          DDS::PublisherListener::_nil ());
  
  // Initialize the transport for subscriber.
  TAO::DCPS::TransportImpl_rch pub_tcp_impl
           = TheTransportFactory->create_transport_impl (TRANSPORT_IMPL_ID_1,
                                                         ::TAO::DCPS::AUTO_CONFIG);


  /* Attach the transport protocol with the publishing entity */
       TAO::DCPS::PublisherImpl* p_impl =
         ::TAO::DCPS::reference_to_servant <TAO::DCPS::PublisherImpl, DDS::Publisher_ptr> (p);
       p_impl->attach_transport (pub_tcp_impl.in ());



       /* Create topic for datawriter */
       AckMessageTypeSupportImpl* ackmessage_dt = new AckMessageTypeSupportImpl;
       ackmessage_dt->register_type (dp.in (), 
                                    "DDSPerfTest::AckMessage");
       DDS::Topic_var ackmessage_topic = dp->create_topic ("ackmessage_topic", // topic name
                                                           "DDSPerfTest::AckMessage", // topic type
                                                           TOPIC_QOS_DEFAULT, 
                                                           DDS::TopicListener::_nil ());

       /* Create PubMessage data writer */
       DDS::DataWriter_var dw = p->create_datawriter (ackmessage_topic.in (),
                                                      DATAWRITER_QOS_DEFAULT,
                                                      DDS::DataWriterListener::_nil ());
       AckMessageDataWriter_var ackmessage_writer = 
         AckMessageDataWriter::_narrow (dw);
       

       /* Create the subscriber */ 
       DDS::Subscriber_var s =
         dp->create_subscriber(SUBSCRIBER_QOS_DEFAULT,
                               DDS::SubscriberListener::_nil());


  // Initialize the transport for subscriber.
  TAO::DCPS::TransportImpl_rch sub_tcp_impl  
           = TheTransportFactory->create_transport_impl (TRANSPORT_IMPL_ID_2, 
                                                         ::TAO::DCPS::AUTO_CONFIG);


  /* Attach the transport protocol with the subscribing entity */
       TAO::DCPS::SubscriberImpl* sub_impl =
         ::TAO::DCPS::reference_to_servant< TAO::DCPS::SubscriberImpl,
                               DDS::Subscriber_ptr> (s.in ());
       sub_impl->attach_transport(sub_tcp_impl.in());

  PubMessageTypeSupportImpl* pubmessage_dt = 0;
  PubComplexMessageTypeSupportImpl* pubcomplexmessage_dt = 0;
  DDS::Topic_var pubmessage_topic;
  DDS::DataReader_var dr;
  PubMessageDataReader_var pubmessage_reader;
  PubComplexMessageDataReader_var pubcomplexmessage_reader;

  // Create the listener for datareader.
  PubDataReaderListenerImpl listener_servant;
  PortableServer::POA_var poa = TheServiceParticipant->the_poa ();
  CORBA::Object_var obj = poa->servant_to_reference (&listener_servant);
  DDS::DataReaderListener_var listener =
    DDS::DataReaderListener::_narrow (obj.in ());

  switch (TEST_TYPE)
    {
      case BYTE_SEQ:
        // Create topic for datareader.
        ACE_NEW_RETURN (pubmessage_dt,
                        PubMessageTypeSupportImpl,
                        -1);
                        
        pubmessage_dt->register_type (dp.in (), 
                                      "DDSPerfTest::PubMessage");
        pubmessage_topic =
          dp->create_topic ("pubmessage_topic",
                            "DDSPerfTest::PubMessage",
                            TOPIC_QOS_DEFAULT, 
                            DDS::TopicListener::_nil ());

        // Create AckMessage datareader.
        dr =
          s->create_datareader (pubmessage_topic.in (),
                                DATAREADER_QOS_DEFAULT,
                                listener.in ());

        pubmessage_reader = 
          PubMessageDataReader::_narrow (dr.in ());
          
        break;
      case COMPLEX:
        // Create topic for datareader.
        ACE_NEW_RETURN (pubcomplexmessage_dt,
                        PubComplexMessageTypeSupportImpl,
                        -1);
                        
        pubcomplexmessage_dt->register_type (dp.in (), 
                                             "DDSPerfTest::PubComplexMessage");
        pubmessage_topic =
          dp->create_topic ("pubcomplexmessage_topic",
                            "DDSPerfTest::PubComplexMessage",
                            TOPIC_QOS_DEFAULT, 
                            DDS::TopicListener::_nil ());

        // Create AckMessage datareader.
        dr =
          s->create_datareader (pubmessage_topic.in (),
                                DATAREADER_QOS_DEFAULT,
                                listener.in ());

        pubcomplexmessage_reader = 
          PubComplexMessageDataReader::_narrow (dr.in ());
          
        break;
      default:
        break;
    }

  listener_servant.init (dr.in (), dw.in (), TEST_TYPE);

  while (!listener_servant.done ()) 
    {
      ACE_OS::sleep (1);
    };

  ACE_DEBUG ((LM_DEBUG,
              "tao_sub: shut down\n"));
  
  // Shut down domain entities.
  dp->delete_contained_entities ();
  dpf->delete_participant (dp.in ());
  TheTransportFactory->release ();
  TheServiceParticipant->shutdown ();
        
  return 0;
}
