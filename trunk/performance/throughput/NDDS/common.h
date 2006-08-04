/*
 (c) Copyright, Real-Time Innovations, 2005.  All rights reserved.
 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.
*/

#ifndef COMMON_H
#define COMMON_H

/* Type header files */
#include "TP_PacketSupport.h"

#define RTI_SHARED_MEMORY /*undefine if you don't have shared memory plugin */

const long MY_OWN_TEST_OVERHEAD  = sizeof(DDS_UnsignedLong);
const long NDDS_OVERHEAD  = 52; /* Issue overhead + potential INFO_TS */

/* Uncomment this line if you want to debug the publication match */
//#define I_WANT_TO_DEBUG

#endif /* #ifndef COMMON_H */
