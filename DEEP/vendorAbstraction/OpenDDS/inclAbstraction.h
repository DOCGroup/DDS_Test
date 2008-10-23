#ifndef INCLABSTRACTION_H_
#define INCLABSTRACTION_H_

// undef'd elsewhere to avoid clashes with OpenSplice
//typedef long pid_t;
//typedef int mode_t;

//#include "ace/OS_NS_sys_time.h"

#include "dds/DCPS/Qos_Helper.h"
#include "dds/DCPS/Service_Participant.h"
#include "dds/DCPS/Marked_Default_Qos.h"
#include "dds/DCPS/WaitSet.h"

#include "deepTypesTypeSupportImpl.h"

#include <iostream>

using namespace std;

#define DEEP_INSTANCE_HANDLE_NIL DDS::HANDLE_NIL

/* The type used for the [] operator on sequences seems to be vendor specific */
typedef CORBA::ULong DEEP_sequenceIndexType;

/* Setting the length of a sequence */
#define DEEP_length(seqLen) length(seqLen) 

/* The narrow operator has a different name for different vendors */
#define DEEP_narrow(entity) _narrow(entity)

/* Different implementations use different strdups */
inline char *DEEP_strdup(const char *source) {
	return CORBA::string_dup(source);
}

#define DEEP_register_type(typeSupportTypeName, \
                           domainParticipant, \
                           typeName, \
                           result) \
  do { \
  	typeSupportTypeName##TypeSupport_var typeSupport = \
  	  new typeSupportTypeName##TypeSupportImpl (); \
  	result = typeSupport->register_type(domainParticipant, typeName); \
  } while (0)

/* Macro's for solving OMG spec versioning issues */
#define DEEP_create_publisher(participant, listener, mask) \
  create_publisher(participant, listener)
#define DEEP_create_datawriter(topic, writerQos, listener, mask) \
  create_datawriter(topic, writerQos, listener)
#define DEEP_create_subscriber(participant, listener, mask) \
  create_subscriber(participant, listener)
#define DEEP_create_datareader(topic, readerQos, listener, mask) \
  create_datareader(topic, readerQos, listener)

inline DDS::Topic *
DEEP_create_topic (
    DDS::DomainParticipant *domainParticipant,
    const char *topicName,
    const char *typeName,
    DDS::TopicQos topicQos)
{
  DDS::Topic *result =
    domainParticipant->create_topic (topicName,
                                     typeName,
                                     topicQos,
                                     DDS::TopicListener::_nil ());
  return result;
}

inline void
DEEP_vendor_specific_readerqos_init (DDS::DataReaderQos readerQos)
{
	/* Nothing for OpenDDS */
}

inline bool
DEEP_waitSetWait (
  DDS::WaitSet &waitSet, // by reference, no copy constructor available 
  DDS::Duration_t timeOut)
{
  return false;
}

inline
DDS::DomainParticipant_ptr DEEP_create_participant (const char *domainId)
{
  DDS::DomainParticipantFactory_var factory = TheParticipantFactory;

  return
    factory->create_participant (atoi (domainId),
                                 PARTICIPANT_QOS_DEFAULT,
                                 DDS::DomainParticipantListener::_nil ());
}

#endif /*INCLABSTRACTION_H_*/
