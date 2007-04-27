#ifndef SETTINGSPARSERDEFAULT_IMPL_H_
#define SETTINGSPARSERDEFAULT_IMPL_H_

#include "SettingsParserNode.h"

namespace Deep {
    
typedef enum ActorKind_e {
    AK_UNKNOWN,
    AK_SOURCE,
    AK_REFLECTOR,
    AK_SINK
} ActorKind;

class SettingsParserDefault_impl;
typedef SettingsParserDefault_impl *SettingsParserDefault_impl_ptr;
typedef std::vector<SettingsParserDefault_impl_ptr>
  SettingsParserDefaultImplPtrVector;

class SettingsParserDefault_impl : public virtual SettingsParserNode {
    /* Private constructor, class is factory of its own instances */ 
    SettingsParserDefault_impl(const char *_name);
    /* Default constructor */
    SettingsParserDefault_impl(){};
    /* Common code for constructors is moved to init() */
    void init(const char *_name);
    /* Private members */
    const char *name;
    SettingsParserDefaultImplPtrVector children;
public:
    /* Public constructor for root object */
	SettingsParserDefault_impl(ActorKind actorKind);
	virtual ~SettingsParserDefault_impl();

    const char  *getName ();
    
    virtual void getValue (const SettingIdentifierType path,
                           unsigned int &value)
      throw (SettingsParserException);
      
    virtual void getValue (const SettingIdentifierType path,
                           float &value)
      throw (SettingsParserException);
      
    virtual void getValue (const SettingIdentifierType path,
                           bool &value)
      throw (SettingsParserException);
      
    virtual void getValue (const SettingIdentifierType path,
                           char *&value)
      throw (SettingsParserException);
    
	// Pure virtual in base class, must implement to instantiate.
	
    virtual void getValue (const SettingIdentifierType /* path */,
                           unsigned int &value, 
                           unsigned int defaulValue)
      throw (SettingsParserException) {}
      
    virtual void getValue (const SettingIdentifierType /* path */,
                           float & /* value */,
                           float /* defaulValue */)
      throw (SettingsParserException) {}
      
    virtual void getValue (const SettingIdentifierType /* path */,
                           bool & /* value */,
                           bool /* defaulValue */)
      throw (SettingsParserException) {}
      
    virtual void getValue (const SettingIdentifierType /* path */,
                           char *& /* value */,
                           char * /* defaulValue */)
      throw (SettingsParserException) {}

    SettingsParserNodePtrVector
    getChildNodes (const SettingIdentifierType path)
      throw (SettingsParserException);
};

}

#endif /*SETTINGSPARSERDEFAULT_IMPL_H_*/
