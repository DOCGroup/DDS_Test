#ifndef INCLABSTRACTION_H_
#define INCLABSTRACTION_H_

#include "ndds/ndds_cpp.h"
/*include this file if you want to use DDS namespace */
#include "ndds/ndds_namespace_cpp.h"
#include "deepTypes.h"
#include "deepTypesSupport.h"

#define DEEP_INSTANCE_HANDLE_NIL DDS::HANDLE_NIL

/* The type used for the [] operator on sequences seems to be vendor specific */
typedef int DEEP_sequenceIndexType;

/* Setting the length of a sequence */
#define DEEP_length(seqLen) ensure_length(seqLen, seqLen)

/* The narrow operator has a different name for different vendors */
#define DEEP_narrow(entity) narrow(entity)
 
/* Different implementations use different strdups */
inline char *DEEP_strdup(const char *source) {
	return DDS_String_dup(source);
}

#define DEEP_register_type(typeSupportTypeName, domainParticipant, typeName, result) \
    result = typeSupportTypeName##TypeSupport::register_type(domainParticipant, typeName)


/* Macro's for solving OMG spec versioning issues */
#define DEEP_create_publisher(participant, listener, mask) create_publisher(participant, listener, mask)
#define DEEP_create_datawriter(topic, writerQos, listener, mask) create_datawriter(topic, writerQos, listener, mask)
#define DEEP_create_subscriber(participant, listener, mask) create_subscriber(participant, listener, mask)
#define DEEP_create_datareader(topic, readerQos, listener, mask) create_datareader(topic, readerQos, listener, mask)

/* @@Note: We need to first see if an existing topic is already there
           if so, grab that topic, if not, we then create a new topic
           failing to do so might result calling creat_topic with the
           same name and same type twice on the same domainparticipant
           and the second call will fail, thus affecting the subsequent
           creation of writer or reader
*/
inline DDS::Topic *
DEEP_create_topic(
    DDS::DomainParticipant *domainParticipant,
    const char *topicName,
    const char *typeName,
    DDS::TopicQos topicQos)
{
	DDS::Topic *result;
    DDS::Duration_t timeout = {0,0};
    result = domainParticipant->find_topic (topicName, timeout);
    if (result == NULL) {
        result = domainParticipant->create_topic(topicName,
            typeName, topicQos, NULL, DDS::STATUS_MASK_NONE);
    } 
    return result;
}

inline void DEEP_vendor_specific_readerqos_init(DDS::DataReaderQos readerQos) {
    /* we assume that this reader is going to receive on multicast */\
    readerQos.multicast.value.DEEP_length(1);\
    readerQos.multicast.value[0].receive_address = DDS::strdup("225.3.2.1");\
}

namespace DDS
{
  typedef DomainParticipantFactory *DomainParticipantFactory_ptr;
  typedef DomainParticipant *DomainParticipant_ptr;
  typedef DataWriter *DataWriter_ptr;
  typedef DataReader *DataReader_ptr;
  typedef WaitSet *WaitSet_ptr;
  typedef Topic *Topic_ptr;
  typedef StatusCondition *StatusCondition_ptr;
}

/* This function waits on a waitset with timeOut as timeout.
 * The result is true if the waitset has triggered, false orhterwise */
inline bool
DEEP_waitSetWait(
    DDS::WaitSet &waitSet, /* by reference, no copy constructor available */
    DDS::Duration_t timeOut)
{
    DDS::ConditionSeq conditions;
    bool result;
    waitSet.wait(conditions, timeOut);
    result = (conditions.length() > 0);
    return result;
}

inline DDSDomainParticipant *DEEP_create_participant(const char *domainId) {
    DDSDomainParticipantFactory *factory = DDSDomainParticipantFactory::get_instance();
    return factory->create_participant (atoi(domainId),
                                        DDS_PARTICIPANT_QOS_DEFAULT,
                                        NULL,
                                        DDS_STATUS_MASK_NONE);
}



#endif /*INCLABSTRACTION_H_*/
