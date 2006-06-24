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
#include "common.h"
#include "Stats.h"

#include "ace/Sched_Params.h"

const char * sub_output_file = "stats_sub";
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
                      "subscriber (%P|%t): user is not superuser, "
                      "test runs in time-shared class\n"));
        }
      else
        {
          ACE_ERROR ((LM_ERROR,
                      "subscriber (%P|%t): sched_params failed\n"));
        }
      return -1;
    }
  else
    {
      printf ("Real time priority successfully set!\n");
      return 0;
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
      ACE_DEBUG ((LM_DEBUG,
                  "subscriber (%P|%t): failed to access data from the reader\n"));
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


class NDDSLatencyPacketListener : public DDSDataReaderListener {
    
  private:
    /* Data declarations */
    NDDSLatencyPacket _instance;
    DDS_InstanceHandle_t _instanceHandle;
    NDDSLatencyPacketDataWriter* _writer;
    int _sequenceNumber;



    int packetsize_;
    int prime_num_;
    int stats_num_;
    PubSub_Stats stats_;
    bool is_finished_;

  public:
    NDDSLatencyPacketListener(int packetsize,
                              int prime_num,
                              int stats_num)
	: _instanceHandle(DDS_HANDLE_NIL),
	  _writer(NULL),
	  _sequenceNumber(0),
          packetsize_ (packetsize),
          stats_ (sub_output_file, prime_num, stats_num, packetsize)
    {
      this->is_finished_ = false;
    }

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

    void set_writer(NDDSLatencyPacketDataWriter* writer) { _writer = writer; }

    /* test is finished if the sn received is FINAL */
    RTIBool is_finished()
    {
      #ifdef I_HAVE_MY_OWN_TEST_CODES
        return is_finished_;
      #else
        return _sequenceNumber == FINAL_SEQUENCE_NUMBER;
      #endif /* I_HAVE_MY_OWN_TEST_CODES */                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
    }
};

static RTIBool NddsSubscriberMain(int nddsDomain,
                                  int thePacketSize,
                                  int prime_num,
                                  int stats_num,
                                  int role,
                                  RTIBool isEchoer,
				  RTIBool isReliable,
				  RTIBool receiveOnMulticast,
                                  RTIBool receiveOnWaitSet)
{

    int rt = set_rt ();

    /*------------------------- declarations ----------------------------*/
    /* common declarations */

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
        printf ("protocol = Best effort \n");
      }
    if (receiveOnMulticast)
      {
        printf ("Multicast = Yes\n");
      }
    else
      {
        printf ("Multicast = No\n");

      }
    if (receiveOnWaitSet)
      {
        printf ("Notification_Type = wait-based\n");
      }
    else
      {
        printf ("Notification_Type = listener-based\n");
      }
    if (QoS_KEEP_ALL)
      {
        printf ("History = KEEP_ALL\n");
      }
    else
      {
        printf ("History = KEEP_LAST\n");
      }
    printf ("=============Settings==============\n\n");
    
    


    int i;

    ACE_CDR::ULong ts = 0;      // time stamp variable used for waitset
    RTIBool isFinished = RTI_FALSE; // used only for waitset


    // initiate stats file
    PubSub_Stats stats_ (sub_output_file,
                         prime_num,
                         stats_num,
                         thePacketSize);


    RTIBool ok = RTI_FALSE;
    DDS_ReturnCode_t retcode = DDS_RETCODE_ERROR;
    DDS_Duration_t sleepTime = {1,0};  /* 1 second */



    DDS_Duration_t waitTime = {500, 0}; /* WaitSet blocking timeout */
       
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
    DDSDataWriterListener* writer_listener = NULL;

    
    /* Listener declarations */
    NDDSLatencyPacketListener reader_listener (thePacketSize,
                                               prime_num,
                                               stats_num);


    /* WaitSet declarations */
    DDSWaitSet *waitset = new DDSWaitSet ();
    DDSStatusCondition *condition;
    DDSConditionSeq conditionList;

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
        ACE_DEBUG ((LM_DEBUG,
                  "subscriber (%P|%t): failed to get domain participant factory\n"));
	goto finally;
    }
    
    /* Do not auto enable participants upon creation since we want to register
       transport plugins
    */
    factory->get_qos(factoryQos);
    factoryQos.entity_factory.autoenable_created_entities = DDS_BOOLEAN_FALSE;

    if (factory->set_qos(factoryQos) != DDS_RETCODE_OK) {
        ACE_DEBUG ((LM_DEBUG,
                  "subscriber (%P|%t): failed to set factory QoS\n"));
        goto finally;
    }    
    

    /* initialize participant_qos with default values. similiar to 
       LatencyWriter setup*/
    factory->get_default_participant_qos(participant_qos);
    /* regardless of where the reader app runs, force the host_id, so we can
       make the send order deterministic (b/c order is decided by hostId-appId)
       pick the same host_id on both publisher and the subscriber
    */
    participant_qos.wire_protocol.rtps_host_id = 0x2;
    participant_qos.wire_protocol.rtps_app_id = role;
    printf ("rtps_host_id: %ld, rtps_app_id: %ld\n",participant_qos.wire_protocol.rtps_host_id,
                                                    participant_qos.wire_protocol.rtps_app_id);


    participant_qos.discovery.participant_index	= role;// > 0

    participant_qos.receiver_pool.buffer_size = MAX_MSG_LENGTH + NDDS_OVERHEAD + MY_OWN_TEST_OVERHEAD;

#ifdef RTI_SHARED_MEMORY
    printf ("Shared Memory Plug-in is installed! \n");

    participant_qos.transport_builtin.mask |= DDS_TRANSPORTBUILTIN_SHMEM;
#endif

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
                  "subscriber (%P|%t): failed to create domain participant\n"));
	goto finally;
    }
    printf ("[Done]\n");

    
    if(NDDSTransportSupport::get_builtin_transport_property(
	participant, DDS_TRANSPORTBUILTIN_UDPv4,
	(struct NDDS_Transport_Property_t&)udpv4Property) != DDS_RETCODE_OK) {
        ACE_DEBUG ((LM_DEBUG,
                  "subscriber (%P|%t): failed to get default UDPv4 xport property\n"));
	goto finally;
    }

    udpv4Property.parent.message_size_max = MAX_MSG_LENGTH + NDDS_OVERHEAD + MY_OWN_TEST_OVERHEAD;
    udpv4Property.send_socket_buffer_size
	= udpv4Property.parent.message_size_max;
    udpv4Property.recv_socket_buffer_size
	= 2 * udpv4Property.send_socket_buffer_size;
    //udpv4Property.no_zero_copy = RTI_TRUE;

    if(NDDSTransportSupport::set_builtin_transport_property(
	participant, DDS_TRANSPORTBUILTIN_UDPv4,
	(struct NDDS_Transport_Property_t&)udpv4Property) != DDS_RETCODE_OK) {
        ACE_DEBUG ((LM_DEBUG,
                  "subscriber (%P|%t): failed to set UDPv4 xport property\n"));
	goto finally;
    }

#ifdef RTI_SHARED_MEMORY
    /* Do the same if NDDS shared memory transport is installed by default */
    if(NDDSTransportSupport::get_builtin_transport_property(
	participant, DDS_TRANSPORTBUILTIN_SHMEM,
	(struct NDDS_Transport_Property_t&)shmemProperty) != DDS_RETCODE_OK) {
        ACE_DEBUG ((LM_DEBUG,
                  "subscriber (%P|%t): failed to get default shmem xport property\n"));
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
        ACE_DEBUG ((LM_DEBUG,
                  "subscriber (%P|%t): failed to set shmem xport property\n"));
	goto finally;
    }
#endif //RTI_SHARED_MEMORY

    retcode = participant->enable();
    if (retcode != DDS_RETCODE_OK) {
        ACE_DEBUG ((LM_DEBUG,
                  "subscriber (%P|%t): failed to enable participant\n"));
        goto finally;
    }
    
/*--------------------------------------------------------------------------
  Create a publisher and a subsciber
----------------------------------------------------------------------------*/

    /* initialize subscriber_qos with default values */
    participant->get_default_subscriber_qos(subscriber_qos);

    /* optionally modify subscriber QoS */

    /* create and enable subscriber */
    printf ("Creating data subscriber............");
    subscriber = participant->create_subscriber(subscriber_qos,
						subscriber_listener,
						DDS_STATUS_MASK_NONE);
    if (subscriber == NULL) {
        ACE_DEBUG ((LM_DEBUG,
                  "subscriber (%P|%t): failed to create subscriber\n"));
	goto finally;
    }
    printf ("[Done]\n");


/*--------------------------------------------------------------------------
  Register data types, and create topics: data_topic and echo_topic.
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
                  "subscriber (%P|%t): bad data size: %d\n", thePacketSize));
      goto finally;

    }
#else
    printf ("Registering participant with data type \"%s\"......", LATENCY_TYPE_NAME);

    NDDSLatencyPacketTypeSupport::register_type(participant, LATENCY_TYPE_NAME);
#endif

    printf ("[Done]\n");
					     
    /* initialize topic_qos with default values */
    participant->get_default_topic_qos(data_topic_qos);
    // each instance can only be owned by one DataWriter at a time
    data_topic_qos.ownership.kind = DDS_EXCLUSIVE_OWNERSHIP_QOS;


    data_topic_qos.resource_limits.max_samples_per_instance = QoS_MAX_SAMPLES_PER_INSTANCE;
    data_topic_qos.resource_limits.max_instances = QoS_MAX_INSTANCES;
    data_topic_qos.resource_limits.max_samples = QoS_MAX_SAMPLES;
    

    /* create and enable data_topic. for issue from LatencyWriter to 
       LatencyReader */

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
    data_topic = participant->create_topic(LATENCY_DATA_TOPIC_NAME,
                                           LATENCY_TYPE_NAME,
                                           data_topic_qos,
                                           data_topic_listener,
                                           DDS_STATUS_MASK_NONE);
#endif /* I_HAVE_MY_OWN_TEST_CODES */

    if (data_topic == NULL) {
        ACE_DEBUG ((LM_DEBUG,
                  "subscriber (%P|%t): failed to create data topic\n"));
	goto finally;
    }
    printf ("[Done]\n");


    if(isEchoer) {

#ifdef I_HAVE_MY_OWN_TEST_CODES

      // no-op for now

#else

        printf ("Whoops! I am the echoer... \n");
	/* create and enable echo_topic. for issue from LatencyReader to
	   LatencyWrtier */
	echo_topic_qos = data_topic_qos;

        printf ("Creating echo data topic \"%s\"............", LATENCY_ECHO_TOPIC_NAME);
	echo_topic = participant->create_topic(
	    LATENCY_ECHO_TOPIC_NAME, LATENCY_TYPE_NAME,
	    echo_topic_qos, echo_topic_listener, DDS_STATUS_MASK_NONE);
	if (echo_topic == NULL) {
            ACE_DEBUG ((LM_DEBUG,
                       "subscriber (%P|%t): failed to create echo topic\n"));
	    goto finally;
	}
        printf ("[Done]\n");


	/* initialize publisher_qos with default values */
	participant->get_default_publisher_qos(publisher_qos);

	/* optionally modify publisher qos values */

	/* create and enable publisher */
        printf ("Creating echo publisher............");
	publisher = participant->create_publisher(publisher_qos,
						  publisher_listener,
						  DDS_STATUS_MASK_NONE);
	if (publisher == NULL) {
            ACE_DEBUG ((LM_DEBUG,
                       "subscriber (%P|%t): failed to create publisher\n"));
	    goto finally;
	}
        printf ("[Done]\n");

	/*----------------------------------------------------------------
	  Create one data writer: (echo_)writer
	  ---------------------------------------------------------------*/ 

	/* initialize writer_qos with default values */
	publisher->get_default_datawriter_qos(writer_qos);

	if(!isReliable) {//writer is reliable by default
	    writer_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
	}

	/* create and enable writer */
        printf ("Creating echo writer from echo publisher......");
	writer = publisher->create_datawriter(
	    echo_topic, writer_qos, writer_listener, DDS_STATUS_MASK_NONE);
	if (writer == NULL) {
            ACE_DEBUG ((LM_DEBUG,
                        "subscriber (%P|%t): failed to create echo writer\n"));
	    goto finally;
	}
        printf ("[Done]\n");


	latencyPacketDataWriter = NDDSLatencyPacketDataWriter::narrow(writer);
	if (latencyPacketDataWriter == NULL) {
            ACE_DEBUG ((LM_DEBUG,
                       "subscriber (%P|%t): failed to narrow echo writer\n"));
	    goto finally;
	}

	reader_listener.set_writer(latencyPacketDataWriter);

#endif /* I_HAVE_MY_OWN_TEST_CODES */

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

    if (QoS_KEEP_ALL) {
      reader_qos.history.kind = DDS_KEEP_ALL_HISTORY_QOS;
    }

    if(receiveOnMulticast) {
	reader_qos.multicast.value.ensure_length(1,1);
	reader_qos.multicast.value[0].receive_address
	    = DDS_String_dup("225.1.2.3");
    }

    /* create and enable reader without listener at first */
    printf ("Creating data reader from data subscriber......");
    reader = subscriber->create_datareader(data_topic, reader_qos,
					   NULL, DDS_STATUS_MASK_NONE);
    if (reader == NULL) {
        ACE_DEBUG ((LM_DEBUG,
                  "subscriber (%P|%t): failed to create data reader\n"));
	goto finally;
    }

    printf ("[Done]\n");



    if (receiveOnWaitSet)
      {
        /* create condition for data reader waitset */
        printf ("Setting WaitSet condition for data reader...");
        condition = reader->get_statuscondition ();
        condition->set_enabled_statuses (DDS_DATA_AVAILABLE_STATUS);

        retcode = waitset->attach_condition (condition);

        if (retcode != DDS_RETCODE_OK)
          {
            ACE_DEBUG ((LM_DEBUG,
                        "subscriber (%P|%t): failed to set waitset condition\n"));
            goto finally;
          }
        printf ("[Done]\n");
      }
    else
      {

        /* setup reader to access received data via a listener 
           explicitly specify which operations in the listener are
           activated for callback
        */
        printf ("Setting data reader listner for data reader...");
        retcode = reader->set_listener(
                                       &reader_listener, 
                                       DDS_DATA_AVAILABLE_STATUS/* | DDS_SAMPLE_REJECTED_STATUS */);
        if (retcode != DDS_RETCODE_OK) {
          ACE_DEBUG ((LM_DEBUG,
                      "subscriber (%P|%t): failed to set data reader listener\n"));
          goto finally;
        }
        printf ("[Done]\n");
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


#ifdef I_HAVE_MY_OWN_TEST_CODES
      printf ("Start receiving data [I_HAVE_MY_OWN_TEST_CODES]..\n");
#else
      printf ("Start receiving data [NDDS_EXAMPLE_CODES]..\n");
#endif /* I_HAVE_MY_OWN_TEST_CODES */


    if (receiveOnWaitSet) // wait-based
      {
        while (!isFinished)
          {
            retcode = waitset->wait (conditionList, waitTime);

            if (0 == conditionList.length ())
              {
                ACE_DEBUG ((LM_DEBUG,
                            "subscriber (%P|%t): No conditions triggered\n"));
                goto finally;
              }
            else
              {
                for (i = 0; i < conditionList.length (); i++)
                  {
                    if (condition == conditionList[i])
                      {
                        switch (thePacketSize)
                          {
                          case 4:
                            ts = 
                              dr_read< Bytes4,
                              Bytes4Seq,
                              Bytes4DataReader>
                              (reader);
                            break;
                          case 8:
                            ts = 
                              dr_read< Bytes8,
                              Bytes8Seq,
                              Bytes8DataReader>
                              (reader);
                            break;
                          case 16:
                            ts = 
                              dr_read< Bytes16,
                              Bytes16Seq,
                              Bytes16DataReader>
                              (reader);
                            break;
                          case 32:
                            ts = 
                              dr_read< Bytes32,
                              Bytes32Seq,
                              Bytes32DataReader>
                              (reader);
                            break;
                          case 64:
                            ts = 
                              dr_read< Bytes64,
                              Bytes64Seq,
                              Bytes64DataReader>
                              (reader);
                            break;
                          case 128:
                            ts = 
                              dr_read< Bytes128,
                              Bytes128Seq,
                              Bytes128DataReader>
                              (reader);
                            break;
                          case 256:
                            ts = 
                              dr_read< Bytes256,
                              Bytes256Seq,
                              Bytes256DataReader>
                              (reader);
                            break;
                          case 512:
                            ts = 
                              dr_read< Bytes512,
                              Bytes512Seq,
                              Bytes512DataReader>
                              (reader);
                            break;
                          case 1024:
                            ts = 
                              dr_read< Bytes1024,
                              Bytes1024Seq,
                              Bytes1024DataReader>
                              (reader);
                            break;
                          case 2048:
                            ts = 
                              dr_read< Bytes2048,
                              Bytes2048Seq,
                              Bytes2048DataReader>
                              (reader);
                            break;
                          case 4096:
                            ts = 
                              dr_read< Bytes4096,
                              Bytes4096Seq,
                              Bytes4096DataReader>
                              (reader);
                            break;
                          case 8192:
                            ts = 
                              dr_read< Bytes8192,
                              Bytes8192Seq,
                              Bytes8192DataReader>
                              (reader);
                            break;
                          case 16384:
                            ts = 
                              dr_read< Bytes16384,
                              Bytes16384Seq,
                              Bytes16384DataReader>
                              (reader);
                            break;
                          default:
                            ACE_DEBUG ((LM_DEBUG,
                                        "subscriber (%P|%t): bad data size: %d\n", thePacketSize));
                            break;
                          };

                        stats_.sample_for_throughput (ts, true);

                        if (stats_.ready_to_dump ())
                          {
                            printf ("Dumping results...\n");
                            stats_.file_dump_throughput ();
                            isFinished = RTI_TRUE;
                          }
                    
                      }
                    else
                      {
                        ACE_DEBUG ((LM_DEBUG,
                                    "incorrect conditions caught...\n"));
                      }
                  }
              }
            
          }
        
      }
    else  // listener-based by default 
      {
        /* passively receive issue and echo back */
        while (!reader_listener.is_finished()) {
          NDDSUtility::sleep(sleepTime);
        }

      }

    /*------------------------ tear down dds entities ----------------------*/

/*--------------------------------------------------------------------------
  The shutdown phase.
----------------------------------------------------------------------------*/ 
    if(isEchoer) {

#ifdef I_HAVE_MY_OWN_TEST_CODES

      // no op

#else
      printf ("Deleting echo entiries............");
      retcode = publisher->delete_datawriter(writer);
      retcode = participant->delete_publisher(publisher);
      retcode = participant->delete_topic(echo_topic);
      printf ("[Done]\n");
#endif /* I_HAVE_MY_OWN_TEST_CODES */
    }

    printf ("Deleting data entities............");
    retcode = subscriber->delete_datareader(reader);
    retcode = participant->delete_subscriber(subscriber);
    retcode = participant->delete_topic(data_topic);
    printf ("[Done]\n");

    printf ("Deleting domain participant............");
    retcode = factory->delete_participant(participant);
    printf ("[Done]\n");


    printf ("Deleting data reader waitset............");
    delete waitset;
    waitset = NULL;
    printf ("[Done]\n");


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


void NDDSLatencyPacketListener::on_data_available(DDSDataReader* datareader)
{
#ifdef I_HAVE_MY_OWN_TEST_CODES


  ACE_CDR::ULong ts = 0;
  
  switch (this->packetsize_)
    {
    case 4:
      ts = 
        dr_read< Bytes4,
        Bytes4Seq,
        Bytes4DataReader>
        (datareader);
      break;
    case 8:
      ts = 
        dr_read< Bytes8,
        Bytes8Seq,
        Bytes8DataReader>
        (datareader);
      break;
    case 16:
      ts = 
        dr_read< Bytes16,
        Bytes16Seq,
        Bytes16DataReader>
        (datareader);
      break;
    case 32:
      ts = 
        dr_read< Bytes32,
        Bytes32Seq,
        Bytes32DataReader>
        (datareader);
      break;
    case 64:
      ts = 
        dr_read< Bytes64,
        Bytes64Seq,
        Bytes64DataReader>
        (datareader);
      break;
    case 128:
      ts = 
        dr_read< Bytes128,
        Bytes128Seq,
        Bytes128DataReader>
        (datareader);
      break;
    case 256:
      ts = 
        dr_read< Bytes256,
        Bytes256Seq,
        Bytes256DataReader>
        (datareader);
      break;
    case 512:
      ts = 
        dr_read< Bytes512,
        Bytes512Seq,
        Bytes512DataReader>
        (datareader);
      break;
    case 1024:
      ts = 
        dr_read< Bytes1024,
        Bytes1024Seq,
        Bytes1024DataReader>
        (datareader);
      break;
    case 2048:
      ts = 
        dr_read< Bytes2048,
        Bytes2048Seq,
        Bytes2048DataReader>
        (datareader);
      break;
    case 4096:
      ts = 
        dr_read< Bytes4096,
        Bytes4096Seq,
        Bytes4096DataReader>
        (datareader);
      break;
    case 8192:
      ts = 
        dr_read< Bytes8192,
        Bytes8192Seq,
        Bytes8192DataReader>
        (datareader);
      break;
    case 16384:
      ts = 
        dr_read< Bytes16384,
        Bytes16384Seq,
        Bytes16384DataReader>
        (datareader);
      break;
    default:
      ACE_DEBUG ((LM_DEBUG,
                  "subscriber (%P|%t): bad data size: %d\n", this->packetsize_));
      break;
    };

  this->stats_.sample_for_throughput (ts, false);

  if (this->stats_.ready_to_dump ())
    {
      printf ("Dumping results...\n");
      this->stats_.file_dump_throughput ();
      this->is_finished_ = true;
    }


#else
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

    if (retcode != DDS_RETCODE_OK) {
        ACE_DEBUG ((LM_DEBUG,
                  "subscriber (%P|%t): failed to access data from the reader\n"));
    } else {
	// Examine every sample returned
	for (int i = 0; i < data_seq.length(); i++) {

	    /* Must check the 'valid_data' because for some
	       samples the data_seq[i] will be NULL */
	    if (info_seq[i].valid_data) {
		_sequenceNumber = data_seq[i].sequenceNumber;
		_instance.sequenceNumber = _sequenceNumber;
		_instance.data.loan_contiguous(data_seq[i].data.
						get_contiguous_bufferI(),
						data_seq[i].data.length(),
						data_seq[i].data.maximum());


		if(_writer) { // echo back to the originator
                    printf ("sending out echo message ...\n");
		    retcode = _writer->write(_instance, _instanceHandle); 
		    if (retcode != DDS_RETCODE_OK) {
                        ACE_DEBUG ((LM_DEBUG,
                                    "subscriber (%P|%t): failed to send data\n"));
		    }
		}
		_instance.data.unloan();/* return loan */
	    }
	}
    }

    // Let the service know the application no longer needs the data and
    // info buffers
    reader->return_loan(data_seq, info_seq);
#endif /* I_HAVE_MY_OWN_TEST_CODES */
}

int main(int argc, char *argv[])
{
    int nddsDomain = 89;
    int role = 1; //translates to participant index
    int thePacketSize = 4;
    RTIBool thisSubscriberIsEchoer = RTI_TRUE;
    RTIBool useMulticast = RTI_FALSE;
    RTIBool isReliable = RTI_FALSE;
    RTIBool useWaitSet = RTI_FALSE;

    int prime_num = 10, stats_num = 10000;

    const char *usageStr =
	"Usage: [-d #] [-noecho] [-multicast] [-reliable] [-role #]\n"
	"\t-d NDDS domain\n"
	"\t-role unique number among subscribers. > 0\n"
	"\t-noecho do not echo\n"
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
        sub_output_file = argv[++i];
      } else if (strcmp(argv[i], "-n") == 0) {
        net_config_file = argv[++i];
      } else if (strcmp(argv[i], "-q") == 0) {
        qos_config_file = argv[++i];
      } else if (strcmp(argv[i], "-top") == 0) {
        TEST_TOPIC_NAME = argv[++i];
      } else if (strcmp(argv[i], "-wait") == 0) {
        useWaitSet = RTI_TRUE;
      } else if (strcmp(argv[i], "-keep_all") == 0) {
        QoS_KEEP_ALL = RTI_TRUE;
      } else if (strcmp(argv[i], "-noecho") == 0) {
        thisSubscriberIsEchoer = RTI_FALSE;
      } else if (strcmp(argv[i], "-multicast") == 0) {
        useMulticast = RTI_TRUE;
      } else if (strcmp(argv[i], "-reliable") == 0) {
        isReliable = RTI_TRUE;
      } else {
        ACE_DEBUG ((LM_DEBUG,
                    "subscriber (%P|%t): Invalid argument: %s\n", argv[i]));
        ACE_DEBUG ((LM_DEBUG,
                    " %s\n", usageStr));
        return 0;
      }
    }

    if(role < 1) role = 1; //put a lower bound to role

    return NddsSubscriberMain(nddsDomain,
                              thePacketSize,
                              prime_num,
                              stats_num,
                              role,
                              thisSubscriberIsEchoer,
			      isReliable,
                              useMulticast,
                              useWaitSet);
}
