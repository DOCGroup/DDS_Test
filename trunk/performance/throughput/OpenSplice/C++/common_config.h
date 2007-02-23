// Author: Hieu Nguyen
// June 19th, 2006

#ifndef __COMMON_CONFIG_H
#define __COMMON_CONFIG_H

// To avoid a clash of typedefs in ACE and OpenSplice
#define pid_t ACE_pid_t_typedef_clash_workaround
#define mode_t ACE_mode_t_typedef_clash_workaround

#include "ace/Log_Msg.h"
#include "ace/Arg_Shifter.h"
#include "ace/Sched_Params.h"
#include "Stats.h"

#undef pid_t
#undef mode_t

// To avoid a redef error on Windows from OpenSplice header files,
// ACE defines it in config-win32-common.h.
#if defined (FD_SETSIZE)
#undef FD_SETSIZE
#endif

#include "TPTDefDcps_impl.h"
#include "ccpp_dds_dcps.h"

const char *pub_output_file = "stats_pub";
const char *sub_output_file = "stats_sub";
const char *network_config_file = "net.txt";
const char *qos_config_file = "qos.txt";
const char *test_topic_name = "TEST_TOPIC";
const char *test_type_name = "TP_Test::Bytes";
const char *write_partition = "TEST";
const char *read_partition  = "TEST";

unsigned long PRIMER_SAMPLES = 0;
unsigned long STATS_SAMPLES = 100;
unsigned long DATA_SIZE = 1;

int num_datawriters = 1;
int num_datareaders = 1;

// mydebug
bool transfer_complete = false;
int counter = 0;

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

#endif /* __COMMON_CONFIG_H */
