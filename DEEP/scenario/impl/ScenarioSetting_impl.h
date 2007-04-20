#ifndef SCENARIOSETTING_IMPL_H_
#define SCENARIOSETTING_IMPL_H_

/* Base class, interface */
#include "ScenarioSetting.h"
/* Base class, implementation */
#include "impl/NamedSetting_impl.h"
/* Implementation */
#include <vector>
#include "impl/ParticipantSetting_impl.h"

/* Built-in setting names that we can use as long as we have not completely defined the setting mechanism */
#define BUILTIN_SETTING_NAME_SOURCE    "__source__"
#define BUILTIN_SETTING_NAME_REFLECTOR "__reflector__"
#define BUILTIN_SETTING_NAME_SINK      "__sink__"

namespace Deep {

class ScenarioSetting_impl : public virtual ScenarioSetting, public NamedSetting_impl {
    std::vector<ParticipantSetting_ptr> participantSettings;
public:
	ScenarioSetting_impl(const SettingNameType scenarioId);
	virtual ~ScenarioSetting_impl();
    ParticipantSetting_ptr getParticipantSetting(const SettingNameType name);
};

}

#endif /*SCENARIOSETTING_IMPL_H_*/
