#ifndef SOURCE_IMPL_H_
#define SOURCE_IMPL_H_

/* Base class */
#include "impl/Actor_impl.h"
/* Interface */
#include "SourceSetting.h"
#include "ReaderWriterFactory.h"
/* Implementation */
#include "GenericWriter.h"

namespace Deep {

class Source_impl : public Actor_impl {
    unsigned int nofBursts;
    unsigned int burstSize;
    unsigned int sleepTime;
    unsigned int payload;
    GenericWriter_ptr writer;
public:
	Source_impl(SourceSetting_ptr sourceSetting, ReaderWriterFactory_ptr readerWriterFactory);
	virtual ~Source_impl();
    void run();
};

typedef Source_impl *Source_impl_ptr;
}

#endif /*SOURCE_IMPL_H_*/
