#ifndef GENERICREADER_IMPL_H_
#define GENERICREADER_IMPL_H_

/* Base class */
#include "GenericReader.h"
/* Friend */
#include "ReaderWriterFactory_impl.h"
/* Implementation */
#include "TypedFunctions.h"
#include "GenericWriter_impl.h"

namespace Deep {

template <class TypedReader> class GenericReader_impl : public GenericReader {

    /* Members */
    TypedReader *dataReader;

    DDS::WaitSet waitSet;

    /* Constructor/destructor (used by factory only) */
    GenericReader_impl(TypedReader *_dataReader) {
      DDS::StatusCondition *condition;
      dataReader = _dataReader;
      condition = dataReader->get_statuscondition ();
      condition->set_enabled_statuses(DDS::DATA_AVAILABLE_STATUS);
      waitSet.attach_condition(condition);
    }
    virtual ~GenericReader_impl() {}
    friend class ReaderWriterFactory_impl;

public:
    
    /* Public Methods from GenericReader */
    unsigned int takeData(unsigned int maxNofSamples) {
        typedFunctionsTakeData(dataReader, maxNofSamples);
    }
    
    unsigned int takeData(unsigned int maxNofSamples, duration *latencies) {
        typedFunctionsTakeData(dataReader, maxNofSamples, (DDS::Time_t *)latencies);
    }
    
    unsigned int takeAndForwardData(GenericWriter_ptr forwardTo, unsigned int maxNofSamples) {
        GenericWriterBase_impl_ptr writer_impl;        
        writer_impl = dynamic_cast<GenericWriterBase_impl_ptr>(forwardTo);
        typedFunctionsTakeAndForwardData(dataReader, writer_impl->getWriter(), maxNofSamples);
    }
    
    unsigned int takeAndForwardData(GenericWriter_ptr forwardTo, unsigned int maxNofSamples, duration *latencies) {
        GenericWriterBase_impl_ptr writer_impl;        
        writer_impl = dynamic_cast<GenericWriterBase_impl_ptr>(forwardTo);
        typedFunctionsTakeAndForwardData(dataReader, writer_impl->getWriter(), maxNofSamples, (DDS::Time_t *)latencies);
    }
    
    bool waitForData(unsigned int timeOutMsecs) {
        bool result;
        DDS::ConditionSeq  conditions;
        DDS::Duration_t timeOut;
        timeOut.sec = timeOutMsecs/1000;
        timeOut.nanosec = 1000000*(timeOutMsecs % 1000);
        waitSet.wait(conditions, timeOut);
        result = (conditions.length() > 0);
        return result;
    }

};


}

#endif /*GENERICREADER_IMPL_H_*/
