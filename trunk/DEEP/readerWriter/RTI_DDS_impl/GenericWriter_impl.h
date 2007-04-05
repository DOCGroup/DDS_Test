#ifndef GENERICWRITER_IMPL_H_
#define GENERICWRITER_IMPL_H_

/* Base class */
#include "GenericWriter.h"
/* Friend */
#include "ReaderWriterFactory_impl.h"
/* Implementation */
#include "TypedFunctions.h"

namespace Deep {
    
class GenericWriterBase_impl : public GenericWriter {
public:
    virtual DDS::DataWriter_ptr getWriter() = 0;
};

typedef GenericWriterBase_impl *GenericWriterBase_impl_ptr;

template <class TypedWriter_ptr, class IdlDataType> class GenericWriter_impl : public GenericWriterBase_impl {

    /* Members */
    TypedWriter_ptr dataWriter;
    IdlDataType currentData;

    /* Constructor/destructor (used by factory only) */
	GenericWriter_impl(TypedWriter_ptr _dataWriter) {dataWriter = _dataWriter;}
	virtual ~GenericWriter_impl() {}
    friend class Deep::ReaderWriterFactory_impl;

public:
    
    /* Public Methods from GenericWriter */
    
    void initData() {typedFunctionsInitData(currentData);}
    void writeData() {typedFunctionsWriteData(dataWriter, currentData);}
    void incrementData() {typedFunctionsIncrementData(currentData);}
    
    /* Own public method */
    DDS::DataWriter_ptr getWriter() {return dataWriter;}
};

}

#endif /*GENERICWRITER_IMPL_H_*/
