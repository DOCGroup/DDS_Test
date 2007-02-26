// -*- C++ -*-
//
// $Id$

#include "Writer.h"

#include "BytesTypeSupportImpl.h"
#include "ComplexTypeSupportImpl.h"

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

      payload.timestamp = i;

      std::cerr << "Writing packet (" << i << ")\n";

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

    write< ::TP_Test::Bytes,
            BytesDataWriter,
            BytesDataWriterImpl > (writer_id_,
                                   data_size_,
                                   num_messages_,
                                   writer_.in (),
                                   this->stats_);
  }
  ACE_CATCHANY
  {
    ACE_PRINT_EXCEPTION (ACE_ANY_EXCEPTION,
                         "Exception caught in svc:");
  }
  ACE_ENDTRY;

  
  ::DDS::InstanceHandleSeq handles;

  ACE_DEBUG ((LM_DEBUG,
              "Writer wait for %d reader remove_associations\n",
              num_datareaders_));
              
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

 ACE_DEBUG ((LM_DEBUG, "Writer thread exit\n")); 

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

