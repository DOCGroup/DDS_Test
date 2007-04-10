/* Interface */
#include "ActorSetting_impl.h"
/* Implementation */
#include "impl/TopicSetting_impl.h"

namespace Deep
{

static char *defaultTypeName = "deepTypes::simpleType";
static char *defaultTopicName = "simpleTopic";

ActorSetting_impl::ActorSetting_impl(
    const char *settingName,
    SettingsParserNode_ptr settingsParserNode) : NamedSetting_impl(settingName) {
    
    SettingsParserNodePtrVector parsedTopics;
    SettingsParserNode_ptr parsedTopic;
    
    settingsParserNode->getValue("typeName", typeName, defaultTypeName);
    settingsParserNode->getValue("topicName", topicName, defaultTopicName);
    
    parsedTopics = settingsParserNode->getChildNodes("topicSetting");
    if (parsedTopics.size() > 0) {
        /* Just pick the first in case there are more */
        parsedTopic = parsedTopics[0];
        topicSetting = new TopicSetting_impl(parsedTopic->getName(), parsedTopic);
    } else {
        topicSetting = NULL;
    }
}

ActorSetting_impl::~ActorSetting_impl() {
}


const char *
ActorSetting_impl::getTopicName() {
    return topicName;
}

const char *
ActorSetting_impl::getTypeName() {
    
    return typeName;
}

TopicSetting_ptr
ActorSetting_impl::getTopicSetting() {
    
    return topicSetting;
}

}
