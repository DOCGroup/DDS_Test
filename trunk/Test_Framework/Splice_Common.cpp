// $Id$

#include "Splice_Common.h"

#if defined (SPLICE_CONFIG)

#include "dds_dcps_private.h"

Splice_Common::Splice_Common (void)
  : TestBase (),
    participant_factory_ (DDS_OBJECT_NIL),
    participant_ (DDS_OBJECT_NIL),
    participant_qos_ (0),
    topic_ (DDS_OBJECT_NIL),
    topic_qos_ (0),
    dt_name_ (0),
    domain_id_ (DDS_OBJECT_NIL)
{
}

Splice_Common::~Splice_Common (void)
{
}

int
Splice_Common::Init (int argc, char *argv[])
{
  ACE_Arg_Shifter arg_shifter (argc, argv);

  if (this->ParseArgs (arg_shifter) != 0)
    {
      // Error message already output.
      return -1;
    }
    
  if (this->InitParticipantFactory () != 0)
    {
      // Error message already output.
      return -1;
    }

  this->participant_qos_ = DDS_DomainParticipantQos__alloc ();
  
  this->SetParticipantQos ();

  if (this->InitParticipant () != 0)
    {
      // Error message already output.
      return -1;
    }
    
  this->topic_qos_ = DDS_TopicQos__alloc ();
  
  return 0;
}

int
Splice_Common::Fini (void)
{
  DDS::ReturnCode_t retcode =
    DDS_DomainParticipant_delete_topic (this->participant_, this->topic_);
    
  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("Fini", "delete_topic", retcode);
      return -1;
    }

  retcode =
    DDS_DomainParticipantFactory_delete_participant (
      this->participant_factory_,
      this->participant_);
    
  if (retcode != DDS_RETCODE_OK)
    {
      this->RetcodeErrorMsg ("Fini", "delete_participant", retcode);
      return -1;
    }
    
  DDS_free (this->participant_qos_);
  DDS_free (this->topic_qos_);
  DDS_string_clean (&this->dt_name_);
  
  return 0;
}

int
Splice_Common::ParseArgs (ACE_Arg_Shifter &arg_shifter)
{
  bool good = true;
  
  // Ignore the command - argv[0].
  arg_shifter.ignore_arg ();
  
  while (arg_shifter.is_anything_left ()) 
    {
      if (this->TestBase::ParseArgs (arg_shifter) != 0)
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

void
Splice_Common::Usage (void) const
{
  this->TestBase::Usage ();
}

int
Splice_Common::InitParticipantFactory (void)
{
  this->participant_factory_ =
    DDS_DomainParticipantFactory_get_instance ();
    
  if (this->participant_factory_ == DDS_OBJECT_NIL)
    {
      this->NullReturnErrorMsg ("InitParticipantFactory", "get_instance");
      return -1;
    }
    
  return 0;  
}

int
Splice_Common::InitParticipant (void)
{
  this->participant_ =
    DDS_DomainParticipantFactory_create_participant (this->participant_factory_, 
                                                     this->domain_id_, 
							                                       this->participant_qos_, 
							                                       0);

  if (this->participant_ == DDS_OBJECT_NIL)
    {
      this->NullReturnErrorMsg ("InitParticipant", "create_participant");
      return -1;
    }
    
  return 0;
}

void
Splice_Common::SetParticipantQos (void)
{
  // TODO - integrate with TweakQoS.
  DDS_DomainParticipantFactory_get_default_participant_qos (
    this->participant_factory_,
    this->participant_qos_);
}

int
Splice_Common::CreateTopic (void)
{
  // TODO - integrate with TweakQoS.
  DDS_DomainParticipant_get_default_topic_qos (this->participant_,
                                               this->topic_qos_);
                                               
  this->topic_ =
    DDS_DomainParticipant_create_topic (this->participant_,
                                        this->topic_name_.c_str (),
                                        this->dt_name_,
                                        this->topic_qos_,
                                        0);
  
  if (this->topic_ == DDS_OBJECT_NIL)
    {
      this->NullReturnErrorMsg ("CreateTopic", "create_topic");
      return -1;
    }
    
  return 0;
}

#endif /* SPLICE_CONFIG */

