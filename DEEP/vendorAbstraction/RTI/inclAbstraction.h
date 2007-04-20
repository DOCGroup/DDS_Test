#ifndef INCLABSTRACTION_H_
#define INCLABSTRACTION_H_

#include "ndds/ndds_cpp.h"
/*include this file if you want to use DDS namespace */
#include "ndds/ndds_namespace_cpp.h"
#include "deepTypes.h"
#include "deepTypesSupport.h"

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


inline DDSDomainParticipant *DEEP_create_participant(int domainId) {
    DDSDomainParticipantFactory *factory = DDSDomainParticipantFactory::get_instance();
    return factory->create_participant (domainId,
                                        DDS_PARTICIPANT_QOS_DEFAULT,
                                        NULL,
                                        DDS_STATUS_MASK_NONE);
}



#endif /*INCLABSTRACTION_H_*/
