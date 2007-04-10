#include "impl/SettingsParserXercesNode_impl.h"
#include "impl/SettingsParserXerces_impl.h"

#include "xercesc/util/PlatformUtils.hpp"
#include "xercesc/parsers/AbstractDOMParser.hpp"
#include "xercesc/dom/DOMImplementation.hpp"
#include "xercesc/dom/DOMImplementationLS.hpp"
#include "xercesc/dom/DOMImplementationRegistry.hpp"
#include "xercesc/dom/DOMBuilder.hpp"
#include "xercesc/dom/DOMException.hpp"
#include "xercesc/dom/DOMDocument.hpp"
#include "xercesc/dom/DOMNodeList.hpp"
#include "xercesc/dom/DOMError.hpp"
#include "xercesc/dom/DOMLocator.hpp"
#include "xercesc/dom/DOMNamedNodeMap.hpp"
#include "xercesc/dom/DOMAttr.hpp"
#include "xercesc/dom/DOMElement.hpp"


XERCES_CPP_NAMESPACE_USE

namespace Deep
{
    
const char *nameName = "name";
const char *nameType = "xsi:type";

static void
fillSettingsNode(
    SettingsParserXercesNode_impl_ptr settingsNode,
    DOMElement *element) {
    
    /* get all the other attributes */
    DOMNamedNodeMap *attributes = element->getAttributes();
    for(int i = 0; i < attributes->getLength(); i++) {
        DOMAttr *attribute = (DOMAttr*) attributes->item(i);
        /* get attribute name */
        char *attrName = XMLString::transcode(attribute->getName());
        if ((strcmp(attrName, nameName) != 0) &&
            (strcmp(attrName, nameType) != 0)) {
            char *attrValue = XMLString::transcode(attribute->getValue());
            settingsNode->setValue(attrName, attrValue);
        }
    }
}


/* The constructor parses the complete XML file and builds the corresponding
 * tree of settings nodes */
SettingsParserXerces_impl::SettingsParserXerces_impl(const char *xmlFile){
    
    try {
      XMLPlatformUtils::Initialize();
    }
    catch (const XMLException& toCatch) {
      // Do your failure processing here
    }
    // Instantiate the DOM parser.
    static const XMLCh gLS[] = { chLatin_L, chLatin_S, chNull };
    DOMImplementation *impl = DOMImplementationRegistry::getDOMImplementation(gLS);
    DOMBuilder        *parser = ((DOMImplementationLS*)impl)->createDOMBuilder(DOMImplementationLS::MODE_SYNCHRONOUS, 0);
    DOMDocument       *domDocument;

    parser->resetDocumentPool();
    domDocument = parser->parseURI(xmlFile);
    
    /* Now walk over all childnodes and create the tree */
    DOMElement *documentElement;
    DOMNode *child;
    SettingsParserXerces_impl_ptr settingsChild;
    SettingsParserXercesNode_impl_ptr topLevelNodeImpl;
    char *nameTag;
    char *settingsName;
    char *settingsType;
    
    topLevelNodeImpl = new SettingsParserXercesNode_impl(this, xmlFile, "scenario");
    documentElement = domDocument->getDocumentElement();
    fillSettingsNode(topLevelNodeImpl, documentElement);
    topLevelNode = topLevelNodeImpl;
    
    /* First walk over all children in order to create the corresponding settings nodes */
    child = documentElement->getFirstChild();
    while (child != NULL) {
        if (child->getNodeType() == DOMNode::ELEMENT_NODE) {
            DOMElement *childElement = (DOMElement *)child;
            if(childElement->hasAttributes()) {
                /* First get the mandatory attributes */
                DOMAttr *nameAttr = childElement->getAttributeNode(XMLString::transcode(nameName));
                if (nameAttr != NULL) {
                    settingsName = XMLString::transcode(nameAttr->getValue());
                } else {
                    settingsName = "(noname)";
                }
                DOMAttr *typeAttr = childElement->getAttributeNode(XMLString::transcode(nameType));
                if (typeAttr != NULL) {
                    settingsType = XMLString::transcode(typeAttr->getValue());
                } else {
                    settingsType = "(notype)";
                }
                SettingsParserXercesNode_impl_ptr newSetting =
                    new SettingsParserXercesNode_impl(this, settingsName, settingsType);
                children.push_back(newSetting);
                
                fillSettingsNode(newSetting, childElement);
                
            }            
        }
        child = child->getNextSibling();
    }
    
    /* finalize */
    parser->release();
    XMLPlatformUtils::Terminate();
}

SettingsParserXerces_impl::~SettingsParserXerces_impl() {
}


SettingsParserNode_ptr
SettingsParserXerces_impl::getToplevelNode() throw (SettingsParserException) {
    return topLevelNode;
}

#define PATHSTART "//@settings."
#define CHAR_IS_INT(a) \
    (((a) >= '0') && ((a) <= '9')) 
#define CHAR_TO_INT(a) \
    ((int)(a)-(int)('0'))

SettingsParserNodePtrVector
SettingsParserXerces_impl::getChildNodes(
    const char *path) {
    
    SettingsParserNodePtrVector result;
    
    /* Parse the path expression */
    char *currentPath = (char *)path;
    while (*currentPath != '\0') {
        while (*currentPath == ' ') {
            currentPath = &currentPath[1];
        }
        int index = 0;
        /* Skip the "//@settings." part */
        currentPath = &currentPath[sizeof(PATHSTART)-1];
        while (CHAR_IS_INT(*currentPath)) {
            index *= 10;
            index += CHAR_TO_INT(*currentPath);
            currentPath = &currentPath[1];
        }
        /* Index has been determined, now add the corresponding node to the result */
        result.push_back(children[index]);
    }
    
    return result;
}

}
