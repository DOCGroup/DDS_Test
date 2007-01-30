// $Id$

#ifndef NDDS_TEST_T_CPP
#define NDDS_TEST_T_CPP

#include "NDDS_Test_T.h"

#include "ace/Log_Msg.h"
#include "ace/Streams.h"

// Workaround since I can't initialize class members
// from these macros.
namespace
{
  const NDDS_Transport_UDPv4_Property_t udpv4Property =
    NDDS_TRANSPORT_UDPV4_PROPERTY_DEFAULT;
      
  const NDDS_Transport_Shmem_Property_t shmemProperty =
    NDDS_TRANSPORT_SHMEM_PROPERTY_DEFAULT;
}
    
template<typename DATA_TYPE, typename TYPE_SUPPORT>
NDDS_Test_T<DATA_TYPE, TYPE_SUPPORT>::NDDS_Test_T (void)
  : participant_factory_ (0),
    participant_ (0),
    topic_ (0),
    topic_listener_ (0),
    udpv4_property_ (udpv4Property),
    shmem_property_ (shmemProperty),
    host_id_ (2UL),
    shared_memory_ (false)
{
}

template<typename DATA_TYPE, typename TYPE_SUPPORT>
NDDS_Test_T<DATA_TYPE, TYPE_SUPPORT>::~NDDS_Test_T (void)
{
}

template<typename DATA_TYPE, typename TYPE_SUPPORT>
int
NDDS_Test_T<DATA_TYPE, TYPE_SUPPORT>::Init (int argc, char *argv[])
{
  this->argc_ = argc;
  this->argv_ = argv;

  if (this->ParseArgs () != 0)
    {
      // Error message already output.
      return -1;
    }
    
  if (this->InitParticipantFactory () != 0)
    {
      // Error message already output.
      return -1;
    }

  this->SetParticipantQos ();

  if (this->InitParticipant () != 0)
    {
      // Error message already output.
      return -1;
    }
  
  return 0;
}

template<typename DATA_TYPE, typename TYPE_SUPPORT>
int
NDDS_Test_T<DATA_TYPE, TYPE_SUPPORT>::Fini (void)
{
  DDS::ReturnCode_t retcode =
    this->participant_->delete_topic (this->topic_);
    
  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("Fini", "delete_topic", retcode);
      return -1;
    }
    
  retcode =
    this->participant_factory_->delete_participant (this->participant_);
    
  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("Fini", "delete_participant", retcode);
      return -1;
    }
    
  retcode = DDS::DomainParticipantFactory::finalize_instance ();
    
  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("Fini", "finalize_instance", retcode);
      return -1;
    }
  
  return 0;
}

template<typename DATA_TYPE, typename TYPE_SUPPORT>
int
NDDS_Test_T<DATA_TYPE, TYPE_SUPPORT>::ParseArgs (void)
{
  ACE_Arg_Shifter arg_shifter (this->argc_, this->argv_);
  bool good = true;
  
  // Ignore the command - argv[0].
  arg_shifter.ignore_arg ();
  
  while (arg_shifter.is_anything_left ()) 
    {
      if (arg_shifter.cur_arg_strncasecmp ("-shmem") == 0) 
        {
          this->shared_memory_ = true;
          arg_shifter.consume_arg ();
        }
      else if (this->ParseArgsBase (arg_shifter) != 0)
        {
          arg_shifter.ignore_arg ();
          good = false;
        }
    }
    
  if (!good)
    {
      this->Usage ();
      return -1;
    }
    
  return 0;
}

template<typename DATA_TYPE, typename TYPE_SUPPORT>
void
NDDS_Test_T<DATA_TYPE, TYPE_SUPPORT>::Usage (void) const
{
  cout << "NDDS Usage:" << endl
       << "\t[-shmem]          - using shared memory" << endl;
       
  this->UsageBase ();
}

template<typename DATA_TYPE, typename TYPE_SUPPORT>
int
NDDS_Test_T<DATA_TYPE, TYPE_SUPPORT>::DataTypeAndTopic (
  const char *entity_type)
{
  DDS::ReturnCode_t retcode =
    TYPE_SUPPORT::register_type (this->participant_,
                                 TYPE_SUPPORT::get_type_name ());
    
  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("DataTypeAndTopic", "register_type", retcode);
      return -1;
    }
        
  if (this->CreateTopic () != 0)
    {
      // Error message already output.
      return -1;
    }
    
  return 0;
}

template<typename DATA_TYPE, typename TYPE_SUPPORT>
int
NDDS_Test_T<DATA_TYPE, TYPE_SUPPORT>::InitParticipantFactory (void)
{
  this->participant_factory_ =
    DDS::DomainParticipantFactory::get_instance ();

  if (this->participant_factory_ == 0)
    {
      this->NullReturnErrorMsg ("InitParticipantFactory", "get_instance");
      return -1;
    }
    
  // Do not auto-enable participants upon creation, since we may want 
  // to register transport plugins.
  this->participant_factory_->get_qos (this->factory_qos_);
  this->factory_qos_.entity_factory.autoenable_created_entities =
    DDS_BOOLEAN_FALSE;
    
  DDS::ReturnCode_t retcode =
    this->participant_factory_->set_qos (this->factory_qos_);
    
  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("InitParticipantFactory", "set_qos", retcode);
      return -1;
    }
    
  return 0;  
}

template<typename DATA_TYPE, typename TYPE_SUPPORT>
int
NDDS_Test_T<DATA_TYPE, TYPE_SUPPORT>::InitParticipant (void)
{
  this->participant_ = 
    this->participant_factory_->create_participant (
      this->domain_id_, 
      this->participant_qos_,
      0,
      DDS_STATUS_MASK_NONE);

  if (this->participant_ == 0)
    {
      this->NullReturnErrorMsg ("InitParticipant", "create_participant");
      return -1;
    }
    
  // Must do this before enabling participant.  
  if (this->ConfigureTransport () != 0)
    {
      // Error message already output.
      return -1;
    }
  
  DDS::ReturnCode_t retcode = this->participant_->enable ();
  
  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("InitParticipant", "enable", retcode);
      return -1;
    }
    
  return 0;
}

template<typename DATA_TYPE, typename TYPE_SUPPORT>
void
NDDS_Test_T<DATA_TYPE, TYPE_SUPPORT>::SetParticipantQos (void)
{
  // TODO - integrate with TweakQoS.
  this->participant_factory_->get_default_participant_qos (this->participant_qos_);
  
  // Regardless of where the reader app runs, force the host_id, so we can
  // make the send order deterministic (b/c order is decided by hostId-appId)
  // Pick the same host_id on both publisher and the subscriber.
  // May need dedicated command line arg with multiple topics per domain.
  this->participant_qos_.wire_protocol.rtps_host_id = this->host_id_;
  
  // Lower bound of 1 on role.
  long role = (this->entity_id_ < 1 ? 1 : this->entity_id_);
  this->participant_qos_.wire_protocol.rtps_app_id = role;
  this->participant_qos_.discovery.participant_index = role;

  this->participant_qos_.receiver_pool.buffer_size =
    MAX_MSG_LENGTH + NDDS_OVERHEAD + MY_OWN_TEST_OVERHEAD;
    
  if (this->shared_memory_)
    {
      this->participant_qos_.transport_builtin.mask |= DDS_TRANSPORTBUILTIN_SHMEM;
    }
  
  // TODO - find out about and get rid of these magic numbers.
  if (MAX_MSG_LENGTH + NDDS_OVERHEAD + 14 + 20 + 8 > 64 * 1024)
    {
      this->participant_qos_.transport_builtin.mask &= ~DDS_TRANSPORTBUILTIN_UDPv4;
    }
}

template<typename DATA_TYPE, typename TYPE_SUPPORT>
int
NDDS_Test_T<DATA_TYPE, TYPE_SUPPORT>::ConfigureTransport (void)
{
  DDS::ReturnCode_t retcode = DDS_RETCODE_OK;
  
  if (this->participant_qos_.transport_builtin.mask & DDS_TRANSPORTBUILTIN_UDPv4)
    {
      retcode =
        NDDSTransportSupport::get_builtin_transport_property (
	        this->participant_,
	        DDS_TRANSPORTBUILTIN_UDPv4,
	        this->udpv4_property_.parent);
    
	    if (retcode != DDS_RETCODE_OK) 
	      {
	        this->RetcodeErrorMsg ("ConfigureTransport",
	                               "get_builtin_transport_property",
	                               retcode);
	        return -1;
	      }

	    this->udpv4_property_.parent.message_size_max =
	      MAX_MSG_LENGTH + NDDS_OVERHEAD + MY_OWN_TEST_OVERHEAD;
	      
	    this->udpv4_property_.send_socket_buffer_size =
        this->udpv4_property_.parent.message_size_max;
        
      // This magic number is 15 for subscribersand 2 for publishers
      // in existing test code. We may have to separate or distinguish
      // between these kinds for some NDDS test stuff.
	    this->udpv4_property_.recv_socket_buffer_size =
        15 * this->udpv4_property_.send_socket_buffer_size;
           
	    if (MAX_MSG_LENGTH > UNFRAGMENTED_UDP_PACKET_SIZE_MAX - NDDS_OVERHEAD)
	      {
	        this->udpv4_property_.no_zero_copy = RTI_TRUE;
	      }
	      
	    retcode =
	      NDDSTransportSupport::set_builtin_transport_property (
	        this->participant_,
	        DDS_TRANSPORTBUILTIN_UDPv4,
	        this->udpv4_property_.parent);

	    if (retcode != DDS_RETCODE_OK)
	      {
	        this->RetcodeErrorMsg ("ConfigureTransport",
	                               "set_builtin_transport_property",
	                               retcode);
          return -1;
	      }
    }
    
  if (this->shared_memory_ && this->ConfigShmemTransport () != 0)
    {
      // Error message already output.
      return -1;
    }

  return 0;
}

template<typename DATA_TYPE, typename TYPE_SUPPORT>
int
NDDS_Test_T<DATA_TYPE, TYPE_SUPPORT>::ConfigShmemTransport (void)
{
  DDS::ReturnCode_t retcode =
    NDDSTransportSupport::get_builtin_transport_property (
	    this->participant_,
	    DDS_TRANSPORTBUILTIN_SHMEM,
	    this->shmem_property_.parent);
	    
  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("ConfigShmemTransport",
                             "get_builtin_transport_property",
                             retcode);
      return -1;
    }

  this->shmem_property_.parent.message_size_max =
    MAX_MSG_LENGTH + NDDS_OVERHEAD + MY_OWN_TEST_OVERHEAD;
    
  this->shmem_property_.received_message_count_max = 8;
  
  this->shmem_property_.receive_buffer_size =
	  this->shmem_property_.received_message_count_max
	  * this->shmem_property_.parent.message_size_max;
	    
	retcode =
	  NDDSTransportSupport::set_builtin_transport_property (
	    this->participant_,
	    DDS_TRANSPORTBUILTIN_SHMEM,
	    this->shmem_property_.parent);

  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("ConfigShmemTransport",
                             "set_builtin_transport_property",
                             retcode);
      return -1;
    }

  return 0;
}

template<typename DATA_TYPE, typename TYPE_SUPPORT>
int
NDDS_Test_T<DATA_TYPE, TYPE_SUPPORT>::CreateTopic (void)
{
  // TODO - integrate with TweakQoS.
  DDS::ReturnCode_t retcode =
    this->participant_->get_default_topic_qos (this->topic_qos_);
    
  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("CreateTopic",
                             "get_default_topic_qos",
                             retcode);
      return -1;
    }
  
  this->topic_ =
    this->participant_->create_topic (this->topic_name_.c_str (),
                                      TYPE_SUPPORT::get_type_name (),
                                      this->topic_qos_,
                                      this->topic_listener_,
                                      DDS_STATUS_MASK_NONE);
  
  if (this->topic_ == 0)
    {
      this->NullReturnErrorMsg ("CreateTopic", "create_topic");
      return -1;
    }
    
  return 0;
}

#endif /* NDDS_TEST_T_CPP */

