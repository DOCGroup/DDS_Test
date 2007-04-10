#ifndef NAMEDSETTING_H_
#define NAMEDSETTING_H_

#include "SettingTypes.h"

namespace Deep {
    
class NamedSetting {
public:
    virtual const char *getName() = 0;
};

typedef NamedSetting *NamedSetting_ptr;

}

#endif /*NAMEDSETTING_H_*/
