#ifndef INCLABSTRACTION_H_
#define INCLABSTRACTION_H_

/* Abstraction with respect to the names of the include files.
 * This is vendor dependent */

#include "ccpp_deepTypes.h"
#include "ccpp_dds_dcps.h"

#define DEEP_INSTANCE_HANDLE_NIL DDS::HANDLE_NIL

/* The type used for the [] operator on sequences seems to be vendor specific */
typedef CORBA::ULong DEEP_sequenceIndexType;

/* Setting the length of a sequence */
#define DEEP_length(seqLen) length(seqLen) 

/* The narrow operator has a different name for different vendors */
#define DEEP_narrow(entity) _narrow(entity)

/* Different implementations use different strdups */
inline char *DEEP_strdup(const char *source) {
	return strdup(source);
}

#define DEEP_register_type(typeSupportTypeName, domainParticipant, typeName, result) \
    do { \
    	typeSupportTypeName##TypeSupport typeSupport; \
    	result = typeSupport.register_type(domainParticipant, typeName); \
    } while (0)

/* Macro's for solving OMG spec versioning issues */
#define DEEP_create_publisher(participant, listener, mask) create_publisher(participant, listener)
#define DEEP_create_datawriter(topic, writerQos, listener, mask) create_datawriter(topic, writerQos, listener)
#define DEEP_create_subscriber(participant, listener, mask) create_subscriber(participant, listener)
#define DEEP_create_datareader(topic, readerQos, listener, mask) create_datareader(topic, readerQos, listener)

inline DDS::Topic *
DEEP_create_topic(
    DDS::DomainParticipant *domainParticipant,
    const char *topicName,
    const char *typeName,
    DDS::TopicQos topicQos)
{
	DDS::Topic *result;
    result = domainParticipant->create_topic(topicName, typeName, topicQos, NULL);
    return result;
}

inline void
DEEP_vendor_specific_readerqos_init(DDS::DataReaderQos readerQos)
{
	/* Nothing for OpenSplice */
}

/* This function waits on a waitset with timeOut as timeout.
 * The result is true if the waitset has triggered, false orhterwise */
inline bool
DEEP_waitSetWait(
    DDS::WaitSet &waitSet, /* by reference, no copy constructor available */
    DDS::Duration_t timeOut)
{
    DDS::ConditionSeq *conditions;
    bool result;
    waitSet.wait(conditions, timeOut);
    result = (conditions->length() > 0);
    return result;
}

inline DDS::DomainParticipant_ptr DEEP_create_participant(const char *domainId) {
    const char *domainIdParm;
    DDS::DomainParticipant_ptr dp;
    DDS::DomainParticipantFactory_ptr dpf = DDS::DomainParticipantFactory::get_instance();
    if ((domainId != NULL) && (*domainId == '\0')) {
        domainIdParm = NULL;
    } else {
        domainIdParm = domainId;
    }
    dp =  dpf->create_participant (domainIdParm, PARTICIPANT_QOS_DEFAULT, NULL);
    if (dp == NULL)
      {
        printf ("***Error: Splice Daemon not running \n");
        exit (1);
      }
    return dp;
}

#endif /* INCLABSTRACTION_H_ */
