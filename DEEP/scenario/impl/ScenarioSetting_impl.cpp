/* Interface */
#include "ScenarioSetting_impl.h"
/* Implementation */
#include "impl/SettingsParserXerces_impl.h"
#include "impl/ParticipantSetting_impl.h"
#include <string.h>

namespace Deep
{

ScenarioSetting_impl::ScenarioSetting_impl(const SettingNameType scenarioId) : NamedSetting_impl(scenarioId) {
    
    SettingsParserXerces_impl_ptr settingsParser;
    SettingsParserNode_ptr scenarioSetting;
    SettingsParserNodePtrVector parsedParticipants;
    SettingsParserNode_ptr parsedParticipant;
    ParticipantSetting_ptr newParticipantSetting;
    
    settingsParser = new SettingsParserXerces_impl(scenarioId);
    scenarioSetting = settingsParser->getToplevelNode();
    parsedParticipants = scenarioSetting->getChildNodes("participantSettings");
    
    for (unsigned int i = 0; i<parsedParticipants.size(); i++) {
        parsedParticipant = parsedParticipants[i];            
        newParticipantSetting = new ParticipantSetting_impl(parsedParticipant->getName(), parsedParticipant);
        participantSettings.push_back(newParticipantSetting);
    }
    delete settingsParser;
}

ScenarioSetting_impl::~ScenarioSetting_impl() {
    /* TODO: Delete ParticipantSettings in vector */
}

ParticipantSetting_ptr
ScenarioSetting_impl::getParticipantSetting(
    const SettingNameType name) {

    ParticipantSetting_ptr result = NULL;
    ParticipantSetting_ptr current;
    unsigned int index = 0;

    if (name == NULL) {
        if (participantSettings.size() > 0) {
            result = participantSettings[0];
        }
    } else {
        while ((result == NULL) && (index < participantSettings.size())) {
            current = participantSettings[index];
            if (strcmp(current->getName(), name) == 0) {
                result = current;
            } else {
                index++;
            }
        }
    }
    
    return result;
}

}
