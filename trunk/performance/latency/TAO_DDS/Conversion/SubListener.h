// -*- C++ -*-
//
// $Id: DataReaderListener.h,v 1.1 2005/07/18 18:21:16 calabrese_p Exp $
#ifndef DATAREADER_LISTENER_IMPL
#define DATAREADER_LISTENER_IMPL

#include <dds/DdsDcpsSubscriptionS.h>
#include <dds/DdsDcpsPublicationC.h>

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

enum TestType
{
  BYTE_SEQ,
  COMPLEX
};

class PubMessageDataReaderImpl;
class PubComplexMessageDataReaderImpl;
class AckMessageDataWriterImpl;

//Class PubDataReaderListenerImpl
class PubDataReaderListenerImpl
  : public virtual POA_DDS::DataReaderListener,
    public virtual PortableServer::RefCountServantBase
{
public:
  //Constructor
  PubDataReaderListenerImpl (void);
  void init (DDS::DataReader_ptr dr,
             DDS::DataWriter_ptr dw,
             TestType test_type);

  //Destructor
  virtual ~PubDataReaderListenerImpl (void);

  virtual void on_requested_deadline_missed (
      DDS::DataReader_ptr reader,
      const DDS::RequestedDeadlineMissedStatus & status
    )
    throw (CORBA::SystemException);

  virtual void on_requested_incompatible_qos (
      DDS::DataReader_ptr reader,
      const DDS::RequestedIncompatibleQosStatus & status
    )
    throw (CORBA::SystemException);

  virtual void on_liveliness_changed (
      DDS::DataReader_ptr reader,
      const DDS::LivelinessChangedStatus & status
    )
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

  bool done (void) const { return this->done_; }

private:

  DDS::DataWriter_var writer_;
  DDS::DataReader_var reader_;
  PubMessageDataReaderImpl* dr_servant_;
  PubComplexMessageDataReaderImpl* dr_servant_complex_;
  AckMessageDataWriterImpl* dw_servant_;
  DDS::InstanceHandle_t handle_;
  long sample_num_;
  bool done_;
  TestType test_type_;
};

#endif /* DATAREADER_LISTENER_IMPL  */
