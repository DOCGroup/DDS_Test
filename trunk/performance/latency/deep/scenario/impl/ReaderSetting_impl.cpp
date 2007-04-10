#include "ReaderSetting_impl.h"

namespace Deep
{

const unsigned int defaultHistoryDepth = 1;

ReaderSetting_impl::ReaderSetting_impl(
    const char *settingName,
    SettingsParserNode_ptr settingsParserNode) : NamedSetting_impl(settingName) {

    settingsParserNode->getValue("historyDepth", historyDepth, defaultHistoryDepth);
}

ReaderSetting_impl::~ReaderSetting_impl()
{
}

unsigned int
ReaderSetting_impl::getHistoryDepth() {
    return historyDepth;
}

}
