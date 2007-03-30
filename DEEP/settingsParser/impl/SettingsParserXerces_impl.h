#ifndef SETTINGSPARSERXERCES_IMPL_H_
#define SETTINGSPARSERXERCES_IMPL_H_

/* Implementation */
#include <vector>

namespace Deep {
    
class SettingsParserXerces_impl {
    /* Children in the scenario settings tree structure (container) */
    SettingsParserNodePtrVector children;
    /* Pointer to the toplevel node */
    SettingsParserNode_ptr topLevelNode;
public:
    /* Public constructor for root object */
    SettingsParserXerces_impl(const char *xmlFile);
    virtual ~SettingsParserXerces_impl();

    SettingsParserNode_ptr getToplevelNode() throw (SettingsParserException);
    SettingsParserNodePtrVector getChildNodes(const char *path);
};

typedef SettingsParserXerces_impl *SettingsParserXerces_impl_ptr;

}                                  

#endif /*SETTINGSPARSERXERCES_IMPL_H_*/
