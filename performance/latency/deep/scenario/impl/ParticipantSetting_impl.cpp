/* Interface */
#include "impl/ParticipantSetting_impl.h"
/* Implementation */
#include "impl/SourceSetting_impl.h"
#include "impl/ReflectorSetting_impl.h"
#include "impl/SinkSetting_impl.h"

namespace Deep {
    
static char *defaultDomainName = "";

ParticipantSetting_impl::ParticipantSetting_impl(
    const char *settingName, 
    SettingsParserNode_ptr settingsParserNode) : NamedSetting_impl(settingName) {
    
    SettingsParserNodePtrVector parsedActors;
    SettingsParserNode_ptr parsedActor;
    unsigned int i;

    settingsParserNode->getValue("domainId", domainName, defaultDomainName);
    
    parsedActors = settingsParserNode->getChildNodes("sourceSettings");
    for (i=0; i<parsedActors.size(); i++) {
        parsedActor = parsedActors[i];
        sourceSettings.push_back(new SourceSetting_impl(parsedActor->getName(), parsedActor));
    }
    
    parsedActors = settingsParserNode->getChildNodes("reflectorSettings");
    for (i=0; i<parsedActors.size(); i++) {
        parsedActor = parsedActors[i];
        reflectorSettings.push_back(new ReflectorSetting_impl(parsedActor->getName(), parsedActor));
    }
    
    parsedActors = settingsParserNode->getChildNodes("sinkSettings");
    for (i=0; i<parsedActors.size(); i++) {
        parsedActor = parsedActors[i];
        sinkSettings.push_back(new SinkSetting_impl(parsedActor->getName(), parsedActor));
    }
}    
        

ParticipantSetting_impl::~ParticipantSetting_impl() {
}

const char *
ParticipantSetting_impl::getDomainName() {
    return domainName;
}

unsigned int
ParticipantSetting_impl::getNofActors() {
    return sourceSettings.size() + reflectorSettings.size() + sinkSettings.size();
}

const char *
ParticipantSetting_impl::getActorName(
    unsigned int index) {
    
    unsigned int helperIndex;
    const char *result;
    
    result = NULL;
    helperIndex = index;
    if (helperIndex < sourceSettings.size()) {
        result = sourceSettings[helperIndex]->getName();
    } else {
        helperIndex -= sourceSettings.size();
        if (helperIndex < reflectorSettings.size()) {
            result = reflectorSettings[helperIndex]->getName();
        } else {
            helperIndex -= reflectorSettings.size();
            if (helperIndex < sinkSettings.size()) {
                result = sinkSettings[helperIndex]->getName();
            }
        }
    }
    return result;
}

ActorKind
ParticipantSetting_impl::getActorKind(
    unsigned int index) {
        
    unsigned int helperIndex = index;
    ActorKind result;
    
    result = ACTOR_UNKNOWN;
    if (helperIndex < sourceSettings.size()) {
        result = ACTOR_SOURCE;
    } else {
        helperIndex -= sourceSettings.size();
        if (helperIndex < reflectorSettings.size()) {
            result = ACTOR_REFLECTOR;
        } else {
            helperIndex -= reflectorSettings.size();
            if (helperIndex < sinkSettings.size()) {
                result = ACTOR_SOURCE;
            }
        }
    }
    return result;
}

SourceSetting_ptr
ParticipantSetting_impl::getSourceSetting(
    SettingNameType name) {

    unsigned int i;
    SourceSetting_ptr result;
    
    result = NULL;
    if (name == NULL) {
        if (sourceSettings.size() > 0) {
            result = sourceSettings[0];
        }
    } else {
        for (i=0; (i<sourceSettings.size()) && (result == NULL); i++) {
            if (strcmp(sourceSettings[i]->getName(), name) == 0) {
                result = sourceSettings[i];
            }
        }
    }
    return result;
}
        
ReflectorSetting_ptr
ParticipantSetting_impl::getReflectorSetting(
    SettingNameType name) {

    unsigned int i;
    ReflectorSetting_ptr result;
    
    result = NULL;
    if (name == NULL) {
        if (reflectorSettings.size() > 0) {
            result = reflectorSettings[0];
        }
    } else {
        for (i=0; (i<reflectorSettings.size()) && (result == NULL); i++) {
            if (strcmp(reflectorSettings[i]->getName(), name) == 0) {
                result = reflectorSettings[i];
            }
        }
    }
    
    return result;
}

SinkSetting_ptr
ParticipantSetting_impl::getSinkSetting(
    SettingNameType name) {

    unsigned int i;
    SinkSetting_ptr result;
    
    result = NULL;
    if (name == NULL) {
        if (sinkSettings.size() > 0) {
            result = sinkSettings[0];
        }
    } else {
        for (i=0; (i<sinkSettings.size()) && (result == NULL); i++) {
            if (strcmp(sinkSettings[i]->getName(), name) == 0) {
                result = sinkSettings[i];
            }
        }
    }
    return result;
}        

}
