/*
 (c) Copyright, Real-Time Innovations, 2005.  All rights reserved.
 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>  /*for sqrt */

#include "osapi/osapi_semaphore.h"
#include "transport/transport_log.h"
#include "clock/clock_highResolution.h"

#include "config.h"

#include "Stats.h"



const char * pub_output_file = "stats_pub";
const char * qos_config_file = "qos";
const char * net_config_file = "net";
const char * TEST_TOPIC_NAME = "TEST_TOPIC";
const char * TEST_ECHO_TOPIC_NAME = "TEST_ECHO_TOPIC";
const char * TEST_TOPIC_TYPE_NAME = "TEST_TOPIC_TYPE";

int is_finished = 0;

int num_subscribers = 0;

template<typename T, typename W>
void dw_write (
               int size,
               int num_messages,
               DDSDataWriter *writer,
               PubSub_Stats & stats)
{
  T instance;

  /* set up the data buffer for user data */
  DDS_Octet *dataBuffer = (DDS_Octet *)calloc(size, sizeof(DDS_Octet));

  //  cout << " Buffer allocated \n" << endl;

  if (dataBuffer == NULL) {
    printf("***Error: failed to create data buffer\n");
    free(dataBuffer);
    return;
  }

  instance.data.loan_contiguous(dataBuffer,
                                size,
                                size);


  instance.data.length (size);

  for (long i = 0; i < size; ++i)
    {
      instance.data[i] = static_cast<DDS_Octet> (i % 256);
    }

  instance.timestamp = 0;


  W *dw = W::narrow (writer);

  if (dw == NULL) {
    printf("***Error: failed to narrow writer\n");
    return;
  }

  for (int i = 0; i < num_messages; ++i)
    {

      stats.sample_for_throughput (instance.timestamp);

      //cout << "trying to write message [" << i << "]" << endl;

      /* send the raw data to all interested parties */
      DDS_ReturnCode_t retcode = dw->write(instance,
                                           DDS_HANDLE_NIL);

      //cout << "success!" << endl;
    
      if (retcode != DDS_RETCODE_OK)
        {
          printf ("***Error: failed to write\n");
          goto fin;
        }

      /* wait until the echo message is received from the LatencyReader
         if(dataProcessor.wait((struct RTINtpTime*)&sleepTime)
         != RTI_OSAPI_SEMAPHORE_STATUS_OK) {
         printf("***Error: did not hear back echo in time\n");
         goto fin;
         } */
    } /* end of for (i) */


  if (stats.ready_to_dump ())
    {
      printf ("Dumping results...");
      stats.file_dump_throughput ();
      printf ("[Done]\n");
    }

  while (!is_finished)
    {
      DDS_ReturnCode_t retcode = dw->write(instance,
                                           DDS_HANDLE_NIL);
    
      if (retcode != DDS_RETCODE_OK)
        {
          printf ("***Error: failed to write\n");
          goto fin;
        }
    }

fin:
  if (!instance.data.has_ownership()) {
    instance.data.unloan();
    free(dataBuffer);
  }

}


template<typename T, typename TSeq, typename R>
void
echo_read (DDSDataReader *datareader,
           int &count,
           int &num_subscribers)
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
      //// Examine every sample returned
      for (int i = 0; i < instance_seq.length(); i++)
        {

          /* Must check the 'valid_data' because for some
             samples the instance_seq[i] will be NULL */
          if (info_seq[i].valid_data
              && (instance_seq[i].timestamp == 0))
            {
              ++count;

              printf ("# of echos received = %d, expecting %d more echos from subscribers\n", count, num_subscribers - count);

              if (num_subscribers == count)
                {
                  is_finished = 1;
                }

            }
        }
    }
  // Let the service know the application no longer needs the data and
  // info buffers
  dr->return_loan(instance_seq, info_seq);
}



#ifndef JUST_WANT_DATA_PROCESSOR
class TP_PacketListener : public DDSDataReaderListener {

private:
  int num_subscribers_;
  int count_;
  int size_;

public:
  TP_PacketListener(int num_subscribers, int size)
    : num_subscribers_ (num_subscribers),
      count_ (0),
      size_ (size)
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
};


static RTIBool NddsPublisherMain(int nddsDomain,
                                 int size,
                                 int prime_num,
                                 int stats_num,
                                 int num_subscribers,
                                 RTIBool isReliable,
                                 RTIBool receiveOnMulticast)
{


  const int MAX_MSG_LENGTH = 16384;

  // initiate stats file
  PubSub_Stats stats_ (pub_output_file,
                       prime_num,
                       stats_num,
                       size);

  /*------------------------- declarations ----------------------------*/

  /* common declarations */
  RTIBool ok = RTI_FALSE;
  DDS_ReturnCode_t retcode = DDS_RETCODE_ERROR;
  const struct DDS_Duration_t sleepTime = {1,0}, waitTime = {0, 20*1000000};
  int i = 0, packetsize;

  struct DDS_DomainParticipantFactoryQos factoryQos;

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
  TP_PacketListener reader_listener (num_subscribers,
                                     size);


  struct NDDS_Transport_UDPv4_Property_t udpv4Property
    = NDDS_TRANSPORT_UDPV4_PROPERTY_DEFAULT;

#ifdef RTI_SHARED_MEMORY
  struct NDDS_Transport_Shmem_Property_t shmemProperty
    = NDDS_TRANSPORT_SHMEM_PROPERTY_DEFAULT;
#endif
  
  NDDSConfigLogger* logger = NULL;

  if(size > MAX_MSG_LENGTH) {
    printf("***Error: invalid parameter; size > MAX_MSG_LENGTH\n");
    goto fin;
  }

  /*-------------------------- create dds entities ---------------------*/

  /*--------------------------------------------------------------------------
    Create participant to join the domain and allocate system resources
    (start DDS threads, grab set of port numbers, etc.).
    ----------------------------------------------------------------------------*/

  /* get handle to participant factory */
  factory = DDSDomainParticipantFactory::get_instance();
  if (factory == NULL) {
    printf("***Error: failed to get domain participant factory\n");
    goto fin;
  }

  /* Do not auto enable participants upon creation since we want to register
     transport plugins */
  factory->get_qos(factoryQos);
  factoryQos.entity_factory.autoenable_created_entities = DDS_BOOLEAN_FALSE;

  if (factory->set_qos(factoryQos) != DDS_RETCODE_OK) {
    printf("***Error: failed to set factory QoS\n");
    goto fin;
  }

  /* initialize participant_qos with default values */
  factory->get_default_participant_qos(participant_qos);

  //pick the same host_id on both publisher and the subscriber
  participant_qos.wire_protocol.rtps_host_id = 0x1;
  /* writer's participant index is left as 0, the default */

  /* If you want to send message larger than the UDPv4 transport plugin's
     limit of 64 KB, you have to use a non-UDPv4 transport plugin, such as
     the shared memory transport (in which case you will be restricted to
     sending to readers on the SAME host).  Using your own pluggable transport
     is an option, but this example does NOT show to to plug in your own
     transport.
  */
  participant_qos.receiver_pool.buffer_size = MAX_MSG_LENGTH + NDDS_OVERHEAD;

#ifdef RTI_SHARED_MEMORY
  /* If ONLY the shared memory transport plugin
     is used, you can tell NDDS NOT to instantiate its builtin UDPv4
     transport, and use smaller (a few bytes only) buffer size, because the
     shared memory plugin will lend its buffer to the user.
  */
  participant_qos.transport_builtin.mask |= DDS_TRANSPORTBUILTIN_SHMEM;
#endif//RTI_SHARED_MEMORY

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
    goto fin;
  }

  if(participant_qos.transport_builtin.mask & DDS_TRANSPORTBUILTIN_UDPv4) {
    if(NDDSTransportSupport::get_builtin_transport_property(
                                                            participant, DDS_TRANSPORTBUILTIN_UDPv4,
                                                            (struct NDDS_Transport_Property_t&)udpv4Property)
       != DDS_RETCODE_OK) {
      printf("***Error: failed to get default UDPv4 xport property\n");
      goto fin;
    }

    udpv4Property.parent.message_size_max = MAX_MSG_LENGTH + NDDS_OVERHEAD;
    udpv4Property.send_socket_buffer_size
      = udpv4Property.parent.message_size_max;
    udpv4Property.recv_socket_buffer_size
      = 2 * udpv4Property.send_socket_buffer_size;

    /* if IP fragmentation unavoidable, don't use zbuf,
       which will only slow NDDS down */
    if(size > UNFRAGMENTED_UDP_PACKET_SIZE_MAX - NDDS_OVERHEAD) {
      udpv4Property.no_zero_copy = RTI_TRUE;
    }

    if(NDDSTransportSupport::set_builtin_transport_property(
                                                            participant,
                                                            DDS_TRANSPORTBUILTIN_UDPv4,
                                                            (struct NDDS_Transport_Property_t&)udpv4Property)
       != DDS_RETCODE_OK) {
      printf("***Error: failed to get default UDPv4 xport property\n");
      goto fin;
    }
  }

#ifdef RTI_SHARED_MEMORY
  /* Do the same if NDDS shared memory transport is installed by default */
  if(NDDSTransportSupport::get_builtin_transport_property(
                                                          participant, DDS_TRANSPORTBUILTIN_SHMEM,
                                                          (struct NDDS_Transport_Property_t&)shmemProperty) != DDS_RETCODE_OK) {
    printf("***Error: failed to get default shmem xport property\n");
    goto fin;
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
    goto fin;
  }
#endif//RTI_SHARED_MEMORY

  retcode = participant->enable();/* now bring up the participant */
  if (retcode != DDS_RETCODE_OK) {
    printf("*** Error: failed to enable participant\n");
    goto fin;
  }

  /*--------------------------------------------------------------------------
    Create a publisher and a subsciber, both with default QoSes.
    ----------------------------------------------------------------------------*/

  /* initialize subscriber_qos with default values */
  participant->get_default_subscriber_qos(subscriber_qos);

  /* optionally modify subscriber qos values */

  /* create and enable subscriber */
  subscriber = participant->create_subscriber(subscriber_qos,
                                              subscriber_listener,
                                              DDS_STATUS_MASK_NONE);
  if (subscriber == NULL) {
    printf("***Error: failed to create subscriber\n");
    goto fin;
  }

  /* initialize publisher_qos with default values */
  participant->get_default_publisher_qos(publisher_qos);

  /* optionally modify publisher qos values here */

  /* create and enable publisher */
  publisher = participant->create_publisher(publisher_qos,
                                            publisher_listener,
                                            DDS_STATUS_MASK_NONE);
  if (publisher == NULL) {
    printf("***Error: failed to create publisher\n");
    goto fin;
  }

  /*--------------------------------------------------------------------------
    Register data types, and create topics: echo_topic and data_topic
    ----------------------------------------------------------------------------*/


  // Register data type for different size
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
  echo_topic_qos = data_topic_qos;

  /* create and enable data_topic. This is topic for data from
     TP_PacketWriter to TP_PacketReader. */
  data_topic = participant->create_topic(
                                         TEST_TOPIC_NAME,
                                         TEST_TOPIC_TYPE_NAME,
                                         data_topic_qos,
                                         data_topic_listener,
                                         DDS_STATUS_MASK_NONE);
  if (data_topic == NULL) {
    printf("***Error: failed to create data topic\n");
    goto fin;
  }


  printf ("Current topic name is %s\n", TEST_TOPIC_NAME);


  /* create and enable processedDataTopic. This is topic for data from
     TP_PacketReader to TP_PacketWriter. */
  echo_topic = participant->create_topic(
                                         TEST_ECHO_TOPIC_NAME,
                                         TEST_TOPIC_TYPE_NAME,
                                         echo_topic_qos,
                                         echo_topic_listener,
                                         DDS_STATUS_MASK_NONE);
  if (echo_topic == NULL) {
    printf("***Error: failed to create echo topic\n");
    goto fin;
  }


  /*--------------------------------------------------------------------------
    Create one data writer: (data_)writer
    ----------------------------------------------------------------------------*/

  /* initialize writer_qos with default values */
  publisher->get_default_datawriter_qos(writer_qos);

  if(!isReliable) {//writer is reliable by default
    writer_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
  }

  /* create and enable writer. use data_topic. */
  writer = publisher->create_datawriter(
                                        data_topic,
                                        writer_qos,
                                        writer_listener,
                                        DDS_STATUS_MASK_NONE);
  
  if (writer == NULL) {
    printf("***Error: failed to create writer\n");
    goto fin;
  }



  /*--------------------------------------------------------------------------
    Create one data reader: (echo_)reader
    ----------------------------------------------------------------------------*/

  /* initialize reader_qos with default values */
  subscriber->get_default_datareader_qos(reader_qos);

  if(isReliable) {//reader is BE by default
    reader_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
    /* NOTE: not changing history depth or kind here */
  }

  if(receiveOnMulticast) {
    reader_qos.multicast.value.ensure_length(1,1);
    /* must use strdup() to avoid crash at end */
    reader_qos.multicast.value[0].receive_address
      = DDS_String_dup("225.3.2.1");
  }

  /* create and enable reader. use echo_topic. */
  reader = subscriber->create_datareader(echo_topic,
                                         reader_qos,
                                         NULL,
                                         DDS_STATUS_MASK_NONE);
  if (reader == NULL)
    {
      printf("***Error: failed to create reader\n");
      goto fin;
    }
  /* setup reader to access received data via a listener
     explicitly specify which operations in the listener are
     activated for callback
  */
  retcode = reader->set_listener(&reader_listener, DDS_DATA_AVAILABLE_STATUS);

  if (retcode != DDS_RETCODE_OK) {
    printf("***Error: failed to set listener\n");
    goto fin;
  }



  for(i = 0; i < 8; ++i) {
    NDDSUtility::sleep(sleepTime);
  }

  /*------------------------ start the latency test ----------------------*/

  /*--------------------------------------------------------------------------
    The core latency test is in the following for() loop.
    ----------------------------------------------------------------------------*/
  NDDSUtility::sleep(sleepTime);


  printf ("Sending samples...");

  /* send to reader to terminate the reader */
  switch (size)
    {
    case 4:
      dw_write< Bytes4,
                Bytes4DataWriter>
        (size,
         prime_num + stats_num,
         writer,
         stats_);
      break;
    case 8:
      dw_write< Bytes8,
                Bytes8DataWriter>
        (size,
         prime_num + stats_num,
         writer,
         stats_);
      break;
    case 16:
      dw_write< Bytes16,
                Bytes16DataWriter>
        (size,
         prime_num + stats_num,
         writer,
         stats_);
      break;
    case 32:
      dw_write< Bytes32,
                Bytes32DataWriter>
        (size,
         prime_num + stats_num,
         writer,
         stats_);
      break;
    case 64:
      dw_write< Bytes64,
                Bytes64DataWriter>
        (size,
         prime_num + stats_num,
         writer,
         stats_);
      break;
    case 128:
      dw_write< Bytes128,
             Bytes128DataWriter>
        (size,
         prime_num + stats_num,
         writer,
         stats_);
      break;
    case 256:
      dw_write< Bytes256,
             Bytes256DataWriter>
        (size,
         prime_num + stats_num,
         writer,
         stats_);
      break;
    case 512:
      dw_write< Bytes512,
             Bytes512DataWriter>
        (size,
         prime_num + stats_num,
         writer,
         stats_);
      break;
    case 1024:
      dw_write< Bytes1024,
             Bytes1024DataWriter>
        (size,
         prime_num + stats_num,
         writer,
         stats_);
      break;
    case 2048:
      dw_write< Bytes2048,
             Bytes2048DataWriter>
        (size,
         prime_num + stats_num,
         writer,
         stats_);
      break;
    case 4096:
      dw_write< Bytes4096,
             Bytes4096DataWriter>
        (size,
         prime_num + stats_num,
         writer,
         stats_);
      break;
    case 8192:
      dw_write< Bytes8192,
                Bytes8192DataWriter>
        (size,
         prime_num + stats_num,
         writer,
         stats_);
      break;
    case 16384:
      dw_write< Bytes16384,
                Bytes16384DataWriter>
        (size,
         prime_num + stats_num,
         writer,
         stats_);
      break;
    default:
      printf ("ERROR: bad data size %d\n", size);

    }

  printf ("[Done]\n");

  NDDSUtility::sleep(sleepTime);

  /*--------------------------------------------------------------------------
    The shutdown period.
    ----------------------------------------------------------------------------*/

  /*------------------------ tear down dds entities ----------------------*/
  retcode = subscriber->delete_datareader(reader);
  retcode = publisher->delete_datawriter(writer);
  retcode = participant->delete_topic(echo_topic);
  retcode = participant->delete_topic(data_topic);
  retcode = participant->delete_subscriber(subscriber);
  retcode = participant->delete_publisher(publisher);
  retcode = factory->delete_participant(participant);

  /* NDDS provides finalize_instance() method for people who want to release
     memory used by the participant factory singleton.
     Uncomment the following block of code for clean destruction of
     the participant factory singleton. */
  /*
    retcode = DDSDomainParticipantFactory::finalize_instance();
  */

  ok = RTI_TRUE;

fin:
  if (ok && retcode == DDS_RETCODE_OK) {
    printf("Test successfull!\n");
    return 0;
  } else {
    printf("Error! Test NOT successfull!\n");
    return -1;
  }
}

/*i called when received echo */
void TP_PacketListener::on_data_available(DDSDataReader* datareader)
{

  switch (this->size_)
    {
    case 4:
        echo_read< Bytes4,
        Bytes4Seq,
        Bytes4DataReader>
          (datareader,
           this->count_,
           this->num_subscribers_);
      break;
    case 8:
        echo_read< Bytes8,
        Bytes8Seq,
        Bytes8DataReader>
          (datareader,
           this->count_,
           this->num_subscribers_);
      break;
    case 16:
        echo_read< Bytes16,
        Bytes16Seq,
        Bytes16DataReader>
          (datareader,
           this->count_,
           this->num_subscribers_);
      break;
    case 32:
        echo_read< Bytes32,
        Bytes32Seq,
        Bytes32DataReader>
          (datareader,
           this->count_,
           this->num_subscribers_);
      break;
    case 64:
        echo_read< Bytes64,
        Bytes64Seq,
        Bytes64DataReader>
          (datareader,
           this->count_,
           this->num_subscribers_);
      break;
    case 128:
        echo_read< Bytes128,
        Bytes128Seq,
        Bytes128DataReader>
          (datareader,
           this->count_,
           this->num_subscribers_);
      break;
    case 256:
        echo_read< Bytes256,
        Bytes256Seq,
        Bytes256DataReader>
          (datareader,
           this->count_,
           this->num_subscribers_);
      break;
    case 512:
        echo_read< Bytes512,
        Bytes512Seq,
        Bytes512DataReader>
          (datareader,
           this->count_,
           this->num_subscribers_);
      break;
    case 1024:
        echo_read< Bytes1024,
        Bytes1024Seq,
        Bytes1024DataReader>
          (datareader,
           this->count_,
           this->num_subscribers_);
      break;
    case 2048:
        echo_read< Bytes2048,
        Bytes2048Seq,
        Bytes2048DataReader>
          (datareader,
           this->count_,
           this->num_subscribers_);
      break;
    case 4096:
        echo_read< Bytes4096,
        Bytes4096Seq,
        Bytes4096DataReader>
          (datareader,
           this->count_,
           this->num_subscribers_);
      break;
    case 8192:
        echo_read< Bytes8192,
        Bytes8192Seq,
        Bytes8192DataReader>
          (datareader,
           this->count_,
           this->num_subscribers_);
      break;
    case 16384:
        echo_read< Bytes16384,
        Bytes16384Seq,
        Bytes16384DataReader>
          (datareader,
           this->count_,
           this->num_subscribers_);
      break;
    default:
      printf ("***Error: bad data size %d\n", this->size_);
      break;
    };
}
#endif//!JUST_WANT_DATA_PROCESSOR



#ifndef I_HAVE_MY_OWN_MAIN
int main(int argc, char **argv)
{
  int size, nddsDomain = 89;
  int prime_num, stats_num;
  int num_subscribers = 1;
  RTIBool useMulticast = RTI_FALSE;
  RTIBool isReliable = RTI_FALSE;

  const char *usageStr =
    "Usage: [-d #] [-minsize #] [-maxsize #] [-multicast] [-reliable]\n"
    "\t-d NDDS domain\n"
    "\t-minsize minimum payload size\n"
    "\t-maxsize maximum payload size\n"
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
    } else if (strncmp(argv[i], "-num_of_sub", 11) == 0) {
      num_subscribers = strtol(argv[++i], NULL, 10);
    } else if (strncmp(argv[i], "-top", 4) == 0) {
      TEST_TOPIC_NAME = argv[++i];
    } else if (strncmp(argv[i], "-r", 2) == 0) {
      pub_output_file = argv[++i];
    } else if (strncmp(argv[i], "-n", 2) == 0) {
      net_config_file = argv[++i];
    } else if (strncmp(argv[i], "-q", 2) == 0) {
      qos_config_file = argv[++i];
    } else if (strncmp(argv[i], "-multicast", 10) == 0) {
      useMulticast = RTI_TRUE;
    } else if (strncmp(argv[i], "-reliable", 9) == 0) {
      isReliable = RTI_TRUE;
    } else {
      printf("%s", usageStr);
      return 0;
    }
  }

  return NddsPublisherMain(nddsDomain,
                           size,
                           prime_num,
                           stats_num,
                           num_subscribers,
                           isReliable, useMulticast);

}
#endif//!I_HAVE_MY_OWN_MAIN
