#include "NamedSetting_impl.h"

namespace Deep
{

/*
NamedSetting_impl::NamedSetting_impl(const SettingNameType _name) {
    name = _name;
}
*/

NamedSetting_impl::~NamedSetting_impl() {
}

const char *
NamedSetting_impl::getName() {
    return name;
}

}
