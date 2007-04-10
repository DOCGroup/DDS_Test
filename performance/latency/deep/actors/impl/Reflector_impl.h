#ifndef REFLECTOR_IMPL_H_
#define REFLECTOR_IMPL_H_

/* Base class */
#include "impl/Actor_impl.h"
/* Interface */
#include "ReflectorSetting.h"
#include "ReaderWriterFactory.h" 

namespace Deep {

class Reflector_impl : public Actor_impl {
    unsigned int timeoutPeriod;
    bool doTiming;
    GenericReader_ptr reader;
    GenericWriter_ptr writer;
public:
	Reflector_impl(ReflectorSetting_ptr reflectorSetting, ReaderWriterFactory_ptr readerWriterFactory);
	virtual ~Reflector_impl();
    void run();
};

typedef Reflector_impl *Reflector_impl_ptr;
}

#endif /*REFLECTOR_IMPL_H_*/
