#ifndef TOPICSETTING_H_
#define TOPICSETTING_H_

#include "SettingTypes.h"
#include "NamedSetting.h"

namespace Deep {

class TopicSetting : public virtual NamedSetting {
public:
    virtual bool getReliable() = 0;
};

typedef TopicSetting *TopicSetting_ptr;

}

#endif /*TOPICSETTING_H_*/
