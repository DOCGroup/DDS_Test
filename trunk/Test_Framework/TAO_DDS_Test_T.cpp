// $Id$

#ifndef TAO_DDS_TEST_T_CPP
#define TAO_DDS_TEST_T_CPP

#include "TAO_DDS_Test_T.h"
#include "DataReaderListener_T.h"

#include "dds/DCPS/Marked_Default_Qos.h"
#include "dds/DCPS/transport/framework/TheTransportFactory.h"
#include "dds/DCPS/transport/simpleTCP/SimpleTcpConfiguration.h"

#include "ace/Streams.h"

template<typename DATA_TYPE, typename TYPE_SUPPORT_IMPL>
TAO_DDS_Test_T<DATA_TYPE, TYPE_SUPPORT_IMPL>::TAO_DDS_Test_T (void)
  : participant_qos_ (PARTICIPANT_QOS_DEFAULT), // TODO - TweakQoS
    topic_qos_ (TOPIC_QOS_DEFAULT),
    ts_servant_ (0)
{
}

template<typename DATA_TYPE, typename TYPE_SUPPORT_IMPL>
TAO_DDS_Test_T<DATA_TYPE, TYPE_SUPPORT_IMPL>::~TAO_DDS_Test_T (void)
{
}

template<typename DATA_TYPE, typename TYPE_SUPPORT_IMPL>
int
TAO_DDS_Test_T<DATA_TYPE, TYPE_SUPPORT_IMPL>::Init (int argc, char *argv[])
{
  this->argc_ = argc;
  this->argv_ = argv;
  
  // This call must be made before ParseArgs(), so the -DCPSxxx
  // options can be stripped from the command line.
  this->participant_factory_ =
    TheParticipantFactoryWithArgs (this->argc_, this->argv_);

  if (CORBA::is_nil (this->participant_factory_.in ()))
    {
      this->NullReturnErrorMsg ("Init", "TheParticipantFactoryWithArgs");
      return -1;
    }
    
  if (this->ParseArgs () != 0)
    {
      // Error message already output.
      return -1;
    }

  this->participant_ = 
    this->participant_factory_->create_participant (
      this->domain_id_, 
      this->participant_qos_,
      DDS::DomainParticipantListener::_nil ());

  if (CORBA::is_nil (this->participant_.in ()))
    {
      this->NullReturnErrorMsg ("Init", "create_participant");
      return -1;
    }
    
  // Used in type registration and topic creation.  
  this->ts_servant_ = new TYPE_SUPPORT_IMPL ();
        
  // Gives memory management to InfoRepo ORB.
  PortableServer::ServantBase_var safe_servant = this->ts_servant_; 
  
  return 0;
}

template<typename DATA_TYPE, typename TYPE_SUPPORT_IMPL>
int
TAO_DDS_Test_T<DATA_TYPE, TYPE_SUPPORT_IMPL>::Fini (void)
{
  DDS::ReturnCode_t retcode =
    this->participant_->delete_topic (this->topic_.in ());
    
  if (retcode != DDS::RETCODE_OK)
    {
      this->RetcodeErrorMsg ("Fini", "delete_topic", retcode);
      return -1;
    }
    
  retcode =
    this->participant_factory_->delete_participant (
      this->participant_.in ());
      
  if (retcode != DDS::RETCODE_OK)
    {
      this->RetcodeErrorMsg ("Fini", "delete_participant", retcode);
      return -1;
    }
    
  TheTransportFactory->release ();
  TheServiceParticipant->shutdown (); 
  
  return 0;
}

template<typename DATA_TYPE, typename TYPE_SUPPORT_IMPL>
const char *
TAO_DDS_Test_T<DATA_TYPE, TYPE_SUPPORT_IMPL>::ClassName (void) const
{
  return "TAO_DDS_Test_T";
}

template<typename DATA_TYPE, typename TYPE_SUPPORT_IMPL>
DDS::ReturnCode_t
TAO_DDS_Test_T<DATA_TYPE, TYPE_SUPPORT_IMPL>::RegisterType (void)
{
  typename TYPE_SUPPORT_IMPL::_stub_var_type ts =
    TAO::DCPS::servant_to_reference_2<
      TYPE_SUPPORT_IMPL::_stub_type> (this->ts_servant_);
    
  return ts->register_type (this->participant_.in (),
                            this->ts_servant_->get_type_name ());
}

template<typename DATA_TYPE, typename TYPE_SUPPORT_IMPL>
int
TAO_DDS_Test_T<DATA_TYPE, TYPE_SUPPORT_IMPL>::CreateTopic (void)
{
  this->topic_ =
    this->participant_->create_topic (this->topic_name_.c_str (),
                                      this->ts_servant_->get_type_name (),
                                      this->topic_qos_,
                                      DDS::TopicListener::_nil ());
                                      
  if (CORBA::is_nil (this->topic_.in ()))     
    {
      this->NullReturnErrorMsg ("CreateTopic", "create_topic");
      return -1;
    }
    
  return 0;
}

template<typename DATA_TYPE, typename TYPE_SUPPORT_IMPL>
int
TAO_DDS_Test_T<DATA_TYPE, TYPE_SUPPORT_IMPL>::DataTypeAndTopic (
  const char *entity_type)
{
  DDS::ReturnCode_t retcode = this->RegisterType ();
  
  if (retcode != DDS::RETCODE_OK)
    {
      this->RetcodeErrorMsg ("DataTypeAndTopic", "RegisterType", retcode);
      return -1;
    }
    
  if (this->CreateTopic () != 0)
    {
      // Error message alrady output.
      return -1;
    }
    
  return 0;
}

template<typename DATA_TYPE, typename TYPE_SUPPORT_IMPL>
int
TAO_DDS_Test_T<DATA_TYPE, TYPE_SUPPORT_IMPL>::AttachTransport (
  TAO::DCPS::TransportInterface *entity_impl,
  TAO::DCPS::TransportImpl *transport_impl,
  const char *entity_type)
{
  // Attach the entity to the transport.
  TAO::DCPS::AttachStatus attach_status =
    entity_impl->attach_transport (transport_impl);

  if (attach_status != TAO::DCPS::ATTACH_OK)
    {
      // We failed to attach to the transport for some reason.
      std::string status_str;

      switch (attach_status)
        {
          case TAO::DCPS::ATTACH_BAD_TRANSPORT:
            status_str = "ATTACH_BAD_TRANSPORT";
            break;
          case TAO::DCPS::ATTACH_ERROR:
            status_str = "ATTACH_ERROR";
            break;
          case TAO::DCPS::ATTACH_INCOMPATIBLE_QOS:
            status_str = "ATTACH_INCOMPATIBLE_QOS";
            break;
          default:
            status_str = "Unknown Status";
            break;
        }

      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("TAO_DDS_Test_T::Create%s - ")
                         ACE_TEXT ("failed to attach to the transport. ")
                         ACE_TEXT ("AttachStatus == %s\n"),
                         entity_type,
                         status_str.c_str ()),
                        -1);
    }
    
  return 0;
}

#endif /* TAO_DDS_TEST_T_CPP */

