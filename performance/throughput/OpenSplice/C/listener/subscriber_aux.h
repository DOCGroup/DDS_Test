#ifndef __SUBSCRIBER_AUX_H
#define __SUBSCRIBER_AUX_H

#include "dds_dcps.h"
#include "TPTDef.h"

#include "common_config.h"
#include "Stats.h"
#include "getopt.h"
#include "types_registration.h"
#include "tweak_qos.h"

#include "ace/CDR_Base.h"
#include "ace/OS_NS_sys_time.h"
#include "ace/OS_NS_unistd.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// mydebug
static char * read_partition = "Pong";
static char * write_partition = "Pong";


template <typename Stats,
	  typename FooDataReader> 
void
on_data_available_takewstats (Stats *stats, FooDataReader datareader);


void BenchmarkMainSub (int argc, char *argv[])
{
    DDS_char *test_type_name = "";


    DDS_DomainId_t                             myDomain           = DDS_OBJECT_NIL;
    DDS_DomainParticipantFactory               dpf                = DDS_OBJECT_NIL;
    DDS_DomainParticipant                      dp                 = DDS_OBJECT_NIL;
    DDS_Subscriber                             s                  = DDS_OBJECT_NIL;

    
    DDS_DataReader                             data_reader        = DDS_OBJECT_NIL;

    DDS_Topic                                  test_topic         = DDS_OBJECT_NIL;


    DDS_SampleInfoSeq                          infoList           = { 0, 0, DDS_OBJECT_NIL, FALSE };

    

    DDS_DomainParticipantQos                  *dpQos;
    DDS_TopicQos                              *tQos;
    DDS_SubscriberQos                         *sQos;
    DDS_DataReaderQos                         *drQos;


    DDS_boolean                                terminate = FALSE;

    DDS_ReturnCode_t                           retcode;



    printf ("Listener-based...\n");

    // Initialize stats object
    PubSub_Stats *substats = new PubSub_Stats (sub_output_file,
                                               PRIMER_SAMPLES,		       
			                       STATS_SAMPLES,		       
			                       DATA_SIZE);

    // store Qos settings from file into a hash table
    TweakQos myqos (qos_config_file);


    /*
     * Initialize Qos variables
     */ 
    dpQos = DDS_DomainParticipantQos__alloc();
    tQos  = DDS_TopicQos__alloc();
    sQos  = DDS_SubscriberQos__alloc();
    drQos = DDS_DataReaderQos__alloc();


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
        printf ("%s Sub: ERROR - Splice Daemon not running\n", argv[0]);
        exit(1);
    }


    // register our test's types to the domain
    printf ("Data size: %d.\n", DATA_SIZE);
    int register_status = TP_Test_register_type (dp, DATA_SIZE, &test_type_name); 


    /*
     * Create a subscriber
     */
    DDS_DomainParticipant_get_default_subscriber_qos (dp, sQos);
    sQos->partition.name._length = 1;
    sQos->partition.name._maximum = 1;
    sQos->partition.name._buffer = DDS_StringSeq_allocbuf (1);
    sQos->partition.name._buffer[0] = DDS_string_alloc (strlen (read_partition) + 1);
    strcpy (sQos->partition.name._buffer[0], read_partition);

    // load Qos from hash table
    myqos.setSubscriberQos (*sQos);

    s = DDS_DomainParticipant_create_subscriber (dp, sQos, NULL);
    


    /* Create a topic associated with the registered type*/
    DDS_DomainParticipant_get_default_topic_qos (dp, tQos);

    // load Qos from hash table
    myqos.setTopicQos (*tQos);

    test_topic = DDS_DomainParticipant_create_topic (dp, 
                                                     test_topic_name, 
						     test_type_name, 
						     tQos, 
						     NULL);

    /* Create datareader for the registered topic*/
    DDS_Subscriber_get_default_datareader_qos (s, drQos);





    // mydebug
    //DDS_Duration_t timeval;

    //DDS_DataReaderQos *temprQos2;    
    //temprQos2  = DDS_DataReaderQos__alloc();
    //DDS_DataReader_get_qos (data_reader, temprQos2);
    //if (temprQos2->durability.kind == DDS_VOLATILE_DURABILITY_QOS)
    //  std::cout << "Sub: 1) Default reader's durability is volatile.\n";
    //timeval = temprQos2->deadline.period;
    //std::cout << "Sub: 2) Default reader's deadline second - "
    //          << timeval.sec << ", nanosecond - " << timeval.nanosec << ".\n";
    //timeval = temprQos2->latency_budget.duration;
    //std::cout << "Sub: 3) Default reader's latency_budget second - "
    //          << timeval.sec << ", nanosecond - " << timeval.nanosec << ".\n";
    //if (temprQos2->liveliness.kind == DDS_AUTOMATIC_LIVELINESS_QOS)
    //  std::cout << "Sub: 4) Default reader's liveliness kind is automatic.\n";
    //timeval = temprQos2->liveliness.lease_duration;
    //std::cout << "Sub: 5) Default reader's liveliness duration second - "
    //          << timeval.sec << ", nanosecond - " << timeval.nanosec << ".\n";
    //if (temprQos2->reliability.kind == DDS_BEST_EFFORT_RELIABILITY_QOS)
    //  std::cout << "Sub: 6) Default reader's reliability is best_effort.\n";
    //timeval = temprQos2->reliability.max_blocking_time;
    //std::cout << "Sub: 7) Default reader's max_blocking time second - " 
    //          << timeval.sec << ", nanosecond - " << timeval.nanosec << ".\n";
    //if (temprQos2->destination_order.kind == DDS_BY_RECEPTION_TIMESTAMP_DESTINATIONORDER_QOS)
    //  std::cout << "Sub: 8) Default reader's destination_order kind is by_reception_timestamp.\n";
    //if (temprQos2->history.kind == DDS_KEEP_LAST_HISTORY_QOS)
    //  std::cout << "Sub: 9) Default reader's history kind is keep_last.\n";
    //std::cout << "Sub: 10) Default reader's history depth is " << temprQos2->history.depth << ".\n";
    //std::cout << "Sub: 11) Default reader's max_samples is " << temprQos2->resource_limits.max_samples << ".\n";
    //std::cout << "Sub: 12) Default reader's max_instances is " << temprQos2->resource_limits.max_instances << ".\n";
    //std::cout << "Sub: 13) Default reader's max_samples_per_instance is " << temprQos2->resource_limits.max_samples_per_instance << ".\n";
    //timeval = temprQos2->time_based_filter.minimum_separation;
    //std::cout << "Sub: 14) Default reader's time_based_filter second - "
    //          << timeval.sec << ", nanosecond - " << timeval.nanosec << ".\n";
    //timeval = temprQos2->reader_data_lifecycle.autopurge_nowriter_samples_delay;
    //std::cout << "Sub: 15) Default reader's data_lifecycle second - "
    //          << timeval.sec << ", nanosecond - " << timeval.nanosec << ".\n";
    //DDS_free(temprQos2);
    // end of mydebug

    // load Qos from hash table
    myqos.setDataReaderQos (*drQos);    

    data_reader = DDS_Subscriber_create_datareader (s, 
                                                    test_topic, 
						    drQos, 
						    NULL);

    // mydebug
    //DDS_DataReaderQos *temprQos;
    //temprQos  = DDS_DataReaderQos__alloc();
    //DDS_DataReader_get_qos (data_reader, temprQos);
    //if (temprQos->durability.kind == DDS_TRANSIENT_DURABILITY_QOS)
    //  std::cout << "Sub: 1) Set reader's durability successful!\n";
    //timeval = temprQos->deadline.period;
    //std::cout << "Sub: 2) Reader's deadline second - "
    //          << timeval.sec << ", nanosecond - " << timeval.nanosec << ".\n";
    //timeval = temprQos->latency_budget.duration;
    //std::cout << "Sub: 3) Reader's latency_budget second - "
    //          << timeval.sec << ", nanosecond - " << timeval.nanosec << ".\n";
    //if (temprQos->liveliness.kind == DDS_MANUAL_BY_PARTICIPANT_LIVELINESS_QOS)
    //  std::cout << "Sub: 4) Set reader's liveliness successful!\n";
    //timeval = temprQos->liveliness.lease_duration;
    //std::cout << "Sub: 5) Reader's liveliness duration second - "
    //          << timeval.sec << ", nanosecond - " << timeval.nanosec << ".\n";
    //if (temprQos->reliability.kind == DDS_RELIABLE_RELIABILITY_QOS)
    //  std::cout << "Sub: 6) Set reader's reliability successful!\n";
    //timeval = temprQos->reliability.max_blocking_time;
    //std::cout << "Sub: 7) Reader's max_blocking time second - " 
    //          << timeval.sec << ", nanosecond - " << timeval.nanosec << ".\n";
    //if (temprQos->destination_order.kind == DDS_BY_RECEPTION_TIMESTAMP_DESTINATIONORDER_QOS)
    //  std::cout << "Sub: 8) Reader's destination_order kind is by_reception_timestamp.\n";
    //if (temprQos->history.kind == DDS_KEEP_ALL_HISTORY_QOS)
    //  std::cout << "Sub: 9) Set reader's history kind to KEEP_ALL.\n";
    //std::cout << "Sub: 10) Reader's history depth is " << temprQos->history.depth << ".\n";
    //std::cout << "Sub: 11) Reader's max_samples is " << temprQos->resource_limits.max_samples << ".\n";
    //std::cout << "Sub: 12) Reader's max_instances is " << temprQos->resource_limits.max_instances << ".\n";
    //std::cout << "Sub: 13) Reader's max_samples_per_instance is " << temprQos->resource_limits.max_samples_per_instance << ".\n";
    //timeval = temprQos->time_based_filter.minimum_separation;
    //std::cout << "Sub: 14) Reader's time_based_filter second - "
    //          << timeval.sec << ", nanosecond - " << timeval.nanosec << ".\n";
    //timeval = temprQos->reader_data_lifecycle.autopurge_nowriter_samples_delay;
    //std::cout << "Sub: 15) Reader's data_lifecycle second - "
    //          << timeval.sec << ", nanosecond - " << timeval.nanosec << ".\n";
    //DDS_free (temprQos);
    // end of mydebug

    // initialize DataReader's Listener, activate on_data_available method    
    DDS_DataReaderListener *dr_listener;
    dr_listener = DDS_DataReaderListener__alloc ();
    dr_listener->listener_data = substats;
    dr_listener->on_requested_deadline_missed = 0;
    dr_listener->on_requested_incompatible_qos = 0;
    dr_listener->on_sample_rejected = 0;
    dr_listener->on_liveliness_changed = 0;
    dr_listener->on_data_available = &on_data_available_takewstats;
    dr_listener->on_subscription_match = 0;
    dr_listener->on_sample_lost = 0;


    // attach listener to DataReader
    retcode = DDS_DataReader_set_listener (data_reader,
                                           dr_listener,
					   DDS_DATA_AVAILABLE_STATUS);

    /*------------------------------------------------------------------------*
     *                        Listen for data                                 *
     *------------------------------------------------------------------------*/

    listener_start_time = ACE_OS::gettimeofday ();

    
    while (!transfer_complete) {
      bool loss_rate_printed = false;

      if (!loss_rate_printed) {
	listener_current_time = ACE_OS::gettimeofday ();

	// -------------------------
	//     print loss rate    
	// -------------------------

	// wait time_to_live secs before printing out
	if (listener_current_time->tv_sec - listener_start_time->tv_sec > listener_time_to_live) {   
	  printf ("Sub - Data size %d: Number of packets lost: %lu / %lu\n", DATA_SIZE,
	                                                                     PRIMER_SAMPLES + STATS_SAMPLES - num_received_samples,
									     PRIMER_SAMPLES + STATS_SAMPLES);
	  loss_rate_printed = true;
	}
      }
    
      // ---------------------------
      // end of measuring loss rate
      // ---------------------------

      ACE_OS::sleep (1);
    }



    // clean up all entities
    retcode = DDS_Subscriber_delete_datareader (s, data_reader);        
    retcode = DDS_DomainParticipant_delete_subscriber (dp, s);
    retcode = DDS_DomainParticipant_delete_topic (dp, test_topic);    
    retcode = DDS_DomainParticipantFactory_delete_participant (dpf, dp);
    DDS_free (dpQos);
    DDS_free (sQos);
    DDS_free (tQos);
    DDS_free (drQos);
    DDS_free (dr_listener);
    delete substats;


    printf ("Sub: Shut down...\n");
}

#endif /* __SUBSCRIBER_AUX_H */
