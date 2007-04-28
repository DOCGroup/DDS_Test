/* Interface */
#include "impl/SettingsParserDefault_impl.h"
/* Implementation */
#include <stdio.h>
#include <string.h>

namespace Deep
{

/* Avoid typo's */
#define N_SCENARIO    "Scenario"
#define N_PARTICIPANT "Participant"
#define N_SOURCE      "Source"
#define N_REFLECTOR   "Reflector"
#define N_SINK        "Sink"
#define N_TOPIC       "Topic"
#define N_READER      "Reader"
#define N_WRITER      "Writer"

static const struct {
   const char *parentName;
   const char *childName;
} configTree[] = {
    {N_SOURCE N_SCENARIO,       N_SOURCE N_PARTICIPANT},
    {N_REFLECTOR N_SCENARIO,    N_REFLECTOR N_PARTICIPANT},
    {N_SINK N_SCENARIO,         N_SINK N_PARTICIPANT},
    {N_SOURCE N_PARTICIPANT,    N_SOURCE,},
    {N_REFLECTOR N_PARTICIPANT, N_REFLECTOR},
    {N_SINK N_PARTICIPANT,      N_SINK},
    {N_SOURCE,                  N_WRITER},
    {N_SOURCE,                  N_TOPIC},
    {N_REFLECTOR,               N_READER},
    {N_REFLECTOR,               N_WRITER},
    {N_REFLECTOR,               N_TOPIC},
    {N_SINK,                    N_READER},
    {N_SINK,                    N_TOPIC},
    {NULL, NULL}
};

#define P_DOMAIN_ID                    "DomainId"
#define P_WRITER_PARTITION_EXPRESSION  "WriterPartitionExpression"
#define P_READER_PARTITION_EXPRESSION  "ReaderPartitionExpression"
#define P_BURST_SIZE                   "BurstSize"
#define P_NOF_BURSTS                   "NofBursts"
#define P_SLEEP_TIME                   "SleepTime"
#define P_SCHEDULING_CLASS             "SchedulingClass"
#define P_SCHEDULING_PRIO              "SchedulingPrio"
#define P_TIMEOUT_PERIOD               "TimeoutPeriod"
#define P_DO_TIMING                    "DoTiming"
#define P_IMPORTANCE                   "Importance"
#define P_URGENCY                      "Urgency"
#define P_RELIABILITY                  "Reliability"
#define P_TOPIC_NAME                   "TopicName"
#define P_TYPE_NAME                    "TypeName"

static const struct {
    const char *nodeName;
    const char *paramName;
    unsigned int defaultValue;
} defaultIntSettings[] = {
    {N_SOURCE,    P_BURST_SIZE,      500},
    {N_SOURCE,    P_NOF_BURSTS,      20},
    {N_SOURCE,    P_SLEEP_TIME,      200},
    {N_SOURCE,    P_SCHEDULING_PRIO, 50},
    {N_REFLECTOR, P_SCHEDULING_PRIO, 50},
    {N_REFLECTOR, P_TIMEOUT_PERIOD,  5000},
    {N_SINK,      P_SCHEDULING_PRIO, 50},
    {N_SINK,      P_TIMEOUT_PERIOD,  5000},
    {N_WRITER,    P_IMPORTANCE,      0},
    {N_WRITER,    P_URGENCY,         0},
    {NULL, NULL, 0}
};

static const struct {
    const char *nodeName;
    const char *paramName;
    float defaultValue;
} defaultFloatSettings[] = {
    {NULL, NULL, 0.0}
};

static const struct {
    const char *nodeName;
    const char *paramName;
    bool defaultValue;
} defaultBoolSettings[] = {
    {N_REFLECTOR, P_DO_TIMING, true},
    {N_SINK,      P_DO_TIMING, true},
    {NULL, NULL, false}
};

#define V_DEFAULT_DOMAIN_ID        ""
#define V_DEFAULT_WRITER_PARTITION "DeepWriterPartition"
#define V_DEFAULT_READER_PARTITION "DeepReaderPartition"
#define V_DEFAULT_SCHEDULING_CLASS "Default"
#define V_DEFAULT_RELIABILITY      "BestEffort"
#define V_DEFAULT_TOPIC_NAME       "simpleTypeTopic"
#define V_DEFAULT_TYPE_NAME        "simpleType"

static const struct {
    const char *nodeName;
    const char *paramName;
    const char *defaultValue;
} defaultStringSettings[] = {
    {N_SOURCE    N_PARTICIPANT,    P_DOMAIN_ID,  V_DEFAULT_DOMAIN_ID,},
    {N_REFLECTOR N_PARTICIPANT,    P_DOMAIN_ID,  V_DEFAULT_DOMAIN_ID,},
    {N_SINK      N_PARTICIPANT,    P_DOMAIN_ID,  V_DEFAULT_DOMAIN_ID,},
    {N_SOURCE,    P_WRITER_PARTITION_EXPRESSION, V_DEFAULT_WRITER_PARTITION},
    {N_SOURCE,    P_SCHEDULING_CLASS,            V_DEFAULT_SCHEDULING_CLASS},
    {N_SOURCE,    P_TOPIC_NAME,                  V_DEFAULT_TOPIC_NAME},
    {N_SOURCE,    P_TYPE_NAME,                   V_DEFAULT_TYPE_NAME},
    {N_REFLECTOR, P_WRITER_PARTITION_EXPRESSION, V_DEFAULT_READER_PARTITION},
    {N_REFLECTOR, P_READER_PARTITION_EXPRESSION, V_DEFAULT_WRITER_PARTITION},
    {N_REFLECTOR, P_SCHEDULING_CLASS,            V_DEFAULT_SCHEDULING_CLASS},
    {N_REFLECTOR, P_TOPIC_NAME,                  V_DEFAULT_TOPIC_NAME},
    {N_REFLECTOR, P_TYPE_NAME,                   V_DEFAULT_TYPE_NAME},
    {N_SINK,      P_READER_PARTITION_EXPRESSION, V_DEFAULT_READER_PARTITION},
    {N_SINK,      P_TOPIC_NAME,                  V_DEFAULT_TOPIC_NAME},
    {N_SINK,      P_TYPE_NAME,                   V_DEFAULT_TYPE_NAME},
    {N_TOPIC,     P_RELIABILITY,                 V_DEFAULT_RELIABILITY},
    {NULL, NULL, NULL}
};

void
SettingsParserDefault_impl::init(const char *_name) {
    const char *currentName;
    int i = 0;
    
    name = _name;
    
    /* Then fill array */
    currentName = configTree[i].parentName;
    while (currentName != NULL) {
        if (strcmp(currentName, name) == 0) {
            children.push_back(new SettingsParserDefault_impl(configTree[i].childName));
        }
        i++;
        currentName = configTree[i].parentName;
    }
}


SettingsParserDefault_impl::SettingsParserDefault_impl(ActorKind actorKind) {
    const char *nodeName = NULL;
    switch (actorKind) {
        case AK_SOURCE:
            nodeName = N_SOURCE N_SCENARIO;
            break;
        case AK_REFLECTOR:
            nodeName = N_REFLECTOR N_SCENARIO;
            break;
        case AK_SINK:
            nodeName = N_SINK N_SCENARIO;
            break;
        default:
            break;
    }
    init(nodeName);
}


SettingsParserDefault_impl::~SettingsParserDefault_impl()
{
    /* TODO: walk over children and delete them */
}


SettingsParserDefault_impl::SettingsParserDefault_impl(const char *_name) {
    init(_name);
}


SettingsParserNodePtrVector
SettingsParserDefault_impl::getChildNodes(const SettingIdentifierType path) throw (SettingsParserException) {
    
    SettingsParserNodePtrVector result;
    unsigned int i;
    bool satisfies;
    bool doSubstring;
    
    doSubstring = (strcmp(path, N_PARTICIPANT) == 0);
    for (i=0; i<children.size(); i++) {
        if (doSubstring) {
            satisfies = (strstr(children[i]->name, path) != NULL);
        } else {
            satisfies = (strcmp(children[i]->name, path) == 0);
        }
        if (satisfies) {
            result.push_back(children[i]);
        }
    }
    return result;
}


void
SettingsParserDefault_impl::getValue(const SettingIdentifierType path, unsigned int &value) throw (SettingsParserException) {
    
    unsigned int i;
    bool found;
    const char *currentName;
    
    found = false;
    i = 0;
    currentName = defaultIntSettings[i].nodeName;
    while (!found && (currentName != NULL)) {
        if (strcmp(name, currentName) == 0) {
            found = (strcmp(path, defaultIntSettings[i].paramName) == 0);
            if (found) {
                value = defaultIntSettings[i].defaultValue;
            }
        }
        currentName = defaultIntSettings[++i].nodeName;
    }
    if (!found) {
        throw SETTING_EXCEPTION_NOT_FOUND;
    }
}


void
SettingsParserDefault_impl::getValue(const SettingIdentifierType path, float &value) throw (SettingsParserException) {
    unsigned int i;
    bool found;
    const char *currentName;
    
    found = false;
    i = 0;
    currentName = defaultFloatSettings[i].nodeName;
    while (!found && (currentName != NULL)) {
        if (strcmp(name, currentName) == 0) {
            found = (strcmp(path, defaultFloatSettings[i].paramName) == 0);
            if (found) {
                value = defaultFloatSettings[i].defaultValue;
            }
        }
        currentName = defaultFloatSettings[++i].nodeName;
    }
    if (!found) {
        throw SETTING_EXCEPTION_NOT_FOUND;
    }
}


void
SettingsParserDefault_impl::getValue(const SettingIdentifierType path, bool &value) throw (SettingsParserException) {
    unsigned int i;
    bool found;
    const char *currentName;
    
    found = false;
    i = 0;
    currentName = defaultBoolSettings[i].nodeName;
    while (!found && (currentName != NULL)) {
        if (strcmp(name, currentName) == 0) {
            found = (strcmp(path, defaultBoolSettings[i].paramName) == 0);
            if (found) {
                value = defaultBoolSettings[i].defaultValue;
            }
        }
        currentName = defaultBoolSettings[++i].nodeName;
    }
    if (!found) {
        throw SETTING_EXCEPTION_NOT_FOUND;
    }
}


void
SettingsParserDefault_impl::getValue (const SettingIdentifierType path,
                                      char *&value)
  throw (SettingsParserException)
{
  // const char *result;
  unsigned int i;
  bool found;
  const char *currentName;
  
  found = false;
  i = 0;
  currentName = defaultStringSettings[i].nodeName;
  while (!found && (currentName != NULL)) {
      if (strcmp(name, currentName) == 0) {
          found = (strcmp(path, defaultStringSettings[i].paramName) == 0);
          if (found) {
              value = strdup(defaultStringSettings[i].defaultValue);
          }
      }
      currentName = defaultStringSettings[++i].nodeName;
  }
  if (!found) {
      throw SETTING_EXCEPTION_NOT_FOUND;
  }
}

const char *
SettingsParserDefault_impl::getName() {
    return name;
}

}
