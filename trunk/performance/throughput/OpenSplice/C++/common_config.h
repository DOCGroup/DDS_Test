// Author: Hieu Nguyen
// June 19th, 2006

#ifndef __COMMON_CONFIG_H
#define __COMMON_CONFIG_H

//#include "Stats.h"
#include "ace/CDR_Base.h"
#include "ace/Sched_Params.h"

#include "ccpp_dds_dcps.h"
#include "ccpp_TPTDef.h"

using namespace DDS;
using namespace TP_Test;

const ACE_CDR::Char *pub_output_file ("stats_pub");
const ACE_CDR::Char *sub_output_file ("stats_sub");
const ACE_CDR::Char *network_config_file ("net.txt");
const ACE_CDR::Char *qos_config_file ("qos.txt");
const ACE_CDR::Char *test_topic_name ("TEST_TOPIC");
const ACE_CDR::Char *test_type_name = ("");

ACE_CDR::ULong PRIMER_SAMPLES = 0;
ACE_CDR::ULong STATS_SAMPLES = 100;
ACE_CDR::ULong DATA_SIZE = 1;

int num_datawriters = 1;
int num_datareaders = 1;


// This can be changed to the desired value.
const int PRIORITY =
  (ACE_Sched_Params::priority_min (ACE_SCHED_FIFO)
   + ACE_Sched_Params::priority_max (ACE_SCHED_FIFO)) / 2;


// Attempt to set the real time priority and lock memory.
void
set_rt (void) 
{
  int rt_status =
    ACE_OS::sched_params (ACE_Sched_Params (ACE_SCHED_FIFO,
                                            PRIORITY,
                                            ACE_SCOPE_PROCESS));
  
  if (rt_status != 0)
    {
      if (ACE_OS::last_error () == EPERM)
        {
          ACE_DEBUG ((LM_DEBUG,
                      "(%P|%t): user is not superuser, "
                      "test runs in time-shared class\n"));
        }
      else
        {
          ACE_ERROR ((LM_ERROR,
                      "(%P|%t): sched_params failed\n"));
        }
    }
}


// Template function that wraps around the DataWriter's write ()
// function to have it send the data and also use the data for stats.
// Send data using this writewstats () function instead of write ().
// writewstats() timestamps the samples being sent and record the timestamps 
// to a Stats object.
// It shuts down its timer and dumps the stats to file once the
// transfer is complete.
template <typename FooDataType, typename FooDataWriter_ptr>
ReturnCode_t 
writewstats (DataWriter_ptr dw/*, PubSub_Stats &mystats*/)
{
  ReturnCode_t retcode;

  FooDataType sample;
  sample.timestamp = 0;

  FooDataWriter_ptr typed_dw;
  typed_dw = dynamic_cast<FooDataWriter_ptr> (dw);

  retcode = typed_dw->write (sample, HANDLE_NIL);

  return retcode;
}


// Template function that wraps around the DataReader's take ()
// function to have it take the data and also use the data for stats.
// Take data using this takewstats () function instead of take ().
// takewstats() examines the samples received, extracts out the timestamps
// and record them to a Stats object.
// It shuts down its timer and dumps the stats to file once the
// transfer is complete.
template <typename FooDataSequence, typename FooDataSequence_var, typename FooDataReader_ptr>
ReturnCode_t
takewstats (DataReader_ptr dr/*, PubSub_Stats &mystats*/)
{
  ReturnCode_t retcode;

  FooDataSequence_var received_seq = new FooDataSequence;
  SampleInfoSeq_var info_seq = new SampleInfoSeq;

  FooDataReader_ptr typed_dr;
  typed_dr = dynamic_cast<FooDataReader_ptr> (dr);

  retcode = typed_dr->take (received_seq,
                            info_seq,
		            1,
			    ANY_SAMPLE_STATE,
		            ANY_VIEW_STATE,
		            ANY_INSTANCE_STATE);

  
  printf ("Sub: Taking one sample.\n");

  return retcode;
}


ReturnCode_t typed_write (DataWriter_ptr dw, ACE_CDR::ULong data_size)
{
  ReturnCode_t retcode;

  switch (data_size) {
    case 4:
      retcode = writewstats<Bytes4, Bytes4DataWriter_ptr> (dw);
      break;
    case 8:
      retcode = writewstats<Bytes8, Bytes8DataWriter_ptr> (dw);
      break;
    case 16:
      retcode = writewstats<Bytes16, Bytes16DataWriter_ptr> (dw);
      break;
    case 32:
      retcode = writewstats<Bytes32, Bytes32DataWriter_ptr> (dw);
      break;
    case 64:
      retcode = writewstats<Bytes64, Bytes64DataWriter_ptr> (dw);
      break;
    case 128:
      retcode = writewstats<Bytes128, Bytes128DataWriter_ptr> (dw);
      break;
    case 256:
      retcode = writewstats<Bytes256, Bytes256DataWriter_ptr> (dw);
      break;
    case 512:
      retcode = writewstats<Bytes512, Bytes512DataWriter_ptr> (dw);
      break;
    case 1024:
      retcode = writewstats<Bytes1024, Bytes1024DataWriter_ptr> (dw);
      break;
    case 2048:
      retcode = writewstats<Bytes2048, Bytes2048DataWriter_ptr> (dw);
      break;
    case 4096:
      retcode = writewstats<Bytes4096, Bytes4096DataWriter_ptr> (dw);
      break;
    case 8192:
      retcode = writewstats<Bytes8192, Bytes8192DataWriter_ptr> (dw);
      break;
    case 16384:
      retcode = writewstats<Bytes16384, Bytes16384DataWriter_ptr> (dw);
      break;
    default:
      printf ("Sub: DATA_SIZE not supported!\n");
  }

  return retcode;
}


ReturnCode_t typed_take (DataReader_ptr dr, ACE_CDR::ULong data_size)
{
  ReturnCode_t retcode;

  switch (data_size) {
    case 4:
      retcode = takewstats<Bytes4Seq, Bytes4Seq_var, Bytes4DataReader_ptr> (dr);
      break;
    case 8:
      retcode = takewstats<Bytes8Seq, Bytes8Seq_var, Bytes8DataReader_ptr> (dr);
      break;
    case 16:
      retcode = takewstats<Bytes16Seq, Bytes16Seq_var, Bytes16DataReader_ptr> (dr);
      break;
    case 32:
      retcode = takewstats<Bytes32Seq, Bytes32Seq_var, Bytes32DataReader_ptr> (dr);
      break;
    case 64:
      retcode = takewstats<Bytes64Seq, Bytes64Seq_var, Bytes64DataReader_ptr> (dr);
      break;
    case 128:
      retcode = takewstats<Bytes128Seq, Bytes128Seq_var, Bytes128DataReader_ptr> (dr);
      break;
    case 256:
      retcode = takewstats<Bytes256Seq, Bytes256Seq_var, Bytes256DataReader_ptr> (dr);
      break;
    case 512:
      retcode = takewstats<Bytes512Seq, Bytes512Seq_var, Bytes512DataReader_ptr> (dr);
      break;
    case 1024:
      retcode = takewstats<Bytes1024Seq, Bytes1024Seq_var, Bytes1024DataReader_ptr> (dr);
      break;
    case 2048:
      retcode = takewstats<Bytes2048Seq, Bytes2048Seq_var, Bytes2048DataReader_ptr> (dr);
      break;
    case 4096:
      retcode = takewstats<Bytes4096Seq, Bytes4096Seq_var, Bytes4096DataReader_ptr> (dr);
      break;
    case 8192:
      retcode = takewstats<Bytes8192Seq, Bytes8192Seq_var, Bytes8192DataReader_ptr> (dr);
      break;
    case 16384:
      retcode = takewstats<Bytes16384Seq, Bytes16384Seq_var, Bytes16384DataReader_ptr> (dr);
      break;
    default:
      printf ("Sub: DATA_SIZE not supported!\n");
  }

  return retcode;
}


#endif /* __COMMON_CONFIG_H */
