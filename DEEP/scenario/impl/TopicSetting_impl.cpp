#include "TopicSetting_impl.h"

namespace Deep
{

static const bool defaultReliable = false;

TopicSetting_impl::TopicSetting_impl(
    const char *settingName,
    SettingsParserNode_ptr settingsParserNode) : NamedSetting_impl(settingName) {
        
    settingsParserNode->getValue("reliable", reliable, defaultReliable);
}

TopicSetting_impl::~TopicSetting_impl() {
}

bool
TopicSetting_impl::getReliable() {
    return reliable;
}

}
