#ifndef ACTORSETTING_IMPL_H_
#define ACTORSETTING_IMPL_H_

/* Base class (interface) */
#include "ActorSetting.h"
/* Base class (implementation) */
#include "impl/NamedSetting_impl.h"
/* Implementation */
#include "SettingsParserNode.h"

namespace Deep {

class ActorSetting_impl : public virtual ActorSetting, public NamedSetting_impl {
    char *topicName;
    char *typeName;
    TopicSetting_ptr topicSetting;
protected:
    ActorSetting_impl(const char *settingName, SettingsParserNode_ptr settingsParserNode);
    virtual ~ActorSetting_impl();
public:
    const char       *getTopicName();
    const char       *getTypeName();
    TopicSetting_ptr  getTopicSetting();
};
typedef ActorSetting_impl *ActorSetting_impl_ptr;
}

#endif /*ACTORSETTING_IMPL_H_*/
