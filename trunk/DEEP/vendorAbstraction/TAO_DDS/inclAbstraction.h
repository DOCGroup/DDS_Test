#ifndef INCLABSTRACTION_H_
#define INCLABSTRACTION_H_

// undef'd elsewhere to avoid clashes with OpenSplice
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

inline
DDS::DomainParticipant_ptr DEEP_create_participant (const char *domainId)
{
    const char *domainIdParm = 0;
    DDS::DomainParticipantFactory_var dpf = TheParticipantFactory;

  if (domainId == 0 || *domainId != '\0')
    {
      domainIdParm = domainId;
    }
  
    ACE_CString conv (domainId);
    
    // TAO DDS domain ids are not strings. This is a temporary hack.
    DDS::DomainId_t did = static_cast<CORBA::Long> (conv.hash ());
    
    return dpf->create_participant (did, PARTICIPANT_QOS_DEFAULT, 0);
}

#endif /*INCLABSTRACTION_H_*/
