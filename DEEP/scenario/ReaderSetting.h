#ifndef READERSETTING_H_
#define READERSETTING_H_

#include "SettingTypes.h"
#include "NamedSetting.h"

namespace Deep {

class ReaderSetting : public virtual NamedSetting {
public:
    virtual unsigned int getHistoryDepth() = 0;
};

typedef ReaderSetting *ReaderSetting_ptr;

}

#endif /*READERSETTING_H_*/
