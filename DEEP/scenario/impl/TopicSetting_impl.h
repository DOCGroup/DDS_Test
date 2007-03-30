#ifndef TOPICSETTING_IMPL_H_
#define TOPICSETTING_IMPL_H_

/* Base class (interface) */
#include "TopicSetting.h"
/* Base class (implementation) */
#include "impl/NamedSetting_impl.h"
/* Friend classes */
#include "impl/ActorSetting_impl.h"

namespace Deep {

class TopicSetting_impl : public virtual TopicSetting, public NamedSetting_impl {
    bool reliable;
    /* ctor/dtor */
    TopicSetting_impl(const char *settingName, SettingsParserNode_ptr settingsParserNode);
    virtual ~TopicSetting_impl();
    friend class ActorSetting_impl;
public:
    bool getReliable();
};

}

#endif /*TOPICSETTING_IMPL_H_*/
