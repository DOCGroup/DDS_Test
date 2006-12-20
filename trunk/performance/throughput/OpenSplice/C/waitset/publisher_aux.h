#ifndef __PUBLISHER_AUX_H
#define __PUBLISHER_AUX_H

#include "dds_dcps.h"
#include "TPTDef.h"

#include "common_config.h"
#include "Stats.h"
#include "getopt.h"
#include "types_registration.h"
#include "tweak_qos.h"

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


    printf ("Wait-based...\n");

    // Initialize stats object
    PubSub_Stats *pubstats = new PubSub_Stats (pub_output_file,
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

    // load Qos from hash table
    myqos.setDataWriterQos (*dwQos);    

    data_writer = DDS_Publisher_create_datawriter (p, 
                                                   test_topic, 
						   dwQos, 
						   NULL);




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
