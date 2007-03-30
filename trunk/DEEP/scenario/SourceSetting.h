#ifndef SOURCESETTING_H_
#define SOURCESETTING_H_

#include "SettingTypes.h"
#include "ActorSetting.h"
#include "WriterSetting.h"

namespace Deep {

class SourceSetting : public virtual ActorSetting {
public:
    virtual unsigned int getBurstSize() = 0;
    virtual unsigned int getSleepTime() = 0;
    virtual unsigned int getNofBursts() = 0;
    
    virtual const char        *getWriterPartitionExpression() = 0;
    virtual WriterSetting_ptr  getWriterSetting() = 0;
};

typedef SourceSetting *SourceSetting_ptr;

}

#endif /*SOURCESETTING_H_*/
