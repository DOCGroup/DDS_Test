/* $Id$

   Quoter_subscriber.cxx

   A subscription and republish example

   This file is derived from code automatically generated by the nddsgen 
   command:

   nddsgen -language C++ -example <arch> Quoter.idl

   HOWEVER, this code has been changed so that it not only subscriber to
   stock quote values but also filters these to determine max and min
   and then publishes these values. Dynamic content filtered topics are
   used to subscribe to new max and min values.

   Example subscription of type Quoter automatically generated by 
   'nddsgen'. To test them follow these steps:

   (1) Compile this file and the example publication.

   (2) Start the subscription on the same domain used for RTI Data Distribution
       Service with the command
       objs/<arch>/Quoter_subscriber <domain_id> <sample_count>

   (3) Start the publication on the same domain used for RTI Data Distribution
       with the command
       objs/<arch>/Quoter_publisher <domain_id> <sample_count>

   (4) [Optional] Specify the list of discovery initial peers and 
       multicast receive addresses via an environment variable or a file 
       (in the current working directory) called NDDS_DISCOVERY_PEERS. 
       
   You can run any number of publishers and subscribers programs, and can 
   add and remove them dynamically from the domain.
              
                                   
   Example:
        
       To run the example application on domain <domain_id>:
                          
       On Unix: 
       
       objs/<arch>/Quoter_publisher <domain_id> 
       objs/<arch>/Quoter_subscriber <domain_id> 
                            
       On Windows:
       
       objs\<arch>\Quoter_publisher <domain_id>  
       objs\<arch>\Quoter_subscriber <domain_id>   
              
       
modification history
------------ -------       
*/

#include <stdio.h>
#include <stdlib.h>
#include "ndds/ndds_cpp.h"
#include "Quoter.h"
#include "QuoterSupport.h"

// jhoffert - Added includes
#include <iostream>
#include <sstream>
//#include "ndds/dds_cpp/dds_cpp_infrastructure.h"

class QuoterListener : public DDSDataReaderListener
{
public:
  QuoterListener(DDSGuardCondition *guard);

  ~QuoterListener();

    virtual void on_requested_deadline_missed(DDSDataReader* /*reader*/,
        const DDS_RequestedDeadlineMissedStatus& /*status*/) {}
    
    virtual void on_requested_incompatible_qos(DDSDataReader* reader,
        const DDS_RequestedIncompatibleQosStatus& status);
    
    virtual void on_sample_rejected(DDSDataReader* /*reader*/,
        const DDS_SampleRejectedStatus& /*status*/) {}

    virtual void on_liveliness_changed(DDSDataReader* /*reader*/,
        const DDS_LivelinessChangedStatus& /*status*/) {}

    virtual void on_sample_lost(DDSDataReader* /*reader*/,
        const DDS_SampleLostStatus& /*status*/) {}

    virtual void on_subscription_matched(DDSDataReader* /*reader*/,
        const DDS_SubscriptionMatchedStatus& /*status*/) {}

    virtual void on_data_available(DDSDataReader* reader);

  void set_guard_condition(DDS_Boolean value);

private:

  DDSGuardCondition *guard_;
};

QuoterListener::QuoterListener(DDSGuardCondition *guard)
  : guard_(guard)
{
}

QuoterListener::~QuoterListener()
{
}

void QuoterListener::set_guard_condition(DDS_Boolean value)
{
  guard_->set_trigger_value(value);
}

void QuoterListener::on_requested_incompatible_qos(DDSDataReader*,
                const DDS_RequestedIncompatibleQosStatus& status)
{
  std::cerr << "Incompatible QoS Requested" << std::endl;
}

void QuoterListener::on_data_available(DDSDataReader* reader)
{
  QuoterSeq data_seq;
  DDS_SampleInfoSeq info_seq;
  DDS_ReturnCode_t retcode;
  int i;
  static bool updatedOnce = false;

  QuoterDataReader *quoter_reader = QuoterDataReader::narrow(reader);
  if (quoter_reader == NULL)
    {
      printf("DataReader narrow error\n");
      return;
    }

  set_guard_condition(DDS_BOOLEAN_TRUE);
}

/* Delete all entities */
static int subscriber_shutdown(DDSDomainParticipant *participant)
{
    DDS_ReturnCode_t retcode;
    int status = 0;

    if (participant != NULL) {
        retcode = participant->delete_contained_entities();
        if (retcode != DDS_RETCODE_OK) {
            printf("delete_contained_entities error %d\n", retcode);
            status = -1;
        }

        retcode = DDSTheParticipantFactory->delete_participant(participant);
        if (retcode != DDS_RETCODE_OK) {
            printf("delete_participant error %d\n", retcode);
            status = -1;
        }
    }

    /* RTI Data Distribution Service provides finalize_instance() method for
       people who want to release memory used by the participant factory
       singleton. Uncomment the following block of code for clean destruction of
       the participant factory singleton. */
/*
    retcode = DDSDomainParticipantFactory::finalize_instance();
    if (retcode != DDS_RETCODE_OK) {
        printf("finalize_instance error %d\n", retcode);
        status = -1;
    }
*/
    return status;
}

static int handle_new_minmax(DDSDataReader* reader)
{
  QuoterDataReader *Quoter_reader = NULL;
  QuoterSeq data_seq;
  DDS_SampleInfoSeq info_seq;
  DDS_ReturnCode_t retcode;
  int i;
  static bool updatedOnce = false;

  Quoter_reader = QuoterDataReader::narrow(reader);
  if (Quoter_reader == NULL)
    {
      printf("DataReader narrow error\n");
      return -1;
    }

  retcode = Quoter_reader->take(data_seq,
                                info_seq,
                                DDS_LENGTH_UNLIMITED,
                                DDS_ANY_SAMPLE_STATE,
                                DDS_ANY_VIEW_STATE,
                                DDS_ANY_INSTANCE_STATE);

  if (retcode == DDS_RETCODE_NO_DATA)
    {
      return -1;
    }
  else if (retcode != DDS_RETCODE_OK)
    {
      printf("take error %d\n", retcode);
      return -1;
    }

  DDS_StringSeq filterParams;
  //DDS_StringSeq filterParams(2);
  //filterParams.ensure_length(2, 2);
  for (i = 0; i < data_seq.length(); ++i)
    {
      if (info_seq[i].valid_data)
        {
          // If we have values here then we either have a new maximum
          // or a new minimum. (Maybe this should be split out separately?)
          // Reset the new max or min and publish the data.
          //QuoterTypeSupport::print_data(&data_seq[i]);
          // Print out the values here
          std::cout << "Index  = " << i << std::endl;
          std::cout << "New max/min price for " << data_seq[i].symbol << " = "
                    << data_seq[i].price << std::endl;

          //DDSContentFilteredTopic *filteredTopic =
          //    dynamic_cast<DDSContentFilteredTopic *>(topicDesc);

          DDSTopicDescription *topicDesc = reader->get_topicdescription();
          DDSContentFilteredTopic *filteredTopic =
            DDSContentFilteredTopic::narrow(topicDesc);
          if (filteredTopic == NULL)
            {
              std::cerr << "Filtered Topic narrow error" << std::endl;
              return -1;
            }
          std::cout << "Before call to get_expression_parameters"
                    << std::endl;
          filteredTopic->get_expression_parameters(filterParams);

          std::cout << "Getting Filter Params[0] == "
                    << filterParams[0] << std::endl;
          std::cout << "Getting Filter Params[1] == "
                    << filterParams[1] << std::endl;

          // Figure out if new max or new min has been set.
          std::string lastMaxStr = filterParams[0];
          double lastMax = ::atof(lastMaxStr.c_str());
          std::cout << "Last Max value = " << lastMax << std::endl;
          std::ostringstream newPriceStr;
          newPriceStr << data_seq[i].price;
          if (lastMax < data_seq[i].price)
            {
              filterParams[0] = DDS_String_dup(newPriceStr.str().c_str());
              std::cout << "resetting max filter param to "
                        << filterParams[0] << std::endl;

              // Do a one-time check to see if the current minimum has ever
              // been updated. If not then update it with the new value
              // (which will also be the new max since the initial values
              // are -1).
              if (!updatedOnce)
                {
                  updatedOnce = true;
                  filterParams[1] = DDS_String_dup(newPriceStr.str().c_str());
                  std::cout << "resetting min filter param to "
                            << filterParams[1] << std::endl;
                }
            }
          else // new minimum
            {
              filterParams[1] = DDS_String_dup(newPriceStr.str().c_str());
              std::cout << "resetting min filter param to "
                        << filterParams[1] << std::endl;
            }

          // Reset the filter to use the new maximum value.
          std::cout << "Setting Filter Params[0] == "
                    << filterParams[0] << std::endl;
          std::cout << "Setting Filter Params[1] == "
                    << filterParams[1] << std::endl;
          filteredTopic->set_expression_parameters(filterParams);
        }
    }

  retcode = Quoter_reader->return_loan(data_seq, info_seq);
  if (retcode != DDS_RETCODE_OK)
    {
      printf("return loan error %d\n", retcode);
    }
}

extern "C" int subscriber_main(int domainId, int sample_count)
{
    DDSDomainParticipant *participant = NULL;
    DDSSubscriber *subscriber = NULL;
    DDSTopic *topic = NULL;
    QuoterListener *reader_listener = NULL; 
    DDSDataReader *reader = NULL;
    DDS_ReturnCode_t retcode;
    const char *type_name = NULL;
    int count = 0;
    //struct DDS_Duration_t receive_period = {4,0};
    int status = 0;
    // jhoffert - Additions
    const int MAX_NUM_SAMPLES = 1000;
    const char *filteredTopicBaseName = "Max Min Quoter";
    // Filter expression to handle maximum and minimum.
    const std::string filterExpr("(price > %0) or (price < %1)");
    // Filter expression to handle maximum.
    //const std::string filterExpr("price > %0");

    /* To customize participant QoS, use 
       DDSTheParticipantFactory->get_default_participant_qos()
       instead */
    participant =
      DDSTheParticipantFactory->create_participant(domainId,
                                                   DDS_PARTICIPANT_QOS_DEFAULT,
                                                   NULL /* listener */,
                                                   DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        printf("create_participant error\n");
        subscriber_shutdown(participant);
        return -1;
    }

    /* To customize subscriber QoS, use
       participant->get_default_subscriber_qos() instead */
    subscriber =
      participant->create_subscriber(DDS_SUBSCRIBER_QOS_DEFAULT,
                                     NULL /* listener */,
                                     DDS_STATUS_MASK_NONE);
    if (subscriber == NULL) {
        printf("create_subscriber error\n");
        subscriber_shutdown(participant);
        return -1;
    }

    /* Register type before creating topic */
    type_name = QuoterTypeSupport::get_type_name();
    retcode = QuoterTypeSupport::register_type(participant,
                                               type_name);
    if (retcode != DDS_RETCODE_OK) {
        printf("register_type error %d\n", retcode);
        subscriber_shutdown(participant);
        return -1;
    }

    /* To customize topic QoS, use
       participant->get_default_topic_qos() instead */
    topic = participant->create_topic("Example Quoter",
                                      type_name,
                                      DDS_TOPIC_QOS_DEFAULT,
                                      NULL /* listener */,
                                      DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        printf("create_topic error\n");
        subscriber_shutdown(participant);
        return -1;
    }

    // jhoffert - Create content filtered topic
    std::string filteredTopicName(filteredTopicBaseName);
    std::ostringstream pidStr;
    long id = ::getpid();
    pidStr << id;
    filteredTopicName += pidStr.str().c_str();
    DDS_StringSeq filterParams(2);
    filterParams.ensure_length(2, 2);
    std::ostringstream defPriceStr;
    defPriceStr << -1;
    filterParams[0] = DDS_String_dup(defPriceStr.str().c_str());
    filterParams[1] = DDS_String_dup(defPriceStr.str().c_str());

    // START DEBUG
    std::cout << "pid = " << id << std::endl;
    std::cout << "pidStr = " << pidStr << std::endl;
    std::cout << "filteredTopicName = " << filteredTopicName << std::endl;
    std::cout << "filterExpr = " << filterExpr << std::endl;
    std::cout << "filterParams[0] = " << filterParams[0] << std::endl;
    std::cout << "filterParams[1] = " << filterParams[1] << std::endl;
    // END DEBUG
    DDSContentFilteredTopic *filteredTopic =
      participant->create_contentfilteredtopic(filteredTopicName.c_str(),
                                               topic,
                                               filterExpr.c_str(),
                                               filterParams,
                                               DDS_SQLFILTER_NAME);

    /* Create data reader listener */
    DDSGuardCondition guard_cond;
    reader_listener = new QuoterListener(&guard_cond);
    if (reader_listener ==  NULL) {
        printf("listener instantiation error\n");
        subscriber_shutdown(participant);
        return -1;
    }

    // jhoffert - Adding QoS policies to save history of values
    DDS_DataReaderQos default_datareader_qos;
    subscriber->get_default_datareader_qos(default_datareader_qos);
    default_datareader_qos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;
    default_datareader_qos.durability.kind =
      DDS_TRANSIENT_LOCAL_DURABILITY_QOS;
    default_datareader_qos.history.kind = DDS_KEEP_ALL_HISTORY_QOS;
    default_datareader_qos.resource_limits.max_samples = MAX_NUM_SAMPLES;
    subscriber->set_default_datareader_qos(default_datareader_qos);

    /* To customize data reader QoS, use
       subscriber->get_default_datareader_qos() instead */
    reader = subscriber->create_datareader(filteredTopic,
                                           DDS_DATAREADER_QOS_DEFAULT,
                                           reader_listener,
                                           DDS_STATUS_MASK_ALL);
    if (reader == NULL) {
        printf("create_datareader error\n");
        subscriber_shutdown(participant);
        delete reader_listener;
        return -1;
    }

    // Create a waitset for when a new minimum or maximum is received.
    DDSWaitSet waitset;

    retcode = waitset.attach_condition(&guard_cond);
    if (retcode != DDS_RETCODE_OK)
      {
        std::cerr << "Error attaching guard condition, retcode = "
                  << retcode << std::endl;
        return -1;
      }

    /* Main loop */
    //DDS_Duration_t timeout = {0, 1000000};  // 1 ms
    DDS_Duration_t waitset_timeout = {1, 0};  // 1 s
    DDSConditionSeq active_conditions;

    for (count=0; (sample_count == 0) || (count < sample_count); ++count)
      {
        retcode = waitset.wait(active_conditions,
                               waitset_timeout);
        if (retcode != DDS_RETCODE_OK &&
            retcode != DDS_RETCODE_TIMEOUT)
          {
            std::cerr << "Error waiting on waitset, retcode = "
                      << retcode << std::endl;
            return -1;
          }

        //if (active_conditions.length() == 0)
        if (retcode == DDS_RETCODE_TIMEOUT)
          {
            std::cout << "Waitset timed out...no conditions triggered"
                      << std::endl;
          }
        else
          {
            // We only have one condition - the guard condition set by
            // the listener when new data arrives. Reset the guard condition
            // and then calculate the min or max value.
            reader_listener->set_guard_condition(DDS_BOOLEAN_FALSE);
            handle_new_minmax(reader);
          }

//         printf("Quoter subscriber sleeping for %d sec...\n",
//                receive_period.sec);

//         NDDSUtility::sleep(receive_period);
      }

    /* Delete all entities */
    status = subscriber_shutdown(participant);
    delete reader_listener;

    return status;
}

#if !defined(RTI_VXWORKS) && !defined(RTI_PSOS)
int main(int argc, char *argv[])
{
    int domainId = 0;
    int sample_count = 0; /* infinite loop */

    if (argc >= 2) {
        domainId = atoi(argv[1]);
    }
    if (argc >= 3) {
        sample_count = atoi(argv[2]);
    }

    /* Uncomment this to turn on additional logging
    NDDSConfigLogger::get_instance()->
        set_verbosity_by_category(NDDS_CONFIG_LOG_CATEGORY_API, 
                                  NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);
    */
                                  
    return subscriber_main(domainId, sample_count);
}
#endif

