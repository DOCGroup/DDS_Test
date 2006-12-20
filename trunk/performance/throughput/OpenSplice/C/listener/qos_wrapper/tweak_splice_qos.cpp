// Author: Hieu Nguyen
// June 19th, 2006

#ifndef __TWEAK_SPLICE_QOS_CPP
#define __TWEAK_SPLICE_QOS_CPP

#include "tweak_splice_qos.h"
#include <iostream>
#include <string>
#include "dds_config_file.h"
#include "qos_file_format.h"

using std::string;
using namespace QosFormat;


string getsec (const string duration_str)
{  
  unsigned comma_pos = duration_str.find (',');

  if (comma_pos == string::npos) {
    printf ("Could not parse duration %s.\n", duration_str.c_str());
    return "";
  }

  string sec (duration_str, 0, comma_pos);  
  return sec;
}

string getnanosec (const string duration_str)
{  
  unsigned comma_pos = duration_str.find (',');

  if (comma_pos == string::npos) {
    printf ("Could not parse duration %s.\n", duration_str.c_str());
    return "";
  }

  string nanosec (duration_str, comma_pos + 1, string::npos);  
  return nanosec;
}

bool dds_get_time (const string duration_str, DDS_Duration_t &dds_duration)
{
  string tempsec = getsec (duration_str);
  string tempnanosec = getnanosec (duration_str);
  char *stop_str;
  if (tempsec != "" && tempnanosec != "") {
    if ((dds_duration.sec = atol (tempsec.c_str())) == 0)
      return false;
    if ((dds_duration.nanosec = strtoul (tempnanosec.c_str(), &stop_str, 0))== 0)
      return false;
    return true;
  }
  else
    return false;
}


// ----------------------------------------------------------------------------
// TweakSpliceQos member functions
// ----------------------------------------------------------------------------

TweakSpliceQos::~TweakSpliceQos (void)
{

}


// Qos Policies for Domain Participant:
//   user_data
//   entity_factory
void 
TweakSpliceQos::setDomainParticipantQos (DDS_DomainParticipantQos &dpQos)
{
  
}


// Qos Policies for Topic:
//   topic_data
//   durability
//   durability_service
//   deadline
//   latency_budget
//   liveliness
//   reliability
//   destination_order
//   history
//   resource_limits
//   transport_priority
//   lifespan
//   ownership
void 
TweakSpliceQos::setTopicQos (DDS_TopicQos &tQos)
{
  if (this->qos_hash_ != 0) {
    string QosFound;
    DDS_Duration_t timeval;
    DDS_long val;

    QosFound = this->qos_hash_->get (TopicQosKeys::get_durability_kind_key ());
    if (QosFound.compare ("") != 0) {    
      if (QosFound.compare ("volatile") == 0) 
      {
	tQos.durability.kind = DDS_VOLATILE_DURABILITY_QOS;    
	printf ("TweakSpliceQos::setTopicQos: Topic's durability set to VOLATILE.\n");
      }
      else if (QosFound.compare ("transient") == 0) 
      {
	tQos.durability.kind = DDS_TRANSIENT_DURABILITY_QOS;
	printf ("TweakSpliceQos::setTopicQos: Topic's durability set to TRANSIENT.\n");
      }
      else if (QosFound.compare ("transient_local") ==0) 
      {
	tQos.durability.kind = DDS_TRANSIENT_LOCAL_DURABILITY_QOS;
	printf ("TweakSpliceQos::setTopicQos: Topic's durability set to TRANSIENT_LOCAL.\n");
      }
      else if (QosFound.compare ("persistent") == 0) 
      {
	tQos.durability.kind = DDS_PERSISTENT_DURABILITY_QOS;
	printf ("TweakSpliceQos::setTopicQos: Topic's durability set to PERSISTENT.\n");
      }
      else
	printf ("TweakSpliceQos::setTopicQos: unknown durability kind.\n");
    }

    QosFound = this->qos_hash_->get (TopicQosKeys::get_durability_service_cleanup_delay_key ());
    if (QosFound.compare ("") != 0) {
      if (dds_get_time (QosFound, timeval)) 
      {
	tQos.durability_service.service_cleanup_delay = timeval;
	printf ("TweakSpliceQos::setTopicQos: Topic's service_cleanup_delay set.\n");
      }
      else
	printf ("TweakSpliceQos::setTopicQos: service_cleanup_delay - unknown time format.\n");
    }


    QosFound = this->qos_hash_->get (TopicQosKeys::get_deadline_key ());
    if (QosFound.compare ("") != 0) {
      if (dds_get_time (QosFound, timeval)) 
      {
	tQos.deadline.period = timeval;
	printf ("TweakSpliceQos::setTopicQos: Topic's deadline set.\n");
      }
      else
	printf ("TweakSpliceQos::setTopicQos: deadline - unknown time format.\n");
    }

    QosFound = this->qos_hash_->get (TopicQosKeys::get_latency_budget_key ());
    if (QosFound.compare ("") != 0) {
      if (dds_get_time (QosFound, timeval)) 
      {
	tQos.latency_budget.duration = timeval;
	printf ("TweakSpliceQos::setTopicQos: Topic's latency_budget set.\n");
      }
      else
	printf ("TweakSpliceQos::setTopicQos: latency_budget - unknown time format.\n");
    }


    QosFound = this->qos_hash_->get (TopicQosKeys::get_reliability_kind_key ());
    if (QosFound.compare ("") != 0) {    
      if (QosFound.compare ("best_effort") == 0)
      {
	tQos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;    
	printf ("TweakSpliceQos::setTopicQos: Topic's reliability set to BEST_EFFORT.\n");
      }
      else if (QosFound.compare ("reliable") == 0)
      {
	tQos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;    
	printf ("TweakSpliceQos::setTopicQos: Topic's reliability set to RELIABLE.\n");
      }
      else
	printf ("TweakSpliceQos::setTopicQos: unknown reliablity kind.\n");
    }

    QosFound = this->qos_hash_->get (TopicQosKeys::get_reliability_max_blocking_time_key ());
    if (QosFound.compare ("") != 0) {
      if (dds_get_time (QosFound, timeval))      
      {
	tQos.reliability.max_blocking_time = timeval;
	printf ("TweakSpliceQos::setTopicQos: Topic's max_blocking_time set.\n");
      }
      else
	printf ("TweakSpliceQos::setTopicQos: max_blocking time - unknown time format.\n");
    }


    QosFound = this->qos_hash_->get (TopicQosKeys::get_resource_limits_max_samples_key ());
    if (QosFound.compare ("") != 0) {
      if ((val = atol (QosFound.c_str())) == 0)
	printf ("TweakSpliceQos::setTopicQos: cannot convert max_samples.\n");
      else
      {
	tQos.resource_limits.max_samples = val;
	printf ("TweakSpliceQos::setTopicQos: Topic's max_samples set to %lu.\n", val);
      }
    }
        

    QosFound = this->qos_hash_->get (TopicQosKeys::get_resource_limits_max_instances_key ());
    if (QosFound.compare ("") != 0) {
      if ((val = atol (QosFound.c_str())) == 0)      
	printf ("TweakSpliceQos::setTopicQos: cannot conver max_instances.\n");	
      else
      {
	tQos.resource_limits.max_instances = val;
        printf ("TweakSpliceQos::setTopicQos: Topic's max_instances set to %lu.\n", val);
      }
    }
        


    QosFound = this->qos_hash_->get (TopicQosKeys::get_resource_limits_max_samples_per_instance_key ());
    if (QosFound.compare ("") != 0) {
      if ((val = atol (QosFound.c_str())) == 0)
	printf ("TweakSpliceQos::setTopicQos: cannot convert max_samples_per_instance.\n");
      else
      {
	tQos.resource_limits.max_samples_per_instance = val;
	printf ("TweakSpliceQos::setTopicQos: Topic's max_samples_per_instance set to %lu.\n", val);
      }
    }



    QosFound = this->qos_hash_->get (TopicQosKeys::get_history_kind_key ());
    if (QosFound.compare ("") != 0) {    
      if (QosFound.compare ("keep_last") == 0)
      {
	tQos.history.kind = DDS_KEEP_LAST_HISTORY_QOS;    
	printf ("TweakSpliceQos::setTopicQos: Topic's history set to KEEP_LAST.\n");
      }
      else if (QosFound.compare ("keep_all") == 0)
      {
	tQos.history.kind = DDS_KEEP_ALL_HISTORY_QOS;    
	printf ("TweakSpliceQos::setTopicQos: Topic's history set to KEEP_ALL.\n");
      }
      else
	printf ("TweakSpliceQos::setTopicQos: unknown history kind.\n");
    }


    QosFound = this->qos_hash_->get (TopicQosKeys::get_ownership_key ());
    if (QosFound.compare ("") != 0) {
      if (QosFound.compare ("shared") == 0)
      {
	tQos.ownership.kind = DDS_SHARED_OWNERSHIP_QOS;
	printf ("TweakSpliceQos::setTopicQos: Topic's ownership set to SHARED.\n");
      }
      else if (QosFound.compare ("exclusive") == 0)
      {
	tQos.ownership.kind = DDS_EXCLUSIVE_OWNERSHIP_QOS;
	printf ("TweakSpliceQos::setTopicQos: Topic's ownership set to EXCLUSIVE.\n");
      }
      else
	printf ("TweakSpliceQos::setTopicQos: unknown ownership kind.\n");
    }

    QosFound = this->qos_hash_->get (TopicQosKeys::get_liveliness_kind_key ());
    if (QosFound.compare ("") != 0) {
      if (QosFound.compare ("automatic") == 0)
      {
	tQos.liveliness.kind = DDS_AUTOMATIC_LIVELINESS_QOS;
	printf ("TweakSpliceQos::setTopicQos: Topic's liveliness set to AUTOMATIC.\n");
      }
      else if (QosFound.compare ("manual_by_participant") == 0)
      {
	tQos.liveliness.kind = DDS_MANUAL_BY_PARTICIPANT_LIVELINESS_QOS;
	printf ("TweakSpliceQos::setTopicQos: Topic's liveliness set to MANUAL_BY_PARTICIPANT.\n");
      }
      else if (QosFound.compare ("manual_by_topic") == 0)
      {
	tQos.liveliness.kind = DDS_MANUAL_BY_TOPIC_LIVELINESS_QOS;
	printf ("TweakSpliceQos::setTopicQos: Topic's liveliness set to MANUAL_BY_TOPIC.\n");
      }
      else
	printf ("TweakSpliceQos::setTopicQos: unknown liveliness kind.\n");
    }

    QosFound = this->qos_hash_->get (TopicQosKeys::get_liveliness_lease_duration_key ());
    if (QosFound.compare ("") != 0) {
      if (dds_get_time (QosFound, timeval))       
      {
	tQos.liveliness.lease_duration = timeval;
	printf ("TweakSpliceQos::setTopicQos: Topic's liveliness.lease_duration set to %lu.\n", val);
      }
      else
	printf ("TweakSpliceQos::setTopicQos: lease_duration - unknown time format.\n");
    }

    QosFound = this->qos_hash_->get (TopicQosKeys::get_lifespan_key ());
    if (QosFound.compare ("") != 0) {
      if (dds_get_time (QosFound, timeval))       
      {
	tQos.lifespan.duration = timeval;
	printf ("TweakSpliceQos::setTopicQos: Topic's lifespan set to %lu.\n", val);
      }
      else
	printf ("TweakSpliceQos::setTopicQos: life_span - unknown time format.\n");
    }
  }
}


// Qos Policies for Publisher:
//   presentation
//   partition
//   group data
//   entity_factory
void 
TweakSpliceQos::setPublisherQos (DDS_PublisherQos &pQos)
{
  if (this->qos_hash_ != 0) {
    string QosFound;

    QosFound = this->qos_hash_->get (PublisherQosKeys::get_presentation_access_scope_key ());
    if (QosFound.compare ("") != 0) {
      if (QosFound.compare ("instance") == 0)
      {
	pQos.presentation.access_scope = DDS_INSTANCE_PRESENTATION_QOS;
	printf ("TweakSpliceQos::setPublisherQos: Publisher's access_scope set to INSTANCE.\n");
      }
      else if (QosFound.compare ("topic") == 0) 
      {
	pQos.presentation.access_scope = DDS_TOPIC_PRESENTATION_QOS;
	printf ("TweakSpliceQos::setPublisherQos: Publisher's access_scope set to TOPIC.\n");
      }
      else if (QosFound.compare ("group") == 0)
      {
	pQos.presentation.access_scope = DDS_GROUP_PRESENTATION_QOS;
	printf ("TweakSpliceQos::setPublisherQos: Publisher's access_scope set to GROUP.\n");
      }
      else
	printf ("TweakSpliceQos::setPublisherQos: unknown access_scope.\n");
    }

    QosFound = this->qos_hash_->get (PublisherQosKeys::get_presentation_coherent_access_key ());    
    if (QosFound.compare ("") != 0) {
      if (QosFound.compare ("true") == 0)
      {
	pQos.presentation.coherent_access = TRUE;
	printf ("TweakSpliceQos::setPublisherQos: Publisher's coherent_access is enabled.\n");
      }
      else if (QosFound.compare ("false") == 0)
      {
	pQos.presentation.coherent_access = FALSE;
	printf ("TweakSpliceQos::setPublisherQos: Publisher's coherent_access is disabled.\n");
      }
      else
	printf ("TweakSpliceQos::setPublisherQos: coherent_access assigned to unknown boolean type (true/false).\n");
    }



    QosFound = this->qos_hash_->get (PublisherQosKeys::get_presentation_ordered_access_key ());    
    if (QosFound.compare ("") != 0) {
      if (QosFound.compare ("true") == 0) 
      {
	pQos.presentation.ordered_access = TRUE;
	printf ("TweakSpliceQos::setPublisherQos: Publisher's order_access is enabled.\n");
      }
      else if (QosFound.compare ("false") == 0)
      {
	pQos.presentation.ordered_access = FALSE;
	printf ("TweakSpliceQos::setPublisherQos: Publisher's order_access is disabled.\n");
      }
      else
	printf ("TweakSpliceQos::setPublisherQos: ordered_access assigned to unknown boolean type (true/false).\n");
    }
  }
}


// Qos Policies for Subscriber:
//   presentation
//   partition
//   group data
//   entity_factory
void 
TweakSpliceQos::setSubscriberQos (DDS_SubscriberQos &sQos)
{
  if (this->qos_hash_ != 0) {
    string QosFound;

    QosFound = this->qos_hash_->get (SubscriberQosKeys::get_presentation_access_scope_key ());
    if (QosFound.compare ("") != 0) {
      if (QosFound.compare ("instance") == 0)
      {
	sQos.presentation.access_scope = DDS_INSTANCE_PRESENTATION_QOS;
	printf ("TweakSpliceQos::setSubscriberQos: Subscriber's access_scope set to INSTANCE.\n");
      }
      else if (QosFound.compare ("topic") == 0)
      {
	sQos.presentation.access_scope = DDS_TOPIC_PRESENTATION_QOS;
	printf ("TweakSpliceQos::setSubscriberQos: Subscriber's access_scope set to TOPIC.\n");
      }
      else if (QosFound.compare ("group") == 0)
      {
	sQos.presentation.access_scope = DDS_GROUP_PRESENTATION_QOS;
	printf ("TweakSpliceQos::setSubscriberQos: Subscriber's access_scope set to GROUP.\n");
      }
      else
	printf ("TweakSpliceQos::setSubscriberQos: unknown access_scope.\n");
    }

    QosFound = this->qos_hash_->get (SubscriberQosKeys::get_presentation_coherent_access_key ());
    if (QosFound.compare ("") != 0) {
      if (QosFound.compare ("true") == 0)
      {
	sQos.presentation.coherent_access = TRUE;
	printf ("TweakSpliceQos::setSubscriberQos: Subscriber's coherent_access is enabled.\n");
      }
      else if (QosFound.compare ("false") == 0)
      {
	sQos.presentation.coherent_access = FALSE;
	printf ("TweakSpliceQos::setSubscriberQos: Subscriber's coherent_access is disabled.\n");
      }
      else
	printf ("TweakSpliceQos::setSubscriberQos: coherent_access assigned to unknown boolean type (true/false).\n");
    }



    QosFound = this->qos_hash_->get (SubscriberQosKeys::get_presentation_ordered_access_key ());
    if (QosFound.compare ("") != 0) {
      if (QosFound.compare ("true") == 0)
      {
	sQos.presentation.ordered_access = TRUE;
	printf ("TweakSpliceQos::setSubscriberQos: Subscriber's order_access is enabled.\n");
      }
      else if (QosFound.compare ("false") == 0)
      {
	sQos.presentation.ordered_access = FALSE;
	printf ("TweakSpliceQos::setSubscriberQos: Subscriber's order_access is disabled.\n");
      }
      else
	printf ("TweakSpliceQos::setSubscriberQos: ordered_access assigned to unknown boolean type (true/false).\n");
    }
  }
}


// Qos Policies for Writer:
//   durability
//   deadline
//   latency_budget
//   liveliness
//   reliability
//   destination_order
//   history
//   resource_limits
//   transport_priority
//   lifespan
//   user_data
//   ownership_strength
//   writer_data_lifecycle
void 
TweakSpliceQos::setDataWriterQos (DDS_DataWriterQos &dwQos)
{  
  if (this->qos_hash_ != 0) {
    string QosFound;
    DDS_Duration_t timeval;
    DDS_long val;

    QosFound = this->qos_hash_->get (DataWriterQosKeys::get_durability_kind_key ());
    if (QosFound.compare ("") != 0) {    
      if (QosFound.compare ("volatile") == 0)
      {
	dwQos.durability.kind = DDS_VOLATILE_DURABILITY_QOS;    
	printf ("TweakSpliceQos::setDataWriterQos: Writer's durability set to VOLATILE.\n");
      }
      else if (QosFound.compare ("transient") == 0) 
      {
	dwQos.durability.kind = DDS_TRANSIENT_DURABILITY_QOS;
	printf ("TweakSpliceQos::setDataWriterQos: Writer's durability set to TRANSIENT.\n");
      }
      else if (QosFound.compare ("transient_local") ==0)
      {
	dwQos.durability.kind = DDS_TRANSIENT_LOCAL_DURABILITY_QOS;
	printf ("TweakSpliceQos::setDataWriterQos: Writer's durability set to TRANSIENT_LOCAL.\n");
      }
      else if (QosFound.compare ("persistent") == 0)
      {
	dwQos.durability.kind = DDS_PERSISTENT_DURABILITY_QOS;
	printf ("TweakSpliceQos::setDataWriterQos: Writer's durability set to PERSISTENT.\n");
      }
      else
	printf ("TweakSpliceQos::setDataWriterQos: unknown durability kind.\n");
    }


    QosFound = this->qos_hash_->get (DataWriterQosKeys::get_deadline_key ());
    if (QosFound.compare ("") != 0) {
      if (dds_get_time (QosFound, timeval))   
      {
	dwQos.deadline.period = timeval;
	printf ("TweakSpliceQos::setDataWriterQos: Writer's deadline set.\n");
      }
      else
	printf ("TweakSpliceQos::setDataWriterQos: deadline - unknown time format.\n");
    }

    QosFound = this->qos_hash_->get (DataWriterQosKeys::get_latency_budget_key ());
    if (QosFound.compare ("") != 0) {
      if (dds_get_time (QosFound, timeval))       
      {
	dwQos.latency_budget.duration = timeval;
	printf ("TweakSpliceQos::setDataWriterQos: Writer's latency_budget set.\n");
      }
      else
	printf ("TweakSpliceQos::setDataWriterQos: latency_budget - unknown time format.\n");
    }



    QosFound = this->qos_hash_->get (DataWriterQosKeys::get_reliability_kind_key ());
    if (QosFound.compare ("") != 0) {    
      if (QosFound.compare ("best_effort") == 0)
      {
	dwQos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;    
	printf ("TweakSpliceQos::setDataWriterQos: Writer's reliability set to BEST_EFFORT.\n");
      }
      else if (QosFound.compare ("reliable") == 0)
      {
	dwQos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;    
	printf ("TweakSpliceQos::setDataWriterQos: Writer's reliability set to RELIABLE.\n");
      }
      else
	printf ("TweakSpliceQos::setDataWriterQos: unknown reliablity kind.\n");
    }

    QosFound = this->qos_hash_->get (DataWriterQosKeys::get_reliability_max_blocking_time_key ());
    if (QosFound.compare ("") != 0) {
      if (dds_get_time (QosFound, timeval))       
      {
	dwQos.reliability.max_blocking_time = timeval;
	printf ("TweakSpliceQos::setDataWriterQos: Writer's max_blocking_time set.\n");
      }
      else
	printf ("TweakSpliceQos::setDataWriterQos: max_blocking_time - unknown time format.\n");
    }


    QosFound = this->qos_hash_->get (DataWriterQosKeys::get_resource_limits_max_samples_key ());
    if (QosFound.compare ("") != 0) {
      if ((val = atol (QosFound.c_str())) == 0)
	printf ("TweakSpliceQos::setDataWriterQos: cannot convert max_samples.\n");
      else
      {
	dwQos.resource_limits.max_samples = val;
	printf ("TweakSpliceQos::setDataWriterQos: Writer's max_samples set to %lu.\n", val);
      }
    }
        

    QosFound = this->qos_hash_->get (DataWriterQosKeys::get_resource_limits_max_instances_key ());
    if (QosFound.compare ("") != 0) {
      if ((val = atol (QosFound.c_str())) == 0)
	printf ("TweakSpliceQos::setDataWriterQos: cannot conver max_instances.\n");
      else {
	dwQos.resource_limits.max_instances = val;
	printf ("TweakSpliceQos::setDataWriterQos: Writer's max_instances set to %lu.\n", val);
      }
    }
        


    QosFound = this->qos_hash_->get (DataWriterQosKeys::get_resource_limits_max_samples_per_instance_key ());
    if (QosFound.compare ("") != 0) {
      if ((val = atol (QosFound.c_str())) == 0)
	printf ("TweakSpliceQos::setDataWriterQos: cannot convert max_samples_per_instance.\n");
      else
      {
	dwQos.resource_limits.max_samples_per_instance = val;
	printf ("TweakSpliceQos::setDataWriterQos: Writer's max_samples_per_instance set to %lu.\n", val);
      }
    }



    QosFound = this->qos_hash_->get (DataWriterQosKeys::get_history_kind_key ());
    if (QosFound.compare ("") != 0) {    
      if (QosFound.compare ("keep_last") == 0)
      {
	dwQos.history.kind = DDS_KEEP_LAST_HISTORY_QOS;    
	printf ("TweakSpliceQos::setDataWriterQos: Writer's history set to KEEP_LAST.\n");
      }
      else if (QosFound.compare ("keep_all") == 0)
      {
	dwQos.history.kind = DDS_KEEP_ALL_HISTORY_QOS;    
	printf ("TweakSpliceQos::setDataWriterQos: Writer's history set to KEEP_ALL.\n");
      }
      else
	printf ("TweakSpliceQos::setDataWriterQos: unknown history kind.\n");
    }


    QosFound = this->qos_hash_->get (DataWriterQosKeys::get_history_depth_key ());
    if (QosFound.compare ("") != 0) {
      if ((val = atol (QosFound.c_str())) == 0)
	printf ("TweakSpliceQos::setDataWriterQos: cannot convert history depth.\n");
      else
      {
	dwQos.history.depth = val;
	printf ("TweakSpliceQos::setDataWriterQos: Writer's history depth set to %lu.\n", dwQos.history.depth);
      }
    }




    QosFound = this->qos_hash_->get (DataWriterQosKeys::get_liveliness_kind_key ());
    if (QosFound.compare ("") != 0) {
      if (QosFound.compare ("automatic") == 0)
      {
	dwQos.liveliness.kind = DDS_AUTOMATIC_LIVELINESS_QOS;
	printf ("TweakSpliceQos::setDataWriterQos: Writer's liveliness set to AUTOMATIC.\n");
      }
      else if (QosFound.compare ("manual_by_participant") == 0)
      {
	dwQos.liveliness.kind = DDS_MANUAL_BY_PARTICIPANT_LIVELINESS_QOS;
	printf ("TweakSpliceQos::setDataWriterQos: Writer's liveliness set to MANUAL_BY_PARTICIPANT.\n");
      }
      else if (QosFound.compare ("manual_by_topic") == 0)
      {
	dwQos.liveliness.kind = DDS_MANUAL_BY_TOPIC_LIVELINESS_QOS;
	printf ("TweakSpliceQos::setDataWriterQos: Writer's liveliness set to MANUAL_BY_TOPIC.\n");
      }
      else
	printf ("TweakSpliceQos::setDataWriterQos: unknown liveliness kind.\n");
    }

    QosFound = this->qos_hash_->get (DataWriterQosKeys::get_liveliness_lease_duration_key ());
    if (QosFound.compare ("") != 0) {
      if (dds_get_time (QosFound, timeval))       
      {
	dwQos.liveliness.lease_duration = timeval;
	printf ("TweakSpliceQos::setDataWriterQos: Writer's lease_duration set.\n");
      }
      else
	printf ("TweakSpliceQos::setDataWriterQos: lease_duration - unknown time format.\n");
    }

    QosFound = this->qos_hash_->get (DataWriterQosKeys::get_lifespan_key ());
    if (QosFound.compare ("") != 0) {
      if (dds_get_time (QosFound, timeval))       
      {
	dwQos.lifespan.duration = timeval;
	printf ("TweakSpliceQos::setDataWriterQos: Writer's lifespan set.\n");
      }
      else
	printf ("TweakSpliceQos::setDataWriterQos: lifespan - unknown time format.\n");
    }
  }
}



// Qos Policies for Reader:
//   durability
//   deadline
//   latency_budget
//   liveliness
//   reliability
//   destination_order
//   history
//   resource_limits
//   user_data
//   time_based_filter
//   reader_data_lifecycle
void 
TweakSpliceQos::setDataReaderQos (DDS_DataReaderQos &drQos)
{
  if (this->qos_hash_ != 0) {
    string QosFound;
    DDS_Duration_t timeval;
    DDS_long val;

    QosFound = this->qos_hash_->get (DataReaderQosKeys::get_durability_kind_key ());    
    if (QosFound.compare ("") != 0) {    
      if (QosFound.compare ("volatile") == 0)
      {
	drQos.durability.kind = DDS_VOLATILE_DURABILITY_QOS;    
	printf ("TweakSpliceQos::setDataReaderQos: Reader's durability set to VOLATILE.\n");
      }
      else if (QosFound.compare ("transient") == 0)
      {
	drQos.durability.kind = DDS_TRANSIENT_DURABILITY_QOS;
	printf ("TweakSpliceQos::setDataReaderQos: Reader's durability set to TRANSIENT.\n");
      }
      else if (QosFound.compare ("transient_local") ==0)
      {
	drQos.durability.kind = DDS_TRANSIENT_LOCAL_DURABILITY_QOS;
	printf ("TweakSpliceQos::setDataReaderQos: Reader's durability set to TRANSIENT_LOCAL.\n");
      }
      else if (QosFound.compare ("persistent") == 0)
      {
	drQos.durability.kind = DDS_PERSISTENT_DURABILITY_QOS;
	printf ("TweakSpliceQos::setDataReaderQos: Reader's durability set to PERSISTENT.\n");
      }
      else
	printf ("TweakSpliceQos::setDataReaderQos: unknown durability kind.\n");
    }


    QosFound = this->qos_hash_->get (DataReaderQosKeys::get_deadline_key ());
    if (QosFound.compare ("") != 0) {
      if (dds_get_time (QosFound, timeval))       
      {
	drQos.deadline.period = timeval;
	printf ("TweakSpliceQos::setDataReaderQos: Reader's deadline set.\n");
      }
      else
	printf ("TweakSpliceQos::setDataReaderQos: deadline - unknown time format.\n");
    }

    QosFound = this->qos_hash_->get (DataReaderQosKeys::get_latency_budget_key ());
    if (QosFound.compare ("") != 0) {  
      if (dds_get_time (QosFound, timeval))       
      {
	drQos.latency_budget.duration = timeval;
	printf ("TweakSpliceQos::setDataReaderQos: Reader's latency_budget set.\n");
      }
      else
	printf ("TweakSpliceQos::setDataReaderQos: latency_budget - unknown time format.\n");
    }


    QosFound = this->qos_hash_->get (DataReaderQosKeys::get_reliability_kind_key ());
    if (QosFound.compare ("") != 0) {    
      if (QosFound.compare ("best_effort") == 0)
      {
	drQos.reliability.kind = DDS_BEST_EFFORT_RELIABILITY_QOS;    
	printf ("TweakSpliceQos::setDataReaderQos: Reader's reliability set to BEST_EFFORT.\n");
      }
      else if (QosFound.compare ("reliable") == 0)
      {
	drQos.reliability.kind = DDS_RELIABLE_RELIABILITY_QOS;    
	printf ("TweakSpliceQos::setDataReaderQos: Reader's reliability set to RELIABLE.\n");
      }
      else
	printf ("TweakSpliceQos::setDataReaderQos: unknown reliablity kind.\n");
    }

    QosFound = this->qos_hash_->get (DataReaderQosKeys::get_reliability_max_blocking_time_key ());
    if (QosFound.compare ("") != 0) {
      if (dds_get_time (QosFound, timeval))       
      {
	drQos.reliability.max_blocking_time = timeval;
	printf ("TweakSpliceQos::setDataReaderQos: Reader's max_blocking_time set.\n");
      }
      else
	printf ("TweakSpliceQos::setDataReaderQos: max_blocking_time - unknown time format.\n");
    }


    QosFound = this->qos_hash_->get (DataReaderQosKeys::get_resource_limits_max_samples_key ());
    if (QosFound.compare ("") != 0) {
      if ((val = atol (QosFound.c_str())) == 0)
	printf ("TweakSpliceQos::setDataReaderQos: cannot convert max_samples.\n");
      else
      {
	drQos.resource_limits.max_samples = val;
	printf ("TweakSpliceQos::setDataReaderQos: Reader's max_samples set to %lu.\n", val);
      }
    }
        

    QosFound = this->qos_hash_->get (DataReaderQosKeys::get_resource_limits_max_instances_key ());
    if (QosFound.compare ("") != 0) {
      if ((val = atol (QosFound.c_str())) == 0)
	printf ("TweakSpliceQos::setDataReaderQos: cannot conver max_instances.\n");
      else
      {
	drQos.resource_limits.max_instances = val;
	printf ("TweakSpliceQos::setDataReaderQos: Reader's max_instances set to %lu.\n", val);
      }
    }
        


    QosFound = this->qos_hash_->get (DataReaderQosKeys::get_resource_limits_max_samples_per_instance_key ());
    if (QosFound.compare ("") != 0) {
      if ((val = atol (QosFound.c_str())) == 0)
	printf ("TweakSpliceQos::setDataReaderQos: cannot convert max_samples_per_instance.\n");
      else
      {
	drQos.resource_limits.max_samples_per_instance = val;
	printf ("TweakSpliceQos::setDataReaderQos: Reader's max_samples_per_instance set to %lu.\n", val);
      }
    }



    QosFound = this->qos_hash_->get (DataReaderQosKeys::get_history_kind_key ());
    if (QosFound.compare ("") != 0) {    
      if (QosFound.compare ("keep_last") == 0)
      {
	drQos.history.kind = DDS_KEEP_LAST_HISTORY_QOS;    
	printf ("TweakSpliceQos::setDataReaderQos: Reader's history set to KEEP_LAST.\n");
	printf ("TweakSpliceQos::setDataReaderQos: Reader's history set to KEEP_LAST.\n");
      }
      else if (QosFound.compare ("keep_all") == 0)
      {
	drQos.history.kind = DDS_KEEP_ALL_HISTORY_QOS;    
	printf ("TweakSpliceQos::setDataReaderQos: Reader's history set to KEEP_ALL.\n");
	printf ("TweakSpliceQos::setDataReaderQos: Reader's history set to KEEP_ALL.\n");
      }
      else
	printf ("TweakSpliceQos::setDataReaderQos: unknown history kind.\n");        
    }


    QosFound = this->qos_hash_->get (DataReaderQosKeys::get_history_depth_key ());
    if (QosFound.compare ("") != 0) {
      if ((val = atol (QosFound.c_str())) == 0)
	printf ("TweakSpliceQos::setDataReaderQos: cannot convert history depth.\n");
      else
      {
	drQos.history.depth = val;
	printf ("TweakSpliceQos::setDataReaderQos: Reader's history depth set to %lu.\n", drQos.history.depth);
      }
    }




    QosFound = this->qos_hash_->get (DataReaderQosKeys::get_liveliness_kind_key ());
    if (QosFound.compare ("") != 0) {
      if (QosFound.compare ("automatic") == 0)
      {
	drQos.liveliness.kind = DDS_AUTOMATIC_LIVELINESS_QOS;
	printf ("TweakSpliceQos::setDataReaderQos: Reader's liveliness set to AUTOMATIC.\n");
      }
      else if (QosFound.compare ("manual_by_participant") == 0)
      {
	drQos.liveliness.kind = DDS_MANUAL_BY_PARTICIPANT_LIVELINESS_QOS;
	printf ("TweakSpliceQos::setDataReaderQos: Reader's liveliness set to MANUAL_BY_PARTICIPANT.\n");
      }
      else if (QosFound.compare ("manual_by_topic") == 0)
      {
	drQos.liveliness.kind = DDS_MANUAL_BY_TOPIC_LIVELINESS_QOS;
	printf ("TweakSpliceQos::setDataReaderQos: Reader's liveliness set to MANUAL_BY_TOPIC.\n");
      }
      else
	printf ("TweakSpliceQos::setDataReaderQos: unknown liveliness kind.\n");
    }

    QosFound = this->qos_hash_->get (DataReaderQosKeys::get_liveliness_lease_duration_key ());
    if (QosFound.compare ("") != 0) {
      if (dds_get_time (QosFound, timeval))       
      {
	drQos.history.depth = val;
	drQos.liveliness.lease_duration = timeval;
	printf ("TweakSpliceQos::setDataReaderQos: Reader's lease_duration set.\n");
      }
      else
	printf ("TweakSpliceQos::setDataReaderQos: lease_duration - unknown time format.\n");
    }

    QosFound = this->qos_hash_->get (DataReaderQosKeys::get_time_based_filter_key ());
    if (QosFound.compare ("") != 0) {
      if (dds_get_time (QosFound, timeval))       
      {
	drQos.time_based_filter.minimum_separation = timeval;
	printf ("TweakSpliceQos::setDataReaderQos: Reader's time_based_filter set.\n");
      }
      else
	printf ("TweakSpliceQos::setDataReaderQos: time_based_filter - unknown time format.\n");
    }
  }
}


#endif /* __TWEAK_SPLICE_QOS_CPP */
