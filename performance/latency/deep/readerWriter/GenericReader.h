#ifndef GENERICREADER_H_
#define GENERICREADER_H_

#include "ReaderWriterTypes.h"
#include "GenericWriter.h"

namespace Deep {
    
class GenericReader {
public:
    virtual unsigned int takeData(unsigned int maxNofSamples) = 0;
    virtual unsigned int takeData(unsigned int maxNofSamples, duration *latencies) = 0;
    virtual unsigned int takeAndForwardData(GenericWriter_ptr forwardTo, unsigned int maxNofSamples) = 0;
    virtual unsigned int takeAndForwardData(GenericWriter_ptr forwardTo, unsigned int maxNofSamples, duration *latencies) = 0;
    virtual bool         waitForData(unsigned int timeOutMsecs) = 0;
};

typedef GenericReader *GenericReader_ptr;

}

#endif /*GENERICREADER_H_*/
