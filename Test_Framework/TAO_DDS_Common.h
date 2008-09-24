//$Id$
// -*- C++ -*-

//================================================================
/**
 *  @file  TAO_DDS_Common.h
 *
 *  @author Jeff Parsons <j.parsons@vanderbilt.edu>
 *
 *  This file declares a non-template base class to be used with
 *  TAO DDS pub and sub applications.
 */
//================================================================

#ifndef TAO_DDS_COMMON_H
#define TAO_DDS_COMMON_H

#include "dds_config.h"

#if defined (TAO_DDS_CONFIG)

#include "TestBase.h"
#include "dds/DdsDcpsInfrastructureC.h"
#include <tao/PortableServer/Servant_Base.h>

namespace DDS
{
  // StatusKindMask is 1.0, StatusMask is 1.1 and later.
  typedef StatusKindMask StatusMask;
}

// A couple of types found in almost every TAO DDS test,
// but for some reason not factored into the middleware.

enum TransportTypeId
{
  SIMPLE_TCP,
  SIMPLE_UDP
};

enum TransportInstanceId
{
  SUB_TRAFFIC,
  PUB_TRAFFIC
};

namespace TAO
{
  namespace DCPS
  {
    class TransportInterface;
    class TransportImpl;
  }
}

class Test_Framework_Export TAO_DDS_Common : public virtual TestBase
{
protected:
  TAO_DDS_Common (void);
  virtual ~TAO_DDS_Common (void);

  virtual int Init (int argc, char *argv[]);
  virtual int Fini (void);
  int AttachTransport (OpenDDS::DCPS::TransportInterface *entity_impl,
                       OpenDDS::DCPS::TransportImpl *transport_impl,
                       const char *entity_type);
  
protected:
  DDS::DomainParticipantFactory_var participant_factory_;
  
  DDS::DomainParticipant_var participant_;
  DDS::DomainParticipantQos participant_qos_;
  
  DDS::Topic_var topic_;
  DDS::TopicQos topic_qos_;
  
  PortableServer::ServantBase_var safe_ts_servant_;
};

#endif /* TAO_DDS_CONFIG */

#endif /* TAO_DDS_COMMON_H */

