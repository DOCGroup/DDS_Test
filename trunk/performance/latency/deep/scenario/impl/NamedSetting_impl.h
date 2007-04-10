#ifndef NAMEDSETTING_IMPL_H_
#define NAMEDSETTING_IMPL_H_

#include "NamedSetting.h"

namespace Deep {

class NamedSetting_impl : public virtual NamedSetting {
    const char *name;
protected:
	NamedSetting_impl(const char *settingName) : name(settingName) {};
	virtual ~NamedSetting_impl();
    const char *getName();
};

typedef NamedSetting_impl *NamedSetting_impl_ptr;

}

#endif /*NAMEDSETTING_IMPL_H_*/
