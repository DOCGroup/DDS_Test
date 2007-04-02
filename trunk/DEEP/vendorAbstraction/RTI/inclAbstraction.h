#ifndef INCLABSTRACTION_H_
#define INCLABSTRACTION_H_

/* NDDS header file */
//#include "ndds/ndds_cpp.h"

/* Type header files */
#include "deepTypesSupport.h"
//#include "deepTypes.h"

#include <iostream>

using namespace std;

// For better compliance with OMG IDL PSM C++ mapping.
namespace DDS
{
  typedef DDSDomainParticipantFactory DomainParticipantFactory;
  
  typedef DDSDomainParticipant DomainParticipant;
  typedef DomainParticipant *DomainParticipant_ptr;
  typedef DDS_DomainParticipantQos DomainParticipantQos;
  typedef DDSDomainParticipantListener DomainParticipantListener;
  
  typedef DDSTopic Topic;
  typedef DDS_TopicQos TopicQos;
  typedef DDSTopicListener TopicListener;
  
  typedef DDS_StatusMask StatusMask;
  
  typedef DDS_ReturnCode_t ReturnCode_t;
  typedef DDS_Duration_t Duration_t;
}

#endif /*INCLABSTRACTION_H_*/
