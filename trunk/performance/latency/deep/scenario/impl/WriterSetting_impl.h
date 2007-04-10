#ifndef WRITERSETTING_IMPL_H_
#define WRITERSETTING_IMPL_H_

/* Base class (interface) */
#include "WriterSetting.h"
/* Base class (implementation) */
#include "impl/NamedSetting_impl.h"
/* Friends (factories) */
#include "impl/SourceSetting_impl.h"
#include "impl/ReflectorSetting_impl.h"

namespace Deep {

class WriterSetting_impl : public virtual WriterSetting, public NamedSetting_impl {
    UrgencyType urgency;
    ImportanceType importance;
    /* ctor/dtor */
	WriterSetting_impl(const char *settingName, SettingsParserNode_ptr settingsParserNode);
	virtual ~WriterSetting_impl();
    friend class SourceSetting_impl;
    friend class ReflectorSetting_impl;
public:
    UrgencyType    getUrgency();
    ImportanceType getImportance();
};

}

#endif /*WRITERSETTING_IMPL_H_*/
