/* Interface */
#include "ReaderWriterFactory_impl.h"
/* Implementation */
#include "inclAbstraction.h"
/* #include "ParticipantSetting.h" */
#include "GenericReader_impl.h"
#include "GenericWriter_impl.h"
#include "string.h"

namespace Deep {

ReaderWriterFactory_impl::ReaderWriterFactory_impl(ParticipantSetting_ptr participantSetting) {
    domainParticipant = DEEP_create_participant(participantSetting->getDomainName());
}

ReaderWriterFactory_impl::~ReaderWriterFactory_impl() {
}

GenericReader_ptr
ReaderWriterFactory_impl::createReader(
    const char *typeName,
    const char *topicName,
    const char *partitionExpression/* ,
    ReaderSetting_ptr readerSetting,
    TopicSetting_ptr topicSetting*/) {

    DDS::SubscriberQos  sQos;
    DDS::Subscriber_ptr s;
    DDS::Topic_ptr topic;
    DDS::DataReader_ptr reader;
    GenericReader_ptr result = NULL;

    domainParticipant->get_default_subscriber_qos(sQos);
    sQos.partition.name.length (1);
    sQos.partition.name[0] = strdup(partitionExpression);
    s = domainParticipant->create_subscriber (sQos, NULL);
    
    
    /* Typespecific switch */
#define CONDITIONAL_GENERIC_READER_CONSTRUCTION(typeRequested) \
    if (strcmp(typeName, #typeRequested) == 0) { \
        typeRequested##TypeSupport typeSupport; \
        typeRequested##DataReader_ptr dataReader; \
        typeSupport.register_type(domainParticipant, typeName); \
        /* TODO: Use TopicQos derived from topicSetting in stead of default */ \
        topic = domainParticipant-> create_topic(topicName, typeName, TOPIC_QOS_DEFAULT, NULL); \
        /* TODO: Copy from topicQos and override from readerSetting in stead of default */ \
        reader = s->create_datareader(topic, DATAREADER_QOS_DEFAULT, NULL); \
        dataReader = typeRequested##DataReader::_narrow(reader); \
        result = new GenericReader_impl<typeRequested##DataReader_ptr>(dataReader); \
    }

    CONDITIONAL_GENERIC_READER_CONSTRUCTION(deepTypes::simpleType)
    CONDITIONAL_GENERIC_READER_CONSTRUCTION(deepTypes::nestedType)
    CONDITIONAL_GENERIC_READER_CONSTRUCTION(deepTypes::arrayType)
    CONDITIONAL_GENERIC_READER_CONSTRUCTION(deepTypes::stringType)
    
#undef CONDITIONAL_GENERIC_READER_CONSTRUCTION
    
    return result;
}
    
GenericWriter_ptr
ReaderWriterFactory_impl::createWriter(
    const char *typeName,
    const char *topicName,
    const char *partitionExpression/*,
    WriterSetting_ptr writerSetting,
    TopicSetting_ptr topicSetting*/) {

    DDS::PublisherQos  pQos;
    DDS::Publisher_ptr p;
    DDS::Topic_ptr topic;
    DDS::DataWriter_ptr writer;
    GenericWriter_ptr result = NULL;
    
    domainParticipant->get_default_publisher_qos(pQos);
    pQos.partition.name.length (1);
    pQos.partition.name[0] = strdup(partitionExpression);
    p = domainParticipant->create_publisher (pQos, NULL);
    
    /* Typespecific switch */
#define CONDITIONAL_GENERIC_WRITER_CONSTRUCTION(typeRequested) \
    if (strcmp(typeName, #typeRequested) == 0) { \
        typeRequested##TypeSupport typeSupport; \
        typeRequested##DataWriter_ptr dataWriter; \
        typeSupport.register_type(domainParticipant, typeName); \
        /* TODO: Use TopicQos derived from topicSetting in stead of default */ \
        topic = domainParticipant-> create_topic(topicName, typeName, TOPIC_QOS_DEFAULT, NULL); \
        /* TODO: Copy from topicQos and override from writerSetting in stead of default */ \
        writer = p->create_datawriter(topic, DATAWRITER_QOS_DEFAULT, NULL); \
        dataWriter = typeRequested##DataWriter::_narrow(writer); \
        result = new GenericWriter_impl<typeRequested##DataWriter_ptr,typeRequested>(dataWriter); \
    }

    CONDITIONAL_GENERIC_WRITER_CONSTRUCTION(deepTypes::simpleType)
    CONDITIONAL_GENERIC_WRITER_CONSTRUCTION(deepTypes::nestedType)
    CONDITIONAL_GENERIC_WRITER_CONSTRUCTION(deepTypes::arrayType)
    CONDITIONAL_GENERIC_WRITER_CONSTRUCTION(deepTypes::stringType)

#undef CONDITIONAL_GENERIC_WRITER_CONSTRUCTION
    
    return result;
    
}

}