// Author: Hieu Nguyen
// June 19th, 2006

#ifndef __QOS_FILE_FORMAT_H
#define __QOS_FILE_FORMAT_H

#include <string>
using std::string;


// Define classes that manage the Qos file's keys naming format.
// To change the format, edit qos_file_format.cpp
namespace QosFormat {

class DomainParticipantQosKeys {
public:
  static string get_user_data_key () { return user_data; }
  static string get_entity_factory_key () { return entity_factory; }

private:
   static const string user_data;
   static const string entity_factory;
};



class TopicQosKeys {
public:
  static string get_topic_data_key () { return topic_data; }
  static string get_durability_kind_key () { return durability_kind; }
  static string get_durability_service_cleanup_delay_key () { return durability_service_cleanup_delay; }
  static string get_deadline_key () { return deadline; }
  static string get_latency_budget_key () { return latency_budget; }
  static string get_liveliness_kind_key () { return liveliness_kind; }
  static string get_liveliness_lease_duration_key () { return liveliness_lease_duration; }
  static string get_reliability_kind_key () { return reliability_kind; }
  static string get_reliability_max_blocking_time_key () { return reliability_max_blocking_time; }
  static string get_destination_order_key () { return destination_order; }
  static string get_history_kind_key () { return history_kind; }
  static string get_history_depth_key () { return history_depth; }
  static string get_resource_limits_max_samples_key () { return resource_limits_max_samples; }
  static string get_resource_limits_max_instances_key () { return resource_limits_max_instances; }
  static string get_resource_limits_max_samples_per_instance_key () { return resource_limits_max_samples_per_instance; }
  static string get_transport_priority_key () { return transport_priority; }
  static string get_lifespan_key () { return lifespan; }
  static string get_ownership_key () { return ownership; }

private:
  static const string topic_data;
  static const string durability_kind;
  static const string durability_service_cleanup_delay;
  static const string deadline;
  static const string latency_budget;
  static const string liveliness_kind;
  static const string liveliness_lease_duration;
  static const string reliability_kind;
  static const string reliability_max_blocking_time;
  static const string destination_order;
  static const string history_kind;
  static const string history_depth;
  static const string resource_limits_max_samples;
  static const string resource_limits_max_instances;
  static const string resource_limits_max_samples_per_instance;
  static const string transport_priority;
  static const string lifespan;
  static const string ownership;
};



class PublisherQosKeys {
public:
  static string get_presentation_access_scope_key () { return presentation_access_scope; }
  static string get_presentation_coherent_access_key () { return presentation_coherent_access; }
  static string get_presentation_ordered_access_key () { return presentation_ordered_access; }
  static string get_partition_key () { return partition; }
  static string get_group_data_key () { return group_data; }
  static string get_entity_factory_key () { return entity_factory; }

private:
  static const string presentation_access_scope;
  static const string presentation_coherent_access;
  static const string presentation_ordered_access;
  static const string partition;
  static const string group_data;
  static const string entity_factory;
};



class SubscriberQosKeys {
public:
  static string get_presentation_access_scope_key () { return presentation_access_scope; }
  static string get_presentation_coherent_access_key () { return presentation_coherent_access; }
  static string get_presentation_ordered_access_key () { return presentation_ordered_access; }
  static string get_partition_key () { return partition; }
  static string get_group_data_key () { return group_data; }
  static string get_entity_factory_key () { return entity_factory; }

private:
  static const string presentation_access_scope;
  static const string presentation_coherent_access;
  static const string presentation_ordered_access;
  static const string partition;
  static const string group_data;
  static const string entity_factory;
};



class DataWriterQosKeys {
public:
  static string get_durability_kind_key () { return durability_kind; }
  static string get_durability_service_cleanup_delay_key () { return durability_service_cleanup_delay; }
  static string get_deadline_key () { return deadline; }
  static string get_latency_budget_key () { return latency_budget; }
  static string get_liveliness_kind_key () { return liveliness_kind; }
  static string get_liveliness_lease_duration_key () { return liveliness_lease_duration; }
  static string get_reliability_kind_key () { return reliability_kind; }
  static string get_reliability_max_blocking_time_key () { return reliability_max_blocking_time; }
  static string get_destination_order_key () { return destination_order; }
  static string get_history_kind_key () { return history_kind; }
  static string get_history_depth_key () { return history_depth; }
  static string get_resource_limits_max_samples_key () { return resource_limits_max_samples; }
  static string get_resource_limits_max_instances_key () { return resource_limits_max_instances; }
  static string get_resource_limits_max_samples_per_instance_key () { return resource_limits_max_samples_per_instance; }
  static string get_transport_priority_key () { return transport_priority; }
  static string get_lifespan_key () { return lifespan; }
  static string get_user_data_key () { return user_data; }
  static string get_ownership_strength_key () { return ownership_strength; }
  static string get_writer_data_lifecycle_key () { return writer_data_lifecycle; }

private:
  static const string durability_kind;
  static const string durability_service_cleanup_delay;
  static const string deadline;
  static const string latency_budget;
  static const string liveliness_kind;
  static const string liveliness_lease_duration;
  static const string reliability_kind;
  static const string reliability_max_blocking_time;
  static const string destination_order;
  static const string history_kind;
  static const string history_depth;
  static const string resource_limits_max_samples;
  static const string resource_limits_max_instances;
  static const string resource_limits_max_samples_per_instance;
  static const string transport_priority;
  static const string lifespan;
  static const string user_data;
  static const string ownership_strength;
  static const string writer_data_lifecycle;
};



class DataReaderQosKeys {
public:
  static string get_durability_kind_key () { return durability_kind; }
  static string get_durability_service_cleanup_delay_key () { return durability_service_cleanup_delay; }
  static string get_deadline_key () { return deadline; }
  static string get_latency_budget_key () { return latency_budget; }
  static string get_liveliness_kind_key () { return liveliness_kind; }
  static string get_liveliness_lease_duration_key () { return liveliness_lease_duration; }
  static string get_reliability_kind_key () { return reliability_kind; }
  static string get_reliability_max_blocking_time_key () { return reliability_max_blocking_time; }
  static string get_destination_order_key () { return destination_order; }
  static string get_history_kind_key () { return history_kind; }
  static string get_history_depth_key () { return history_depth; }
  static string get_resource_limits_max_samples_key () { return resource_limits_max_samples; }
  static string get_resource_limits_max_instances_key () { return resource_limits_max_instances; }
  static string get_resource_limits_max_samples_per_instance_key () { return resource_limits_max_samples_per_instance; }
  static string get_user_data_key () { return user_data; }
  static string get_time_based_filter_key () { return time_based_filter; }
  static string get_reader_data_lifecycle_key () { return reader_data_lifecycle; }

private:
  static const string durability_kind;
  static const string durability_service_cleanup_delay;
  static const string deadline;
  static const string latency_budget;
  static const string liveliness_kind;
  static const string liveliness_lease_duration;
  static const string reliability_kind;
  static const string reliability_max_blocking_time;
  static const string destination_order;
  static const string history_kind;
  static const string history_depth;
  static const string resource_limits_max_samples;
  static const string resource_limits_max_instances;
  static const string resource_limits_max_samples_per_instance;
  static const string user_data;
  static const string time_based_filter;
  static const string reader_data_lifecycle;
};


} // end of namespace QosFormat

#endif /* __QOS_FILE_FORMAT_H */
