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
#include "QuoterTypeSupportImpl.h"
#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/SubscriberImpl.h>
#include <dds/DCPS/transport/framework/TheTransportFactory.h>
#include <dds/DCPS/transport/simpleTCP/SimpleTcpConfiguration.h>
#include <ace/streams.h>

const TAO::DCPS::TransportIdType TCP_IMPL_ID = 0;
const char* pub_ready_filename    = "publisher_ready.txt";
const char* pub_finished_filename = "publisher_finished.txt";
const char* sub_ready_filename    = "subscriber_ready.txt";
const char* sub_finished_filename = "subscriber_finished.txt";
const char *reader_address_str    = "default";


int main (int argc, char *argv[])
{
  const int domainId = 411;
  const char *topicName = "Stock Quotes";

  try {
    DDS::DomainParticipantFactory_var dpf;
    DDS::DomainParticipant_var participant;

    dpf = TheParticipantFactoryWithArgs(argc, argv);

    // To Do: Create the participant
    participant =
      dpf->create_participant(domainId,
                              PARTICIPANT_QOS_DEFAULT,
                              DDS::DomainParticipantListener::_nil());
    if (CORBA::is_nil (participant.in ())) {
      cerr << "create_participant failed." << endl;
      return 1 ;
    }
    // End: Create the participant

    QuoterTypeSupportImpl* servant = new QuoterTypeSupportImpl();
    PortableServer::ServantBase_var safe_servant = servant;

    // To Do: Register the type
    if (DDS::RETCODE_OK != servant->register_type(participant.in (),
                                                      "")) {
      cerr << "Failed to register the QuoterTypeTypeSupport." << endl;
      exit(1);
    }
    // End: Register the type

    CORBA::String_var type_name = servant->get_type_name ();

    // To Do: Get the (default) topic QoS and create the topic
    DDS::TopicQos topic_qos;
    participant->get_default_topic_qos(topic_qos);
    DDS::Topic_var topic =
      participant->create_topic(topicName,
                                type_name.in (),
                                topic_qos,
                                DDS::TopicListener::_nil());
    if (CORBA::is_nil (topic.in ())) {
      cerr << "Failed to create_topic." << endl;
      exit(1);
    }
    // End: Get the (default) topic QoS and create the topic
    
    // To Do: Create the subscriber
    DDS::Subscriber_var sub =
      participant->create_subscriber(SUBSCRIBER_QOS_DEFAULT,
                                     DDS::SubscriberListener::_nil());
    if (CORBA::is_nil (sub.in ())) {
      cerr << "Failed to create_subscriber." << endl;
      exit(1);
    }
    // End: Create the subscriber

    // jhoffert
    // There seem to be problems using auto configurations with an application
    // distributed across different nodes. Take this out for now.

    // Initialize the transport
    TAO::DCPS::TransportImpl_rch tcp_impl =
      TheTransportFactory->create_transport_impl (TCP_IMPL_ID,
                                                  //::TAO::DCPS::AUTO_CONFIG);
                                                  ::TAO::DCPS::DONT_AUTO_CONFIG);
    TAO::DCPS::TransportConfiguration_rch reader_config =
      //TheTransportFactory->get_configuration (SUB_TRAFFIC);
      TheTransportFactory->get_configuration (TCP_IMPL_ID);

    TAO::DCPS::SimpleTcpConfiguration* reader_tcp_config =
      static_cast <TAO::DCPS::SimpleTcpConfiguration*> (reader_config.in ());

    if (0 != ACE_OS::strcmp ("default", reader_address_str)) {
      ACE_INET_Addr reader_address (reader_address_str);
      reader_tcp_config->local_address_ = reader_address;
    }

    if (0 != tcp_impl->configure (reader_config.in ())) {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT("(%P|%t) ::main: ")
                  ACE_TEXT("Failed to configure the transport.\n")));
      exit(1);
    }
    // jhoffert - End of transport configuration changes

    // Attach the subscriber to the transport.
    TAO::DCPS::SubscriberImpl* sub_impl =
      ::TAO::DCPS::reference_to_servant< TAO::DCPS::SubscriberImpl,
                                         DDS::Subscriber_ptr> (sub.in ());
    if (0 == sub_impl) {
      cerr << "Failed to obtain subscriber servant\n" << endl;
      exit(1);
    }

    TAO::DCPS::AttachStatus status = sub_impl->attach_transport(tcp_impl.in());
    if (status != TAO::DCPS::ATTACH_OK) {
      std::string status_str;
      switch (status) {
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
      cerr << "Failed to attach to the transport. Status == "
           << status_str.c_str() << endl;
      exit(1);
    }

    // activate the listener
    DataReaderListenerImpl        listener_servant;
    PortableServer::POA_var poa = TheServiceParticipant->the_poa ();
    CORBA::Object_var obj = poa->servant_to_reference(&listener_servant);
    DDS::DataReaderListener_var listener =
      DDS::DataReaderListener::_narrow (obj.in ());
    if (CORBA::is_nil (listener.in ())) {
      cerr << "listener is nil." << endl;
      exit(1);
    }

    // To Do: Get default data reader QoS and create the data reader.
    DDS::DataReaderQos dr_qos;
    sub->get_default_datareader_qos (dr_qos);
    DDS::DataReader_var dr = sub->create_datareader(topic.in (),
                                                    dr_qos,
                                                    listener.in ());
    if (CORBA::is_nil (dr.in ())) {
      cerr << "create_datareader failed." << endl;
      exit(1);
    }
    // End: Get default data reader QoS and create the data reader.

    // To Do: Set up the constraints for when the subscriber is done
    // receiving updates.
    int expected = 10;
    while ( listener_servant.num_reads() < expected) {
      ACE_OS::sleep (1);
    }
    // End: Set up the constraints for how long the subscriber should
    // receive updates.

    // To Do: Delete the participant's contained entities
    if (!CORBA::is_nil (participant.in ())) {
      participant->delete_contained_entities();
    }
    // End: Delete the participant's contained entities
    if (!CORBA::is_nil (dpf.in ())) {
      dpf->delete_participant(participant.in ());
    }

    ::DDS::InstanceHandleSeq handles;
    while (1)
    {
      ACE_OS::sleep(1);
      dr->get_matched_publications(handles);
      if (handles.length() == 0)
        break;
    }

    ACE_OS::sleep(2);

    TheTransportFactory->release();
    TheServiceParticipant->shutdown ();

  } catch (CORBA::Exception& e) {
    cerr << "Exception caught in main ():" << endl << e << endl;
    return 1;
  }

  return 0;
}
