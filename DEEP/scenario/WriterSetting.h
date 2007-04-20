#ifndef WRITERSETTING_H_
#define WRITERSETTING_H_

#include "SettingTypes.h"
#include "NamedSetting.h"

namespace Deep {

class WriterSetting : public virtual NamedSetting {
public:
    virtual UrgencyType    getUrgency() = 0;
    virtual ImportanceType getImportance() = 0;
};

typedef WriterSetting *WriterSetting_ptr;

}

#endif /*WRITERSETTING_H_*/
