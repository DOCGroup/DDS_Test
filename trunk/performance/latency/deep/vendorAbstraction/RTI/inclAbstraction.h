#ifndef INCLABSTRACTION_H_
#define INCLABSTRACTION_H_

#include "ndds/ndds_cpp.h"
/*include this file if you want to use DDS namespace */
// #include "ndds/ndds_namespace_cpp.h"
#include "deepTypes.h"
#include "deepTypesSupport.h"

#define DEEP_INSTANCE_HANDLE_NIL DDS_HANDLE_NIL

inline DDSDomainParticipant *DEEP_create_participant(int domainId) {
    DDSDomainParticipantFactory *factory = DDSDomainParticipantFactory::get_instance();
    return factory->create_participant (domainId,
                                        DDS_PARTICIPANT_QOS_DEFAULT,
                                        NULL,
                                        DDS_STATUS_MASK_NONE);
}



#endif /*INCLABSTRACTION_H_*/
