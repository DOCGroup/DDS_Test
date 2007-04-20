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
#include <unistd.h>
#include <sched.h>

#define BUILTIN_SETTING_NAME_DEFAULT BUILTIN_SETTING_NAME_SOURCE

using namespace Deep;

static void set_rt(int prio) 
{
    struct sched_param p;

    p.sched_priority = prio;
    if (-1 == sched_setscheduler(0, SCHED_FIFO, &p)) {
            perror("sched_setscheduler");
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
    unsigned int curArgc;
    
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
    
    sleep(5);
    
    if (actor) {
        actor->run();
    }
    
    sleep(10);

    return 0;    
}
