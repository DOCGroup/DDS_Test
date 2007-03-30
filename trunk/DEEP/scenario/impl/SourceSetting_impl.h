#ifndef SOURCESETTING_IMPL_H_
#define SOURCESETTING_IMPL_H_

/* Base-class (interface) */
#include "SourceSetting.h"
/* Base-class (implementation) */
#include "impl/ActorSetting_impl.h"
/* Friend class (factory) */
#include "impl/ParticipantSetting_impl.h"
/* Implementation */

namespace Deep {

class SourceSetting_impl : public virtual SourceSetting, public ActorSetting_impl {
    /* Private members */
    unsigned int burstSize;
    unsigned int sleepTime;
    unsigned int nofBursts;
    char *writerPartitionExpression;
    WriterSetting_ptr writerSetting;
    /* Constructor/destructor */
    SourceSetting_impl(const char *settingName, SettingsParserNode_ptr settingsParserNode);
	virtual ~SourceSetting_impl();
    friend class ParticipantSetting_impl;
public:
    unsigned int getBurstSize();
    unsigned int getSleepTime();
    unsigned int getNofBursts();
    
    const char *getWriterPartitionExpression();
    WriterSetting_ptr getWriterSetting();

};

}

#endif /*SOURCESETTING_IMPL_H_*/
