#ifndef ACTORSETTING_H_
#define ACTORSETTING_H_

#include "NamedSetting.h"
#include "TopicSetting.h"

namespace Deep {

class ActorSetting : public virtual NamedSetting {
public:
    virtual const char      *getTypeName() = 0;
    virtual const char      *getTopicName() = 0;
    virtual TopicSetting_ptr getTopicSetting() = 0;
};
typedef ActorSetting *ActorSetting_ptr;

}

#endif /*ACTORSETTING_H_*/
