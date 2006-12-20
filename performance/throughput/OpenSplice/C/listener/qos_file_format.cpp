// Author: Hieu Nguyen
// June 19th, 2006

#ifndef __QOS_FILE_FORMAT_CPP
#define __QOS_FILE_FORMAT_CPP

#include "qos_file_format.h"
#include <string>
using namespace QosFormat;

const string DomainParticipantQosKeys::user_data = "domain_participant.userdata";
const string DomainParticipantQosKeys::entity_factory = "domain_participant.entity_factory";



const string TopicQosKeys::topic_data = "topic.topic_data";
const string TopicQosKeys::durability_kind = "topic.durability.kind";
const string TopicQosKeys::durability_service_cleanup_delay = "topic.durability.service_cleanup_delay";
const string TopicQosKeys::deadline = "topic.deadline.period";
const string TopicQosKeys::latency_budget = "topic.latency_budget.duration";
const string TopicQosKeys::liveliness_kind = "topic.liveliness.kind";
const string TopicQosKeys::liveliness_lease_duration = "topic.liveliness.lease_duration";
const string TopicQosKeys::reliability_kind = "topic.reliability.kind";
const string TopicQosKeys::reliability_max_blocking_time = "topic.reliability.max_blocking_time";
const string TopicQosKeys::destination_order = "topic.destination_order";
const string TopicQosKeys::history_kind = "topic.history.kind";
const string TopicQosKeys::history_depth = "topic.history.depth";
const string TopicQosKeys::resource_limits_max_samples = "topic.resource_limits.max_samples";
const string TopicQosKeys::resource_limits_max_instances = "topic.resource_limits.max_instances";
const string TopicQosKeys::resource_limits_max_samples_per_instance = "topic.resource_limits.max_samples_per_instance";
const string TopicQosKeys::transport_priority = "topic.transport_priority";
const string TopicQosKeys::lifespan = "topic.lifespan.duration";
const string TopicQosKeys::ownership = "topic.ownership.kind";



const string PublisherQosKeys::presentation_access_scope = "publisher.presentation.access_scope";
const string PublisherQosKeys::presentation_coherent_access = "publisher.presentation.coherent_access";
const string PublisherQosKeys::presentation_ordered_access = "publisher.presentation.ordered_access";
const string PublisherQosKeys::partition = "publisher.partition";
const string PublisherQosKeys::group_data = "publisher.group_data";
const string PublisherQosKeys::entity_factory = "publisher.entity_factory";



const string SubscriberQosKeys::presentation_access_scope = "subscriber.presentation.access_scope";
const string SubscriberQosKeys::presentation_coherent_access = "subscriber.presentation.coherent_access";
const string SubscriberQosKeys::presentation_ordered_access = "subscriber.presentation.ordered_access";
const string SubscriberQosKeys::partition = "subscriber.partition";
const string SubscriberQosKeys::group_data = "subscriber.group_data";
const string SubscriberQosKeys::entity_factory = "subscriber.entity_factory";



const string DataWriterQosKeys::durability_kind = "datawriter.durability.kind";
const string DataWriterQosKeys::durability_service_cleanup_delay = "datawriter.durability.service_cleanup_delay";
const string DataWriterQosKeys::deadline = "datawriter.deadline.period";
const string DataWriterQosKeys::latency_budget = "datawriter.latency_budget.duration";
const string DataWriterQosKeys::liveliness_kind = "datawriter.liveliness.kind";
const string DataWriterQosKeys::liveliness_lease_duration = "datawriter.liveliness.lease_duration";
const string DataWriterQosKeys::reliability_kind = "datawriter.reliability.kind";
const string DataWriterQosKeys::reliability_max_blocking_time = "datawriter.reliability.max_blocking_time";
const string DataWriterQosKeys::destination_order = "datawriter.destination_order";
const string DataWriterQosKeys::history_kind = "datawriter.history.kind";
const string DataWriterQosKeys::history_depth = "datawriter.history.depth";
const string DataWriterQosKeys::resource_limits_max_samples = "datawriter.resource_limits.max_samples";
const string DataWriterQosKeys::resource_limits_max_instances = "datawriter.resource_limits.max_instances";
const string DataWriterQosKeys::resource_limits_max_samples_per_instance = "datawriter.resource_limits.max_samples_per_instance";
const string DataWriterQosKeys::transport_priority = "datawriter.transport_priority";
const string DataWriterQosKeys::lifespan = "datawriter.lifespan.duration";
const string DataWriterQosKeys::user_data = "datawriter.userdata";
const string DataWriterQosKeys::ownership_strength = "datawriter.ownership_strength";
const string DataWriterQosKeys::writer_data_lifecycle = "datawriter.writer_data_lifecycle";



const string DataReaderQosKeys::durability_kind = "datareader.durability.kind";
const string DataReaderQosKeys::durability_service_cleanup_delay = "datareader.durability.service_cleanup_delay";
const string DataReaderQosKeys::deadline = "datareader.deadline.period";
const string DataReaderQosKeys::latency_budget = "datareader.latency_budget.duration";
const string DataReaderQosKeys::liveliness_kind = "datareader.liveliness.kind";
const string DataReaderQosKeys::liveliness_lease_duration = "datareader.liveliness.lease_duration";
const string DataReaderQosKeys::reliability_kind = "datareader.reliability.kind";
const string DataReaderQosKeys::reliability_max_blocking_time = "datareader.reliability.max_blocking_time";
const string DataReaderQosKeys::destination_order = "datareader.destination_order.kind";
const string DataReaderQosKeys::history_kind = "datareader.history.kind";
const string DataReaderQosKeys::history_depth = "datareader.history.depth";
const string DataReaderQosKeys::resource_limits_max_samples = "datareader.resource_limits.max_samples";
const string DataReaderQosKeys::resource_limits_max_instances = "datareader.resource_limits.max_instances";
const string DataReaderQosKeys::resource_limits_max_samples_per_instance = "datareader.resource_limits.max_samples_per_instance";
const string DataReaderQosKeys::user_data = "datareader.userdata";
const string DataReaderQosKeys::time_based_filter = "datareader.time_based_filter.minimum_separation";
const string DataReaderQosKeys::reader_data_lifecycle = "datareader.reader_data_lifecycle";



#endif /* __QOS_FILE_FORMAT_CPP */
