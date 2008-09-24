// $Id$

#include "TAO_DDS_Common.h"

#if defined (TAO_DDS_CONFIG)

#include "dds/DCPS/transport/framework/TransportInterface.h"

TAO_DDS_Common::TAO_DDS_Common (void)
  : TestBase ()
{
}

TAO_DDS_Common::~TAO_DDS_Common (void)
{
}

int
TAO_DDS_Common::Init (int argc, char *argv[])
{
  // This call must be made before ParseArgs(), so the -DCPSxxx
  // options can be stripped from the command line.
  this->participant_factory_ =
    TheParticipantFactoryWithArgs (argc, argv);

  if (CORBA::is_nil (this->participant_factory_.in ()))
    {
      this->NullReturnErrorMsg ("Init", "TheParticipantFactoryWithArgs");
      return -1;
    }
  
  ACE_Arg_Shifter arg_shifter (argc, argv);
  
  // ParseArgs() is virtual, so this will end up in the most derived
  // class. The call has to come after TheParticipantFactoryWithArgs
  // as explained above.
  if (this->ParseArgs (arg_shifter) != 0)
    {
      // Error message already output.
      return -1;
    }

  // TODO - set with TweakQoS.
  // Must be called after TheParticipantFactoryWithArgs().    
  this->participant_qos_ = PARTICIPANT_QOS_DEFAULT;
  this->topic_qos_ = TOPIC_QOS_DEFAULT;
      
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
    
  return 0;
}

int
TAO_DDS_Common::Fini (void)
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

int
TAO_DDS_Common::AttachTransport (OpenDDS::DCPS::TransportInterface *entity_impl,
                                 OpenDDS::DCPS::TransportImpl *transport_impl,
                                 const char *entity_type)
{
  // Attach the entity to the transport.
  OpenDDS::DCPS::AttachStatus attach_status =
    entity_impl->attach_transport (transport_impl);

  if (attach_status != OpenDDS::DCPS::ATTACH_OK)
    {
      // We failed to attach to the transport for some reason.
      std::string status_str;

      switch (attach_status)
        {
          case OpenDDS::DCPS::ATTACH_BAD_TRANSPORT:
            status_str = "ATTACH_BAD_TRANSPORT";
            break;
          case OpenDDS::DCPS::ATTACH_ERROR:
            status_str = "ATTACH_ERROR";
            break;
          case OpenDDS::DCPS::ATTACH_INCOMPATIBLE_QOS:
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

#endif /* TAO_DDS_CONFIG */

