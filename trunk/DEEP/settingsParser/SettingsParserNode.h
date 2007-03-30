#ifndef SETTINGSPARSERNODE_H_
#define SETTINGSPARSERNODE_H_

#include <vector>

namespace Deep {

typedef enum SettingsParserException_e {
    SETTING_EXCEPTION_UNKNOWN,
    SETTING_EXCEPTION_NOT_IMPLEMENTED,
    SETTING_EXCEPTION_INVALID_FORMAT,
    SETTING_EXCEPTION_NOT_FOUND,
    SETTING_EXCEPTION_NO_VALUE
} SettingsParserException;

typedef char *SettingIdentifierType;

class SettingsParserNode;
typedef SettingsParserNode *SettingsParserNode_ptr;
typedef std::vector<SettingsParserNode_ptr> SettingsParserNodePtrVector;

class SettingsParserNode {
public:
    virtual const char *getName() = 0;
    virtual void getValue(const SettingIdentifierType path, unsigned int &value) throw (SettingsParserException) = 0;
    virtual void getValue(const SettingIdentifierType path, unsigned int &value, unsigned int defaultValue) throw (SettingsParserException) = 0;
    virtual void getValue(const SettingIdentifierType path, float &value) throw (SettingsParserException) = 0;
    virtual void getValue(const SettingIdentifierType path, float &value, float defaultValue) throw (SettingsParserException) = 0;
    virtual void getValue(const SettingIdentifierType path, bool &value) throw (SettingsParserException) = 0;
    virtual void getValue(const SettingIdentifierType path, bool &value, bool defaultValue) throw (SettingsParserException) = 0;
    virtual void getValue(const SettingIdentifierType path, char *&value) throw (SettingsParserException) = 0;
    virtual void getValue(const SettingIdentifierType path, char *&value, char *defaultValue) throw (SettingsParserException) = 0;
    
    virtual SettingsParserNodePtrVector getChildNodes(const SettingIdentifierType path) throw (SettingsParserException) = 0;
};
typedef SettingsParserNode *SettingsParserNode_ptr;
typedef std::vector<SettingsParserNode_ptr> SettingsParserNodePtrVector;

}

#endif /*SETTINGSPARSERNODE_H_*/
