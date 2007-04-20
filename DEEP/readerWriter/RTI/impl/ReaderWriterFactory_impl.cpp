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
  // domainParticipant = DEEP_create_participant(participantSetting->getDomainName());
  domainParticipant = DEEP_create_participant(89);
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

    DDS::SubscriberQos  sQos;
    DDS::DataReaderQos rQos;
    DDS::Subscriber *s;
    DDS::Topic *topic;
    DDS::DataReader *reader;
    GenericReader_ptr result = NULL;

    
    domainParticipant->get_default_subscriber_qos(sQos);
    sQos.partition.name.ensure_length (1, 1);
    sQos.partition.name[0] = DDS_String_dup (partitionExpression);


    
    
    s = domainParticipant->create_subscriber (sQos,
                                              NULL,
                                              DDS_STATUS_MASK_NONE);

    if (s == NULL) {
	printf("***Error: failed to create subscriber\n");
	return result;
    }

    
    /* Typespecific switch */
#define CONDITIONAL_GENERIC_READER_CONSTRUCTION(typeRequested) \
    if (strcmp(typeName, #typeRequested) == 0) { \
        DDS::ReturnCode_t ret_code;\
        ret_code = typeRequested##TypeSupport::register_type(domainParticipant, typeName); \
        if (ret_code != DDS::RETCODE_OK) {\
          printf ("***Error: failed to register type: error %d", ret_code);\
          return result;\
        }\
        /* @@Note: We need to first see if an existing topic is already there \
                   if so, grab that topic, if not, we then create a new topic \
                   failing to do so might result calling creat_topic with the \
                   same name and same type twice on the same domainparticipant\
                   and the second call will fail, thus affecting the subsequent\
                   creation of writer or reader\
        */\
        DDS::Duration_t timeout = {0,0};\
        topic = domainParticipant->find_topic (topicName, timeout);       \
        if (topic == NULL)\
          {\
            topic = domainParticipant->create_topic(topicName,\
                                                    typeName, \
                                                    DDS::TOPIC_QOS_DEFAULT, \
                                                    NULL, \
                                                    DDS::STATUS_MASK_NONE); \
            if (topic == NULL) {                                        \
              printf("***Error: failed to create reader topic %s with type %s\n", topicName, typeName); \
              return result;                                            \
            }                                                           \
            else                                                        \
              printf("ReaderWriterFactory: Created reader topic %s with type %s\n", topicName, typeName); \
          }\
        else\
          printf ("ReaderWriterFactory: Found reader topic %s\n", topicName);\
        s->get_default_datareader_qos(rQos);\
        /* we assume that this reader is going to receive on multicast */\
        rQos.multicast.value.ensure_length(1,1);\
        rQos.multicast.value[0].receive_address = DDS_String_dup("225.3.2.1");\
        /* TODO: Copy from topicQos and override from readerSetting in stead of default */ \
        reader = s->create_datareader(topic,\
                                      rQos,\
                                      NULL, \
                                      DDS::STATUS_MASK_NONE);    \
        if (reader == NULL) {\
          printf("***Error: failed to create reader\n");\
          return result;\
        }\
        typeRequested##DataReader *dataReader; \
        dataReader = typeRequested##DataReader::narrow(reader); \
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

    DDS::PublisherQos  pQos;
    DDS::DataWriterQos wQos;
    DDS::Publisher *p;
    DDS::Topic  *topic;
    DDS::DataWriter *writer;
    GenericWriter_ptr result = NULL;


    domainParticipant->get_default_publisher_qos(pQos);
    pQos.partition.name.ensure_length (1, 1);
    pQos.partition.name[0] = DDS_String_dup (partitionExpression);

    p = domainParticipant->create_publisher (pQos,
                                             NULL,
                                             DDS::STATUS_MASK_NONE);

    if (p == NULL) {
	printf("***Error: failed to create publisher\n");
	return result;
    }

    
    /* Typespecific switch */
#define CONDITIONAL_GENERIC_WRITER_CONSTRUCTION(typeRequested) \
    if (strcmp(typeName, #typeRequested) == 0) { \
        DDS::ReturnCode_t ret_code;\
        ret_code = typeRequested##TypeSupport::register_type(domainParticipant, typeName); \
        if (ret_code != DDS::RETCODE_OK) {\
          printf ("***Error: failed to register type: error %d", ret_code);\
          return result;\
        }\
        /* @@Note: We need to first see if an existing topic is already there \
                   if so, grab that topic, if not, we then create a new topic \
                   failing to do so might result calling creat_topic with the \
                   same name and same type twice on the same domainparticipant\
                   and the second call will fail, thus affecting the subsequent\
                   creation of writer or reader\
        */\
        DDS::Duration_t timeout = {0,0};\
        topic = domainParticipant->find_topic (topicName, timeout);       \
        if (topic == NULL)\
          {\
            topic = domainParticipant->create_topic(topicName, typeName, DDS::TOPIC_QOS_DEFAULT, NULL, DDS::STATUS_MASK_NONE); \
            if (topic == NULL) {                                        \
              printf("***Error: failed to create writer topic %s with type %s\n", topicName, typeName); \
              return result;                                            \
            }                                                           \
            else                                                        \
              printf("ReaderWriterFactory: Created writer topic %s with type %s\n", topicName, typeName); \
          }\
        else\
          printf ("ReaderWriterFactory: Found writer topic %s\n", topicName);\
        /* TODO: Copy from topicQos and override from writerSetting in stead of default */ \
        p->get_default_datawriter_qos(wQos);\
	/* wQos.reliability.kind = DDS::BEST_EFFORT_RELIABILITY_QOS;*/   \
        writer = p->create_datawriter(topic,DDS::DATAWRITER_QOS_DEFAULT, NULL, DDS::STATUS_MASK_NONE); \
        if (writer == NULL) {\
          printf("***Error: failed to create writer\n");\
          return result;\
        }\
        typeRequested##DataWriter *dataWriter; \
        dataWriter = typeRequested##DataWriter::narrow(writer); \
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
