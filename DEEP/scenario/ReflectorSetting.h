#ifndef REFLECTORSETTING_H_
#define REFLECTORSETTING_H_

#include "SettingTypes.h"
#include "ActorSetting.h"
#include "ReaderSetting.h"
#include "WriterSetting.h"

namespace Deep {

class ReflectorSetting : public virtual ActorSetting {
public:
    virtual unsigned int       getTimeoutPeriod() = 0;
    virtual bool               getDoTiming() = 0;
    virtual const char         *getReaderPartitionExpression() = 0;
    virtual const char         *getWriterPartitionExpression() = 0;
    virtual ReaderSetting_ptr   getReaderSetting() = 0;
    virtual WriterSetting_ptr   getWriterSetting() = 0;
};

typedef ReflectorSetting *ReflectorSetting_ptr;

}

#endif /*REFLECTORSETTING_H_*/
