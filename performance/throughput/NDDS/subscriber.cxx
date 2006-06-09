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


const char * sub_output_file = "stats_sub";
const char * qos_config_file = "qos";
const char * net_config_file = "net";
const char * TEST_TOPIC_NAME = "TEST_TOPIC";
const char * TEST_ECHO_TOPIC_NAME = "TEST_ECHO_TOPIC";
const char * TEST_TOPIC_TYPE_NAME = "TEST_TOPIC_TYPE";



template<typename T, typename W>
void echo_write (
               int size,
               int num_messages,
               DDSDataWriter *writer)
{
  T instance;

  /* set up the data buffer for user data */
  DDS_Octet *dataBuffer = (DDS_Octet *)calloc(size, sizeof(DDS_Octet));

  if (dataBuffer == NULL) {
    printf("***Error: failed to create data buffer\n");
    free(dataBuffer);
    return;
  }

  instance.data.loan_contiguous(dataBuffer, size, size);


  instance.data.length (size);

  instance.timestamp = 0;


  W *dw = W::narrow (writer);

  if (dw == NULL) {
    printf("***Error: failed to narrow writer\n");
    return;
  }

  printf ("Sending echo message...");

  DDS_ReturnCode_t retcode = dw->write(instance,
                                       DDS_HANDLE_NIL);

  printf ("[Done]\n");
    
  if (retcode != DDS_RETCODE_OK)
    {
      printf ("***Error: failed to write\n");
      goto fin;
    }

fin:
  if (!instance.data.has_ownership()) {
    instance.data.unloan();
    free(dataBuffer);
  }

}


template<typename T, typename TSeq, typename R>
long
dr_read (DDSDataReader *datareader)
{
  R* dr =
    R::narrow (datareader);

  TSeq instance_seq;

  T instance;

  DDS_SampleInfoSeq info_seq;
  
  DDS_ReturnCode_t retcode;

  long ts = 1;

  /* get all the data that the reader has received since the last 'take' */
  retcode = dr->take(instance_seq,
                     info_seq,
                     DDS_LENGTH_UNLIMITED,
                     DDS_ANY_SAMPLE_STATE,
                     DDS_ANY_VIEW_STATE,
                     DDS_ANY_INSTANCE_STATE);

  if (retcode != DDS_RETCODE_OK)
    {
      printf("***Error: failed to access data from the reader\n");
    }
  else
    {
      ts = instance_seq[0].timestamp;

      
      //// Examine every sample returned
      for (int i = 0; i < instance_seq.length(); i++) {

        /* Must check the 'valid_data' because for some
           samples the instance_seq[i] will be NULL */
        if (info_seq[i].valid_data) {
          instance.data.loan_contiguous(instance_seq[i].data.
                                        get_contiguous_bufferI(),
                                        instance_seq[i].data.length(),
                                        instance_seq[i].data.maximum());
          //  if(_writer) { // echo back to the originator
          //      retcode = _writer->write(_instance, _instanceHandle);
          //      if (retcode != DDS_RETCODE_OK) {
          //    printf("***Error: failed to send data\n");
          //      }
          //  }

          instance.data.unloan();/* return loan */
        }
      }
    }

  // Let the service know the application no longer needs the data and
  // info buffers
  dr->return_loan(instance_seq, info_seq);

  return ts;
}



class TP_PacketListener : public DDSDataReaderListener {

private:
  /* Data declarations */
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

  TP_PacketListener   (int num_publishers,
                       int prime_num,
                       int stats_num,
                       int size)
  //, const char *output_file_name)
    :num_publishers_ (num_publishers),
     prime_num_ (prime_num),
     stats_num_ (stats_num),
     size_ (size),
     stats_ (sub_output_file, prime_num, stats_num, size)
  {
    this->is_finished_ = false;
  }


  TP_PacketListener()
    : _instanceHandle(DDS_HANDLE_NIL),
      _writer(NULL),
      _sequenceNumber(0),
      num_publishers_ (0),
      prime_num_ (0),
      stats_num_ (0),
      size_ (0),
      stats_(sub_output_file, 0, 0, 0)
  {}
  virtual ~TP_PacketListener() {}

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
                                  int size, int prime_num, int stats_num,
                                  int role, RTIBool isEchoer,
                                  RTIBool isReliable,
                                  RTIBool receiveOnMulticast)
{
  const int MAX_MSG_LENGTH = 16384;

    
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


  DDS_DataWriterQos writer_qos;
  DDSDataWriterListener* writer_listener = NULL;

  

  /* Listener declarations */
  TP_PacketListener reader_listener(1, prime_num, stats_num, size);

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
    return -1;
  }

  /* Do not auto enable participants upon creation since we want to register
     transport plugins
  */
  factory->get_qos(factoryQos);
  factoryQos.entity_factory.autoenable_created_entities = DDS_BOOLEAN_FALSE;

  if (factory->set_qos(factoryQos) != DDS_RETCODE_OK) {
    printf("***Error: failed to set factory QoS\n");
    return -1;
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
    return -1;
  }

  if(NDDSTransportSupport::get_builtin_transport_property(
                                                          participant, DDS_TRANSPORTBUILTIN_UDPv4,
                                                          (struct NDDS_Transport_Property_t&)udpv4Property) != DDS_RETCODE_OK) {
    printf("***Error: failed to get default UDPv4 xport property\n");
    return -1;
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
    return -1;
  }

#ifdef RTI_SHARED_MEMORY
  /* Do the same if NDDS shared memory transport is installed by default */
  if(NDDSTransportSupport::get_builtin_transport_property(
                                                          participant, DDS_TRANSPORTBUILTIN_SHMEM,
                                                          (struct NDDS_Transport_Property_t&)shmemProperty) != DDS_RETCODE_OK) {
    printf("***Error: failed to get default shmem xport property\n");
    return -1;
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
    return -1;
  }
#endif //RTI_SHARED_MEMORY

  retcode = participant->enable();
  if (retcode != DDS_RETCODE_OK) {
    printf("*** Error: failed to enable participant\n");
    return -1;
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
    return -1;
  }

  /*--------------------------------------------------------------------------
    Register data types, and create topics: data_topic and echo_topic.
    ----------------------------------------------------------------------------*/

  switch (size)
    {
    case 4:
      Bytes4TypeSupport::register_type(participant, TEST_TOPIC_TYPE_NAME);
      break;
    case 8:
      Bytes8TypeSupport::register_type(participant, TEST_TOPIC_TYPE_NAME);
      break;
    case 16:
      Bytes16TypeSupport::register_type(participant, TEST_TOPIC_TYPE_NAME);
      break;
    case 32:
      Bytes32TypeSupport::register_type(participant, TEST_TOPIC_TYPE_NAME);
      break;
    case 64:
      Bytes64TypeSupport::register_type(participant, TEST_TOPIC_TYPE_NAME);
      break;
    case 128:
      Bytes128TypeSupport::register_type(participant, TEST_TOPIC_TYPE_NAME);
      break;
    case 256:
      Bytes256TypeSupport::register_type(participant, TEST_TOPIC_TYPE_NAME);
      break;
    case 512:
      Bytes512TypeSupport::register_type(participant, TEST_TOPIC_TYPE_NAME);
      break;
    case 1024:
      Bytes1024TypeSupport::register_type(participant, TEST_TOPIC_TYPE_NAME);
      break;
    case 2048:
      Bytes2048TypeSupport::register_type(participant, TEST_TOPIC_TYPE_NAME);
      break;
    case 4096:
      Bytes4096TypeSupport::register_type(participant, TEST_TOPIC_TYPE_NAME);
      break;
    case 8192:
      Bytes8192TypeSupport::register_type(participant, TEST_TOPIC_TYPE_NAME);
      break;
    case 16384:
      Bytes16384TypeSupport::register_type(participant, TEST_TOPIC_TYPE_NAME);
    }


  /* initialize topic_qos with default values */
  participant->get_default_topic_qos(data_topic_qos);
  data_topic_qos.ownership.kind = DDS_EXCLUSIVE_OWNERSHIP_QOS;

  /* create and enable data_topic. for issue from LatencyWriter to
     LatencyReader */
  data_topic = participant->create_topic(
                                         TEST_TOPIC_NAME,
                                         TEST_TOPIC_TYPE_NAME,
                                         data_topic_qos,
                                         data_topic_listener,
                                         DDS_STATUS_MASK_NONE);
  if (data_topic == NULL) {
    printf("***Error: failed to create data topic\n");
    return -1;
  }

  printf ("Current topic name is %s\n", TEST_TOPIC_NAME);

  /* create and enable echo_topic. for issue from LatencyReader to
     LatencyWrtier */
  echo_topic_qos = data_topic_qos;

  echo_topic = participant->create_topic(
                                         TEST_ECHO_TOPIC_NAME,
                                         TEST_TOPIC_TYPE_NAME,
                                         echo_topic_qos,
                                         echo_topic_listener,
                                         DDS_STATUS_MASK_NONE);
  if (echo_topic == NULL) {
    printf("***Error: failed to create echo topic\n");
    return -1;
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
    return -1;
  }
  /*----------------------------------------------------------------
    Create one data writer: (echo_)writer
    ---------------------------------------------------------------*/

  /* initialize writer_qos with default values */
  publisher->get_default_datawriter_qos(writer_qos);

  //  writer_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;

  /* create and enable writer */
  writer = publisher->create_datawriter(
                                        echo_topic,
                                        writer_qos,
                                        writer_listener,
                                        DDS_STATUS_MASK_NONE);

  writer_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;

  if (writer == NULL) {
    printf("***Error: failed to create writer\n");
    return -1;
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
  reader = subscriber->create_datareader(data_topic,
                                         reader_qos,
                                         NULL,
                                         DDS_STATUS_MASK_NONE);
  if (reader == NULL) {
    printf("***Error: failed to create reader\n");
    return -1 -1;
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
    return -1;
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

  printf ("Receiving samples...");
  
  while (!reader_listener.is_finished()) {
    NDDSUtility::sleep(sleepTime);
  }
  
  printf ("[Done]\n");




  switch (size)
    {
    case 4:
      echo_write< Bytes4,
                Bytes4DataWriter>
        (size,
         1,
         writer);
      break;
    case 8:
      echo_write< Bytes8,
                Bytes8DataWriter>
        (size,
         1,
         writer);
      break;
    case 16:
      echo_write< Bytes16,
                Bytes16DataWriter>
        (size,
         1,
         writer);
      break;
    case 32:
      echo_write< Bytes32,
                Bytes32DataWriter>
        (size,
         1,
         writer);
      break;
    case 64:
      echo_write< Bytes64,
                Bytes64DataWriter>
        (size,
         1,
         writer);
      break;
    case 128:
      echo_write< Bytes128,
             Bytes128DataWriter>
        (size,
         1,
         writer);
      break;
    case 256:
      echo_write< Bytes256,
             Bytes256DataWriter>
        (size,
         1,
         writer);
      break;
    case 512:
      echo_write< Bytes512,
             Bytes512DataWriter>
        (size,
         1,
         writer);
      break;
    case 1024:
      echo_write< Bytes1024,
             Bytes1024DataWriter>
        (size,
         1,
         writer);
      break;
    case 2048:
      echo_write< Bytes2048,
             Bytes2048DataWriter>
        (size,
         1,
         writer);
      break;
    case 4096:
      echo_write< Bytes4096,
             Bytes4096DataWriter>
        (size,
         1,
         writer);
      break;
    case 8192:
      echo_write< Bytes8192,
                Bytes8192DataWriter>
        (size,
         1,
         writer);
      break;
    case 16384:
      echo_write< Bytes16384,
                Bytes16384DataWriter>
        (size,
         1,
         writer);
      break;
    default:
      printf ("ERROR: bad data size %d\n", size);

    }
  

  /*------------------------ tear down dds entities ----------------------*/

  /*--------------------------------------------------------------------------
    The shutdown phase.
    ----------------------------------------------------------------------------*/
  retcode = publisher->delete_datawriter(writer);
  retcode = participant->delete_publisher(publisher);
  retcode = participant->delete_topic(echo_topic);

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


void TP_PacketListener::on_data_available(DDSDataReader* datareader)
{
  ACE_CDR::ULong num_read;

//   printf ("here\n");


  switch (this->size_)
    {
    case 4:
      num_read =
        dr_read< Bytes4,
        Bytes4Seq,
        Bytes4DataReader>
        (datareader);
      break;
    case 8:
      num_read =
        dr_read< Bytes8,
        Bytes8Seq,
        Bytes8DataReader>
        (datareader);
      break;
    case 16:
      num_read =
        dr_read< Bytes16,
        Bytes16Seq,
        Bytes16DataReader>
        (datareader);
      break;
    case 32:
      num_read =
        dr_read< Bytes32,
        Bytes32Seq,
        Bytes32DataReader>
        (datareader);
      break;
    case 64:
      num_read =
        dr_read< Bytes64,
        Bytes64Seq,
        Bytes64DataReader>
        (datareader);
      break;
    case 128:
      num_read =
        dr_read< Bytes128,
        Bytes128Seq,
        Bytes128DataReader>
        (datareader);
      break;
    case 256:
      num_read =
        dr_read< Bytes256,
        Bytes256Seq,
        Bytes256DataReader>
        (datareader);
      break;
    case 512:
      num_read =
        dr_read< Bytes512,
        Bytes512Seq,
        Bytes512DataReader>
        (datareader);
      break;
    case 1024:
      num_read =
        dr_read< Bytes1024,
        Bytes1024Seq,
        Bytes1024DataReader>
        (datareader);
      break;
    case 2048:
      num_read =
        dr_read< Bytes2048,
        Bytes2048Seq,
        Bytes2048DataReader>
        (datareader);
      break;
    case 4096:
      num_read =
        dr_read< Bytes4096,
        Bytes4096Seq,
        Bytes4096DataReader>
        (datareader);
      break;
    case 8192:
      num_read =
        dr_read< Bytes8192,
        Bytes8192Seq,
        Bytes8192DataReader>
        (datareader);
      break;
    case 16384:
      num_read =
        dr_read< Bytes16384,
        Bytes16384Seq,
        Bytes16384DataReader>
        (datareader);
      break;
    default:
      printf ("***Error: bad data size %d\n", this->size_);
      break;
    };


  this->stats_.sample_for_throughput (num_read, true);


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


    int size = 0, prime_num = 0, stats_num = 0;

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
        size = strtol(argv[++i], NULL, 10);
      } else if (strncmp(argv[i], "-pn", 3) == 0) {
        prime_num = strtol(argv[++i], NULL, 10);
      } else if (strncmp(argv[i], "-sn", 3) == 0) {
        stats_num = strtol(argv[++i], NULL, 10);
      } else if (strncmp(argv[i], "-r", 2) == 0) {
        sub_output_file = argv[++i];
      } else if (strncmp(argv[i], "-n", 2) == 0) {
        net_config_file = argv[++i];
      } else if (strncmp(argv[i], "-q", 2) == 0) {
        qos_config_file = argv[++i];
      } else if (strncmp(argv[i], "-top", 4) == 0) {
        TEST_TOPIC_NAME = argv[++i];
      } else if (strncmp(argv[i], "-role", 5) == 0) {
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

    if(role < 1) role = 1; //put a lower bound to role

    return NddsSubscriberMain(nddsDomain, size, prime_num, stats_num,
                              role, thisSubscriberIsEchoer,
                             isReliable, useMulticast);
}
