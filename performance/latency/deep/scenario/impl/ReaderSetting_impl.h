#ifndef READERSETTING_IMPL_H_
#define READERSETTING_IMPL_H_

/* Base class (interface) */
#include "ReaderSetting.h"
/* Base class (implementation) */
#include "impl/NamedSetting_impl.h"
/* Friends (factories) */
#include "impl/ReflectorSetting_impl.h"
#include "impl/SinkSetting_impl.h"
/* Implementation */

namespace Deep {

class ReaderSetting_impl : public virtual ReaderSetting, public NamedSetting_impl {
    
    /* ctor/dtor */
	ReaderSetting_impl(const char *settingName, SettingsParserNode_ptr settingsParserNode);
	virtual ~ReaderSetting_impl();
    friend class ReflectorSetting_impl;
    friend class SinkSetting_impl;
    /* Private members */
    unsigned int historyDepth;
public:
    unsigned int getHistoryDepth();
};

}

#endif /*READERSETTING_IMPL_H_*/
