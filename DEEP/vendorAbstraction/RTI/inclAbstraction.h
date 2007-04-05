#ifndef INCLABSTRACTION_H_
#define INCLABSTRACTION_H_

// undef'd elsewhere to avoid clashes with OpenSplice
typedef long pid_t;
typedef int mode_t;

#include "ace/SString.h"

/* System header files */
#include "ndds/ndds_namespace_cpp.h"

/* Type header files */
#include "deepTypesSupport.h"

#include <iostream>

using namespace std;

#define DEEP_INSTANCE_HANDLE_NIL DDS::HANDLE_NIL

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

inline
DDS::DomainParticipant_ptr DEEP_create_participant (const char *domainId)
{
  const char *domainIdParm = 0;
  DDS::DomainParticipantFactory_ptr dpf =
    DDS::DomainParticipantFactory::get_instance ();
    
  if (domainId == 0 || *domainId != '\0')
    {
      domainIdParm = domainId;
    }
  
    ACE_CString conv (domainId);
    
    // RTI DDS domain ids are not strings. This is a temporary hack.
    DDS::DomainId_t did = static_cast<RTI_INT32> (conv.hash ());
    
  return dpf->create_participant (did, 
                                  DDS::PARTICIPANT_QOS_DEFAULT,
                                  0,
                                  DDS::STATUS_MASK_NONE);
}

#endif /*INCLABSTRACTION_H_*/
