#include "ccpp_dds_dcps.h"
#include "ccpp_splice_test.h"

#include <iostream>
#include <time.h>
#include <sys/time.h>

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sched.h>
#include <sys/types.h>

using namespace std;
using namespace DDS;
using namespace CORBA;
using namespace DDSPerfTest;


/* name for the read/write partition */

// write to publisher
static char * write_partition = "DDSTEST_PUB";

// read from subscriber
static char * read_partition  = "DDSTEST_SUB";


/*  Type Definitions */

typedef struct
{
    char name[30];
    double average;
    double min;
    double max;
    int count;
} stats_type;

#define SPLICE2_TEST_DEBUG    1
#define DPRINTF(x) if(SPLICE2_TEST_DEBUG) { fprintf(stderr, "%s", x); }
/* void set_rt() */
/*      Attempt to set the real time priority and lock memory */
void set_rt() 
{
        struct sched_param p;

        p.sched_priority = 20;
        if (-1 == sched_setscheduler(0, SCHED_FIFO, &p)) {
                perror("sched_setscheduler");
        }
        if (mlockall(MCL_CURRENT || MCL_FUTURE)) {
                fprintf(stderr, 
                        "== Could not lock memory - Run with root access.\n");
        }
}


int main(int argc, char *argv[])
{

       DomainId_t                   	 myDomain           = NULL;
       DomainParticipantFactory_ptr 	 dpf                = NULL;
       DomainParticipant_ptr        	 dp                 = NULL;
       Publisher_ptr                	 p                  = NULL;
       Subscriber_ptr               	 s                  = NULL;
       DataWriter_ptr               	 dw                 = NULL;
       DataReader_ptr               	 dr                 = NULL;
       PubMessageDataReader_ptr          pubmessage_reader     = NULL;
       AckMessageDataWriter_ptr          ackmessage_writer     = NULL;

       PubMessage_NestDataReader_ptr     pubmessage_nest_reader = NULL;

       PubMessageTypeSupport             pubmessage_dt;
       AckMessageTypeSupport             ackmessage_dt;

       PubMessage_NestTypeSupport        pubmessage_nest_dt;

       PubMessageSeq_var                 pubmessage_dataList   = new PubMessageSeq;
       PubMessage_NestSeq_var            pubmessage_nest_dataList = new PubMessage_NestSeq;

       StatusCondition_ptr               pubmessage_sc         = NULL;
       StatusCondition_ptr               pubmessage_nest_sc         = NULL;
       

       Topic_ptr                         pubmessage_topic      = NULL;
       Topic_ptr                         ackmessage_topic      = NULL;

       Topic_ptr                         pubmessage_nest_topic      = NULL;

       struct timeval                    roundTripTime;
       struct timeval                    preWriteTime;
       struct timeval                    postWriteTime;
       struct timeval                    preTakeTime;
       struct timeval                    postTakeTime;
       stats_type                        roundtrip;
       stats_type                        write_access;
       stats_type                        read_access;


       ConditionSeq_var                     conditionList;
       WaitSet                              w;
       Condition_ptr                        exp_condition;

       DomainParticipantQos                 dpQos;
       TopicQos                             tQos;
       PublisherQos                         pQos;
       DataWriterQos                        dwQos;
       SubscriberQos                        sQos;
       DataReaderQos                        drQos;


       Duration_t                           wait_timeout = {3, 0};
       ReturnCode_t                         result;


       int                                  imax = 1;
       int                                  jmax = 1;
       int                                  i;
       int                                  j;
       int size;
       char sz_size[100];
       char sz_topic[1000];

       CORBA::Long sample_num = 1;
       CORBA::Long sequence_number;

       
       setbuf( stdout, NULL );		/* no buffering for standard-out */


       if( argc > 2 )
       {
          DPRINTF("splice_sub: setting size ... ");
          strcpy(sz_size,argv[2]);
          size = atoi(sz_size);
       }

       
       /* Try to set realtime */
       set_rt();



       /* Create participant */
       DPRINTF("splice_sub: creating participant ... ")
       dpf = DomainParticipantFactory::get_instance ();
       dp = dpf->create_participant (myDomain, 
                                     PARTICIPANT_QOS_DEFAULT, 
                                     NULL);
       if (dp == NULL) {
         cout << argv[0] << "SUB: ERROR - Splice Daemon not running";
         exit (1);
       }
       DPRINTF("done\n")

       
       /* Create publisher, blocks until the reciever creates the subject */
       DPRINTF("splice_sub: creating publisher ... ")
       dp->get_default_publisher_qos (pQos);
       pQos.partition.name.length (1);
       pQos.partition.name [0] = string_dup (write_partition);
       p = dp->create_publisher (pQos, NULL);
       DPRINTF("done\n")

       
       /* Create subscriber, blocks until the reciever creates the subject */
       DPRINTF("splice_sub: creating subscriber ... ")
       dp->get_default_subscriber_qos (sQos);
       sQos.partition.name.length (1);
       sQos.partition.name [0] = string_dup (read_partition);
       s = dp->create_subscriber (sQos, NULL);
       DPRINTF("done\n")
      



       /* Create topic for data writer*/
       DPRINTF("splice_sub: creating topic ... ")
       ackmessage_dt.register_type (dp,
                                    "DDSPerfTest::AckMessage");
       strcpy(sz_topic,"ackmessage_topic");
       strcat(sz_topic,sz_size);
       ackmessage_topic = dp->create_topic (sz_topic,
                                            "DDSPerfTest::AckMessage",
                                            TOPIC_QOS_DEFAULT,
                                            NULL);
       DPRINTF("done\n") 
               

       /* Create datawriter */
       DPRINTF("splice_sub: creating data writer... ")
       dw = p->create_datawriter (ackmessage_topic,
                                  DATAWRITER_QOS_DEFAULT,
                                  NULL);
       ackmessage_writer = AckMessageDataWriter::_narrow (dw);
       DPRINTF("done\n") 

//================= pubmessage =========================

       /* Create topic for data reader*/
       DPRINTF("splice_sub: creating topic ... ")
       pubmessage_dt.register_type (dp, 
                                    "DDSPerfTest::PubMessage");
       strcpy(sz_topic,"pubmessage_topic");
       strcat(sz_topic,sz_size);
       pubmessage_topic = dp->create_topic (sz_topic,
                                            "DDSPerfTest::PubMessage",
                                            TOPIC_QOS_DEFAULT,
                                            NULL);
       DPRINTF("done\n") 
      

       /* Create datareader */
       DPRINTF("splice_sub: creating data reader... ")
       dr = s->create_datareader (pubmessage_topic,
                                  DATAREADER_QOS_DEFAULT,
                                  NULL);
       pubmessage_reader = PubMessageDataReader::_narrow (dr);
       DPRINTF("done\n") 

       

//================= pubmessage_nest =========================

       /* Create topic for data reader*/
       DPRINTF("splice_sub: creating topic ... ")
       pubmessage_nest_dt.register_type (dp, 
                                    "DDSPerfTest::PubMessage_Nest");
       strcpy(sz_topic,"pubmessage_nest_topic");
       strcat(sz_topic,sz_size);
       pubmessage_nest_topic = dp->create_topic (sz_topic,
                                            "DDSPerfTest::PubMessage_Nest",
                                            TOPIC_QOS_DEFAULT,
                                            NULL);
       DPRINTF("done\n") 
      

       /* Create datareader */
       DPRINTF("splice_sub: creating data reader... ")
       dr = s->create_datareader (pubmessage_nest_topic,
                                  DATAREADER_QOS_DEFAULT,
                                  NULL);
       pubmessage_nest_reader = PubMessage_NestDataReader::_narrow (dr);
       DPRINTF("done\n") 

       
       /* Create statusCondition for pubmessage */
       DPRINTF("splice_sub: creating conditionfor pubmessage ... ")
       pubmessage_sc = pubmessage_reader->get_statuscondition ();
       pubmessage_sc->set_enabled_statuses (DATA_AVAILABLE_STATUS);
       result = w.attach_condition (pubmessage_sc);
       DPRINTF("done\n")

       /* Create statusCondition for pubmessage_nest */
       DPRINTF("splice_sub: creating condition ... ")
       pubmessage_nest_sc = pubmessage_nest_reader->get_statuscondition ();
       pubmessage_nest_sc->set_enabled_statuses (DATA_AVAILABLE_STATUS);
       result = w.attach_condition (pubmessage_nest_sc);
       DPRINTF("done\n")
       

       SampleInfoSeq_var infoList = new SampleInfoSeq;
        
       while (1) {

               /* Wait for a publication on the subject "pubmessage_topic"*/
               result = w.wait (conditionList.out (),
                                DURATION_INFINITY);

                          
               imax = conditionList->length ();
               for (i = 0; i < imax; i++)
               {
                 if ((*conditionList)[i] == pubmessage_sc)
                 {
                   result = pubmessage_reader->take (pubmessage_dataList,
                                                     infoList,
                                                     1,
                                                     ANY_SAMPLE_STATE,
                                                     ANY_VIEW_STATE,
                                                     ANY_INSTANCE_STATE);


                   jmax = pubmessage_dataList->length ();
                   if (jmax != 0)
                   {

                     sequence_number = pubmessage_dataList[0U].seqnum;


                     if (sequence_number == 0)
                     {
                           DPRINTF("splice_sub: recieved FIN from sender\n")
                           result =  pubmessage_reader->return_loan (pubmessage_dataList,
                                                                     infoList);

                           exit (1);
                     }
                     if (sequence_number != sample_num)
                     {
                         fprintf(stderr, 
                                 "ERROR - splice_sub: recieved seqnum %d on %d\n",
                                 sequence_number, sample_num);
                          exit (1);
                          
                     }
                     AckMessage ackmessage_data;
                     ackmessage_data.seqnum = sequence_number;
                     result = ackmessage_writer->write (ackmessage_data,
                                                        HANDLE_NIL);
                     sample_num++;
                     result =  pubmessage_reader->return_loan (pubmessage_dataList,
                                                               infoList);
                   }
                   else
                   {
                     cout << "pubmessage triggered, but no data available" << endl;
                     exit (1);
                   }
                 }
                 else if ((*conditionList)[i] == pubmessage_nest_sc)
                 {
                    result = pubmessage_nest_reader->take (pubmessage_nest_dataList,
                                                       infoList,
                                                       1,
                                                       ANY_SAMPLE_STATE,
                                                       ANY_VIEW_STATE,
                                                       ANY_INSTANCE_STATE);


                     jmax = pubmessage_nest_dataList->length ();
                     if (jmax != 0)
                       {
                         sequence_number = pubmessage_nest_dataList[0U].seqnum;

                         if (sequence_number == 0)
                           {
                             DPRINTF("splice_sub: recieved FIN from sender\n")
                               result =  pubmessage_nest_reader->return_loan (pubmessage_nest_dataList,
                                                                         infoList);

                             exit (1);
                           }
                         if (sequence_number != sample_num)
                           {
                             fprintf(stderr, 
                                     "ERROR - splice_sub: recieved seqnum %d on %d\n",
                                     sequence_number, sample_num);
                             //    result =  pubmessage_reader->return_loan (pubmessage_dataList,
                             //                                            infoList);
                             exit (1);
                          
                           }
                         AckMessage ackmessage_data;
                         ackmessage_data.seqnum = sequence_number;
                         result = ackmessage_writer->write (ackmessage_data,
                                                            HANDLE_NIL);
                         sample_num++;
                         result =  pubmessage_nest_reader->return_loan (pubmessage_nest_dataList,
                                                                   infoList);

                   }
                   else
                   {
                     cout << "pubmessage triggered, but no data available" << endl;
                     exit (1);
                   }
                 }
                 else
                 {
                   cout << "unknown condition triggered"
                        << (*conditionList)[i]
                        << endl;
                   exit (1);
                 }
               }
       }

FINISH:               
       /* Close it all up */
       result = p->delete_datawriter (ackmessage_writer);
       result = s->delete_datareader (pubmessage_reader);
       result = s->delete_datareader (pubmessage_nest_reader);
       result = dp->delete_subscriber (s);
       result = dp->delete_publisher (p);
       result = dp->delete_topic (pubmessage_topic);
       result = dp->delete_topic (ackmessage_topic);
       result = dp->delete_topic (pubmessage_nest_topic);
       result = dpf->delete_participant (dp);        
       return(0);
}
