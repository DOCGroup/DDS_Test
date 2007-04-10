/* Interface */
#include "ReflectorSetting_impl.h"
/* Implementation */
#include "SettingsParserNode.h"
#include "impl/ReaderSetting_impl.h"
#include "impl/WriterSetting_impl.h"

namespace Deep
{

static char *defaultPartitionExpression = "DeepPartition";
static const bool defaultDoTiming = false;
static const unsigned int defaultTimeoutPeriod = 5000;

ReflectorSetting_impl::ReflectorSetting_impl(
    const char *settingName,
    SettingsParserNode_ptr settingsParserNode) : ActorSetting_impl(settingName, settingsParserNode) {
        
    SettingsParserNodePtrVector children;
    SettingsParserNode_ptr child;
    
    settingsParserNode->getValue("readerPartitionExpression", readerPartitionExpression, defaultPartitionExpression);
    settingsParserNode->getValue("writerPartitionExpression", writerPartitionExpression, defaultPartitionExpression);
    settingsParserNode->getValue("doTiming", doTiming, defaultDoTiming);
    settingsParserNode->getValue("timeoutPeriod", timeoutPeriod, defaultTimeoutPeriod);
        
    children = settingsParserNode->getChildNodes("readerSettings");
    if (children.size() > 0) {
        child = children[0];
        readerSetting = new ReaderSetting_impl(child->getName(), child);
    } else {
        readerSetting = NULL;
    }
    
    children = settingsParserNode->getChildNodes("writerSettings");
    if (children.size() > 0) {
        child = children[0];
        writerSetting = new WriterSetting_impl(child->getName(), child);
    } else {
        writerSetting = NULL;
    }
    
}

ReflectorSetting_impl::~ReflectorSetting_impl() {
}

const char *
ReflectorSetting_impl::getReaderPartitionExpression() {
    return readerPartitionExpression;
}

const char *
ReflectorSetting_impl::getWriterPartitionExpression() {
    return writerPartitionExpression;
}

ReaderSetting_ptr
ReflectorSetting_impl::getReaderSetting() {
    return readerSetting;
}

WriterSetting_ptr
ReflectorSetting_impl::getWriterSetting() {
    return writerSetting;
}

unsigned int
ReflectorSetting_impl::getTimeoutPeriod() {
    return timeoutPeriod;
}

bool
ReflectorSetting_impl::getDoTiming() {
    return doTiming;
}

}
