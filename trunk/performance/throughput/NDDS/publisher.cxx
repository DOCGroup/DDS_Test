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

#include "common.h"
#include "Stats.h"

#include "ace/Sched_Params.h"

const char * pub_output_file = "stats_pub";
const char * qos_config_file = "qos";
const char * net_config_file = "net";
const char * TEST_TOPIC_NAME = "TEST_TOPIC";
const char * TEST_ECHO_TOPIC_NAME = "TEST_ECHO_TOPIC";
const char * TEST_TOPIC_TYPE_NAME = "TEST_TOPIC_TYPE";


/* global QoS settings */
RTIBool QoS_KEEP_ALL = RTI_FALSE;
long QoS_MAX_SAMPLES_PER_INSTANCE = DDS_LENGTH_UNLIMITED;
long QoS_MAX_SAMPLES = DDS_LENGTH_UNLIMITED;
long QoS_MAX_INSTANCES = DDS_LENGTH_UNLIMITED;
long QoS_HISTORY_DEPTH = 1;

// This can be changed to the desired value.
const int PRIORITY =
  (ACE_Sched_Params::priority_min (ACE_SCHED_FIFO)
   + ACE_Sched_Params::priority_max (ACE_SCHED_FIFO)) / 2;

// Attempt to set the real time priority and lock memory.
int
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
      return -1;
    }
  else
    {
      printf ("Real time priority successfully set!\n");
      return 0;
    }
}


/**
 *
 * template data write
 * return -1 if failure
 * otherwise return 0
 */

template<typename T, typename W>
int dw_write (
              int size,
              int num_messages,
              DDSDataWriter *writer,
              PubSub_Stats & stats)
{
  T instance;
  int ret_val = 0;
  long i;
  W *dw;
  DDS_Octet *dataBuffer;
  DDS_ReturnCode_t retcode;

  /* narrow the generic data writer to a specific data writer*/
  dw = W::narrow (writer);

  if (dw == NULL) {
    ACE_DEBUG ((LM_DEBUG,
                "publisher (%P|%t): failed to narrow data writer\n"));
    ret_val = -1;
    goto fin;
  }

  /* set up the data buffer for user data */
  dataBuffer = (DDS_Octet *)calloc(size, sizeof(DDS_Octet));

  if (dataBuffer == NULL) {
    ACE_DEBUG ((LM_DEBUG,
                "publisher (%P|%t): failed to create data buffer\n"));
    ret_val = -1;
    goto fin;
  }


  instance.data.loan_contiguous(dataBuffer,
                                size,
                                size);

  // @@ this step can be ommited if the length set by the
  //    loan_contiguous is what we want it to be
  instance.data.length (size); // - sizeof (DDS_UnsignedLong));

  instance.timestamp = 0;


  for (i = 0; i < num_messages; ++i)
    {

      stats.sample_for_throughput (instance.timestamp);

      /* send the raw data to all interested parties */
      retcode = dw->write(instance,
                          DDS_HANDLE_NIL);

      if (retcode != DDS_RETCODE_OK)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "publisher (%P|%t): failed to write\n"));
          ret_val = -1;
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
      printf ("Dumping results...\n");
      stats.file_dump_throughput ();
    }



  for (i = 0; i < 15 * num_messages; ++i)
    {

      /* send the raw data to all interested parties */
      retcode = dw->write(instance,
                          DDS_HANDLE_NIL);

      if (retcode != DDS_RETCODE_OK)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "publisher (%P|%t): failed to write\n"));
          ret_val = -1;
          goto fin;
        }

      /* wait until the echo message is received from the LatencyReader
         if(dataProcessor.wait((struct RTINtpTime*)&sleepTime)
         != RTI_OSAPI_SEMAPHORE_STATUS_OK) {
         printf("***Error: did not hear back echo in time\n");
         goto fin;
         } */
    } /* end of for (i) */

fin:
  if (!instance.data.has_ownership()) {
    instance.data.unloan();
    free(dataBuffer);
  }

  return ret_val;
}





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
  if (NULL != _sem)
    {
      RTIOsapiSemaphore_delete(_sem);
    }
}
NDDSLatencyDataProcessor::NDDSLatencyDataProcessor()
    : _sem (NULL),
      _clock(NULL),
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



class TP_PacketDataWriterListener : public DDSDataWriterListener 
{
private:
  int num_of_subs_;

public:

  TP_PacketDataWriterListener()
    : num_of_subs_(0) {}
  
  virtual ~TP_PacketDataWriterListener() {} 

  virtual void on_offered_deadline_missed (DDSDataWriter *, 
                                           const DDS_OfferedDeadlineMissedStatus &) {}

  virtual void on_liveliness_lost(DDSDataWriter *, 
                                  const DDS_LivelinessLostStatus &) {}

  virtual void on_offered_incompatible_qos(DDSDataWriter *,
                                           const DDS_OfferedIncompatibleQosStatus &) {}

  virtual void on_publication_matched(DDSDataWriter *data_writer,
                                      const DDS_PublicationMatchedStatus &pub_stat);

};



#ifndef JUST_WANT_DATA_PROCESSOR
class NDDSLatencyPacketListener : public DDSDataReaderListener {
    
  private:
    NDDSLatencyDataProcessor *_dataProcessor;
    
  public:
    NDDSLatencyPacketListener(NDDSLatencyDataProcessor *dp)
	: _dataProcessor(dp) {}
    virtual ~NDDSLatencyPacketListener() {} 

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
                                 int thePacketSize,
                                 int prime_num,
                                 int stats_num,
				 RTIBool isReliable,
				 RTIBool receiveOnMulticast)
{
    int rt = set_rt ();

    printf ("=============Settings==============\n");

    if (0 == rt)
      {
        printf ("Real-Time Schedule = yes\n");
      }
    else
      {
        printf ("Real-Time Schedule = no\n");
      }

    printf ("MAX_MSG_LENGTH =  %d\n", MAX_MSG_LENGTH);

    printf ("max_samples_per_instances = %ld\n", QoS_MAX_SAMPLES_PER_INSTANCE);
    printf ("max_samples = %ld\n", QoS_MAX_SAMPLES);
    printf ("max_instances = %ld\n", QoS_MAX_INSTANCES);


    if (isReliable)
      {
        printf ("protocol = Reliable\n");
      }
    else
      {
        printf ("protocol = Best Effort \n");
      }


    if (receiveOnMulticast)
      {
        printf ("Multicast = Yes\n");
      }
    else
      {
        printf ("Multicast = No\n");
      }
    printf ("Notification_Type = N/A\n");
    if (QoS_KEEP_ALL)
      {
        printf ("History = KEEP_ALL\n");
      }
    else
      {
        printf ("History = KEEP_LAST\n");
      }

    printf ("History.depth = %d\n",QoS_HISTORY_DEPTH);

    printf ("=============Settings==============\n\n");


    // initiate stats file
    PubSub_Stats stats_ (pub_output_file,
                         prime_num,
                         stats_num,
                         thePacketSize);

    /*------------------------- declarations ----------------------------*/

    /* common declarations */
    RTIBool ok = RTI_FALSE;
    DDS_ReturnCode_t retcode = DDS_RETCODE_ERROR;
    // sleepTime for synchrinization, waitTime for echo message
    const struct DDS_Duration_t sleepTime = {1,0}, waitTime = {10, 0};
    struct RTIClock *clock = RTIHighResolutionClock_new();
    NDDSLatencyDataProcessor dataProcessor;
    int i = 0, packetsize, retval = 0;
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
    NDDSLatencyPacketDataWriter* latencyPacketDataWriter;
    DDS_DataWriterQos writer_qos;

    /* Listener declarations */
    NDDSLatencyPacketListener reader_listener(&dataProcessor);
    TP_PacketDataWriterListener writer_listener;

    /* Data declarations */
    NDDSLatencyPacket instance;
    DDS_InstanceHandle_t instance_handle = DDS_HANDLE_NIL;

    struct NDDS_Transport_UDPv4_Property_t udpv4Property
	= NDDS_TRANSPORT_UDPV4_PROPERTY_DEFAULT;
#ifdef RTI_SHARED_MEMORY
    struct NDDS_Transport_Shmem_Property_t shmemProperty
	= NDDS_TRANSPORT_SHMEM_PROPERTY_DEFAULT;
#endif
    NDDSConfigLogger* logger = NULL;

    if(thePacketSize > MAX_MSG_LENGTH) {
      ACE_DEBUG ((LM_DEBUG,
                  "publisher (%P|%t): invalid parameter; thePacketSize > MAX_MSG_LENGTH\n"));

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
        ACE_DEBUG ((LM_DEBUG,
                  "publisher (%P|%t): failed to get domain participant factory\n"));
	goto fin;
    }
    
    /* Do not auto enable participants upon creation since we want to register
       transport plugins */
    factory->get_qos(factoryQos);
    factoryQos.entity_factory.autoenable_created_entities = DDS_BOOLEAN_FALSE;

    if (factory->set_qos(factoryQos) != DDS_RETCODE_OK) {
        ACE_DEBUG ((LM_DEBUG,
                  "publisher (%P|%t): failed to set factory QoS\n"));
        goto fin;
    }    
    
    /* initialize participant_qos with default values */
    factory->get_default_participant_qos(participant_qos);

    //pick the same host_id on both publisher and the subscriber
    participant_qos.wire_protocol.rtps_host_id = 0x2;
    printf ("rtps_host_id: %ld, rtps_app_id: %ld\n",participant_qos.wire_protocol.rtps_host_id,
                                                    participant_qos.wire_protocol.rtps_app_id);
    
    /* writer's participant index is left as 0, the default */

    /* If you want to send message larger than the UDPv4 transport plugin's
       limit of 64 KB, you have to use a non-UDPv4 transport plugin, such as
       the shared memory transport (in which case you will be restricted to
       sending to readers on the SAME host).  Using your own pluggable transport
       is an option, but this example does NOT show to to plug in your own
       transport.
    */
    participant_qos.receiver_pool.buffer_size = MAX_MSG_LENGTH + NDDS_OVERHEAD + MY_OWN_TEST_OVERHEAD;

#ifdef RTI_SHARED_MEMORY
    printf ("Shared Memory Plug-in is installed! \n");

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

    printf ("Creating participant............");
    participant = factory->create_participant(domain_id,
					      participant_qos,
					      participant_listener,
					      DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        ACE_DEBUG ((LM_DEBUG,
                  "publisher (%P|%t): failed to create domain participant\n"));
	goto fin;
    }
    printf ("[Done]\n");

    if(participant_qos.transport_builtin.mask & DDS_TRANSPORTBUILTIN_UDPv4) {
	if(NDDSTransportSupport::get_builtin_transport_property(
	    participant, DDS_TRANSPORTBUILTIN_UDPv4,
	    (struct NDDS_Transport_Property_t&)udpv4Property)
	   != DDS_RETCODE_OK) {
            ACE_DEBUG ((LM_DEBUG,
                       "publisher (%P|%t): failed to get default UDPv4 xport property\n"));
	    goto fin;
	}

	udpv4Property.parent.message_size_max = MAX_MSG_LENGTH + NDDS_OVERHEAD + MY_OWN_TEST_OVERHEAD;
	udpv4Property.send_socket_buffer_size 
          = udpv4Property.parent.message_size_max;
	udpv4Property.recv_socket_buffer_size
          = 2 * udpv4Property.send_socket_buffer_size;


        printf ("udpv4Property: message_size_max = %d \n", udpv4Property.parent.message_size_max);
        printf ("udpv4Property: send_socker_buffer_size = %d \n", udpv4Property.send_socket_buffer_size);
        printf ("udpv4Property: recv_socket_buffer_size = %d \n", udpv4Property.recv_socket_buffer_size);

	/* if IP fragmentation unavoidable, don't use zbuf,
	   which will only slow NDDS down */

        printf ("maximum unfragmented udp packet size is %d\n", UNFRAGMENTED_UDP_PACKET_SIZE_MAX);
	if(thePacketSize > UNFRAGMENTED_UDP_PACKET_SIZE_MAX - NDDS_OVERHEAD) {
	    udpv4Property.no_zero_copy = RTI_TRUE;
	}

	if(NDDSTransportSupport::set_builtin_transport_property(
	    participant, DDS_TRANSPORTBUILTIN_UDPv4,
	    (struct NDDS_Transport_Property_t&)udpv4Property)
	   != DDS_RETCODE_OK) {
            ACE_DEBUG ((LM_DEBUG,
                       "publisher (%P|%t): failed to set UDPv4 xport property\n"));
	    goto fin;
	}
    }

#ifdef RTI_SHARED_MEMORY
    /* Do the same if NDDS shared memory transport is installed by default */
    if(NDDSTransportSupport::get_builtin_transport_property(
	participant, DDS_TRANSPORTBUILTIN_SHMEM,
	(struct NDDS_Transport_Property_t&)shmemProperty) != DDS_RETCODE_OK) {
        ACE_DEBUG ((LM_DEBUG,
                  "publisher (%P|%t): failed to get default shmem xport property\n"));
	goto fin;
    }

    shmemProperty.parent.message_size_max = MAX_MSG_LENGTH + NDDS_OVERHEAD + MY_OWN_TEST_OVERHEAD;
    shmemProperty.received_message_count_max = 8;
    shmemProperty.receive_buffer_size
	= (shmemProperty.received_message_count_max
	   * shmemProperty.parent.message_size_max);

    if(NDDSTransportSupport::set_builtin_transport_property(
	participant, DDS_TRANSPORTBUILTIN_SHMEM,
	(struct NDDS_Transport_Property_t&)shmemProperty) != DDS_RETCODE_OK) {
        ACE_DEBUG ((LM_DEBUG,
                  "publisher (%P|%t): failed to set shmem xport property\n"));
	goto fin;
    }
#endif//RTI_SHARED_MEMORY

    retcode = participant->enable();/* now bring up the participant */
    if (retcode != DDS_RETCODE_OK) {
        ACE_DEBUG ((LM_DEBUG,
                  "publisher (%P|%t): failed to enable participant\n"));
        goto fin;
    }
    
/*--------------------------------------------------------------------------
  Create a publisher and a subsciber, both with default QoSes.
----------------------------------------------------------------------------*/


    /* initialize publisher_qos with default values */
    participant->get_default_publisher_qos(publisher_qos);

    /* optionally modify publisher qos values here */

    /* create and enable publisher */
    printf ("Creating data publisher............");
    publisher = participant->create_publisher(publisher_qos,
					      publisher_listener,
					      DDS_STATUS_MASK_NONE);
    if (publisher == NULL) {
        ACE_DEBUG ((LM_DEBUG,
                  "publisher (%P|%t): failed to create publisher\n"));
	goto fin;
    }
    printf ("[Done]\n");


/*--------------------------------------------------------------------------
  Register data types, and create topics: echo_topic and data_topic
----------------------------------------------------------------------------*/ 



#ifdef I_HAVE_MY_OWN_TEST_CODES

  printf ("Registering participant with data type \"%s\"......", TEST_TOPIC_TYPE_NAME);

  switch (thePacketSize)
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
      break;
    default:
      ACE_DEBUG ((LM_DEBUG,
                  "subscriber (%P|%t): bad data size: %d\n", packetsize));
      goto fin;
    }

#else
    printf ("Registering participant with data type \"%s\"......", LATENCY_TYPE_NAME);

    NDDSLatencyPacketTypeSupport::register_type(participant, LATENCY_TYPE_NAME);
#endif /* I_HAVE_MY_OWN_TEST_CODES */

    printf ("[Done]\n");
					     
    /* initialize topic_qos with default values */
    participant->get_default_topic_qos(data_topic_qos);
    // each instance can only be owned by one DataWriter at a time
    data_topic_qos.ownership.kind = DDS_EXCLUSIVE_OWNERSHIP_QOS;
    data_topic_qos.resource_limits.max_samples_per_instance = QoS_MAX_SAMPLES_PER_INSTANCE;
    data_topic_qos.resource_limits.max_instances = QoS_MAX_INSTANCES;
    data_topic_qos.resource_limits.max_samples = QoS_MAX_SAMPLES;


    echo_topic_qos = data_topic_qos;
    
    /* create and enable data_topic. This is topic for data from 
       NDDSLatencyWriter to NDDSLatencyReader. */
    
#ifdef I_HAVE_MY_OWN_TEST_CODES

    printf ("Creating normal data topic \"%s\"......", TEST_TOPIC_NAME);

    data_topic = participant->create_topic(
                                           TEST_TOPIC_NAME,
                                           TEST_TOPIC_TYPE_NAME,
                                           data_topic_qos,
                                           data_topic_listener,
                                           DDS_STATUS_MASK_NONE);
#else

    printf ("Creating normal data topic \"%s\"......", LATENCY_DATA_TOPIC_NAME);


    data_topic = participant->create_topic(
                                           LATENCY_DATA_TOPIC_NAME,
                                           LATENCY_TYPE_NAME,
	                                   data_topic_qos,
                                           data_topic_listener,
                                           DDS_STATUS_MASK_NONE);

#endif /* I_HAVE_MY_OWN_TEST_CODES */

    if (data_topic == NULL) {
        ACE_DEBUG ((LM_DEBUG,
                  "publisher(%P|%t): failed to create data topic\n"));
	goto fin;
    }
    printf ("[Done]\n");





#ifdef I_HAVE_MY_OWN_TEST_CODES

    // NO ECHO participants

#else
    printf ("Creating echo data topic \"%s\"............", LATENCY_ECHO_TOPIC_NAME);
    echo_topic = participant->create_topic(LATENCY_ECHO_TOPIC_NAME,
                                           LATENCY_TYPE_NAME,
                                           echo_topic_qos,
                                           echo_topic_listener,
                                           DDS_STATUS_MASK_NONE);
    if (echo_topic == NULL) {
	printf("\n***Error: failed to create echo topic\n");
	goto fin;
    }
    printf ("[Done]\n");


    /* initialize subscriber_qos with default values */
    participant->get_default_subscriber_qos(subscriber_qos);

    /* optionally modify subscriber qos values */

    /* create and enable subscriber */
    printf ("Creating echo subscriber............");
    subscriber = participant->create_subscriber(subscriber_qos,
						subscriber_listener,
						DDS_STATUS_MASK_NONE);
    if (subscriber == NULL) {
	printf("***Error: failed to create subscriber\n");
	goto fin;
    }
    printf ("[Done]\n");



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

    
    /* create and enable reader, using echo_topic. */
    printf ("Creating echo reader from echo subscriber......");
    reader = subscriber->create_datareader(echo_topic,
                                           reader_qos,
					   NULL,
                                           DDS_STATUS_MASK_NONE);
    if (reader == NULL) {
	printf("***Error: failed to create reader\n");
	goto fin;
    }
    printf ("[Done]\n");
    
    /* setup reader to access received data via a listener 
       explicitly specify which operations in the listener are
       activated for callback
    */
    printf ("Setting echo reader listner............");
    retcode = reader->set_listener(&reader_listener,
                                   DDS_DATA_AVAILABLE_STATUS);
    if (retcode != DDS_RETCODE_OK) {
	printf("***Error: failed to set listener\n");
	goto fin;
    }
    printf ("[Done]\n");

#endif /* I_HAVE_MY_OWN_TEST_CODES */


/*--------------------------------------------------------------------------
  Create one data writer: (data_)writer
----------------------------------------------------------------------------*/ 

    /* initialize writer_qos with default values */
    publisher->get_default_datawriter_qos(writer_qos);

    if(!isReliable) {//writer is reliable by default
	writer_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
    }

    if (QoS_KEEP_ALL) {
      writer_qos.history.kind = DDS_KEEP_ALL_HISTORY_QOS;
    }
    writer_qos.history.depth = QoS_HISTORY_DEPTH;


    /* create and enable writer. use data_topic. */
    printf ("Creating data writer from data publisher......");
    writer = publisher->create_datawriter(data_topic,
                                          writer_qos,
                                          NULL,
                                          DDS_STATUS_MASK_NONE);
    if (writer == NULL) {
        ACE_DEBUG ((LM_DEBUG,
                   "publisher (%P|%t): failed to create data writer\n"));
	goto fin;
    }
    printf ("[Done]\n");


#ifdef I_WANT_TO_DEBUG

    printf ("Setting data writer listener for data writer......");
    retcode = writer->set_listener (
                                    &writer_listener,
                                    DDS_PUBLICATION_MATCHED_STATUS);
    if (retcode != DDS_RETCODE_OK) {
      ACE_DEBUG ((LM_DEBUG,
                  "publisher (%P|%t): failed to set data writer listener\n"));
      goto fin;
    }
    printf ("[Done]\n");

#endif
    


#ifdef I_HAVE_MY_OWN_TEST_CODES

    // NO-OP

#else

    // Narrow down the data writer

    latencyPacketDataWriter = NDDSLatencyPacketDataWriter::narrow(writer);
    if (latencyPacketDataWriter == NULL) {
	printf("***Error: failed to narrow writer\n");
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
    dataBuffer = (DDS_Octet *)calloc(thePacketSize, sizeof(DDS_Octet));
    if (dataBuffer == NULL) {
	printf("***Error: failed to create data buffer\n");
	goto fin;
    }
    instance.data.loan_contiguous(dataBuffer, thePacketSize, thePacketSize);

    /* calculate the overhead for clock->getTime() call */
    if (!dataProcessor.calculate_clock_overhead()) {
	printf("***Error: failed to calculate clock overhead\n");
	goto fin;
    }

#endif /* I_HAVE_MY_OWN_TEST_CODES */



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
    printf ("Waiting for subscribers to be discovered..\n");
    for(i = 0; i < 20; ++i) {
	NDDSUtility::sleep(sleepTime);
    }


    /*------------------------ start the latency test ----------------------*/

/*--------------------------------------------------------------------------
  The core latency test is in the following for() loop.
----------------------------------------------------------------------------*/ 


    packetsize = thePacketSize;


#ifdef I_HAVE_MY_OWN_TEST_CODES

    printf ("Start sending samples [I_HAVE_MY_OWN_TEST_CODES]..\n");

    NDDSUtility::sleep(sleepTime);


    switch (packetsize)
      {
      case 4:
        retval = dw_write< Bytes4,
          Bytes4DataWriter>
          (packetsize,
           prime_num + stats_num,
           writer,
           stats_);
        break;
      case 8:
        retval = dw_write< Bytes8,
          Bytes8DataWriter>
          (packetsize,
           prime_num + stats_num,
           writer,
           stats_);
        break;
      case 16:
        retval = dw_write< Bytes16,
          Bytes16DataWriter>
          (packetsize,
           prime_num + stats_num,
           writer,
           stats_);
        break;
      case 32:
        retval = dw_write< Bytes32,
          Bytes32DataWriter>
          (packetsize,
           prime_num + stats_num,
           writer,
           stats_);
        break;
      case 64:
        retval = dw_write< Bytes64,
          Bytes64DataWriter>
          (packetsize,
           prime_num + stats_num,
           writer,
           stats_);
        break;
      case 128:
        retval = dw_write< Bytes128,
          Bytes128DataWriter>
          (packetsize,
           prime_num + stats_num,
           writer,
           stats_);
        break;
      case 256:
        retval = dw_write< Bytes256,
          Bytes256DataWriter>
          (packetsize,
           prime_num + stats_num,
           writer,
           stats_);
        break;
      case 512:
        retval = dw_write< Bytes512,
          Bytes512DataWriter>
          (packetsize,
           prime_num + stats_num,
           writer,
           stats_);
        break;
      case 1024:
        retval = dw_write< Bytes1024,
          Bytes1024DataWriter>
          (packetsize,
           prime_num + stats_num,
           writer,
           stats_);
        break;
      case 2048:
        retval = dw_write< Bytes2048,
          Bytes2048DataWriter>
          (packetsize,
           prime_num + stats_num,
           writer,
           stats_);
        break;
      case 4096:
        retval = dw_write< Bytes4096,
          Bytes4096DataWriter>
          (packetsize,
           prime_num + stats_num,
           writer,
           stats_);
        break;
      case 8192:
        retval = dw_write< Bytes8192,
          Bytes8192DataWriter>
          (packetsize,
           prime_num + stats_num,
           writer,
           stats_);
        break;
      case 16384:
        retval = dw_write< Bytes16384,
          Bytes16384DataWriter>
          (packetsize,
           prime_num + stats_num,
           writer,
           stats_);
        break;
      default:
        ACE_DEBUG ((LM_DEBUG,
                    "subscriber (%P|%t): bad data size: %d\n", packetsize));
        goto fin;

      }

    if (-1 == retval) goto fin;

#else

    printf ("Start sending samples [NDDS_EXAMPLE_CODES]..\n");

    NDDSUtility::sleep(sleepTime);

    instance.data.length(packetsize - sizeof(DDS_Long));
    dataProcessor.start_one_round(packetsize);

    for (i = 0; i <= NUM_OF_LOOPS; ++i) {

      instance.sequenceNumber = dataProcessor.get_sequence_number();
      dataProcessor.start_one_issue();

      /* send the raw data to all interested parties */
      retcode = latencyPacketDataWriter->write(instance,
                                               instance_handle); 
      if (retcode != DDS_RETCODE_OK) {
        printf("***Error: failed to send data\n");
        goto fin;
      }

      /* wait until the echo message is received from the LatencyReader */
      if(dataProcessor.wait((struct RTINtpTime*)&waitTime)
         != RTI_OSAPI_SEMAPHORE_STATUS_OK) {
        printf("***Error: did not hear back echo in time\n");
        goto fin;
      }
    } /* end of for (i) */

    /* one round (packetsize) finished. print out the result */
    dataProcessor.finish_one_round();


    /* Set to final sequence number */
    instance.sequenceNumber = FINAL_SEQUENCE_NUMBER;
    
    /* send to reader to terminate the reader */
    retcode = latencyPacketDataWriter->write(instance, instance_handle); 
    
    if (retcode != DDS_RETCODE_OK) {
	printf("***Error: failed to send data\n");
	goto fin;
    }
    
#endif /* I_HAVE_OWN_TEST_CODES */

    NDDSUtility::sleep(sleepTime);

/*--------------------------------------------------------------------------
  The shutdown period.
----------------------------------------------------------------------------*/ 
   
    /*------------------------ tear down dds entities ----------------------*/


#ifdef I_HAVE_MY_OWN_TEST_CODES

    printf ("Deleting data entities ............");
    retcode = publisher->delete_datawriter(writer);
    retcode = participant->delete_topic(data_topic);
    retcode = participant->delete_publisher(publisher);
    printf ("[Done]\n");

#else

    printf ("Deleting data/echo entities ............");
    retcode = subscriber->delete_datareader(reader);
    retcode = publisher->delete_datawriter(writer);
    retcode = participant->delete_topic(echo_topic);
    retcode = participant->delete_topic(data_topic);
    retcode = participant->delete_subscriber(subscriber);
    retcode = participant->delete_publisher(publisher);
    printf ("[Done]\n");

#endif /* I_HAVE_MY_OWN_TEST_CODES */


    printf ("Deleting domain participant............");

    retcode = factory->delete_participant(participant);

    printf ("[Done]\n");


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

#ifdef I_HAVE_MY_OWN_TEST_CODES

    // NO-OP

#else

    if (!instance.data.has_ownership()) {
        printf ("Unloan instance data.............");
        instance.data.unloan();
        free(dataBuffer);
        printf ("[Done]\n");
    }

#endif /* I_HAVE_MY_OWN_TEST_CODES */

    if (ok && retcode == DDS_RETCODE_OK) {
	printf("Test successfull!\n");
	return 0;
    } else {
	printf("Error! Test NOT successfull!\n");
	return -1;
    }


}



void TP_PacketDataWriterListener::on_publication_matched( 
                                               DDSDataWriter *data_writer, 
                                               const DDS_PublicationMatchedStatus &pub_stat) 
{
  this->num_of_subs_++;
  printf("Discovered subscription: No.%d!\n", this->num_of_subs_);
}


/*i called when received echo */
void NDDSLatencyPacketListener::on_data_available(DDSDataReader* datareader)
{
    NDDSLatencyPacketDataReader* reader = 
	NDDSLatencyPacketDataReader::narrow(datareader);
    NDDSLatencyPacketSeq data_seq;
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
	    if (info_seq[i].valid_data
		&& (data_seq[i].sequenceNumber
		    == _dataProcessor->get_sequence_number())) {
		_dataProcessor->finish_one_issue_recv_thread();
	    }
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
    int nddsDomain = 89;
    int role = 0;
    int thePacketSize = 4;
    int prime_num, stats_num;
    RTIBool useMulticast = RTI_FALSE;
    RTIBool isReliable = RTI_FALSE;
   
    const char *usageStr =
	"Usage: [-d #] [-Size #] [-minSize #] [-maxSize #] [-multicast] [-reliable]\n"
	"\t-d NDDS domain\n"
	"\t-minSize minimum payload size\n"
	"\t-maxSize maximum payload size\n"
	"\t-multicast subscribe multicast\n"
	"\t-reliable request reliable service\n";

    for (int i = 1; i < argc; i++) {
      if(strcmp(argv[i], "-d") == 0) {
        nddsDomain = strtol(argv[++i], NULL, 10);
      } else if (strcmp(argv[i], "-role") == 0) {
        role = strtol(argv[++i], NULL, 10);
      } else if (strcmp(argv[i], "-Size") == 0) {
        thePacketSize = strtol(argv[++i], NULL, 10);
      } else if (strcmp(argv[i], "-pn") == 0) {
        prime_num = strtol(argv[++i], NULL, 10);
      } else if (strcmp(argv[i], "-sn") == 0) {
        stats_num = strtol(argv[++i], NULL, 10);
      } else if (strcmp(argv[i], "-msi") == 0) {
        QoS_MAX_SAMPLES_PER_INSTANCE  = strtol(argv[++i], NULL, 10);
      } else if (strcmp(argv[i], "-mxs") == 0) {
        QoS_MAX_SAMPLES = strtol(argv[++i], NULL, 10);
      } else if (strcmp(argv[i], "-mxi") == 0) {
        QoS_MAX_INSTANCES = strtol(argv[++i], NULL, 10);
      } else if (strcmp(argv[i], "-r") == 0) {
        pub_output_file = argv[++i];
      } else if (strcmp(argv[i], "-n") == 0) {
        net_config_file = argv[++i];
      } else if (strcmp(argv[i], "-q") == 0) {
        qos_config_file = argv[++i];
      } else if (strcmp(argv[i], "-top") == 0) {
        TEST_TOPIC_NAME = argv[++i];
      } else if (strcmp(argv[i], "-keep_all") == 0) {
        QoS_KEEP_ALL = RTI_TRUE;
      } else if (strcmp(argv[i], "-multicast") == 0) {
        useMulticast = RTI_TRUE;
      } else if (strcmp(argv[i], "-reliable") == 0) {
        isReliable = RTI_TRUE;
      } else if (strcmp(argv[i], "-depth") == 0 ) {
        QoS_HISTORY_DEPTH = strtol(argv[++i], NULL, 10);
      } else {
        ACE_DEBUG ((LM_DEBUG,
                    "publisher (%P|%t): Invalid argument: %s\n", argv[i]));
        ACE_DEBUG ((LM_DEBUG,
                    " %s\n", usageStr));
        return 0;
      }
    }

    return NddsPublisherMain(nddsDomain,
                             thePacketSize,
                             prime_num,
                             stats_num,
			     isReliable,
                             useMulticast);

}
#endif//!I_HAVE_MY_OWN_MAIN
