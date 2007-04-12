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
    const char *partitionExpression,
    TopicSetting_ptr topicSetting,
    ReaderSetting_ptr readerSetting) {

    DDS::SubscriberQos  subscriberQos;
    DDS::Subscriber_ptr subscriber;
    DDS::Topic_ptr topic;
    DDS::DataReader_ptr reader;
    GenericReader_ptr result = NULL;
    
    domainParticipant->get_default_subscriber_qos(subscriberQos);
    subscriberQos.partition.name.length (1);
    subscriberQos.partition.name[0] = strdup(partitionExpression);
    subscriber = domainParticipant->create_subscriber (subscriberQos, NULL);
    
    
    /* Typespecific switch */
#define CONDITIONAL_GENERIC_READER_CONSTRUCTION(typeRequested) \
    if (strcmp(typeName, #typeRequested) == 0) { \
        typeRequested##TypeSupport typeSupport; \
        typeRequested##DataReader_ptr dataReader; \
        DDS::TopicQos topicQos; \
        DDS::DataReaderQos dataReaderQos; \
        typeSupport.register_type(domainParticipant, typeName); \
        domainParticipant->get_default_topic_qos(topicQos); \
        if (topicSetting->getReliable()) \
            topicQos.reliability.kind = DDS::RELIABLE_RELIABILITY_QOS; \
        else \
            topicQos.reliability.kind = DDS::BEST_EFFORT_RELIABILITY_QOS; \
        topic = domainParticipant-> create_topic(topicName, typeName, topicQos, NULL); \
        subscriber->get_default_datareader_qos(dataReaderQos); \
        subscriber->copy_from_topic_qos(dataReaderQos, topicQos); \
        dataReaderQos.history.depth = readerSetting->getHistoryDepth(); \
        reader = subscriber->create_datareader(topic, dataReaderQos, NULL); \
        dataReader = typeRequested##DataReader::_narrow(reader); \
        result = new GenericReader_impl<typeRequested##DataReader_ptr>(dataReader); \
    }

    CONDITIONAL_GENERIC_READER_CONSTRUCTION(deepTypes::simpleType)
    CONDITIONAL_GENERIC_READER_CONSTRUCTION(deepTypes::nestedType)
    CONDITIONAL_GENERIC_READER_CONSTRUCTION(deepTypes::arrayType)
    CONDITIONAL_GENERIC_READER_CONSTRUCTION(deepTypes::stringType)
    CONDITIONAL_GENERIC_READER_CONSTRUCTION(deepTypes::sequenceType)

    
#undef CONDITIONAL_GENERIC_READER_CONSTRUCTION
    
    return result;
}
    
GenericWriter_ptr
ReaderWriterFactory_impl::createWriter(
    const char *typeName,
    const char *topicName,
    const char *partitionExpression,
    TopicSetting_ptr topicSetting,
    WriterSetting_ptr writerSetting) {

    DDS::PublisherQos  publisherQos;
    DDS::Publisher_ptr publisher;
    DDS::Topic_ptr topic;
    DDS::DataWriter_ptr writer;
    GenericWriter_ptr result = NULL;
    
    domainParticipant->get_default_publisher_qos(publisherQos);
    publisherQos.partition.name.length (1);
    publisherQos.partition.name[0] = strdup(partitionExpression);
    publisher = domainParticipant->create_publisher (publisherQos, NULL);
    
    /* Typespecific switch */
#define CONDITIONAL_GENERIC_WRITER_CONSTRUCTION(typeRequested) \
    if (strcmp(typeName, #typeRequested) == 0) { \
        typeRequested##TypeSupport typeSupport; \
        typeRequested##DataWriter_ptr dataWriter; \
        DDS::TopicQos topicQos; \
        DDS::DataWriterQos dataWriterQos; \
        typeSupport.register_type(domainParticipant, typeName); \
        domainParticipant->get_default_topic_qos(topicQos); \
        if (topicSetting->getReliable()) \
            topicQos.reliability.kind = DDS::RELIABLE_RELIABILITY_QOS; \
        else \
            topicQos.reliability.kind = DDS::BEST_EFFORT_RELIABILITY_QOS; \
        topic = domainParticipant-> create_topic(topicName, typeName, topicQos, NULL); \
        publisher->get_default_datawriter_qos(dataWriterQos); \
        publisher->copy_from_topic_qos(dataWriterQos, topicQos); \
        dataWriterQos.transport_priority.value = writerSetting->getImportance(); \
        dataWriterQos.latency_budget.duration.sec = writerSetting->getUrgency()/1000; \
        dataWriterQos.latency_budget.duration.nanosec = 1000000 * (writerSetting->getUrgency()%1000); \
        writer = publisher->create_datawriter(topic, dataWriterQos, NULL); \
        dataWriter = typeRequested##DataWriter::_narrow(writer); \
        result = new GenericWriter_impl<typeRequested##DataWriter_ptr,typeRequested>(dataWriter); \
    }

    CONDITIONAL_GENERIC_WRITER_CONSTRUCTION(deepTypes::simpleType)
    CONDITIONAL_GENERIC_WRITER_CONSTRUCTION(deepTypes::nestedType)
    CONDITIONAL_GENERIC_WRITER_CONSTRUCTION(deepTypes::arrayType)
    CONDITIONAL_GENERIC_WRITER_CONSTRUCTION(deepTypes::stringType)
    CONDITIONAL_GENERIC_WRITER_CONSTRUCTION(deepTypes::sequenceType)


#undef CONDITIONAL_GENERIC_WRITER_CONSTRUCTION
    
    return result;
    
}

}
