#ifndef READERWRITERFACTORY_IMPL_H_
#define READERWRITERFACTORY_IMPL_H_

/* Base class */
#include "ReaderWriterFactory.h"
/* Friend class that acts as factory */
/* #include "impl/Actor_impl.h" */
/* Implementation */
#include "ParticipantSetting.h"
#include "inclAbstraction.h"

namespace Deep {

class ReaderWriterFactory_impl : public ReaderWriterFactory {
    
    /* Members */
    DDS::DomainParticipant_ptr domainParticipant;
public:
    /* Constructor to be used by factory only */
	ReaderWriterFactory_impl(ParticipantSetting_ptr participantSetting);
	virtual ~ReaderWriterFactory_impl();
    /* friend Actor_impl; */

    GenericReader_ptr createReader(const char *typeName, const char *topicName, const char *partitionExpression /*,
                                   ReaderSetting_ptr readerSetting, TopicSetting_ptr topicSetting */);
    GenericWriter_ptr createWriter(const char *typeName, const char *topicName, const char *partitionExpression /*,
                                   WriterSetting_ptr writerSetting, TopicSetting_ptr topicSetting */);
};

}

#endif /*READERWRITERFACTORY_IMPL_H_*/
