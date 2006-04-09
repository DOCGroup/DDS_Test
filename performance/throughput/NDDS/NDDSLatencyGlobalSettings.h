/*
 (c) Copyright, Real-Time Innovations, 2005.  All rights reserved.
 No duplications, whole or partial, manual or electronic, may be made
 without express written permission.  Any such copies, or
 revisions thereof, must display this notice unaltered.
 This code contains trade secrets of Real-Time Innovations, Inc.

Description
-----------

We use two best effort writer and best effort reader pairs to measure the 
latency. The basic algorithm is as follow:

    NDDSLatencyWriter                      NDDSLatencyReader
    Create a writer (topic dataTopic)      Create a reader (topic dataTopic)
    Create a reader (topic echoTopic)      Create a writer (topic echoTopic)
    Start timer                            Wait
    Send one issue --(topic dataTopic)-->  ...
    Wait                                   Receive the issue
    ....           <--(topic echoTopic)--  Send one issue of the same size
    Receive the issue
    Stop timer
    Calculate delay, minus clock overhead, and divide by 2
*/

#ifndef latency_global_settings_h
#define latency_global_settings_h

/* NDDS header file */
#include "ndds/ndds_cpp.h"

/* Type header files */
#include "NDDSLatencyPacketSupport.h"
#include "NDDSLatencyPacket.h"

/* Type name */
#define LATENCY_TYPE_NAME "PacketDataType"

/* Topic names define what information is exchanged between pub/sub apps */

/* The max length of topic named used */
#define TOPIC_NAME_LENGTH_MAX (10)
/* DataTopic: from LatencyWriter to LatencyReader */
#define LATENCY_DATA_TOPIC_NAME    "DataTopic"
/* EchoTopic: from LatencyReader to LatencyWriter */
#define LATENCY_ECHO_TOPIC_NAME    "EchoTopic"

/* Max number of different issue sizes tested */
#define LATENCY_ROUND_MAX (16)
/* Number of loops to calculate clock overhead */
#define NUM_OF_LOOPS_CLOCK (32)
/* Number of loops to ave latency for each issue size */
#define NUM_OF_LOOPS (256)
/* The final sequence number to indicate to terminate the application */
#define FINAL_SEQUENCE_NUMBER (-1)

#define RTI_SHARED_MEMORY/*undefine if you don't have shared memory plugin */
#define NDDS_OVERHEAD 52 /* Issue overhead + potential INFO_TS */
#define UNFRAGMENTED_UDP_PACKET_SIZE_MAX (1500 - 14 - 20 - 8)
#endif /* #ifndef latency_global_settings_h */
