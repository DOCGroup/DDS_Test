// $Id$

#ifndef TAO_DDS_TEST_T_CPP
#define TAO_DDS_TEST_T_CPP

#include "TAO_DDS_Test_T.h"

#ifdef TAO_DDS_CONFIG

#include "DataReaderListener_T.h"

#include "dds/DCPS/Marked_Default_Qos.h"
#include "dds/DCPS/transport/framework/TheTransportFactory.h"
#include "dds/DCPS/transport/simpleTCP/SimpleTcpConfiguration.h"

template<typename TYPE_SUPPORT_IMPL>
TAO_DDS_Test_T<TYPE_SUPPORT_IMPL>::TAO_DDS_Test_T (void)
  : TestBase (),
    TAO_DDS_Common (),
    ts_servant_ (0)
{
}

template<typename TYPE_SUPPORT_IMPL>
TAO_DDS_Test_T<TYPE_SUPPORT_IMPL>::~TAO_DDS_Test_T (void)
{
}

template<typename TYPE_SUPPORT_IMPL>
int
TAO_DDS_Test_T<TYPE_SUPPORT_IMPL>::Init (int argc, char *argv[])
{
  int status = this->TAO_DDS_Common::Init (argc, argv);
  
  if (status != 0)
    {
      // Error message already output.
      return -1;
    }
    
  // Used in type registration and topic creation.  
  this->ts_servant_ = new TYPE_SUPPORT_IMPL ();       
  
  return 0;
}

// This method could be eliminated completely, but it's kept as
// a placeholder in case template-specific things are added later.
template<typename TYPE_SUPPORT_IMPL>
int
TAO_DDS_Test_T<TYPE_SUPPORT_IMPL>::Fini (void)
{
  return this->TAO_DDS_Common::Fini ();
}

template<typename TYPE_SUPPORT_IMPL>
DDS::ReturnCode_t
TAO_DDS_Test_T<TYPE_SUPPORT_IMPL>::RegisterType (void)
{
  return ts_servant_->register_type (this->participant_.in (),
                            this->ts_servant_->get_type_name ());
}

template<typename TYPE_SUPPORT_IMPL>
int
TAO_DDS_Test_T<TYPE_SUPPORT_IMPL>::CreateTopic (void)
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

template<typename TYPE_SUPPORT_IMPL>
int
TAO_DDS_Test_T<TYPE_SUPPORT_IMPL>::DataTypeAndTopic (
  const char *)
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

#endif /* TAO_DDS_CONFIG */

#endif /* TAO_DDS_TEST_T_CPP */
