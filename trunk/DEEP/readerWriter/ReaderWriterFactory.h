#ifndef READERWRITERFACTORY_H_
#define READERWRITERFACTORY_H_

#include "GenericReader.h"
#include "GenericWriter.h"
/*
#include "ReaderSetting.h"
#include "WriterSetting.h"
#include "TopicSetting.h"
*/

namespace Deep {

class ReaderWriterFactory {
public:
    virtual GenericReader_ptr createReader(const char *typeName, const char *topicName, const char *partitionExpression /*,
                                   ReaderSetting_ptr readerSetting, TopicSetting_ptr topicSetting */) = 0;
    virtual GenericWriter_ptr createWriter(const char *typeName, const char *topicName, const char *partitionExpression /*,
                                   WriterSetting_ptr writerSetting, TopicSetting_ptr topicSetting */) = 0;
};

typedef ReaderWriterFactory *ReaderWriterFactory_ptr;

}

#endif /*READERWRITERFACTORY_H_*/
