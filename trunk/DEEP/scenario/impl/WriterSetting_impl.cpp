#include "WriterSetting_impl.h"

namespace Deep {
    
static const unsigned int defaultImportance = 0;
static const unsigned int defaultUrgency = 0;

WriterSetting_impl::WriterSetting_impl(
    const char *settingName,
    SettingsParserNode_ptr settingsParserNode) : NamedSetting_impl(settingName) {
        
    settingsParserNode->getValue("importance", importance, defaultImportance);
    settingsParserNode->getValue("urgency", urgency, defaultUrgency);
}

WriterSetting_impl::~WriterSetting_impl() {
}

UrgencyType
WriterSetting_impl::getUrgency() {
    return urgency;
}

ImportanceType
WriterSetting_impl::getImportance() {
    return importance;
}

}
