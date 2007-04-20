#ifndef REFLECTORSETTING_IMPL_H_
#define REFLECTORSETTING_IMPL_H_

/* Base class (interface) */
#include "ReflectorSetting.h"
/* Base class (implementation) */
#include "impl/ActorSetting_impl.h"
/* Friend (factory) */
#include "impl/ParticipantSetting_impl.h"

namespace Deep {

class ReflectorSetting_impl : public virtual ReflectorSetting, public ActorSetting_impl {
    unsigned int timeoutPeriod;
    bool doTiming;
    char *readerPartitionExpression;
    char *writerPartitionExpression;
    ReaderSetting_ptr readerSetting;
    WriterSetting_ptr writerSetting;
    /* ctor/dtor */
	ReflectorSetting_impl(const char *settingName, SettingsParserNode_ptr settingsParserNode);
	virtual ~ReflectorSetting_impl();
    friend class ParticipantSetting_impl;
public:
    const char        *getReaderPartitionExpression();
    const char        *getWriterPartitionExpression();
    ReaderSetting_ptr  getReaderSetting();
    WriterSetting_ptr  getWriterSetting();
    unsigned int       getTimeoutPeriod();
    bool               getDoTiming();

};

}

#endif /*REFLECTORSETTING_IMPL_H_*/
