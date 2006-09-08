//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  TAO_DDS_Test_T.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file declares a template class to be used with TAO DDS
 *  tests.
 */
//================================================================

#ifndef TAO_DDS_TEST_T_H
#define TAO_DDS_TEST_T_H

#include "TestBase.h"

#include "dds/DCPS/Service_Participant.h"

namespace DDS
{
  // StatusKindMask is 1.0, StatusMask is 1.1.
  typedef StatusKindMask StatusMask;
}

// A couple of types found in almost every TAO DDS test,
// but for some reason not factored into the middleware.

enum TransportTypeId
{
  SIMPLE_TCP
};

enum TransportInstanceId
{
  SUB_TRAFFIC,
  PUB_TRAFFIC
};

/*
 * @class TAO_DDS_Test_T
 *
 * @brief Template class for TAO DDS tests.
 *
 *
 */
template<typename DATA_TYPE,
         typename TYPE_SUPPORT_IMPL>
class TAO_DDS_Test_T : public TestBase
{
protected:
  TAO_DDS_Test_T (void);
  virtual ~TAO_DDS_Test_T (void);
  
  int Init (int argc, char *argv[]);
  int Fini (void);
  int DataTypeAndTopic (const char *entity_type);
  int AttachTransport (TAO::DCPS::TransportInterface *entity_impl,
                       TAO::DCPS::TransportImpl *transport_impl,
                       const char *entity_type);
  
private:
  virtual int ParseArgs (void) = 0;
  virtual const char *ClassName (void) const;  
  DDS::ReturnCode_t RegisterType (void);
  int CreateTopic (void);
  
protected:
  DDS::DomainParticipantFactory_var participant_factory_;
  
  DDS::DomainParticipant_var participant_;
  DDS::DomainParticipantQos participant_qos_;
  
  DDS::Topic_var topic_;
  DDS::TopicQos topic_qos_;
  
  TYPE_SUPPORT_IMPL *ts_servant_;
  PortableServer::ServantBase_var safe_ts_servant_;
};

#if defined (ACE_TEMPLATES_REQUIRE_SOURCE)
#include "TAO_DDS_Test_T.cpp"
#endif /* ACE_TEMPLATES_REQUIRE_SOURCE */

#if defined (ACE_TEMPLATES_REQUIRE_PRAGMA)
#pragma implementation ("TAO_DDS_Test_T.cpp")
#endif /* ACE_TEMPLATES_REQUIRE_PRAGMA */

#endif /* TAO_DDS_TEST_T_H */

