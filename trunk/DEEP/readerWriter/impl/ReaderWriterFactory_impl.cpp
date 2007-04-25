#include <stdio.h>
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
    ReaderSetting_ptr readerSetting){

    DDS::Subscriber *subscriber;
    DDS::SubscriberQos subscriberQos;
    DDS::DataReader *reader;
    DDS::DataReaderQos readerQos;
    DDS::Topic *topic;
    DDS::TopicQos topicQos;
    GenericReader_ptr result = NULL;

    domainParticipant->get_default_subscriber_qos(subscriberQos);
    subscriberQos.partition.name.DEEP_length(1);
    subscriberQos.partition.name[0] = DEEP_strdup(partitionExpression);
    subscriber = domainParticipant->DEEP_create_subscriber(
        subscriberQos, NULL, DDS_STATUS_MASK_NONE);
    if (subscriber == NULL) {
	    printf("***Error (readerWriterFactory::createReader): failed to create subscriber\n");
	    return result;
    }
    
    /* Typespecific switch */
#define CONDITIONAL_GENERIC_READER_CONSTRUCTION(typeRequested) \
    if (strcmp(typeName, #typeRequested) == 0) { \
        DDS::ReturnCode_t retCode;\
        typeRequested##DataReader *dataReader; \
        DEEP_register_type(typeRequested, domainParticipant, typeName, retCode); \
        if (retCode != DDS::RETCODE_OK) { \
          printf ("***Error (readerWriterFactory::createReader): failed to register type \"%s\": error %d", typeName, retCode); \
          return result; \
        } \
        domainParticipant->get_default_topic_qos(topicQos); \
        if (topicSetting->getReliable()) { \
            topicQos.reliability.kind = DDS::RELIABLE_RELIABILITY_QOS; \
        } else { \
            topicQos.reliability.kind = DDS::BEST_EFFORT_RELIABILITY_QOS; \
        } \
        topic = DEEP_create_topic(domainParticipant, topicName, typeName, topicQos); \
        if (topic == NULL) { \
            printf("***Error (readerWriterFactory::createReader): failed to create topic \"%s\" with type \"%s\"\n", topicName, typeName); \
            return result; \
        } \
        subscriber->get_default_datareader_qos(readerQos); \
        subscriber->copy_from_topic_qos(readerQos, topicQos); \
        if (topicSetting->getReliable()) { \
            topicQos.reliability.kind = DDS::RELIABLE_RELIABILITY_QOS; \
        } else { \
            topicQos.reliability.kind = DDS::BEST_EFFORT_RELIABILITY_QOS; \
        } \
        readerQos.history.depth = readerSetting->getHistoryDepth(); \
        DEEP_vendor_specific_readerqos_init(readerQos); \
        reader = subscriber->DEEP_create_datareader(topic, readerQos, NULL, DDS::STATUS_MASK_NONE); \
        dataReader = typeRequested##DataReader::DEEP_narrow(reader); \
        result = new GenericReader_impl<typeRequested##DataReader>(dataReader); \
    }

    CONDITIONAL_GENERIC_READER_CONSTRUCTION(simpleType)
    CONDITIONAL_GENERIC_READER_CONSTRUCTION(nestedType)
    CONDITIONAL_GENERIC_READER_CONSTRUCTION(arrayType)
    CONDITIONAL_GENERIC_READER_CONSTRUCTION(stringType)
    CONDITIONAL_GENERIC_READER_CONSTRUCTION(sequenceType)
    
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

    DDS::Publisher *publisher;
    DDS::PublisherQos publisherQos;
    DDS::DataWriter *writer;
    DDS::DataWriterQos writerQos;
    DDS::Topic  *topic;
    DDS::TopicQos  topicQos;
    GenericWriter_ptr result = NULL;

    domainParticipant->get_default_publisher_qos(publisherQos);
    publisherQos.partition.name.DEEP_length(1);
    publisherQos.partition.name[0] = DEEP_strdup(partitionExpression);

    publisher = domainParticipant->DEEP_create_publisher(publisherQos,
        NULL, DDS::STATUS_MASK_NONE);

    if (publisher == NULL) {
	    printf("***Error(readerWriterFactory::createWriter): failed to create publisher\n");
	return result;
    }

    /* Typespecific switch */
#define CONDITIONAL_GENERIC_WRITER_CONSTRUCTION(typeRequested) \
    if (strcmp(typeName, #typeRequested) == 0) { \
        DDS::ReturnCode_t retCode; \
        typeRequested##DataWriter *dataWriter; \
        DEEP_register_type(typeRequested, domainParticipant, typeName, retCode); \
        if (retCode != DDS::RETCODE_OK) {\
            printf ("***Error (readerWriterFactory::createWriter): failed to register type \"%s\": error %d", typeName, retCode);\
            return result;\
        }\
        domainParticipant->get_default_topic_qos(topicQos); \
        if (topicSetting->getReliable()) { \
            topicQos.reliability.kind = DDS::RELIABLE_RELIABILITY_QOS; \
        } else { \
            topicQos.reliability.kind = DDS::BEST_EFFORT_RELIABILITY_QOS; \
        } \
        topic = DEEP_create_topic(domainParticipant, topicName, typeName, topicQos); \
        if (topic == NULL) { \
            printf("***Error (readerWriterFactory::createReader): failed to create topic \"%s\" with type \"%s\"\n", topicName, typeName); \
            return result; \
        } \
        publisher->get_default_datawriter_qos(writerQos); \
        publisher->copy_from_topic_qos(writerQos, topicQos); \
        writerQos.transport_priority.value = writerSetting->getImportance(); \
        writerQos.latency_budget.duration.sec = writerSetting->getUrgency()/1000; \
        writerQos.latency_budget.duration.nanosec = 1000000 * (writerSetting->getUrgency()%1000); \
        writer = publisher->DEEP_create_datawriter(topic, writerQos, NULL, DDS::STATUS_MASK_NONE); \
        dataWriter = typeRequested##DataWriter::DEEP_narrow(writer); \
        result = new GenericWriter_impl<typeRequested##DataWriter,typeRequested>(dataWriter); \
    }

    CONDITIONAL_GENERIC_WRITER_CONSTRUCTION(simpleType)
    CONDITIONAL_GENERIC_WRITER_CONSTRUCTION(nestedType)
    CONDITIONAL_GENERIC_WRITER_CONSTRUCTION(arrayType)
    CONDITIONAL_GENERIC_WRITER_CONSTRUCTION(stringType)
    CONDITIONAL_GENERIC_WRITER_CONSTRUCTION(sequenceType)

#undef CONDITIONAL_GENERIC_WRITER_CONSTRUCTION
    
    return result;
}

}
