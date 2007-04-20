#ifndef PARTICIPANTSETTING_IMPL_H_
#define PARTICIPANTSETTING_IMPL_H_

/* Base class (interface) */
#include "ParticipantSetting.h"
/* Base class (implementation) */
#include "impl/NamedSetting_impl.h"
/* Factory friend */
#include "impl/ScenarioSetting_impl.h"
/* Implementation */
#include "SettingsParserNode.h"
#include "SourceSetting.h"
#include "ReflectorSetting.h"
#include "SinkSetting.h"
#include <vector>

namespace Deep {

class ParticipantSetting_impl : public virtual ParticipantSetting, public NamedSetting_impl {

    /* Properties */
    char *domainName;
    /* Children */
    std::vector<SourceSetting_ptr> sourceSettings;
    std::vector<ReflectorSetting_ptr> reflectorSettings;
    std::vector<SinkSetting_ptr> sinkSettings;
    /* To be constructed by a factory only */
	ParticipantSetting_impl(const char *settingName, SettingsParserNode_ptr settingsParserNode);
	virtual ~ParticipantSetting_impl();
    friend class ScenarioSetting_impl;
public:
    const char            *getDomainName();
    unsigned int           getNofActors();
    const char            *getActorName(unsigned int index);
    ActorKind              getActorKind(unsigned int index);
    SourceSetting_ptr      getSourceSetting(SettingNameType name = NULL);
    ReflectorSetting_ptr   getReflectorSetting(SettingNameType name = NULL);
    SinkSetting_ptr        getSinkSetting(SettingNameType name = NULL);
};

typedef ParticipantSetting_impl *ParticipantSetting_impl_ptr;

}

#endif /*PARTICIPANTSETTING_IMPL_H_*/

