/* Interface */
#include "Source_impl.h"
/* Implementation */
#include <time.h>

namespace Deep
{

Source_impl::Source_impl(
    SourceSetting_ptr sourceSetting,
    ReaderWriterFactory_ptr readerWriterFactory) : Actor_impl(sourceSetting) {
    
    nofBursts = sourceSetting->getNofBursts();
    burstSize = sourceSetting->getBurstSize();
    sleepTime = sourceSetting->getSleepTime();
    writer = readerWriterFactory->createWriter(sourceSetting->getTypeName(),
        sourceSetting->getTopicName(), sourceSetting->getWriterPartitionExpression());
}

Source_impl::~Source_impl()
{
}

void
Source_impl::run() {
    
    unsigned int iBurst;
    unsigned int iSample;
    struct timespec timeSpec;
    
    timeSpec.tv_sec = sleepTime/1000;
    timeSpec.tv_nsec = 1000000*(sleepTime % 1000);
    for (iBurst=0; iBurst<nofBursts; iBurst++) {
        writer->initData();
        for (iSample=0; iSample<burstSize; iSample++) {
            writer->writeData();
            writer->incrementData();
        }
        nanosleep(&timeSpec, NULL);
    }
}

}
