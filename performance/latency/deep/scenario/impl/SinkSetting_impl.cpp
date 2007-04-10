/* Interface */
#include "SinkSetting_impl.h"
/* Implementation */
#include "impl/ReaderSetting_impl.h"

namespace Deep {
    
static const unsigned int defaultTimeoutPeriod = 5000;
static const bool defaultDoTiming = false;
static char *defaultPartitionExpression = "DeepPartition";

SinkSetting_impl::SinkSetting_impl(
    const char *settingName,
    SettingsParserNode_ptr settingsParserNode) : ActorSetting_impl(settingName, settingsParserNode) {
        
    SettingsParserNodePtrVector readers;
    SettingsParserNode_ptr reader;
    
    settingsParserNode->getValue("timeoutPeriod", timeoutPeriod, defaultTimeoutPeriod);
    settingsParserNode->getValue("doTiming", doTiming, defaultDoTiming);
    settingsParserNode->getValue("readerPartitionExpression", readerPartitionExpression, defaultPartitionExpression);
    
    readers = settingsParserNode->getChildNodes("readerSettings");
    if (readers.size() > 0) {
        reader = readers[0];
        readerSetting = new ReaderSetting_impl(reader->getName(), reader);
    } else {
        readerSetting = NULL;
    }
}

SinkSetting_impl::~SinkSetting_impl()
{
}

unsigned int
SinkSetting_impl::getTimeoutPeriod() {
    return timeoutPeriod;
}

bool
SinkSetting_impl::getDoTiming() {
    return doTiming;
}

const char *
SinkSetting_impl::getReaderPartitionExpression() {
    return readerPartitionExpression;
}

ReaderSetting_ptr
SinkSetting_impl::getReaderSetting() {
    return readerSetting;
}

}
