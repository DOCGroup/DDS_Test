// To avoid a clash of typedefs in ACE and OpenSplice
#define pid_t ACE_pid_t_typedef_clash_workaround
#define mode_t ACE_mode_t_typedef_clash_workaround

#include "ace/Sched_params.h"
#include "ace/OS_NS_unistd.h"

#undef pid_t
#undef mode_t

// To avoid a redef error on Windows from OpenSplice header files,
// ACE defines it in config-win32-common.h.
#if defined (ETIMEDOUT)
#undef ETIMEDOUT
#endif

// To avoid a redef error on Windows from OpenSplice header files,
// ACE defines it in config-win32-common.h.
#if defined (FD_SETSIZE)
#undef FD_SETSIZE
#endif

/* Implementation classes to be used */
#include "impl/ScenarioSetting_impl.h"
#include "impl/ReaderWriterFactory_impl.h"
#include "impl/Source_impl.h"
#include "impl/Reflector_impl.h"
#include "impl/Sink_impl.h"
/* Interfaces */
#include "ParticipantSetting.h"
#include "SourceSetting.h"
#include "ReflectorSetting.h"
#include "SinkSetting.h"
/* Implementation */
//#include <unistd.h>
//#include <sched.h>

#define BUILTIN_SETTING_NAME_DEFAULT BUILTIN_SETTING_NAME_SOURCE

using namespace Deep;

static void set_rt (int prio) 
{
  int rt_status =
    ACE_OS::sched_params (ACE_Sched_Params (ACE_SCHED_FIFO,
                                            prio,
                                            ACE_SCOPE_PROCESS));
  
  if (rt_status != 0)
    {
      switch (ACE_OS::last_error ())
        {
          case EPERM:
            cout << "user is not superuser, "
                 << "test runs in time-shared class" << endl;
            break;
          case EINVAL:
            cout << "priority " << prio
                 << " is invalid on this platform, test runs"
                 << " in time-shared class"
                 << endl;
            break;
          case ESRCH:
            cout << "process id " << ACE_SCOPE_PROCESS
                 << " not found, test runs in time-shared class"
                 << endl;
            break;
          default:
            // No other reasons why sched_params() can fail.
            break;
        }
    }
  else
    {
      cout << "real time priority successfully set!" << endl;
    }
/*
    if (mlockall(MCL_CURRENT || MCL_FUTURE)) {
            fprintf(stderr, 
                    "== Could not lock memory - Run with root access.\n");
    }
*/
}

int
main(
    int argc,
    char *argv[]) {
    
    ScenarioSetting_ptr scenarioSetting;
    ParticipantSetting_ptr participantSetting;
    SourceSetting_ptr sourceSetting;
    ReflectorSetting_ptr reflectorSetting;
    SinkSetting_ptr sinkSetting;
    Actor_ptr actor;
    ReaderWriterFactory_ptr readerWriterFactory;
    char *scenarioName = NULL;
    char *participantName = NULL;
    int curArgc;
    
    curArgc = 1;
    if (argc > curArgc) {
        scenarioName = strdup(argv[curArgc]);
        curArgc++;
        if (argc > curArgc) {
            participantName = strdup(argv[curArgc]);
            curArgc++;
            if (argc > curArgc) {
                int i = atoi(argv[curArgc]);
                if (i!=0) {
                    set_rt(i);
                    curArgc++;
                }
            }
        }
    }
    
    if (scenarioName != NULL) {
        scenarioSetting = new ScenarioSetting_impl(scenarioName);
        participantSetting = scenarioSetting->getParticipantSetting(participantName);
        readerWriterFactory = new ReaderWriterFactory_impl(participantSetting);
    
        /* For now, only get one of the source/sink/reflector settings */
        actor = NULL;
        sourceSetting = participantSetting->getSourceSetting();
        if (sourceSetting) {
            actor = new Source_impl(sourceSetting, readerWriterFactory);
        } else {
            reflectorSetting = participantSetting->getReflectorSetting();
            if (reflectorSetting) {
                actor = new Reflector_impl(reflectorSetting, readerWriterFactory);
            } else {
                sinkSetting = participantSetting->getSinkSetting();
                if (sinkSetting) {
                    actor = new Sink_impl(sinkSetting, readerWriterFactory);
                }
            }
        }
    }
    
	ACE_OS::sleep(5);
    
    if (actor) {
        actor->run();
    }
    
	ACE_OS::sleep(10);

    return 0;    
}
