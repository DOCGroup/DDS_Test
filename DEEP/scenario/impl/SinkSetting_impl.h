#ifndef SINKSETTING_IMPL_H_
#define SINKSETTING_IMPL_H_

/* Base-class (interface) */
#include "SinkSetting.h"
/* Base-class (implementation) */
#include "impl/ActorSetting_impl.h"
/* Friend (factory) */
#include "impl/ParticipantSetting_impl.h"
/* Implementation */

namespace Deep {

class SinkSetting_impl : public virtual SinkSetting, public ActorSetting_impl {
    unsigned int timeoutPeriod;
    bool doTiming;
    char *readerPartitionExpression;
    ReaderSetting_ptr readerSetting;
    /* ctor/dtor */
    SinkSetting_impl(const char *settingName, SettingsParserNode_ptr settingsParserNode);
	virtual ~SinkSetting_impl();
    friend class ParticipantSetting_impl;
public:
    unsigned int       getTimeoutPeriod();
    bool               getDoTiming();
    const char        *getReaderPartitionExpression();
    ReaderSetting_ptr  getReaderSetting();

};

typedef SinkSetting_impl *SinkSetting_impl_ptr;

}

#endif /*SINKSETTING_IMPL_H_*/
