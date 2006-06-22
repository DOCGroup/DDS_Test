/*
 (c) Copyright, Real-Time Innovations, 2005.  All rights reserved.
 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h> /*for sqrt */

#include "osapi/osapi_semaphore.h"
#include "transport/transport_log.h"
#include "clock/clock_highResolution.h"

#include "NDDSLatencyGlobalSettings.h"

#include "Stats.h"

class NDDSLatencyDataProcessor {

  private:
    int _sequenceNumber;
    RTIBool _gotValidEcho;
    int _count;
    int _packetsize;
    int _arrayIndex;

    struct RTIOsapiSemaphore* _sem;
    struct RTIClock *_clock;
    struct RTINtpTime _startTime;
    struct RTINtpTime _finishTime;
    struct RTINtpTime _recvSignaledTime;
    double _clockOverhead;

    double _sigmaRoundtripTime;
    double _sigmaRoundtripTimeSquared;
    double _sigmaRoundtripTimeArray[LATENCY_ROUND_MAX];
    double _sigmaRoundtripTimeSquaredArray[LATENCY_ROUND_MAX];
    int _packetsizeArray[LATENCY_ROUND_MAX];
    int _countArray[LATENCY_ROUND_MAX];

  public:
    ~NDDSLatencyDataProcessor();
    NDDSLatencyDataProcessor();
    RTIBool calculate_clock_overhead();
    RTIBool initialize(struct RTIClock *clock);
    void reset();
    RTIBool start_one_issue();
    void finish_one_issue_recv_thread();
    void start_one_round(int packetsize)
    {
  reset();
  _packetsize = packetsize;
  _sequenceNumber = 0;
    }
    void finish_one_round();
    int get_sequence_number() { return _sequenceNumber; }
    RTIBool echo_received();
    RTIBool is_finished() { return _gotValidEcho; }
    RTIOsapiSemaphoreStatus wait(const struct RTINtpTime*);
};

NDDSLatencyDataProcessor::~NDDSLatencyDataProcessor()
{
    RTIOsapiSemaphore_delete(_sem);
}
NDDSLatencyDataProcessor::NDDSLatencyDataProcessor()
    : _clock(NULL),
      _arrayIndex(0)
{}
RTIOsapiSemaphoreStatus NDDSLatencyDataProcessor::wait(
    const struct RTINtpTime* blockTime)
{
    return RTIOsapiSemaphore_take(_sem, blockTime);
}

RTIBool NDDSLatencyDataProcessor::calculate_clock_overhead() {
    RTIBool ok = RTI_FALSE;
    int i = 0;
    struct RTINtpTime beginTime = RTI_NTP_TIME_ZERO,
  clockRoundtripTime = RTI_NTP_TIME_ZERO;

    if (!_clock->reset(_clock)) {
  goto fin;
    }
    if (!_clock->getTime(_clock, &beginTime)) {
  goto fin;
    }
    for (i = 0; i < NUM_OF_LOOPS_CLOCK; ++i) {
  if (!_clock->getTime(_clock, &clockRoundtripTime)) {
      goto fin;
  }
    }
    RTINtpTime_decrement(clockRoundtripTime, beginTime);
    _clockOverhead = 1E6*RTINtpTime_toDouble(&clockRoundtripTime) /
  (double)NUM_OF_LOOPS_CLOCK;
    ok = RTI_TRUE;

 fin:
    return ok;
}

RTIBool NDDSLatencyDataProcessor::initialize(struct RTIClock *clock) {
    _clock = clock;
    reset();
    _sem = RTIOsapiSemaphore_new(RTI_OSAPI_SEMAPHORE_KIND_BINARY, NULL);
    return((RTIBool)_sem);
}

RTIBool NDDSLatencyDataProcessor::echo_received() { /* stop timer */
    _clock->getTime(_clock, &_finishTime);
    return RTI_TRUE;
}


RTIBool NDDSLatencyDataProcessor::start_one_issue() { /* start timer */
    _gotValidEcho = RTI_FALSE;
    return _clock->reset(_clock) && _clock->getTime(_clock, &_startTime);
}

void NDDSLatencyDataProcessor::reset() { /* start one new round (packetsize) */
    RTINtpTime_setZero(&_startTime);
    RTINtpTime_setZero(&_finishTime);
    RTINtpTime_setZero(&_recvSignaledTime);
    _gotValidEcho = RTI_FALSE;
    _count = -1;
    _packetsize = 4;
    _sigmaRoundtripTime             = 0.0;
    _sigmaRoundtripTimeSquared      = 0.0;
}

void NDDSLatencyDataProcessor::finish_one_issue_recv_thread() {
    RTINtpTime roundtrip = {0, 0};
    double roundtripInDouble = 0.0;

    ++_sequenceNumber;/* always increase the next sequence number */

    /* The total roundtrip time */
    RTINtpTime_subtract(roundtrip, _finishTime, _startTime);
    roundtripInDouble = 1E6*RTINtpTime_toDouble(&roundtrip);
    if (roundtripInDouble <= 0) {
  printf("***Warn: roundtrip time <= 0\n");
    }

    RTIOsapiSemaphore_give(_sem);
    _gotValidEcho = RTI_TRUE;

    /* throw away jitters caused by the OS */
    if (_count > 0 &&
  roundtripInDouble > 50 * _sigmaRoundtripTime/(double)_count) {
  return;
    }

    if (_count < 0) { // drop the first result since we do lazy alloc
  goto fin;
    }

    _sigmaRoundtripTime += roundtripInDouble;
    _sigmaRoundtripTimeSquared += (roundtripInDouble * roundtripInDouble);

 fin:
    ++_count;
}

void NDDSLatencyDataProcessor::finish_one_round()
{ /* print out result */
    double timeAve = _sigmaRoundtripTime/(double)_count;
    double variance = sqrt(_sigmaRoundtripTimeSquared/(double)_count
         - timeAve * timeAve);

    printf("%7d bytes: roundtrip %7.1f, roundtrip/2 %7.1f, std %5.1f\n",
     _packetsize, timeAve - _clockOverhead,
     (timeAve - _clockOverhead)/2, variance);

     _sigmaRoundtripTimeArray[_arrayIndex] = _sigmaRoundtripTime;
     _sigmaRoundtripTimeSquaredArray[_arrayIndex] = _sigmaRoundtripTimeSquared;
     _packetsizeArray[_arrayIndex] = _packetsize;
     _countArray[_arrayIndex] = _count;
     ++(_arrayIndex);
}

#ifndef JUST_WANT_DATA_PROCESSOR
class Bytes4Listener : public DDSDataReaderListener {

  private:
    NDDSLatencyDataProcessor *_dataProcessor;

  public:
    Bytes4Listener(NDDSLatencyDataProcessor *dp)
  : _dataProcessor(dp) {}
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
};

static RTIBool NddsPublisherMain(int nddsDomain,
                                int Size, int prime_num, int stats_num,
                                RTIBool isReliable,
                                RTIBool receiveOnMulticast)
{

  PubSub_Stats stats_ ("pub_stats",
                       prime_num,
                       stats_num,
                       Size);

    /*------------------------- declarations ----------------------------*/

    /* common declarations */
    RTIBool ok = RTI_FALSE;
    DDS_ReturnCode_t retcode = DDS_RETCODE_ERROR;
    const struct DDS_Duration_t sleepTime = {1,0}, waitTime = {0, 20*1000000};
    struct RTIClock *clock = RTIHighResolutionClock_new();
    NDDSLatencyDataProcessor dataProcessor;
    int i = 0, packetsize;
    DDS_Octet *dataBuffer = NULL;

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
    Bytes4DataWriter* latencyPacketDataWriter;
    DDS_DataWriterQos writer_qos;
    DDSDataWriterListener* writer_listener = NULL;

    /* Listener declarations */
    Bytes4Listener reader_listener(&dataProcessor);

    /* Data declarations */
    Bytes4 instance;
    DDS_InstanceHandle_t instance_handle = DDS_HANDLE_NIL;

    struct NDDS_Transport_UDPv4_Property_t udpv4Property
  = NDDS_TRANSPORT_UDPV4_PROPERTY_DEFAULT;
#ifdef RTI_SHARED_MEMORY
    struct NDDS_Transport_Shmem_Property_t shmemProperty
  = NDDS_TRANSPORT_SHMEM_PROPERTY_DEFAULT;
#endif
    NDDSConfigLogger* logger = NULL;

    if(Size > MAX_MSG_LENGTH) {
  printf("***Error: invalid parameter; Size > MAX_MSG_LENGTH\n");
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
  if(Size > UNFRAGMENTED_UDP_PACKET_SIZE_MAX - NDDS_OVERHEAD) {
      udpv4Property.no_zero_copy = RTI_TRUE;
  }

  if(NDDSTransportSupport::set_builtin_transport_property(
      participant, DDS_TRANSPORTBUILTIN_UDPv4,
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

    Bytes4TypeSupport::register_type(participant, LATENCY_TYPE_NAME);

    /* initialize topic_qos with default values */
    participant->get_default_topic_qos(data_topic_qos);
    data_topic_qos.ownership.kind = DDS_EXCLUSIVE_OWNERSHIP_QOS;
    echo_topic_qos = data_topic_qos;

    /* create and enable data_topic. This is topic for data from
       NDDSLatencyWriter to NDDSLatencyReader. */
    data_topic = participant->create_topic(
  LATENCY_DATA_TOPIC_NAME, LATENCY_TYPE_NAME,
  data_topic_qos, data_topic_listener, DDS_STATUS_MASK_NONE);
    if (data_topic == NULL) {
  printf("***Error: failed to create data topic\n");
  goto fin;
    }

    /* create and enable processedDataTopic. This is topic for data from
       NDDSLatencyReader to NDDSLatencyWriter. */
    echo_topic = participant->create_topic(
  LATENCY_ECHO_TOPIC_NAME, LATENCY_TYPE_NAME,
  echo_topic_qos, echo_topic_listener, DDS_STATUS_MASK_NONE);
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
  data_topic, writer_qos, writer_listener, DDS_STATUS_MASK_NONE);
    if (writer == NULL) {
  printf("***Error: failed to create writer\n");
  goto fin;
    }
    latencyPacketDataWriter = Bytes4DataWriter::narrow(writer);
    if (latencyPacketDataWriter == NULL) {
  printf("***Error: failed to narrow writer\n");
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
    reader = subscriber->create_datareader(echo_topic, reader_qos,
             NULL, DDS_STATUS_MASK_NONE);
    if (reader == NULL) {
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

/*--------------------------------------------------------------------------
  Misc initialization and set-up.
----------------------------------------------------------------------------*/

    if (clock == NULL
  || !dataProcessor.initialize(clock)) {
  printf("***Error: failed to initiate data processor or clock\n");
  goto fin;
    }


    /* set up the data buffer for user data */
    dataBuffer = (DDS_Octet *)calloc(Size, sizeof(DDS_Octet));
    if (dataBuffer == NULL) {
  printf("***Error: failed to create data buffer\n");
  goto fin;
    }
    instance.data.loan_contiguous(dataBuffer, Size, Size);

    /* calculate the overhead for clock->getTime() call */
    if (!dataProcessor.calculate_clock_overhead()) {
  printf("***Error: failed to calculate clock overhead\n");
  goto fin;
    }
    /*
    logger = NDDSConfigLogger::get_instance();
    logger->set_verbosity_by_category(NDDS_CONFIG_LOG_CATEGORY_ENTITIES,
              NDDS_CONFIG_LOG_VERBOSITY_STATUS_REMOTE);
    */
    /* We can detect that the readers have appeared by accessing the built-in
       reader, but we omit this in this example to keep the code simple, and
       just sleep a while, assuming that the readers will be discovered within
       this time.
    */
    for(i = 0; i < 8; ++i) {
  NDDSUtility::sleep(sleepTime);
    }

    /*------------------------ start the latency test ----------------------*/

/*--------------------------------------------------------------------------
  The core latency test is in the following for() loop.
----------------------------------------------------------------------------*/
    packetsize = Size;

  NDDSUtility::sleep(sleepTime);

  instance.data.length(packetsize);
//  dataProcessor.start_one_round(packetsize);


  int total_num = prime_num + stats_num;

  for (i = 0; i < total_num; ++i) {

    //      dataProcessor.start_one_issue();

     stats_.sample_for_throughput ();

      /* send the raw data to all interested parties */
      retcode = latencyPacketDataWriter->write(instance,
                 instance_handle);
      if (retcode != DDS_RETCODE_OK) {
    printf("***Error: failed to send data\n");
    goto fin;
      }

      /* wait until the echo message is received from the LatencyReader
      if(dataProcessor.wait((struct RTINtpTime*)&sleepTime)
         != RTI_OSAPI_SEMAPHORE_STATUS_OK) {
    printf("***Error: did not hear back echo in time\n");
    goto fin;
      } */
   } /* end of for (i) */


  if (stats_.ready_to_dump ())
    {
      stats_.file_dump_throughput ();
      printf ("results dumped\n");
    }


  /* one round (packetsize) finished. print out the result */
//  dataProcessor.finish_one_round();


    /* send to reader to terminate the reader */
    retcode = latencyPacketDataWriter->write(instance, instance_handle);

    if (retcode != DDS_RETCODE_OK) {
  printf("***Error: failed to send data\n");
  goto fin;
    }

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

    RTIHighResolutionClock_delete(clock);

    ok = RTI_TRUE;
 fin:
    if (!instance.data.has_ownership()) {
        instance.data.unloan();
        free(dataBuffer);
    }
    if (ok && retcode == DDS_RETCODE_OK) {
  printf("Test successfull!\n");
  return 0;
    } else {
  printf("Error! Test NOT successfull!\n");
  return -1;
    }
}

/*i called when received echo */
void Bytes4Listener::on_data_available(DDSDataReader* datareader)
{
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

    if (!_dataProcessor->echo_received()) {
  printf("***Error: failed to call echo_received\n");
    }

    if (retcode != DDS_RETCODE_OK) {
  printf("***Error: failed to access data from the reader\n");
    } else {
  // Examine every sample returned, but we actually only expect 1
  for (int i = 0; i < data_seq.length(); i++) {

      /* Must check the 'valid_data' because for some
         samples the data_seq[i] will be NULL */
//      if (info_seq[i].valid_data
//    && (data_seq[i].sequenceNumber
//        == _dataProcessor->get_sequence_number())) {
//    _dataProcessor->finish_one_issue_recv_thread();
//      }
  }
    }

    // Let the service know the application no longer needs the data and
    // info buffers
    reader->return_loan(data_seq, info_seq);
}
#endif//!JUST_WANT_DATA_PROCESSOR



#ifndef I_HAVE_MY_OWN_MAIN
int main(int argc, char **argv)
{
    int Size, nddsDomain = 89;
    int prime_num, stats_num;
    RTIBool useMulticast = RTI_FALSE;
    RTIBool isReliable = RTI_FALSE;

    const char *usageStr =
  "Usage: [-d #] [-minSize #] [-maxSize #] [-multicast] [-reliable]\n"
  "\t-d NDDS domain\n"
  "\t-minSize minimum payload size\n"
  "\t-maxSize maximum payload size\n"
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
  } else if (strncmp(argv[i], "-multicast", 10) == 0) {
      useMulticast = RTI_TRUE;
  } else if (strncmp(argv[i], "-reliable", 9) == 0) {
      isReliable = RTI_TRUE;
  } else {
      printf("%s", usageStr);
      return 0;
  }
    }

    return NddsPublisherMain(nddsDomain, Size, prime_num, stats_num,
           isReliable, useMulticast);

}
#endif//!I_HAVE_MY_OWN_MAIN