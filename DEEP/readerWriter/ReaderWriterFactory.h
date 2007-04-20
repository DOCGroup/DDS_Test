#ifndef READERWRITERFACTORY_H_
#define READERWRITERFACTORY_H_

#include "GenericReader.h"
#include "GenericWriter.h"

#include "ReaderSetting.h"
#include "WriterSetting.h"
#include "TopicSetting.h"


namespace Deep {

class ReaderWriterFactory {
public:
    virtual GenericReader_ptr createReader(const char *typeName, const char *topicName, const char *partitionExpression,
                                   TopicSetting_ptr topicSetting, ReaderSetting_ptr readerSetting) = 0;
    virtual GenericWriter_ptr createWriter(const char *typeName, const char *topicName, const char *partitionExpression,
                                   TopicSetting_ptr topicSetting, WriterSetting_ptr writerSetting) = 0;
};

typedef ReaderWriterFactory *ReaderWriterFactory_ptr;

}

#endif /*READERWRITERFACTORY_H_*/
