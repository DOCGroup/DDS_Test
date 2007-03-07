// -*- C++ -*-
//
// $Id: DataReaderListener.cpp,v 1.1 2005/07/18 18:21:16 calabrese_p Exp $
#include "PubListener.h"
#include "PubMessageTypeSupportImpl.h"
#include "PubComplexMessageTypeSupportImpl.h"
#include "AckMessageTypeSupportImpl.h"

#include <dds/DCPS/Service_Participant.h>
#include <ace/streams.h>

// Implementation skeleton constructor
AckDataReaderListenerImpl::AckDataReaderListenerImpl (
    CORBA::ULong seq_len,
    CORBA::ULong primer_samples,
    CORBA::ULong stats_samples,
    const char *output_file,
    TestType test_type)
 : writer_ (),
   reader_ (),
   dr_servant_ (0),
   dw_servant_ (0),
   dw_servant_complex_ (0),
   handle_ (),
   seq_len_ (seq_len),
   primer_samples_ (primer_samples),
   stats_samples_ (stats_samples),
   sample_num_(1),
   done_ (false),
   stats_ (output_file, primer_samples, stats_samples, seq_len),
   test_type_ (test_type)
{
}

// Implementation skeleton destructor
AckDataReaderListenerImpl::~AckDataReaderListenerImpl ()
{
}

void AckDataReaderListenerImpl::init(DDS::DataReader_ptr dr,
                                     DDS::DataWriter_ptr dw,
                                     TestType test_type)
{
  this->writer_ = DDS::DataWriter::_duplicate (dw);
  this->reader_ = DDS::DataReader::_duplicate (dr);
  this->test_type_ = test_type;

  AckMessageDataReader_var ackmessage_dr = 
    AckMessageDataReader::_narrow(this->reader_.in());
  this->dr_servant_ =
    ::TAO::DCPS::reference_to_servant< AckMessageDataReaderImpl,
                                       AckMessageDataReader_ptr>(ackmessage_dr.in());

  PubMessageDataWriter_var pubmessage_dw =
    PubMessageDataWriter::_narrow (this->writer_.in ());
  this->dw_servant_ =
    ::TAO::DCPS::reference_to_servant< PubMessageDataWriterImpl,
                                       PubMessageDataWriter_ptr>(pubmessage_dw.in());
  DDSPerfTest::PubMessage msg;
  this->handle_ = this->dw_servant_->_cxx_register (msg);




  switch (test_type)
    {
      case BYTE_SEQ:
        {
          PubMessageDataWriter_var pubmessage_dw =
            PubMessageDataWriter::_narrow (this->writer_.in ());
          this->dw_servant_ =
            ::TAO::DCPS::reference_to_servant< PubMessageDataWriterImpl,
                                       PubMessageDataWriter_ptr>(pubmessage_dw.in());
          DDSPerfTest::PubMessage msg;
          this->handle_ = this->dw_servant_->_cxx_register (msg);

          break;
        }
      case COMPLEX:
        {
          PubComplexMessageDataWriter_var pubcomplexmessage_dw =
            PubComplexMessageDataWriter::_narrow (this->writer_.in ());
          this->dw_servant_complex_ =
            ::TAO::DCPS::reference_to_servant<
                PubComplexMessageDataWriterImpl,
                PubComplexMessageDataWriter_ptr
              > (pubcomplexmessage_dw.in());
          DDSPerfTest::PubComplexMessage complex_msg;
          this->handle_ =
            this->dw_servant_complex_->_cxx_register (complex_msg);
          break;
        }
      default:
        break;      
    }
}

void AckDataReaderListenerImpl::on_data_available(DDS::DataReader_ptr /* reader */)
  throw (CORBA::SystemException)
{
    DDSPerfTest::AckMessage message;
    DDS::SampleInfo si;
    DDS::ReturnCode_t status = this->dr_servant_->take_next_sample (message, si);
 
    this->timer_.stop ();
    CORBA::ULong sequence_number = message.seqnum;

    switch (status)
      {
        case DDS::RETCODE_OK:
          break;
        case DDS::RETCODE_NO_DATA:
          ACE_ERROR ((LM_ERROR,
                      "reader received DDS::RETCODE_NO_DATA\n"));
          break;
        default:
          ACE_ERROR ((LM_ERROR,
                      "unknown read message error\n"));
          break;
      }
    if (sequence_number != this->sample_num_)
      {
        ACE_ERROR ((LM_ERROR,
                    "tao_pub: recieved seqnum %d on %d\n",
                    sequence_number,
                    this->sample_num_));
        return;
      }

    if (this->sample_num_ > this->primer_samples_)
      {
        this->timer_.elapsed_microseconds (this->elapsed_time_);
        this->stats_.sample (static_cast<ACE_INT32> (this->elapsed_time_));
      }

    if (this->sample_num_ ==  this->stats_samples_ + this->primer_samples_)
      {
        // Send 0 to end the ping-pong operation.
        switch (this->test_type_)
          {
            case BYTE_SEQ:
              {
                DDSPerfTest::PubMessage msg;        
                msg.seqnum = 0;
                this->dw_servant_->write (msg, this->handle_);
                break;
              }
            case COMPLEX:
              {
                DDSPerfTest::PubComplexMessage complex_msg;
                complex_msg.seqnum = 0;
                complex_msg.data.length (0UL);
                this->dw_servant_complex_->write (complex_msg, this->handle_);
                break;
              }
           }
             
        this->done_ = true;
        
        this->stats_.do_stats ();
        this->stats_.file_dump ();
        this->stats_.dump ();
        
        return;
      }
    
    this->sample_num_++;
    
    switch (this->test_type_)
      {
        case BYTE_SEQ:
          {
            DDSPerfTest::PubMessage msg;
            msg.seqnum = this->sample_num_;
            msg.data.length (this->seq_len_);

            this->timer_.start ();
            this->dw_servant_->write (msg, this->handle_);
            break;
          }
        case COMPLEX:
          {
            DDSPerfTest::PubComplexMessage complex_msg;
            complex_msg.seqnum = this->sample_num_;
            complex_msg.data.length (this->seq_len_);
            
            for (CORBA::ULong i = 0; i < this->seq_len_; ++i)
              {
                complex_msg.data[i].length = 1;
                complex_msg.data[i].nested_member.length (1UL);
                complex_msg.data[i].nested_member[0UL].info = "nestinfo";
                complex_msg.data[i].nested_member[0UL].index = -1;
              }

            this->timer_.start ();
            this->dw_servant_complex_->write (complex_msg, this->handle_);
            break;
          }
        default:
          break;
      }
    
    return;    
}

void AckDataReaderListenerImpl::on_requested_deadline_missed (
    DDS::DataReader_ptr,
    const DDS::RequestedDeadlineMissedStatus &)
  throw (CORBA::SystemException)
{
}

void AckDataReaderListenerImpl::on_requested_incompatible_qos (
    DDS::DataReader_ptr,
    const DDS::RequestedIncompatibleQosStatus &)
  throw (CORBA::SystemException)
{
}

void AckDataReaderListenerImpl::on_liveliness_changed (
    DDS::DataReader_ptr,
    const DDS::LivelinessChangedStatus &)
  throw (CORBA::SystemException)
{
}

void AckDataReaderListenerImpl::on_subscription_match (
    DDS::DataReader_ptr,
    const DDS::SubscriptionMatchStatus &)
  throw (CORBA::SystemException)
{
}

void AckDataReaderListenerImpl::on_sample_rejected(
    DDS::DataReader_ptr,
    const DDS::SampleRejectedStatus&)
  throw (CORBA::SystemException)
{
}

void AckDataReaderListenerImpl::on_sample_lost(
  DDS::DataReader_ptr,
  const DDS::SampleLostStatus&)
  throw (CORBA::SystemException)
{
}
