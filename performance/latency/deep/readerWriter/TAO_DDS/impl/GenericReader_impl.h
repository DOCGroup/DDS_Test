#ifndef GENERICREADER_IMPL_H_
#define GENERICREADER_IMPL_H_

/* Base class */
#include "GenericReader.h"
/* Friend */
#include "impl/ReaderWriterFactory_impl.h"
/* Implementation */
#include "TypedFunctions.h"
#include "impl/GenericWriter_impl.h"

namespace Deep {

template <class TypedReader_ptr> class GenericReader_impl : public GenericReader {

    /* Members */
    TypedReader_ptr dataReader;
//    DDS::WaitSet_ptr waitSet;

    /* Constructor/destructor (used by factory only) */
    GenericReader_impl(TypedReader_ptr _dataReader) {
//        DDS::StatusCondition_ptr dataAvailableCondition;
        dataReader = _dataReader;
//        dataAvailableCondition = dataReader->get_statuscondition();
//        dataAvailableCondition->set_enabled_statuses(DDS::DATA_AVAILABLE_STATUS);
//        waitSet = new DDS::WaitSet();
//        waitSet->attach_condition(dataAvailableCondition);
    }
    virtual ~GenericReader_impl() {}
    friend class ReaderWriterFactory_impl;

public:
    
    /* Public Methods from GenericReader */
    unsigned int takeData(unsigned int maxNofSamples) {
        return typedFunctionsTakeData(dataReader, maxNofSamples);
    }
    
    unsigned int takeData(unsigned int maxNofSamples, duration *latencies) {
        return typedFunctionsTakeData(dataReader, maxNofSamples, (DDS::Time_t *)latencies);
    }
    
    unsigned int takeAndForwardData(GenericWriter_ptr forwardTo, unsigned int maxNofSamples) {
        GenericWriterBase_impl_ptr writer_impl;        
        writer_impl = dynamic_cast<GenericWriterBase_impl_ptr>(forwardTo);
        return typedFunctionsTakeAndForwardData(dataReader, writer_impl->getWriter(), maxNofSamples);
    }
    
    unsigned int takeAndForwardData(GenericWriter_ptr forwardTo, unsigned int maxNofSamples, duration *latencies) {
        GenericWriterBase_impl_ptr writer_impl;        
        writer_impl = dynamic_cast<GenericWriterBase_impl_ptr>(forwardTo);
        return typedFunctionsTakeAndForwardData(dataReader, writer_impl->getWriter(), maxNofSamples, (DDS::Time_t *)latencies);
    }
    
    bool waitForData(unsigned int timeOutMsecs) {
        bool result = false;
//        DDS::ConditionSeq_var conditions;
        DDS::Duration_t timeOut;
        timeOut.sec = timeOutMsecs/1000;
        timeOut.nanosec = 1000*(timeOutMsecs % 1000);
//        waitSet->wait(conditions, timeOut);
//        result = (conditions->length() > 0);
        return result;
    }

};


}

#endif /*GENERICREADER_IMPL_H_*/
