#ifndef SINKSETTING_H_
#define SINKSETTING_H_

#include "SettingTypes.h"
#include "ActorSetting.h"
#include "ReaderSetting.h"

namespace Deep {

class SinkSetting : public virtual ActorSetting {
public:
    virtual unsigned int       getTimeoutPeriod() = 0;
    virtual bool               getDoTiming() = 0;
    virtual const char        *getReaderPartitionExpression() = 0;
    virtual ReaderSetting_ptr  getReaderSetting() = 0;
};

typedef SinkSetting *SinkSetting_ptr;

}

#endif /*SINKSETTING_H_*/
