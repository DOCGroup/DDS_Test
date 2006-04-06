// -*- C++ -*-
//
// $Id$
#ifndef DATAREADER_LISTENER_IMPL
#define DATAREADER_LISTENER_IMPL

#include "ace/Synch.h"
#include "ace/SString.h"

#include "Stats.h"

#include "dds/DdsDcpsSubscriptionS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
#pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

class DataReaderListenerImpl 
  : public virtual POA_DDS::DataReaderListener,
    public virtual PortableServer::RefCountServantBase
{
public:
  DataReaderListenerImpl (ACE_CDR::ULong num_publishers,
                          ACE_CDR::ULong primer_samples,
                          ACE_CDR::ULong stats_samples,
                          ACE_CDR::ULong data_size,
                          const char *output_file_name);
  
  virtual ~DataReaderListenerImpl (void);
  
  virtual void on_requested_deadline_missed (
      ::DDS::DataReader_ptr reader,
      const ::DDS::RequestedDeadlineMissedStatus & status
      ACE_ENV_ARG_DECL
    )
  ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

 virtual void on_requested_incompatible_qos (
      ::DDS::DataReader_ptr reader,
      const ::DDS::RequestedIncompatibleQosStatus & status
      ACE_ENV_ARG_DECL
    )
  ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  virtual void on_liveliness_changed (
      ::DDS::DataReader_ptr reader,
      const ::DDS::LivelinessChangedStatus & status
      ACE_ENV_ARG_DECL
    )
  ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  virtual void on_subscription_match (
      ::DDS::DataReader_ptr reader,
      const ::DDS::SubscriptionMatchStatus & status
      ACE_ENV_ARG_DECL
    )
  ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  virtual void on_sample_rejected (
      ::DDS::DataReader_ptr reader,
      const DDS::SampleRejectedStatus & status
    )
  ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  virtual void on_data_available (
      ::DDS::DataReader_ptr reader
    )
  ACE_THROW_SPEC ((
      CORBA::SystemException
    ));
  
  virtual void on_sample_lost (
      ::DDS::DataReader_ptr reader,
      const DDS::SampleLostStatus& status
    )
  ACE_THROW_SPEC ((
      CORBA::SystemException
    ));

  bool is_finished (void);
  
private:
  int read_samples (::DDS::DataReader_ptr reader);

  typedef ACE_Recursive_Thread_Mutex LockType;
  typedef ACE_Guard<LockType>        GuardType;

  // Used to protect the counts 
  LockType lock_;

  ACE_CDR::ULong samples_lost_count_;
  ACE_CDR::ULong samples_rejected_count_;
  ACE_CDR::ULong samples_received_count_;
  ACE_CDR::ULong total_samples_count_;

  ACE_CDR::ULong num_publishers_;
  ACE_CDR::ULong num_samples_;
  ACE_CDR::ULong data_size_;
  
  ACE_CString output_file_name_;
  PubSub_Stats stats_;
  
  bool is_finished_;
};

#endif /* DATAREADER_LISTENER_IMPL  */
