// -*- C++ -*-
//
// $Id$

#include "DataReaderListener.h"

#include "dds/DCPS/Service_Participant.h"

#include "../TypeNoKeyBounded/Bytes4TypeSupportImpl.h"
#include "../TypeNoKeyBounded/Bytes8TypeSupportImpl.h"
#include "../TypeNoKeyBounded/Bytes16TypeSupportImpl.h"
#include "../TypeNoKeyBounded/Bytes32TypeSupportImpl.h"
#include "../TypeNoKeyBounded/Bytes64TypeSupportImpl.h"
#include "../TypeNoKeyBounded/Bytes128TypeSupportImpl.h"
#include "../TypeNoKeyBounded/Bytes256TypeSupportImpl.h"
#include "../TypeNoKeyBounded/Bytes512TypeSupportImpl.h"
#include "../TypeNoKeyBounded/Bytes1024TypeSupportImpl.h"
#include "../TypeNoKeyBounded/Bytes2048TypeSupportImpl.h"
#include "../TypeNoKeyBounded/Bytes4096TypeSupportImpl.h"
#include "../TypeNoKeyBounded/Bytes8192TypeSupportImpl.h"
#include "../TypeNoKeyBounded/Bytes16384TypeSupportImpl.h"

extern long subscriber_delay_msec; // from common.h

template<typename Tseq, typename R, typename Rimpl>
int
read (::DDS::DataReader_ptr reader)
{
  // TWF: There is an optimization to the test by
  // using a pointer to the known servant and 
  // static_casting it to the servant
  typename R::_var_type var_dr = R::_narrow (reader);

  Rimpl* dr_servant =
    ::TAO::DCPS::reference_to_servant<Rimpl, typename R::_ptr_type> (
        var_dr.in ()
      );

  const ::CORBA::Long max_read_samples = 100;
  Tseq samples (max_read_samples);
  ::DDS::SampleInfoSeq infos (max_read_samples);

  int samples_recvd = 0;
  DDS::ReturnCode_t status;

  status = dr_servant->read (samples,
                             infos,
                             max_read_samples,
                             ::DDS::NOT_READ_SAMPLE_STATE, 
                             ::DDS::ANY_VIEW_STATE, 
                             ::DDS::ANY_INSTANCE_STATE);

  if (::DDS::RETCODE_OK == status)
    {
      samples_recvd = samples.length ();
    }
  else if (::DDS::RETCODE_NO_DATA == status)
    {
      ACE_ERROR ((LM_ERROR, "Empty read!\n"));
    }
  else
    {
      ACE_ERROR ((LM_ERROR, "read  data: Error: %d\n", status));
    }

  return samples_recvd;
}

DataReaderListenerImpl::DataReaderListenerImpl (ACE_CDR::ULong num_publishers,
                                                ACE_CDR::ULong primer_samples,
                                                ACE_CDR::ULong stats_samples,
                                                ACE_CDR::ULong data_size,
                                                const char *output_file_name)
 : samples_lost_count_(0),
   samples_rejected_count_(0),
   samples_received_count_(0),
   total_samples_count_(0),
   num_publishers_(num_publishers),
   num_samples_ (stats_samples),
   data_size_ (data_size),
   output_file_name_ (output_file_name),
   stats_ (output_file_name, primer_samples, stats_samples, data_size),
   is_finished_ (false)
{
}

DataReaderListenerImpl::~DataReaderListenerImpl (void)
{
}
  
void
DataReaderListenerImpl::on_requested_deadline_missed (
    ::DDS::DataReader_ptr reader,
    const ::DDS::RequestedDeadlineMissedStatus & status
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
  {
    ACE_UNUSED_ARG (reader);
    ACE_UNUSED_ARG (status);
  }

void
DataReaderListenerImpl::on_requested_incompatible_qos (
    ::DDS::DataReader_ptr reader,
    const ::DDS::RequestedIncompatibleQosStatus & status
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
  {
    ACE_UNUSED_ARG (reader);
    ACE_UNUSED_ARG (status);
  }

void
DataReaderListenerImpl::on_liveliness_changed (
    ::DDS::DataReader_ptr reader,
    const ::DDS::LivelinessChangedStatus & status
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
  {
    ACE_UNUSED_ARG (reader);
    ACE_UNUSED_ARG (status);
/*
    ACE_DEBUG ((LM_INFO, 
                ACE_TEXT ("(%P|%t) DataReaderListenerImpl::")
                ACE_TEXT ("on_liveliness_changed called\n")));
*/
  }

void
DataReaderListenerImpl::on_subscription_match (
    ::DDS::DataReader_ptr reader,
    const ::DDS::SubscriptionMatchStatus & status
    ACE_ENV_ARG_DECL
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
  {
    ACE_UNUSED_ARG (reader) ;
    ACE_UNUSED_ARG (status) ;
/*
    ACE_DEBUG ((LM_INFO,
                ACE_TEXT ("(%P|%t) DataReaderListenerImpl::")
                ACE_TEXT ("on_subscription_match called\n")));
*/
  }


void
DataReaderListenerImpl::on_sample_rejected (
    ::DDS::DataReader_ptr reader,
    const DDS::SampleRejectedStatus& status
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
  {
    ACE_UNUSED_ARG (reader) ;
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("(%P|%t) DataReaderListenerImpl")
                ACE_TEXT ("::on_sample_rejected\n")));

    GuardType guard (this->lock_);
    this->samples_rejected_count_ += status.total_count_change;
    this->total_samples_count_ += status.total_count_change;
  }

void
DataReaderListenerImpl::on_data_available (
    ::DDS::DataReader_ptr reader
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
  {
    GuardType guard (this->lock_);
    
    this->stats_.sample_for_throughput ();
      
    int samples_read = read_samples (reader);
    
    if (this->stats_.ready_to_dump ())
      {
        this->stats_.file_dump_throughput ();
        this->is_finished_ = true;
      }
  }

void
DataReaderListenerImpl::on_sample_lost (
    ::DDS::DataReader_ptr reader,
    const DDS::SampleLostStatus& status
  )
  ACE_THROW_SPEC ((
    CORBA::SystemException
  ))
  {
    ACE_UNUSED_ARG (reader) ;
    ACE_DEBUG ((LM_DEBUG,
                ACE_TEXT ("(%P|%t) DataReaderListenerImpl")
                ACE_TEXT ("::on_sample_lost\n")));

    GuardType guard (this->lock_);
    samples_lost_count_ += status.total_count_change;
    total_samples_count_ += status.total_count_change;
  }

int
DataReaderListenerImpl::read_samples (::DDS::DataReader_ptr reader)
{
  int num_read = 0;

  switch (this->data_size_)
  {
  case 4:
    num_read =
      read< ::Mine::Bytes4Seq,
            ::Mine::Bytes4DataReader,
            ::Mine::Bytes4DataReaderImpl > (reader);
    break;
  case 8:
    num_read =
      read< ::Mine::Bytes8Seq,
            ::Mine::Bytes8DataReader,
            ::Mine::Bytes8DataReaderImpl > (reader);
    break;
  case 16:
    num_read =
      read< ::Mine::Bytes16Seq,
            ::Mine::Bytes16DataReader,
            ::Mine::Bytes16DataReaderImpl > (reader);
    break;
  case 32:
    num_read =
      read< ::Mine::Bytes32Seq,
            ::Mine::Bytes32DataReader,
            ::Mine::Bytes32DataReaderImpl > (reader);
    break;
  case 64:
    num_read =
      read< ::Mine::Bytes64Seq,
            ::Mine::Bytes64DataReader,
            ::Mine::Bytes64DataReaderImpl > (reader);
    break;
  case 128:
    num_read =
      read< ::Mine::Bytes128Seq,
            ::Mine::Bytes128DataReader,
            ::Mine::Bytes128DataReaderImpl > (reader);
    break;
  case 256:
    num_read =
      read< ::Mine::Bytes256Seq,
            ::Mine::Bytes256DataReader,
            ::Mine::Bytes256DataReaderImpl > (reader);
    break;
  case 512:
    num_read =
      read< ::Mine::Bytes512Seq,
            ::Mine::Bytes512DataReader,
            ::Mine::Bytes512DataReaderImpl > (reader);
    break;
  case 1024:
    num_read =
      read< ::Mine::Bytes1024Seq,
            ::Mine::Bytes1024DataReader,
            ::Mine::Bytes1024DataReaderImpl > (reader);
    break;
  case 2048:
    num_read =
      read< ::Mine::Bytes2048Seq,
            ::Mine::Bytes2048DataReader,
            ::Mine::Bytes2048DataReaderImpl > (reader);
    break;
  case 4096:
    num_read =
      read< ::Mine::Bytes4096Seq,
            ::Mine::Bytes4096DataReader,
            ::Mine::Bytes4096DataReaderImpl > (reader);
    break;
  case 8192:
    num_read =
      read< ::Mine::Bytes8192Seq,
            ::Mine::Bytes8192DataReader,
            ::Mine::Bytes8192DataReaderImpl > (reader);
    break;
  case 16384:
    num_read =
      read< ::Mine::Bytes16384Seq,
            ::Mine::Bytes16384DataReader,
            ::Mine::Bytes16384DataReaderImpl > (reader);
    break;
  default:
    ACE_ERROR ((LM_ERROR,
                "ERROR: bad data size %d\n",
                data_size_));
    return 0;
    break;
  };

  return num_read;
}

bool
DataReaderListenerImpl::is_finished (void)
{
  return this->is_finished_;
}

