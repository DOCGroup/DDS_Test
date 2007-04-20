#ifndef INCLABSTRACTION_H_
#define INCLABSTRACTION_H_

/* Abstraction with respect to the names of the include files.
 * This is vendor dependent */

#include "ccpp_deepTypes.h"
#include "ccpp_dds_dcps.h"

#define DEEP_INSTANCE_HANDLE_NIL DDS::HANDLE_NIL

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

#endif /*INCLABSTRACTION_H_*/