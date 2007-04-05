#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h> /*for sqrt */
#include <iostream>

//#include <getopt.h>

#include <fstream>

#include "osapi/osapi_semaphore.h"
#include "transport/transport_log.h"
#include "clock/clock_highResolution.h"

#include "GlobalSettings.h"

#include "ace/Env_Value_T.h"
#include "ace/Sched_Params.h"


#define TOTAL_PRIMER_SAMPLES 100
#define RESULT_FILE_NAME_MAX 1024
#define SCALAR 1
#define WAITBASED


using namespace std;

// This can be changed to the desired value.
const int PRIORITY =
  (ACE_Sched_Params::priority_min (ACE_SCHED_FIFO)
   + ACE_Sched_Params::priority_max (ACE_SCHED_FIFO)) / 2;

// Attempt to set the real time priority and lock memory.
void
set_rt (void) 
{
  int rt_status =
    ACE_OS::sched_params (ACE_Sched_Params (ACE_SCHED_FIFO,
                                            PRIORITY,
                                            ACE_SCOPE_PROCESS));
  
  if (rt_status != 0)
    {
      switch (ACE_OS::last_error ())
        {
          case EPERM:
            cout << "publisher: user is not superuser, "
                 << "test runs in time-shared class" << endl;
            break;
          case EINVAL:
            cout << "publisher: priority " << PRIORITY << " is invalid"
                 << "on this platform, test runs in time-shared class"
                 << endl;
            break;
          case ESRCH:
            cout << "publisher: process id " << ACE_SCOPE_PROCESS
                 << " not found, test runs in time-shared class"
                 << endl;
            break;
          default:
            // No other reasons why sched_params() can fail.
            break;
        }
    }
  else
    {
      cout << "publisher: real time priority successfully set!" << endl;
    }
}


static int isComplex = 0;
static char topic_id = 's';
int publication_matched = 0;
int NDDS_DEBUG_LEVEL = 0;
char resultsFile[RESULT_FILE_NAME_MAX] = "results";



typedef struct
{
    char name[20];
    double average;
    double min;
    double max;
    double sum;
    double sum2;
    int count;
} stats_type;

//
// Static functions
//

static void
add_stats (
    stats_type& stats,
    double data
    )
{
    stats.average = (stats.count * stats.average + data)/(stats.count + 1);
    stats.min     = (stats.count == 0 || data < stats.min) ? data : stats.min;
    stats.max     = (stats.count == 0 || data > stats.max) ? data : stats.max;
    stats.sum = stats.sum + data;
    stats.sum2 = stats.sum2 + data * data;
    stats.count++;
}

static void
init_stats (
    stats_type& stats,
    char *name)
{
    strncpy ((char *)stats.name, name, 19);
    stats.name[19] = '\0';
    stats.count    = 0;
    stats.average  = 0.0;
    stats.min      = 0.0;
    stats.max      = 0.0;
    stats.sum      = 0.0;
    stats.sum2     = 0.0;
}

static double
std_dev (stats_type& stats)
{
  if (stats.count >=2)
  {
    return sqrt ((static_cast<double>(stats.count) * stats.sum2 - stats.sum * stats.sum) / 
                (static_cast<double>(stats.count) * static_cast<double>(stats.count - 1)));
  }
}


class PubMessageListener : public DDSDataWriterListener 
{
private:
  int num_of_subs_;

public:

  PubMessageListener (void)
    : num_of_subs_(0)
  {}
  
  virtual ~PubMessageListener (void)
  {} 

  virtual void on_offered_deadline_missed (
    DDSDataWriter *, 
    const DDS_OfferedDeadlineMissedStatus &)
  {}

  virtual void on_liveliness_lost (DDSDataWriter *, 
                                   const DDS_LivelinessLostStatus &)
  {}

  virtual void on_offered_incompatible_qos (
    DDSDataWriter *,
    const DDS_OfferedIncompatibleQosStatus &)
  {}

  virtual void on_publication_matched (
    DDSDataWriter *writer,
    const DDS_PublicationMatchedStatus &status)
  {
    DDSTopic *topic = writer->get_topic ();

    ++this->num_of_subs_;
    if (1 == this->num_of_subs_)
      {
        publication_matched = 1;
      }

    if (NDDS_DEBUG_LEVEL > 0)
      {
        std::cout << "Discovered subscription: No. " << this->num_of_subs_ << std::endl;
        std::cout << " topic name:" << topic->get_name () << std::endl;

        std::cout << "total count" << status.total_count << std::endl;
        std::cout << "total count change" << status.total_count_change << std::endl;
        std::cout << "current count" << status.current_count << std::endl;
        std::cout << "current count change" << status.current_count_change << std::endl;
      }


  }
};


class AckMessageDataProcessor {

  private:
    stats_type round_trip;
    std::ofstream result_file;
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
    ~AckMessageDataProcessor();
    AckMessageDataProcessor();
    RTIBool calculate_clock_overhead();
    RTIBool initialize(struct RTIClock *clock);
    void reset();
    RTIBool start_one_issue();
    void finish_one_issue_recv_thread();
    void start_one_round(int packetsize)
    {
	reset();
	_packetsize = packetsize;
        result_file << packetsize - 4 << std::endl;
        
	_sequenceNumber = 0;
    }
    void finish_one_round();
    int get_sequence_number() { return _sequenceNumber; }
    RTIBool echo_received();
    RTIBool is_finished() { return _gotValidEcho; }
    RTIOsapiSemaphoreStatus wait(const struct RTINtpTime*);
};




AckMessageDataProcessor::~AckMessageDataProcessor()
{
    RTIOsapiSemaphore_delete(_sem);
    result_file.close ();
}
AckMessageDataProcessor::AckMessageDataProcessor()
    : _clock(NULL),
      _arrayIndex(0)
{
  init_stats (round_trip, "round_trip");
  result_file.open (resultsFile,ios_base::app);
}

RTIOsapiSemaphoreStatus AckMessageDataProcessor::wait(
    const struct RTINtpTime* blockTime)
{
    return RTIOsapiSemaphore_take(_sem, blockTime);
}

RTIBool AckMessageDataProcessor::calculate_clock_overhead() {
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

RTIBool AckMessageDataProcessor::initialize(struct RTIClock *clock) {
    _clock = clock;
    reset();
    _sem = RTIOsapiSemaphore_new(RTI_OSAPI_SEMAPHORE_KIND_BINARY, NULL);
    return((RTIBool)_sem);
}

RTIBool AckMessageDataProcessor::echo_received() { /* stop timer */
    _clock->getTime(_clock, &_finishTime); 
    return RTI_TRUE;
}


RTIBool AckMessageDataProcessor::start_one_issue() { /* start timer */
    _gotValidEcho = RTI_FALSE;
    return _clock->reset(_clock) && _clock->getTime(_clock, &_startTime);
}

void AckMessageDataProcessor::reset() { /* start one new round (packetsize) */
    RTINtpTime_setZero(&_startTime);
    RTINtpTime_setZero(&_finishTime);
    RTINtpTime_setZero(&_recvSignaledTime);
    _gotValidEcho = RTI_FALSE;
    _count = -1;
    _packetsize = 4;
    _sigmaRoundtripTime             = 0.0;
    _sigmaRoundtripTimeSquared      = 0.0;
}

void AckMessageDataProcessor::finish_one_issue_recv_thread() {
    RTINtpTime roundtrip = {0, 0};
    double roundtripInDouble = 0.0;

    ++_sequenceNumber;/* always increase the next sequence number */

    /* The total roundtrip time */
    RTINtpTime_subtract(roundtrip, _finishTime, _startTime);
    roundtripInDouble = 1E6*RTINtpTime_toDouble(&roundtrip);

    if (_sequenceNumber > TOTAL_PRIMER_SAMPLES)
    {
      add_stats (round_trip,
                 roundtripInDouble);
      result_file << roundtripInDouble << "\t";
    }


    //    printf("%7d bytes:  Count: %3d roundtrip %7.1f\n",
    //	   _packetsize, _count, roundtripInDouble);
    
    if (roundtripInDouble <= 0) {
	printf("***Warn: roundtrip time <= 0\n");
    }

    RTIOsapiSemaphore_give(_sem);
    _gotValidEcho = RTI_TRUE;

    /* throw away jitters caused by the OS */
    //    if (_count > 0 && 
    //roundtripInDouble > 50 * _sigmaRoundtripTime/(double)_count) {
    // return;
    //}

    if (_count < 0) { // drop the first result since we do lazy alloc
	goto fin;
    }
    
    _sigmaRoundtripTime += roundtripInDouble;
    _sigmaRoundtripTimeSquared += (roundtripInDouble * roundtripInDouble);

 fin:
    ++_count;
}

void AckMessageDataProcessor::finish_one_round()
{ /* print out result */
    double timeAve = _sigmaRoundtripTime/(double)_count;
    double variance = sqrt(_sigmaRoundtripTimeSquared/(double)_count
			   - timeAve * timeAve);

    printf("%7d bytes: clockoverhead %7.1f roundtrip %7.1f, roundtrip/2 %7.1f, std %5.1f\n",
	   _packetsize, _clockOverhead, timeAve,
	   (timeAve - _clockOverhead)/2, variance);

    result_file << std::endl;
    result_file << round_trip.min << std::endl;
    result_file << round_trip.max << std::endl;
    result_file << round_trip.average << std::endl;
    result_file << std_dev (round_trip) << std::endl;

    time_t clock = time (NULL);
    std::cout << "# MY Pub Sub measurements (in us) \n";
    std::cout << "# Executed at:" <<  ctime(&clock);
    std::cout << "#       Roundtrip time [us]\n";
    std::cout << "Count     mean      min      max   std_dev\n";
    std::cout << " "
              << round_trip.count
              << "        "
              << round_trip.average
              << "     "
              << round_trip.min
              << "      "
              << round_trip.max
              << "      "
              << std_dev (round_trip)
              << std::endl;


     _sigmaRoundtripTimeArray[_arrayIndex] = _sigmaRoundtripTime;
     _sigmaRoundtripTimeSquaredArray[_arrayIndex] = _sigmaRoundtripTimeSquared;
     _packetsizeArray[_arrayIndex] = _packetsize;
     _countArray[_arrayIndex] = _count;
     ++(_arrayIndex);
}

#ifndef JUST_WANT_DATA_PROCESSOR
class AckMessageListener : public DDSDataReaderListener {
    
  private:
    AckMessageDataProcessor *_dataProcessor;
    
  public:
    AckMessageListener(AckMessageDataProcessor *dp)
	: _dataProcessor(dp) {}
    virtual ~AckMessageListener() {} 

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
                                         const DDS_SubscriptionMatchedStatus& /*status*/) {};

    virtual void on_sample_lost(DDSDataReader* /*reader*/,
        const DDS_SampleLostStatus& /*status*/) {}

    virtual void on_data_available(DDSDataReader* /*reader*/);
};

static RTIBool NddsPublisherMain(int nddsDomain, 
				 int size, int count,
				 RTIBool isReliable,
				 RTIBool receiveOnMulticast)
{

    set_rt ();
  
    printf ("Size of corba long %ld\n", sizeof(DDS_Long));

    printf ("Size of nested %ld\n", sizeof(Nested));

    printf ("Size of outer %ld\n", sizeof(Outer));

    printf ("Size of data %ld\n", size * sizeof(PubMessage_Nest));

    /*------------------------- declarations ----------------------------*/

    /* common declarations */
    RTIBool ok = RTI_FALSE;
    DDS_ReturnCode_t retcode = DDS_RETCODE_ERROR;
    const struct DDS_Duration_t sleepTime = {1,0}, waitTime = {30, 0};
    struct RTIClock *clock = RTIHighResolutionClock_new();
    AckMessageDataProcessor dataProcessor;
    int i = 0, packetsize;
    DDS_Octet *dataBuffer = NULL;
    Outer *data_nestBuffer = NULL;
    Nested *data_nest_nestBuffer = NULL;
    DDS_Char *data_nest_nest_nestBuffer = NULL;
    

    

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

    /* Topic declarations */
    DDSTopic* data_nest_topic;
    DDS_TopicQos data_nest_topic_qos;
    DDSTopicListener* data_nest_topic_listener = NULL;

    DDSTopic* echo_topic;
    DDS_TopicQos echo_topic_qos;
    DDSTopicListener* echo_topic_listener = NULL;

    /* DataReader declarations */
    DDSDataReader* reader;
    DDS_DataReaderQos reader_qos;

    /* DataWriter declarations */
    DDSDataWriter* writer;
    PubMessageDataWriter* latencyPacketDataWriter;
    PubMessage_NestDataWriter *latencyPacket_NestDataWriter;

    DDS_DataWriterQos writer_qos;

    /* Listener declarations */
    AckMessageListener reader_listener(&dataProcessor);
    PubMessageListener writer_listener;

    /* Data declarations */
    PubMessage instance;
    DDS_InstanceHandle_t instance_handle = DDS_HANDLE_NIL;

    /* Data declarations */
    PubMessage_Nest instance_nest;
    DDS_InstanceHandle_t instance_nest_handle = DDS_HANDLE_NIL;



    DDSWaitSet wait_set;
    DDSConditionSeq_var condition_list;
    DDSStatusCondition condition;
    
'
    struct NDDS_Transport_UDPv4_Property_t udpv4Property
	= NDDS_TRANSPORT_UDPV4_PROPERTY_DEFAULT;
#ifdef RTI_SHARED_MEMORY
    struct NDDS_Transport_Shmem_Property_t shmemProperty
	= NDDS_TRANSPORT_SHMEM_PROPERTY_DEFAULT;
#endif
    NDDSConfigLogger* logger = NULL;

    if(size > MAX_MSG_LENGTH) {
	printf("***Error: invalid parameter; maxPacketSize > MAX_MSG_LENGTH\n");
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
    participant_qos.receiver_pool.buffer_size = 50 * 16384;//MAX_MSG_LENGTH * SCALAR+ NDDS_OVERHEAD;

    printf ("Buffer size %ld\n", participant_qos.receiver_pool.buffer_size);


    /* Default value is UDPv4 | SHMEM */

#ifdef RTI_SHARED_MEMORY
    /* If ONLY the shared memory transport plugin
       is used, you can tell NDDS NOT to instantiate its builtin UDPv4
       transport, and use smaller (a few bytes only) buffer size, because the
       shared memory plugin will lend its buffer to the user.
    */
    participant_qos.transport_builtin.mask |= DDS_TRANSPORTBUILTIN_SHMEM;
#endif//RTI_SHARED_MEMORY

#if ((MAX_MSG_LENGTH * SCALAR + NDDS_OVERHEAD + (14+20+8)) > 64*1024)
    participant_qos.transport_builtin.mask &= ~DDS_TRANSPORTBUILTIN_UDPv4;
#endif


    //ming: eliminate shared memory for remote test
    //      comment this line when running on localhost
    participant_qos.transport_builtin.mask &= ~DDS_TRANSPORTBUILTIN_SHMEM;

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

	udpv4Property.parent.message_size_max = 50 * 16384;//MAX_MSG_LENGTH * SCALAR + NDDS_OVERHEAD;
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
	    participant, DDS_TRANSPORTBUILTIN_UDPv4,
	    (struct NDDS_Transport_Property_t&)udpv4Property)
	   != DDS_RETCODE_OK) {
	    printf("***Error: failed to set default UDPv4 xport property\n");
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

    shmemProperty.parent.message_size_max = MAX_MSG_LENGTH * SCALAR + NDDS_OVERHEAD;
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

    PubMessageTypeSupport::register_type(participant, "DDSPerfTest::PubMessage");
					     
    /* initialize topic_qos with default values */
    participant->get_default_topic_qos(data_topic_qos);
    data_topic_qos.ownership.kind = DDS_EXCLUSIVE_OWNERSHIP_QOS;
    echo_topic_qos = data_topic_qos;
    
    /* create and enable data_topic. This is topic for data from 
       PubMessageWriter to PubMessageReader. */
    data_topic = participant->create_topic(
                                           "pubmessage_topic", // topic name
                                           "DDSPerfTest::PubMessage",// topic type
                                           data_topic_qos,
                                           data_topic_listener, DDS_STATUS_MASK_NONE);
    if (data_topic == NULL) {
	printf("***Error: failed to create data topic\n");
	goto fin;
    }


/*--------------------------------------------------------------------------
  Register data types, and create topics: echo_topic and data_topic
----------------------------------------------------------------------------*/ 

    PubMessage_NestTypeSupport::register_type(participant, "DDSPerfTest::PubMessage_Nest");
					     
    /* initialize topic_qos with default values */
    participant->get_default_topic_qos(data_nest_topic_qos);
    data_nest_topic_qos.ownership.kind = DDS_EXCLUSIVE_OWNERSHIP_QOS;
    
    /* create and enable data_topic. This is topic for data from 
       PubMessageWriter to PubMessageReader. */
    data_nest_topic = participant->create_topic(
                                           "pubmessage_nest_topic", // topic name
                                           "DDSPerfTest::PubMessage_Nest",// topic type
                                           data_nest_topic_qos,
                                           data_nest_topic_listener, DDS_STATUS_MASK_NONE);
    if (data_nest_topic == NULL) {
	printf("***Error: failed to create data topic\n");
	goto fin;
    }

/*--------------------------------------------------------------------------
  Register data types, and create topics: echo_topic and data_topic
----------------------------------------------------------------------------*/ 


    AckMessageTypeSupport::register_type(participant, "DDSPerfTest::AckMessage");

    /* create and enable processedDataTopic. This is topic for data from 
       PubMessageReader to PubMessageWriter. */
    echo_topic = participant->create_topic(
                                           "ackmessage_topic",//topic name
                                           "DDSPerfTest::AckMessage",//topic type
                                           echo_topic_qos,
                                           echo_topic_listener,DDS_STATUS_MASK_NONE);
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
    writer = publisher->create_datawriter(data_topic,
                                          writer_qos,
                                          0,
                                          DDS_STATUS_MASK_NONE);
    if (writer == NULL) {
	printf("***Error: failed to create writer\n");
	goto fin;
    }

    writer->set_listener (&writer_listener,
                          DDS_PUBLICATION_MATCHED_STATUS);

    latencyPacketDataWriter = PubMessageDataWriter::narrow(writer);
    if (latencyPacketDataWriter == NULL) {
	printf("***Error: failed to narrow writer\n");
	goto fin;
    }


/*--------------------------------------------------------------------------
  Create one data writer: (data_nest_)writer
----------------------------------------------------------------------------*/ 

    /* initialize writer_qos with default values */
    publisher->get_default_datawriter_qos(writer_qos);

    if(!isReliable) {//writer is reliable by default
	writer_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
    }

    /* create and enable writer. use data_topic. */
    writer = publisher->create_datawriter(data_nest_topic,
                                          writer_qos,
                                          0,
                                          DDS_STATUS_MASK_NONE);
    if (writer == NULL) {
	printf("***Error: failed to create writer\n");
	goto fin;
    }

    writer->set_listener (&writer_listener,
                           DDS_PUBLICATION_MATCHED_STATUS);

    latencyPacket_NestDataWriter = PubMessage_NestDataWriter::narrow(writer);
    if (latencyPacket_NestDataWriter == NULL) {
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

#ifndef WAITBASED
    retcode = reader->set_listener(&reader_listener, DDS_DATA_AVAILABLE_STATUS);
    if (retcode != DDS_RETCODE_OK) {
	printf("***Error: failed to set listener\n");
	goto fin;
    }
#elseif
    condition = reader->get_statuscondition ();
    condition.set_enabled_statues (DDS_DATA_AVAILABLE_STATUS);
    waitset.attach_condition (condition);
#endif

/*--------------------------------------------------------------------------
  Misc initialization and set-up.
----------------------------------------------------------------------------*/ 

    if (clock == NULL
	|| !dataProcessor.initialize(clock)) {
	printf("***Error: failed to initiate data processor or clock\n");
	goto fin;
    }
    
  
    if ('s' == topic_id)
      {
        /* set up the data buffer for user data */
        dataBuffer = (DDS_Octet *)calloc(size, sizeof(DDS_Octet));
        if (dataBuffer == NULL) {
          printf("***Error: failed to create data buffer\n");
          goto fin;
        }
        instance.data.loan_contiguous(dataBuffer, size, size);
      }
    else
      {
        /* set up the data buffer for user data */
        data_nestBuffer = (Outer *)calloc(size, sizeof(Outer));
        if (data_nestBuffer == NULL) {
          printf("***Error: failed to create nest data buffer\n");
          goto fin;
        }
        instance_nest.data.loan_contiguous(data_nestBuffer, size, size);
        data_nest_nestBuffer = (Nested *)calloc (1, sizeof (Nested));

        printf ("Size of allocated buffer %ld", size * (sizeof (Outer) + sizeof (Nested)));

        //        data_nest_nest_nestBuffer = DDS_String_alloc (8);
      }

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


    while (0 == publication_matched);

    printf ("At least one publication is matched!!!\n");

    for(i = 0; i < 8; ++i) {
	NDDSUtility::sleep(sleepTime);
    }

    /*------------------------ start the latency test ----------------------*/

/*--------------------------------------------------------------------------
  The core latency test is in the following for() loop.
----------------------------------------------------------------------------*/ 

    if ('s' == topic_id)
    {
      printf ("Start simple...\n");
      for(packetsize = size;
          packetsize <= size;
          packetsize *= 2) { // each round doubles payload

#ifndef WAITBASED

	NDDSUtility::sleep(sleepTime);

	instance.data.length(packetsize);
	dataProcessor.start_one_round(packetsize + sizeof (DDS_Long));


   
	for (i = 0; i < count; ++i) {

          instance.seqnum = dataProcessor.get_sequence_number();
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

#else
        std::cout << " start simple...." << std::endl;
        while( sample_num < total_samples ) {
       
          /* Put the sample number in as a sequence number */
          PubMessage pubmessage_data;

          pubmessage_data.seqnum = sample_num;

          // DPRINTF ("alloc size.. \n");
          pubmessage_data.data.length (size);

          struct timeval round_pre_t = tester::get_time ();

          result = pubmessage_writer->write (pubmessage_data,
                                             HANDLE_NIL);

              
          /* wait for a publication of sub node on subject "ackmessage_topic" */
          retcode = waitset.wait (condition_list.out (),
                                  waitTime);

          /* one way to measure roundtrip */
          gettimeofday(&end,NULL);

          int imax = condition_list->length ();

          if (imax != 0)
            {
              for (i = 0; i < imax; i++) 
                {
                  /* validate the condition to see if it's what we are waiting for */
                  if ((*conditionList)[i] == condition)
                    {

                      AckMessageSeq data_seq;
                      DDS_SampleInfoSeq info_seq;
                      DDS_ReturnCode_t retcode;

                      /* get all the data that the reader has received since the last 'take' */
                      retcode = reader->take(data_seq, info_seq, DDS_LENGTH_UNLIMITED,
                                             DDS_ANY_SAMPLE_STATE,
                                             DDS_ANY_VIEW_STATE,
                                             DDS_ANY_INSTANCE_STATE);


                      struct timeval round_post_t = tester::get_time ();


                      if (sample_num >= primer_samples)
                        {
                          add_stats (round_trip,
                                     1E6 * tester::time_to_real (tester::get_time_diff (round_post_t, round_pre_t)));
                        }

                      int amount = data_seq->length ();


                      if (amount != 0)
                        {
                          /* discard any extra messages */
                          if (amount > 1)
                            {
                              cout << "Splice2Test: Ignore excess messages :"
                                   << data_seq->length ()
                                   << " msg received" << endl;

                            }

                          sequence_number = (CORBA::Long)ackmessage_dataList [0].seqnum;


                          // @@Note: check the received senum (sequence_number )
                          //         to see if it matches the value we sent out 
                          if ( sequence_number != sample_num ) 
                            {
                              fprintf(stderr, 
                                      "ERROR - splice_pub: recieved seqnum %d on %d\n",
                                      sequence_number, sample_num);
                              exit (1);
                            }

                          //sample_num++;
                          result = ackmessage_reader->return_loan (ackmessage_dataList,
                                                                   infoList);
                       
                        }
                    }
                  else
                    {
                      cout << "SPLICE_PUB: unexpected condition triggered:"
                           << (*conditionList) [i]
                           << endl;
                      exit (1);
                    }
                }
            }
          sample_num++;

        }
#endif /* WAITBASED */



      } /* end of for (packetsize) */


      /* Set to final sequence number */
      instance.seqnum = FINAL_SEQUENCE_NUMBER;
    
      /* send to reader to terminate the reader */
      retcode = latencyPacketDataWriter->write(instance, instance_handle); 
    
      if (retcode != DDS_RETCODE_OK) {
	printf("***Error: failed to send data\n");
	goto fin;
      }
    
      NDDSUtility::sleep(sleepTime);
    }
    else if ('c' == topic_id)
    {
      printf ("Start complex...\n");

      for(packetsize = size;
          packetsize <= size;
          packetsize *= 2) { // each round doubles payload


	NDDSUtility::sleep(sleepTime);

        printf ("Set length...");
        instance_nest.data.length(packetsize);
        for (int j=0; j< packetsize; j++)
        {
          instance_nest.data[j].o_data.loan_contiguous (data_nest_nestBuffer, 1, 1);
          instance_nest.data[j].o_data.length (1);
          instance_nest.data[j].o_data[0].n_data = DDS_String_dup ("01234567");
        }

        printf ("Done\n");

	dataProcessor.start_one_round(packetsize + sizeof (DDS_Long));

        //        printf ("Done1\n");

   
	for (i = 0; i < count; ++i) {

          instance_nest.seqnum = dataProcessor.get_sequence_number();
          dataProcessor.start_one_issue();

          //          printf ("Done2\n");

          /* send the raw data to all interested parties */
          retcode = latencyPacket_NestDataWriter->write(instance_nest,
                                                        instance_nest_handle); 

          //printf ("Done3\n");

          if (retcode != DDS_RETCODE_OK) {
            printf("***Error: failed to send data\n");
            goto fin;
          }

          /* wait until the echo message is received from the LatencyReader */
          if(dataProcessor.wait((struct RTINtpTime*)&waitTime)
             != RTI_OSAPI_SEMAPHORE_STATUS_OK) {
            printf("***Error_nest: did not hear back echo in time\n");
            goto fin;
          }
	} /* end of for (i) */

	/* one round (packetsize) finished. print out the result */
	dataProcessor.finish_one_round();
      } /* end of for (packetsize) */


      /* Set to final sequence number */
      instance_nest.seqnum = FINAL_SEQUENCE_NUMBER;
    
      /* send to reader to terminate the reader */
      retcode = latencyPacket_NestDataWriter->write(instance_nest, instance_nest_handle); 
    
      if (retcode != DDS_RETCODE_OK) {
	printf("***Error: failed to send data\n");
	goto fin;
      }
    
      NDDSUtility::sleep(sleepTime);
    }

/*--------------------------------------------------------------------------
  The shutdown period.
----------------------------------------------------------------------------*/ 
   
    /*------------------------ tear down dds entities ----------------------*/
    retcode = subscriber->delete_datareader(reader);
    retcode = publisher->delete_datawriter(latencyPacketDataWriter);
    retcode = publisher->delete_datawriter(latencyPacket_NestDataWriter);
    retcode = participant->delete_topic(echo_topic);
    retcode = participant->delete_topic(data_nest_topic);
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

    if (!instance_nest.data.has_ownership()) {
        instance_nest.data.unloan();
        free(data_nestBuffer);
    }

    /*    if (!instance_nest.data.has_ownership()) {
        instance_nest.data.unloan();
        free(data_nestBuffer);
        }*/

    if (ok && retcode == DDS_RETCODE_OK) {
	printf("Pub:Test successfull!\n");
	return 0;
    } else {
	printf("Pub:Error! Test NOT successfull!\n");
	return -1;
    }
}


/*i called when received echo */
void AckMessageListener::on_data_available(DDSDataReader* datareader)
{
    AckMessageDataReader* reader = 
	AckMessageDataReader::narrow(datareader);
    AckMessageSeq data_seq;
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
		&& (data_seq[i].seqnum
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


#define OPTION_STRING  "cs:r:t:b:h"

#ifndef I_HAVE_MY_OWN_MAIN
int main(int argc, char **argv)
{
    int size = 4, count = 10000, nddsDomain = 89;
    RTIBool useMulticast = RTI_FALSE;
    RTIBool isReliable = RTI_FALSE;
   
    printf("Starting the publisher...\n");
    
    const char *usageStr =
	"Usage: [-d #] [-minSize #] [-maxSize #] [-multicast] [-reliable]\n"
	"\t-d NDDS domain\n"
	"\t-minSize minimum payload size\n"
	"\t-maxSize maximum payload size\n"
	"\t-multicast subscribe multicast\n"
	"\t-reliable request reliable service\n";


      ACE_Env_Value<int> envar ("NDDS_DEBUG_LEVEL", 0);

      NDDS_DEBUG_LEVEL = envar;

    printf("Beginning the argument parsing...\n");
      for (int i = 1; i < argc; i++) {
	if(strncmp(argv[i], "-r", 2) == 0) {
          strncpy(resultsFile,argv[i+1],RESULT_FILE_NAME_MAX);
          i++;
	} else if (strncmp(argv[i], "-d", 2) == 0) {
	    size = strtol(argv[++i], NULL, 10);
	} else if (strncmp(argv[i], "-s", 2) == 0) {
	    count = strtol(argv[++i], NULL, 10);
	} else if (strncmp(argv[i], "-multicast", 10) == 0) {
	    useMulticast = RTI_TRUE;
	} else if (strncmp(argv[i], "-reliable", 9) == 0) {
	    isReliable = RTI_TRUE;
	} else if (strncmp(argv[i], "-complex", 8) == 0) {
          printf ("here_1..\n");
            isComplex = 1;
	} else {
            printf("Sorry, don't understand %s. \n\n",argv[i]);
	    printf("%s", usageStr);
	    return 0;
	}
        }

    printf("Passed the argument parsing...\n");

    return NddsPublisherMain(nddsDomain, size, count,
			     isReliable, useMulticast);

}
#endif//!I_HAVE_MY_OWN_MAIN
