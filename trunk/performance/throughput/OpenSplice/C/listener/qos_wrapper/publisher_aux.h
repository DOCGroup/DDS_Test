#ifndef __PUBLISHER_AUX_H
#define __PUBLISHER_AUX_H

#include "dds_dcps.h"
#include "TPTDef.h"

#include "common_config.h"
#include "Stats.h"
#include "getopt.h"
#include "types_registration.h"
#include "tweak_splice_qos.h"

#include "ace/CDR_Base.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// mydebug
static char * read_partition = "Pong";
static char * write_partition = "Pong";


template <typename FooDataType,
          typename FooDataSequence, 
	  typename FooDataReader,
          typename FooDataWriter>
void TypeSpecificMain (int argc, char *argv[],
		       DDS_ReturnCode_t (*ptr2writerwritefunc) (FooDataWriter,
	                                                        const FooDataType*,
								const DDS_InstanceHandle_t),
		       FooDataType* (*ptr2sample__allocfunc) (void))						  
{
    DDS_char *test_type_name = "";


    DDS_DomainId_t                             myDomain           = DDS_OBJECT_NIL;
    DDS_DomainParticipantFactory               dpf                = DDS_OBJECT_NIL;
    DDS_DomainParticipant                      dp                 = DDS_OBJECT_NIL;
    DDS_Publisher                              p                  = DDS_OBJECT_NIL;


    FooDataWriter                              data_writer         = DDS_OBJECT_NIL;
    
    DDS_Topic                                  test_topic         = DDS_OBJECT_NIL;
    

    DDS_DomainParticipantQos                  *dpQos;
    DDS_TopicQos                              *tQos;    
    DDS_PublisherQos                          *pQos;
    DDS_DataWriterQos                         *dwQos;


    DDS_ReturnCode_t                           retcode;



    printf ("Listener-based...\n");

    // Initialize stats object
    PubSub_Stats *pubstats = new PubSub_Stats (pub_output_file,
                                               PRIMER_SAMPLES,		       
			                       STATS_SAMPLES,		       
			                       DATA_SIZE);

    // store Qos settings from file into a hash table
    TweakSpliceQos myqos (qos_config_file);


    /*
     * Initialize Qos variables
     */ 
    dpQos = DDS_DomainParticipantQos__alloc();
    tQos  = DDS_TopicQos__alloc();
    pQos  = DDS_PublisherQos__alloc();
    dwQos = DDS_DataWriterQos__alloc();

    /*
     * Create domain participant
     */
    dpf = DDS_DomainParticipantFactory_get_instance ();

    DDS_DomainParticipantFactory_get_default_participant_qos (dpf, dpQos);

    // load Qos from hash table
    myqos.setDomainParticipantQos (*dpQos);

    dp = DDS_DomainParticipantFactory_create_participant (dpf, 
                                                          myDomain, 
							  dpQos, 
							  NULL);
    if (dp == DDS_OBJECT_NIL) {
        printf ("%s Pub: ERROR - Splice Daemon not running\n", argv[0]);
        exit(1);
    }


    // register our test's types to the domain
    printf ("Data size: %d.\n", DATA_SIZE);
    int register_status = TP_Test_register_type (dp, DATA_SIZE, &test_type_name);


    /* 
     * Create a publisher
     */
    DDS_DomainParticipant_get_default_publisher_qos (dp, pQos);
    pQos->partition.name._length = 1;
    pQos->partition.name._maximum = 1;
    pQos->partition.name._buffer = DDS_StringSeq_allocbuf (1);
    pQos->partition.name._buffer[0] = DDS_string_alloc (strlen (write_partition) + 1);
    strcpy (pQos->partition.name._buffer[0], write_partition);

    // load Qos from hash table
    myqos.setPublisherQos (*pQos);

    p = DDS_DomainParticipant_create_publisher (dp, pQos, NULL);
    

    /* Create a topic associated with the registered type*/    
    DDS_DomainParticipant_get_default_topic_qos (dp, tQos);

    // load Qos from hash table
    myqos.setTopicQos (*tQos);

    test_topic = DDS_DomainParticipant_create_topic (dp, 
                                                     test_topic_name, 
						     test_type_name, 
						     tQos, 
						     NULL);
    
    /* Create datawriter for the registered topic*/
    DDS_Publisher_get_default_datawriter_qos (p, dwQos);









    // mydebug
    //DDS_Duration_t timeval;

    //DDS_DataWriterQos *tempwQos2;    
    //tempwQos2  = DDS_DataWriterQos__alloc();
    //DDS_DataWriter_get_qos (data_writer, tempwQos2);
    //if (tempwQos2->durability.kind == DDS_VOLATILE_DURABILITY_QOS)
    //  std::cout << "Pub: 1) Default writer's durability is volatile.\n";
    //timeval = tempwQos2->deadline.period;
    //std::cout << "Pub: 2) Default writer's deadline second - "
    //          << timeval.sec << ", nanosecond - " << timeval.nanosec << ".\n";
    //timeval = tempwQos2->latency_budget.duration;
    //std::cout << "Pub: 3) Default writer's latency_budget second - "
    //          << timeval.sec << ", nanosecond - " << timeval.nanosec << ".\n";
    //if (tempwQos2->liveliness.kind == DDS_AUTOMATIC_LIVELINESS_QOS)
    //  std::cout << "Pub: 4) Default writer's liveliness kind is automatic.\n";
    //timeval = tempwQos2->liveliness.lease_duration;
    //std::cout << "Pub: 5) Default writer's liveliness duration second - "
    //          << timeval.sec << ", nanosecond - " << timeval.nanosec << ".\n";
    //if (tempwQos2->reliability.kind == DDS_BEST_EFFORT_RELIABILITY_QOS)
    //  std::cout << "Pub: 6) Default writer's reliability is best_effort.\n";
    //timeval = tempwQos2->reliability.max_blocking_time;
    //std::cout << "Pub: 7) Default writer's max_blocking time second - " 
    //          << timeval.sec << ", nanosecond - " << timeval.nanosec << ".\n";
    //if (tempwQos2->destination_order.kind == DDS_BY_RECEPTION_TIMESTAMP_DESTINATIONORDER_QOS)
    //  std::cout << "Pub: 8) Default writer's destination_order kind is by_reception_timestamp.\n";
    //if (tempwQos2->history.kind == DDS_KEEP_LAST_HISTORY_QOS)
    //  std::cout << "Pub: 9) Default writer's history kind is keep_last.\n";
    //std::cout << "Pub: 10) Default writer's history depth is " << tempwQos2->history.depth << ".\n";
    //std::cout << "Pub: 11) Default writer's max_samples is " << tempwQos2->resource_limits.max_samples << ".\n";
    //std::cout << "Pub: 12) Default writer's max_instances is " << tempwQos2->resource_limits.max_instances << ".\n";
    //std::cout << "Pub: 13) Default writer's max_samples_per_instance is " << tempwQos2->resource_limits.max_samples_per_instance << ".\n";
    //timeval = tempwQos2->lifespan.duration;
    //std::cout << "Pub: 14) Default writer's lifespan second - "
    //          << timeval.sec << ", nanosecond - " << timeval.nanosec << ".\n";

    //DDS_free(tempwQos2);
    // end of mydebug










    // load Qos from hash table
    myqos.setDataWriterQos (*dwQos);    

    data_writer = DDS_Publisher_create_datawriter (p, 
                                                   test_topic, 
						   dwQos, 
						   NULL);






    // mydebug
    //DDS_DataWriterQos *tempwQos;    
    //tempwQos  = DDS_DataWriterQos__alloc();
    //DDS_DataWriter_get_qos (data_writer, tempwQos);

    //if (tempwQos->durability.kind == DDS_TRANSIENT_DURABILITY_QOS)
    //  std::cout << "Pub: 1) Set writer's durability successful!\n";
    //timeval = tempwQos->deadline.period;
    //std::cout << "Pub: 2) writer's deadline second - "
    //          << timeval.sec << ", nanosecond - " << timeval.nanosec << ".\n";
    //timeval = tempwQos->latency_budget.duration;
    //std::cout << "Pub: 3) writer's latency_budget second - "
    //          << timeval.sec << ", nanosecond - " << timeval.nanosec << ".\n";
    //if (tempwQos->liveliness.kind == DDS_MANUAL_BY_PARTICIPANT_LIVELINESS_QOS)
    //  std::cout << "Pub: 4) Set writer's liveliness successful!\n";
    //timeval = tempwQos->liveliness.lease_duration;
    //std::cout << "Pub: 5) writer's liveliness duration second - "
    //          << timeval.sec << ", nanosecond - " << timeval.nanosec << ".\n";
    //if (tempwQos->reliability.kind == DDS_RELIABLE_RELIABILITY_QOS)
    //  std::cout << "Pub: 6) Set writer's reliability successful!\n";
    //timeval = tempwQos->reliability.max_blocking_time;
    //std::cout << "Pub: 7) writer's max_blocking time second - " 
    //          << timeval.sec << ", nanosecond - " << timeval.nanosec << ".\n";
    //if (tempwQos->destination_order.kind == DDS_BY_RECEPTION_TIMESTAMP_DESTINATIONORDER_QOS)
    //  std::cout << "Pub: 8) writer's destination_order kind is by_reception_timestamp.\n";
    //if (tempwQos->history.kind == DDS_KEEP_ALL_HISTORY_QOS)
    //  printf ("Pub: 9) Set writer's history kind to KEEP_ALL.\n");
    //std::cout << "Pub: 10) writer's history depth is " << tempwQos->history.depth << ".\n";
    //std::cout << "Pub: 11) writer's max_samples is " << tempwQos->resource_limits.max_samples << ".\n";
    //std::cout << "Pub: 12) writer's max_instances is " << tempwQos->resource_limits.max_instances << ".\n";
    //std::cout << "Pub: 13) writer's max_samples_per_instance is " << tempwQos->resource_limits.max_samples_per_instance << ".\n";
    //timeval = tempwQos->lifespan.duration;
    //std::cout << "Pub: 14) writer's lifespan second - "
    //          << timeval.sec << ", nanosecond - " << timeval.nanosec << ".\n";
    //DDS_free(tempwQos);
    // end of mydebug









    /*------------------------------------------------------------------------*
     *                              Send data                                 *
     *------------------------------------------------------------------------*/

    printf ("Pub: Begin sending samples...\n");    
    retcode = writewstats <FooDataType, FooDataWriter> 
	         (ptr2writerwritefunc,
		  ptr2sample__allocfunc,
		  data_writer,
		  pubstats);

 


    // clean up all entities
    retcode = DDS_Publisher_delete_datawriter (p, data_writer);    
    retcode = DDS_DomainParticipant_delete_publisher (dp, p);
    retcode = DDS_DomainParticipant_delete_topic (dp, test_topic);    
    retcode = DDS_DomainParticipantFactory_delete_participant (dpf, dp);    
    DDS_free (dpQos);
    DDS_free (pQos);
    DDS_free (tQos);    
    DDS_free (dwQos);
    delete pubstats;


    printf ("Pub: Shut down...\n");
}

#endif /* __PUBLISHER_AUX_H */
