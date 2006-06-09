// -*- C++ -*-
//
// $Id$

#include "Writer.h"

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

#include "dds/DCPS/Service_Participant.h"
#include "ace/OS_NS_unistd.h"

extern ACE_Condition<ACE_Recursive_Thread_Mutex> done_condition_;

template<typename T, typename W, typename Wimpl>
void write (long /* id */,
            ACE_CDR::ULong size,
            ACE_CDR::ULong num_messages,
            ::DDS::DataWriter_ptr writer,
            PubSub_Stats & stats)
{
  T payload;
  payload.data.length (size);

  for (ACE_CDR::ULong i = 0; i < size; ++i)
    {
      payload.data[i] = static_cast<CORBA::Octet> (i % 256);
      payload.timestamp = 0;
    }

  typename W::_var_type pt_dw = W::_narrow (writer);
    
  if (CORBA::is_nil (pt_dw.in ()))
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT(" %P|%t Writer::write - ")
                  ACE_TEXT ("narrow of data writer failed\n")));
                  
      return;
    }

  Wimpl* pt_servant =
    ::TAO::DCPS::reference_to_servant<Wimpl, typename W::_ptr_type> (
        pt_dw.in ()
      );

  // SHH remove this kludge when the transport is fixed.
//  ACE_OS::sleep (2); // ensure that the connection has been fully established

  ::DDS::InstanceHandle_t handle 
      = pt_dw->_cxx_register (payload);

  for (ACE_CDR::ULong i = 0; i < num_messages; ++i)
    {
      stats.sample_for_throughput (payload.timestamp);
      
      pt_servant->write (payload, 
                         handle);
    }
    
  if (stats.ready_to_dump ())
    {
      stats.file_dump_throughput ();
    }
}

Writer::Writer (::DDS::DataWriter_ptr writer,
                const char *output_filename,
                ACE_CDR::ULong primer_messages,
                ACE_CDR::ULong stats_messages,
                ACE_CDR::ULong data_size, 
                int num_datareaders,
                int writer_id)
  : writer_ (::DDS::DataWriter::_duplicate (writer)),
    primer_messages_ (primer_messages),
    stats_messages_ (stats_messages),
    data_size_ (data_size),
    num_datareaders_ (num_datareaders),
    writer_id_ (writer_id),
    finished_sending_ (false),
    stats_ (output_filename, primer_messages, stats_messages, data_size)
{
  num_messages_ = primer_messages + stats_messages;
}

void 
Writer::start (void)
{
  if (activate (THR_NEW_LWP | THR_JOINABLE, 1) == -1) 
  {
    ACE_ERROR ((LM_ERROR,
                ACE_TEXT(" %P|%t Writer::start, ")
                ACE_TEXT ("%p."), 
                "activate")); 
  }
}

void 
Writer::end (void) 
{
  wait ();
}

int 
Writer::svc (void)
{
  ACE_TRY_NEW_ENV
  {
    int num_connected_subs = 0;
    ::DDS::InstanceHandleSeq handles;

     while (num_connected_subs != this->num_datareaders_)
       {
         ACE_OS::sleep (1);
         writer_->get_matched_subscriptions (handles);
         num_connected_subs = handles.length ();
       }

    //ACE_OS::sleep (2);

    switch (data_size_)
    {
    case 4:
      write< ::TP_Test::Bytes4,
             ::Mine::Bytes4DataWriter,
             ::Mine::Bytes4DataWriterImpl >
        (writer_id_,
         data_size_,
         num_messages_,
         writer_.in (),
         this->stats_);
      break;
    case 8:
      write< ::TP_Test::Bytes8,
             ::Mine::Bytes8DataWriter,
             ::Mine::Bytes8DataWriterImpl >
        (writer_id_,
         data_size_,
         num_messages_,
         writer_.in (),
         this->stats_);
      break;
    case 16:
      write< ::TP_Test::Bytes16,
             ::Mine::Bytes16DataWriter,
             ::Mine::Bytes16DataWriterImpl >
        (writer_id_,
         data_size_,
         num_messages_,
         writer_.in (),
         this->stats_);
      break;
    case 32:
      write< ::TP_Test::Bytes32,
             ::Mine::Bytes32DataWriter,
             ::Mine::Bytes32DataWriterImpl >
        (writer_id_,
         data_size_,
         num_messages_,
         writer_.in (),
         this->stats_);
      break;
    case 64:
      write< ::TP_Test::Bytes64,
             ::Mine::Bytes64DataWriter,
             ::Mine::Bytes64DataWriterImpl >
        (writer_id_,
         data_size_,
         num_messages_,
         writer_.in (),
         this->stats_);
      break;
    case 128:
      write< ::TP_Test::Bytes128,
             ::Mine::Bytes128DataWriter,
             ::Mine::Bytes128DataWriterImpl >
        (writer_id_,
         data_size_,
         num_messages_,
         writer_.in (),
         this->stats_);
      break;
    case 256:
      write< ::TP_Test::Bytes256,
             ::Mine::Bytes256DataWriter,
             ::Mine::Bytes256DataWriterImpl >
        (writer_id_,
         data_size_,
         num_messages_,
         writer_.in (),
         this->stats_);
      break;
    case 512:
      write< ::TP_Test::Bytes512,
             ::Mine::Bytes512DataWriter,
             ::Mine::Bytes512DataWriterImpl >
        (writer_id_,
         data_size_,
         num_messages_,
         writer_.in (),
         this->stats_);
      break;
    case 1024:
      write< ::TP_Test::Bytes1024,
             ::Mine::Bytes1024DataWriter,
             ::Mine::Bytes1024DataWriterImpl >
        (writer_id_,
         data_size_,
         num_messages_,
         writer_.in (),
         this->stats_);
      break;
    case 2048:
      write< ::TP_Test::Bytes2048,
             ::Mine::Bytes2048DataWriter,
             ::Mine::Bytes2048DataWriterImpl >
        (writer_id_,
         data_size_,
         num_messages_,
         writer_.in (),
         this->stats_);
      break;
    case 4096:
      write< ::TP_Test::Bytes4096,
             ::Mine::Bytes4096DataWriter,
             ::Mine::Bytes4096DataWriterImpl >
        (writer_id_,
         data_size_,
         num_messages_,
         writer_.in (),
         this->stats_);
      break;
    case 8192:
      write< ::TP_Test::Bytes8192,
             ::Mine::Bytes8192DataWriter,
             ::Mine::Bytes8192DataWriterImpl >
        (writer_id_,
         data_size_,
         num_messages_,
         writer_.in (),
         this->stats_);
      break;
    case 16384:
      write< ::TP_Test::Bytes16384,
             ::Mine::Bytes16384DataWriter,
             ::Mine::Bytes16384DataWriterImpl >
        (writer_id_,
         data_size_,
         num_messages_,
         writer_.in (),
         this->stats_);
      break;
    default:
      ACE_ERROR ((LM_ERROR,
                  "ERROR: bad data size %d\n",
                  data_size_));
      return 1;
    };
  }
  ACE_CATCHANY
  {
    ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                         "Exception caught in svc:");
  }
  ACE_ENDTRY;

  
  ::DDS::InstanceHandleSeq handles;
  
  while (!finished_sending_)
    {
      ACE_OS::sleep (1);
      writer_->get_matched_subscriptions (handles);
      
      if (0 == handles.length ())
        {
          this->finished_sending_ = true;
          done_condition_.signal ();
        }
    }


//          this->finished_sending_ = true;
//          done_condition_.signal ();
  return 0;
}

long 
Writer::writer_id (void) const
{
  return this->writer_id_;
}

bool
Writer::is_finished (void) const
{
  return this->finished_sending_;
}

