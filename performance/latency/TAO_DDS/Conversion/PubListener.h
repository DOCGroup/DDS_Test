// -*- C++ -*-
//
// $Id: DataReaderListener.h,v 1.1 2005/07/18 18:21:16 calabrese_p Exp $
#ifndef DATAREADER_LISTENER_IMPL
#define DATAREADER_LISTENER_IMPL

#include <dds/DdsDcpsSubscriptionS.h>
#include <dds/DdsDcpsPublicationC.h>

#include "ace/High_Res_Timer.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

enum TestType
{
  BYTE_SEQ,
  COMPLEX
};

class AckMessageDataReaderImpl;
class PubMessageDataWriterImpl;
class PubComplexMessageDataWriterImpl;

// Class AckDataReaderListenerImpl
class AckDataReaderListenerImpl
  : public virtual POA_DDS::DataReaderListener,
    public virtual PortableServer::RefCountServantBase
{
public:
  //Constructor
  AckDataReaderListenerImpl (CORBA::ULong seq_len,
                             CORBA::ULong primer_samples,
                             CORBA::ULong stats_samples,
                             const char *output_file,
                             TestType test_type);

  void init (DDS::DataReader_ptr dr,
             DDS::DataWriter_ptr dw,
             TestType test_type);
  //Destructor
  virtual ~AckDataReaderListenerImpl (void);

  virtual void on_requested_deadline_missed (
    DDS::DataReader_ptr reader,
    const DDS::RequestedDeadlineMissedStatus & status)
    throw (CORBA::SystemException);

  virtual void on_requested_incompatible_qos (
    DDS::DataReader_ptr reader,
    const DDS::RequestedIncompatibleQosStatus & status)
  throw (CORBA::SystemException);

  virtual void on_liveliness_changed (
    DDS::DataReader_ptr reader,
    const DDS::LivelinessChangedStatus & status)
  throw (CORBA::SystemException);

  virtual void on_subscription_match (
    DDS::DataReader_ptr reader,
    const DDS::SubscriptionMatchStatus & status
  )
  throw (CORBA::SystemException);

  virtual void on_sample_rejected (
    DDS::DataReader_ptr reader,
    const DDS::SampleRejectedStatus& status
  )
  throw (CORBA::SystemException);

  virtual void on_data_available (
    DDS::DataReader_ptr reader
  )
  throw (CORBA::SystemException);

  virtual void on_sample_lost (
    DDS::DataReader_ptr reader,
    const DDS::SampleLostStatus& status
  )
  throw (CORBA::SystemException);

  int done (void) const { return this->done_; }

private:
  DDS::DataWriter_var writer_;
  DDS::DataReader_var reader_;
  AckMessageDataReaderImpl* dr_servant_;
  PubMessageDataWriterImpl* dw_servant_;
  PubComplexMessageDataWriterImpl* dw_servant_complex_;
  DDS::InstanceHandle_t handle_;
  CORBA::ULong seq_len_;
  CORBA::ULong primer_samples_;
  CORBA::ULong stats_samples_;
  CORBA::ULong sample_num_;
  CORBA::Boolean done_;
  TestType test_type_;
};

#endif /* DATAREADER_LISTENER_IMPL  */
