#include "impl/SettingsParserXercesNode_impl.h"
#include "impl/SettingsParserXerces_impl.h"
#include "stdlib.h"
#include "strings.h"

namespace Deep
{

SettingsParserXercesNode_impl::~SettingsParserXercesNode_impl()
{
}

const char *
SettingsParserXercesNode_impl::getName() {
    return name;
}

const char *
SettingsParserXercesNode_impl::getType() {
    return type;
}

void
SettingsParserXercesNode_impl::getValue(
    const SettingIdentifierType path,
    unsigned int &value) throw (SettingsParserException) {
    
    char *stringValue;
    getValue(path, stringValue);
    value = atol(stringValue);
}

void
SettingsParserXercesNode_impl::getValue(
    const SettingIdentifierType path,
    unsigned int &value,
    unsigned int defaultValue) throw (SettingsParserException) {
    
    char *stringValue;
    try {
        getValue(path, stringValue);
        value = atol(stringValue);
    }
    catch (SettingsParserException e) {
        if (e == SETTING_EXCEPTION_NOT_FOUND) {
            value = defaultValue;
        } else {
            throw (e);
        }
    }
}

void
SettingsParserXercesNode_impl::getValue(
    const SettingIdentifierType path,
    float &value) throw (SettingsParserException) {
        
    char *stringValue;
    getValue(path, stringValue);
    value = atof(stringValue);
}

void
SettingsParserXercesNode_impl::getValue(
    const SettingIdentifierType path,
    float &value,
    float defaultValue) throw (SettingsParserException) {
        
    char *stringValue;
    try {
        getValue(path, stringValue);
        value = atof(stringValue);
    }
    catch (SettingsParserException e) {
        if (e == SETTING_EXCEPTION_NOT_FOUND) {
            value = defaultValue;
        } else {
            throw (e);
        }
    }
}

void
SettingsParserXercesNode_impl::getValue(
    const SettingIdentifierType path,
    bool &value) throw (SettingsParserException) {

    char *stringValue;
    getValue(path, stringValue);
    value = (strcasecmp(stringValue, "true") == 0);
}

void
SettingsParserXercesNode_impl::getValue(
    const SettingIdentifierType path,
    bool &value,
    bool defaultValue) throw (SettingsParserException) {

    char *stringValue;
    try {
        getValue(path, stringValue);
        value = (strcasecmp(stringValue, "true") == 0);
    }
    catch (SettingsParserException e) {
        if (e == SETTING_EXCEPTION_NOT_FOUND) {
            value = defaultValue;
        } else {
            throw (e);
        }
    }
}

void
SettingsParserXercesNode_impl::getValue(
    const SettingIdentifierType path,
    char *&value) throw (SettingsParserException) {
    
    bool found = false;
    int index = 0;
    NameValue_ptr currentNameValue;
    
    while (!found && (index < values.size())) {
        currentNameValue = values[index];
        if (strcmp(path, currentNameValue->getName()) == 0) {
            found = true;
            value = values[index]->getValue();
        } else {
            index++;
        }
    }
    if (!found) {
        throw SETTING_EXCEPTION_NOT_FOUND;
    }
}

void
SettingsParserXercesNode_impl::getValue(
    const SettingIdentifierType path,
    char *&value,
    char *defaultValue) throw (SettingsParserException) {
    
    bool found = false;
    int index = 0;
    NameValue_ptr currentNameValue;
    
    while (!found && (index < values.size())) {
        currentNameValue = values[index];
        if (strcmp(path, currentNameValue->getName()) == 0) {
            found = true;
            value = values[index]->getValue();
        } else {
            index++;
        }
    }
    if (!found) {
        value = defaultValue;
    }
}

void
SettingsParserXercesNode_impl::setValue(
    const SettingIdentifierType path,
    char *value) {
    
    char *stringHelper;
    try {
        getValue(path, stringHelper);
    }
    catch (SettingsParserException e) {
        if (e == SETTING_EXCEPTION_NOT_FOUND) {
            NameValue_ptr newNameValue;
            newNameValue = new NameValue(path, value);
            values.push_back(newNameValue);
        } else {
            throw (e);
        }
    }
}        
    
SettingsParserNodePtrVector
SettingsParserXercesNode_impl::getChildNodes(
    const SettingIdentifierType path) throw (SettingsParserException) {
    
    SettingsParserNodePtrVector result;
    char *searchPath;
    
    try {
        getValue(path, searchPath);
        result = owner->getChildNodes(searchPath);
    }
    catch (SettingsParserException e) {
        if (e != SETTING_EXCEPTION_NOT_FOUND) {
            throw (e);
        }
    }
    
    return result;
}        

}
