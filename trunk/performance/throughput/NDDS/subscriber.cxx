/*
 (c) Copyright, Real-Time Innovations, 2005.  All rights reserved.
 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
*/

#include <stdio.h>
#include <stdlib.h>

#include "common.h"
#include "Stats.h"

#include "ace/Sched_Params.h"

const char * sub_output_file = "stats_sub";
const char * qos_config_file = "qos";
const char * net_config_file = "net";
const char * TEST_TOPIC_NAME = "TEST_TOPIC";
const char * TEST_TOPIC_TYPE_NAME = "TEST_TOPIC_TYPE";


/* global QoS settings */
bool QoS_KEEP_ALL = false;
long QoS_MAX_SAMPLES_PER_INSTANCE = DDS_LENGTH_UNLIMITED;
long QoS_MAX_SAMPLES = DDS_LENGTH_UNLIMITED;
long QoS_MAX_INSTANCES = DDS_LENGTH_UNLIMITED;
long QoS_HISTORY_DEPTH = 1;

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

template<typename T, typename TSeq, typename R>
long
dr_read (DDSDataReader *datareader)
{
  R* dr = R::narrow (datareader);
  TSeq instance_seq;
  T instance;
  DDS_SampleInfoSeq info_seq;
  DDS_ReturnCode_t retcode;
  long ts = 1;

  /* get all the data that the reader has received since the last 'take' */
  retcode = dr->take (instance_seq,
                      info_seq,
                      DDS_LENGTH_UNLIMITED,
                      DDS_ANY_SAMPLE_STATE,
                      DDS_ANY_VIEW_STATE,
                      DDS_ANY_INSTANCE_STATE);

  if (retcode != DDS_RETCODE_OK)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "subscriber (%P|%t): failed to access "
                         "data from the reader\n"),
                        -1);
    }
  else
    {
      // We need just a single timestamp from the sequence.
      ts = instance_seq[0].timestamp;
    }

  return ts;
}

class BytesDataListener : public DDSDataReaderListener
{
  private:
    TP_Test_BytesData _instance;
    DDS_InstanceHandle_t _instanceHandle;
    TP_Test_BytesDataDataWriter* _writer;
    int _sequenceNumber;
    int packetsize_;
    int prime_num_;
    int stats_num_;
    PubSub_Stats stats_;
    bool is_finished_;
    long lost_num_;

  public:
    BytesDataListener (int packetsize,
                               int prime_num,
                               int stats_num)
	    : _instanceHandle (DDS_HANDLE_NIL),
	      _writer (0),
	      _sequenceNumber (0),
        packetsize_ (packetsize),
        lost_num_ (0),
        stats_ (sub_output_file, prime_num, stats_num, packetsize)
    {
      this->is_finished_ = false;
    }

    virtual ~BytesDataListener (void)
    {} 

    virtual void on_requested_deadline_missed (
      DDSDataReader* /*reader*/,
	    const DDS_RequestedDeadlineMissedStatus& /*status*/)
	  {}

    virtual void on_requested_incompatible_qos (
      DDSDataReader* /*reader*/,
	    const DDS_RequestedIncompatibleQosStatus& /*status*/)
	  {}

    virtual void on_sample_rejected (
      DDSDataReader* /*reader*/,
      const DDS_SampleRejectedStatus& /*status*/);

    virtual void on_liveliness_changed (
      DDSDataReader* /*reader*/,
      const DDS_LivelinessChangedStatus& /*status*/)
    {}

    virtual void on_subscription_matched (
      DDSDataReader* /*reader*/,
      const DDS_SubscriptionMatchedStatus& /*status*/)
    {}

    virtual void on_sample_lost (DDSDataReader* /*reader*/,
                                 const DDS_SampleLostStatus& /*status*/);

    virtual void on_data_available (DDSDataReader* /*reader*/);

    void set_writer (TP_Test_BytesDataDataWriter* writer)
    { 
      _writer = writer;
    }

    /* test is finished if the sn received is FINAL */
    bool is_finished (void)
    {
      return is_finished_;
    }
};

void BytesDataListener::on_sample_rejected (
  DDSDataReader* /*reader*/,
  const DDS_SampleRejectedStatus& /*status*/)
{
  cout << "Yet another rejected sample" << endl;
}

void BytesDataListener::on_sample_lost (
  DDSDataReader* /*reader*/,
  const DDS_SampleLostStatus& /*status*/) 
{
  cout << "Yet another lost sample: " << this->lost_num_++ << endl;
}

void BytesDataListener::on_data_available (
  DDSDataReader* datareader)
{
  ACE_CDR::ULong ts = 0;

  dr_read <TP_Test_BytesData,
    TP_Test_BytesDataSeq,
    TP_Test_BytesDataDataReader> (datareader);

  this->stats_.sample_for_throughput (ts, false);

  if (this->stats_.ready_to_dump ())
    {
      cout << "Dumping results..." << endl;
      this->stats_.file_dump_throughput ();
      this->is_finished_ = true;
    }
}

int main (int argc, char *argv[])
{
  int nddsDomain = 89;
  int role = 1; //translates to participant index
  unsigned long MAX_MSG_LENGTH = 16384UL;
  unsigned long thePacketSize = 4UL;
  bool useMulticast = false;
  bool isReliable = false;
  bool useWaitSet = false;

  int prime_num = 10;
  int stats_num = 10000;

  const char *usageStr =
	  "Usage: [-d #] [-noecho] [-multicast] [-reliable] [-role #]\n"
	  "\t-d NDDS domain\n"
	  "\t-role unique number among subscribers. > 0\n"
	  "\t-noecho do not echo\n"
	  "\t-multicast subscribe multicast\n"
	  "\t-reliable request reliable service\n";

  for (int i = 1; i < argc; ++i)
    {
      if (strcmp(argv[i], "-d") == 0)
      {
        nddsDomain = strtol (argv[++i], 0, 10);
      }
    else if (strcmp(argv[i], "-role") == 0)
      {
        role = strtol(argv[++i], 0, 10);
      }
    else if (strcmp(argv[i], "-Size") == 0)
      {
        thePacketSize = strtol (argv[++i], 0, 10);
      }
    else if (strcmp(argv[i], "-pn") == 0)
      {
        prime_num = strtol(argv[++i], 0, 10);
      }
    else if (strcmp(argv[i], "-sn") == 0)
      {
        stats_num = strtol(argv[++i], 0, 10);
      }
    else if (strcmp(argv[i], "-msi") == 0)
      {
        QoS_MAX_SAMPLES_PER_INSTANCE  = strtol (argv[++i], 0, 10);
      }
    else if (strcmp(argv[i], "-mxs") == 0)
      {
        QoS_MAX_SAMPLES = strtol(argv[++i], 0, 10);
      }
    else if (strcmp(argv[i], "-mxi") == 0)
      {
        QoS_MAX_INSTANCES = strtol(argv[++i], 0, 10);
      }
    else if (strcmp(argv[i], "-r") == 0)
      {
        sub_output_file = argv[++i];
      }
    else if (strcmp(argv[i], "-n") == 0)
      {
        net_config_file = argv[++i];
      }
    else if (strcmp(argv[i], "-q") == 0)
      {
        qos_config_file = argv[++i];
      }
    else if (strcmp(argv[i], "-top") == 0)
      {
        TEST_TOPIC_NAME = argv[++i];
      }
    else if (strcmp(argv[i], "-wait") == 0)
      {
        useWaitSet = true;
      }
    else if (strcmp(argv[i], "-keep_all") == 0)
      {
        QoS_KEEP_ALL = true;
      }
    else if (strcmp(argv[i], "-depth") == 0)
      {
        QoS_HISTORY_DEPTH = strtol (argv[++i], 0, 10);
      }
    else if (strcmp(argv[i], "-multicast") == 0)
      {
        useMulticast = true;
      }
    else if (strcmp(argv[i], "-reliable") == 0)
      {
        isReliable = true;
      }
    else
      {
        ACE_ERROR_RETURN ((LM_ERROR,
                            "publisher (%P|%t): Invalid argument:"
                            " %s\n%s\n",
                            argv[i],
                            usageStr),
                          -1);
      }
  }

  if (role < 1)
    {
      role = 1; //put a lower bound to role
    }

  set_rt ();

  /*------------------------- declarations ----------------------------*/
  /* common declarations */

  cout << "=============Settings==============" << endl
       << "MAX_MSG_LENGTH = " << MAX_MSG_LENGTH << endl
       << "max_samples_per_instances = " << QoS_MAX_SAMPLES_PER_INSTANCE
       << endl
       << "max_samples = " << QoS_MAX_SAMPLES << endl
       << "max_instances = " << QoS_MAX_INSTANCES << endl
       << "protocol = " << (isReliable ? "Reliable" : "Best effort")
       << endl
       << "Multicast = " << (useMulticast ? "Yes" : "No") << endl
       << "Notification_Type = "
       << (useWaitSet ? "wait-based" : "listener-based") << endl
       << "History = KEEP_" << (QoS_KEEP_ALL ? "ALL" : "LAST") << endl
       << "History.depth = " << QoS_HISTORY_DEPTH << endl
       << "=============Settings==============" << endl << endl;
  
  ACE_CDR::ULong ts = 0;      // time stamp variable used for waitset
  bool isFinished = false; // used only for waitset

  // initiate stats file
  PubSub_Stats stats_ (sub_output_file,
                       prime_num,
                       stats_num,
                       thePacketSize);

  DDS_ReturnCode_t retcode = DDS_RETCODE_ERROR;
  DDS_Duration_t sleepTime = {1, 0};  /* 1 second */

  DDS_Duration_t waitTime = {500, 0}; /* WaitSet blocking timeout */
      
  /* DomainParticipantFactory declarations */
  DDSDomainParticipantFactory* factory = 0;

  /*  DomainParticipant declarations */
  DDS_DomainId_t domain_id = nddsDomain;
  DDSDomainParticipant* participant = 0;
  DDS_DomainParticipantQos participant_qos;
  DDSDomainParticipantListener* participant_listener = 0;

  /* Subscriber declarations */
  DDSSubscriber* subscriber;
  DDS_SubscriberQos subscriber_qos;
  DDSSubscriberListener* subscriber_listener = 0;

  /* Topic declarations */
  DDSTopic* data_topic;
  DDS_TopicQos data_topic_qos;
  DDSTopicListener* data_topic_listener = 0;

  /* DataReader declarations */
  DDSDataReader* reader;
  DDS_DataReaderQos reader_qos;

  /* Listener declarations */
  BytesDataListener reader_listener (thePacketSize,
                                             prime_num,
                                             stats_num);

  /* WaitSet declarations */
  DDSWaitSet *waitset = new DDSWaitSet ();
  DDSStatusCondition *condition;
  DDSConditionSeq conditionList;

  DDS_DomainParticipantFactoryQos factoryQos;
  NDDS_Transport_UDPv4_Property_t udpv4Property =
    NDDS_TRANSPORT_UDPV4_PROPERTY_DEFAULT;
    
#ifdef RTI_SHARED_MEMORY
  NDDS_Transport_Shmem_Property_t shmemProperty =
    NDDS_TRANSPORT_SHMEM_PROPERTY_DEFAULT;
#endif

  NDDSConfigLogger* logger = 0;
  
  /*-------------------------- create dds entities ---------------------*/

/*--------------------------------------------------------------------------
Create participant to join the domain and allocate system resources 
(start DDS threads, grab set of port numbers, etc.).
----------------------------------------------------------------------------*/

  /* get handle to participant factory */
  factory = DDSDomainParticipantFactory::get_instance ();
  
  if (factory == 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "subscriber (%P|%t): failed to get "
                         "domain participant factory\n"),
                        -1);
    }
  
  /* Do not auto enable participants upon creation since we want to register
      transport plugins
  */
  factory->get_qos (factoryQos);
  factoryQos.entity_factory.autoenable_created_entities =
    DDS_BOOLEAN_FALSE;

  if (factory->set_qos(factoryQos) != DDS_RETCODE_OK)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "subscriber (%P|%t): failed to set "
                         "factory QoS\n"),
                        -1);
    }    
  
  /* initialize participant_qos with default values. similiar to 
      LatencyWriter setup*/
  factory->get_default_participant_qos (participant_qos);
  /* regardless of where the reader app runs, force the host_id, so we can
      make the send order deterministic (b/c order is decided by hostId-appId)
      pick the same host_id on both publisher and the subscriber
  */
  participant_qos.wire_protocol.rtps_host_id = 0x2;
  participant_qos.wire_protocol.rtps_app_id = role;
  
  cout << "rtps_host_id: " << participant_qos.wire_protocol.rtps_host_id
       << ", rtps_app_id: " << participant_qos.wire_protocol.rtps_app_id
       << endl;

  participant_qos.discovery.participant_index	= role;// > 0
  participant_qos.receiver_pool.buffer_size =
    MAX_MSG_LENGTH + NDDS_OVERHEAD + MY_OWN_TEST_OVERHEAD;

#ifdef RTI_SHARED_MEMORY
  cout << "Shared Memory Plug-in is installed!" << endl;
  participant_qos.transport_builtin.mask |= DDS_TRANSPORTBUILTIN_SHMEM;
#endif

#if ((MAX_MSG_LENGTH + NDDS_OVERHEAD + (14+20+8)) > 64*1024)
  participant_qos.transport_builtin.mask &= ~DDS_TRANSPORTBUILTIN_UDPv4;
#endif

  /* create and enable participant */
  cout << "Creating participant............";
  
  participant =
    factory->create_participant (domain_id,
					                       participant_qos,
					                       participant_listener,
					                       DDS_STATUS_MASK_NONE);
					                       
  if (participant == 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "subscriber (%P|%t): failed to create "
                         "domain participant\n"),
                        -1);
    }
    
  cout << "[Done]" << endl;
  
  retcode =
    NDDSTransportSupport::get_builtin_transport_property (
      participant,
      DDS_TRANSPORTBUILTIN_UDPv4,
      (NDDS_Transport_Property_t&) udpv4Property);
  
  if (retcode != DDS_RETCODE_OK)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "subscriber (%P|%t): failed to get "
                         "default UDPv4 xport property\n"),
                        -1);
    }

  udpv4Property.parent.message_size_max =
    MAX_MSG_LENGTH + NDDS_OVERHEAD + MY_OWN_TEST_OVERHEAD;
  udpv4Property.send_socket_buffer_size =
    udpv4Property.parent.message_size_max;
  udpv4Property.recv_socket_buffer_size =
    15 * udpv4Property.send_socket_buffer_size;
    
  retcode =
    NDDSTransportSupport::set_builtin_transport_property (
      participant,
      DDS_TRANSPORTBUILTIN_UDPv4,
      (NDDS_Transport_Property_t&) udpv4Property);

  if (retcode != DDS_RETCODE_OK)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "subscriber (%P|%t): failed to set "
                         "UDPv4 xport property\n"),
                        -1);
   }

#ifdef RTI_SHARED_MEMORY
  /* Do the same if NDDS shared memory transport is installed by default */
  retcode =
    NDDSTransportSupport::get_builtin_transport_property (
      participant,
      DDS_TRANSPORTBUILTIN_SHMEM,
      (NDDS_Transport_Property_t&)shmemProperty);
  
  if (retcode != DDS_RETCODE_OK)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "subscriber (%P|%t): failed to get "
                         "default shmem xport property\n"),
                        -1);
    }

  shmemProperty.parent.message_size_max = MAX_MSG_LENGTH + NDDS_OVERHEAD;
  shmemProperty.received_message_count_max = 8;
  shmemProperty.receive_buffer_size =
    (shmemProperty.received_message_count_max
	   * shmemProperty.parent.message_size_max);
	   
	retcode =
	  NDDSTransportSupport::set_builtin_transport_property (
      participant,
      DDS_TRANSPORTBUILTIN_SHMEM,
      (NDDS_Transport_Property_t&) shmemProperty);

  if (retcode != DDS_RETCODE_OK)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "subscriber (%P|%t): failed to set "
                         "shmem xport property\n"),
                        -1);
   }
#endif //RTI_SHARED_MEMORY

  retcode = participant->enable ();
  
  if (retcode != DDS_RETCODE_OK)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "subscriber (%P|%t): failed to "
                         "enable participant\n"),
                        -1);
    }
  
/*--------------------------------------------------------------------------
Create a publisher and a subsciber
----------------------------------------------------------------------------*/

  /* initialize subscriber_qos with default values */
  participant->get_default_subscriber_qos (subscriber_qos);

  /* optionally modify subscriber QoS */

  /* create and enable subscriber */
  cout << "Creating data subscriber............";
  
  subscriber =
    participant->create_subscriber (subscriber_qos,
					                          subscriber_listener,
					                          DDS_STATUS_MASK_NONE);
					                          
  if (subscriber == 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "subscriber (%P|%t): failed to "
                         "create subscriber\n"),
                        -1);
   }
   
  cout << "[Done]" << endl;

/*--------------------------------------------------------------------------
Register data types, and create topics: data_topic and echo_topic.
----------------------------------------------------------------------------*/ 

  cout << "Registering participant with data type \""
       << TEST_TOPIC_TYPE_NAME << "\"......";

  TP_Test_BytesDataTypeSupport::register_type (participant,
                                               TEST_TOPIC_TYPE_NAME);
  cout << "[Done]" << endl;
					    
  /* initialize topic_qos with default values */
  participant->get_default_topic_qos (data_topic_qos);
  
  // each instance can only be owned by one DataWriter at a time
  data_topic_qos.ownership.kind = DDS_EXCLUSIVE_OWNERSHIP_QOS;

  data_topic_qos.resource_limits.max_samples_per_instance =
    QoS_MAX_SAMPLES_PER_INSTANCE;
  data_topic_qos.resource_limits.max_instances = QoS_MAX_INSTANCES;
  data_topic_qos.resource_limits.max_samples = QoS_MAX_SAMPLES;

  /* create and enable data_topic. for issue from LatencyWriter to 
      LatencyReader */

  cout << "Creating normal data topic \"" << TEST_TOPIC_NAME
       << "\"......";
  
  data_topic = participant->create_topic (TEST_TOPIC_NAME,
                                          TEST_TOPIC_TYPE_NAME,
                                          data_topic_qos,
                                          data_topic_listener,
                                          DDS_STATUS_MASK_NONE);

  if (data_topic == 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "subscriber (%P|%t): failed to "
                         "create data topic\n"),
                        -1);
    }
    
  cout << "[Done]" << endl;

/*--------------------------------------------------------------------------
Create one data reader: (data_)reader
----------------------------------------------------------------------------*/
  /* initialize reader_qos with default values */
  subscriber->get_default_datareader_qos(reader_qos);

  if (isReliable)
    {
      reader_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
      /* NOTE: not changing history depth or kind here */
    }

  if (QoS_KEEP_ALL)
    {
      reader_qos.history.kind = DDS_KEEP_ALL_HISTORY_QOS;
    }

  reader_qos.history.depth = QoS_HISTORY_DEPTH;

  if (useMulticast)
    {
      reader_qos.multicast.value.ensure_length(1,1);
      reader_qos.multicast.value[0].receive_address =
	      DDS_String_dup ("225.1.2.3");
    }

  /* create and enable reader without listener at first */
  cout << "Creating data reader from data subscriber......";
  
  reader = subscriber->create_datareader (data_topic,
                                          reader_qos,
					                                0,
					                                DDS_STATUS_MASK_NONE);
					                                
  if (reader == 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "subscriber (%P|%t): failed to "
                         "create data reader\n"),
                        -1);
    }

  cout << "[Done]" << endl;

  if (useWaitSet)
    {
      /* create condition for data reader waitset */
      cout << "Setting WaitSet condition for data reader...";
      
      condition = reader->get_statuscondition ();
      condition->set_enabled_statuses (DDS_DATA_AVAILABLE_STATUS);

      retcode = waitset->attach_condition (condition);

      if (retcode != DDS_RETCODE_OK)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "subscriber (%P|%t): failed to "
                             "set waitset condition\n"),
                            -1);
        }
        
      cout << "[Done]" << endl;
    }
  else
    {

      /* setup reader to access received data via a listener 
          explicitly specify which operations in the listener are
          activated for callback
      */
      cout << "Setting data reader listner for data reader...";
      
      retcode = reader->set_listener (&reader_listener, 
                                      DDS_DATA_AVAILABLE_STATUS);
                                      
      if (retcode != DDS_RETCODE_OK)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "subscriber (%P|%t): failed to "
                             "set data reader listener\n"),
                            -1);
        }
        
      cout << "[Done]" << endl;
    }

  /*------------------------ start the latency test ----------------------*/

/*--------------------------------------------------------------------------
Stay in a the while loop unitl receiving a termination message.
----------------------------------------------------------------------------*/ 

  cout << "Start receiving data.." << endl;

  if (useWaitSet) // wait-based
    {
      while (!isFinished)
        {
          retcode = waitset->wait (conditionList, waitTime);

          if (0 == conditionList.length ())
            {
              ACE_ERROR_RETURN ((LM_ERROR,
                                 "subscriber (%P|%t): No "
                                 "conditions triggered\n"),
                                -1);
            }
          else
            {
              for (int i = 0; i < conditionList.length (); ++i)
                {
                  if (condition == conditionList[i])
                    {


                      dr_read <TP_Test_BytesData,
                        TP_Test_BytesDataSeq,
                        TP_Test_BytesDataDataReader> (reader);

                      stats_.sample_for_throughput (ts, true);

                      if (stats_.ready_to_dump ())
                        {
                          cout << "Dumping results..." << endl;
                          stats_.file_dump_throughput ();
                          isFinished = true;
                        }                
                    }
                  else
                    {
                      ACE_ERROR_RETURN ((LM_ERROR,
                                         "incorrect conditions "
                                         "caught...\n"),
                                        -1);
                    }
                }
            }         
        }     
    }
  else  // listener-based by default 
    {
      /* passively receive issue and echo back */
      while (!reader_listener.is_finished ())
        {
          NDDSUtility::sleep (sleepTime);
        }
    }

  /*------------------------ tear down dds entities ----------------------*/

/*--------------------------------------------------------------------------
The shutdown phase.
----------------------------------------------------------------------------*/ 
  cout << "Deleting data entities............";
  retcode = subscriber->delete_datareader (reader);
  retcode = participant->delete_subscriber (subscriber);
  retcode = participant->delete_topic (data_topic);
  cout << "[Done]" << endl;

  cout << "Deleting domain participant............";
  retcode = factory->delete_participant (participant);
  cout << "[Done]" << endl;

  cout << "Deleting data reader waitset............";
  delete waitset;
  waitset = 0;
  cout << "[Done]" << endl;

  /* NDDS provides finalize_instance() method for people who want to release
      memory used by the participant factory singleton.
      Uncomment the following block of code for clean destruction of
      the participant factory singleton. */
/*
  retcode = DDSDomainParticipantFactory::finalize_instance();
*/

	return 0;
}
