// $Id$

#ifndef SPLICE_TEST_T_CPP
#define SPLICE_TEST_T_CPP

#include "Splice_Test_T.h"

template<typename TYPE_SUPPORT>
Splice_Test_T<TYPE_SUPPORT>::Splice_Test_T (TS_ALLOC_FN_PTR ts_alloc_fn,
                                            REG_DT_FN_PTR register_dt_fn,
                                            DT_NAME_FN_PTR get_dt_name_fn)
  : participant_factory_ (DDS_OBJECT_NIL),
    participant_ (DDS_OBJECT_NIL),
    participant_qos_ (0),
    topic_ (DDS_OBJECT_NIL),
    topic_qos_ (0),
    dt_ (DDS_OBJECT_NIL),
    dt_name_ (0),
    domain_id_ (DDS_OBJECT_NIL),
    ts_alloc_fn_ (ts_alloc_fn),
    register_dt_fn_ (register_dt_fn),
    get_dt_name_fn_ (get_dt_name_fn)
{
}

template<typename TYPE_SUPPORT>
Splice_Test_T<TYPE_SUPPORT>::~Splice_Test_T (void)
{
}

template<typename TYPE_SUPPORT>
int
Splice_Test_T<TYPE_SUPPORT>::Init (int argc, char *argv[])
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

  this->participant_qos_ = DDS_DomainParticipantQos__alloc ();
  
  this->SetParticipantQos ();

  if (this->InitParticipant () != 0)
    {
      // Error message already output.
      return -1;
    }
    
  this->topic_qos_ = DDS_TopicQos__alloc ();
  this->dt_ = (*this->ts_alloc_fn_) ();
  this->dt_name_ = (*this->get_dt_name_fn_) (this->dt_);
    
  return 0;
}

template<typename TYPE_SUPPORT>
int
Splice_Test_T<TYPE_SUPPORT>::Fini (void)
{
  DDS::ReturnCode_t retcode =
    DDS_DomainParticipant_delete_topic (*this->participant_,
                                        *this->topic_);
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
  DDS_free (this->dt_);
  DDS_string_free (this->dt_name_);
}

template<typename TYPE_SUPPORT>
int
Splice_Test_T<TYPE_SUPPORT>::ParseArgs (void)
{
  ACE_Arg_Shifter arg_shifter (this->argc_, this->argv_);
  bool good = true;
  
  // Ignore the command - argv[0].
  arg_shifter.ignore_arg ();
  
  while (arg_shifter.is_anything_left ()) 
    {
      if (this->ParseArgsBase (arg_shifter) != 0)
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

template<typename TYPE_SUPPORT>
void
Splice_Test_T<TYPE_SUPPORT>::Usage (void) const
{
  this->UsageBase ();
}

template<typename TYPE_SUPPORT>
int
Splice_Test_T<TYPE_SUPPORT>::DataTypeAndTopic (const char *entity_type)
{
  DDS::ReturnCode_t retcode = (*this->register_dt_fn_) (this->dt_,
                                                        this->participant_,
                                                        this->dt_name_);
    
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

template<typename TYPE_SUPPORT>
int
Splice_Test_T<TYPE_SUPPORT>::InitParticipantFactory (void)
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

template<typename TYPE_SUPPORT>
int
Splice_Test_T<TYPE_SUPPORT>::InitParticipant (void)
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

template<typename TYPE_SUPPORT>
void
Splice_Test_T<TYPE_SUPPORT>::SetParticipantQos (void)
{
  // TODO - integrate with TweakQoS.
  DDS_DomainParticipantFactory_get_default_participant_qos (
    this->participant_factory_,
    this->participant_qos_);
}

template<typename TYPE_SUPPORT>
int
Splice_Test_T<TYPE_SUPPORT>::CreateTopic (void)
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

#endif /* SPLICE_TEST_T_CPP */
