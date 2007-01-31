// -*- C++ -*-
//
// $Id: DataReaderListener.cpp,v 1.1 2005/07/18 18:21:16 calabrese_p Exp $

#include "SubListener.h"
#include "PubMessageTypeSupportImpl.h"
#include "PubComplexMessageTypeSupportImpl.h"
#include "AckMessageTypeSupportImpl.h"

#include <dds/DCPS/Service_Participant.h>

// Implementation skeleton constructor
PubDataReaderListenerImpl::PubDataReaderListenerImpl (void)
  : writer_ (),
    reader_ (),
    dr_servant_(0),
    dr_servant_complex_ (0),
    dw_servant_(0),
    handle_(),
    sample_num_(1),
    done_ (false),
    test_type_ (BYTE_SEQ)
{
}

void PubDataReaderListenerImpl::init (DDS::DataReader_ptr dr, 
                                      DDS::DataWriter_ptr dw,
                                      TestType test_type)
{
  this->writer_ = DDS::DataWriter::_duplicate (dw);
  this->reader_ = DDS::DataReader::_duplicate (dr);
  this->test_type_ = test_type;

  AckMessageDataWriter_var ackmessage_dw =
    AckMessageDataWriter::_narrow (this->writer_.in ());
  this->dw_servant_ =    
    reference_to_servant<AckMessageDataWriterImpl, 
                         AckMessageDataWriter_ptr> (ackmessage_dw.in ());
  DDSPerfTest::AckMessage msg;
  this->handle_ = this->dw_servant_->_cxx_register (msg);

  PubMessageDataReader_var pubmessage_dr = 
    PubMessageDataReader::_unchecked_narrow (this->reader_.in ());
  this->dr_servant_ =
    reference_to_servant<PubMessageDataReaderImpl,
                         PubMessageDataReader_ptr> (pubmessage_dr.in ());
                         
  PubComplexMessageDataReader_var pubcomplexmessage_dr = 
    PubComplexMessageDataReader::_unchecked_narrow (this->reader_.in ());
  this->dr_servant_complex_ =
    reference_to_servant<
        PubComplexMessageDataReaderImpl,
        PubComplexMessageDataReader_ptr
      > (pubcomplexmessage_dr.in());
}

// Implementation skeleton destructor
PubDataReaderListenerImpl::~PubDataReaderListenerImpl (void)
{
}

void PubDataReaderListenerImpl::on_data_available (DDS::DataReader_ptr)
  throw (CORBA::SystemException)
{
    DDSPerfTest::PubMessage message;
    DDSPerfTest::PubComplexMessage complex_message;
    DDS::SampleInfo si;
    CORBA::Long seq_num = 0;
    
    // Use the reader data member (instead of the argument) for efficiency.
    switch (this->test_type_)
      {
        case BYTE_SEQ:
          this->dr_servant_->take_next_sample (message, si) ;
          seq_num = message.seqnum;
          break;
        case COMPLEX:
          this->dr_servant_complex_->take_next_sample (complex_message, si);
          seq_num = complex_message.seqnum;
          break;
        default:
          return;
      }

    if (seq_num == 0)
      {
        this->done_ = true;
        return;
      }
 
    if (seq_num != this->sample_num_)
      {
        ACE_ERROR ((LM_ERROR, 
                    "tao_sub: recieved seqnum %d on %d\n",
                    seq_num,
                    this->sample_num_));
        return;
      }

    DDSPerfTest::AckMessage msg;
    msg.seqnum = seq_num;
    this->dw_servant_->write (msg, this->handle_);

    this->sample_num_++;
    return;    
}

void PubDataReaderListenerImpl::on_requested_deadline_missed (
    DDS::DataReader_ptr,
    const DDS::RequestedDeadlineMissedStatus &
  )
  throw (CORBA::SystemException)
{
}

void PubDataReaderListenerImpl::on_requested_incompatible_qos (
    DDS::DataReader_ptr,
    const DDS::RequestedIncompatibleQosStatus &
  )
  throw (CORBA::SystemException)
{
}

void PubDataReaderListenerImpl::on_liveliness_changed (
    DDS::DataReader_ptr,
    const DDS::LivelinessChangedStatus &
  )
  throw (CORBA::SystemException)
{
}

void PubDataReaderListenerImpl::on_subscription_match (
    DDS::DataReader_ptr,
    const DDS::SubscriptionMatchStatus &
  )
  throw (CORBA::SystemException)
{
}

void PubDataReaderListenerImpl::on_sample_rejected (
    DDS::DataReader_ptr,
    const DDS::SampleRejectedStatus&
  )
  throw (CORBA::SystemException)
{
}

void PubDataReaderListenerImpl::on_sample_lost(
    DDS::DataReader_ptr,
    const DDS::SampleLostStatus&
  )
  throw (CORBA::SystemException)
{
}
