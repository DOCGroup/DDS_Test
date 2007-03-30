#ifndef SCENARIOSETTING_H_
#define SCENARIOSETTING_H_

#include "SettingTypes.h"
#include "ParticipantSetting.h"

namespace Deep {

class ScenarioSetting {
public:
    virtual ParticipantSetting_ptr getParticipantSetting(const SettingNameType name) = 0;
};

typedef ScenarioSetting *ScenarioSetting_ptr;

}

#endif /*SCENARIOSETTING_H_*/
