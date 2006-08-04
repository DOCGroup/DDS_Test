/*
 (c) Copyright, Real-Time Innovations, 2005.  All rights reserved.
 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
*/

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
bool QoS_KEEP_ALL = false;
long QoS_MAX_SAMPLES_PER_INSTANCE = DDS_LENGTH_UNLIMITED;
long QoS_MAX_SAMPLES = DDS_LENGTH_UNLIMITED;
long QoS_MAX_INSTANCES = DDS_LENGTH_UNLIMITED;
long QoS_HISTORY_DEPTH = 1;
const long UNFRAGMENTED_UDP_PACKET_SIZE_MAX = 1500 - 14 - 20 - 8;

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

template<typename T, typename W>
int dw_write (int size,
              int num_messages,
              DDSDataWriter *writer,
              PubSub_Stats & stats)
{
  T instance;
  long i = 0;
  DDS_Octet *dataBuffer = 0;
  DDS_ReturnCode_t retcode = DDS_RETCODE_OK;

  /* narrow the generic data writer to a specific data writer*/
  W *dw = W::narrow (writer);

  if (dw == 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "publisher (%P|%t): failed to narrow "
                         "data writer\n"),
                        -1);
    }

  // @@ this step can be ommited if the length set by the
  //    loan_contiguous is what we want it to be
  instance.data.length (size); // - sizeof (DDS_UnsignedLong));
  instance.timestamp = 0;

  for (i = 0; i < num_messages; ++i)
    {

      stats.sample_for_throughput (instance.timestamp);

      /* send the raw data to all interested parties */
      retcode = dw->write (instance,
                           DDS_HANDLE_NIL);

      if (retcode != DDS_RETCODE_OK)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "publisher (%P|%t): failed to write\n"),
                            -1);
        }
    }

  if (stats.ready_to_dump ())
    {
      printf ("Dumping results...\n");
      stats.file_dump_throughput ();
    }

  for (i = 0; i < 30 * num_messages; ++i)
    {

      /* send the raw data to all interested parties */
      retcode = dw->write (instance,
                           DDS_HANDLE_NIL);

      if (retcode != DDS_RETCODE_OK)
        {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "publisher (%P|%t): failed to write\n"),
                            -1);
        }
    }

  return 0;
}

class TP_PacketDataWriterListener : public DDSDataWriterListener 
{
private:
  int num_of_subs_;

public:

  TP_PacketDataWriterListener (void)
    : num_of_subs_(0)
  {}
  
  virtual ~TP_PacketDataWriterListener (void)
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
    DDSDataWriter *,
    const DDS_PublicationMatchedStatus &)
  {
    ++this->num_of_subs_;
    cout << "Discovered subscription: No. " << this->num_of_subs_ << endl;
  }
};

int main (int argc, char **argv)
{
  int nddsDomain = 89;
  int role = 0;
  int thePacketSize = 4;
  int prime_num = 0;
  int stats_num = 0;
  bool useMulticast = false;
  bool isReliable = false;
   
  const char *usageStr =
	  "Usage: [-d #] [-Size #] [-minSize #] [-maxSize #] [-multicast] [-reliable]\n"
	  "\t-d NDDS domain\n"
	  "\t-minSize minimum payload size\n"
	  "\t-maxSize maximum payload size\n"
	  "\t-multicast subscribe multicast\n"
	  "\t-reliable request reliable service\n";

  for (int i = 1; i < argc; ++i)
    {
      if (strcmp(argv[i], "-d") == 0)
        {
          nddsDomain = strtol(argv[++i], 0, 10);
        }
      else if (strcmp(argv[i], "-role") == 0)
        {
          role = strtol(argv[++i], 0, 10);
        }
      else if (strcmp(argv[i], "-Size") == 0)
        {
          thePacketSize = strtol(argv[++i], 0, 10);
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
          QoS_MAX_SAMPLES_PER_INSTANCE  = strtol(argv[++i], 0, 10);
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
          pub_output_file = argv[++i];
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
      else if (strcmp(argv[i], "-keep_all") == 0)
        {
          QoS_KEEP_ALL = RTI_TRUE;
        }
      else if (strcmp(argv[i], "-multicast") == 0)
        {
          useMulticast = RTI_TRUE;
        }
      else if (strcmp(argv[i], "-reliable") == 0)
        {
          isReliable = RTI_TRUE;
        }
      else if (strcmp(argv[i], "-depth") == 0 )
        {
          QoS_HISTORY_DEPTH = strtol(argv[++i], 0, 10);
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

  // Use real-time scheduling class, if possible.
  set_rt ();

  cout << "=============Settings==============" << endl
       << "MAX_MSG_LENGTH = " << MAX_MSG_LENGTH << endl
       << "max_samples_per_instances = "
       << QoS_MAX_SAMPLES_PER_INSTANCE << endl
       << "max_samples = " << QoS_MAX_SAMPLES << endl
       << "max_instances = " << QoS_MAX_INSTANCES << endl
       << "protocol = " << (isReliable ? "Reliable" : "Best Effort") << endl
       << "Multicast = " << (useMulticast ? "Yes" : "No") << endl
       << "Notification_Type = N/A" << endl
       << "History = KEEP_" << (QoS_KEEP_ALL ? "ALL" : "LAST") << endl
       << "History.depth = " << QoS_HISTORY_DEPTH << endl
       << "=============Settings==============" << endl << endl;


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
  const DDS_Duration_t sleepTime = {1,0}, waitTime = {10, 0};
  int packetsize = 0, retval = 0;
  DDS_Octet *dataBuffer = 0;

  DDS_DomainParticipantFactoryQos factoryQos;         

  /* DomainParticipantFactory declarations */
  DDSDomainParticipantFactory* factory = 0;

  /*  DomainParticipant declarations */
  DDS_DomainId_t domain_id = nddsDomain;
  DDSDomainParticipant* participant = 0;
  DDS_DomainParticipantQos participant_qos;

  /* Publisher declarations */
  DDSPublisher* publisher;
  DDS_PublisherQos publisher_qos;
  DDSPublisherListener* publisher_listener = 0;

  /* Topic declarations */
  DDSTopic* data_topic;
  DDS_TopicQos data_topic_qos;
  DDSTopicListener* data_topic_listener = 0;

  DDS_TopicQos echo_topic_qos;
  DDSTopicListener* echo_topic_listener = 0;

  /* DataReader declarations */
  DDS_DataReaderQos reader_qos;

  /* DataWriter declarations */
  DDSDataWriter* writer;
  DDS_DataWriterQos writer_qos;

  /* Listener declarations */
  TP_PacketDataWriterListener writer_listener;

  /* Data declarations */
  DDS_InstanceHandle_t instance_handle = DDS_HANDLE_NIL;

  NDDS_Transport_UDPv4_Property_t udpv4Property =
    NDDS_TRANSPORT_UDPV4_PROPERTY_DEFAULT;
    
#ifdef RTI_SHARED_MEMORY
  NDDS_Transport_Shmem_Property_t shmemProperty =
    NDDS_TRANSPORT_SHMEM_PROPERTY_DEFAULT;
#endif

  if (thePacketSize > MAX_MSG_LENGTH)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "publisher (%P|%t): invalid parameter; "
                         "thePacketSize > MAX_MSG_LENGTH\n"),
                        -1);
    }

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
                         "publisher (%P|%t): failed to get domain "
                         "participant factory\n"),
                        -1);
    }
  
  /* Do not auto enable participants upon creation since we want to register
      transport plugins */
  factory->get_qos (factoryQos);
  factoryQos.entity_factory.autoenable_created_entities =
    DDS_BOOLEAN_FALSE;

  if (factory->set_qos (factoryQos) != DDS_RETCODE_OK)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "publisher (%P|%t): failed to set "
                         "factory QoS\n"),
                        -1);
    }    
  
  /* initialize participant_qos with default values */
  factory->get_default_participant_qos (participant_qos);

  // pick the same host_id on both publisher and the subscriber
  participant_qos.wire_protocol.rtps_host_id = 0x2;
  
  cout << "rtps_host_id: " << participant_qos.wire_protocol.rtps_host_id
       << ", rtps_app_id: " << participant_qos.wire_protocol.rtps_app_id
       << endl;
  
  /* writer's participant index is left as 0, the default */

  /* If you want to send message larger than the UDPv4 transport plugin's
      limit of 64 KB, you have to use a non-UDPv4 transport plugin, such as
      the shared memory transport (in which case you will be restricted to
      sending to readers on the SAME host).  Using your own pluggable transport
      is an option, but this example does NOT show to to plug in your own
      transport.
  */
  participant_qos.receiver_pool.buffer_size =
    MAX_MSG_LENGTH + NDDS_OVERHEAD + MY_OWN_TEST_OVERHEAD;

#ifdef RTI_SHARED_MEMORY
  cout << "Shared Memory Plug-in is installed!" << endl;

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

  cout << "Creating participant............";
  
  participant =
    factory->create_participant (domain_id,
					                       participant_qos,
					                       0,
					                       DDS_STATUS_MASK_NONE);
					                      
  if (participant == 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "publisher (%P|%t): failed to create "
                         "domain participant\n"),
                        -1);
    }
    
  cout << "[Done]" << endl;

  if (participant_qos.transport_builtin.mask & DDS_TRANSPORTBUILTIN_UDPv4)
    {
      retcode =
        NDDSTransportSupport::get_builtin_transport_property (
	        participant,
	        DDS_TRANSPORTBUILTIN_UDPv4,
	        (NDDS_Transport_Property_t&) udpv4Property);
    
	    if (retcode != DDS_RETCODE_OK) 
	      {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "publisher (%P|%t): failed to get "
                             "default UDPv4 xport property\n"),
                            -1);
	      }

	    udpv4Property.parent.message_size_max =
	      MAX_MSG_LENGTH + NDDS_OVERHEAD + MY_OWN_TEST_OVERHEAD;
	    udpv4Property.send_socket_buffer_size =
        udpv4Property.parent.message_size_max;
	    udpv4Property.recv_socket_buffer_size =
        2 * udpv4Property.send_socket_buffer_size;

      cout << "udpv4Property: message_size_max = "
           << udpv4Property.parent.message_size_max << endl
           << "udpv4Property: send_socker_buffer_size = "
           << udpv4Property.send_socket_buffer_size << endl
           << "udpv4Property: recv_socket_buffer_size = "
           << udpv4Property.recv_socket_buffer_size << endl
           << "maximum unfragmented udp packet size is "
           << UNFRAGMENTED_UDP_PACKET_SIZE_MAX << endl;
           
	    if (thePacketSize > UNFRAGMENTED_UDP_PACKET_SIZE_MAX - NDDS_OVERHEAD)
	      {
	        udpv4Property.no_zero_copy = RTI_TRUE;
	      }
	      
	    retcode =
	      NDDSTransportSupport::set_builtin_transport_property (
	        participant,
	        DDS_TRANSPORTBUILTIN_UDPv4,
	        (NDDS_Transport_Property_t&) udpv4Property);

	    if (retcode != DDS_RETCODE_OK)
	      {
          ACE_ERROR_RETURN ((LM_ERROR,
                             "publisher (%P|%t): failed to set "
                             "UDPv4 xport property\n"),
                            -1);
	      }
    }

#ifdef RTI_SHARED_MEMORY
  /* Do the same if NDDS shared memory transport is installed by default */
  retcode =
    NDDSTransportSupport::get_builtin_transport_property (
	    participant,
	    DDS_TRANSPORTBUILTIN_SHMEM,
	    (NDDS_Transport_Property_t&) shmemProperty);
	    
  if (retcode != DDS_RETCODE_OK)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "publisher (%P|%t): failed to get "
                         "default shmem xport property\n"),
                        -1);
    }

  shmemProperty.parent.message_size_max =
    MAX_MSG_LENGTH + NDDS_OVERHEAD + MY_OWN_TEST_OVERHEAD;
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
                         "publisher (%P|%t): failed to set shmem "
                         "xport property\n"),
                        -1);
    }
#endif//RTI_SHARED_MEMORY

  retcode = participant->enable ();/* now bring up the participant */
  
  if (retcode != DDS_RETCODE_OK)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "publisher (%P|%t): failed to enable "
                         "participant\n"),
                        -1);
    }
  
/*--------------------------------------------------------------------------
Create a publisher and a subsciber, both with default QoSes.
----------------------------------------------------------------------------*/

  /* initialize publisher_qos with default values */
  participant->get_default_publisher_qos (publisher_qos);

  /* optionally modify publisher qos values here */

  /* create and enable publisher */
  cout << "Creating data publisher............";
  publisher =
    participant->create_publisher (publisher_qos,
					                          publisher_listener,
					                          DDS_STATUS_MASK_NONE);
					                          
  if (publisher == 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "publisher (%P|%t): failed to create "
                         "publisher\n"),
                        -1);
    }
    
  cout << "[Done]" << endl;

/*--------------------------------------------------------------------------
Register data types, and create topics: echo_topic and data_topic
----------------------------------------------------------------------------*/ 

  cout << "Registering participant with data type \""
       << TEST_TOPIC_TYPE_NAME << "\"......";

  switch (thePacketSize)
    {
      case 4:
        Bytes4TypeSupport::register_type (participant,
                                          TEST_TOPIC_TYPE_NAME);
        break;
      case 8:
        Bytes8TypeSupport::register_type (participant,
                                          TEST_TOPIC_TYPE_NAME);
        break;
      case 16:
        Bytes16TypeSupport::register_type (participant,
                                            TEST_TOPIC_TYPE_NAME);
        break;
      case 32:
        Bytes32TypeSupport::register_type (participant,
                                            TEST_TOPIC_TYPE_NAME);
        break;
      case 64:
        Bytes64TypeSupport::register_type (participant,
                                            TEST_TOPIC_TYPE_NAME);
        break;
      case 128:
        Bytes128TypeSupport::register_type (participant,
                                            TEST_TOPIC_TYPE_NAME);
        break;
      case 256:
        Bytes256TypeSupport::register_type (participant,
                                            TEST_TOPIC_TYPE_NAME);
        break;
      case 512:
        Bytes512TypeSupport::register_type (participant,
                                            TEST_TOPIC_TYPE_NAME);
        break;
      case 1024:
        Bytes1024TypeSupport::register_type (participant,
                                            TEST_TOPIC_TYPE_NAME);
        break;
      case 2048:
        Bytes2048TypeSupport::register_type (participant,
                                              TEST_TOPIC_TYPE_NAME);
        break;
      case 4096:
        Bytes4096TypeSupport::register_type (participant,
                                              TEST_TOPIC_TYPE_NAME);
        break;
      case 8192:
        Bytes8192TypeSupport::register_type (participant,
                                              TEST_TOPIC_TYPE_NAME);
        break;
      case 16384:
        Bytes16384TypeSupport::register_type (participant,
                                              TEST_TOPIC_TYPE_NAME);
        break;
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "publisher (%P|%t): bad data size: %d\n",
                           packetsize),
                          -1);
    }

  cout << "[Done]" << endl;
					    
  /* initialize topic_qos with default values */
  participant->get_default_topic_qos (data_topic_qos);
  // each instance can only be owned by one DataWriter at a time
  data_topic_qos.ownership.kind = DDS_EXCLUSIVE_OWNERSHIP_QOS;
  data_topic_qos.resource_limits.max_samples_per_instance =
    QoS_MAX_SAMPLES_PER_INSTANCE;
  data_topic_qos.resource_limits.max_instances = QoS_MAX_INSTANCES;
  data_topic_qos.resource_limits.max_samples = QoS_MAX_SAMPLES;
  echo_topic_qos = data_topic_qos;
  
  /* create and enable data_topic. This is topic for data from 
      NDDSLatencyWriter to NDDSLatencyReader. */
  
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
                         "publisher(%P|%t): failed to create "
                         "data topic\n"),
                        -1);
    }
    
  cout << "[Done]" << endl;

/*--------------------------------------------------------------------------
Create one data writer: (data_)writer
----------------------------------------------------------------------------*/ 

  /* initialize writer_qos with default values */
  publisher->get_default_datawriter_qos (writer_qos);

  if (!isReliable)
    {
      //writer is reliable by default
	    writer_qos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;
    }

  if (QoS_KEEP_ALL)
    {
      writer_qos.history.kind = DDS_KEEP_ALL_HISTORY_QOS;
    }
    
  writer_qos.history.depth = QoS_HISTORY_DEPTH;

  /* create and enable writer. use data_topic. */
  cout << "Creating data writer from data publisher......";
  
  writer = publisher->create_datawriter(data_topic,
                                        writer_qos,
                                        0,
                                        DDS_STATUS_MASK_NONE);
  if (writer == 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "publisher (%P|%t): failed to "
                         "create data writer\n"),
                        -1);
    }
    
  cout << "[Done]" << endl;

  cout << "Setting data writer listener for data writer......";
  
  retcode = writer->set_listener (&writer_listener,
                                  DDS_PUBLICATION_MATCHED_STATUS);
                                  
  if (retcode != DDS_RETCODE_OK)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "publisher (%P|%t): failed to set "
                         "data writer listener\n"),
                        -1);
    }
    
  cout << "[Done]" << endl;
  
  /* We can detect that the readers have appeared by accessing the built-in
      reader, but we omit this in this example to keep the code simple, and
      just sleep a while, assuming that the readers will be discovered within
      this time.
  */
  cout << "Waiting for subscribers to be discovered.." << endl;
  
  for (int i = 0; i < 20; ++i)
    {
	    NDDSUtility::sleep (sleepTime);
    }

  /*------------------------ start the latency test ----------------------*/

/*--------------------------------------------------------------------------
The core latency test is in the following for() loop.
----------------------------------------------------------------------------*/ 

  packetsize = thePacketSize;

  cout << "Start sending samples.." << endl;

  NDDSUtility::sleep (sleepTime);

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
      ACE_ERROR_RETURN ((LM_ERROR,
                         "publisher (%P|%t): bad data size: %d\n",
                         packetsize),
                        -1);
    }

  if (-1 == retval)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         "publisher (%P|%t): write of packet "
                         "size: %d failed\n",
                         packetsize),
                        -1);
    }

  NDDSUtility::sleep (sleepTime);

/*--------------------------------------------------------------------------
The shutdown period.
----------------------------------------------------------------------------*/ 
  
  /*------------------------ tear down dds entities ----------------------*/

  cout << "Deleting data entities ............";
  
  retcode = publisher->delete_datawriter(writer);
  retcode = participant->delete_topic(data_topic);
  retcode = participant->delete_publisher(publisher);
  
  cout << "[Done]" << endl
       << "Deleting domain participant............";

  retcode = factory->delete_participant(participant);

  cout << "[Done]" << endl;

  /* NDDS provides finalize_instance() method for people who want to release
      memory used by the participant factory singleton.
      Uncomment the following block of code for clean destruction of
      the participant factory singleton. */
/*
  retcode = DDSDomainParticipantFactory::finalize_instance ();
*/

  return 0;
}

