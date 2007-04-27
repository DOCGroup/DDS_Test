/* Interface */
#include "Source_impl.h"
/* Implementation */
#if defined (_WINDOWS)
# include <Windows.h>
#else
#include <time.h>
#endif

#if defined (_WINDOWS)
struct timespec
{
  time_t tv_sec;
  long tv_nsec;
};

void nanosleep (const struct timespec *ts,
                struct timespec * /* remaining */)
{
  ::Sleep (static_cast<DWORD> (ts->tv_sec * 1000 + ts->tv_nsec / 1000));
}
#endif

namespace Deep
{

Source_impl::Source_impl(
    SourceSetting_ptr sourceSetting,
    ReaderWriterFactory_ptr readerWriterFactory) : Actor_impl(sourceSetting) {
    
    nofBursts = sourceSetting->getNofBursts();
    burstSize = sourceSetting->getBurstSize();
    sleepTime = sourceSetting->getSleepTime();
    payload = sourceSetting->getPayload ();
    writer = readerWriterFactory->createWriter(sourceSetting->getTypeName(),
                                               sourceSetting->getTopicName(),
                                               sourceSetting->getWriterPartitionExpression(),
                                               sourceSetting->getTopicSetting(),
                                               sourceSetting->getWriterSetting());
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
        writer->initData(payload);
        for (iSample=0; iSample<burstSize; iSample++) {
            writer->writeData();
            writer->incrementData();
        }
        nanosleep(&timeSpec, NULL);
    }
}

}
