/* HelloWorld_publisher.cxx

   A publication of data of type HelloWorld

   This file is derived from code automatically generated by the nddsgen 
   command:

   nddsgen -language C++ -example i86Linux2.6gcc3.4.3  HelloWorld.idl

   Example publication of type HelloWorld automatically generated by 
   'nddsgen' To test them follow these steps:

   (1) Compile this file and the example subscription.

   (2) Start the subscription on the same domain used for NDDS with the command
       objs/i86Linux2.6gcc3.4.3/HelloWorld_subscriber 
       		<domain_id> <participant_index> <sample_count>
                
   (3) Start the publication on the same domain used for NDDS with the command
       objs/i86Linux2.6gcc3.4.3/HelloWorld_publisher 
       		<domain_id> <participant_index> <sample_count>

   (4) To run on the same host (and same domain), use a different 
       participant_index for the subscriber and publisher.

   (5) [Optional] Specify the list of discovery initial peers and 
       multicast receive addresses via an environment variable or a file 
       (in the current working directory) called NDDS_DISCOVERY_PEERS. 
       
   You can run any number of publishers and subscribers programs, and can 
   add and remove them dynamically from the domain.

                                   
   Example:
        
       To run the example application on domain <domain_id>:
        
       NOTE: To run multiple applications on a host, belonging to the same
       domain, specify a different <participant_index> for each one of them.
       Note that the <participant_index> can be 0 if the participants in a
       domain are on on different hosts.
                          
       On Unix: 
       
       objs/i86Linux2.6gcc3.4.3/HelloWorld_publisher <domain_id> 
       objs/i86Linux2.6gcc3.4.3/HelloWorld_subscriber <domain_id> 
                            
       On Windows:
       
       objs\i86Linux2.6gcc3.4.3\HelloWorld_publisher <domain_id>  
       objs\i86Linux2.6gcc3.4.3\HelloWorld_subscriber <domain_id>    

       
modification history
------------ -------       
*/

#include <stdio.h>
#include <stdlib.h>
#include "ndds/ndds_cpp.h"
#include "HelloWorld.h"
#include "HelloWorldSupport.h"

/* Delete all entities */
static int publisher_shutdown(
    DDSDomainParticipant *participant,
    DDSPublisher *publisher,
    DDSTopic *topic,
    DDSDataWriter *writer)
{
    DDS_ReturnCode_t retcode;
    int status = 0;

    if (writer != NULL) {
        retcode = publisher->delete_datawriter(writer);
        if (retcode != DDS_RETCODE_OK) {
            printf("delete_datawriter error %d\n", retcode);
            status = -1;
        }
    }

    if (topic != NULL) {
        retcode = participant->delete_topic(topic);
        if (retcode != DDS_RETCODE_OK) {
            printf("delete_topic error %d\n", retcode);
            status = -1;
        }
    }

    if (publisher != NULL) {
        retcode = participant->delete_publisher(publisher);
        if (retcode != DDS_RETCODE_OK) {
            printf("delete_publisher error %d\n", retcode);
            status = -1;
        }
    }

    if (participant != NULL) {
        retcode = DDSTheParticipantFactory->delete_participant(participant);
        if (retcode != DDS_RETCODE_OK) {
            printf("delete_participant error %d\n", retcode);
            status = -1;
        }
    }

    /* NDDS provides finalize_instance() method for people who want to release
       memory used by the participant factory singleton.
       Uncomment the following block of code for clean destruction of
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

extern "C" int publisher_main(
    int domainId, int participant_index, int sample_count)
{
    DDS_DomainParticipantQos participant_qos;
    DDSDomainParticipant *participant = NULL;
    DDSPublisher *publisher = NULL;
    DDSTopic *topic = NULL;
    DDSDataWriter *writer = NULL;
    HelloWorldDataWriter *HelloWorld_writer = NULL;
    HelloWorld *instance = NULL;
    DDS_ReturnCode_t retcode;
    DDS_InstanceHandle_t instance_handle = DDS_HANDLE_NIL;
    const char *type_name = NULL;
    int count = 0;  
    struct DDS_Duration_t send_period = {4,0};

    /* Get default participant QoS to customize */
    retcode = DDSTheParticipantFactory->get_default_participant_qos(
        participant_qos);
    if (retcode != DDS_RETCODE_OK) {
        printf("get_default_participant_qos error %d\n", retcode);
        publisher_shutdown(participant, publisher, topic, writer);
        return -1;
    }

    /* Customize discovery qos policy in participant QoS */
    participant_qos.discovery.participant_index = participant_index;


    /* To create participant with default QoS, use DDS_PARTICIPANT_QOS_DEFAULT
       instead */
    participant = DDSTheParticipantFactory->create_participant(
        domainId, participant_qos, NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (participant == NULL) {
        printf("create_participant error\n");
        publisher_shutdown(participant, publisher, topic, writer);
        return -1;
    }

    /* To customize publisher QoS, use
       participant->get_default_publisher_qos() instead */
    publisher = participant->create_publisher(
        DDS_PUBLISHER_QOS_DEFAULT, NULL /* listener */, DDS_STATUS_MASK_NONE);
    if (publisher == NULL) {
        printf("create_participant error\n");
        publisher_shutdown(participant, publisher, topic, writer);
        return -1;
    }

    /* Register type before creating topic */
    type_name = HelloWorldTypeSupport::get_type_name();
    retcode = HelloWorldTypeSupport::register_type(
        participant, type_name);
    if (retcode != DDS_RETCODE_OK) {
        printf("register_type error %d\n", retcode);
        publisher_shutdown(participant, publisher, topic, writer);
        return -1;
    }

    /* To customize topic QoS, use
       participant->get_default_topic_qos() instead */
    topic = participant->create_topic(
        "Example HelloWorld",
        type_name, DDS_TOPIC_QOS_DEFAULT, NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (topic == NULL) {
        printf("create_topic error\n");
        publisher_shutdown(participant, publisher, topic, writer);
        return -1;
    }

    /* To customize data writer QoS, use
       publisher->get_default_datawriter_qos() instead */
    writer = publisher->create_datawriter(
        topic, DDS_DATAWRITER_QOS_DEFAULT, NULL /* listener */,
        DDS_STATUS_MASK_NONE);
    if (writer == NULL) {
        printf("create_datawriter error\n");
        publisher_shutdown(participant, publisher, topic, writer);
        return -1;
    }
    HelloWorld_writer = HelloWorldDataWriter::narrow(writer);
    if (HelloWorld_writer == NULL) {
        printf("DataWriter narrow error\n");
        publisher_shutdown(participant, publisher, topic, writer);
        return -1;
    }

    /* Create data sample for writing */
    instance = HelloWorldTypeSupport::create_data();
    if (instance == NULL) {
        printf("HelloWorldTypeSupport::create_data error\n");
        publisher_shutdown(participant, publisher, topic, writer);
        return -1;
    }

    /* For data type that has key, if the same instance is going to be
       written multiple times, initialize the key here
       and register the keyed instance prior to writing */
/*
    instance_handle = HelloWorld_writer->register_instance(*instance);
*/

    /* Main loop */
    for (count=0; (sample_count == 0) || (count < sample_count); ++count) {

        printf("Writing HelloWorld, count %d\n", count);

        /* Modify the data to be sent here */

        retcode = HelloWorld_writer->write(*instance, instance_handle);
        if (retcode != DDS_RETCODE_OK) {
            printf("write error %d\n", retcode);
        }

        NDDSUtility::sleep(send_period);
    }

/*
    retcode = HelloWorld_writer->unregister_instance(
        *instance, instance_handle);
    if (retcode != DDS_RETCODE_OK) {
        printf("unregister instance error %d\n", retcode);
    }
*/

    /* Delete data sample */
    retcode = HelloWorldTypeSupport::delete_data(instance);
    if (retcode != DDS_RETCODE_OK) {
        printf("HelloWorldTypeSupport::delete_data error %d\n", retcode);
    }

    /* Delete all entities */
    return publisher_shutdown(participant, publisher, topic, writer);
}

#if !defined(RTI_VXWORKS) && !defined(RTI_PSOS)
int main(int argc, char *argv[])
{
    int domainId = 0;
    int participant_index = 0;
    int sample_count = 0; /* infinite loop */

    if (argc >= 2) {
        domainId = atoi(argv[1]);
    }
    if (argc >= 3) {
        participant_index = atoi(argv[2]);
    }
    if (argc >= 4) {
        sample_count = atoi(argv[3]);
    }

    /* Uncomment this to turn on additional logging
    NDDSConfigLogger::get_instance()->
        set_verbosity_by_category(NDDS_CONFIG_LOG_CATEGORY_API, 
                                  NDDS_CONFIG_LOG_VERBOSITY_STATUS_ALL);
    */
    
    return publisher_main(domainId, participant_index, sample_count);
}
#endif
