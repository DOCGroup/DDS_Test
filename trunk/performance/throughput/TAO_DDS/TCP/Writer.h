// -*- C++ -*-
//
// $Id$
#ifndef WRITER_H
#define WRITER_H

#include "dds/DdsDcpsPublicationC.h"
#include "ace/Task.h"

#include "Stats.h"

class Writer : public ACE_Task_Base 
{
public:

  Writer (::DDS::DataWriter_ptr writer, 
          const char *output_filename,
          ACE_CDR::ULong primer_messages = 1,
          ACE_CDR::ULong stats_messages = 1,
          ACE_CDR::ULong data_size = 128,
          int num_readers = 1,
          int writer_id = -1);

  void start (void);

  void end (void);

  /** Lanch a thread to write. **/
  virtual int svc (void);

  long writer_id (void) const;

  bool is_finished (void) const;

private:
  ::DDS::DataWriter_var writer_;
  ACE_CDR::ULong primer_messages_;
  ACE_CDR::ULong stats_messages_;
  ACE_CDR::ULong num_messages_;
  ACE_CDR::ULong data_size_;
  int num_readers_;
  long writer_id_;
  bool finished_sending_;
  PubSub_Stats stats_;
};

#endif /* WRITER_H */
