#include "ReaderSetting_impl.h"

namespace Deep
{

ReaderSetting_impl::ReaderSetting_impl(
    const char *settingName,
    SettingsParserNode_ptr settingsParserNode) : NamedSetting_impl(settingName) {
}

ReaderSetting_impl::~ReaderSetting_impl()
{
}

}
