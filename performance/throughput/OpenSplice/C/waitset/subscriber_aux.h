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
		       DDS_ReturnCode_t (*ptr2readertakefunc) (FooDataReader,
                                                               FooDataSequence*,					                    
							       DDS_SampleInfoSeq*,					                    
							       const DDS_long,					                    
							       const DDS_SampleStateMask,
							       const DDS_ViewStateMask,					                    
							       const DDS_InstanceStateMask),
		       DDS_ReturnCode_t (*ptr2readerreturnloanfunc) (FooDataReader,
	                                                             FooDataSequence*,						      
								     DDS_SampleInfoSeq*))
{
    DDS_char *test_type_name = "";


    DDS_DomainId_t                             myDomain           = DDS_OBJECT_NIL;
    DDS_DomainParticipantFactory               dpf                = DDS_OBJECT_NIL;
    DDS_DomainParticipant                      dp                 = DDS_OBJECT_NIL;
    DDS_Subscriber                             s                  = DDS_OBJECT_NIL;

    
    FooDataReader                              data_reader        = DDS_OBJECT_NIL;

    DDS_Topic                                  test_topic         = DDS_OBJECT_NIL;


    
    DDS_SampleInfoSeq                          infoList           = { 0, 0, DDS_OBJECT_NIL, FALSE };


    DDS_ConditionSeq                          *conditionList;    
    DDS_WaitSet                                w;    

    DDS_StatusCondition                        reader_sc;
    

    DDS_DomainParticipantQos                  *dpQos;
    DDS_TopicQos                              *tQos;
    DDS_SubscriberQos                         *sQos;
    DDS_DataReaderQos                         *drQos;


    DDS_boolean                                terminate = FALSE;

    DDS_ReturnCode_t                           retcode;


    printf ("Wait-based...\n");


    // Initialize stats object
    PubSub_Stats *substats = new PubSub_Stats (sub_output_file,
                                               PRIMER_SAMPLES,		       
			                       STATS_SAMPLES,		       
			                       DATA_SIZE);

    // store Qos settings from file into a hash table
    TweakQos myqos (qos_config_file);

    /*
     * Create WaitSet
     */
    w = DDS_WaitSet__alloc ();

    /*
     * Initialize Qos variables
     */ 
    dpQos = DDS_DomainParticipantQos__alloc();
    tQos  = DDS_TopicQos__alloc();
    sQos  = DDS_SubscriberQos__alloc();
    drQos = DDS_DataReaderQos__alloc();

    /*
     * Initialize condition list
     */
    conditionList = NULL;

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

    // load Qos from hash table
    myqos.setDataReaderQos (*drQos);    

    data_reader = DDS_Subscriber_create_datareader (s, 
                                                    test_topic, 
						    drQos, 
						    NULL);


    // add datareader statuscondition to waitset
    reader_sc = DDS_DataReader_get_statuscondition (data_reader);
    DDS_StatusCondition_set_enabled_statuses (reader_sc, DDS_DATA_AVAILABLE_STATUS);
    retcode = DDS_WaitSet_attach_condition (w, reader_sc);



    /*------------------------------------------------------------------------*
     *                             Receive data                               *
     *------------------------------------------------------------------------*/

    int i;
    while (!transfer_complete) {
      DDS_Duration_t wait_timeout = DDS_DURATION_INFINITY;

      //printf ("Sub: waiting for data...\n");
      retcode = DDS_WaitSet_wait (w, &conditionList, &wait_timeout);

      if (conditionList) {
	int imax = conditionList->_length;
	for (i = 0; i < imax; i++) {
	  if (conditionList->_buffer[i] == reader_sc) {
	    //printf ("Sub: data arrived...\n");

	    retcode = takewstats <FooDataSequence, FooDataReader> 
	               (ptr2readertakefunc,
		        ptr2readerreturnloanfunc,
		        data_reader,			
			substats);
	 
	  } else {
	    printf ("Sub: unknown condition triggered: %x\n", (unsigned int)conditionList->_buffer[i]);
	  }
	}

        DDS_free(conditionList);
      } else {
            printf ("Sub: unknown condition triggered: %x\n", (unsigned int)conditionList->_buffer[i]);
      }
    }
    
    

    // clean up all entities
    retcode = DDS_Subscriber_delete_datareader (s, data_reader);    
    retcode = DDS_DomainParticipant_delete_subscriber (dp, s);
    retcode = DDS_DomainParticipant_delete_topic (dp, test_topic);
    retcode = DDS_DomainParticipantFactory_delete_participant (dpf, dp);
    DDS_free (w);    
    DDS_free (dpQos);
    DDS_free (sQos);
    DDS_free (tQos);
    DDS_free (drQos);
    delete substats;


    printf ("Sub: Shut down...\n");
}

#endif /* __SUBSCRIBER_AUX_H */
