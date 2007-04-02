#ifndef INCLABSTRACTION_H_
#define INCLABSTRACTION_H_

typedef long pid_t;
typedef int mode_t;

#include "ace/OS_NS_sys_time.h"

#include "dds/DCPS/Qos_Helper.h"
#include "dds/DCPS/Service_Participant.h"
#include "dds/DCPS/Marked_Default_Qos.h"

#include "simpleTypeTypeSupportImpl.h"
#include "nestedTypeTypeSupportImpl.h"
#include "arrayTypeTypeSupportImpl.h"
#include "stringTypeTypeSupportImpl.h"

#include <iostream>

using namespace std;

#define DEEP_INSTANCE_HANDLE_NIL DDS::HANDLE_NIL

// Temporary hacks to compile until framework is changed to use listeners.
namespace DDS
{
  class WaitSet
  {
  };
  
  typedef WaitSet *WaitSet_ptr;
}

inline DDS::DomainParticipant_ptr DEEP_create_participant(const char *domainId) {
    const char *domainIdParm;
    ::DDS::DomainParticipantFactory_var dpf = TheParticipantFactory;

    if ((domainId != NULL) && (*domainId == '\0'))
      {
        domainIdParm = NULL;
      } 
    else
      {
        domainIdParm = domainId;
      }

    ACE_CString conv (domainId);
    DDS::DomainId_t did = static_cast<CORBA::Long> (conv.hash ());
    return dpf->create_participant (did, PARTICIPANT_QOS_DEFAULT, NULL);
}

#endif /*INCLABSTRACTION_H_*/
