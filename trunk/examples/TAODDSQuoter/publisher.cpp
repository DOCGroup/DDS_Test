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

#include "QuoterTypeSupportImpl.h"
#include "Writer.h"
#include <dds/DCPS/Service_Participant.h>
#include <dds/DCPS/Marked_Default_Qos.h>
#include <dds/DCPS/PublisherImpl.h>
#include <dds/DCPS/transport/framework/TheTransportFactory.h>
#include <dds/DCPS/transport/simpleTCP/SimpleTcpConfiguration.h>
#include <ace/streams.h>

// Match this value with what the benchmark test (implicitly) has
// just to be safe.
//const TAO::DCPS::TransportIdType TCP_IMPL_ID = 0;
const TAO::DCPS::TransportIdType TCP_IMPL_ID = 1;

const char* pub_ready_filename    = "publisher_ready.txt";
const char* pub_finished_filename = "publisher_finished.txt";
const char* sub_ready_filename    = "subscriber_ready.txt";
const char* sub_finished_filename = "subscriber_finished.txt";
const char *writer_address_str = "default";


int main (int argc, char *argv[]) {
  const int domainId = 411;
  const char *topicName = "Stock Quotes";

  try {
    DDS::DomainParticipantFactory_var dpf =
      TheParticipantFactoryWithArgs(argc, argv);

    // To Do: Create the participant
    DDS::DomainParticipant_var participant =
      dpf->create_participant(domainId,
                              PARTICIPANT_QOS_DEFAULT,
                              DDS::DomainParticipantListener::_nil());
    if (CORBA::is_nil (participant.in ())) {
      cerr << "create_participant failed." << endl;
      return 1;
    }
    // End: Create the participant

    QuoterTypeSupportImpl* servant = new QuoterTypeSupportImpl();
    PortableServer::ServantBase_var safe_servant = servant;

    // To Do: Register the type
    if (DDS::RETCODE_OK != servant->register_type(participant.in (), "")) {
      cerr << "register_type failed." << endl;
      exit(1);
    }
    // End: Register the type
  
    CORBA::String_var type_name = servant->get_type_name ();

    // To Do: Get the (default) topic QoS and create the topic
    DDS::TopicQos topic_qos;
    participant->get_default_topic_qos(topic_qos);
    DDS::Topic_var topic =
      participant->create_topic (topicName,
                                 type_name.in (),
                                 topic_qos,
                                 DDS::TopicListener::_nil());
    if (CORBA::is_nil (topic.in ())) {
      cerr << "create_topic failed." << endl;
      exit(1);
    }
    // End: Get the (default) topic QoS and create the topic

    // There are problems with publisher and subscriber being on separate
    // machines. Take the transport configuration from the benchmark tests
    // to see if that fixes the problem.
    TAO::DCPS::TransportImpl_rch tcp_impl =
      TheTransportFactory->create_transport_impl (TCP_IMPL_ID, 
                                                  //::TAO::DCPS::AUTO_CONFIG);
                                                  ::TAO::DCPS::DONT_AUTO_CONFIG);

    TAO::DCPS::TransportConfiguration_rch writer_config =
      TheTransportFactory->get_configuration (TCP_IMPL_ID);

    TAO::DCPS::SimpleTcpConfiguration* writer_tcp_config =
      static_cast <TAO::DCPS::SimpleTcpConfiguration*> (writer_config.in ());

    if (0 != ACE_OS::strcmp("default", writer_address_str)) {
      ACE_INET_Addr writer_address (writer_address_str);
      writer_tcp_config->local_address_ = writer_address;
    }

    if (0 != tcp_impl->configure (writer_config.in ())) {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT("(%P|%t) ::main: ")
                  ACE_TEXT("Failed to configure the transport.\n")));
      exit(1);
    }
    // End of transport configuration changes

    // To Do: Create the publisher
    DDS::Publisher_var pub =
      participant->create_publisher(PUBLISHER_QOS_DEFAULT,
                                    DDS::PublisherListener::_nil());
    if (CORBA::is_nil (pub.in ())) {
      cerr << "create_publisher failed." << endl;
      exit(1);
    }
    // End: Create the publisher

    // Attach the publisher to the transport.
    TAO::DCPS::PublisherImpl* pub_impl =
      ::TAO::DCPS::reference_to_servant< TAO::DCPS::PublisherImpl, 
                                         DDS::Publisher_ptr>(pub.in ());
    if (0 == pub_impl) {
      cerr << "Failed to obtain publisher servant" << endl;
      exit(1);
    }

    TAO::DCPS::AttachStatus status = pub_impl->attach_transport(tcp_impl.in());
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

    // To Do: Get the (default) data writer QoS and create the datawriter
    DDS::DataWriterQos dw_qos;
    pub->get_default_datawriter_qos (dw_qos);
    DDS::DataWriter_var dw =
      pub->create_datawriter(topic.in (),
                             dw_qos,
                             DDS::DataWriterListener::_nil());
    if (CORBA::is_nil (dw.in ())) {
      cerr << "create_datawriter failed." << endl;
      exit(1);
    }
    // End: Get the (default) data writer QoS and create the datawriter
    Writer* writer = new Writer(dw.in());

    // Indicate that the publisher is ready
    FILE* writers_ready = ACE_OS::fopen (pub_ready_filename, "w");
    if (writers_ready == 0) {
      cerr << "ERROR Unable to create publisher ready file" << endl;
      exit(1);
    }
    ACE_OS::fclose(writers_ready);

    // To Do: Start the writer task and wait until it is finished
    writer->start ();
    while ( !writer->is_finished()) {
      ACE_Time_Value small(0,250000);
      ACE_OS::sleep (small);
    }
    // End: Start the writer task and wait until it is finished

    // Cleanup
    writer->end ();
    delete writer;
    
    // To Do: Delete the participant's contained entities when finished
    participant->delete_contained_entities();
    // End: Delete the participant's contained entities when finished

    dpf->delete_participant(participant.in ());
    TheTransportFactory->release();
    TheServiceParticipant->shutdown ();
  } catch (CORBA::Exception& e) {
    cerr << "Exception caught in main.cpp:" << endl
         << e << endl;
    exit(1);
  }

  return 0;
}
