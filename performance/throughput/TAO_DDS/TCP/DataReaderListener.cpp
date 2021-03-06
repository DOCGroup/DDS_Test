// -*- C++ -*-
//
// $Id$

#include "DataReaderListener.h"

#include "dds/DCPS/Service_Participant.h"

#include "BytesTypeSupportImpl.h"
#include "ComplexTypeSupportImpl.h"

extern long subscriber_delay_msec; // from common.h

template<typename Tseq, typename R, typename Rimpl>
ACE_CDR::ULong
read (::DDS::DataReader_ptr reader)
{
  // TWF: There is an optimization to the test by
  // using a pointer to the known servant and 
  // static_casting it to the servant
  typename R::_var_type var_dr = R::_narrow (reader);

  Rimpl* dr_servant =
    ::TAO::DCPS::reference_to_servant<Rimpl, typename R::_ptr_type> (
      var_dr.in ());

  const ::CORBA::Long max_read_samples = 100;
  Tseq samples (max_read_samples);
  ::DDS::SampleInfoSeq infos (max_read_samples);

  DDS::ReturnCode_t status =
    dr_servant->take (samples,
                      infos,
                      max_read_samples,
                      ::DDS::NOT_READ_SAMPLE_STATE,
                      ::DDS::ANY_VIEW_STATE, 
                      ::DDS::ANY_INSTANCE_STATE);

  if (::DDS::RETCODE_OK == status)
    {
      if (samples.length () > 1)
        {
          ACE_DEBUG ((LM_DEBUG, "multiple samples read\n"));
        }
    }
  else if (::DDS::RETCODE_NO_DATA == status)
    {
      ACE_ERROR ((LM_ERROR, "Empty read!\n"));
    }
  else
    {
      ACE_ERROR ((LM_ERROR, "read  data: Error: %d\n", status));
    }

  return samples[0].timestamp;
}

DataReaderListenerImpl::DataReaderListenerImpl (ACE_CDR::ULong num_publishers,
                                                ACE_CDR::ULong primer_samples,
                                                ACE_CDR::ULong stats_samples,
                                                ACE_CDR::ULong data_size,
                                                const char *output_file_name)
 : samples_lost_count_( 0),
   samples_rejected_count_ (0),
   samples_received_count_ (0),
   total_samples_count_ (0),
   num_publishers_ (num_publishers),
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
  )
{
  ACE_UNUSED_ARG (reader);
  ACE_UNUSED_ARG (status);
}

void
DataReaderListenerImpl::on_requested_incompatible_qos (
    ::DDS::DataReader_ptr reader,
    const ::DDS::RequestedIncompatibleQosStatus & status
  )
{
  ACE_UNUSED_ARG (reader);
  ACE_UNUSED_ARG (status);
}

void
DataReaderListenerImpl::on_liveliness_changed (
    ::DDS::DataReader_ptr reader,
    const ::DDS::LivelinessChangedStatus & status
  )
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
  )
{
ACE_DEBUG ((LM_DEBUG, "(%P|%t)on_subscription_match\n"));
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
  ::DDS::DataReader_ptr reader)
{
  std::cerr << "Data is available.\n";
  GuardType guard (this->lock_);
  
  ACE_CDR::ULong ts = read_samples (reader);
  
  this->stats_.sample_for_throughput (ts, false);
    
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

  num_read =
    read< BytesSeq,
          BytesDataReader,
          BytesDataReaderImpl > (reader);

/*  if( num_read > 1 )
  {
    fprintf(stderr, "The 'impossible' has happened and we took more than ");
    fprintf(stderr, " 1 (actually %d)\n", num_read);
  }  
*/
  return num_read;
}

bool
DataReaderListenerImpl::is_finished (void)
{
  return this->is_finished_;
}

