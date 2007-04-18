#ifndef publisher_test_core_h
#define publisher_test_core_h


#include "latency.h"
#include "latency_support.h"

#include "GlobalSettings.h"

class PublisherTestCore
{
 private:
  DDS_DomainId_t domain_id_;
  int size_, test_samples_, primer_samples_;
  RTIBool is_reliable_;
  RTIBool receive_on_multicast_;
  DDSDomainParticipant* participant_;

  DDSPublisher* publisher_;
  DDSPublisherListener* publisher_listener_;

  DDSSubscriber* subscriber_;
  DDSSubscriberListener* subscriber_listener_;

  DDSDataWriter* writer_;
  PubMessageDataWriter* latency_data_writer_;

  DDSDataReader* reader_;
  AckMessageDataReader *latency_data_reader_;

  DDSTopic* data_topic_;
  DDSTopicListener* data_topic_listener_;
  
  DDSTopic* echo_topic_;
  DDSTopicListener* echo_topic_listener_;



 public:  

  PublisherTestCore (int domain_id,
                     int size,
                     int test_samples,
                     int primer_samples,
                     RTIBool is_reliable,
                     RTIBool receive_on_multicast);
  DDS_Boolean create_dds_entities ();
  DDS_Boolean delete_dds_entities ();
  DDS_Boolean configure_udpv4_transport ();
  DDS_Boolean configure_shmem_transport ();
  DDS_Boolean launch_test ();
  
}


#endif /* publisher_test_core */
