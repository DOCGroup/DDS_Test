#ifndef SINK_IMPL_H_
#define SINK_IMPL_H_

/* Base class */
#include "impl/Actor_impl.h"
/* Interface */
#include "ParticipantSetting.h"
#include "SinkSetting.h"
#include "ReaderWriterFactory.h"
/* Implementation */
#include "GenericReader.h"

namespace Deep {

class Laptimer_impl : public Actor_impl {
    unsigned int timeoutPeriod;
    bool doTiming;
    GenericReader_ptr reader;
public:
	Sink_impl(SinkSetting_ptr sinkSetting, ReaderWriterFactory_ptr readerWriterFactory);
	virtual ~Sink_impl();
    void run();
};

typedef Sink_impl *Sink_impl_ptr;

}

#endif /*SINK_IMPL_H_*/
