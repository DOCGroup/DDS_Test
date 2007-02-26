// $Id$

#ifndef NDDS_TEST_T_CPP
#define NDDS_TEST_T_CPP

#include "NDDS_Test_T.h"

#if defined (NDDS_CONFIG)

template<typename TYPE_SUPPORT>
NDDS_Test_T<TYPE_SUPPORT>::NDDS_Test_T (void)
  : TestBase (),
    NDDS_Common ()
{
}

template<typename TYPE_SUPPORT>
NDDS_Test_T<TYPE_SUPPORT>::~NDDS_Test_T (void)
{
}

template<typename TYPE_SUPPORT>
int
NDDS_Test_T<TYPE_SUPPORT>::DataTypeAndTopic (
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

template<typename TYPE_SUPPORT>
int
NDDS_Test_T<TYPE_SUPPORT>::CreateTopic (void)
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

#endif /* NDDS_CONFIG */

#endif /* NDDS_TEST_T_CPP */

