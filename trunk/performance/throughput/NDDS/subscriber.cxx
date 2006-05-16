/*
 (c) Copyright, Real-Time Innovations, 2005.  All rights reserved.
 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
*/

#include <stdio.h>
#include <stdlib.h>

//#include "transport/transport_log.h"
#include "config.h"

#include "Stats.h"

class Bytes4Listener : public DDSDataReaderListener {

  private:
    /* Data declarations */
    Bytes4 _instance;
    DDS_InstanceHandle_t _instanceHandle;
    Bytes4DataWriter* _writer;
    int _sequenceNumber;

    int num_publishers_;
    int prime_num_;
    int stats_num_;
    int size_;
    PubSub_Stats stats_;
    bool is_finished_;

  public:

    Bytes4Listener   (int num_publishers,
                      int prime_num,
                      int stats_num,
                      int size)
                      //, const char *output_file_name)
                      :num_publishers_ (num_publishers),
                       prime_num_ (prime_num),
                       stats_num_ (stats_num),
                       size_ (size),
                       stats_ ("sub_stats", prime_num, stats_num, size)
    {
      this->is_finished_ = false;
    }


    Bytes4Listener()
  : _instanceHandle(DDS_HANDLE_NIL),
    _writer(NULL),
    _sequenceNumber(0),
    num_publishers_ (0),
    prime_num_ (0),
    stats_num_ (0),
    size_ (0),
    stats_("sub_stats", 0, 0, 0)
    {}
    virtual ~Bytes4Listener() {}

    // DDSDataReaderListener
    virtual void on_requested_deadline_missed(
        DDSDataReader* /*reader*/,
  const DDS_RequestedDeadlineMissedStatus& /*status*/) {}

    virtual void on_requested_incompatible_qos(
        DDSDataReader* /*reader*/,
  const DDS_RequestedIncompatibleQosStatus& /*status*/) {}

    virtual void on_sample_rejected(DDSDataReader* /*reader*/,
      const DDS_SampleRejectedStatus& /*status*/) {}

    virtual void on_liveliness_changed(DDSDataReader* /*reader*/,
        const DDS_LivelinessChangedStatus& /*status*/) {}

    virtual void on_subscription_matched(DDSDataReader* /*reader*/,
        const DDS_SubscriptionMatchedStatus& /*status*/) {}

    virtual void on_sample_lost(DDSDataReader* /*reader*/,
        const DDS_SampleLostStatus& /*status*/) {}

    virtual void on_data_available(DDSDataReader* /*reader*/);

    void set_writer(Bytes4DataWriter* writer) { _writer = writer; }

    /* test is finished if the sn received is FINAL */
    RTIBool is_finished() { return this->is_finished_; }



};

static RTIBool NddsSubscriberMain(int nddsDomain,
                                  int Size, int prime_num, int stats_num,
                                  int role, RTIBool isEchoer,
                                  RTIBool isReliable,
                                  RTIBool receiveOnMulticast)
{
    /*------------------------- declarations ----------------------------*/

    /* common declarations */
    RTIBool ok = RTI_FALSE;
    DDS_ReturnCode_t retcode = DDS_RETCODE_ERROR;
    DDS_Duration_t sleepTime = {1,0};  /* 1 second */

    /* DomainParticipantFactory declarations */
    DDSDomainParticipantFactory* factory = NULL;

    /*  DomainParticipant declarations */
    DDS_DomainId_t domain_id = nddsDomain;
    DDSDomainParticipant* participant = NULL;
    DDS_DomainParticipantQos participant_qos;
    DDSDomainParticipantListener* participant_listener = NULL;

    /* Subscriber declarations */
    DDSSubscriber* subscriber;
    DDS_SubscriberQos subscriber_qos;
    DDSSubscriberListener* subscriber_listener = NULL;

    /* Publisher declarations */
    DDSPublisher* publisher;
    DDS_PublisherQos publisher_qos;
    DDSPublisherListener* publisher_listener = NULL;

    /* Topic declarations */
    DDSTopic* data_topic;
    DDS_TopicQos data_topic_qos;
    DDSTopicListener* data_topic_listener = NULL;

    DDSTopic* echo_topic;
    DDS_TopicQos echo_topic_qos;
    DDSTopicListener* echo_topic_listener = NULL;

    /* DataReader declarations */
    DDSDataReader* reader;
    DDS_DataReaderQos reader_qos;

    /* DataWriter declarations */
    DDSDataWriter* writer;
    Bytes4DataWriter* latencyPacketDataWriter;
    DDS_DataWriterQos writer_qos;
    DDSDataWriterListener* writer_listener = NULL;

    /* Listener declarations */
    Bytes4Listener reader_listener(1, prime_num, stats_num, Size);

    struct DDS_DomainParticipantFactoryQos factoryQos;
    struct NDDS_Transport_UDPv4_Property_t udpv4Property
  = NDDS_TRANSPORT_UDPV4_PROPERTY_DEFAULT;
#ifdef RTI_SHARED_MEMORY
    struct NDDS_Transport_Shmem_Property_t shmemProperty
  = NDDS_TRANSPORT_SHMEM_PROPERTY_DEFAULT;
#endif
    NDDSConfigLogger* logger = NULL;

    /*-------------------------- create dds entities ---------------------*/

/*--------------------------------------------------------------------------
  Create participant to join the domain and allocate system resources
  (start DDS threads, grab set of port numbers, etc.).
----------------------------------------------------------------------------*/

    /* get handle to participant factory */
    factory = DDSDomainParticipantFactory::get_instance();
    if (factory == NULL) {
  printf("***Error: failed to get domain participant factory\n");
  goto finally;
    }

    /* Do not auto enable participants upon creation since we want to register
       transport plugins
    */
    factory->get_qos(factoryQos);
    factoryQos.entity_factory.autoenable_created_entities = DDS_BOOLEAN_FALSE;

    if (factory->set_qos(factoryQos) != DDS_RETCODE_OK) {
        printf("***Error: failed to set factory QoS\n");
        goto finally;
    }


    /* initialize participant_qos with default values. similiar to
       LatencyWriter setup*/
    factory->get_default_participant_qos(participant_qos);
    /* regardless of where the reader app runs, force the host_id, so we can
       make the send order deterministic (b/c order is decided by hostId-appId)
       pick the same host_id on both publisher and the subscriber
    */
    participant_qos.wire_protocol.rtps_host_id = 0x1;
    participant_qos.wire_protocol.rtps_app_id = role;

    participant_qos.discovery.participant_index  = role;// > 0

    participant_qos.receiver_pool.buffer_size = MAX_MSG_LENGTH + NDDS_OVERHEAD;

#ifdef RTI_SHARED_MEMORY
    participant_qos.transport_builtin.mask |= DDS_TRANSPORTBUILTIN_SHMEM;
#endif

#if ((MAX_MSG_LENGTH + NDDS_OVERHEAD + (14+20+8)) > 64*1024)
    participant_qos.transport_builtin.mask &= ~DDS_TRANSPORTBUILTIN_UDPv4;
#endif

    /* create and enable participant */
    participant = factory->create_participant(domain_id,
                participant_qos,
                participant_listener,
                DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
  printf("***Error: failed to create domain participant\n");
  goto finally;
    }

    if(NDDSTransportSupport::get_builtin_transport_property(
  participant, DDS_TRANSPORTBUILTIN_UDPv4,
  (struct NDDS_Transport_Property_t&)udpv4Property) != DDS_RETCODE_OK) {
  printf("***Error: failed to get default UDPv4 xport property\n");
  goto finally;
    }

    udpv4Property.parent.message_size_max = MAX_MSG_LENGTH + NDDS_OVERHEAD;
    udpv4Property.send_socket_buffer_size
  = udpv4Property.parent.message_size_max;
    udpv4Property.recv_socket_buffer_size
  = 2 * udpv4Property.send_socket_buffer_size;
    //udpv4Property.no_zero_copy = RTI_TRUE;

    if(NDDSTransportSupport::set_builtin_transport_property(
  participant, DDS_TRANSPORTBUILTIN_UDPv4,
  (struct NDDS_Transport_Property_t&)udpv4Property) != DDS_RETCODE_OK) {
  printf("***Error: failed to get default UDPv4 xport property\n");
  goto finally;
    }

#ifdef RTI_SHARED_MEMORY
    /* Do the same if NDDS shared memory transport is installed by default */
    if(NDDSTransportSupport::get_builtin_transport_property(
  participant, DDS_TRANSPORTBUILTIN_SHMEM,
  (struct NDDS_Transport_Property_t&)shmemProperty) != DDS_RETCODE_OK) {
  printf("***Error: failed to get default shmem xport property\n");
  goto finally;
    }

    shmemProperty.parent.message_size_max = MAX_MSG_LENGTH + NDDS_OVERHEAD;
    shmemProperty.received_message_count_max = 8;
    shmemProperty.receive_buffer_size
  = (shmemProperty.received_message_count_max
     * shmemProperty.parent.message_size_max);

    if(NDDSTransportSupport::set_builtin_transport_property(
  participant, DDS_TRANSPORTBUILTIN_SHMEM,
  (struct NDDS_Transport_Property_t&)shmemProperty) != DDS_RETCODE_OK) {
  printf("***Error: failed to get default shmem xport property\n");
  goto finally;
    }
#endif //RTI_SHARED_MEMORY

    retcode = participant->enable();
    if (retcode != DDS_RETCODE_OK) {
        printf("*** Error: failed to enable participant\n");
        goto finally;
    }

/*--------------------------------------------------------------------------
  Create a publisher and a subsciber
----------------------------------------------------------------------------*/

    /* initialize subscriber_qos with default values */
    participant->get_default_subscriber_qos(subscriber_qos);

    /* optionally modify subscriber QoS */

    /* create and enable subscriber */
    subscriber = participant->create_subscriber(subscriber_qos,
            subscriber_listener,
            DDS_STATUS_MASK_NONE);
    if (subscriber == NULL) {
  printf("***Error: failed to create subscriber\n");
  goto finally;
    }

/*--------------------------------------------------------------------------
  Register data types, and create topics: data_topic and echo_topic.
----------------------------------------------------------------------------*/

    Bytes4TypeSupport::register_type(participant, LATENCY_TYPE_NAME);

    /* initialize topic_qos with default values */
    participant->get_default_topic_qos(data_topic_qos);
    data_topic_qos.ownership.kind = DDS_EXCLUSIVE_OWNERSHIP_QOS;

    /* create and enable data_topic. for issue from LatencyWriter to
       LatencyReader */
    data_topic = participant->create_topic(
  LATENCY_DATA_TOPIC_NAME, LATENCY_TYPE_NAME,
  data_topic_qos, data_topic_listener, DDS_STATUS_MASK_NONE);
    if (data_topic == NULL) {
  printf("***Error: failed to create data topic\n");
  goto finally;
    }

    if(isEchoer) {
  /* create and enable echo_topic. for issue from LatencyReader to
     LatencyWrtier */
  echo_topic_qos = data_topic_qos;

  echo_topic = participant->create_topic(
      LATENCY_ECHO_TOPIC_NAME, LATENCY_TYPE_NAME,
      echo_topic_qos, echo_topic_listener, DDS_STATUS_MASK_NONE);
  if (echo_topic == NULL) {
      printf("***Error: failed to create echo topic\n");
      goto finally;
  }

  /* initialize publisher_qos with default values */
  participant->get_default_publisher_qos(publisher_qos);

  /* optionally modify publisher qos values */

  /* create and enable publisher */
  publisher = participant->create_publisher(publisher_qos,
              publisher_listener,
              DDS_STATUS_MASK_NONE);
  if (publisher == NULL) {
      printf("***Error: failed to create publisher\n");
      goto finally;
  }
  /*----------------------------------------------------------------
    Create one data writer: (echo_)writer
    ---------------------------------------------------------------*/

  /* initialize writer_qos with default values */
  publisher->get_default_datawriter_qos(writer_qos);

  if(!isReliable) {//writer is reliable by default
      writer_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
  }

  /* create and enable writer */
  writer = publisher->create_datawriter(
      echo_topic, writer_qos, writer_listener, DDS_STATUS_MASK_NONE);
  if (writer == NULL) {
      printf("***Error: failed to create writer\n");
      goto finally;
  }
  latencyPacketDataWriter = Bytes4DataWriter::narrow(writer);
  if (latencyPacketDataWriter == NULL) {
      printf("***Error: failed to narrow writer\n");
      goto finally;
  }

  reader_listener.set_writer(latencyPacketDataWriter);
    }

/*--------------------------------------------------------------------------
  Create one data reader: (data_)reader
----------------------------------------------------------------------------*/
    /* initialize reader_qos with default values */
    subscriber->get_default_datareader_qos(reader_qos);

    if(isReliable) {
  reader_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
  /* NOTE: not changing history depth or kind here */
    }

    if(receiveOnMulticast) {
  reader_qos.multicast.value.ensure_length(1,1);
  reader_qos.multicast.value[0].receive_address
      = DDS_String_dup("225.1.2.3");
    }

    /* create and enable reader without listener at first */
    reader = subscriber->create_datareader(data_topic, reader_qos,
             NULL, DDS_STATUS_MASK_NONE);
    if (reader == NULL) {
  printf("***Error: failed to create reader\n");
  goto finally;
    }
    /* setup reader to access received data via a listener
       explicitly specify which operations in the listener are
       activated for callback
    */
    retcode = reader->set_listener(
  &reader_listener,
  DDS_DATA_AVAILABLE_STATUS/* | DDS_SAMPLE_REJECTED_STATUS */);
    if (retcode != DDS_RETCODE_OK) {
  printf("***Error: failed to set listener\n");
  goto finally;
    }
    /*
    logger = NDDSConfigLogger::get_instance();
    logger->set_verbosity_by_category(NDDS_CONFIG_LOG_CATEGORY_ENTITIES,
              NDDS_CONFIG_LOG_VERBOSITY_STATUS_REMOTE);
    */
    /*------------------------ start the latency test ----------------------*/

/*--------------------------------------------------------------------------
  Stay in a the while loop unitl receiving a termination message.
----------------------------------------------------------------------------*/

    /* passively receive issue and echo back */
    while (!reader_listener.is_finished()) {
  NDDSUtility::sleep(sleepTime);
    }

    /*------------------------ tear down dds entities ----------------------*/

/*--------------------------------------------------------------------------
  The shutdown phase.
----------------------------------------------------------------------------*/
    if(isEchoer) {
  retcode = publisher->delete_datawriter(writer);
  retcode = participant->delete_publisher(publisher);
  retcode = participant->delete_topic(echo_topic);
    }

    retcode = subscriber->delete_datareader(reader);
    retcode = participant->delete_subscriber(subscriber);
    retcode = participant->delete_topic(data_topic);

    retcode = factory->delete_participant(participant);

    /* NDDS provides finalize_instance() method for people who want to release
       memory used by the participant factory singleton.
       Uncomment the following block of code for clean destruction of
       the participant factory singleton. */
/*
    retcode = DDSDomainParticipantFactory::finalize_instance();
*/

    ok = RTI_TRUE;
 finally:
    if (ok && retcode == DDS_RETCODE_OK) {
  printf("Test successfull!\n");
  return 0;
    } else {
  printf("Error! Test NOT successfull!\n");
  return -1;
    }

}


void Bytes4Listener::on_data_available(DDSDataReader* datareader)
{
    this->stats_.sample_for_throughput ();

    Bytes4DataReader* reader =
  Bytes4DataReader::narrow(datareader);
    Bytes4Seq data_seq;
    DDS_SampleInfoSeq info_seq;
    DDS_ReturnCode_t retcode;

    /* get all the data that the reader has received since the last 'take' */
    retcode = reader->take(data_seq, info_seq, DDS_LENGTH_UNLIMITED,
         DDS_ANY_SAMPLE_STATE,
         DDS_ANY_VIEW_STATE,
         DDS_ANY_INSTANCE_STATE);

    if (retcode != DDS_RETCODE_OK) {
  printf("***Error: failed to access data from the reader\n");
    }


    else {
  //// Examine every sample returned
  for (int i = 0; i < data_seq.length(); i++) {

      /* Must check the 'valid_data' because for some
         samples the data_seq[i] will be NULL */
      if (info_seq[i].valid_data) {
    _instance.data.loan_contiguous(data_seq[i].data.
            get_contiguous_bufferI(),
            data_seq[i].data.length(),
            data_seq[i].data.maximum());
  //  if(_writer) { // echo back to the originator
  //      retcode = _writer->write(_instance, _instanceHandle);
  //      if (retcode != DDS_RETCODE_OK) {
  //    printf("***Error: failed to send data\n");
  //      }
  //  }

    _instance.data.unloan();/* return loan */
      }
  }
    }

  //  // Let the service know the application no longer needs the data and
  //  // info buffers
    reader->return_loan(data_seq, info_seq);


    if (this->stats_.ready_to_dump ())
      {
        this->stats_.file_dump_throughput ();
        this->is_finished_ = true;
      }

}

int main(int argc, char *argv[])
{
    int nddsDomain = 89;
    int role = 1;//translates to participant index
    RTIBool thisSubscriberIsEchoer = RTI_TRUE;
    RTIBool useMulticast = RTI_FALSE;
    RTIBool isReliable = RTI_FALSE;


    int Size = 0, prime_num = 0, stats_num = 0;

    const char *usageStr =
  "Usage: [-d #] [-noecho] [-multicast] [-reliable] [-role #]\n"
  "\t-d NDDS domain\n"
  "\t-role unique number among subscribers. > 0\n"
  "\t-noecho do not echo\n"
  "\t-multicast subscribe multicast\n"
  "\t-reliable request reliable service\n";

    for (int i = 1; i < argc; i++) {
  if(strncmp(argv[i], "-d", 2) == 0) {
      nddsDomain = strtol(argv[++i], NULL, 10);
  } else if (strncmp(argv[i], "-Size", 5) == 0) {
      Size = strtol(argv[++i], NULL, 10);
  } else if (strncmp(argv[i], "-pn", 3) == 0) {
      prime_num = strtol(argv[++i], NULL, 10);
  } else if (strncmp(argv[i], "-sn", 3) == 0) {
      stats_num = strtol(argv[++i], NULL, 10);
  }
  else if (strncmp(argv[i], "-role", 5) == 0) {
      role = strtol(argv[++i], NULL, 10);
  } else if (strncmp(argv[i], "-noecho", 7) == 0) {
      thisSubscriberIsEchoer = RTI_FALSE;
  } else if (strncmp(argv[i], "-multicast", 10) == 0) {
      useMulticast = RTI_TRUE;
  } else if (strncmp(argv[i], "-reliable", 9) == 0) {
      isReliable = RTI_TRUE;
  } else {
      printf("%s", usageStr);
      return 0;
  }
    }

    if(role < 1) role = 1;//put a lower bound to role

    return NddsSubscriberMain(nddsDomain, Size, prime_num, stats_num,
                              role, thisSubscriberIsEchoer,
                             isReliable, useMulticast);
}
