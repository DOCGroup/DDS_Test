#ifndef PARTICIPANTSETTING_H_
#define PARTICIPANTSETTING_H_

#include "SettingTypes.h"
#include "NamedSetting.h"
#include "SourceSetting.h"
#include "ReflectorSetting.h"
#include "SinkSetting.h"
#include <stdio.h>

namespace Deep {    

class ParticipantSetting : public virtual NamedSetting {
public:
    virtual const char            *getDomainName() = 0;
    virtual unsigned int           getNofActors() = 0;
    virtual const char            *getActorName(unsigned int index) = 0;
    virtual ActorKind              getActorKind(unsigned int index) = 0;
    virtual SourceSetting_ptr      getSourceSetting(SettingNameType name = NULL) = 0;
    virtual ReflectorSetting_ptr   getReflectorSetting(SettingNameType name = NULL) = 0;
    virtual SinkSetting_ptr        getSinkSetting(SettingNameType name = NULL) = 0;
};

typedef ParticipantSetting *ParticipantSetting_ptr;

}

#endif /*PARTICIPANTSETTING_H_*/
