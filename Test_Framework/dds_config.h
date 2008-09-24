
#ifndef DDS_FRAMEWORK_CONFIG_H
#define DDS_FRAMEWORK_CONFIG_H

// Uncomment exactly one of these.
//#define NDDS_CONFIG
#define TAO_DDS_CONFIG
//#define SPLICE_CONFIG

#if defined (NDDS_CONFIG)

# if defined (TAO_DDS_CONFIG) || defined (SPLICE_CONFIG)
# error Only one implementation config flag should be uncommented
# endif

#include "ndds/ndds_cpp.h"

#elif defined (TAO_DDS_CONFIG)

# if defined (NDDS_CONFIG) || defined (SPLICE_CONFIG)
# error Only one implementation config flag should be uncommented
# endif

#include "dds/DCPS/Service_Participant.h"
#include "dds/DCPS/Marked_Default_Qos.h"
#include "dds/DCPS/transport/framework/TheTransportFactory.h"
#include "dds/DCPS/transport/simpleTCP/SimpleTcpConfiguration.h"

#elif defined (SPLICE_CONFIG)

# if defined (NDDS_CONFIG) || defined (TAO_DDS_CONFIG)
# error Only one implementation config flag should be uncommented
# endif

#include "dds_dcps.h"

#endif /* if defined */

#endif /* DDS_FRAMEWORK_CONFIG_H */
