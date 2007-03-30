/* Interface */
#include "SourceSetting_impl.h"
/* Implementation */
#include "SettingsParserNode.h"
#include "impl/WriterSetting_impl.h"

namespace Deep
{

static const unsigned int defaultBurstSize = 10;
static const unsigned int defaultSleepTime = 200;
static const unsigned int defaultNofBursts = 50;
static char *defaultPartitionExpression = "DeepPartition";

SourceSetting_impl::SourceSetting_impl(
    const char *settingName,
    SettingsParserNode_ptr settingsParserNode) : ActorSetting_impl(settingName, settingsParserNode) {
    
    SettingsParserNodePtrVector writers;
    SettingsParserNode_ptr writer;
        
    settingsParserNode->getValue("burstSize", burstSize, defaultBurstSize);
    settingsParserNode->getValue("sleepTime", sleepTime, defaultSleepTime);
    settingsParserNode->getValue("nofBursts", nofBursts, defaultNofBursts);
    settingsParserNode->getValue("writerPartitionExpression", writerPartitionExpression, defaultPartitionExpression);
    
    writers = settingsParserNode->getChildNodes("writerSetting");
    if (writers.size() > 0) {
        /* Just pick the first one */
        writer = writers[0];
        writerSetting = new WriterSetting_impl(writer->getName(), writer);
    } else {
        writerSetting = NULL;
    }
}

SourceSetting_impl::~SourceSetting_impl()
{
}

unsigned int
SourceSetting_impl::getBurstSize() {
    return burstSize;
}

unsigned int
SourceSetting_impl::getSleepTime() {
    return sleepTime;
}

unsigned int
SourceSetting_impl::getNofBursts() {
    return nofBursts;
}
    
const char *
SourceSetting_impl::getWriterPartitionExpression() {
    return writerPartitionExpression;
}

WriterSetting_ptr
SourceSetting_impl::getWriterSetting() {
    return writerSetting;
}

}
