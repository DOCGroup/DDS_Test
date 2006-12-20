#ifndef TPTDEFSACDCPS_H
#define TPTDEFSACDCPS_H

#include "TPTDefDcps.h"

#define TP_Test_QuitMsgTypeSupport DDS_TypeSupport

TP_Test_QuitMsgTypeSupport
TP_Test_QuitMsgTypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_QuitMsgTypeSupport_register_type (
    TP_Test_QuitMsgTypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_QuitMsgTypeSupport_get_type_name (
    TP_Test_QuitMsgTypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_QuitMsg_defined
#define _DDS_sequence_TP_Test_QuitMsg_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_QuitMsg *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_QuitMsg;

DDS_sequence_TP_Test_QuitMsg *DDS_sequence_TP_Test_QuitMsg__alloc (void);
TP_Test_QuitMsg *DDS_sequence_TP_Test_QuitMsg_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_QuitMsg_defined */

#define TP_Test_QuitMsgDataWriter DDS_DataWriter

#define TP_Test_QuitMsgDataWriter_enable DDS_Entity_enable

#define TP_Test_QuitMsgDataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_QuitMsgDataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_QuitMsgDataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_QuitMsgDataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_QuitMsgDataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_QuitMsgDataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_QuitMsgDataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_QuitMsgDataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_QuitMsgDataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_QuitMsgDataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_QuitMsgDataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_QuitMsgDataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_QuitMsgDataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_QuitMsgDataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_QuitMsgDataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_QuitMsgDataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_QuitMsgDataWriter_register_instance (
    TP_Test_QuitMsgDataWriter _this,
    const TP_Test_QuitMsg *instance_data
    );

DDS_InstanceHandle_t
TP_Test_QuitMsgDataWriter_register_instance_w_timestamp (
    TP_Test_QuitMsgDataWriter _this,
    const TP_Test_QuitMsg *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataWriter_unregister_instance (
    TP_Test_QuitMsgDataWriter _this,
    const TP_Test_QuitMsg *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataWriter_unregister_instance_w_timestamp (
    TP_Test_QuitMsgDataWriter _this,
    const TP_Test_QuitMsg *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataWriter_write (
    TP_Test_QuitMsgDataWriter _this,
    const TP_Test_QuitMsg *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataWriter_write_w_timestamp (
    TP_Test_QuitMsgDataWriter _this,
    const TP_Test_QuitMsg *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataWriter_dispose (
    TP_Test_QuitMsgDataWriter _this,
    const TP_Test_QuitMsg *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataWriter_dispose_w_timestamp (
    TP_Test_QuitMsgDataWriter _this,
    const TP_Test_QuitMsg *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataWriter_writedispose (
    TP_Test_QuitMsgDataWriter _this,
    const TP_Test_QuitMsg *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataWriter_writedispose_w_timestamp (
    TP_Test_QuitMsgDataWriter _this,
    const TP_Test_QuitMsg *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataWriter_get_key_value (
    TP_Test_QuitMsgDataWriter _this,
    TP_Test_QuitMsg *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_QuitMsgDataReader DDS_DataReader

#define TP_Test_QuitMsgDataReader_enable DDS_Entity_enable

#define TP_Test_QuitMsgDataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_QuitMsgDataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_QuitMsgDataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_QuitMsgDataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_QuitMsgDataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_QuitMsgDataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_QuitMsgDataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_QuitMsgDataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_QuitMsgDataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_QuitMsgDataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_QuitMsgDataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_QuitMsgDataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_QuitMsgDataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_QuitMsgDataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_QuitMsgDataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_QuitMsgDataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_QuitMsgDataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_QuitMsgDataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_QuitMsgDataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_QuitMsgDataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_QuitMsgDataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_QuitMsgDataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_QuitMsgDataReader_read (
    TP_Test_QuitMsgDataReader _this,
    DDS_sequence_TP_Test_QuitMsg *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReader_take (
    TP_Test_QuitMsgDataReader _this,
    DDS_sequence_TP_Test_QuitMsg *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReader_read_w_condition (
    TP_Test_QuitMsgDataReader _this,
    DDS_sequence_TP_Test_QuitMsg *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReader_take_w_condition (
    TP_Test_QuitMsgDataReader _this,
    DDS_sequence_TP_Test_QuitMsg *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReader_read_next_sample (
    TP_Test_QuitMsgDataReader _this,
    TP_Test_QuitMsg *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReader_take_next_sample (
    TP_Test_QuitMsgDataReader _this,
    TP_Test_QuitMsg *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReader_read_instance (
    TP_Test_QuitMsgDataReader _this,
    DDS_sequence_TP_Test_QuitMsg *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReader_take_instance (
    TP_Test_QuitMsgDataReader _this,
    DDS_sequence_TP_Test_QuitMsg *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReader_read_next_instance (
    TP_Test_QuitMsgDataReader _this,
    DDS_sequence_TP_Test_QuitMsg *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReader_take_next_instance (
    TP_Test_QuitMsgDataReader _this,
    DDS_sequence_TP_Test_QuitMsg *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReader_read_next_instance_w_condition (
    TP_Test_QuitMsgDataReader _this,
    DDS_sequence_TP_Test_QuitMsg *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReader_take_next_instance_w_condition (
    TP_Test_QuitMsgDataReader _this,
    DDS_sequence_TP_Test_QuitMsg *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReader_return_loan (
    TP_Test_QuitMsgDataReader _this,
    DDS_sequence_TP_Test_QuitMsg *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReader_get_key_value (
    TP_Test_QuitMsgDataReader _this,
    TP_Test_QuitMsg *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_QuitMsgDataReader_lookup_instance (
    TP_Test_QuitMsgDataReader _this,
    const TP_Test_QuitMsg *key_holder
    );

#define TP_Test_QuitMsgDataReaderView DDS_DataReaderView

#define TP_Test_QuitMsgDataReaderView_enable DDS_Entity_enable

#define TP_Test_QuitMsgDataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_QuitMsgDataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_QuitMsgDataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_QuitMsgDataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_QuitMsgDataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_QuitMsgDataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_QuitMsgDataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_QuitMsgDataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_QuitMsgDataReaderView_read (
    TP_Test_QuitMsgDataReaderView _this,
    DDS_sequence_TP_Test_QuitMsg *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReaderView_take (
    TP_Test_QuitMsgDataReaderView _this,
    DDS_sequence_TP_Test_QuitMsg *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReaderView_read_next_sample (
    TP_Test_QuitMsgDataReaderView _this,
    TP_Test_QuitMsg *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReaderView_take_next_sample (
    TP_Test_QuitMsgDataReaderView _this,
    TP_Test_QuitMsg *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReaderView_read_instance (
    TP_Test_QuitMsgDataReaderView _this,
    DDS_sequence_TP_Test_QuitMsg *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReaderView_take_instance (
    TP_Test_QuitMsgDataReaderView _this,
    DDS_sequence_TP_Test_QuitMsg *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReaderView_read_next_instance (
    TP_Test_QuitMsgDataReaderView _this,
    DDS_sequence_TP_Test_QuitMsg *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReaderView_take_next_instance (
    TP_Test_QuitMsgDataReaderView _this,
    DDS_sequence_TP_Test_QuitMsg *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReaderView_return_loan (
    TP_Test_QuitMsgDataReaderView _this,
    DDS_sequence_TP_Test_QuitMsg *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReaderView_read_w_condition (
    TP_Test_QuitMsgDataReaderView _this,
    DDS_sequence_TP_Test_QuitMsg *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReaderView_take_w_condition (
    TP_Test_QuitMsgDataReaderView _this,
    DDS_sequence_TP_Test_QuitMsg *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReaderView_read_next_instance_w_condition (
    TP_Test_QuitMsgDataReaderView _this,
    DDS_sequence_TP_Test_QuitMsg *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReaderView_take_next_instance_w_condition (
    TP_Test_QuitMsgDataReaderView _this,
    DDS_sequence_TP_Test_QuitMsg *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_QuitMsgDataReaderView_get_key_value (
    TP_Test_QuitMsgDataReaderView _this,
    TP_Test_QuitMsg *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_QuitMsgDataReaderView_lookup_instance (
    TP_Test_QuitMsgDataReaderView _this,
    TP_Test_QuitMsg *key_holder
    );



#define TP_Test_Bytes4TypeSupport DDS_TypeSupport

TP_Test_Bytes4TypeSupport
TP_Test_Bytes4TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Bytes4TypeSupport_register_type (
    TP_Test_Bytes4TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Bytes4TypeSupport_get_type_name (
    TP_Test_Bytes4TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Bytes4_defined
#define _DDS_sequence_TP_Test_Bytes4_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Bytes4 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Bytes4;

DDS_sequence_TP_Test_Bytes4 *DDS_sequence_TP_Test_Bytes4__alloc (void);
TP_Test_Bytes4 *DDS_sequence_TP_Test_Bytes4_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Bytes4_defined */

#define TP_Test_Bytes4DataWriter DDS_DataWriter

#define TP_Test_Bytes4DataWriter_enable DDS_Entity_enable

#define TP_Test_Bytes4DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes4DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes4DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes4DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Bytes4DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Bytes4DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Bytes4DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Bytes4DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Bytes4DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Bytes4DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Bytes4DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Bytes4DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Bytes4DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Bytes4DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Bytes4DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Bytes4DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Bytes4DataWriter_register_instance (
    TP_Test_Bytes4DataWriter _this,
    const TP_Test_Bytes4 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Bytes4DataWriter_register_instance_w_timestamp (
    TP_Test_Bytes4DataWriter _this,
    const TP_Test_Bytes4 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataWriter_unregister_instance (
    TP_Test_Bytes4DataWriter _this,
    const TP_Test_Bytes4 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataWriter_unregister_instance_w_timestamp (
    TP_Test_Bytes4DataWriter _this,
    const TP_Test_Bytes4 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataWriter_write (
    TP_Test_Bytes4DataWriter _this,
    const TP_Test_Bytes4 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataWriter_write_w_timestamp (
    TP_Test_Bytes4DataWriter _this,
    const TP_Test_Bytes4 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataWriter_dispose (
    TP_Test_Bytes4DataWriter _this,
    const TP_Test_Bytes4 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataWriter_dispose_w_timestamp (
    TP_Test_Bytes4DataWriter _this,
    const TP_Test_Bytes4 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataWriter_writedispose (
    TP_Test_Bytes4DataWriter _this,
    const TP_Test_Bytes4 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataWriter_writedispose_w_timestamp (
    TP_Test_Bytes4DataWriter _this,
    const TP_Test_Bytes4 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataWriter_get_key_value (
    TP_Test_Bytes4DataWriter _this,
    TP_Test_Bytes4 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Bytes4DataReader DDS_DataReader

#define TP_Test_Bytes4DataReader_enable DDS_Entity_enable

#define TP_Test_Bytes4DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes4DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes4DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes4DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Bytes4DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Bytes4DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Bytes4DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Bytes4DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Bytes4DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Bytes4DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Bytes4DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Bytes4DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Bytes4DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Bytes4DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Bytes4DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Bytes4DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Bytes4DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Bytes4DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Bytes4DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Bytes4DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Bytes4DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Bytes4DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Bytes4DataReader_read (
    TP_Test_Bytes4DataReader _this,
    DDS_sequence_TP_Test_Bytes4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReader_take (
    TP_Test_Bytes4DataReader _this,
    DDS_sequence_TP_Test_Bytes4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReader_read_w_condition (
    TP_Test_Bytes4DataReader _this,
    DDS_sequence_TP_Test_Bytes4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReader_take_w_condition (
    TP_Test_Bytes4DataReader _this,
    DDS_sequence_TP_Test_Bytes4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReader_read_next_sample (
    TP_Test_Bytes4DataReader _this,
    TP_Test_Bytes4 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReader_take_next_sample (
    TP_Test_Bytes4DataReader _this,
    TP_Test_Bytes4 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReader_read_instance (
    TP_Test_Bytes4DataReader _this,
    DDS_sequence_TP_Test_Bytes4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReader_take_instance (
    TP_Test_Bytes4DataReader _this,
    DDS_sequence_TP_Test_Bytes4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReader_read_next_instance (
    TP_Test_Bytes4DataReader _this,
    DDS_sequence_TP_Test_Bytes4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReader_take_next_instance (
    TP_Test_Bytes4DataReader _this,
    DDS_sequence_TP_Test_Bytes4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReader_read_next_instance_w_condition (
    TP_Test_Bytes4DataReader _this,
    DDS_sequence_TP_Test_Bytes4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReader_take_next_instance_w_condition (
    TP_Test_Bytes4DataReader _this,
    DDS_sequence_TP_Test_Bytes4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReader_return_loan (
    TP_Test_Bytes4DataReader _this,
    DDS_sequence_TP_Test_Bytes4 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReader_get_key_value (
    TP_Test_Bytes4DataReader _this,
    TP_Test_Bytes4 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes4DataReader_lookup_instance (
    TP_Test_Bytes4DataReader _this,
    const TP_Test_Bytes4 *key_holder
    );

#define TP_Test_Bytes4DataReaderView DDS_DataReaderView

#define TP_Test_Bytes4DataReaderView_enable DDS_Entity_enable

#define TP_Test_Bytes4DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes4DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Bytes4DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Bytes4DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Bytes4DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Bytes4DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Bytes4DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Bytes4DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Bytes4DataReaderView_read (
    TP_Test_Bytes4DataReaderView _this,
    DDS_sequence_TP_Test_Bytes4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReaderView_take (
    TP_Test_Bytes4DataReaderView _this,
    DDS_sequence_TP_Test_Bytes4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReaderView_read_next_sample (
    TP_Test_Bytes4DataReaderView _this,
    TP_Test_Bytes4 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReaderView_take_next_sample (
    TP_Test_Bytes4DataReaderView _this,
    TP_Test_Bytes4 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReaderView_read_instance (
    TP_Test_Bytes4DataReaderView _this,
    DDS_sequence_TP_Test_Bytes4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReaderView_take_instance (
    TP_Test_Bytes4DataReaderView _this,
    DDS_sequence_TP_Test_Bytes4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReaderView_read_next_instance (
    TP_Test_Bytes4DataReaderView _this,
    DDS_sequence_TP_Test_Bytes4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReaderView_take_next_instance (
    TP_Test_Bytes4DataReaderView _this,
    DDS_sequence_TP_Test_Bytes4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReaderView_return_loan (
    TP_Test_Bytes4DataReaderView _this,
    DDS_sequence_TP_Test_Bytes4 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReaderView_read_w_condition (
    TP_Test_Bytes4DataReaderView _this,
    DDS_sequence_TP_Test_Bytes4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReaderView_take_w_condition (
    TP_Test_Bytes4DataReaderView _this,
    DDS_sequence_TP_Test_Bytes4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReaderView_read_next_instance_w_condition (
    TP_Test_Bytes4DataReaderView _this,
    DDS_sequence_TP_Test_Bytes4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReaderView_take_next_instance_w_condition (
    TP_Test_Bytes4DataReaderView _this,
    DDS_sequence_TP_Test_Bytes4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes4DataReaderView_get_key_value (
    TP_Test_Bytes4DataReaderView _this,
    TP_Test_Bytes4 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes4DataReaderView_lookup_instance (
    TP_Test_Bytes4DataReaderView _this,
    TP_Test_Bytes4 *key_holder
    );



#define TP_Test_Bytes8TypeSupport DDS_TypeSupport

TP_Test_Bytes8TypeSupport
TP_Test_Bytes8TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Bytes8TypeSupport_register_type (
    TP_Test_Bytes8TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Bytes8TypeSupport_get_type_name (
    TP_Test_Bytes8TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Bytes8_defined
#define _DDS_sequence_TP_Test_Bytes8_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Bytes8 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Bytes8;

DDS_sequence_TP_Test_Bytes8 *DDS_sequence_TP_Test_Bytes8__alloc (void);
TP_Test_Bytes8 *DDS_sequence_TP_Test_Bytes8_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Bytes8_defined */

#define TP_Test_Bytes8DataWriter DDS_DataWriter

#define TP_Test_Bytes8DataWriter_enable DDS_Entity_enable

#define TP_Test_Bytes8DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes8DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes8DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes8DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Bytes8DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Bytes8DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Bytes8DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Bytes8DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Bytes8DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Bytes8DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Bytes8DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Bytes8DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Bytes8DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Bytes8DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Bytes8DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Bytes8DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Bytes8DataWriter_register_instance (
    TP_Test_Bytes8DataWriter _this,
    const TP_Test_Bytes8 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Bytes8DataWriter_register_instance_w_timestamp (
    TP_Test_Bytes8DataWriter _this,
    const TP_Test_Bytes8 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataWriter_unregister_instance (
    TP_Test_Bytes8DataWriter _this,
    const TP_Test_Bytes8 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataWriter_unregister_instance_w_timestamp (
    TP_Test_Bytes8DataWriter _this,
    const TP_Test_Bytes8 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataWriter_write (
    TP_Test_Bytes8DataWriter _this,
    const TP_Test_Bytes8 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataWriter_write_w_timestamp (
    TP_Test_Bytes8DataWriter _this,
    const TP_Test_Bytes8 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataWriter_dispose (
    TP_Test_Bytes8DataWriter _this,
    const TP_Test_Bytes8 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataWriter_dispose_w_timestamp (
    TP_Test_Bytes8DataWriter _this,
    const TP_Test_Bytes8 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataWriter_writedispose (
    TP_Test_Bytes8DataWriter _this,
    const TP_Test_Bytes8 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataWriter_writedispose_w_timestamp (
    TP_Test_Bytes8DataWriter _this,
    const TP_Test_Bytes8 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataWriter_get_key_value (
    TP_Test_Bytes8DataWriter _this,
    TP_Test_Bytes8 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Bytes8DataReader DDS_DataReader

#define TP_Test_Bytes8DataReader_enable DDS_Entity_enable

#define TP_Test_Bytes8DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes8DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes8DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes8DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Bytes8DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Bytes8DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Bytes8DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Bytes8DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Bytes8DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Bytes8DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Bytes8DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Bytes8DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Bytes8DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Bytes8DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Bytes8DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Bytes8DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Bytes8DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Bytes8DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Bytes8DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Bytes8DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Bytes8DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Bytes8DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Bytes8DataReader_read (
    TP_Test_Bytes8DataReader _this,
    DDS_sequence_TP_Test_Bytes8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReader_take (
    TP_Test_Bytes8DataReader _this,
    DDS_sequence_TP_Test_Bytes8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReader_read_w_condition (
    TP_Test_Bytes8DataReader _this,
    DDS_sequence_TP_Test_Bytes8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReader_take_w_condition (
    TP_Test_Bytes8DataReader _this,
    DDS_sequence_TP_Test_Bytes8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReader_read_next_sample (
    TP_Test_Bytes8DataReader _this,
    TP_Test_Bytes8 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReader_take_next_sample (
    TP_Test_Bytes8DataReader _this,
    TP_Test_Bytes8 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReader_read_instance (
    TP_Test_Bytes8DataReader _this,
    DDS_sequence_TP_Test_Bytes8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReader_take_instance (
    TP_Test_Bytes8DataReader _this,
    DDS_sequence_TP_Test_Bytes8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReader_read_next_instance (
    TP_Test_Bytes8DataReader _this,
    DDS_sequence_TP_Test_Bytes8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReader_take_next_instance (
    TP_Test_Bytes8DataReader _this,
    DDS_sequence_TP_Test_Bytes8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReader_read_next_instance_w_condition (
    TP_Test_Bytes8DataReader _this,
    DDS_sequence_TP_Test_Bytes8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReader_take_next_instance_w_condition (
    TP_Test_Bytes8DataReader _this,
    DDS_sequence_TP_Test_Bytes8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReader_return_loan (
    TP_Test_Bytes8DataReader _this,
    DDS_sequence_TP_Test_Bytes8 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReader_get_key_value (
    TP_Test_Bytes8DataReader _this,
    TP_Test_Bytes8 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes8DataReader_lookup_instance (
    TP_Test_Bytes8DataReader _this,
    const TP_Test_Bytes8 *key_holder
    );

#define TP_Test_Bytes8DataReaderView DDS_DataReaderView

#define TP_Test_Bytes8DataReaderView_enable DDS_Entity_enable

#define TP_Test_Bytes8DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes8DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Bytes8DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Bytes8DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Bytes8DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Bytes8DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Bytes8DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Bytes8DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Bytes8DataReaderView_read (
    TP_Test_Bytes8DataReaderView _this,
    DDS_sequence_TP_Test_Bytes8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReaderView_take (
    TP_Test_Bytes8DataReaderView _this,
    DDS_sequence_TP_Test_Bytes8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReaderView_read_next_sample (
    TP_Test_Bytes8DataReaderView _this,
    TP_Test_Bytes8 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReaderView_take_next_sample (
    TP_Test_Bytes8DataReaderView _this,
    TP_Test_Bytes8 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReaderView_read_instance (
    TP_Test_Bytes8DataReaderView _this,
    DDS_sequence_TP_Test_Bytes8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReaderView_take_instance (
    TP_Test_Bytes8DataReaderView _this,
    DDS_sequence_TP_Test_Bytes8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReaderView_read_next_instance (
    TP_Test_Bytes8DataReaderView _this,
    DDS_sequence_TP_Test_Bytes8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReaderView_take_next_instance (
    TP_Test_Bytes8DataReaderView _this,
    DDS_sequence_TP_Test_Bytes8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReaderView_return_loan (
    TP_Test_Bytes8DataReaderView _this,
    DDS_sequence_TP_Test_Bytes8 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReaderView_read_w_condition (
    TP_Test_Bytes8DataReaderView _this,
    DDS_sequence_TP_Test_Bytes8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReaderView_take_w_condition (
    TP_Test_Bytes8DataReaderView _this,
    DDS_sequence_TP_Test_Bytes8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReaderView_read_next_instance_w_condition (
    TP_Test_Bytes8DataReaderView _this,
    DDS_sequence_TP_Test_Bytes8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReaderView_take_next_instance_w_condition (
    TP_Test_Bytes8DataReaderView _this,
    DDS_sequence_TP_Test_Bytes8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes8DataReaderView_get_key_value (
    TP_Test_Bytes8DataReaderView _this,
    TP_Test_Bytes8 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes8DataReaderView_lookup_instance (
    TP_Test_Bytes8DataReaderView _this,
    TP_Test_Bytes8 *key_holder
    );



#define TP_Test_Bytes16TypeSupport DDS_TypeSupport

TP_Test_Bytes16TypeSupport
TP_Test_Bytes16TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Bytes16TypeSupport_register_type (
    TP_Test_Bytes16TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Bytes16TypeSupport_get_type_name (
    TP_Test_Bytes16TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Bytes16_defined
#define _DDS_sequence_TP_Test_Bytes16_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Bytes16 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Bytes16;

DDS_sequence_TP_Test_Bytes16 *DDS_sequence_TP_Test_Bytes16__alloc (void);
TP_Test_Bytes16 *DDS_sequence_TP_Test_Bytes16_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Bytes16_defined */

#define TP_Test_Bytes16DataWriter DDS_DataWriter

#define TP_Test_Bytes16DataWriter_enable DDS_Entity_enable

#define TP_Test_Bytes16DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes16DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes16DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes16DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Bytes16DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Bytes16DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Bytes16DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Bytes16DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Bytes16DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Bytes16DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Bytes16DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Bytes16DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Bytes16DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Bytes16DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Bytes16DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Bytes16DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Bytes16DataWriter_register_instance (
    TP_Test_Bytes16DataWriter _this,
    const TP_Test_Bytes16 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Bytes16DataWriter_register_instance_w_timestamp (
    TP_Test_Bytes16DataWriter _this,
    const TP_Test_Bytes16 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataWriter_unregister_instance (
    TP_Test_Bytes16DataWriter _this,
    const TP_Test_Bytes16 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataWriter_unregister_instance_w_timestamp (
    TP_Test_Bytes16DataWriter _this,
    const TP_Test_Bytes16 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataWriter_write (
    TP_Test_Bytes16DataWriter _this,
    const TP_Test_Bytes16 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataWriter_write_w_timestamp (
    TP_Test_Bytes16DataWriter _this,
    const TP_Test_Bytes16 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataWriter_dispose (
    TP_Test_Bytes16DataWriter _this,
    const TP_Test_Bytes16 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataWriter_dispose_w_timestamp (
    TP_Test_Bytes16DataWriter _this,
    const TP_Test_Bytes16 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataWriter_writedispose (
    TP_Test_Bytes16DataWriter _this,
    const TP_Test_Bytes16 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataWriter_writedispose_w_timestamp (
    TP_Test_Bytes16DataWriter _this,
    const TP_Test_Bytes16 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataWriter_get_key_value (
    TP_Test_Bytes16DataWriter _this,
    TP_Test_Bytes16 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Bytes16DataReader DDS_DataReader

#define TP_Test_Bytes16DataReader_enable DDS_Entity_enable

#define TP_Test_Bytes16DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes16DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes16DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes16DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Bytes16DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Bytes16DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Bytes16DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Bytes16DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Bytes16DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Bytes16DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Bytes16DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Bytes16DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Bytes16DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Bytes16DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Bytes16DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Bytes16DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Bytes16DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Bytes16DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Bytes16DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Bytes16DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Bytes16DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Bytes16DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Bytes16DataReader_read (
    TP_Test_Bytes16DataReader _this,
    DDS_sequence_TP_Test_Bytes16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReader_take (
    TP_Test_Bytes16DataReader _this,
    DDS_sequence_TP_Test_Bytes16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReader_read_w_condition (
    TP_Test_Bytes16DataReader _this,
    DDS_sequence_TP_Test_Bytes16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReader_take_w_condition (
    TP_Test_Bytes16DataReader _this,
    DDS_sequence_TP_Test_Bytes16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReader_read_next_sample (
    TP_Test_Bytes16DataReader _this,
    TP_Test_Bytes16 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReader_take_next_sample (
    TP_Test_Bytes16DataReader _this,
    TP_Test_Bytes16 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReader_read_instance (
    TP_Test_Bytes16DataReader _this,
    DDS_sequence_TP_Test_Bytes16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReader_take_instance (
    TP_Test_Bytes16DataReader _this,
    DDS_sequence_TP_Test_Bytes16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReader_read_next_instance (
    TP_Test_Bytes16DataReader _this,
    DDS_sequence_TP_Test_Bytes16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReader_take_next_instance (
    TP_Test_Bytes16DataReader _this,
    DDS_sequence_TP_Test_Bytes16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReader_read_next_instance_w_condition (
    TP_Test_Bytes16DataReader _this,
    DDS_sequence_TP_Test_Bytes16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReader_take_next_instance_w_condition (
    TP_Test_Bytes16DataReader _this,
    DDS_sequence_TP_Test_Bytes16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReader_return_loan (
    TP_Test_Bytes16DataReader _this,
    DDS_sequence_TP_Test_Bytes16 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReader_get_key_value (
    TP_Test_Bytes16DataReader _this,
    TP_Test_Bytes16 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes16DataReader_lookup_instance (
    TP_Test_Bytes16DataReader _this,
    const TP_Test_Bytes16 *key_holder
    );

#define TP_Test_Bytes16DataReaderView DDS_DataReaderView

#define TP_Test_Bytes16DataReaderView_enable DDS_Entity_enable

#define TP_Test_Bytes16DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes16DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Bytes16DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Bytes16DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Bytes16DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Bytes16DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Bytes16DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Bytes16DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Bytes16DataReaderView_read (
    TP_Test_Bytes16DataReaderView _this,
    DDS_sequence_TP_Test_Bytes16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReaderView_take (
    TP_Test_Bytes16DataReaderView _this,
    DDS_sequence_TP_Test_Bytes16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReaderView_read_next_sample (
    TP_Test_Bytes16DataReaderView _this,
    TP_Test_Bytes16 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReaderView_take_next_sample (
    TP_Test_Bytes16DataReaderView _this,
    TP_Test_Bytes16 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReaderView_read_instance (
    TP_Test_Bytes16DataReaderView _this,
    DDS_sequence_TP_Test_Bytes16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReaderView_take_instance (
    TP_Test_Bytes16DataReaderView _this,
    DDS_sequence_TP_Test_Bytes16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReaderView_read_next_instance (
    TP_Test_Bytes16DataReaderView _this,
    DDS_sequence_TP_Test_Bytes16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReaderView_take_next_instance (
    TP_Test_Bytes16DataReaderView _this,
    DDS_sequence_TP_Test_Bytes16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReaderView_return_loan (
    TP_Test_Bytes16DataReaderView _this,
    DDS_sequence_TP_Test_Bytes16 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReaderView_read_w_condition (
    TP_Test_Bytes16DataReaderView _this,
    DDS_sequence_TP_Test_Bytes16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReaderView_take_w_condition (
    TP_Test_Bytes16DataReaderView _this,
    DDS_sequence_TP_Test_Bytes16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReaderView_read_next_instance_w_condition (
    TP_Test_Bytes16DataReaderView _this,
    DDS_sequence_TP_Test_Bytes16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReaderView_take_next_instance_w_condition (
    TP_Test_Bytes16DataReaderView _this,
    DDS_sequence_TP_Test_Bytes16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes16DataReaderView_get_key_value (
    TP_Test_Bytes16DataReaderView _this,
    TP_Test_Bytes16 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes16DataReaderView_lookup_instance (
    TP_Test_Bytes16DataReaderView _this,
    TP_Test_Bytes16 *key_holder
    );



#define TP_Test_Bytes32TypeSupport DDS_TypeSupport

TP_Test_Bytes32TypeSupport
TP_Test_Bytes32TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Bytes32TypeSupport_register_type (
    TP_Test_Bytes32TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Bytes32TypeSupport_get_type_name (
    TP_Test_Bytes32TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Bytes32_defined
#define _DDS_sequence_TP_Test_Bytes32_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Bytes32 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Bytes32;

DDS_sequence_TP_Test_Bytes32 *DDS_sequence_TP_Test_Bytes32__alloc (void);
TP_Test_Bytes32 *DDS_sequence_TP_Test_Bytes32_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Bytes32_defined */

#define TP_Test_Bytes32DataWriter DDS_DataWriter

#define TP_Test_Bytes32DataWriter_enable DDS_Entity_enable

#define TP_Test_Bytes32DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes32DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes32DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes32DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Bytes32DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Bytes32DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Bytes32DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Bytes32DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Bytes32DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Bytes32DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Bytes32DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Bytes32DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Bytes32DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Bytes32DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Bytes32DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Bytes32DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Bytes32DataWriter_register_instance (
    TP_Test_Bytes32DataWriter _this,
    const TP_Test_Bytes32 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Bytes32DataWriter_register_instance_w_timestamp (
    TP_Test_Bytes32DataWriter _this,
    const TP_Test_Bytes32 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataWriter_unregister_instance (
    TP_Test_Bytes32DataWriter _this,
    const TP_Test_Bytes32 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataWriter_unregister_instance_w_timestamp (
    TP_Test_Bytes32DataWriter _this,
    const TP_Test_Bytes32 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataWriter_write (
    TP_Test_Bytes32DataWriter _this,
    const TP_Test_Bytes32 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataWriter_write_w_timestamp (
    TP_Test_Bytes32DataWriter _this,
    const TP_Test_Bytes32 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataWriter_dispose (
    TP_Test_Bytes32DataWriter _this,
    const TP_Test_Bytes32 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataWriter_dispose_w_timestamp (
    TP_Test_Bytes32DataWriter _this,
    const TP_Test_Bytes32 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataWriter_writedispose (
    TP_Test_Bytes32DataWriter _this,
    const TP_Test_Bytes32 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataWriter_writedispose_w_timestamp (
    TP_Test_Bytes32DataWriter _this,
    const TP_Test_Bytes32 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataWriter_get_key_value (
    TP_Test_Bytes32DataWriter _this,
    TP_Test_Bytes32 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Bytes32DataReader DDS_DataReader

#define TP_Test_Bytes32DataReader_enable DDS_Entity_enable

#define TP_Test_Bytes32DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes32DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes32DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes32DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Bytes32DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Bytes32DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Bytes32DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Bytes32DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Bytes32DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Bytes32DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Bytes32DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Bytes32DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Bytes32DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Bytes32DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Bytes32DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Bytes32DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Bytes32DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Bytes32DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Bytes32DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Bytes32DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Bytes32DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Bytes32DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Bytes32DataReader_read (
    TP_Test_Bytes32DataReader _this,
    DDS_sequence_TP_Test_Bytes32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReader_take (
    TP_Test_Bytes32DataReader _this,
    DDS_sequence_TP_Test_Bytes32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReader_read_w_condition (
    TP_Test_Bytes32DataReader _this,
    DDS_sequence_TP_Test_Bytes32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReader_take_w_condition (
    TP_Test_Bytes32DataReader _this,
    DDS_sequence_TP_Test_Bytes32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReader_read_next_sample (
    TP_Test_Bytes32DataReader _this,
    TP_Test_Bytes32 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReader_take_next_sample (
    TP_Test_Bytes32DataReader _this,
    TP_Test_Bytes32 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReader_read_instance (
    TP_Test_Bytes32DataReader _this,
    DDS_sequence_TP_Test_Bytes32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReader_take_instance (
    TP_Test_Bytes32DataReader _this,
    DDS_sequence_TP_Test_Bytes32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReader_read_next_instance (
    TP_Test_Bytes32DataReader _this,
    DDS_sequence_TP_Test_Bytes32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReader_take_next_instance (
    TP_Test_Bytes32DataReader _this,
    DDS_sequence_TP_Test_Bytes32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReader_read_next_instance_w_condition (
    TP_Test_Bytes32DataReader _this,
    DDS_sequence_TP_Test_Bytes32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReader_take_next_instance_w_condition (
    TP_Test_Bytes32DataReader _this,
    DDS_sequence_TP_Test_Bytes32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReader_return_loan (
    TP_Test_Bytes32DataReader _this,
    DDS_sequence_TP_Test_Bytes32 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReader_get_key_value (
    TP_Test_Bytes32DataReader _this,
    TP_Test_Bytes32 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes32DataReader_lookup_instance (
    TP_Test_Bytes32DataReader _this,
    const TP_Test_Bytes32 *key_holder
    );

#define TP_Test_Bytes32DataReaderView DDS_DataReaderView

#define TP_Test_Bytes32DataReaderView_enable DDS_Entity_enable

#define TP_Test_Bytes32DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes32DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Bytes32DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Bytes32DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Bytes32DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Bytes32DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Bytes32DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Bytes32DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Bytes32DataReaderView_read (
    TP_Test_Bytes32DataReaderView _this,
    DDS_sequence_TP_Test_Bytes32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReaderView_take (
    TP_Test_Bytes32DataReaderView _this,
    DDS_sequence_TP_Test_Bytes32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReaderView_read_next_sample (
    TP_Test_Bytes32DataReaderView _this,
    TP_Test_Bytes32 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReaderView_take_next_sample (
    TP_Test_Bytes32DataReaderView _this,
    TP_Test_Bytes32 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReaderView_read_instance (
    TP_Test_Bytes32DataReaderView _this,
    DDS_sequence_TP_Test_Bytes32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReaderView_take_instance (
    TP_Test_Bytes32DataReaderView _this,
    DDS_sequence_TP_Test_Bytes32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReaderView_read_next_instance (
    TP_Test_Bytes32DataReaderView _this,
    DDS_sequence_TP_Test_Bytes32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReaderView_take_next_instance (
    TP_Test_Bytes32DataReaderView _this,
    DDS_sequence_TP_Test_Bytes32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReaderView_return_loan (
    TP_Test_Bytes32DataReaderView _this,
    DDS_sequence_TP_Test_Bytes32 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReaderView_read_w_condition (
    TP_Test_Bytes32DataReaderView _this,
    DDS_sequence_TP_Test_Bytes32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReaderView_take_w_condition (
    TP_Test_Bytes32DataReaderView _this,
    DDS_sequence_TP_Test_Bytes32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReaderView_read_next_instance_w_condition (
    TP_Test_Bytes32DataReaderView _this,
    DDS_sequence_TP_Test_Bytes32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReaderView_take_next_instance_w_condition (
    TP_Test_Bytes32DataReaderView _this,
    DDS_sequence_TP_Test_Bytes32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes32DataReaderView_get_key_value (
    TP_Test_Bytes32DataReaderView _this,
    TP_Test_Bytes32 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes32DataReaderView_lookup_instance (
    TP_Test_Bytes32DataReaderView _this,
    TP_Test_Bytes32 *key_holder
    );



#define TP_Test_Bytes64TypeSupport DDS_TypeSupport

TP_Test_Bytes64TypeSupport
TP_Test_Bytes64TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Bytes64TypeSupport_register_type (
    TP_Test_Bytes64TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Bytes64TypeSupport_get_type_name (
    TP_Test_Bytes64TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Bytes64_defined
#define _DDS_sequence_TP_Test_Bytes64_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Bytes64 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Bytes64;

DDS_sequence_TP_Test_Bytes64 *DDS_sequence_TP_Test_Bytes64__alloc (void);
TP_Test_Bytes64 *DDS_sequence_TP_Test_Bytes64_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Bytes64_defined */

#define TP_Test_Bytes64DataWriter DDS_DataWriter

#define TP_Test_Bytes64DataWriter_enable DDS_Entity_enable

#define TP_Test_Bytes64DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes64DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes64DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes64DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Bytes64DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Bytes64DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Bytes64DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Bytes64DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Bytes64DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Bytes64DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Bytes64DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Bytes64DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Bytes64DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Bytes64DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Bytes64DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Bytes64DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Bytes64DataWriter_register_instance (
    TP_Test_Bytes64DataWriter _this,
    const TP_Test_Bytes64 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Bytes64DataWriter_register_instance_w_timestamp (
    TP_Test_Bytes64DataWriter _this,
    const TP_Test_Bytes64 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataWriter_unregister_instance (
    TP_Test_Bytes64DataWriter _this,
    const TP_Test_Bytes64 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataWriter_unregister_instance_w_timestamp (
    TP_Test_Bytes64DataWriter _this,
    const TP_Test_Bytes64 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataWriter_write (
    TP_Test_Bytes64DataWriter _this,
    const TP_Test_Bytes64 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataWriter_write_w_timestamp (
    TP_Test_Bytes64DataWriter _this,
    const TP_Test_Bytes64 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataWriter_dispose (
    TP_Test_Bytes64DataWriter _this,
    const TP_Test_Bytes64 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataWriter_dispose_w_timestamp (
    TP_Test_Bytes64DataWriter _this,
    const TP_Test_Bytes64 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataWriter_writedispose (
    TP_Test_Bytes64DataWriter _this,
    const TP_Test_Bytes64 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataWriter_writedispose_w_timestamp (
    TP_Test_Bytes64DataWriter _this,
    const TP_Test_Bytes64 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataWriter_get_key_value (
    TP_Test_Bytes64DataWriter _this,
    TP_Test_Bytes64 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Bytes64DataReader DDS_DataReader

#define TP_Test_Bytes64DataReader_enable DDS_Entity_enable

#define TP_Test_Bytes64DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes64DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes64DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes64DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Bytes64DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Bytes64DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Bytes64DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Bytes64DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Bytes64DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Bytes64DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Bytes64DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Bytes64DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Bytes64DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Bytes64DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Bytes64DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Bytes64DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Bytes64DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Bytes64DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Bytes64DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Bytes64DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Bytes64DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Bytes64DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Bytes64DataReader_read (
    TP_Test_Bytes64DataReader _this,
    DDS_sequence_TP_Test_Bytes64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReader_take (
    TP_Test_Bytes64DataReader _this,
    DDS_sequence_TP_Test_Bytes64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReader_read_w_condition (
    TP_Test_Bytes64DataReader _this,
    DDS_sequence_TP_Test_Bytes64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReader_take_w_condition (
    TP_Test_Bytes64DataReader _this,
    DDS_sequence_TP_Test_Bytes64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReader_read_next_sample (
    TP_Test_Bytes64DataReader _this,
    TP_Test_Bytes64 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReader_take_next_sample (
    TP_Test_Bytes64DataReader _this,
    TP_Test_Bytes64 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReader_read_instance (
    TP_Test_Bytes64DataReader _this,
    DDS_sequence_TP_Test_Bytes64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReader_take_instance (
    TP_Test_Bytes64DataReader _this,
    DDS_sequence_TP_Test_Bytes64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReader_read_next_instance (
    TP_Test_Bytes64DataReader _this,
    DDS_sequence_TP_Test_Bytes64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReader_take_next_instance (
    TP_Test_Bytes64DataReader _this,
    DDS_sequence_TP_Test_Bytes64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReader_read_next_instance_w_condition (
    TP_Test_Bytes64DataReader _this,
    DDS_sequence_TP_Test_Bytes64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReader_take_next_instance_w_condition (
    TP_Test_Bytes64DataReader _this,
    DDS_sequence_TP_Test_Bytes64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReader_return_loan (
    TP_Test_Bytes64DataReader _this,
    DDS_sequence_TP_Test_Bytes64 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReader_get_key_value (
    TP_Test_Bytes64DataReader _this,
    TP_Test_Bytes64 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes64DataReader_lookup_instance (
    TP_Test_Bytes64DataReader _this,
    const TP_Test_Bytes64 *key_holder
    );

#define TP_Test_Bytes64DataReaderView DDS_DataReaderView

#define TP_Test_Bytes64DataReaderView_enable DDS_Entity_enable

#define TP_Test_Bytes64DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes64DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Bytes64DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Bytes64DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Bytes64DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Bytes64DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Bytes64DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Bytes64DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Bytes64DataReaderView_read (
    TP_Test_Bytes64DataReaderView _this,
    DDS_sequence_TP_Test_Bytes64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReaderView_take (
    TP_Test_Bytes64DataReaderView _this,
    DDS_sequence_TP_Test_Bytes64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReaderView_read_next_sample (
    TP_Test_Bytes64DataReaderView _this,
    TP_Test_Bytes64 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReaderView_take_next_sample (
    TP_Test_Bytes64DataReaderView _this,
    TP_Test_Bytes64 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReaderView_read_instance (
    TP_Test_Bytes64DataReaderView _this,
    DDS_sequence_TP_Test_Bytes64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReaderView_take_instance (
    TP_Test_Bytes64DataReaderView _this,
    DDS_sequence_TP_Test_Bytes64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReaderView_read_next_instance (
    TP_Test_Bytes64DataReaderView _this,
    DDS_sequence_TP_Test_Bytes64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReaderView_take_next_instance (
    TP_Test_Bytes64DataReaderView _this,
    DDS_sequence_TP_Test_Bytes64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReaderView_return_loan (
    TP_Test_Bytes64DataReaderView _this,
    DDS_sequence_TP_Test_Bytes64 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReaderView_read_w_condition (
    TP_Test_Bytes64DataReaderView _this,
    DDS_sequence_TP_Test_Bytes64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReaderView_take_w_condition (
    TP_Test_Bytes64DataReaderView _this,
    DDS_sequence_TP_Test_Bytes64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReaderView_read_next_instance_w_condition (
    TP_Test_Bytes64DataReaderView _this,
    DDS_sequence_TP_Test_Bytes64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReaderView_take_next_instance_w_condition (
    TP_Test_Bytes64DataReaderView _this,
    DDS_sequence_TP_Test_Bytes64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes64DataReaderView_get_key_value (
    TP_Test_Bytes64DataReaderView _this,
    TP_Test_Bytes64 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes64DataReaderView_lookup_instance (
    TP_Test_Bytes64DataReaderView _this,
    TP_Test_Bytes64 *key_holder
    );



#define TP_Test_Bytes128TypeSupport DDS_TypeSupport

TP_Test_Bytes128TypeSupport
TP_Test_Bytes128TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Bytes128TypeSupport_register_type (
    TP_Test_Bytes128TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Bytes128TypeSupport_get_type_name (
    TP_Test_Bytes128TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Bytes128_defined
#define _DDS_sequence_TP_Test_Bytes128_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Bytes128 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Bytes128;

DDS_sequence_TP_Test_Bytes128 *DDS_sequence_TP_Test_Bytes128__alloc (void);
TP_Test_Bytes128 *DDS_sequence_TP_Test_Bytes128_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Bytes128_defined */

#define TP_Test_Bytes128DataWriter DDS_DataWriter

#define TP_Test_Bytes128DataWriter_enable DDS_Entity_enable

#define TP_Test_Bytes128DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes128DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes128DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes128DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Bytes128DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Bytes128DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Bytes128DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Bytes128DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Bytes128DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Bytes128DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Bytes128DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Bytes128DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Bytes128DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Bytes128DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Bytes128DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Bytes128DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Bytes128DataWriter_register_instance (
    TP_Test_Bytes128DataWriter _this,
    const TP_Test_Bytes128 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Bytes128DataWriter_register_instance_w_timestamp (
    TP_Test_Bytes128DataWriter _this,
    const TP_Test_Bytes128 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataWriter_unregister_instance (
    TP_Test_Bytes128DataWriter _this,
    const TP_Test_Bytes128 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataWriter_unregister_instance_w_timestamp (
    TP_Test_Bytes128DataWriter _this,
    const TP_Test_Bytes128 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataWriter_write (
    TP_Test_Bytes128DataWriter _this,
    const TP_Test_Bytes128 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataWriter_write_w_timestamp (
    TP_Test_Bytes128DataWriter _this,
    const TP_Test_Bytes128 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataWriter_dispose (
    TP_Test_Bytes128DataWriter _this,
    const TP_Test_Bytes128 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataWriter_dispose_w_timestamp (
    TP_Test_Bytes128DataWriter _this,
    const TP_Test_Bytes128 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataWriter_writedispose (
    TP_Test_Bytes128DataWriter _this,
    const TP_Test_Bytes128 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataWriter_writedispose_w_timestamp (
    TP_Test_Bytes128DataWriter _this,
    const TP_Test_Bytes128 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataWriter_get_key_value (
    TP_Test_Bytes128DataWriter _this,
    TP_Test_Bytes128 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Bytes128DataReader DDS_DataReader

#define TP_Test_Bytes128DataReader_enable DDS_Entity_enable

#define TP_Test_Bytes128DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes128DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes128DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes128DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Bytes128DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Bytes128DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Bytes128DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Bytes128DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Bytes128DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Bytes128DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Bytes128DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Bytes128DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Bytes128DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Bytes128DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Bytes128DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Bytes128DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Bytes128DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Bytes128DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Bytes128DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Bytes128DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Bytes128DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Bytes128DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Bytes128DataReader_read (
    TP_Test_Bytes128DataReader _this,
    DDS_sequence_TP_Test_Bytes128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReader_take (
    TP_Test_Bytes128DataReader _this,
    DDS_sequence_TP_Test_Bytes128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReader_read_w_condition (
    TP_Test_Bytes128DataReader _this,
    DDS_sequence_TP_Test_Bytes128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReader_take_w_condition (
    TP_Test_Bytes128DataReader _this,
    DDS_sequence_TP_Test_Bytes128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReader_read_next_sample (
    TP_Test_Bytes128DataReader _this,
    TP_Test_Bytes128 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReader_take_next_sample (
    TP_Test_Bytes128DataReader _this,
    TP_Test_Bytes128 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReader_read_instance (
    TP_Test_Bytes128DataReader _this,
    DDS_sequence_TP_Test_Bytes128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReader_take_instance (
    TP_Test_Bytes128DataReader _this,
    DDS_sequence_TP_Test_Bytes128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReader_read_next_instance (
    TP_Test_Bytes128DataReader _this,
    DDS_sequence_TP_Test_Bytes128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReader_take_next_instance (
    TP_Test_Bytes128DataReader _this,
    DDS_sequence_TP_Test_Bytes128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReader_read_next_instance_w_condition (
    TP_Test_Bytes128DataReader _this,
    DDS_sequence_TP_Test_Bytes128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReader_take_next_instance_w_condition (
    TP_Test_Bytes128DataReader _this,
    DDS_sequence_TP_Test_Bytes128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReader_return_loan (
    TP_Test_Bytes128DataReader _this,
    DDS_sequence_TP_Test_Bytes128 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReader_get_key_value (
    TP_Test_Bytes128DataReader _this,
    TP_Test_Bytes128 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes128DataReader_lookup_instance (
    TP_Test_Bytes128DataReader _this,
    const TP_Test_Bytes128 *key_holder
    );

#define TP_Test_Bytes128DataReaderView DDS_DataReaderView

#define TP_Test_Bytes128DataReaderView_enable DDS_Entity_enable

#define TP_Test_Bytes128DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes128DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Bytes128DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Bytes128DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Bytes128DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Bytes128DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Bytes128DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Bytes128DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Bytes128DataReaderView_read (
    TP_Test_Bytes128DataReaderView _this,
    DDS_sequence_TP_Test_Bytes128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReaderView_take (
    TP_Test_Bytes128DataReaderView _this,
    DDS_sequence_TP_Test_Bytes128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReaderView_read_next_sample (
    TP_Test_Bytes128DataReaderView _this,
    TP_Test_Bytes128 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReaderView_take_next_sample (
    TP_Test_Bytes128DataReaderView _this,
    TP_Test_Bytes128 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReaderView_read_instance (
    TP_Test_Bytes128DataReaderView _this,
    DDS_sequence_TP_Test_Bytes128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReaderView_take_instance (
    TP_Test_Bytes128DataReaderView _this,
    DDS_sequence_TP_Test_Bytes128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReaderView_read_next_instance (
    TP_Test_Bytes128DataReaderView _this,
    DDS_sequence_TP_Test_Bytes128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReaderView_take_next_instance (
    TP_Test_Bytes128DataReaderView _this,
    DDS_sequence_TP_Test_Bytes128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReaderView_return_loan (
    TP_Test_Bytes128DataReaderView _this,
    DDS_sequence_TP_Test_Bytes128 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReaderView_read_w_condition (
    TP_Test_Bytes128DataReaderView _this,
    DDS_sequence_TP_Test_Bytes128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReaderView_take_w_condition (
    TP_Test_Bytes128DataReaderView _this,
    DDS_sequence_TP_Test_Bytes128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReaderView_read_next_instance_w_condition (
    TP_Test_Bytes128DataReaderView _this,
    DDS_sequence_TP_Test_Bytes128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReaderView_take_next_instance_w_condition (
    TP_Test_Bytes128DataReaderView _this,
    DDS_sequence_TP_Test_Bytes128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes128DataReaderView_get_key_value (
    TP_Test_Bytes128DataReaderView _this,
    TP_Test_Bytes128 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes128DataReaderView_lookup_instance (
    TP_Test_Bytes128DataReaderView _this,
    TP_Test_Bytes128 *key_holder
    );



#define TP_Test_Bytes256TypeSupport DDS_TypeSupport

TP_Test_Bytes256TypeSupport
TP_Test_Bytes256TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Bytes256TypeSupport_register_type (
    TP_Test_Bytes256TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Bytes256TypeSupport_get_type_name (
    TP_Test_Bytes256TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Bytes256_defined
#define _DDS_sequence_TP_Test_Bytes256_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Bytes256 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Bytes256;

DDS_sequence_TP_Test_Bytes256 *DDS_sequence_TP_Test_Bytes256__alloc (void);
TP_Test_Bytes256 *DDS_sequence_TP_Test_Bytes256_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Bytes256_defined */

#define TP_Test_Bytes256DataWriter DDS_DataWriter

#define TP_Test_Bytes256DataWriter_enable DDS_Entity_enable

#define TP_Test_Bytes256DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes256DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes256DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes256DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Bytes256DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Bytes256DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Bytes256DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Bytes256DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Bytes256DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Bytes256DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Bytes256DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Bytes256DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Bytes256DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Bytes256DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Bytes256DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Bytes256DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Bytes256DataWriter_register_instance (
    TP_Test_Bytes256DataWriter _this,
    const TP_Test_Bytes256 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Bytes256DataWriter_register_instance_w_timestamp (
    TP_Test_Bytes256DataWriter _this,
    const TP_Test_Bytes256 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataWriter_unregister_instance (
    TP_Test_Bytes256DataWriter _this,
    const TP_Test_Bytes256 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataWriter_unregister_instance_w_timestamp (
    TP_Test_Bytes256DataWriter _this,
    const TP_Test_Bytes256 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataWriter_write (
    TP_Test_Bytes256DataWriter _this,
    const TP_Test_Bytes256 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataWriter_write_w_timestamp (
    TP_Test_Bytes256DataWriter _this,
    const TP_Test_Bytes256 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataWriter_dispose (
    TP_Test_Bytes256DataWriter _this,
    const TP_Test_Bytes256 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataWriter_dispose_w_timestamp (
    TP_Test_Bytes256DataWriter _this,
    const TP_Test_Bytes256 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataWriter_writedispose (
    TP_Test_Bytes256DataWriter _this,
    const TP_Test_Bytes256 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataWriter_writedispose_w_timestamp (
    TP_Test_Bytes256DataWriter _this,
    const TP_Test_Bytes256 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataWriter_get_key_value (
    TP_Test_Bytes256DataWriter _this,
    TP_Test_Bytes256 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Bytes256DataReader DDS_DataReader

#define TP_Test_Bytes256DataReader_enable DDS_Entity_enable

#define TP_Test_Bytes256DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes256DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes256DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes256DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Bytes256DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Bytes256DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Bytes256DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Bytes256DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Bytes256DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Bytes256DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Bytes256DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Bytes256DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Bytes256DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Bytes256DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Bytes256DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Bytes256DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Bytes256DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Bytes256DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Bytes256DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Bytes256DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Bytes256DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Bytes256DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Bytes256DataReader_read (
    TP_Test_Bytes256DataReader _this,
    DDS_sequence_TP_Test_Bytes256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReader_take (
    TP_Test_Bytes256DataReader _this,
    DDS_sequence_TP_Test_Bytes256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReader_read_w_condition (
    TP_Test_Bytes256DataReader _this,
    DDS_sequence_TP_Test_Bytes256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReader_take_w_condition (
    TP_Test_Bytes256DataReader _this,
    DDS_sequence_TP_Test_Bytes256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReader_read_next_sample (
    TP_Test_Bytes256DataReader _this,
    TP_Test_Bytes256 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReader_take_next_sample (
    TP_Test_Bytes256DataReader _this,
    TP_Test_Bytes256 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReader_read_instance (
    TP_Test_Bytes256DataReader _this,
    DDS_sequence_TP_Test_Bytes256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReader_take_instance (
    TP_Test_Bytes256DataReader _this,
    DDS_sequence_TP_Test_Bytes256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReader_read_next_instance (
    TP_Test_Bytes256DataReader _this,
    DDS_sequence_TP_Test_Bytes256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReader_take_next_instance (
    TP_Test_Bytes256DataReader _this,
    DDS_sequence_TP_Test_Bytes256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReader_read_next_instance_w_condition (
    TP_Test_Bytes256DataReader _this,
    DDS_sequence_TP_Test_Bytes256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReader_take_next_instance_w_condition (
    TP_Test_Bytes256DataReader _this,
    DDS_sequence_TP_Test_Bytes256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReader_return_loan (
    TP_Test_Bytes256DataReader _this,
    DDS_sequence_TP_Test_Bytes256 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReader_get_key_value (
    TP_Test_Bytes256DataReader _this,
    TP_Test_Bytes256 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes256DataReader_lookup_instance (
    TP_Test_Bytes256DataReader _this,
    const TP_Test_Bytes256 *key_holder
    );

#define TP_Test_Bytes256DataReaderView DDS_DataReaderView

#define TP_Test_Bytes256DataReaderView_enable DDS_Entity_enable

#define TP_Test_Bytes256DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes256DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Bytes256DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Bytes256DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Bytes256DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Bytes256DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Bytes256DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Bytes256DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Bytes256DataReaderView_read (
    TP_Test_Bytes256DataReaderView _this,
    DDS_sequence_TP_Test_Bytes256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReaderView_take (
    TP_Test_Bytes256DataReaderView _this,
    DDS_sequence_TP_Test_Bytes256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReaderView_read_next_sample (
    TP_Test_Bytes256DataReaderView _this,
    TP_Test_Bytes256 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReaderView_take_next_sample (
    TP_Test_Bytes256DataReaderView _this,
    TP_Test_Bytes256 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReaderView_read_instance (
    TP_Test_Bytes256DataReaderView _this,
    DDS_sequence_TP_Test_Bytes256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReaderView_take_instance (
    TP_Test_Bytes256DataReaderView _this,
    DDS_sequence_TP_Test_Bytes256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReaderView_read_next_instance (
    TP_Test_Bytes256DataReaderView _this,
    DDS_sequence_TP_Test_Bytes256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReaderView_take_next_instance (
    TP_Test_Bytes256DataReaderView _this,
    DDS_sequence_TP_Test_Bytes256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReaderView_return_loan (
    TP_Test_Bytes256DataReaderView _this,
    DDS_sequence_TP_Test_Bytes256 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReaderView_read_w_condition (
    TP_Test_Bytes256DataReaderView _this,
    DDS_sequence_TP_Test_Bytes256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReaderView_take_w_condition (
    TP_Test_Bytes256DataReaderView _this,
    DDS_sequence_TP_Test_Bytes256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReaderView_read_next_instance_w_condition (
    TP_Test_Bytes256DataReaderView _this,
    DDS_sequence_TP_Test_Bytes256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReaderView_take_next_instance_w_condition (
    TP_Test_Bytes256DataReaderView _this,
    DDS_sequence_TP_Test_Bytes256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes256DataReaderView_get_key_value (
    TP_Test_Bytes256DataReaderView _this,
    TP_Test_Bytes256 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes256DataReaderView_lookup_instance (
    TP_Test_Bytes256DataReaderView _this,
    TP_Test_Bytes256 *key_holder
    );



#define TP_Test_Bytes512TypeSupport DDS_TypeSupport

TP_Test_Bytes512TypeSupport
TP_Test_Bytes512TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Bytes512TypeSupport_register_type (
    TP_Test_Bytes512TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Bytes512TypeSupport_get_type_name (
    TP_Test_Bytes512TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Bytes512_defined
#define _DDS_sequence_TP_Test_Bytes512_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Bytes512 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Bytes512;

DDS_sequence_TP_Test_Bytes512 *DDS_sequence_TP_Test_Bytes512__alloc (void);
TP_Test_Bytes512 *DDS_sequence_TP_Test_Bytes512_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Bytes512_defined */

#define TP_Test_Bytes512DataWriter DDS_DataWriter

#define TP_Test_Bytes512DataWriter_enable DDS_Entity_enable

#define TP_Test_Bytes512DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes512DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes512DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes512DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Bytes512DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Bytes512DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Bytes512DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Bytes512DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Bytes512DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Bytes512DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Bytes512DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Bytes512DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Bytes512DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Bytes512DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Bytes512DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Bytes512DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Bytes512DataWriter_register_instance (
    TP_Test_Bytes512DataWriter _this,
    const TP_Test_Bytes512 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Bytes512DataWriter_register_instance_w_timestamp (
    TP_Test_Bytes512DataWriter _this,
    const TP_Test_Bytes512 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataWriter_unregister_instance (
    TP_Test_Bytes512DataWriter _this,
    const TP_Test_Bytes512 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataWriter_unregister_instance_w_timestamp (
    TP_Test_Bytes512DataWriter _this,
    const TP_Test_Bytes512 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataWriter_write (
    TP_Test_Bytes512DataWriter _this,
    const TP_Test_Bytes512 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataWriter_write_w_timestamp (
    TP_Test_Bytes512DataWriter _this,
    const TP_Test_Bytes512 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataWriter_dispose (
    TP_Test_Bytes512DataWriter _this,
    const TP_Test_Bytes512 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataWriter_dispose_w_timestamp (
    TP_Test_Bytes512DataWriter _this,
    const TP_Test_Bytes512 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataWriter_writedispose (
    TP_Test_Bytes512DataWriter _this,
    const TP_Test_Bytes512 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataWriter_writedispose_w_timestamp (
    TP_Test_Bytes512DataWriter _this,
    const TP_Test_Bytes512 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataWriter_get_key_value (
    TP_Test_Bytes512DataWriter _this,
    TP_Test_Bytes512 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Bytes512DataReader DDS_DataReader

#define TP_Test_Bytes512DataReader_enable DDS_Entity_enable

#define TP_Test_Bytes512DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes512DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes512DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes512DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Bytes512DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Bytes512DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Bytes512DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Bytes512DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Bytes512DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Bytes512DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Bytes512DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Bytes512DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Bytes512DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Bytes512DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Bytes512DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Bytes512DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Bytes512DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Bytes512DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Bytes512DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Bytes512DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Bytes512DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Bytes512DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Bytes512DataReader_read (
    TP_Test_Bytes512DataReader _this,
    DDS_sequence_TP_Test_Bytes512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReader_take (
    TP_Test_Bytes512DataReader _this,
    DDS_sequence_TP_Test_Bytes512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReader_read_w_condition (
    TP_Test_Bytes512DataReader _this,
    DDS_sequence_TP_Test_Bytes512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReader_take_w_condition (
    TP_Test_Bytes512DataReader _this,
    DDS_sequence_TP_Test_Bytes512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReader_read_next_sample (
    TP_Test_Bytes512DataReader _this,
    TP_Test_Bytes512 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReader_take_next_sample (
    TP_Test_Bytes512DataReader _this,
    TP_Test_Bytes512 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReader_read_instance (
    TP_Test_Bytes512DataReader _this,
    DDS_sequence_TP_Test_Bytes512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReader_take_instance (
    TP_Test_Bytes512DataReader _this,
    DDS_sequence_TP_Test_Bytes512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReader_read_next_instance (
    TP_Test_Bytes512DataReader _this,
    DDS_sequence_TP_Test_Bytes512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReader_take_next_instance (
    TP_Test_Bytes512DataReader _this,
    DDS_sequence_TP_Test_Bytes512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReader_read_next_instance_w_condition (
    TP_Test_Bytes512DataReader _this,
    DDS_sequence_TP_Test_Bytes512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReader_take_next_instance_w_condition (
    TP_Test_Bytes512DataReader _this,
    DDS_sequence_TP_Test_Bytes512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReader_return_loan (
    TP_Test_Bytes512DataReader _this,
    DDS_sequence_TP_Test_Bytes512 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReader_get_key_value (
    TP_Test_Bytes512DataReader _this,
    TP_Test_Bytes512 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes512DataReader_lookup_instance (
    TP_Test_Bytes512DataReader _this,
    const TP_Test_Bytes512 *key_holder
    );

#define TP_Test_Bytes512DataReaderView DDS_DataReaderView

#define TP_Test_Bytes512DataReaderView_enable DDS_Entity_enable

#define TP_Test_Bytes512DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes512DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Bytes512DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Bytes512DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Bytes512DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Bytes512DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Bytes512DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Bytes512DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Bytes512DataReaderView_read (
    TP_Test_Bytes512DataReaderView _this,
    DDS_sequence_TP_Test_Bytes512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReaderView_take (
    TP_Test_Bytes512DataReaderView _this,
    DDS_sequence_TP_Test_Bytes512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReaderView_read_next_sample (
    TP_Test_Bytes512DataReaderView _this,
    TP_Test_Bytes512 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReaderView_take_next_sample (
    TP_Test_Bytes512DataReaderView _this,
    TP_Test_Bytes512 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReaderView_read_instance (
    TP_Test_Bytes512DataReaderView _this,
    DDS_sequence_TP_Test_Bytes512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReaderView_take_instance (
    TP_Test_Bytes512DataReaderView _this,
    DDS_sequence_TP_Test_Bytes512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReaderView_read_next_instance (
    TP_Test_Bytes512DataReaderView _this,
    DDS_sequence_TP_Test_Bytes512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReaderView_take_next_instance (
    TP_Test_Bytes512DataReaderView _this,
    DDS_sequence_TP_Test_Bytes512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReaderView_return_loan (
    TP_Test_Bytes512DataReaderView _this,
    DDS_sequence_TP_Test_Bytes512 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReaderView_read_w_condition (
    TP_Test_Bytes512DataReaderView _this,
    DDS_sequence_TP_Test_Bytes512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReaderView_take_w_condition (
    TP_Test_Bytes512DataReaderView _this,
    DDS_sequence_TP_Test_Bytes512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReaderView_read_next_instance_w_condition (
    TP_Test_Bytes512DataReaderView _this,
    DDS_sequence_TP_Test_Bytes512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReaderView_take_next_instance_w_condition (
    TP_Test_Bytes512DataReaderView _this,
    DDS_sequence_TP_Test_Bytes512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes512DataReaderView_get_key_value (
    TP_Test_Bytes512DataReaderView _this,
    TP_Test_Bytes512 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes512DataReaderView_lookup_instance (
    TP_Test_Bytes512DataReaderView _this,
    TP_Test_Bytes512 *key_holder
    );



#define TP_Test_Bytes1024TypeSupport DDS_TypeSupport

TP_Test_Bytes1024TypeSupport
TP_Test_Bytes1024TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Bytes1024TypeSupport_register_type (
    TP_Test_Bytes1024TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Bytes1024TypeSupport_get_type_name (
    TP_Test_Bytes1024TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Bytes1024_defined
#define _DDS_sequence_TP_Test_Bytes1024_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Bytes1024 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Bytes1024;

DDS_sequence_TP_Test_Bytes1024 *DDS_sequence_TP_Test_Bytes1024__alloc (void);
TP_Test_Bytes1024 *DDS_sequence_TP_Test_Bytes1024_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Bytes1024_defined */

#define TP_Test_Bytes1024DataWriter DDS_DataWriter

#define TP_Test_Bytes1024DataWriter_enable DDS_Entity_enable

#define TP_Test_Bytes1024DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes1024DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes1024DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes1024DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Bytes1024DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Bytes1024DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Bytes1024DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Bytes1024DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Bytes1024DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Bytes1024DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Bytes1024DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Bytes1024DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Bytes1024DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Bytes1024DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Bytes1024DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Bytes1024DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Bytes1024DataWriter_register_instance (
    TP_Test_Bytes1024DataWriter _this,
    const TP_Test_Bytes1024 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Bytes1024DataWriter_register_instance_w_timestamp (
    TP_Test_Bytes1024DataWriter _this,
    const TP_Test_Bytes1024 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataWriter_unregister_instance (
    TP_Test_Bytes1024DataWriter _this,
    const TP_Test_Bytes1024 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataWriter_unregister_instance_w_timestamp (
    TP_Test_Bytes1024DataWriter _this,
    const TP_Test_Bytes1024 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataWriter_write (
    TP_Test_Bytes1024DataWriter _this,
    const TP_Test_Bytes1024 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataWriter_write_w_timestamp (
    TP_Test_Bytes1024DataWriter _this,
    const TP_Test_Bytes1024 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataWriter_dispose (
    TP_Test_Bytes1024DataWriter _this,
    const TP_Test_Bytes1024 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataWriter_dispose_w_timestamp (
    TP_Test_Bytes1024DataWriter _this,
    const TP_Test_Bytes1024 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataWriter_writedispose (
    TP_Test_Bytes1024DataWriter _this,
    const TP_Test_Bytes1024 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataWriter_writedispose_w_timestamp (
    TP_Test_Bytes1024DataWriter _this,
    const TP_Test_Bytes1024 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataWriter_get_key_value (
    TP_Test_Bytes1024DataWriter _this,
    TP_Test_Bytes1024 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Bytes1024DataReader DDS_DataReader

#define TP_Test_Bytes1024DataReader_enable DDS_Entity_enable

#define TP_Test_Bytes1024DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes1024DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes1024DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes1024DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Bytes1024DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Bytes1024DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Bytes1024DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Bytes1024DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Bytes1024DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Bytes1024DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Bytes1024DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Bytes1024DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Bytes1024DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Bytes1024DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Bytes1024DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Bytes1024DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Bytes1024DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Bytes1024DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Bytes1024DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Bytes1024DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Bytes1024DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Bytes1024DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Bytes1024DataReader_read (
    TP_Test_Bytes1024DataReader _this,
    DDS_sequence_TP_Test_Bytes1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReader_take (
    TP_Test_Bytes1024DataReader _this,
    DDS_sequence_TP_Test_Bytes1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReader_read_w_condition (
    TP_Test_Bytes1024DataReader _this,
    DDS_sequence_TP_Test_Bytes1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReader_take_w_condition (
    TP_Test_Bytes1024DataReader _this,
    DDS_sequence_TP_Test_Bytes1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReader_read_next_sample (
    TP_Test_Bytes1024DataReader _this,
    TP_Test_Bytes1024 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReader_take_next_sample (
    TP_Test_Bytes1024DataReader _this,
    TP_Test_Bytes1024 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReader_read_instance (
    TP_Test_Bytes1024DataReader _this,
    DDS_sequence_TP_Test_Bytes1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReader_take_instance (
    TP_Test_Bytes1024DataReader _this,
    DDS_sequence_TP_Test_Bytes1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReader_read_next_instance (
    TP_Test_Bytes1024DataReader _this,
    DDS_sequence_TP_Test_Bytes1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReader_take_next_instance (
    TP_Test_Bytes1024DataReader _this,
    DDS_sequence_TP_Test_Bytes1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReader_read_next_instance_w_condition (
    TP_Test_Bytes1024DataReader _this,
    DDS_sequence_TP_Test_Bytes1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReader_take_next_instance_w_condition (
    TP_Test_Bytes1024DataReader _this,
    DDS_sequence_TP_Test_Bytes1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReader_return_loan (
    TP_Test_Bytes1024DataReader _this,
    DDS_sequence_TP_Test_Bytes1024 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReader_get_key_value (
    TP_Test_Bytes1024DataReader _this,
    TP_Test_Bytes1024 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes1024DataReader_lookup_instance (
    TP_Test_Bytes1024DataReader _this,
    const TP_Test_Bytes1024 *key_holder
    );

#define TP_Test_Bytes1024DataReaderView DDS_DataReaderView

#define TP_Test_Bytes1024DataReaderView_enable DDS_Entity_enable

#define TP_Test_Bytes1024DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes1024DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Bytes1024DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Bytes1024DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Bytes1024DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Bytes1024DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Bytes1024DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Bytes1024DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Bytes1024DataReaderView_read (
    TP_Test_Bytes1024DataReaderView _this,
    DDS_sequence_TP_Test_Bytes1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReaderView_take (
    TP_Test_Bytes1024DataReaderView _this,
    DDS_sequence_TP_Test_Bytes1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReaderView_read_next_sample (
    TP_Test_Bytes1024DataReaderView _this,
    TP_Test_Bytes1024 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReaderView_take_next_sample (
    TP_Test_Bytes1024DataReaderView _this,
    TP_Test_Bytes1024 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReaderView_read_instance (
    TP_Test_Bytes1024DataReaderView _this,
    DDS_sequence_TP_Test_Bytes1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReaderView_take_instance (
    TP_Test_Bytes1024DataReaderView _this,
    DDS_sequence_TP_Test_Bytes1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReaderView_read_next_instance (
    TP_Test_Bytes1024DataReaderView _this,
    DDS_sequence_TP_Test_Bytes1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReaderView_take_next_instance (
    TP_Test_Bytes1024DataReaderView _this,
    DDS_sequence_TP_Test_Bytes1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReaderView_return_loan (
    TP_Test_Bytes1024DataReaderView _this,
    DDS_sequence_TP_Test_Bytes1024 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReaderView_read_w_condition (
    TP_Test_Bytes1024DataReaderView _this,
    DDS_sequence_TP_Test_Bytes1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReaderView_take_w_condition (
    TP_Test_Bytes1024DataReaderView _this,
    DDS_sequence_TP_Test_Bytes1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReaderView_read_next_instance_w_condition (
    TP_Test_Bytes1024DataReaderView _this,
    DDS_sequence_TP_Test_Bytes1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReaderView_take_next_instance_w_condition (
    TP_Test_Bytes1024DataReaderView _this,
    DDS_sequence_TP_Test_Bytes1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes1024DataReaderView_get_key_value (
    TP_Test_Bytes1024DataReaderView _this,
    TP_Test_Bytes1024 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes1024DataReaderView_lookup_instance (
    TP_Test_Bytes1024DataReaderView _this,
    TP_Test_Bytes1024 *key_holder
    );



#define TP_Test_Bytes2048TypeSupport DDS_TypeSupport

TP_Test_Bytes2048TypeSupport
TP_Test_Bytes2048TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Bytes2048TypeSupport_register_type (
    TP_Test_Bytes2048TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Bytes2048TypeSupport_get_type_name (
    TP_Test_Bytes2048TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Bytes2048_defined
#define _DDS_sequence_TP_Test_Bytes2048_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Bytes2048 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Bytes2048;

DDS_sequence_TP_Test_Bytes2048 *DDS_sequence_TP_Test_Bytes2048__alloc (void);
TP_Test_Bytes2048 *DDS_sequence_TP_Test_Bytes2048_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Bytes2048_defined */

#define TP_Test_Bytes2048DataWriter DDS_DataWriter

#define TP_Test_Bytes2048DataWriter_enable DDS_Entity_enable

#define TP_Test_Bytes2048DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes2048DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes2048DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes2048DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Bytes2048DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Bytes2048DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Bytes2048DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Bytes2048DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Bytes2048DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Bytes2048DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Bytes2048DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Bytes2048DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Bytes2048DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Bytes2048DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Bytes2048DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Bytes2048DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Bytes2048DataWriter_register_instance (
    TP_Test_Bytes2048DataWriter _this,
    const TP_Test_Bytes2048 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Bytes2048DataWriter_register_instance_w_timestamp (
    TP_Test_Bytes2048DataWriter _this,
    const TP_Test_Bytes2048 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataWriter_unregister_instance (
    TP_Test_Bytes2048DataWriter _this,
    const TP_Test_Bytes2048 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataWriter_unregister_instance_w_timestamp (
    TP_Test_Bytes2048DataWriter _this,
    const TP_Test_Bytes2048 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataWriter_write (
    TP_Test_Bytes2048DataWriter _this,
    const TP_Test_Bytes2048 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataWriter_write_w_timestamp (
    TP_Test_Bytes2048DataWriter _this,
    const TP_Test_Bytes2048 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataWriter_dispose (
    TP_Test_Bytes2048DataWriter _this,
    const TP_Test_Bytes2048 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataWriter_dispose_w_timestamp (
    TP_Test_Bytes2048DataWriter _this,
    const TP_Test_Bytes2048 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataWriter_writedispose (
    TP_Test_Bytes2048DataWriter _this,
    const TP_Test_Bytes2048 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataWriter_writedispose_w_timestamp (
    TP_Test_Bytes2048DataWriter _this,
    const TP_Test_Bytes2048 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataWriter_get_key_value (
    TP_Test_Bytes2048DataWriter _this,
    TP_Test_Bytes2048 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Bytes2048DataReader DDS_DataReader

#define TP_Test_Bytes2048DataReader_enable DDS_Entity_enable

#define TP_Test_Bytes2048DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes2048DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes2048DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes2048DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Bytes2048DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Bytes2048DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Bytes2048DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Bytes2048DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Bytes2048DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Bytes2048DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Bytes2048DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Bytes2048DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Bytes2048DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Bytes2048DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Bytes2048DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Bytes2048DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Bytes2048DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Bytes2048DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Bytes2048DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Bytes2048DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Bytes2048DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Bytes2048DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Bytes2048DataReader_read (
    TP_Test_Bytes2048DataReader _this,
    DDS_sequence_TP_Test_Bytes2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReader_take (
    TP_Test_Bytes2048DataReader _this,
    DDS_sequence_TP_Test_Bytes2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReader_read_w_condition (
    TP_Test_Bytes2048DataReader _this,
    DDS_sequence_TP_Test_Bytes2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReader_take_w_condition (
    TP_Test_Bytes2048DataReader _this,
    DDS_sequence_TP_Test_Bytes2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReader_read_next_sample (
    TP_Test_Bytes2048DataReader _this,
    TP_Test_Bytes2048 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReader_take_next_sample (
    TP_Test_Bytes2048DataReader _this,
    TP_Test_Bytes2048 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReader_read_instance (
    TP_Test_Bytes2048DataReader _this,
    DDS_sequence_TP_Test_Bytes2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReader_take_instance (
    TP_Test_Bytes2048DataReader _this,
    DDS_sequence_TP_Test_Bytes2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReader_read_next_instance (
    TP_Test_Bytes2048DataReader _this,
    DDS_sequence_TP_Test_Bytes2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReader_take_next_instance (
    TP_Test_Bytes2048DataReader _this,
    DDS_sequence_TP_Test_Bytes2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReader_read_next_instance_w_condition (
    TP_Test_Bytes2048DataReader _this,
    DDS_sequence_TP_Test_Bytes2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReader_take_next_instance_w_condition (
    TP_Test_Bytes2048DataReader _this,
    DDS_sequence_TP_Test_Bytes2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReader_return_loan (
    TP_Test_Bytes2048DataReader _this,
    DDS_sequence_TP_Test_Bytes2048 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReader_get_key_value (
    TP_Test_Bytes2048DataReader _this,
    TP_Test_Bytes2048 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes2048DataReader_lookup_instance (
    TP_Test_Bytes2048DataReader _this,
    const TP_Test_Bytes2048 *key_holder
    );

#define TP_Test_Bytes2048DataReaderView DDS_DataReaderView

#define TP_Test_Bytes2048DataReaderView_enable DDS_Entity_enable

#define TP_Test_Bytes2048DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes2048DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Bytes2048DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Bytes2048DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Bytes2048DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Bytes2048DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Bytes2048DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Bytes2048DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Bytes2048DataReaderView_read (
    TP_Test_Bytes2048DataReaderView _this,
    DDS_sequence_TP_Test_Bytes2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReaderView_take (
    TP_Test_Bytes2048DataReaderView _this,
    DDS_sequence_TP_Test_Bytes2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReaderView_read_next_sample (
    TP_Test_Bytes2048DataReaderView _this,
    TP_Test_Bytes2048 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReaderView_take_next_sample (
    TP_Test_Bytes2048DataReaderView _this,
    TP_Test_Bytes2048 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReaderView_read_instance (
    TP_Test_Bytes2048DataReaderView _this,
    DDS_sequence_TP_Test_Bytes2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReaderView_take_instance (
    TP_Test_Bytes2048DataReaderView _this,
    DDS_sequence_TP_Test_Bytes2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReaderView_read_next_instance (
    TP_Test_Bytes2048DataReaderView _this,
    DDS_sequence_TP_Test_Bytes2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReaderView_take_next_instance (
    TP_Test_Bytes2048DataReaderView _this,
    DDS_sequence_TP_Test_Bytes2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReaderView_return_loan (
    TP_Test_Bytes2048DataReaderView _this,
    DDS_sequence_TP_Test_Bytes2048 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReaderView_read_w_condition (
    TP_Test_Bytes2048DataReaderView _this,
    DDS_sequence_TP_Test_Bytes2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReaderView_take_w_condition (
    TP_Test_Bytes2048DataReaderView _this,
    DDS_sequence_TP_Test_Bytes2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReaderView_read_next_instance_w_condition (
    TP_Test_Bytes2048DataReaderView _this,
    DDS_sequence_TP_Test_Bytes2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReaderView_take_next_instance_w_condition (
    TP_Test_Bytes2048DataReaderView _this,
    DDS_sequence_TP_Test_Bytes2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes2048DataReaderView_get_key_value (
    TP_Test_Bytes2048DataReaderView _this,
    TP_Test_Bytes2048 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes2048DataReaderView_lookup_instance (
    TP_Test_Bytes2048DataReaderView _this,
    TP_Test_Bytes2048 *key_holder
    );



#define TP_Test_Bytes4096TypeSupport DDS_TypeSupport

TP_Test_Bytes4096TypeSupport
TP_Test_Bytes4096TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Bytes4096TypeSupport_register_type (
    TP_Test_Bytes4096TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Bytes4096TypeSupport_get_type_name (
    TP_Test_Bytes4096TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Bytes4096_defined
#define _DDS_sequence_TP_Test_Bytes4096_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Bytes4096 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Bytes4096;

DDS_sequence_TP_Test_Bytes4096 *DDS_sequence_TP_Test_Bytes4096__alloc (void);
TP_Test_Bytes4096 *DDS_sequence_TP_Test_Bytes4096_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Bytes4096_defined */

#define TP_Test_Bytes4096DataWriter DDS_DataWriter

#define TP_Test_Bytes4096DataWriter_enable DDS_Entity_enable

#define TP_Test_Bytes4096DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes4096DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes4096DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes4096DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Bytes4096DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Bytes4096DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Bytes4096DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Bytes4096DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Bytes4096DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Bytes4096DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Bytes4096DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Bytes4096DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Bytes4096DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Bytes4096DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Bytes4096DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Bytes4096DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Bytes4096DataWriter_register_instance (
    TP_Test_Bytes4096DataWriter _this,
    const TP_Test_Bytes4096 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Bytes4096DataWriter_register_instance_w_timestamp (
    TP_Test_Bytes4096DataWriter _this,
    const TP_Test_Bytes4096 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataWriter_unregister_instance (
    TP_Test_Bytes4096DataWriter _this,
    const TP_Test_Bytes4096 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataWriter_unregister_instance_w_timestamp (
    TP_Test_Bytes4096DataWriter _this,
    const TP_Test_Bytes4096 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataWriter_write (
    TP_Test_Bytes4096DataWriter _this,
    const TP_Test_Bytes4096 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataWriter_write_w_timestamp (
    TP_Test_Bytes4096DataWriter _this,
    const TP_Test_Bytes4096 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataWriter_dispose (
    TP_Test_Bytes4096DataWriter _this,
    const TP_Test_Bytes4096 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataWriter_dispose_w_timestamp (
    TP_Test_Bytes4096DataWriter _this,
    const TP_Test_Bytes4096 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataWriter_writedispose (
    TP_Test_Bytes4096DataWriter _this,
    const TP_Test_Bytes4096 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataWriter_writedispose_w_timestamp (
    TP_Test_Bytes4096DataWriter _this,
    const TP_Test_Bytes4096 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataWriter_get_key_value (
    TP_Test_Bytes4096DataWriter _this,
    TP_Test_Bytes4096 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Bytes4096DataReader DDS_DataReader

#define TP_Test_Bytes4096DataReader_enable DDS_Entity_enable

#define TP_Test_Bytes4096DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes4096DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes4096DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes4096DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Bytes4096DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Bytes4096DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Bytes4096DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Bytes4096DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Bytes4096DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Bytes4096DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Bytes4096DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Bytes4096DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Bytes4096DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Bytes4096DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Bytes4096DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Bytes4096DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Bytes4096DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Bytes4096DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Bytes4096DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Bytes4096DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Bytes4096DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Bytes4096DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Bytes4096DataReader_read (
    TP_Test_Bytes4096DataReader _this,
    DDS_sequence_TP_Test_Bytes4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReader_take (
    TP_Test_Bytes4096DataReader _this,
    DDS_sequence_TP_Test_Bytes4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReader_read_w_condition (
    TP_Test_Bytes4096DataReader _this,
    DDS_sequence_TP_Test_Bytes4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReader_take_w_condition (
    TP_Test_Bytes4096DataReader _this,
    DDS_sequence_TP_Test_Bytes4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReader_read_next_sample (
    TP_Test_Bytes4096DataReader _this,
    TP_Test_Bytes4096 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReader_take_next_sample (
    TP_Test_Bytes4096DataReader _this,
    TP_Test_Bytes4096 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReader_read_instance (
    TP_Test_Bytes4096DataReader _this,
    DDS_sequence_TP_Test_Bytes4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReader_take_instance (
    TP_Test_Bytes4096DataReader _this,
    DDS_sequence_TP_Test_Bytes4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReader_read_next_instance (
    TP_Test_Bytes4096DataReader _this,
    DDS_sequence_TP_Test_Bytes4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReader_take_next_instance (
    TP_Test_Bytes4096DataReader _this,
    DDS_sequence_TP_Test_Bytes4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReader_read_next_instance_w_condition (
    TP_Test_Bytes4096DataReader _this,
    DDS_sequence_TP_Test_Bytes4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReader_take_next_instance_w_condition (
    TP_Test_Bytes4096DataReader _this,
    DDS_sequence_TP_Test_Bytes4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReader_return_loan (
    TP_Test_Bytes4096DataReader _this,
    DDS_sequence_TP_Test_Bytes4096 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReader_get_key_value (
    TP_Test_Bytes4096DataReader _this,
    TP_Test_Bytes4096 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes4096DataReader_lookup_instance (
    TP_Test_Bytes4096DataReader _this,
    const TP_Test_Bytes4096 *key_holder
    );

#define TP_Test_Bytes4096DataReaderView DDS_DataReaderView

#define TP_Test_Bytes4096DataReaderView_enable DDS_Entity_enable

#define TP_Test_Bytes4096DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes4096DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Bytes4096DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Bytes4096DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Bytes4096DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Bytes4096DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Bytes4096DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Bytes4096DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Bytes4096DataReaderView_read (
    TP_Test_Bytes4096DataReaderView _this,
    DDS_sequence_TP_Test_Bytes4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReaderView_take (
    TP_Test_Bytes4096DataReaderView _this,
    DDS_sequence_TP_Test_Bytes4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReaderView_read_next_sample (
    TP_Test_Bytes4096DataReaderView _this,
    TP_Test_Bytes4096 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReaderView_take_next_sample (
    TP_Test_Bytes4096DataReaderView _this,
    TP_Test_Bytes4096 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReaderView_read_instance (
    TP_Test_Bytes4096DataReaderView _this,
    DDS_sequence_TP_Test_Bytes4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReaderView_take_instance (
    TP_Test_Bytes4096DataReaderView _this,
    DDS_sequence_TP_Test_Bytes4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReaderView_read_next_instance (
    TP_Test_Bytes4096DataReaderView _this,
    DDS_sequence_TP_Test_Bytes4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReaderView_take_next_instance (
    TP_Test_Bytes4096DataReaderView _this,
    DDS_sequence_TP_Test_Bytes4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReaderView_return_loan (
    TP_Test_Bytes4096DataReaderView _this,
    DDS_sequence_TP_Test_Bytes4096 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReaderView_read_w_condition (
    TP_Test_Bytes4096DataReaderView _this,
    DDS_sequence_TP_Test_Bytes4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReaderView_take_w_condition (
    TP_Test_Bytes4096DataReaderView _this,
    DDS_sequence_TP_Test_Bytes4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReaderView_read_next_instance_w_condition (
    TP_Test_Bytes4096DataReaderView _this,
    DDS_sequence_TP_Test_Bytes4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReaderView_take_next_instance_w_condition (
    TP_Test_Bytes4096DataReaderView _this,
    DDS_sequence_TP_Test_Bytes4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes4096DataReaderView_get_key_value (
    TP_Test_Bytes4096DataReaderView _this,
    TP_Test_Bytes4096 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes4096DataReaderView_lookup_instance (
    TP_Test_Bytes4096DataReaderView _this,
    TP_Test_Bytes4096 *key_holder
    );



#define TP_Test_Bytes8192TypeSupport DDS_TypeSupport

TP_Test_Bytes8192TypeSupport
TP_Test_Bytes8192TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Bytes8192TypeSupport_register_type (
    TP_Test_Bytes8192TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Bytes8192TypeSupport_get_type_name (
    TP_Test_Bytes8192TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Bytes8192_defined
#define _DDS_sequence_TP_Test_Bytes8192_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Bytes8192 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Bytes8192;

DDS_sequence_TP_Test_Bytes8192 *DDS_sequence_TP_Test_Bytes8192__alloc (void);
TP_Test_Bytes8192 *DDS_sequence_TP_Test_Bytes8192_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Bytes8192_defined */

#define TP_Test_Bytes8192DataWriter DDS_DataWriter

#define TP_Test_Bytes8192DataWriter_enable DDS_Entity_enable

#define TP_Test_Bytes8192DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes8192DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes8192DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes8192DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Bytes8192DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Bytes8192DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Bytes8192DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Bytes8192DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Bytes8192DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Bytes8192DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Bytes8192DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Bytes8192DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Bytes8192DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Bytes8192DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Bytes8192DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Bytes8192DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Bytes8192DataWriter_register_instance (
    TP_Test_Bytes8192DataWriter _this,
    const TP_Test_Bytes8192 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Bytes8192DataWriter_register_instance_w_timestamp (
    TP_Test_Bytes8192DataWriter _this,
    const TP_Test_Bytes8192 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataWriter_unregister_instance (
    TP_Test_Bytes8192DataWriter _this,
    const TP_Test_Bytes8192 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataWriter_unregister_instance_w_timestamp (
    TP_Test_Bytes8192DataWriter _this,
    const TP_Test_Bytes8192 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataWriter_write (
    TP_Test_Bytes8192DataWriter _this,
    const TP_Test_Bytes8192 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataWriter_write_w_timestamp (
    TP_Test_Bytes8192DataWriter _this,
    const TP_Test_Bytes8192 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataWriter_dispose (
    TP_Test_Bytes8192DataWriter _this,
    const TP_Test_Bytes8192 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataWriter_dispose_w_timestamp (
    TP_Test_Bytes8192DataWriter _this,
    const TP_Test_Bytes8192 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataWriter_writedispose (
    TP_Test_Bytes8192DataWriter _this,
    const TP_Test_Bytes8192 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataWriter_writedispose_w_timestamp (
    TP_Test_Bytes8192DataWriter _this,
    const TP_Test_Bytes8192 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataWriter_get_key_value (
    TP_Test_Bytes8192DataWriter _this,
    TP_Test_Bytes8192 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Bytes8192DataReader DDS_DataReader

#define TP_Test_Bytes8192DataReader_enable DDS_Entity_enable

#define TP_Test_Bytes8192DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes8192DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes8192DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes8192DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Bytes8192DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Bytes8192DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Bytes8192DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Bytes8192DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Bytes8192DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Bytes8192DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Bytes8192DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Bytes8192DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Bytes8192DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Bytes8192DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Bytes8192DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Bytes8192DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Bytes8192DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Bytes8192DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Bytes8192DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Bytes8192DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Bytes8192DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Bytes8192DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Bytes8192DataReader_read (
    TP_Test_Bytes8192DataReader _this,
    DDS_sequence_TP_Test_Bytes8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReader_take (
    TP_Test_Bytes8192DataReader _this,
    DDS_sequence_TP_Test_Bytes8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReader_read_w_condition (
    TP_Test_Bytes8192DataReader _this,
    DDS_sequence_TP_Test_Bytes8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReader_take_w_condition (
    TP_Test_Bytes8192DataReader _this,
    DDS_sequence_TP_Test_Bytes8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReader_read_next_sample (
    TP_Test_Bytes8192DataReader _this,
    TP_Test_Bytes8192 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReader_take_next_sample (
    TP_Test_Bytes8192DataReader _this,
    TP_Test_Bytes8192 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReader_read_instance (
    TP_Test_Bytes8192DataReader _this,
    DDS_sequence_TP_Test_Bytes8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReader_take_instance (
    TP_Test_Bytes8192DataReader _this,
    DDS_sequence_TP_Test_Bytes8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReader_read_next_instance (
    TP_Test_Bytes8192DataReader _this,
    DDS_sequence_TP_Test_Bytes8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReader_take_next_instance (
    TP_Test_Bytes8192DataReader _this,
    DDS_sequence_TP_Test_Bytes8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReader_read_next_instance_w_condition (
    TP_Test_Bytes8192DataReader _this,
    DDS_sequence_TP_Test_Bytes8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReader_take_next_instance_w_condition (
    TP_Test_Bytes8192DataReader _this,
    DDS_sequence_TP_Test_Bytes8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReader_return_loan (
    TP_Test_Bytes8192DataReader _this,
    DDS_sequence_TP_Test_Bytes8192 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReader_get_key_value (
    TP_Test_Bytes8192DataReader _this,
    TP_Test_Bytes8192 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes8192DataReader_lookup_instance (
    TP_Test_Bytes8192DataReader _this,
    const TP_Test_Bytes8192 *key_holder
    );

#define TP_Test_Bytes8192DataReaderView DDS_DataReaderView

#define TP_Test_Bytes8192DataReaderView_enable DDS_Entity_enable

#define TP_Test_Bytes8192DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes8192DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Bytes8192DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Bytes8192DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Bytes8192DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Bytes8192DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Bytes8192DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Bytes8192DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Bytes8192DataReaderView_read (
    TP_Test_Bytes8192DataReaderView _this,
    DDS_sequence_TP_Test_Bytes8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReaderView_take (
    TP_Test_Bytes8192DataReaderView _this,
    DDS_sequence_TP_Test_Bytes8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReaderView_read_next_sample (
    TP_Test_Bytes8192DataReaderView _this,
    TP_Test_Bytes8192 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReaderView_take_next_sample (
    TP_Test_Bytes8192DataReaderView _this,
    TP_Test_Bytes8192 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReaderView_read_instance (
    TP_Test_Bytes8192DataReaderView _this,
    DDS_sequence_TP_Test_Bytes8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReaderView_take_instance (
    TP_Test_Bytes8192DataReaderView _this,
    DDS_sequence_TP_Test_Bytes8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReaderView_read_next_instance (
    TP_Test_Bytes8192DataReaderView _this,
    DDS_sequence_TP_Test_Bytes8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReaderView_take_next_instance (
    TP_Test_Bytes8192DataReaderView _this,
    DDS_sequence_TP_Test_Bytes8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReaderView_return_loan (
    TP_Test_Bytes8192DataReaderView _this,
    DDS_sequence_TP_Test_Bytes8192 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReaderView_read_w_condition (
    TP_Test_Bytes8192DataReaderView _this,
    DDS_sequence_TP_Test_Bytes8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReaderView_take_w_condition (
    TP_Test_Bytes8192DataReaderView _this,
    DDS_sequence_TP_Test_Bytes8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReaderView_read_next_instance_w_condition (
    TP_Test_Bytes8192DataReaderView _this,
    DDS_sequence_TP_Test_Bytes8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReaderView_take_next_instance_w_condition (
    TP_Test_Bytes8192DataReaderView _this,
    DDS_sequence_TP_Test_Bytes8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes8192DataReaderView_get_key_value (
    TP_Test_Bytes8192DataReaderView _this,
    TP_Test_Bytes8192 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes8192DataReaderView_lookup_instance (
    TP_Test_Bytes8192DataReaderView _this,
    TP_Test_Bytes8192 *key_holder
    );



#define TP_Test_Bytes16384TypeSupport DDS_TypeSupport

TP_Test_Bytes16384TypeSupport
TP_Test_Bytes16384TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Bytes16384TypeSupport_register_type (
    TP_Test_Bytes16384TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Bytes16384TypeSupport_get_type_name (
    TP_Test_Bytes16384TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Bytes16384_defined
#define _DDS_sequence_TP_Test_Bytes16384_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Bytes16384 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Bytes16384;

DDS_sequence_TP_Test_Bytes16384 *DDS_sequence_TP_Test_Bytes16384__alloc (void);
TP_Test_Bytes16384 *DDS_sequence_TP_Test_Bytes16384_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Bytes16384_defined */

#define TP_Test_Bytes16384DataWriter DDS_DataWriter

#define TP_Test_Bytes16384DataWriter_enable DDS_Entity_enable

#define TP_Test_Bytes16384DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes16384DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes16384DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes16384DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Bytes16384DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Bytes16384DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Bytes16384DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Bytes16384DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Bytes16384DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Bytes16384DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Bytes16384DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Bytes16384DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Bytes16384DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Bytes16384DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Bytes16384DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Bytes16384DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Bytes16384DataWriter_register_instance (
    TP_Test_Bytes16384DataWriter _this,
    const TP_Test_Bytes16384 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Bytes16384DataWriter_register_instance_w_timestamp (
    TP_Test_Bytes16384DataWriter _this,
    const TP_Test_Bytes16384 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataWriter_unregister_instance (
    TP_Test_Bytes16384DataWriter _this,
    const TP_Test_Bytes16384 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataWriter_unregister_instance_w_timestamp (
    TP_Test_Bytes16384DataWriter _this,
    const TP_Test_Bytes16384 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataWriter_write (
    TP_Test_Bytes16384DataWriter _this,
    const TP_Test_Bytes16384 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataWriter_write_w_timestamp (
    TP_Test_Bytes16384DataWriter _this,
    const TP_Test_Bytes16384 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataWriter_dispose (
    TP_Test_Bytes16384DataWriter _this,
    const TP_Test_Bytes16384 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataWriter_dispose_w_timestamp (
    TP_Test_Bytes16384DataWriter _this,
    const TP_Test_Bytes16384 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataWriter_writedispose (
    TP_Test_Bytes16384DataWriter _this,
    const TP_Test_Bytes16384 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataWriter_writedispose_w_timestamp (
    TP_Test_Bytes16384DataWriter _this,
    const TP_Test_Bytes16384 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataWriter_get_key_value (
    TP_Test_Bytes16384DataWriter _this,
    TP_Test_Bytes16384 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Bytes16384DataReader DDS_DataReader

#define TP_Test_Bytes16384DataReader_enable DDS_Entity_enable

#define TP_Test_Bytes16384DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Bytes16384DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Bytes16384DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes16384DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Bytes16384DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Bytes16384DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Bytes16384DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Bytes16384DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Bytes16384DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Bytes16384DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Bytes16384DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Bytes16384DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Bytes16384DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Bytes16384DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Bytes16384DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Bytes16384DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Bytes16384DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Bytes16384DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Bytes16384DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Bytes16384DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Bytes16384DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Bytes16384DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Bytes16384DataReader_read (
    TP_Test_Bytes16384DataReader _this,
    DDS_sequence_TP_Test_Bytes16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReader_take (
    TP_Test_Bytes16384DataReader _this,
    DDS_sequence_TP_Test_Bytes16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReader_read_w_condition (
    TP_Test_Bytes16384DataReader _this,
    DDS_sequence_TP_Test_Bytes16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReader_take_w_condition (
    TP_Test_Bytes16384DataReader _this,
    DDS_sequence_TP_Test_Bytes16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReader_read_next_sample (
    TP_Test_Bytes16384DataReader _this,
    TP_Test_Bytes16384 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReader_take_next_sample (
    TP_Test_Bytes16384DataReader _this,
    TP_Test_Bytes16384 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReader_read_instance (
    TP_Test_Bytes16384DataReader _this,
    DDS_sequence_TP_Test_Bytes16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReader_take_instance (
    TP_Test_Bytes16384DataReader _this,
    DDS_sequence_TP_Test_Bytes16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReader_read_next_instance (
    TP_Test_Bytes16384DataReader _this,
    DDS_sequence_TP_Test_Bytes16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReader_take_next_instance (
    TP_Test_Bytes16384DataReader _this,
    DDS_sequence_TP_Test_Bytes16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReader_read_next_instance_w_condition (
    TP_Test_Bytes16384DataReader _this,
    DDS_sequence_TP_Test_Bytes16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReader_take_next_instance_w_condition (
    TP_Test_Bytes16384DataReader _this,
    DDS_sequence_TP_Test_Bytes16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReader_return_loan (
    TP_Test_Bytes16384DataReader _this,
    DDS_sequence_TP_Test_Bytes16384 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReader_get_key_value (
    TP_Test_Bytes16384DataReader _this,
    TP_Test_Bytes16384 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes16384DataReader_lookup_instance (
    TP_Test_Bytes16384DataReader _this,
    const TP_Test_Bytes16384 *key_holder
    );

#define TP_Test_Bytes16384DataReaderView DDS_DataReaderView

#define TP_Test_Bytes16384DataReaderView_enable DDS_Entity_enable

#define TP_Test_Bytes16384DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Bytes16384DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Bytes16384DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Bytes16384DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Bytes16384DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Bytes16384DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Bytes16384DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Bytes16384DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Bytes16384DataReaderView_read (
    TP_Test_Bytes16384DataReaderView _this,
    DDS_sequence_TP_Test_Bytes16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReaderView_take (
    TP_Test_Bytes16384DataReaderView _this,
    DDS_sequence_TP_Test_Bytes16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReaderView_read_next_sample (
    TP_Test_Bytes16384DataReaderView _this,
    TP_Test_Bytes16384 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReaderView_take_next_sample (
    TP_Test_Bytes16384DataReaderView _this,
    TP_Test_Bytes16384 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReaderView_read_instance (
    TP_Test_Bytes16384DataReaderView _this,
    DDS_sequence_TP_Test_Bytes16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReaderView_take_instance (
    TP_Test_Bytes16384DataReaderView _this,
    DDS_sequence_TP_Test_Bytes16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReaderView_read_next_instance (
    TP_Test_Bytes16384DataReaderView _this,
    DDS_sequence_TP_Test_Bytes16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReaderView_take_next_instance (
    TP_Test_Bytes16384DataReaderView _this,
    DDS_sequence_TP_Test_Bytes16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReaderView_return_loan (
    TP_Test_Bytes16384DataReaderView _this,
    DDS_sequence_TP_Test_Bytes16384 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReaderView_read_w_condition (
    TP_Test_Bytes16384DataReaderView _this,
    DDS_sequence_TP_Test_Bytes16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReaderView_take_w_condition (
    TP_Test_Bytes16384DataReaderView _this,
    DDS_sequence_TP_Test_Bytes16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReaderView_read_next_instance_w_condition (
    TP_Test_Bytes16384DataReaderView _this,
    DDS_sequence_TP_Test_Bytes16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReaderView_take_next_instance_w_condition (
    TP_Test_Bytes16384DataReaderView _this,
    DDS_sequence_TP_Test_Bytes16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Bytes16384DataReaderView_get_key_value (
    TP_Test_Bytes16384DataReaderView _this,
    TP_Test_Bytes16384 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Bytes16384DataReaderView_lookup_instance (
    TP_Test_Bytes16384DataReaderView _this,
    TP_Test_Bytes16384 *key_holder
    );



#define TP_Test_Complex4TypeSupport DDS_TypeSupport

TP_Test_Complex4TypeSupport
TP_Test_Complex4TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Complex4TypeSupport_register_type (
    TP_Test_Complex4TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Complex4TypeSupport_get_type_name (
    TP_Test_Complex4TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Complex4_defined
#define _DDS_sequence_TP_Test_Complex4_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Complex4 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Complex4;

DDS_sequence_TP_Test_Complex4 *DDS_sequence_TP_Test_Complex4__alloc (void);
TP_Test_Complex4 *DDS_sequence_TP_Test_Complex4_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Complex4_defined */

#define TP_Test_Complex4DataWriter DDS_DataWriter

#define TP_Test_Complex4DataWriter_enable DDS_Entity_enable

#define TP_Test_Complex4DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex4DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex4DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex4DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Complex4DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Complex4DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Complex4DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Complex4DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Complex4DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Complex4DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Complex4DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Complex4DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Complex4DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Complex4DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Complex4DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Complex4DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Complex4DataWriter_register_instance (
    TP_Test_Complex4DataWriter _this,
    const TP_Test_Complex4 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Complex4DataWriter_register_instance_w_timestamp (
    TP_Test_Complex4DataWriter _this,
    const TP_Test_Complex4 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex4DataWriter_unregister_instance (
    TP_Test_Complex4DataWriter _this,
    const TP_Test_Complex4 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex4DataWriter_unregister_instance_w_timestamp (
    TP_Test_Complex4DataWriter _this,
    const TP_Test_Complex4 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex4DataWriter_write (
    TP_Test_Complex4DataWriter _this,
    const TP_Test_Complex4 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex4DataWriter_write_w_timestamp (
    TP_Test_Complex4DataWriter _this,
    const TP_Test_Complex4 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex4DataWriter_dispose (
    TP_Test_Complex4DataWriter _this,
    const TP_Test_Complex4 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex4DataWriter_dispose_w_timestamp (
    TP_Test_Complex4DataWriter _this,
    const TP_Test_Complex4 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex4DataWriter_writedispose (
    TP_Test_Complex4DataWriter _this,
    const TP_Test_Complex4 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex4DataWriter_writedispose_w_timestamp (
    TP_Test_Complex4DataWriter _this,
    const TP_Test_Complex4 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex4DataWriter_get_key_value (
    TP_Test_Complex4DataWriter _this,
    TP_Test_Complex4 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Complex4DataReader DDS_DataReader

#define TP_Test_Complex4DataReader_enable DDS_Entity_enable

#define TP_Test_Complex4DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex4DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex4DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex4DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Complex4DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Complex4DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Complex4DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Complex4DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Complex4DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Complex4DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Complex4DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Complex4DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Complex4DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Complex4DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Complex4DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Complex4DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Complex4DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Complex4DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Complex4DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Complex4DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Complex4DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Complex4DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Complex4DataReader_read (
    TP_Test_Complex4DataReader _this,
    DDS_sequence_TP_Test_Complex4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReader_take (
    TP_Test_Complex4DataReader _this,
    DDS_sequence_TP_Test_Complex4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReader_read_w_condition (
    TP_Test_Complex4DataReader _this,
    DDS_sequence_TP_Test_Complex4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReader_take_w_condition (
    TP_Test_Complex4DataReader _this,
    DDS_sequence_TP_Test_Complex4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReader_read_next_sample (
    TP_Test_Complex4DataReader _this,
    TP_Test_Complex4 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReader_take_next_sample (
    TP_Test_Complex4DataReader _this,
    TP_Test_Complex4 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReader_read_instance (
    TP_Test_Complex4DataReader _this,
    DDS_sequence_TP_Test_Complex4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReader_take_instance (
    TP_Test_Complex4DataReader _this,
    DDS_sequence_TP_Test_Complex4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReader_read_next_instance (
    TP_Test_Complex4DataReader _this,
    DDS_sequence_TP_Test_Complex4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReader_take_next_instance (
    TP_Test_Complex4DataReader _this,
    DDS_sequence_TP_Test_Complex4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReader_read_next_instance_w_condition (
    TP_Test_Complex4DataReader _this,
    DDS_sequence_TP_Test_Complex4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReader_take_next_instance_w_condition (
    TP_Test_Complex4DataReader _this,
    DDS_sequence_TP_Test_Complex4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReader_return_loan (
    TP_Test_Complex4DataReader _this,
    DDS_sequence_TP_Test_Complex4 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReader_get_key_value (
    TP_Test_Complex4DataReader _this,
    TP_Test_Complex4 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex4DataReader_lookup_instance (
    TP_Test_Complex4DataReader _this,
    const TP_Test_Complex4 *key_holder
    );

#define TP_Test_Complex4DataReaderView DDS_DataReaderView

#define TP_Test_Complex4DataReaderView_enable DDS_Entity_enable

#define TP_Test_Complex4DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex4DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Complex4DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Complex4DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Complex4DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Complex4DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Complex4DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Complex4DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Complex4DataReaderView_read (
    TP_Test_Complex4DataReaderView _this,
    DDS_sequence_TP_Test_Complex4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReaderView_take (
    TP_Test_Complex4DataReaderView _this,
    DDS_sequence_TP_Test_Complex4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReaderView_read_next_sample (
    TP_Test_Complex4DataReaderView _this,
    TP_Test_Complex4 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReaderView_take_next_sample (
    TP_Test_Complex4DataReaderView _this,
    TP_Test_Complex4 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReaderView_read_instance (
    TP_Test_Complex4DataReaderView _this,
    DDS_sequence_TP_Test_Complex4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReaderView_take_instance (
    TP_Test_Complex4DataReaderView _this,
    DDS_sequence_TP_Test_Complex4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReaderView_read_next_instance (
    TP_Test_Complex4DataReaderView _this,
    DDS_sequence_TP_Test_Complex4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReaderView_take_next_instance (
    TP_Test_Complex4DataReaderView _this,
    DDS_sequence_TP_Test_Complex4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReaderView_return_loan (
    TP_Test_Complex4DataReaderView _this,
    DDS_sequence_TP_Test_Complex4 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReaderView_read_w_condition (
    TP_Test_Complex4DataReaderView _this,
    DDS_sequence_TP_Test_Complex4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReaderView_take_w_condition (
    TP_Test_Complex4DataReaderView _this,
    DDS_sequence_TP_Test_Complex4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReaderView_read_next_instance_w_condition (
    TP_Test_Complex4DataReaderView _this,
    DDS_sequence_TP_Test_Complex4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReaderView_take_next_instance_w_condition (
    TP_Test_Complex4DataReaderView _this,
    DDS_sequence_TP_Test_Complex4 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex4DataReaderView_get_key_value (
    TP_Test_Complex4DataReaderView _this,
    TP_Test_Complex4 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex4DataReaderView_lookup_instance (
    TP_Test_Complex4DataReaderView _this,
    TP_Test_Complex4 *key_holder
    );



#define TP_Test_Complex8TypeSupport DDS_TypeSupport

TP_Test_Complex8TypeSupport
TP_Test_Complex8TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Complex8TypeSupport_register_type (
    TP_Test_Complex8TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Complex8TypeSupport_get_type_name (
    TP_Test_Complex8TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Complex8_defined
#define _DDS_sequence_TP_Test_Complex8_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Complex8 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Complex8;

DDS_sequence_TP_Test_Complex8 *DDS_sequence_TP_Test_Complex8__alloc (void);
TP_Test_Complex8 *DDS_sequence_TP_Test_Complex8_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Complex8_defined */

#define TP_Test_Complex8DataWriter DDS_DataWriter

#define TP_Test_Complex8DataWriter_enable DDS_Entity_enable

#define TP_Test_Complex8DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex8DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex8DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex8DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Complex8DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Complex8DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Complex8DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Complex8DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Complex8DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Complex8DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Complex8DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Complex8DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Complex8DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Complex8DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Complex8DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Complex8DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Complex8DataWriter_register_instance (
    TP_Test_Complex8DataWriter _this,
    const TP_Test_Complex8 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Complex8DataWriter_register_instance_w_timestamp (
    TP_Test_Complex8DataWriter _this,
    const TP_Test_Complex8 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex8DataWriter_unregister_instance (
    TP_Test_Complex8DataWriter _this,
    const TP_Test_Complex8 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex8DataWriter_unregister_instance_w_timestamp (
    TP_Test_Complex8DataWriter _this,
    const TP_Test_Complex8 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex8DataWriter_write (
    TP_Test_Complex8DataWriter _this,
    const TP_Test_Complex8 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex8DataWriter_write_w_timestamp (
    TP_Test_Complex8DataWriter _this,
    const TP_Test_Complex8 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex8DataWriter_dispose (
    TP_Test_Complex8DataWriter _this,
    const TP_Test_Complex8 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex8DataWriter_dispose_w_timestamp (
    TP_Test_Complex8DataWriter _this,
    const TP_Test_Complex8 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex8DataWriter_writedispose (
    TP_Test_Complex8DataWriter _this,
    const TP_Test_Complex8 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex8DataWriter_writedispose_w_timestamp (
    TP_Test_Complex8DataWriter _this,
    const TP_Test_Complex8 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex8DataWriter_get_key_value (
    TP_Test_Complex8DataWriter _this,
    TP_Test_Complex8 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Complex8DataReader DDS_DataReader

#define TP_Test_Complex8DataReader_enable DDS_Entity_enable

#define TP_Test_Complex8DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex8DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex8DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex8DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Complex8DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Complex8DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Complex8DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Complex8DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Complex8DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Complex8DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Complex8DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Complex8DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Complex8DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Complex8DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Complex8DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Complex8DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Complex8DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Complex8DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Complex8DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Complex8DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Complex8DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Complex8DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Complex8DataReader_read (
    TP_Test_Complex8DataReader _this,
    DDS_sequence_TP_Test_Complex8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReader_take (
    TP_Test_Complex8DataReader _this,
    DDS_sequence_TP_Test_Complex8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReader_read_w_condition (
    TP_Test_Complex8DataReader _this,
    DDS_sequence_TP_Test_Complex8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReader_take_w_condition (
    TP_Test_Complex8DataReader _this,
    DDS_sequence_TP_Test_Complex8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReader_read_next_sample (
    TP_Test_Complex8DataReader _this,
    TP_Test_Complex8 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReader_take_next_sample (
    TP_Test_Complex8DataReader _this,
    TP_Test_Complex8 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReader_read_instance (
    TP_Test_Complex8DataReader _this,
    DDS_sequence_TP_Test_Complex8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReader_take_instance (
    TP_Test_Complex8DataReader _this,
    DDS_sequence_TP_Test_Complex8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReader_read_next_instance (
    TP_Test_Complex8DataReader _this,
    DDS_sequence_TP_Test_Complex8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReader_take_next_instance (
    TP_Test_Complex8DataReader _this,
    DDS_sequence_TP_Test_Complex8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReader_read_next_instance_w_condition (
    TP_Test_Complex8DataReader _this,
    DDS_sequence_TP_Test_Complex8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReader_take_next_instance_w_condition (
    TP_Test_Complex8DataReader _this,
    DDS_sequence_TP_Test_Complex8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReader_return_loan (
    TP_Test_Complex8DataReader _this,
    DDS_sequence_TP_Test_Complex8 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReader_get_key_value (
    TP_Test_Complex8DataReader _this,
    TP_Test_Complex8 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex8DataReader_lookup_instance (
    TP_Test_Complex8DataReader _this,
    const TP_Test_Complex8 *key_holder
    );

#define TP_Test_Complex8DataReaderView DDS_DataReaderView

#define TP_Test_Complex8DataReaderView_enable DDS_Entity_enable

#define TP_Test_Complex8DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex8DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Complex8DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Complex8DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Complex8DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Complex8DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Complex8DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Complex8DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Complex8DataReaderView_read (
    TP_Test_Complex8DataReaderView _this,
    DDS_sequence_TP_Test_Complex8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReaderView_take (
    TP_Test_Complex8DataReaderView _this,
    DDS_sequence_TP_Test_Complex8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReaderView_read_next_sample (
    TP_Test_Complex8DataReaderView _this,
    TP_Test_Complex8 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReaderView_take_next_sample (
    TP_Test_Complex8DataReaderView _this,
    TP_Test_Complex8 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReaderView_read_instance (
    TP_Test_Complex8DataReaderView _this,
    DDS_sequence_TP_Test_Complex8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReaderView_take_instance (
    TP_Test_Complex8DataReaderView _this,
    DDS_sequence_TP_Test_Complex8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReaderView_read_next_instance (
    TP_Test_Complex8DataReaderView _this,
    DDS_sequence_TP_Test_Complex8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReaderView_take_next_instance (
    TP_Test_Complex8DataReaderView _this,
    DDS_sequence_TP_Test_Complex8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReaderView_return_loan (
    TP_Test_Complex8DataReaderView _this,
    DDS_sequence_TP_Test_Complex8 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReaderView_read_w_condition (
    TP_Test_Complex8DataReaderView _this,
    DDS_sequence_TP_Test_Complex8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReaderView_take_w_condition (
    TP_Test_Complex8DataReaderView _this,
    DDS_sequence_TP_Test_Complex8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReaderView_read_next_instance_w_condition (
    TP_Test_Complex8DataReaderView _this,
    DDS_sequence_TP_Test_Complex8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReaderView_take_next_instance_w_condition (
    TP_Test_Complex8DataReaderView _this,
    DDS_sequence_TP_Test_Complex8 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex8DataReaderView_get_key_value (
    TP_Test_Complex8DataReaderView _this,
    TP_Test_Complex8 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex8DataReaderView_lookup_instance (
    TP_Test_Complex8DataReaderView _this,
    TP_Test_Complex8 *key_holder
    );



#define TP_Test_Complex16TypeSupport DDS_TypeSupport

TP_Test_Complex16TypeSupport
TP_Test_Complex16TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Complex16TypeSupport_register_type (
    TP_Test_Complex16TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Complex16TypeSupport_get_type_name (
    TP_Test_Complex16TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Complex16_defined
#define _DDS_sequence_TP_Test_Complex16_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Complex16 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Complex16;

DDS_sequence_TP_Test_Complex16 *DDS_sequence_TP_Test_Complex16__alloc (void);
TP_Test_Complex16 *DDS_sequence_TP_Test_Complex16_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Complex16_defined */

#define TP_Test_Complex16DataWriter DDS_DataWriter

#define TP_Test_Complex16DataWriter_enable DDS_Entity_enable

#define TP_Test_Complex16DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex16DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex16DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex16DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Complex16DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Complex16DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Complex16DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Complex16DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Complex16DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Complex16DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Complex16DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Complex16DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Complex16DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Complex16DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Complex16DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Complex16DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Complex16DataWriter_register_instance (
    TP_Test_Complex16DataWriter _this,
    const TP_Test_Complex16 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Complex16DataWriter_register_instance_w_timestamp (
    TP_Test_Complex16DataWriter _this,
    const TP_Test_Complex16 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex16DataWriter_unregister_instance (
    TP_Test_Complex16DataWriter _this,
    const TP_Test_Complex16 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex16DataWriter_unregister_instance_w_timestamp (
    TP_Test_Complex16DataWriter _this,
    const TP_Test_Complex16 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex16DataWriter_write (
    TP_Test_Complex16DataWriter _this,
    const TP_Test_Complex16 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex16DataWriter_write_w_timestamp (
    TP_Test_Complex16DataWriter _this,
    const TP_Test_Complex16 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex16DataWriter_dispose (
    TP_Test_Complex16DataWriter _this,
    const TP_Test_Complex16 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex16DataWriter_dispose_w_timestamp (
    TP_Test_Complex16DataWriter _this,
    const TP_Test_Complex16 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex16DataWriter_writedispose (
    TP_Test_Complex16DataWriter _this,
    const TP_Test_Complex16 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex16DataWriter_writedispose_w_timestamp (
    TP_Test_Complex16DataWriter _this,
    const TP_Test_Complex16 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex16DataWriter_get_key_value (
    TP_Test_Complex16DataWriter _this,
    TP_Test_Complex16 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Complex16DataReader DDS_DataReader

#define TP_Test_Complex16DataReader_enable DDS_Entity_enable

#define TP_Test_Complex16DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex16DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex16DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex16DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Complex16DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Complex16DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Complex16DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Complex16DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Complex16DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Complex16DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Complex16DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Complex16DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Complex16DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Complex16DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Complex16DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Complex16DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Complex16DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Complex16DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Complex16DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Complex16DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Complex16DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Complex16DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Complex16DataReader_read (
    TP_Test_Complex16DataReader _this,
    DDS_sequence_TP_Test_Complex16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReader_take (
    TP_Test_Complex16DataReader _this,
    DDS_sequence_TP_Test_Complex16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReader_read_w_condition (
    TP_Test_Complex16DataReader _this,
    DDS_sequence_TP_Test_Complex16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReader_take_w_condition (
    TP_Test_Complex16DataReader _this,
    DDS_sequence_TP_Test_Complex16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReader_read_next_sample (
    TP_Test_Complex16DataReader _this,
    TP_Test_Complex16 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReader_take_next_sample (
    TP_Test_Complex16DataReader _this,
    TP_Test_Complex16 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReader_read_instance (
    TP_Test_Complex16DataReader _this,
    DDS_sequence_TP_Test_Complex16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReader_take_instance (
    TP_Test_Complex16DataReader _this,
    DDS_sequence_TP_Test_Complex16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReader_read_next_instance (
    TP_Test_Complex16DataReader _this,
    DDS_sequence_TP_Test_Complex16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReader_take_next_instance (
    TP_Test_Complex16DataReader _this,
    DDS_sequence_TP_Test_Complex16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReader_read_next_instance_w_condition (
    TP_Test_Complex16DataReader _this,
    DDS_sequence_TP_Test_Complex16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReader_take_next_instance_w_condition (
    TP_Test_Complex16DataReader _this,
    DDS_sequence_TP_Test_Complex16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReader_return_loan (
    TP_Test_Complex16DataReader _this,
    DDS_sequence_TP_Test_Complex16 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReader_get_key_value (
    TP_Test_Complex16DataReader _this,
    TP_Test_Complex16 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex16DataReader_lookup_instance (
    TP_Test_Complex16DataReader _this,
    const TP_Test_Complex16 *key_holder
    );

#define TP_Test_Complex16DataReaderView DDS_DataReaderView

#define TP_Test_Complex16DataReaderView_enable DDS_Entity_enable

#define TP_Test_Complex16DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex16DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Complex16DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Complex16DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Complex16DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Complex16DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Complex16DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Complex16DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Complex16DataReaderView_read (
    TP_Test_Complex16DataReaderView _this,
    DDS_sequence_TP_Test_Complex16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReaderView_take (
    TP_Test_Complex16DataReaderView _this,
    DDS_sequence_TP_Test_Complex16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReaderView_read_next_sample (
    TP_Test_Complex16DataReaderView _this,
    TP_Test_Complex16 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReaderView_take_next_sample (
    TP_Test_Complex16DataReaderView _this,
    TP_Test_Complex16 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReaderView_read_instance (
    TP_Test_Complex16DataReaderView _this,
    DDS_sequence_TP_Test_Complex16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReaderView_take_instance (
    TP_Test_Complex16DataReaderView _this,
    DDS_sequence_TP_Test_Complex16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReaderView_read_next_instance (
    TP_Test_Complex16DataReaderView _this,
    DDS_sequence_TP_Test_Complex16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReaderView_take_next_instance (
    TP_Test_Complex16DataReaderView _this,
    DDS_sequence_TP_Test_Complex16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReaderView_return_loan (
    TP_Test_Complex16DataReaderView _this,
    DDS_sequence_TP_Test_Complex16 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReaderView_read_w_condition (
    TP_Test_Complex16DataReaderView _this,
    DDS_sequence_TP_Test_Complex16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReaderView_take_w_condition (
    TP_Test_Complex16DataReaderView _this,
    DDS_sequence_TP_Test_Complex16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReaderView_read_next_instance_w_condition (
    TP_Test_Complex16DataReaderView _this,
    DDS_sequence_TP_Test_Complex16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReaderView_take_next_instance_w_condition (
    TP_Test_Complex16DataReaderView _this,
    DDS_sequence_TP_Test_Complex16 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex16DataReaderView_get_key_value (
    TP_Test_Complex16DataReaderView _this,
    TP_Test_Complex16 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex16DataReaderView_lookup_instance (
    TP_Test_Complex16DataReaderView _this,
    TP_Test_Complex16 *key_holder
    );



#define TP_Test_Complex32TypeSupport DDS_TypeSupport

TP_Test_Complex32TypeSupport
TP_Test_Complex32TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Complex32TypeSupport_register_type (
    TP_Test_Complex32TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Complex32TypeSupport_get_type_name (
    TP_Test_Complex32TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Complex32_defined
#define _DDS_sequence_TP_Test_Complex32_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Complex32 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Complex32;

DDS_sequence_TP_Test_Complex32 *DDS_sequence_TP_Test_Complex32__alloc (void);
TP_Test_Complex32 *DDS_sequence_TP_Test_Complex32_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Complex32_defined */

#define TP_Test_Complex32DataWriter DDS_DataWriter

#define TP_Test_Complex32DataWriter_enable DDS_Entity_enable

#define TP_Test_Complex32DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex32DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex32DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex32DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Complex32DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Complex32DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Complex32DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Complex32DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Complex32DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Complex32DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Complex32DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Complex32DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Complex32DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Complex32DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Complex32DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Complex32DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Complex32DataWriter_register_instance (
    TP_Test_Complex32DataWriter _this,
    const TP_Test_Complex32 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Complex32DataWriter_register_instance_w_timestamp (
    TP_Test_Complex32DataWriter _this,
    const TP_Test_Complex32 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex32DataWriter_unregister_instance (
    TP_Test_Complex32DataWriter _this,
    const TP_Test_Complex32 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex32DataWriter_unregister_instance_w_timestamp (
    TP_Test_Complex32DataWriter _this,
    const TP_Test_Complex32 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex32DataWriter_write (
    TP_Test_Complex32DataWriter _this,
    const TP_Test_Complex32 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex32DataWriter_write_w_timestamp (
    TP_Test_Complex32DataWriter _this,
    const TP_Test_Complex32 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex32DataWriter_dispose (
    TP_Test_Complex32DataWriter _this,
    const TP_Test_Complex32 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex32DataWriter_dispose_w_timestamp (
    TP_Test_Complex32DataWriter _this,
    const TP_Test_Complex32 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex32DataWriter_writedispose (
    TP_Test_Complex32DataWriter _this,
    const TP_Test_Complex32 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex32DataWriter_writedispose_w_timestamp (
    TP_Test_Complex32DataWriter _this,
    const TP_Test_Complex32 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex32DataWriter_get_key_value (
    TP_Test_Complex32DataWriter _this,
    TP_Test_Complex32 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Complex32DataReader DDS_DataReader

#define TP_Test_Complex32DataReader_enable DDS_Entity_enable

#define TP_Test_Complex32DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex32DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex32DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex32DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Complex32DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Complex32DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Complex32DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Complex32DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Complex32DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Complex32DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Complex32DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Complex32DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Complex32DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Complex32DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Complex32DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Complex32DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Complex32DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Complex32DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Complex32DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Complex32DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Complex32DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Complex32DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Complex32DataReader_read (
    TP_Test_Complex32DataReader _this,
    DDS_sequence_TP_Test_Complex32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReader_take (
    TP_Test_Complex32DataReader _this,
    DDS_sequence_TP_Test_Complex32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReader_read_w_condition (
    TP_Test_Complex32DataReader _this,
    DDS_sequence_TP_Test_Complex32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReader_take_w_condition (
    TP_Test_Complex32DataReader _this,
    DDS_sequence_TP_Test_Complex32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReader_read_next_sample (
    TP_Test_Complex32DataReader _this,
    TP_Test_Complex32 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReader_take_next_sample (
    TP_Test_Complex32DataReader _this,
    TP_Test_Complex32 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReader_read_instance (
    TP_Test_Complex32DataReader _this,
    DDS_sequence_TP_Test_Complex32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReader_take_instance (
    TP_Test_Complex32DataReader _this,
    DDS_sequence_TP_Test_Complex32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReader_read_next_instance (
    TP_Test_Complex32DataReader _this,
    DDS_sequence_TP_Test_Complex32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReader_take_next_instance (
    TP_Test_Complex32DataReader _this,
    DDS_sequence_TP_Test_Complex32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReader_read_next_instance_w_condition (
    TP_Test_Complex32DataReader _this,
    DDS_sequence_TP_Test_Complex32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReader_take_next_instance_w_condition (
    TP_Test_Complex32DataReader _this,
    DDS_sequence_TP_Test_Complex32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReader_return_loan (
    TP_Test_Complex32DataReader _this,
    DDS_sequence_TP_Test_Complex32 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReader_get_key_value (
    TP_Test_Complex32DataReader _this,
    TP_Test_Complex32 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex32DataReader_lookup_instance (
    TP_Test_Complex32DataReader _this,
    const TP_Test_Complex32 *key_holder
    );

#define TP_Test_Complex32DataReaderView DDS_DataReaderView

#define TP_Test_Complex32DataReaderView_enable DDS_Entity_enable

#define TP_Test_Complex32DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex32DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Complex32DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Complex32DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Complex32DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Complex32DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Complex32DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Complex32DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Complex32DataReaderView_read (
    TP_Test_Complex32DataReaderView _this,
    DDS_sequence_TP_Test_Complex32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReaderView_take (
    TP_Test_Complex32DataReaderView _this,
    DDS_sequence_TP_Test_Complex32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReaderView_read_next_sample (
    TP_Test_Complex32DataReaderView _this,
    TP_Test_Complex32 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReaderView_take_next_sample (
    TP_Test_Complex32DataReaderView _this,
    TP_Test_Complex32 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReaderView_read_instance (
    TP_Test_Complex32DataReaderView _this,
    DDS_sequence_TP_Test_Complex32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReaderView_take_instance (
    TP_Test_Complex32DataReaderView _this,
    DDS_sequence_TP_Test_Complex32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReaderView_read_next_instance (
    TP_Test_Complex32DataReaderView _this,
    DDS_sequence_TP_Test_Complex32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReaderView_take_next_instance (
    TP_Test_Complex32DataReaderView _this,
    DDS_sequence_TP_Test_Complex32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReaderView_return_loan (
    TP_Test_Complex32DataReaderView _this,
    DDS_sequence_TP_Test_Complex32 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReaderView_read_w_condition (
    TP_Test_Complex32DataReaderView _this,
    DDS_sequence_TP_Test_Complex32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReaderView_take_w_condition (
    TP_Test_Complex32DataReaderView _this,
    DDS_sequence_TP_Test_Complex32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReaderView_read_next_instance_w_condition (
    TP_Test_Complex32DataReaderView _this,
    DDS_sequence_TP_Test_Complex32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReaderView_take_next_instance_w_condition (
    TP_Test_Complex32DataReaderView _this,
    DDS_sequence_TP_Test_Complex32 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex32DataReaderView_get_key_value (
    TP_Test_Complex32DataReaderView _this,
    TP_Test_Complex32 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex32DataReaderView_lookup_instance (
    TP_Test_Complex32DataReaderView _this,
    TP_Test_Complex32 *key_holder
    );



#define TP_Test_Complex64TypeSupport DDS_TypeSupport

TP_Test_Complex64TypeSupport
TP_Test_Complex64TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Complex64TypeSupport_register_type (
    TP_Test_Complex64TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Complex64TypeSupport_get_type_name (
    TP_Test_Complex64TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Complex64_defined
#define _DDS_sequence_TP_Test_Complex64_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Complex64 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Complex64;

DDS_sequence_TP_Test_Complex64 *DDS_sequence_TP_Test_Complex64__alloc (void);
TP_Test_Complex64 *DDS_sequence_TP_Test_Complex64_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Complex64_defined */

#define TP_Test_Complex64DataWriter DDS_DataWriter

#define TP_Test_Complex64DataWriter_enable DDS_Entity_enable

#define TP_Test_Complex64DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex64DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex64DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex64DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Complex64DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Complex64DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Complex64DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Complex64DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Complex64DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Complex64DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Complex64DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Complex64DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Complex64DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Complex64DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Complex64DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Complex64DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Complex64DataWriter_register_instance (
    TP_Test_Complex64DataWriter _this,
    const TP_Test_Complex64 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Complex64DataWriter_register_instance_w_timestamp (
    TP_Test_Complex64DataWriter _this,
    const TP_Test_Complex64 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex64DataWriter_unregister_instance (
    TP_Test_Complex64DataWriter _this,
    const TP_Test_Complex64 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex64DataWriter_unregister_instance_w_timestamp (
    TP_Test_Complex64DataWriter _this,
    const TP_Test_Complex64 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex64DataWriter_write (
    TP_Test_Complex64DataWriter _this,
    const TP_Test_Complex64 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex64DataWriter_write_w_timestamp (
    TP_Test_Complex64DataWriter _this,
    const TP_Test_Complex64 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex64DataWriter_dispose (
    TP_Test_Complex64DataWriter _this,
    const TP_Test_Complex64 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex64DataWriter_dispose_w_timestamp (
    TP_Test_Complex64DataWriter _this,
    const TP_Test_Complex64 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex64DataWriter_writedispose (
    TP_Test_Complex64DataWriter _this,
    const TP_Test_Complex64 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex64DataWriter_writedispose_w_timestamp (
    TP_Test_Complex64DataWriter _this,
    const TP_Test_Complex64 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex64DataWriter_get_key_value (
    TP_Test_Complex64DataWriter _this,
    TP_Test_Complex64 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Complex64DataReader DDS_DataReader

#define TP_Test_Complex64DataReader_enable DDS_Entity_enable

#define TP_Test_Complex64DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex64DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex64DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex64DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Complex64DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Complex64DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Complex64DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Complex64DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Complex64DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Complex64DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Complex64DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Complex64DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Complex64DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Complex64DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Complex64DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Complex64DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Complex64DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Complex64DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Complex64DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Complex64DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Complex64DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Complex64DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Complex64DataReader_read (
    TP_Test_Complex64DataReader _this,
    DDS_sequence_TP_Test_Complex64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReader_take (
    TP_Test_Complex64DataReader _this,
    DDS_sequence_TP_Test_Complex64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReader_read_w_condition (
    TP_Test_Complex64DataReader _this,
    DDS_sequence_TP_Test_Complex64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReader_take_w_condition (
    TP_Test_Complex64DataReader _this,
    DDS_sequence_TP_Test_Complex64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReader_read_next_sample (
    TP_Test_Complex64DataReader _this,
    TP_Test_Complex64 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReader_take_next_sample (
    TP_Test_Complex64DataReader _this,
    TP_Test_Complex64 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReader_read_instance (
    TP_Test_Complex64DataReader _this,
    DDS_sequence_TP_Test_Complex64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReader_take_instance (
    TP_Test_Complex64DataReader _this,
    DDS_sequence_TP_Test_Complex64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReader_read_next_instance (
    TP_Test_Complex64DataReader _this,
    DDS_sequence_TP_Test_Complex64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReader_take_next_instance (
    TP_Test_Complex64DataReader _this,
    DDS_sequence_TP_Test_Complex64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReader_read_next_instance_w_condition (
    TP_Test_Complex64DataReader _this,
    DDS_sequence_TP_Test_Complex64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReader_take_next_instance_w_condition (
    TP_Test_Complex64DataReader _this,
    DDS_sequence_TP_Test_Complex64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReader_return_loan (
    TP_Test_Complex64DataReader _this,
    DDS_sequence_TP_Test_Complex64 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReader_get_key_value (
    TP_Test_Complex64DataReader _this,
    TP_Test_Complex64 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex64DataReader_lookup_instance (
    TP_Test_Complex64DataReader _this,
    const TP_Test_Complex64 *key_holder
    );

#define TP_Test_Complex64DataReaderView DDS_DataReaderView

#define TP_Test_Complex64DataReaderView_enable DDS_Entity_enable

#define TP_Test_Complex64DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex64DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Complex64DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Complex64DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Complex64DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Complex64DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Complex64DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Complex64DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Complex64DataReaderView_read (
    TP_Test_Complex64DataReaderView _this,
    DDS_sequence_TP_Test_Complex64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReaderView_take (
    TP_Test_Complex64DataReaderView _this,
    DDS_sequence_TP_Test_Complex64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReaderView_read_next_sample (
    TP_Test_Complex64DataReaderView _this,
    TP_Test_Complex64 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReaderView_take_next_sample (
    TP_Test_Complex64DataReaderView _this,
    TP_Test_Complex64 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReaderView_read_instance (
    TP_Test_Complex64DataReaderView _this,
    DDS_sequence_TP_Test_Complex64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReaderView_take_instance (
    TP_Test_Complex64DataReaderView _this,
    DDS_sequence_TP_Test_Complex64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReaderView_read_next_instance (
    TP_Test_Complex64DataReaderView _this,
    DDS_sequence_TP_Test_Complex64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReaderView_take_next_instance (
    TP_Test_Complex64DataReaderView _this,
    DDS_sequence_TP_Test_Complex64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReaderView_return_loan (
    TP_Test_Complex64DataReaderView _this,
    DDS_sequence_TP_Test_Complex64 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReaderView_read_w_condition (
    TP_Test_Complex64DataReaderView _this,
    DDS_sequence_TP_Test_Complex64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReaderView_take_w_condition (
    TP_Test_Complex64DataReaderView _this,
    DDS_sequence_TP_Test_Complex64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReaderView_read_next_instance_w_condition (
    TP_Test_Complex64DataReaderView _this,
    DDS_sequence_TP_Test_Complex64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReaderView_take_next_instance_w_condition (
    TP_Test_Complex64DataReaderView _this,
    DDS_sequence_TP_Test_Complex64 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex64DataReaderView_get_key_value (
    TP_Test_Complex64DataReaderView _this,
    TP_Test_Complex64 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex64DataReaderView_lookup_instance (
    TP_Test_Complex64DataReaderView _this,
    TP_Test_Complex64 *key_holder
    );



#define TP_Test_Complex128TypeSupport DDS_TypeSupport

TP_Test_Complex128TypeSupport
TP_Test_Complex128TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Complex128TypeSupport_register_type (
    TP_Test_Complex128TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Complex128TypeSupport_get_type_name (
    TP_Test_Complex128TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Complex128_defined
#define _DDS_sequence_TP_Test_Complex128_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Complex128 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Complex128;

DDS_sequence_TP_Test_Complex128 *DDS_sequence_TP_Test_Complex128__alloc (void);
TP_Test_Complex128 *DDS_sequence_TP_Test_Complex128_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Complex128_defined */

#define TP_Test_Complex128DataWriter DDS_DataWriter

#define TP_Test_Complex128DataWriter_enable DDS_Entity_enable

#define TP_Test_Complex128DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex128DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex128DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex128DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Complex128DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Complex128DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Complex128DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Complex128DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Complex128DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Complex128DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Complex128DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Complex128DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Complex128DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Complex128DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Complex128DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Complex128DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Complex128DataWriter_register_instance (
    TP_Test_Complex128DataWriter _this,
    const TP_Test_Complex128 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Complex128DataWriter_register_instance_w_timestamp (
    TP_Test_Complex128DataWriter _this,
    const TP_Test_Complex128 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex128DataWriter_unregister_instance (
    TP_Test_Complex128DataWriter _this,
    const TP_Test_Complex128 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex128DataWriter_unregister_instance_w_timestamp (
    TP_Test_Complex128DataWriter _this,
    const TP_Test_Complex128 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex128DataWriter_write (
    TP_Test_Complex128DataWriter _this,
    const TP_Test_Complex128 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex128DataWriter_write_w_timestamp (
    TP_Test_Complex128DataWriter _this,
    const TP_Test_Complex128 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex128DataWriter_dispose (
    TP_Test_Complex128DataWriter _this,
    const TP_Test_Complex128 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex128DataWriter_dispose_w_timestamp (
    TP_Test_Complex128DataWriter _this,
    const TP_Test_Complex128 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex128DataWriter_writedispose (
    TP_Test_Complex128DataWriter _this,
    const TP_Test_Complex128 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex128DataWriter_writedispose_w_timestamp (
    TP_Test_Complex128DataWriter _this,
    const TP_Test_Complex128 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex128DataWriter_get_key_value (
    TP_Test_Complex128DataWriter _this,
    TP_Test_Complex128 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Complex128DataReader DDS_DataReader

#define TP_Test_Complex128DataReader_enable DDS_Entity_enable

#define TP_Test_Complex128DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex128DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex128DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex128DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Complex128DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Complex128DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Complex128DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Complex128DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Complex128DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Complex128DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Complex128DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Complex128DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Complex128DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Complex128DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Complex128DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Complex128DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Complex128DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Complex128DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Complex128DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Complex128DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Complex128DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Complex128DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Complex128DataReader_read (
    TP_Test_Complex128DataReader _this,
    DDS_sequence_TP_Test_Complex128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReader_take (
    TP_Test_Complex128DataReader _this,
    DDS_sequence_TP_Test_Complex128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReader_read_w_condition (
    TP_Test_Complex128DataReader _this,
    DDS_sequence_TP_Test_Complex128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReader_take_w_condition (
    TP_Test_Complex128DataReader _this,
    DDS_sequence_TP_Test_Complex128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReader_read_next_sample (
    TP_Test_Complex128DataReader _this,
    TP_Test_Complex128 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReader_take_next_sample (
    TP_Test_Complex128DataReader _this,
    TP_Test_Complex128 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReader_read_instance (
    TP_Test_Complex128DataReader _this,
    DDS_sequence_TP_Test_Complex128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReader_take_instance (
    TP_Test_Complex128DataReader _this,
    DDS_sequence_TP_Test_Complex128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReader_read_next_instance (
    TP_Test_Complex128DataReader _this,
    DDS_sequence_TP_Test_Complex128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReader_take_next_instance (
    TP_Test_Complex128DataReader _this,
    DDS_sequence_TP_Test_Complex128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReader_read_next_instance_w_condition (
    TP_Test_Complex128DataReader _this,
    DDS_sequence_TP_Test_Complex128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReader_take_next_instance_w_condition (
    TP_Test_Complex128DataReader _this,
    DDS_sequence_TP_Test_Complex128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReader_return_loan (
    TP_Test_Complex128DataReader _this,
    DDS_sequence_TP_Test_Complex128 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReader_get_key_value (
    TP_Test_Complex128DataReader _this,
    TP_Test_Complex128 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex128DataReader_lookup_instance (
    TP_Test_Complex128DataReader _this,
    const TP_Test_Complex128 *key_holder
    );

#define TP_Test_Complex128DataReaderView DDS_DataReaderView

#define TP_Test_Complex128DataReaderView_enable DDS_Entity_enable

#define TP_Test_Complex128DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex128DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Complex128DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Complex128DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Complex128DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Complex128DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Complex128DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Complex128DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Complex128DataReaderView_read (
    TP_Test_Complex128DataReaderView _this,
    DDS_sequence_TP_Test_Complex128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReaderView_take (
    TP_Test_Complex128DataReaderView _this,
    DDS_sequence_TP_Test_Complex128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReaderView_read_next_sample (
    TP_Test_Complex128DataReaderView _this,
    TP_Test_Complex128 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReaderView_take_next_sample (
    TP_Test_Complex128DataReaderView _this,
    TP_Test_Complex128 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReaderView_read_instance (
    TP_Test_Complex128DataReaderView _this,
    DDS_sequence_TP_Test_Complex128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReaderView_take_instance (
    TP_Test_Complex128DataReaderView _this,
    DDS_sequence_TP_Test_Complex128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReaderView_read_next_instance (
    TP_Test_Complex128DataReaderView _this,
    DDS_sequence_TP_Test_Complex128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReaderView_take_next_instance (
    TP_Test_Complex128DataReaderView _this,
    DDS_sequence_TP_Test_Complex128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReaderView_return_loan (
    TP_Test_Complex128DataReaderView _this,
    DDS_sequence_TP_Test_Complex128 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReaderView_read_w_condition (
    TP_Test_Complex128DataReaderView _this,
    DDS_sequence_TP_Test_Complex128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReaderView_take_w_condition (
    TP_Test_Complex128DataReaderView _this,
    DDS_sequence_TP_Test_Complex128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReaderView_read_next_instance_w_condition (
    TP_Test_Complex128DataReaderView _this,
    DDS_sequence_TP_Test_Complex128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReaderView_take_next_instance_w_condition (
    TP_Test_Complex128DataReaderView _this,
    DDS_sequence_TP_Test_Complex128 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex128DataReaderView_get_key_value (
    TP_Test_Complex128DataReaderView _this,
    TP_Test_Complex128 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex128DataReaderView_lookup_instance (
    TP_Test_Complex128DataReaderView _this,
    TP_Test_Complex128 *key_holder
    );



#define TP_Test_Complex256TypeSupport DDS_TypeSupport

TP_Test_Complex256TypeSupport
TP_Test_Complex256TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Complex256TypeSupport_register_type (
    TP_Test_Complex256TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Complex256TypeSupport_get_type_name (
    TP_Test_Complex256TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Complex256_defined
#define _DDS_sequence_TP_Test_Complex256_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Complex256 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Complex256;

DDS_sequence_TP_Test_Complex256 *DDS_sequence_TP_Test_Complex256__alloc (void);
TP_Test_Complex256 *DDS_sequence_TP_Test_Complex256_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Complex256_defined */

#define TP_Test_Complex256DataWriter DDS_DataWriter

#define TP_Test_Complex256DataWriter_enable DDS_Entity_enable

#define TP_Test_Complex256DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex256DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex256DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex256DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Complex256DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Complex256DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Complex256DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Complex256DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Complex256DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Complex256DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Complex256DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Complex256DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Complex256DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Complex256DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Complex256DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Complex256DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Complex256DataWriter_register_instance (
    TP_Test_Complex256DataWriter _this,
    const TP_Test_Complex256 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Complex256DataWriter_register_instance_w_timestamp (
    TP_Test_Complex256DataWriter _this,
    const TP_Test_Complex256 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex256DataWriter_unregister_instance (
    TP_Test_Complex256DataWriter _this,
    const TP_Test_Complex256 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex256DataWriter_unregister_instance_w_timestamp (
    TP_Test_Complex256DataWriter _this,
    const TP_Test_Complex256 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex256DataWriter_write (
    TP_Test_Complex256DataWriter _this,
    const TP_Test_Complex256 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex256DataWriter_write_w_timestamp (
    TP_Test_Complex256DataWriter _this,
    const TP_Test_Complex256 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex256DataWriter_dispose (
    TP_Test_Complex256DataWriter _this,
    const TP_Test_Complex256 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex256DataWriter_dispose_w_timestamp (
    TP_Test_Complex256DataWriter _this,
    const TP_Test_Complex256 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex256DataWriter_writedispose (
    TP_Test_Complex256DataWriter _this,
    const TP_Test_Complex256 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex256DataWriter_writedispose_w_timestamp (
    TP_Test_Complex256DataWriter _this,
    const TP_Test_Complex256 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex256DataWriter_get_key_value (
    TP_Test_Complex256DataWriter _this,
    TP_Test_Complex256 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Complex256DataReader DDS_DataReader

#define TP_Test_Complex256DataReader_enable DDS_Entity_enable

#define TP_Test_Complex256DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex256DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex256DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex256DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Complex256DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Complex256DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Complex256DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Complex256DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Complex256DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Complex256DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Complex256DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Complex256DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Complex256DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Complex256DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Complex256DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Complex256DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Complex256DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Complex256DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Complex256DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Complex256DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Complex256DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Complex256DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Complex256DataReader_read (
    TP_Test_Complex256DataReader _this,
    DDS_sequence_TP_Test_Complex256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReader_take (
    TP_Test_Complex256DataReader _this,
    DDS_sequence_TP_Test_Complex256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReader_read_w_condition (
    TP_Test_Complex256DataReader _this,
    DDS_sequence_TP_Test_Complex256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReader_take_w_condition (
    TP_Test_Complex256DataReader _this,
    DDS_sequence_TP_Test_Complex256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReader_read_next_sample (
    TP_Test_Complex256DataReader _this,
    TP_Test_Complex256 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReader_take_next_sample (
    TP_Test_Complex256DataReader _this,
    TP_Test_Complex256 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReader_read_instance (
    TP_Test_Complex256DataReader _this,
    DDS_sequence_TP_Test_Complex256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReader_take_instance (
    TP_Test_Complex256DataReader _this,
    DDS_sequence_TP_Test_Complex256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReader_read_next_instance (
    TP_Test_Complex256DataReader _this,
    DDS_sequence_TP_Test_Complex256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReader_take_next_instance (
    TP_Test_Complex256DataReader _this,
    DDS_sequence_TP_Test_Complex256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReader_read_next_instance_w_condition (
    TP_Test_Complex256DataReader _this,
    DDS_sequence_TP_Test_Complex256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReader_take_next_instance_w_condition (
    TP_Test_Complex256DataReader _this,
    DDS_sequence_TP_Test_Complex256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReader_return_loan (
    TP_Test_Complex256DataReader _this,
    DDS_sequence_TP_Test_Complex256 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReader_get_key_value (
    TP_Test_Complex256DataReader _this,
    TP_Test_Complex256 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex256DataReader_lookup_instance (
    TP_Test_Complex256DataReader _this,
    const TP_Test_Complex256 *key_holder
    );

#define TP_Test_Complex256DataReaderView DDS_DataReaderView

#define TP_Test_Complex256DataReaderView_enable DDS_Entity_enable

#define TP_Test_Complex256DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex256DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Complex256DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Complex256DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Complex256DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Complex256DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Complex256DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Complex256DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Complex256DataReaderView_read (
    TP_Test_Complex256DataReaderView _this,
    DDS_sequence_TP_Test_Complex256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReaderView_take (
    TP_Test_Complex256DataReaderView _this,
    DDS_sequence_TP_Test_Complex256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReaderView_read_next_sample (
    TP_Test_Complex256DataReaderView _this,
    TP_Test_Complex256 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReaderView_take_next_sample (
    TP_Test_Complex256DataReaderView _this,
    TP_Test_Complex256 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReaderView_read_instance (
    TP_Test_Complex256DataReaderView _this,
    DDS_sequence_TP_Test_Complex256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReaderView_take_instance (
    TP_Test_Complex256DataReaderView _this,
    DDS_sequence_TP_Test_Complex256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReaderView_read_next_instance (
    TP_Test_Complex256DataReaderView _this,
    DDS_sequence_TP_Test_Complex256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReaderView_take_next_instance (
    TP_Test_Complex256DataReaderView _this,
    DDS_sequence_TP_Test_Complex256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReaderView_return_loan (
    TP_Test_Complex256DataReaderView _this,
    DDS_sequence_TP_Test_Complex256 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReaderView_read_w_condition (
    TP_Test_Complex256DataReaderView _this,
    DDS_sequence_TP_Test_Complex256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReaderView_take_w_condition (
    TP_Test_Complex256DataReaderView _this,
    DDS_sequence_TP_Test_Complex256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReaderView_read_next_instance_w_condition (
    TP_Test_Complex256DataReaderView _this,
    DDS_sequence_TP_Test_Complex256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReaderView_take_next_instance_w_condition (
    TP_Test_Complex256DataReaderView _this,
    DDS_sequence_TP_Test_Complex256 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex256DataReaderView_get_key_value (
    TP_Test_Complex256DataReaderView _this,
    TP_Test_Complex256 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex256DataReaderView_lookup_instance (
    TP_Test_Complex256DataReaderView _this,
    TP_Test_Complex256 *key_holder
    );



#define TP_Test_Complex512TypeSupport DDS_TypeSupport

TP_Test_Complex512TypeSupport
TP_Test_Complex512TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Complex512TypeSupport_register_type (
    TP_Test_Complex512TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Complex512TypeSupport_get_type_name (
    TP_Test_Complex512TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Complex512_defined
#define _DDS_sequence_TP_Test_Complex512_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Complex512 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Complex512;

DDS_sequence_TP_Test_Complex512 *DDS_sequence_TP_Test_Complex512__alloc (void);
TP_Test_Complex512 *DDS_sequence_TP_Test_Complex512_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Complex512_defined */

#define TP_Test_Complex512DataWriter DDS_DataWriter

#define TP_Test_Complex512DataWriter_enable DDS_Entity_enable

#define TP_Test_Complex512DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex512DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex512DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex512DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Complex512DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Complex512DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Complex512DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Complex512DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Complex512DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Complex512DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Complex512DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Complex512DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Complex512DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Complex512DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Complex512DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Complex512DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Complex512DataWriter_register_instance (
    TP_Test_Complex512DataWriter _this,
    const TP_Test_Complex512 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Complex512DataWriter_register_instance_w_timestamp (
    TP_Test_Complex512DataWriter _this,
    const TP_Test_Complex512 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex512DataWriter_unregister_instance (
    TP_Test_Complex512DataWriter _this,
    const TP_Test_Complex512 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex512DataWriter_unregister_instance_w_timestamp (
    TP_Test_Complex512DataWriter _this,
    const TP_Test_Complex512 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex512DataWriter_write (
    TP_Test_Complex512DataWriter _this,
    const TP_Test_Complex512 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex512DataWriter_write_w_timestamp (
    TP_Test_Complex512DataWriter _this,
    const TP_Test_Complex512 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex512DataWriter_dispose (
    TP_Test_Complex512DataWriter _this,
    const TP_Test_Complex512 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex512DataWriter_dispose_w_timestamp (
    TP_Test_Complex512DataWriter _this,
    const TP_Test_Complex512 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex512DataWriter_writedispose (
    TP_Test_Complex512DataWriter _this,
    const TP_Test_Complex512 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex512DataWriter_writedispose_w_timestamp (
    TP_Test_Complex512DataWriter _this,
    const TP_Test_Complex512 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex512DataWriter_get_key_value (
    TP_Test_Complex512DataWriter _this,
    TP_Test_Complex512 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Complex512DataReader DDS_DataReader

#define TP_Test_Complex512DataReader_enable DDS_Entity_enable

#define TP_Test_Complex512DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex512DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex512DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex512DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Complex512DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Complex512DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Complex512DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Complex512DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Complex512DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Complex512DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Complex512DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Complex512DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Complex512DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Complex512DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Complex512DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Complex512DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Complex512DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Complex512DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Complex512DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Complex512DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Complex512DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Complex512DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Complex512DataReader_read (
    TP_Test_Complex512DataReader _this,
    DDS_sequence_TP_Test_Complex512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReader_take (
    TP_Test_Complex512DataReader _this,
    DDS_sequence_TP_Test_Complex512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReader_read_w_condition (
    TP_Test_Complex512DataReader _this,
    DDS_sequence_TP_Test_Complex512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReader_take_w_condition (
    TP_Test_Complex512DataReader _this,
    DDS_sequence_TP_Test_Complex512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReader_read_next_sample (
    TP_Test_Complex512DataReader _this,
    TP_Test_Complex512 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReader_take_next_sample (
    TP_Test_Complex512DataReader _this,
    TP_Test_Complex512 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReader_read_instance (
    TP_Test_Complex512DataReader _this,
    DDS_sequence_TP_Test_Complex512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReader_take_instance (
    TP_Test_Complex512DataReader _this,
    DDS_sequence_TP_Test_Complex512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReader_read_next_instance (
    TP_Test_Complex512DataReader _this,
    DDS_sequence_TP_Test_Complex512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReader_take_next_instance (
    TP_Test_Complex512DataReader _this,
    DDS_sequence_TP_Test_Complex512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReader_read_next_instance_w_condition (
    TP_Test_Complex512DataReader _this,
    DDS_sequence_TP_Test_Complex512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReader_take_next_instance_w_condition (
    TP_Test_Complex512DataReader _this,
    DDS_sequence_TP_Test_Complex512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReader_return_loan (
    TP_Test_Complex512DataReader _this,
    DDS_sequence_TP_Test_Complex512 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReader_get_key_value (
    TP_Test_Complex512DataReader _this,
    TP_Test_Complex512 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex512DataReader_lookup_instance (
    TP_Test_Complex512DataReader _this,
    const TP_Test_Complex512 *key_holder
    );

#define TP_Test_Complex512DataReaderView DDS_DataReaderView

#define TP_Test_Complex512DataReaderView_enable DDS_Entity_enable

#define TP_Test_Complex512DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex512DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Complex512DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Complex512DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Complex512DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Complex512DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Complex512DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Complex512DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Complex512DataReaderView_read (
    TP_Test_Complex512DataReaderView _this,
    DDS_sequence_TP_Test_Complex512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReaderView_take (
    TP_Test_Complex512DataReaderView _this,
    DDS_sequence_TP_Test_Complex512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReaderView_read_next_sample (
    TP_Test_Complex512DataReaderView _this,
    TP_Test_Complex512 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReaderView_take_next_sample (
    TP_Test_Complex512DataReaderView _this,
    TP_Test_Complex512 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReaderView_read_instance (
    TP_Test_Complex512DataReaderView _this,
    DDS_sequence_TP_Test_Complex512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReaderView_take_instance (
    TP_Test_Complex512DataReaderView _this,
    DDS_sequence_TP_Test_Complex512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReaderView_read_next_instance (
    TP_Test_Complex512DataReaderView _this,
    DDS_sequence_TP_Test_Complex512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReaderView_take_next_instance (
    TP_Test_Complex512DataReaderView _this,
    DDS_sequence_TP_Test_Complex512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReaderView_return_loan (
    TP_Test_Complex512DataReaderView _this,
    DDS_sequence_TP_Test_Complex512 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReaderView_read_w_condition (
    TP_Test_Complex512DataReaderView _this,
    DDS_sequence_TP_Test_Complex512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReaderView_take_w_condition (
    TP_Test_Complex512DataReaderView _this,
    DDS_sequence_TP_Test_Complex512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReaderView_read_next_instance_w_condition (
    TP_Test_Complex512DataReaderView _this,
    DDS_sequence_TP_Test_Complex512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReaderView_take_next_instance_w_condition (
    TP_Test_Complex512DataReaderView _this,
    DDS_sequence_TP_Test_Complex512 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex512DataReaderView_get_key_value (
    TP_Test_Complex512DataReaderView _this,
    TP_Test_Complex512 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex512DataReaderView_lookup_instance (
    TP_Test_Complex512DataReaderView _this,
    TP_Test_Complex512 *key_holder
    );



#define TP_Test_Complex1024TypeSupport DDS_TypeSupport

TP_Test_Complex1024TypeSupport
TP_Test_Complex1024TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Complex1024TypeSupport_register_type (
    TP_Test_Complex1024TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Complex1024TypeSupport_get_type_name (
    TP_Test_Complex1024TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Complex1024_defined
#define _DDS_sequence_TP_Test_Complex1024_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Complex1024 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Complex1024;

DDS_sequence_TP_Test_Complex1024 *DDS_sequence_TP_Test_Complex1024__alloc (void);
TP_Test_Complex1024 *DDS_sequence_TP_Test_Complex1024_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Complex1024_defined */

#define TP_Test_Complex1024DataWriter DDS_DataWriter

#define TP_Test_Complex1024DataWriter_enable DDS_Entity_enable

#define TP_Test_Complex1024DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex1024DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex1024DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex1024DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Complex1024DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Complex1024DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Complex1024DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Complex1024DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Complex1024DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Complex1024DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Complex1024DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Complex1024DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Complex1024DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Complex1024DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Complex1024DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Complex1024DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Complex1024DataWriter_register_instance (
    TP_Test_Complex1024DataWriter _this,
    const TP_Test_Complex1024 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Complex1024DataWriter_register_instance_w_timestamp (
    TP_Test_Complex1024DataWriter _this,
    const TP_Test_Complex1024 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataWriter_unregister_instance (
    TP_Test_Complex1024DataWriter _this,
    const TP_Test_Complex1024 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataWriter_unregister_instance_w_timestamp (
    TP_Test_Complex1024DataWriter _this,
    const TP_Test_Complex1024 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataWriter_write (
    TP_Test_Complex1024DataWriter _this,
    const TP_Test_Complex1024 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataWriter_write_w_timestamp (
    TP_Test_Complex1024DataWriter _this,
    const TP_Test_Complex1024 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataWriter_dispose (
    TP_Test_Complex1024DataWriter _this,
    const TP_Test_Complex1024 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataWriter_dispose_w_timestamp (
    TP_Test_Complex1024DataWriter _this,
    const TP_Test_Complex1024 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataWriter_writedispose (
    TP_Test_Complex1024DataWriter _this,
    const TP_Test_Complex1024 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataWriter_writedispose_w_timestamp (
    TP_Test_Complex1024DataWriter _this,
    const TP_Test_Complex1024 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataWriter_get_key_value (
    TP_Test_Complex1024DataWriter _this,
    TP_Test_Complex1024 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Complex1024DataReader DDS_DataReader

#define TP_Test_Complex1024DataReader_enable DDS_Entity_enable

#define TP_Test_Complex1024DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex1024DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex1024DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex1024DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Complex1024DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Complex1024DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Complex1024DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Complex1024DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Complex1024DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Complex1024DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Complex1024DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Complex1024DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Complex1024DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Complex1024DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Complex1024DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Complex1024DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Complex1024DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Complex1024DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Complex1024DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Complex1024DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Complex1024DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Complex1024DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Complex1024DataReader_read (
    TP_Test_Complex1024DataReader _this,
    DDS_sequence_TP_Test_Complex1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReader_take (
    TP_Test_Complex1024DataReader _this,
    DDS_sequence_TP_Test_Complex1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReader_read_w_condition (
    TP_Test_Complex1024DataReader _this,
    DDS_sequence_TP_Test_Complex1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReader_take_w_condition (
    TP_Test_Complex1024DataReader _this,
    DDS_sequence_TP_Test_Complex1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReader_read_next_sample (
    TP_Test_Complex1024DataReader _this,
    TP_Test_Complex1024 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReader_take_next_sample (
    TP_Test_Complex1024DataReader _this,
    TP_Test_Complex1024 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReader_read_instance (
    TP_Test_Complex1024DataReader _this,
    DDS_sequence_TP_Test_Complex1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReader_take_instance (
    TP_Test_Complex1024DataReader _this,
    DDS_sequence_TP_Test_Complex1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReader_read_next_instance (
    TP_Test_Complex1024DataReader _this,
    DDS_sequence_TP_Test_Complex1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReader_take_next_instance (
    TP_Test_Complex1024DataReader _this,
    DDS_sequence_TP_Test_Complex1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReader_read_next_instance_w_condition (
    TP_Test_Complex1024DataReader _this,
    DDS_sequence_TP_Test_Complex1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReader_take_next_instance_w_condition (
    TP_Test_Complex1024DataReader _this,
    DDS_sequence_TP_Test_Complex1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReader_return_loan (
    TP_Test_Complex1024DataReader _this,
    DDS_sequence_TP_Test_Complex1024 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReader_get_key_value (
    TP_Test_Complex1024DataReader _this,
    TP_Test_Complex1024 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex1024DataReader_lookup_instance (
    TP_Test_Complex1024DataReader _this,
    const TP_Test_Complex1024 *key_holder
    );

#define TP_Test_Complex1024DataReaderView DDS_DataReaderView

#define TP_Test_Complex1024DataReaderView_enable DDS_Entity_enable

#define TP_Test_Complex1024DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex1024DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Complex1024DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Complex1024DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Complex1024DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Complex1024DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Complex1024DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Complex1024DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Complex1024DataReaderView_read (
    TP_Test_Complex1024DataReaderView _this,
    DDS_sequence_TP_Test_Complex1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReaderView_take (
    TP_Test_Complex1024DataReaderView _this,
    DDS_sequence_TP_Test_Complex1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReaderView_read_next_sample (
    TP_Test_Complex1024DataReaderView _this,
    TP_Test_Complex1024 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReaderView_take_next_sample (
    TP_Test_Complex1024DataReaderView _this,
    TP_Test_Complex1024 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReaderView_read_instance (
    TP_Test_Complex1024DataReaderView _this,
    DDS_sequence_TP_Test_Complex1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReaderView_take_instance (
    TP_Test_Complex1024DataReaderView _this,
    DDS_sequence_TP_Test_Complex1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReaderView_read_next_instance (
    TP_Test_Complex1024DataReaderView _this,
    DDS_sequence_TP_Test_Complex1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReaderView_take_next_instance (
    TP_Test_Complex1024DataReaderView _this,
    DDS_sequence_TP_Test_Complex1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReaderView_return_loan (
    TP_Test_Complex1024DataReaderView _this,
    DDS_sequence_TP_Test_Complex1024 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReaderView_read_w_condition (
    TP_Test_Complex1024DataReaderView _this,
    DDS_sequence_TP_Test_Complex1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReaderView_take_w_condition (
    TP_Test_Complex1024DataReaderView _this,
    DDS_sequence_TP_Test_Complex1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReaderView_read_next_instance_w_condition (
    TP_Test_Complex1024DataReaderView _this,
    DDS_sequence_TP_Test_Complex1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReaderView_take_next_instance_w_condition (
    TP_Test_Complex1024DataReaderView _this,
    DDS_sequence_TP_Test_Complex1024 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex1024DataReaderView_get_key_value (
    TP_Test_Complex1024DataReaderView _this,
    TP_Test_Complex1024 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex1024DataReaderView_lookup_instance (
    TP_Test_Complex1024DataReaderView _this,
    TP_Test_Complex1024 *key_holder
    );



#define TP_Test_Complex2048TypeSupport DDS_TypeSupport

TP_Test_Complex2048TypeSupport
TP_Test_Complex2048TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Complex2048TypeSupport_register_type (
    TP_Test_Complex2048TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Complex2048TypeSupport_get_type_name (
    TP_Test_Complex2048TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Complex2048_defined
#define _DDS_sequence_TP_Test_Complex2048_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Complex2048 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Complex2048;

DDS_sequence_TP_Test_Complex2048 *DDS_sequence_TP_Test_Complex2048__alloc (void);
TP_Test_Complex2048 *DDS_sequence_TP_Test_Complex2048_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Complex2048_defined */

#define TP_Test_Complex2048DataWriter DDS_DataWriter

#define TP_Test_Complex2048DataWriter_enable DDS_Entity_enable

#define TP_Test_Complex2048DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex2048DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex2048DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex2048DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Complex2048DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Complex2048DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Complex2048DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Complex2048DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Complex2048DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Complex2048DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Complex2048DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Complex2048DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Complex2048DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Complex2048DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Complex2048DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Complex2048DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Complex2048DataWriter_register_instance (
    TP_Test_Complex2048DataWriter _this,
    const TP_Test_Complex2048 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Complex2048DataWriter_register_instance_w_timestamp (
    TP_Test_Complex2048DataWriter _this,
    const TP_Test_Complex2048 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataWriter_unregister_instance (
    TP_Test_Complex2048DataWriter _this,
    const TP_Test_Complex2048 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataWriter_unregister_instance_w_timestamp (
    TP_Test_Complex2048DataWriter _this,
    const TP_Test_Complex2048 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataWriter_write (
    TP_Test_Complex2048DataWriter _this,
    const TP_Test_Complex2048 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataWriter_write_w_timestamp (
    TP_Test_Complex2048DataWriter _this,
    const TP_Test_Complex2048 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataWriter_dispose (
    TP_Test_Complex2048DataWriter _this,
    const TP_Test_Complex2048 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataWriter_dispose_w_timestamp (
    TP_Test_Complex2048DataWriter _this,
    const TP_Test_Complex2048 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataWriter_writedispose (
    TP_Test_Complex2048DataWriter _this,
    const TP_Test_Complex2048 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataWriter_writedispose_w_timestamp (
    TP_Test_Complex2048DataWriter _this,
    const TP_Test_Complex2048 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataWriter_get_key_value (
    TP_Test_Complex2048DataWriter _this,
    TP_Test_Complex2048 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Complex2048DataReader DDS_DataReader

#define TP_Test_Complex2048DataReader_enable DDS_Entity_enable

#define TP_Test_Complex2048DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex2048DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex2048DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex2048DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Complex2048DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Complex2048DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Complex2048DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Complex2048DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Complex2048DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Complex2048DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Complex2048DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Complex2048DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Complex2048DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Complex2048DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Complex2048DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Complex2048DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Complex2048DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Complex2048DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Complex2048DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Complex2048DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Complex2048DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Complex2048DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Complex2048DataReader_read (
    TP_Test_Complex2048DataReader _this,
    DDS_sequence_TP_Test_Complex2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReader_take (
    TP_Test_Complex2048DataReader _this,
    DDS_sequence_TP_Test_Complex2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReader_read_w_condition (
    TP_Test_Complex2048DataReader _this,
    DDS_sequence_TP_Test_Complex2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReader_take_w_condition (
    TP_Test_Complex2048DataReader _this,
    DDS_sequence_TP_Test_Complex2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReader_read_next_sample (
    TP_Test_Complex2048DataReader _this,
    TP_Test_Complex2048 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReader_take_next_sample (
    TP_Test_Complex2048DataReader _this,
    TP_Test_Complex2048 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReader_read_instance (
    TP_Test_Complex2048DataReader _this,
    DDS_sequence_TP_Test_Complex2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReader_take_instance (
    TP_Test_Complex2048DataReader _this,
    DDS_sequence_TP_Test_Complex2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReader_read_next_instance (
    TP_Test_Complex2048DataReader _this,
    DDS_sequence_TP_Test_Complex2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReader_take_next_instance (
    TP_Test_Complex2048DataReader _this,
    DDS_sequence_TP_Test_Complex2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReader_read_next_instance_w_condition (
    TP_Test_Complex2048DataReader _this,
    DDS_sequence_TP_Test_Complex2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReader_take_next_instance_w_condition (
    TP_Test_Complex2048DataReader _this,
    DDS_sequence_TP_Test_Complex2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReader_return_loan (
    TP_Test_Complex2048DataReader _this,
    DDS_sequence_TP_Test_Complex2048 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReader_get_key_value (
    TP_Test_Complex2048DataReader _this,
    TP_Test_Complex2048 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex2048DataReader_lookup_instance (
    TP_Test_Complex2048DataReader _this,
    const TP_Test_Complex2048 *key_holder
    );

#define TP_Test_Complex2048DataReaderView DDS_DataReaderView

#define TP_Test_Complex2048DataReaderView_enable DDS_Entity_enable

#define TP_Test_Complex2048DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex2048DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Complex2048DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Complex2048DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Complex2048DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Complex2048DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Complex2048DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Complex2048DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Complex2048DataReaderView_read (
    TP_Test_Complex2048DataReaderView _this,
    DDS_sequence_TP_Test_Complex2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReaderView_take (
    TP_Test_Complex2048DataReaderView _this,
    DDS_sequence_TP_Test_Complex2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReaderView_read_next_sample (
    TP_Test_Complex2048DataReaderView _this,
    TP_Test_Complex2048 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReaderView_take_next_sample (
    TP_Test_Complex2048DataReaderView _this,
    TP_Test_Complex2048 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReaderView_read_instance (
    TP_Test_Complex2048DataReaderView _this,
    DDS_sequence_TP_Test_Complex2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReaderView_take_instance (
    TP_Test_Complex2048DataReaderView _this,
    DDS_sequence_TP_Test_Complex2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReaderView_read_next_instance (
    TP_Test_Complex2048DataReaderView _this,
    DDS_sequence_TP_Test_Complex2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReaderView_take_next_instance (
    TP_Test_Complex2048DataReaderView _this,
    DDS_sequence_TP_Test_Complex2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReaderView_return_loan (
    TP_Test_Complex2048DataReaderView _this,
    DDS_sequence_TP_Test_Complex2048 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReaderView_read_w_condition (
    TP_Test_Complex2048DataReaderView _this,
    DDS_sequence_TP_Test_Complex2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReaderView_take_w_condition (
    TP_Test_Complex2048DataReaderView _this,
    DDS_sequence_TP_Test_Complex2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReaderView_read_next_instance_w_condition (
    TP_Test_Complex2048DataReaderView _this,
    DDS_sequence_TP_Test_Complex2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReaderView_take_next_instance_w_condition (
    TP_Test_Complex2048DataReaderView _this,
    DDS_sequence_TP_Test_Complex2048 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex2048DataReaderView_get_key_value (
    TP_Test_Complex2048DataReaderView _this,
    TP_Test_Complex2048 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex2048DataReaderView_lookup_instance (
    TP_Test_Complex2048DataReaderView _this,
    TP_Test_Complex2048 *key_holder
    );



#define TP_Test_Complex4096TypeSupport DDS_TypeSupport

TP_Test_Complex4096TypeSupport
TP_Test_Complex4096TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Complex4096TypeSupport_register_type (
    TP_Test_Complex4096TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Complex4096TypeSupport_get_type_name (
    TP_Test_Complex4096TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Complex4096_defined
#define _DDS_sequence_TP_Test_Complex4096_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Complex4096 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Complex4096;

DDS_sequence_TP_Test_Complex4096 *DDS_sequence_TP_Test_Complex4096__alloc (void);
TP_Test_Complex4096 *DDS_sequence_TP_Test_Complex4096_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Complex4096_defined */

#define TP_Test_Complex4096DataWriter DDS_DataWriter

#define TP_Test_Complex4096DataWriter_enable DDS_Entity_enable

#define TP_Test_Complex4096DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex4096DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex4096DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex4096DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Complex4096DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Complex4096DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Complex4096DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Complex4096DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Complex4096DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Complex4096DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Complex4096DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Complex4096DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Complex4096DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Complex4096DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Complex4096DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Complex4096DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Complex4096DataWriter_register_instance (
    TP_Test_Complex4096DataWriter _this,
    const TP_Test_Complex4096 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Complex4096DataWriter_register_instance_w_timestamp (
    TP_Test_Complex4096DataWriter _this,
    const TP_Test_Complex4096 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataWriter_unregister_instance (
    TP_Test_Complex4096DataWriter _this,
    const TP_Test_Complex4096 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataWriter_unregister_instance_w_timestamp (
    TP_Test_Complex4096DataWriter _this,
    const TP_Test_Complex4096 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataWriter_write (
    TP_Test_Complex4096DataWriter _this,
    const TP_Test_Complex4096 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataWriter_write_w_timestamp (
    TP_Test_Complex4096DataWriter _this,
    const TP_Test_Complex4096 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataWriter_dispose (
    TP_Test_Complex4096DataWriter _this,
    const TP_Test_Complex4096 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataWriter_dispose_w_timestamp (
    TP_Test_Complex4096DataWriter _this,
    const TP_Test_Complex4096 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataWriter_writedispose (
    TP_Test_Complex4096DataWriter _this,
    const TP_Test_Complex4096 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataWriter_writedispose_w_timestamp (
    TP_Test_Complex4096DataWriter _this,
    const TP_Test_Complex4096 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataWriter_get_key_value (
    TP_Test_Complex4096DataWriter _this,
    TP_Test_Complex4096 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Complex4096DataReader DDS_DataReader

#define TP_Test_Complex4096DataReader_enable DDS_Entity_enable

#define TP_Test_Complex4096DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex4096DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex4096DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex4096DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Complex4096DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Complex4096DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Complex4096DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Complex4096DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Complex4096DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Complex4096DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Complex4096DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Complex4096DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Complex4096DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Complex4096DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Complex4096DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Complex4096DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Complex4096DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Complex4096DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Complex4096DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Complex4096DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Complex4096DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Complex4096DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Complex4096DataReader_read (
    TP_Test_Complex4096DataReader _this,
    DDS_sequence_TP_Test_Complex4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReader_take (
    TP_Test_Complex4096DataReader _this,
    DDS_sequence_TP_Test_Complex4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReader_read_w_condition (
    TP_Test_Complex4096DataReader _this,
    DDS_sequence_TP_Test_Complex4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReader_take_w_condition (
    TP_Test_Complex4096DataReader _this,
    DDS_sequence_TP_Test_Complex4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReader_read_next_sample (
    TP_Test_Complex4096DataReader _this,
    TP_Test_Complex4096 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReader_take_next_sample (
    TP_Test_Complex4096DataReader _this,
    TP_Test_Complex4096 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReader_read_instance (
    TP_Test_Complex4096DataReader _this,
    DDS_sequence_TP_Test_Complex4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReader_take_instance (
    TP_Test_Complex4096DataReader _this,
    DDS_sequence_TP_Test_Complex4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReader_read_next_instance (
    TP_Test_Complex4096DataReader _this,
    DDS_sequence_TP_Test_Complex4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReader_take_next_instance (
    TP_Test_Complex4096DataReader _this,
    DDS_sequence_TP_Test_Complex4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReader_read_next_instance_w_condition (
    TP_Test_Complex4096DataReader _this,
    DDS_sequence_TP_Test_Complex4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReader_take_next_instance_w_condition (
    TP_Test_Complex4096DataReader _this,
    DDS_sequence_TP_Test_Complex4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReader_return_loan (
    TP_Test_Complex4096DataReader _this,
    DDS_sequence_TP_Test_Complex4096 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReader_get_key_value (
    TP_Test_Complex4096DataReader _this,
    TP_Test_Complex4096 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex4096DataReader_lookup_instance (
    TP_Test_Complex4096DataReader _this,
    const TP_Test_Complex4096 *key_holder
    );

#define TP_Test_Complex4096DataReaderView DDS_DataReaderView

#define TP_Test_Complex4096DataReaderView_enable DDS_Entity_enable

#define TP_Test_Complex4096DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex4096DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Complex4096DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Complex4096DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Complex4096DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Complex4096DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Complex4096DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Complex4096DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Complex4096DataReaderView_read (
    TP_Test_Complex4096DataReaderView _this,
    DDS_sequence_TP_Test_Complex4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReaderView_take (
    TP_Test_Complex4096DataReaderView _this,
    DDS_sequence_TP_Test_Complex4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReaderView_read_next_sample (
    TP_Test_Complex4096DataReaderView _this,
    TP_Test_Complex4096 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReaderView_take_next_sample (
    TP_Test_Complex4096DataReaderView _this,
    TP_Test_Complex4096 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReaderView_read_instance (
    TP_Test_Complex4096DataReaderView _this,
    DDS_sequence_TP_Test_Complex4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReaderView_take_instance (
    TP_Test_Complex4096DataReaderView _this,
    DDS_sequence_TP_Test_Complex4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReaderView_read_next_instance (
    TP_Test_Complex4096DataReaderView _this,
    DDS_sequence_TP_Test_Complex4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReaderView_take_next_instance (
    TP_Test_Complex4096DataReaderView _this,
    DDS_sequence_TP_Test_Complex4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReaderView_return_loan (
    TP_Test_Complex4096DataReaderView _this,
    DDS_sequence_TP_Test_Complex4096 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReaderView_read_w_condition (
    TP_Test_Complex4096DataReaderView _this,
    DDS_sequence_TP_Test_Complex4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReaderView_take_w_condition (
    TP_Test_Complex4096DataReaderView _this,
    DDS_sequence_TP_Test_Complex4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReaderView_read_next_instance_w_condition (
    TP_Test_Complex4096DataReaderView _this,
    DDS_sequence_TP_Test_Complex4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReaderView_take_next_instance_w_condition (
    TP_Test_Complex4096DataReaderView _this,
    DDS_sequence_TP_Test_Complex4096 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex4096DataReaderView_get_key_value (
    TP_Test_Complex4096DataReaderView _this,
    TP_Test_Complex4096 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex4096DataReaderView_lookup_instance (
    TP_Test_Complex4096DataReaderView _this,
    TP_Test_Complex4096 *key_holder
    );



#define TP_Test_Complex8192TypeSupport DDS_TypeSupport

TP_Test_Complex8192TypeSupport
TP_Test_Complex8192TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Complex8192TypeSupport_register_type (
    TP_Test_Complex8192TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Complex8192TypeSupport_get_type_name (
    TP_Test_Complex8192TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Complex8192_defined
#define _DDS_sequence_TP_Test_Complex8192_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Complex8192 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Complex8192;

DDS_sequence_TP_Test_Complex8192 *DDS_sequence_TP_Test_Complex8192__alloc (void);
TP_Test_Complex8192 *DDS_sequence_TP_Test_Complex8192_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Complex8192_defined */

#define TP_Test_Complex8192DataWriter DDS_DataWriter

#define TP_Test_Complex8192DataWriter_enable DDS_Entity_enable

#define TP_Test_Complex8192DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex8192DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex8192DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex8192DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Complex8192DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Complex8192DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Complex8192DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Complex8192DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Complex8192DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Complex8192DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Complex8192DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Complex8192DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Complex8192DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Complex8192DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Complex8192DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Complex8192DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Complex8192DataWriter_register_instance (
    TP_Test_Complex8192DataWriter _this,
    const TP_Test_Complex8192 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Complex8192DataWriter_register_instance_w_timestamp (
    TP_Test_Complex8192DataWriter _this,
    const TP_Test_Complex8192 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataWriter_unregister_instance (
    TP_Test_Complex8192DataWriter _this,
    const TP_Test_Complex8192 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataWriter_unregister_instance_w_timestamp (
    TP_Test_Complex8192DataWriter _this,
    const TP_Test_Complex8192 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataWriter_write (
    TP_Test_Complex8192DataWriter _this,
    const TP_Test_Complex8192 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataWriter_write_w_timestamp (
    TP_Test_Complex8192DataWriter _this,
    const TP_Test_Complex8192 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataWriter_dispose (
    TP_Test_Complex8192DataWriter _this,
    const TP_Test_Complex8192 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataWriter_dispose_w_timestamp (
    TP_Test_Complex8192DataWriter _this,
    const TP_Test_Complex8192 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataWriter_writedispose (
    TP_Test_Complex8192DataWriter _this,
    const TP_Test_Complex8192 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataWriter_writedispose_w_timestamp (
    TP_Test_Complex8192DataWriter _this,
    const TP_Test_Complex8192 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataWriter_get_key_value (
    TP_Test_Complex8192DataWriter _this,
    TP_Test_Complex8192 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Complex8192DataReader DDS_DataReader

#define TP_Test_Complex8192DataReader_enable DDS_Entity_enable

#define TP_Test_Complex8192DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex8192DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex8192DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex8192DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Complex8192DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Complex8192DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Complex8192DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Complex8192DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Complex8192DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Complex8192DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Complex8192DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Complex8192DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Complex8192DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Complex8192DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Complex8192DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Complex8192DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Complex8192DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Complex8192DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Complex8192DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Complex8192DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Complex8192DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Complex8192DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Complex8192DataReader_read (
    TP_Test_Complex8192DataReader _this,
    DDS_sequence_TP_Test_Complex8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReader_take (
    TP_Test_Complex8192DataReader _this,
    DDS_sequence_TP_Test_Complex8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReader_read_w_condition (
    TP_Test_Complex8192DataReader _this,
    DDS_sequence_TP_Test_Complex8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReader_take_w_condition (
    TP_Test_Complex8192DataReader _this,
    DDS_sequence_TP_Test_Complex8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReader_read_next_sample (
    TP_Test_Complex8192DataReader _this,
    TP_Test_Complex8192 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReader_take_next_sample (
    TP_Test_Complex8192DataReader _this,
    TP_Test_Complex8192 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReader_read_instance (
    TP_Test_Complex8192DataReader _this,
    DDS_sequence_TP_Test_Complex8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReader_take_instance (
    TP_Test_Complex8192DataReader _this,
    DDS_sequence_TP_Test_Complex8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReader_read_next_instance (
    TP_Test_Complex8192DataReader _this,
    DDS_sequence_TP_Test_Complex8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReader_take_next_instance (
    TP_Test_Complex8192DataReader _this,
    DDS_sequence_TP_Test_Complex8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReader_read_next_instance_w_condition (
    TP_Test_Complex8192DataReader _this,
    DDS_sequence_TP_Test_Complex8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReader_take_next_instance_w_condition (
    TP_Test_Complex8192DataReader _this,
    DDS_sequence_TP_Test_Complex8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReader_return_loan (
    TP_Test_Complex8192DataReader _this,
    DDS_sequence_TP_Test_Complex8192 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReader_get_key_value (
    TP_Test_Complex8192DataReader _this,
    TP_Test_Complex8192 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex8192DataReader_lookup_instance (
    TP_Test_Complex8192DataReader _this,
    const TP_Test_Complex8192 *key_holder
    );

#define TP_Test_Complex8192DataReaderView DDS_DataReaderView

#define TP_Test_Complex8192DataReaderView_enable DDS_Entity_enable

#define TP_Test_Complex8192DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex8192DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Complex8192DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Complex8192DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Complex8192DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Complex8192DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Complex8192DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Complex8192DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Complex8192DataReaderView_read (
    TP_Test_Complex8192DataReaderView _this,
    DDS_sequence_TP_Test_Complex8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReaderView_take (
    TP_Test_Complex8192DataReaderView _this,
    DDS_sequence_TP_Test_Complex8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReaderView_read_next_sample (
    TP_Test_Complex8192DataReaderView _this,
    TP_Test_Complex8192 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReaderView_take_next_sample (
    TP_Test_Complex8192DataReaderView _this,
    TP_Test_Complex8192 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReaderView_read_instance (
    TP_Test_Complex8192DataReaderView _this,
    DDS_sequence_TP_Test_Complex8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReaderView_take_instance (
    TP_Test_Complex8192DataReaderView _this,
    DDS_sequence_TP_Test_Complex8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReaderView_read_next_instance (
    TP_Test_Complex8192DataReaderView _this,
    DDS_sequence_TP_Test_Complex8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReaderView_take_next_instance (
    TP_Test_Complex8192DataReaderView _this,
    DDS_sequence_TP_Test_Complex8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReaderView_return_loan (
    TP_Test_Complex8192DataReaderView _this,
    DDS_sequence_TP_Test_Complex8192 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReaderView_read_w_condition (
    TP_Test_Complex8192DataReaderView _this,
    DDS_sequence_TP_Test_Complex8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReaderView_take_w_condition (
    TP_Test_Complex8192DataReaderView _this,
    DDS_sequence_TP_Test_Complex8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReaderView_read_next_instance_w_condition (
    TP_Test_Complex8192DataReaderView _this,
    DDS_sequence_TP_Test_Complex8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReaderView_take_next_instance_w_condition (
    TP_Test_Complex8192DataReaderView _this,
    DDS_sequence_TP_Test_Complex8192 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex8192DataReaderView_get_key_value (
    TP_Test_Complex8192DataReaderView _this,
    TP_Test_Complex8192 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex8192DataReaderView_lookup_instance (
    TP_Test_Complex8192DataReaderView _this,
    TP_Test_Complex8192 *key_holder
    );



#define TP_Test_Complex16384TypeSupport DDS_TypeSupport

TP_Test_Complex16384TypeSupport
TP_Test_Complex16384TypeSupport__alloc (
    void
    );

DDS_ReturnCode_t
TP_Test_Complex16384TypeSupport_register_type (
    TP_Test_Complex16384TypeSupport _this,
    const DDS_DomainParticipant domain,
    const DDS_string name
    );

DDS_string
TP_Test_Complex16384TypeSupport_get_type_name (
    TP_Test_Complex16384TypeSupport _this
    );

#ifndef _DDS_sequence_TP_Test_Complex16384_defined
#define _DDS_sequence_TP_Test_Complex16384_defined
typedef struct {
    DDS_unsigned_long _maximum;
    DDS_unsigned_long _length;
    TP_Test_Complex16384 *_buffer;
    DDS_boolean _release;
} DDS_sequence_TP_Test_Complex16384;

DDS_sequence_TP_Test_Complex16384 *DDS_sequence_TP_Test_Complex16384__alloc (void);
TP_Test_Complex16384 *DDS_sequence_TP_Test_Complex16384_allocbuf (DDS_unsigned_long len);
#endif /* _DDS_sequence_TP_Test_Complex16384_defined */

#define TP_Test_Complex16384DataWriter DDS_DataWriter

#define TP_Test_Complex16384DataWriter_enable DDS_Entity_enable

#define TP_Test_Complex16384DataWriter_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex16384DataWriter_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex16384DataWriter_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex16384DataWriter_assert_liveliness DDS_DataWriter_assert_liveliness

#define TP_Test_Complex16384DataWriter_get_listener DDS_DataWriter_get_listener

#define TP_Test_Complex16384DataWriter_get_liveliness_lost_status DDS_DataWriter_get_liveliness_lost_status

#define TP_Test_Complex16384DataWriter_get_matched_subscription_data DDS_DataWriter_get_matched_subscription_data

#define TP_Test_Complex16384DataWriter_get_matched_subscriptions DDS_DataWriter_get_matched_subscriptions

#define TP_Test_Complex16384DataWriter_get_offered_deadline_missed_status DDS_DataWriter_get_offered_deadline_missed_status

#define TP_Test_Complex16384DataWriter_get_offered_incompatible_qos_status DDS_DataWriter_get_offered_incompatible_qos_status

#define TP_Test_Complex16384DataWriter_get_publication_match_status DDS_DataWriter_get_publication_match_status

#define TP_Test_Complex16384DataWriter_get_publisher DDS_DataWriter_get_publisher

#define TP_Test_Complex16384DataWriter_get_qos DDS_DataWriter_get_qos

#define TP_Test_Complex16384DataWriter_get_topic DDS_DataWriter_get_topic

#define TP_Test_Complex16384DataWriter_set_listener DDS_DataWriter_set_listener

#define TP_Test_Complex16384DataWriter_set_qos DDS_DataWriter_set_qos

DDS_InstanceHandle_t
TP_Test_Complex16384DataWriter_register_instance (
    TP_Test_Complex16384DataWriter _this,
    const TP_Test_Complex16384 *instance_data
    );

DDS_InstanceHandle_t
TP_Test_Complex16384DataWriter_register_instance_w_timestamp (
    TP_Test_Complex16384DataWriter _this,
    const TP_Test_Complex16384 *instance_data,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataWriter_unregister_instance (
    TP_Test_Complex16384DataWriter _this,
    const TP_Test_Complex16384 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataWriter_unregister_instance_w_timestamp (
    TP_Test_Complex16384DataWriter _this,
    const TP_Test_Complex16384 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataWriter_write (
    TP_Test_Complex16384DataWriter _this,
    const TP_Test_Complex16384 *instance_data,
    const DDS_InstanceHandle_t handle
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataWriter_write_w_timestamp (
    TP_Test_Complex16384DataWriter _this,
    const TP_Test_Complex16384 *instance_data,
    const DDS_InstanceHandle_t handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataWriter_dispose (
    TP_Test_Complex16384DataWriter _this,
    const TP_Test_Complex16384 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataWriter_dispose_w_timestamp (
    TP_Test_Complex16384DataWriter _this,
    const TP_Test_Complex16384 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataWriter_writedispose (
    TP_Test_Complex16384DataWriter _this,
    const TP_Test_Complex16384 *instance_data,
    const DDS_InstanceHandle_t instance_handle
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataWriter_writedispose_w_timestamp (
    TP_Test_Complex16384DataWriter _this,
    const TP_Test_Complex16384 *instance_data,
    const DDS_InstanceHandle_t instance_handle,
    const DDS_Time_t *source_timestamp
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataWriter_get_key_value (
    TP_Test_Complex16384DataWriter _this,
    TP_Test_Complex16384 *key_holder,
    const DDS_InstanceHandle_t handle
    );

#define TP_Test_Complex16384DataReader DDS_DataReader

#define TP_Test_Complex16384DataReader_enable DDS_Entity_enable

#define TP_Test_Complex16384DataReader_get_status_changes DDS_Entity_get_status_changes

#define TP_Test_Complex16384DataReader_get_statuscondition DDS_Entity_get_statuscondition

#define TP_Test_Complex16384DataReader_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex16384DataReader_create_querycondition DDS_DataReader_create_querycondition

#define TP_Test_Complex16384DataReader_create_readcondition DDS_DataReader_create_readcondition

#define TP_Test_Complex16384DataReader_delete_contained_entities DDS_DataReader_delete_contained_entities

#define TP_Test_Complex16384DataReader_delete_readcondition DDS_DataReader_delete_readcondition

#define TP_Test_Complex16384DataReader_get_listener DDS_DataReader_get_listener

#define TP_Test_Complex16384DataReader_get_liveliness_changed_status DDS_DataReader_get_liveliness_changed_status

#define TP_Test_Complex16384DataReader_get_matched_publication_data DDS_DataReader_get_matched_publication_data

#define TP_Test_Complex16384DataReader_get_matched_publications DDS_DataReader_get_matched_publications

#define TP_Test_Complex16384DataReader_get_qos DDS_DataReader_get_qos

#define TP_Test_Complex16384DataReader_get_requested_deadline_missed_status DDS_DataReader_get_requested_deadline_missed_status

#define TP_Test_Complex16384DataReader_get_requested_incompatible_qos_status DDS_DataReader_get_requested_incompatible_qos_status

#define TP_Test_Complex16384DataReader_get_sample_lost_status DDS_DataReader_get_sample_lost_status

#define TP_Test_Complex16384DataReader_get_sample_rejected_status DDS_DataReader_get_sample_rejected_status

#define TP_Test_Complex16384DataReader_get_subscriber DDS_DataReader_get_subscriber

#define TP_Test_Complex16384DataReader_get_subscription_match_status DDS_DataReader_get_subscription_match_status

#define TP_Test_Complex16384DataReader_get_topicdescription DDS_DataReader_get_topicdescription

#define TP_Test_Complex16384DataReader_set_listener DDS_DataReader_set_listener

#define TP_Test_Complex16384DataReader_set_qos DDS_DataReader_set_qos

#define TP_Test_Complex16384DataReader_wait_for_historical_data DDS_DataReader_wait_for_historical_data

DDS_ReturnCode_t
TP_Test_Complex16384DataReader_read (
    TP_Test_Complex16384DataReader _this,
    DDS_sequence_TP_Test_Complex16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReader_take (
    TP_Test_Complex16384DataReader _this,
    DDS_sequence_TP_Test_Complex16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReader_read_w_condition (
    TP_Test_Complex16384DataReader _this,
    DDS_sequence_TP_Test_Complex16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReader_take_w_condition (
    TP_Test_Complex16384DataReader _this,
    DDS_sequence_TP_Test_Complex16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReader_read_next_sample (
    TP_Test_Complex16384DataReader _this,
    TP_Test_Complex16384 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReader_take_next_sample (
    TP_Test_Complex16384DataReader _this,
    TP_Test_Complex16384 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReader_read_instance (
    TP_Test_Complex16384DataReader _this,
    DDS_sequence_TP_Test_Complex16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReader_take_instance (
    TP_Test_Complex16384DataReader _this,
    DDS_sequence_TP_Test_Complex16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReader_read_next_instance (
    TP_Test_Complex16384DataReader _this,
    DDS_sequence_TP_Test_Complex16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReader_take_next_instance (
    TP_Test_Complex16384DataReader _this,
    DDS_sequence_TP_Test_Complex16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReader_read_next_instance_w_condition (
    TP_Test_Complex16384DataReader _this,
    DDS_sequence_TP_Test_Complex16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReader_take_next_instance_w_condition (
    TP_Test_Complex16384DataReader _this,
    DDS_sequence_TP_Test_Complex16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReader_return_loan (
    TP_Test_Complex16384DataReader _this,
    DDS_sequence_TP_Test_Complex16384 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReader_get_key_value (
    TP_Test_Complex16384DataReader _this,
    TP_Test_Complex16384 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex16384DataReader_lookup_instance (
    TP_Test_Complex16384DataReader _this,
    const TP_Test_Complex16384 *key_holder
    );

#define TP_Test_Complex16384DataReaderView DDS_DataReaderView

#define TP_Test_Complex16384DataReaderView_enable DDS_Entity_enable

#define TP_Test_Complex16384DataReaderView_get_instance_handle DDS_Entity_get_instance_handle

#define TP_Test_Complex16384DataReaderView_get_qos DDS_DataReaderView_get_qos

#define TP_Test_Complex16384DataReaderView_get_datareader DDS_DataReaderView_get_datareader

#define TP_Test_Complex16384DataReaderView_set_qos DDS_DataReaderView_set_qos

#define TP_Test_Complex16384DataReaderView_create_readcondition DDS_DataReaderView_create_readcondition

#define TP_Test_Complex16384DataReaderView_create_querycondition DDS_DataReaderView_create_querycondition

#define TP_Test_Complex16384DataReaderView_delete_readcondition DDS_DataReaderView_delete_readcondition

#define TP_Test_Complex16384DataReaderView_delete_contained_entities DDS_DataReaderView_delete_contained_entities

DDS_ReturnCode_t
TP_Test_Complex16384DataReaderView_read (
    TP_Test_Complex16384DataReaderView _this,
    DDS_sequence_TP_Test_Complex16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReaderView_take (
    TP_Test_Complex16384DataReaderView _this,
    DDS_sequence_TP_Test_Complex16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReaderView_read_next_sample (
    TP_Test_Complex16384DataReaderView _this,
    TP_Test_Complex16384 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReaderView_take_next_sample (
    TP_Test_Complex16384DataReaderView _this,
    TP_Test_Complex16384 *received_data,
    DDS_SampleInfo *sample_info
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReaderView_read_instance (
    TP_Test_Complex16384DataReaderView _this,
    DDS_sequence_TP_Test_Complex16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReaderView_take_instance (
    TP_Test_Complex16384DataReaderView _this,
    DDS_sequence_TP_Test_Complex16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReaderView_read_next_instance (
    TP_Test_Complex16384DataReaderView _this,
    DDS_sequence_TP_Test_Complex16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReaderView_take_next_instance (
    TP_Test_Complex16384DataReaderView _this,
    DDS_sequence_TP_Test_Complex16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_SampleStateMask sample_states,
    const DDS_ViewStateMask view_states,
    const DDS_InstanceStateMask instance_states
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReaderView_return_loan (
    TP_Test_Complex16384DataReaderView _this,
    DDS_sequence_TP_Test_Complex16384 *received_data,
    DDS_SampleInfoSeq *info_seq
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReaderView_read_w_condition (
    TP_Test_Complex16384DataReaderView _this,
    DDS_sequence_TP_Test_Complex16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReaderView_take_w_condition (
    TP_Test_Complex16384DataReaderView _this,
    DDS_sequence_TP_Test_Complex16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReaderView_read_next_instance_w_condition (
    TP_Test_Complex16384DataReaderView _this,
    DDS_sequence_TP_Test_Complex16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReaderView_take_next_instance_w_condition (
    TP_Test_Complex16384DataReaderView _this,
    DDS_sequence_TP_Test_Complex16384 *received_data,
    DDS_SampleInfoSeq *info_seq,
    const DDS_long max_samples,
    const DDS_InstanceHandle_t a_handle,
    const DDS_ReadCondition a_condition
    );

DDS_ReturnCode_t
TP_Test_Complex16384DataReaderView_get_key_value (
    TP_Test_Complex16384DataReaderView _this,
    TP_Test_Complex16384 *key_holder,
    const DDS_InstanceHandle_t handle
    );

DDS_InstanceHandle_t
TP_Test_Complex16384DataReaderView_lookup_instance (
    TP_Test_Complex16384DataReaderView _this,
    TP_Test_Complex16384 *key_holder
    );


#endif
