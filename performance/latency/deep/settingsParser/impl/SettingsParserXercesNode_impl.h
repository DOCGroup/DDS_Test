#ifndef SETTINGSPARSERXERCESNODE_IMPL_H_
#define SETTINGSPARSERXERCESNODE_IMPL_H_

/* Base class (interface) */
#include "SettingsParserNode.h"
/* Implementation */
#include "impl/SettingsParserXerces_impl.h"
#include <vector>

namespace Deep {
    
class NameValue {
    char *name;
    char *value;
public:
    NameValue(char *_name, char *_value) {name = _name; value = _value;}
    virtual ~NameValue() {}
    char *getName() {return name;}
    char *getValue() {return value;}
};
typedef NameValue *NameValue_ptr;
typedef std::vector<NameValue_ptr> NameValuePtrVector;


class SettingsParserXercesNode_impl;
typedef SettingsParserXercesNode_impl *SettingsParserXercesNode_impl_ptr;
typedef std::vector<SettingsParserXercesNode_impl_ptr> SettingsParserXercesNodeImplPtrVector;

class SettingsParserXercesNode_impl : public virtual SettingsParserNode {
private:
    /* Private members */
    SettingsParserXerces_impl_ptr owner;
    const char *name;
    const char *type;
    NameValuePtrVector values;
    /* ctor/dtor */
	SettingsParserXercesNode_impl(SettingsParserXerces_impl_ptr _owner, const char *_name, const char *_type)
        {owner=_owner; name=_name; type=_type;}
	virtual ~SettingsParserXercesNode_impl();
    friend class SettingsParserXerces_impl; /* Factory */
public:
    const char *getName();
    const char *getType();
    void getValue(const SettingIdentifierType path, unsigned int &value) throw (SettingsParserException);
    void getValue(const SettingIdentifierType path, unsigned int &value, unsigned int defaultValue) throw (SettingsParserException);
    void getValue(const SettingIdentifierType path, float &value) throw (SettingsParserException);
    void getValue(const SettingIdentifierType path, float &value, float defaultValue) throw (SettingsParserException);
    void getValue(const SettingIdentifierType path, bool &value) throw (SettingsParserException);
    void getValue(const SettingIdentifierType path, bool &value, bool defaultValue) throw (SettingsParserException);
    void getValue(const SettingIdentifierType path, char *&value) throw (SettingsParserException);
    void getValue(const SettingIdentifierType path, char *&value, char *defaultValue) throw (SettingsParserException);
    void setValue(const SettingIdentifierType path, char *value);
    
    SettingsParserNodePtrVector getChildNodes(const SettingIdentifierType path) throw (SettingsParserException);
};

}

#endif /*SETTINGSPARSERXERCESNODE_IMPL_H_*/
