#include "ccpp_dds_dcps.h"
#include "ccpp_splice_test.h"
#include "tester.h"

#include <iostream>
#include <time.h>
#include <sys/time.h>

#include <string.h>
#include <fstream>

#include <getopt.h>
#include <sys/types.h>

#define RESULT_FILE_NAME_MAX 1024

using namespace std;
using namespace DDS;
using namespace CORBA;
using namespace DDSPerfTest;

// comment

static ofstream result_file;

/* name for the read/write partition */

// write to subscriber
static char * write_partition = "DDSTEST_SUB";

// read from publisher
static char * read_partition  = "DDSTEST_PUB";



typedef struct
{
    char name[20];
    double average;
    double min;
    double max;
    double sum;
    double sum2;
    int count;
} stats_type;

//
// Static functions
//

static void
add_stats (
    stats_type& stats,
    double data
    )
{
    stats.average = (stats.count * stats.average + data)/(stats.count + 1);
    stats.min     = (stats.count == 0 || data < stats.min) ? data : stats.min;
    stats.max     = (stats.count == 0 || data > stats.max) ? data : stats.max;
    stats.sum = stats.sum + data;
    stats.sum2 = stats.sum2 + data * data;
    stats.count++;
}

static void
init_stats (
    stats_type& stats,
    char *name)
{
    strncpy ((char *)stats.name, name, 19);
    stats.name[19] = '\0';
    stats.count    = 0;
    stats.average  = 0.0;
    stats.min      = 0.0;
    stats.max      = 0.0;
    stats.sum      = 0.0;
    stats.sum2     = 0.0;
}

static double
std_dev (stats_type& stats)
{
  if (stats.count >=2)
  {
    return sqrt ((static_cast<double>(stats.count) * stats.sum2 - stats.sum * stats.sum) / 
                (static_cast<double>(stats.count) * static_cast<double>(stats.count - 1)));
  }
}


/* Global Variables */

// @@Note: domainId identifies the domain. 
//         Participants with same id shares the same domain
static DomainId_t                   	 myDomain           = NULL;

// @@Note: preexisting singleton object
static DomainParticipantFactory_ptr 	 dpf                = NULL;
static DomainParticipant_ptr        	 dp                 = NULL;

// @@Note: Generic domain entities, which we will need to downcast
//         to specific domain entities
static Publisher_ptr                	 p                  = NULL;
static Subscriber_ptr               	 s                  = NULL;
static DataWriter_ptr               	 dw                 = NULL;
static DataReader_ptr               	 dr                 = NULL;

// @@Note: to get the specific pubmessage_datawriter/ackmessage_datareader,
//         you need to downcast it from DataWriter/DataReader
static PubMessageDataWriter_ptr          pubmessage_writer = NULL;
static AckMessageDataReader_ptr          ackmessage_reader = NULL;

static PubMessage_NestDataWriter_ptr     pubmessage_nest_writer = NULL;

// @@Note: these are derived class from TypeSupport
//         each type that will go over DDS network has
//         a type support class
static PubMessageTypeSupport             pubmessage_dt;
static AckMessageTypeSupport             ackmessage_dt;

static PubMessage_NestTypeSupport        pubmessage_nest_dt;

static AckMessageSeq_var                 ackmessage_dataList   = new AckMessageSeq;

static StatusCondition_ptr               ackmessage_sc         = NULL;

static Topic_ptr                         pubmessage_topic      = NULL;
static Topic_ptr                         ackmessage_topic      = NULL;

static Topic_ptr                         pubmessage_nest_topic = NULL;

static struct timeval                    roundTripTime;
static struct timeval                    preWriteTime;
static struct timeval                    postWriteTime;
static struct timeval                    preTakeTime;
static struct timeval                    postTakeTime;

static stats_type                        round_trip;
static stats_type                        write_access;
static stats_type                        read_access;


static char topic_id = 's';

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


/* Defines and constants for getopts */
#define OPTION_STRING  "c:s:r:d:t:b:h"

/* Global and default test paramters, may be set on command line. */

long size=4;                             /* Message size of test            */
long total_samples=10000;                  /* Total number of samples to take */
long primer_samples=100;

void print_help() 
{
        printf("usage: splice_pub [options]\n\n");
        printf("       -p       number of primer samples(default=100)\n");
        printf("       -s       number of samples(default=100)\n");
        printf("       -d       message size(default=4)\n");
        printf("       -r       range of histogram(default=1000)\n");
        printf("       -b       number of bins in histogram(default=500)\n");
        printf("       -h       help, print this message\n");
        printf("\n");
        printf("If you would like to do a full specturm test use the\n");
        printf("writer.sh and reader.sh scripts.\n\n");

}


int main(int argc, char *argv[])
{

       int                                  ack_received = 0;


       ConditionSeq_var                     conditionList;
       WaitSet                              w;

       DomainParticipantQos                 dpQos;
       TopicQos                             tQos;
       PublisherQos                         pQos;
       DataWriterQos                        dwQos;
       SubscriberQos                        sQos;
       DataReaderQos                        drQos;


       Duration_t                           wait_timeout = {3, 0};
       ReturnCode_t                         result;


       int                                  imax = 1;
       int                                  i;
       int                                  amount;
       char sz_size[100];
       char sz_topic[1000];
       char sz_results[RESULT_FILE_NAME_MAX];


       struct timeval start, end;
       time_t                               clock = time (NULL);
       CORBA::Long sample_num=1;
       int dt=0;
       int debug=0;
       CORBA::Long sequence_number; 
       int ich;

       //
       // init timing statistics 
       //
       init_stats (round_trip,    "round_trip");

       setbuf( stdout, NULL );		/* no buffering for standard-out */




       while ((ich = getopt (argc, argv, OPTION_STRING)) != EOF) {
        switch (ich) {
                
        case 's': /* c specifes number of samples */
        total_samples = atoi(optarg);

        if(total_samples < 0) {
                fprintf(stderr, "splice_pub: ERROR - bad sample number\n");
                exit(1);
        }
                
        break;
        
        case 'd': /* s specifes size of the message */
        size = atoi(optarg);
        strcpy(sz_size,optarg);
        
        break;

        case 'p': /* s specifes size of the message */
        primer_samples = atoi(optarg);
        
        break;

        case 'q': /* s specifes size of the message */
        debug = atoi(optarg);
        
        break;

        case 'r': /* r specifies results file */
        strncpy(sz_results,optarg,RESULT_FILE_NAME_MAX - 1);
        
        break;

        case 't': /* t specifies data types */
        topic_id = *optarg;
        
        
        break;
        
        case 'h':
        print_help();
        exit(0);
        break;
        
        
        default: /* no parameters */
        break;
               
        }
       }

       
       /* Try to set realtime */
       set_rt();
      


       /* Create participant */
       DPRINTF("splice_pub: creating participant ... ")
       dpf = DomainParticipantFactory::get_instance ();
       dp = dpf->create_participant (myDomain,
                                     PARTICIPANT_QOS_DEFAULT, 
                                     NULL);
       if (dp == NULL) {
         cout << argv[0] << "PUB: ERROR - Splice Daemon not running";
         exit (1);
       }
       DPRINTF("done\n")

       
       /* Create publisher to write sequence<char> data*/
       DPRINTF("splice_pub: creating publisher ... ")
       dp->get_default_publisher_qos (pQos);
       pQos.partition.name.length (1);
       pQos.partition.name [0] = string_dup (write_partition);
       p = dp->create_publisher (pQos, NULL);
       DPRINTF("done\n")

       
       /* Create subscriber to read acknowledge message*/
       DPRINTF("splice_pub: creating subscriber ... ")
       dp->get_default_subscriber_qos (sQos);
       sQos.partition.name.length (1);
       sQos.partition.name [0] = string_dup (read_partition);
       s = dp->create_subscriber (sQos, NULL);
       DPRINTF("done\n")
      

//******************pubmessgae****************************

       /* Create pubmessage topic for datawriter */
       pubmessage_dt.register_type (dp, 
                                    "DDSPerfTest::PubMessage");
       DPRINTF("splice_pub: creating topic ... ")
       strcpy(sz_topic,"pubmessage_topic");
       strcat(sz_topic,sz_size);
       pubmessage_topic = dp->create_topic (sz_topic, // topic name
                                            "DDSPerfTest::PubMessage", // type name, which has to match a registered entry
                                            TOPIC_QOS_DEFAULT, // topic qos policy
                                            NULL); // topic listener
       DPRINTF("done\n") 
               

       /* Create PubMessage datawriter */
       DPRINTF("splice_pub: creating data writer... ")
       dw = p->create_datawriter (pubmessage_topic,
                                  DATAWRITER_QOS_DEFAULT,
                                  NULL);
       pubmessage_writer = PubMessageDataWriter::_narrow (dw);
       DPRINTF("done\n") 
       
//******************pubmessgae_nest****************************

       /* Create pubmessage_nest topic for datawriter */
       pubmessage_nest_dt.register_type (dp, 
                                    "DDSPerfTest::PubMessage_Nest");
       DPRINTF("splice_pub: creating topic ... ")
       strcpy(sz_topic,"pubmessage_nest_topic");
       strcat(sz_topic,sz_size);
       pubmessage_nest_topic = dp->create_topic (sz_topic,// topic name
                                            "DDSPerfTest::PubMessage_Nest", // type name, which has to match a registered entry
                                            TOPIC_QOS_DEFAULT, // topic qos policy
                                            NULL); // topic listener
       DPRINTF("done\n") 
               

       /* Create PubMessage datawriter */
       DPRINTF("splice_pub: creating data writer... ")
       dw = p->create_datawriter (pubmessage_nest_topic,
                                  DATAWRITER_QOS_DEFAULT,
                                  NULL);
       pubmessage_nest_writer = PubMessage_NestDataWriter::_narrow (dw);
       DPRINTF("done\n") 
      

//******************ackmessage****************************

       /* Create topic for datareader*/
       DPRINTF("splice_pub: creating topic ... ")
       ackmessage_dt.register_type (dp,
                                    "DDSPerfTest::AckMessage");
       strcpy(sz_topic,"ackmessage_topic");
       strcat(sz_topic,sz_size);
       ackmessage_topic = dp->create_topic (sz_topic,
                                            "DDSPerfTest::AckMessage",
                                            TOPIC_QOS_DEFAULT,
                                            NULL);
       DPRINTF("done\n") 



       /* Create AckMessage datareader */
       DPRINTF("splice_pub: creating data reader... ")
       dr = s->create_datareader (ackmessage_topic,
                                  DATAREADER_QOS_DEFAULT,
                                  NULL);
       ackmessage_reader = AckMessageDataReader::_narrow (dr);
       DPRINTF("done\n") 

       
       /* Create statusCondition for subscriber */
       DPRINTF("splice_pub: creating condition ... ")
       ackmessage_sc = ackmessage_reader->get_statuscondition ();
       ackmessage_sc->set_enabled_statuses (DATA_AVAILABLE_STATUS);
       result = w.attach_condition (ackmessage_sc);

       DPRINTF("done\n")


      /* as per the request of the PrismTech team, we add an 8 second
       * sleep to ensure service stability */

       sleep(8);

       /* We perform primer_samples extra transfers to prime/warmup Splice2 */
       total_samples += primer_samples;
       
       DPRINTF("splice_pub: running test ... \n")



       switch (topic_id) {
       case 's':
         {
           std::cout << " start simple...." << std::endl;
           while( sample_num < total_samples ) {
       
             /* Put the sample number in as a sequence number */
             PubMessage pubmessage_data;

             pubmessage_data.seqnum = sample_num;

             // DPRINTF ("alloc size.. \n");
             pubmessage_data.data.length (size);

             struct timeval round_pre_t = tester::get_time ();

             result = pubmessage_writer->write (pubmessage_data,
                                                HANDLE_NIL);

              
             /* wait for a publication of sub node on subject "ackmessage_topic" */
             result = w.wait (conditionList.out (),
                              DURATION_INFINITY);

             /* one way to measure roundtrip */
             gettimeofday(&end,NULL);

             imax = conditionList->length ();

             if (imax != 0)
               {
                 for (i = 0; i < imax; i++) 
                   {
                     /* validate the condition to see if it's what we are waiting for */
                     if ((*conditionList)[i] == ackmessage_sc)
                       {
                         SampleInfoSeq_var infoList = new SampleInfoSeq;
                         //DPRINTF ("take... \n");

                         result = ackmessage_reader->take (ackmessage_dataList,
                                                           infoList,
                                                           1,
                                                           ANY_SAMPLE_STATE,
                                                           ANY_VIEW_STATE,
                                                           ANY_INSTANCE_STATE);

                         struct timeval round_post_t = tester::get_time ();


                         if (sample_num >= primer_samples)
                           {
                             add_stats (round_trip,
                                        1E6 * tester::time_to_real (tester::get_time_diff (round_post_t, round_pre_t)));
                           }

                         amount = ackmessage_dataList->length ();


                         if (amount != 0)
                           {
                             /* discard any extra messages */
                             if (amount > 1)
                               {
                                 cout << "Splice2Test: Ignore excess messages :"
                                      << ackmessage_dataList->length ()
                                      << " msg received" << endl;

                               }

                             sequence_number = (CORBA::Long)ackmessage_dataList [0].seqnum;


                             // @@Note: check the received senum (sequence_number )
                             //         to see if it matches the value we sent out 
                             if ( sequence_number != sample_num ) 
                               {
                                 fprintf(stderr, 
                                         "ERROR - splice_pub: recieved seqnum %d on %d\n",
                                         sequence_number, sample_num);
                                 exit (1);
                               }

                             //sample_num++;
                             result = ackmessage_reader->return_loan (ackmessage_dataList,
                                                                      infoList);
                       
                           }
                       }
                     else
                       {
                         cout << "SPLICE_PUB: unexpected condition triggered:"
                              << (*conditionList) [i]
                              << endl;
                         exit (1);
                       }
                   }
               }
             sample_num++;

           }
       
           /* Publish a FINISH signal, sequence number is -1 */
           DPRINTF("splice_pub: sending FIN to receiver ... ")
           PubMessage pubmessage_data;
           pubmessage_data.seqnum = 0;
           result = pubmessage_writer->write (pubmessage_data,
                                              HANDLE_NIL);
           DPRINTF("done\n")

           break;
         }
       case 'c':
         {
           std::cout << " start complex...." << std::endl;

           while( sample_num < total_samples ) {
       
             /* Put the sample number in as a sequence number */
             PubMessage_Nest pubmessage_data;

             pubmessage_data.seqnum = sample_num;

             // DPRINTF ("alloc size.. \n");
             pubmessage_data.data.length (size);
             pubmessage_data.data[0].o_data.length (1);
             pubmessage_data.data[0].o_data[0].n_data = string_dup ("01234567");


             struct timeval round_pre_t = tester::get_time ();
               
             result = pubmessage_nest_writer->write (pubmessage_data,
                                                     HANDLE_NIL);

              
             /* wait for a publication of sub node on subject "ackmessage_topic" */
             result = w.wait (conditionList.out (),
                              DURATION_INFINITY);

             /* one way to measure roundtrip */
             gettimeofday(&end,NULL);

             imax = conditionList->length ();

             if (imax != 0)
               {
                 for (i = 0; i < imax; i++) 
                   {
                     /* validate the condition to see if it's what we are waiting for */
                     if ((*conditionList)[i] == ackmessage_sc)
                       {
                         SampleInfoSeq_var infoList = new SampleInfoSeq;
                         //DPRINTF ("take... \n");

                         result = ackmessage_reader->take (ackmessage_dataList,
                                                           infoList,
                                                           1,
                                                           ANY_SAMPLE_STATE,
                                                           ANY_VIEW_STATE,
                                                           ANY_INSTANCE_STATE);

                         struct timeval round_post_t = tester::get_time ();


                         if (sample_num >= primer_samples)
                           {
                             add_stats (round_trip,
                                        1E6 * tester::time_to_real (tester::get_time_diff (round_post_t, round_pre_t)));
                           }

                         amount = ackmessage_dataList->length ();
                         if (amount != 0)
                           {
                             /* discard any extra messages */
                             if (amount > 1)
                               {
                                 cout << "Splice2Test: Ignore excess messages :"
                                      << ackmessage_dataList->length ()
                                      << " msg received" << endl;

                               }

                             sequence_number = (CORBA::Long)ackmessage_dataList [0].seqnum;


                             // @@Note: check the received senum (sequence_number )
                             //         to see if it matches the value we sent out 
                             if ( sequence_number != sample_num ) 
                               {
                                 fprintf(stderr, 
                                         "ERROR - splice_pub: recieved seqnum %d on %d\n",
                                         sequence_number, sample_num);
                                 exit (1);
                               }

                             //sample_num++;
                             result = ackmessage_reader->return_loan (ackmessage_dataList,
                                                                      infoList);
                       
                           }
                       }
                     else
                       {
                         cout << "SPLICE_PUB: unexpected condition triggered:"
                              << (*conditionList) [i]
                              << endl;
                         exit (1);
                       }
                   }
               }
             sample_num++;

           }
       
           /* Publish a FINISH signal, sequence number is -1 */
           DPRINTF("splice_pub: sending FIN to receiver ... ")
             PubMessage pubmessage_data;
           pubmessage_data.seqnum = 0;
           result = pubmessage_writer->write (pubmessage_data,
                                              HANDLE_NIL);
           DPRINTF("done\n")
           break;
         }
       default:break;
       }


       result_file.open (sz_results,ios_base::app);
       result_file << size << std::endl;

       result_file << round_trip.min << std::endl;
       result_file << round_trip.max << std::endl;
       result_file << round_trip.average << std::endl;
       result_file << std_dev (round_trip) << std::endl;
       result_file << std::endl;
       result_file.close ();

       printf ("# MY Pub Sub PONG measurements (in us) \n");
       printf ("# Executed at: %s", ctime(&clock));
       printf ("#       Roundtrip time [us]\n");
       printf ("# Count     mean      min      max   stdv\n");
       printf (" %6d     %4.1f     %4.1f   %4.1f   %4.1f",
               round_trip.count,
               round_trip.average,
               round_trip.min,
               round_trip.max,
               std_dev (round_trip));

 
       /* Close it all up */
       
       result = s->delete_datareader (ackmessage_reader);
       result = p->delete_datawriter (pubmessage_writer);
       result = p->delete_datawriter (pubmessage_nest_writer);

       
       // @@Note: a Subscriber cannot be deleted if it has any attached DataReader object
       //         so the following operation has to be performed *AFTER* delete_datareader ()
       //         Same with Publisher
       result = dp->delete_subscriber (s);
       result = dp->delete_publisher (p);

       
       result = dp->delete_topic (pubmessage_topic);
       result = dp->delete_topic (ackmessage_topic);
       result = dp->delete_topic (pubmessage_nest_topic);
       result = dpf->delete_participant (dp);
              
       return(0);

}
