// Author: Hieu Nguyen
// June 19th, 2006

#ifndef __COMMON_CONFIG_H
#define __COMMON_CONFIG_H

#include "dds_dcps.h"
#include "Stats.h"
#include "ace/CDR_Base.h"
#include "ace/Sched_Params.h"

const char *pub_output_file ("stats_pub");
const char *sub_output_file ("stats_sub");
const char *network_config_file ("net.txt");
const char *qos_config_file ("qos.txt");
const char *test_topic_name ("TEST_TOPIC");

ACE_CDR::ULong PRIMER_SAMPLES = 0;
ACE_CDR::ULong STATS_SAMPLES = 100;
ACE_CDR::ULong DATA_SIZE = 1;

int num_datawriters = 1;
int num_datareaders = 1;
bool transfer_complete = false;


const timeval *listener_start_time;
const timeval *listener_current_time;
ACE_CDR::ULong listener_time_to_live = 100; // 100 seconds
unsigned long num_received_samples = 0;



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
template <typename FooDataType, typename FooDataWriter>
DDS_ReturnCode_t
writewstats (DDS_ReturnCode_t (*ptr2writerwrite) (FooDataWriter,
	                                          const FooDataType*,
						  const DDS_InstanceHandle_t),
	     FooDataType* (*ptr2sample__alloc) (void),
	     FooDataWriter datawriter,
	     PubSub_Stats *mystats)
{  
  DDS_ReturnCode_t retcode;  	

  FooDataType *data_sample = (*ptr2sample__alloc) ();
    
  // initialize the 'data' field to 0
  //data_sample->data = 0;  
  data_sample->timestamp = 0;

  
  // comment out to measure loss rate
  //for (int i = 0; i < PRIMER_SAMPLES + 5*STATS_SAMPLES; i++) {    
  for (int i = 0; i < PRIMER_SAMPLES + STATS_SAMPLES; i++) {    
    mystats->sample_for_throughput (data_sample->timestamp);     

    // dump publisher's throughput stats to file
    if (mystats->ready_to_dump ()) {
      printf ("************ Pub: dump output to file... *************\n");
      mystats->file_dump_throughput ();  
    }

    //printf ("Pub: sending one sample...\n");  
    retcode = (*ptr2writerwrite) (datawriter, data_sample, DDS_HANDLE_NIL);    
  }  


  // send more off-the-record samples to make sure 
  // all the subscribers get enough samples.

  // comment out to measure loss rate
  //for (int j = 0; j < 19; j++) {
  //  for (int i = 0; i < PRIMER_SAMPLES + 5*STATS_SAMPLES; i++)
  //    retcode = (*ptr2writerwrite) (datawriter, data_sample, DDS_HANDLE_NIL);
  //  ACE_OS::sleep (3);
  //}    

  DDS_free (data_sample);
  return retcode;
}



// Template function that wraps around the DataReader's take ()
// function to have it take the data and also use the data for stats.
// Take data using this takewstats () function instead of take ().
// takewstats() examines the samples received, extracts out the timestamps
// and record them to a Stats object.
// It shuts down its timer and dumps the stats to file once the
// transfer is complete.
template <typename FooDataSequence, typename FooDataReader> 
DDS_ReturnCode_t
takewstats (DDS_ReturnCode_t (*ptr2readertake) (FooDataReader,
                                                FooDataSequence*,     
					        DDS_SampleInfoSeq*,    
					        const DDS_long,    
					        const DDS_SampleStateMask,    
					        const DDS_ViewStateMask,    
					        const DDS_InstanceStateMask),
	    DDS_ReturnCode_t (*ptr2readerreturnloan) (FooDataReader,
	                                              FooDataSequence*,
						      DDS_SampleInfoSeq*),
	    FooDataReader datareader,
	    PubSub_Stats *mystats)
{
  DDS_ReturnCode_t retcode;

  FooDataSequence received_seq = { 0, 0, DDS_OBJECT_NIL, FALSE };
  DDS_SampleInfoSeq info_seq = { 0, 0, DDS_OBJECT_NIL, FALSE };

  retcode = (*ptr2readertake) (datareader,
                               &received_seq,
			       &info_seq,						
			       1,			 
			       DDS_ANY_SAMPLE_STATE,				 
			       DDS_ANY_VIEW_STATE,				 
			       DDS_ANY_INSTANCE_STATE);

  int imax = received_seq._length;
  
  if (imax != 0) {
    num_received_samples++;

 //     if (imax > 1)
 //	  printf ("Sub: multiple samples read...\n");    
 //     for (int i = 0; i < imax; i++) {        

    //printf ("Sub: Taking one sample...\n");	    
    mystats->sample_for_throughput (received_seq._buffer[0].timestamp);
	
    if (mystats->ready_to_dump ()) 	
    {	  
      printf ("************ Sub: Dump output to file... *************\n");	  
      mystats->file_dump_throughput ();	  
      transfer_complete = true;	
    }
      
    retcode = (*ptr2readerreturnloan) (datareader, &received_seq, &info_seq);     
  }     
  else     
  {      
    printf ("Sub: DataReader's take() triggered, but no data available.\n");    
  }    

  return retcode;
}


#endif /* __COMMON_CONFIG_H */
