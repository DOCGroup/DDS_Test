#include "deepTypesSplDcps.h"
#include "deepTypesDcps_impl.h"
#include "ccpp_DataReader_impl.h"
#include "gapi.h"
#include "os_if.h"

#ifndef DDS_API
#define DDS_API
#endif

extern void
__deepTypes_simpleType__copyIn(
    c_base base,
    struct deepTypes::simpleType *from,
    struct _deepTypes_simpleType *to
);

extern void
__deepTypes_simpleType__copyOut(
    void *_from,
    void *_to
);

// DDS deepTypes::simpleType TypeSupportFactory Object Body

DDS_API DDS::DataWriter_ptr 
deepTypes::simpleTypeTypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new deepTypes::simpleTypeDataWriter_impl(handle, statusConditionData);
};

DDS_API DDS::DataReader_ptr 
deepTypes::simpleTypeTypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new deepTypes::simpleTypeDataReader_impl (handle, statusConditionData);
};

// DDS deepTypes::simpleType TypeSupport Object Body

DDS_API deepTypes::simpleTypeTypeSupport::simpleTypeTypeSupport (void) :
    TypeSupport_impl(
        __deepTypes_simpleType__name(),
        __deepTypes_simpleType__keys(),
        deepTypes::simpleTypeTypeSupport::metaDescriptor,
        (gapi_copyIn) __deepTypes_simpleType__copyIn,
        (gapi_copyOut) __deepTypes_simpleType__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<deepTypes::simpleTypeSeq, deepTypes::simpleType>,
        new  deepTypes::simpleTypeTypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

DDS_API deepTypes::simpleTypeTypeSupport::~simpleTypeTypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS_API DDS::ReturnCode_t
deepTypes::simpleTypeTypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

DDS_API char *
deepTypes::simpleTypeTypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS deepTypes::simpleType DataWriter_impl Object Body

DDS_API deepTypes::simpleTypeDataWriter_impl::simpleTypeDataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

DDS_API deepTypes::simpleTypeDataWriter_impl::~simpleTypeDataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS_API DDS::InstanceHandle_t
deepTypes::simpleTypeDataWriter_impl::register_instance (
    const deepTypes::simpleType & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS_API DDS::InstanceHandle_t 
deepTypes::simpleTypeDataWriter_impl::register_instance_w_timestamp (
    const simpleType & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS_API DDS::ReturnCode_t
deepTypes::simpleTypeDataWriter_impl::unregister_instance (
    const deepTypes::simpleType & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS_API DDS::ReturnCode_t 
deepTypes::simpleTypeDataWriter_impl::unregister_instance_w_timestamp (
    const simpleType & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS_API DDS::ReturnCode_t
deepTypes::simpleTypeDataWriter_impl::write (
    const deepTypes::simpleType & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS_API DDS::ReturnCode_t
deepTypes::simpleTypeDataWriter_impl::write_w_timestamp (
    const simpleType & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS_API DDS::ReturnCode_t
deepTypes::simpleTypeDataWriter_impl::dispose (
    const deepTypes::simpleType & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS_API DDS::ReturnCode_t 
deepTypes::simpleTypeDataWriter_impl::dispose_w_timestamp (
    const simpleType & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS_API DDS::ReturnCode_t 
deepTypes::simpleTypeDataWriter_impl::get_key_value (
    simpleType & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS deepTypes::simpleType DataReader_impl Object Body

DDS_API deepTypes::simpleTypeDataReader_impl::simpleTypeDataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

DDS_API deepTypes::simpleTypeDataReader_impl::~simpleTypeDataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS_API DDS::ReturnCode_t
deepTypes::simpleTypeDataReader_impl::read (
    deepTypes::simpleTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::read( &received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

DDS_API DDS::ReturnCode_t
deepTypes::simpleTypeDataReader_impl::take (
    deepTypes::simpleTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::take( &received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

DDS_API DDS::ReturnCode_t
deepTypes::simpleTypeDataReader_impl::read_w_condition (
    deepTypes::simpleTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::read_w_condition( &received_data, info_seq, max_samples, a_condition);
    }
    return status;
}

DDS_API DDS::ReturnCode_t
deepTypes::simpleTypeDataReader_impl::take_w_condition (
    deepTypes::simpleTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::take_w_condition( &received_data, info_seq, max_samples, a_condition);
    }
    return status;
}


DDS_API DDS::ReturnCode_t 
deepTypes::simpleTypeDataReader_impl::read_next_sample (
    deepTypes::simpleType & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS_API DDS::ReturnCode_t 
deepTypes::simpleTypeDataReader_impl::take_next_sample (
    deepTypes::simpleType & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS_API DDS::ReturnCode_t
deepTypes::simpleTypeDataReader_impl::read_instance (
    deepTypes::simpleTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::read_instance( &received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

DDS_API DDS::ReturnCode_t
deepTypes::simpleTypeDataReader_impl::take_instance (
    deepTypes::simpleTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::take_instance( &received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

DDS_API DDS::ReturnCode_t
deepTypes::simpleTypeDataReader_impl::read_next_instance (
    deepTypes::simpleTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::read_next_instance( &received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

DDS_API DDS::ReturnCode_t
deepTypes::simpleTypeDataReader_impl::take_next_instance (
    deepTypes::simpleTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::take_next_instance( &received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}


DDS_API DDS::ReturnCode_t 
deepTypes::simpleTypeDataReader_impl::read_next_instance_w_condition (
    deepTypes::simpleTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::read_next_instance_w_condition( &received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


DDS_API DDS::ReturnCode_t 
deepTypes::simpleTypeDataReader_impl::take_next_instance_w_condition (
    deepTypes::simpleTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::take_next_instance_w_condition( &received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


DDS_API DDS::ReturnCode_t
deepTypes::simpleTypeDataReader_impl::return_loan (
    deepTypes::simpleTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status = DDS::RETCODE_OK;

    if ( received_data.length() > 0 && info_seq.length() > 0 && !received_data.release() && !info_seq.release() )
    {
        status = DataReader_impl::return_loan( received_data.get_buffer(), info_seq.get_buffer() );

        if ( status == DDS::RETCODE_OK )
        {
            if ( !received_data.release() )
            {
                deepTypes::simpleTypeSeq::freebuf( received_data.get_buffer(true) );
                received_data.replace(0, 0, NULL, false);
                DDS::SampleInfoSeq::freebuf( info_seq.get_buffer(true) );
                info_seq.replace(0, 0, NULL, false);
            }
        }
        else if ( status == DDS::RETCODE_NO_DATA )
        {
            if ( received_data.release() )
            {
                status = DDS::RETCODE_OK;
            } 
            else
            {
                status = DDS::RETCODE_PRECONDITION_NOT_MET;
            }
        }
    }
    return status;
}


DDS_API DDS::ReturnCode_t 
deepTypes::simpleTypeDataReader_impl::get_key_value (
    deepTypes::simpleType & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS_API DDS::InstanceHandle_t 
deepTypes::simpleTypeDataReader_impl::lookup_instance (
    const deepTypes::simpleType & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS_API DDS::ReturnCode_t 
deepTypes::simpleTypeDataReader_impl::check_preconditions(
    deepTypes::simpleTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples
)
{
    DDS::ReturnCode_t status = DDS::RETCODE_PRECONDITION_NOT_MET;
    
    if ( received_data.length() == info_seq.length() &&
         received_data.maximum() == info_seq.maximum() &&
         received_data.release() == info_seq.release() )
    {
        if ( received_data.maximum() == 0 || received_data.release() )
        {
            if ( received_data.maximum() == 0 ||
		 max_samples <= static_cast<CORBA::Long>(received_data.maximum()) ||
	         max_samples == DDS::LENGTH_UNLIMITED )
            {
                status = DDS::RETCODE_OK;
            }
        }
    }
    return status;
}
extern void
__deepTypes_nestedType__copyIn(
    c_base base,
    struct deepTypes::nestedType *from,
    struct _deepTypes_nestedType *to
);

extern void
__deepTypes_nestedType__copyOut(
    void *_from,
    void *_to
);

// DDS deepTypes::nestedType TypeSupportFactory Object Body

DDS_API DDS::DataWriter_ptr 
deepTypes::nestedTypeTypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new deepTypes::nestedTypeDataWriter_impl(handle, statusConditionData);
};

DDS_API DDS::DataReader_ptr 
deepTypes::nestedTypeTypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new deepTypes::nestedTypeDataReader_impl (handle, statusConditionData);
};

// DDS deepTypes::nestedType TypeSupport Object Body

DDS_API deepTypes::nestedTypeTypeSupport::nestedTypeTypeSupport (void) :
    TypeSupport_impl(
        __deepTypes_nestedType__name(),
        __deepTypes_nestedType__keys(),
        deepTypes::nestedTypeTypeSupport::metaDescriptor,
        (gapi_copyIn) __deepTypes_nestedType__copyIn,
        (gapi_copyOut) __deepTypes_nestedType__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<deepTypes::nestedTypeSeq, deepTypes::nestedType>,
        new  deepTypes::nestedTypeTypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

DDS_API deepTypes::nestedTypeTypeSupport::~nestedTypeTypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS_API DDS::ReturnCode_t
deepTypes::nestedTypeTypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

DDS_API char *
deepTypes::nestedTypeTypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS deepTypes::nestedType DataWriter_impl Object Body

DDS_API deepTypes::nestedTypeDataWriter_impl::nestedTypeDataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

DDS_API deepTypes::nestedTypeDataWriter_impl::~nestedTypeDataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS_API DDS::InstanceHandle_t
deepTypes::nestedTypeDataWriter_impl::register_instance (
    const deepTypes::nestedType & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS_API DDS::InstanceHandle_t 
deepTypes::nestedTypeDataWriter_impl::register_instance_w_timestamp (
    const nestedType & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS_API DDS::ReturnCode_t
deepTypes::nestedTypeDataWriter_impl::unregister_instance (
    const deepTypes::nestedType & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS_API DDS::ReturnCode_t 
deepTypes::nestedTypeDataWriter_impl::unregister_instance_w_timestamp (
    const nestedType & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS_API DDS::ReturnCode_t
deepTypes::nestedTypeDataWriter_impl::write (
    const deepTypes::nestedType & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS_API DDS::ReturnCode_t
deepTypes::nestedTypeDataWriter_impl::write_w_timestamp (
    const nestedType & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS_API DDS::ReturnCode_t
deepTypes::nestedTypeDataWriter_impl::dispose (
    const deepTypes::nestedType & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS_API DDS::ReturnCode_t 
deepTypes::nestedTypeDataWriter_impl::dispose_w_timestamp (
    const nestedType & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS_API DDS::ReturnCode_t 
deepTypes::nestedTypeDataWriter_impl::get_key_value (
    nestedType & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS deepTypes::nestedType DataReader_impl Object Body

DDS_API deepTypes::nestedTypeDataReader_impl::nestedTypeDataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

DDS_API deepTypes::nestedTypeDataReader_impl::~nestedTypeDataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS_API DDS::ReturnCode_t
deepTypes::nestedTypeDataReader_impl::read (
    deepTypes::nestedTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::read( &received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

DDS_API DDS::ReturnCode_t
deepTypes::nestedTypeDataReader_impl::take (
    deepTypes::nestedTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::take( &received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

DDS_API DDS::ReturnCode_t
deepTypes::nestedTypeDataReader_impl::read_w_condition (
    deepTypes::nestedTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::read_w_condition( &received_data, info_seq, max_samples, a_condition);
    }
    return status;
}

DDS_API DDS::ReturnCode_t
deepTypes::nestedTypeDataReader_impl::take_w_condition (
    deepTypes::nestedTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::take_w_condition( &received_data, info_seq, max_samples, a_condition);
    }
    return status;
}


DDS_API DDS::ReturnCode_t 
deepTypes::nestedTypeDataReader_impl::read_next_sample (
    deepTypes::nestedType & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS_API DDS::ReturnCode_t 
deepTypes::nestedTypeDataReader_impl::take_next_sample (
    deepTypes::nestedType & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS_API DDS::ReturnCode_t
deepTypes::nestedTypeDataReader_impl::read_instance (
    deepTypes::nestedTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::read_instance( &received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

DDS_API DDS::ReturnCode_t
deepTypes::nestedTypeDataReader_impl::take_instance (
    deepTypes::nestedTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::take_instance( &received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

DDS_API DDS::ReturnCode_t
deepTypes::nestedTypeDataReader_impl::read_next_instance (
    deepTypes::nestedTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::read_next_instance( &received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

DDS_API DDS::ReturnCode_t
deepTypes::nestedTypeDataReader_impl::take_next_instance (
    deepTypes::nestedTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::take_next_instance( &received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}


DDS_API DDS::ReturnCode_t 
deepTypes::nestedTypeDataReader_impl::read_next_instance_w_condition (
    deepTypes::nestedTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::read_next_instance_w_condition( &received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


DDS_API DDS::ReturnCode_t 
deepTypes::nestedTypeDataReader_impl::take_next_instance_w_condition (
    deepTypes::nestedTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::take_next_instance_w_condition( &received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


DDS_API DDS::ReturnCode_t
deepTypes::nestedTypeDataReader_impl::return_loan (
    deepTypes::nestedTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status = DDS::RETCODE_OK;

    if ( received_data.length() > 0 && info_seq.length() > 0 && !received_data.release() && !info_seq.release() )
    {
        status = DataReader_impl::return_loan( received_data.get_buffer(), info_seq.get_buffer() );

        if ( status == DDS::RETCODE_OK )
        {
            if ( !received_data.release() )
            {
                deepTypes::nestedTypeSeq::freebuf( received_data.get_buffer(true) );
                received_data.replace(0, 0, NULL, false);
                DDS::SampleInfoSeq::freebuf( info_seq.get_buffer(true) );
                info_seq.replace(0, 0, NULL, false);
            }
        }
        else if ( status == DDS::RETCODE_NO_DATA )
        {
            if ( received_data.release() )
            {
                status = DDS::RETCODE_OK;
            } 
            else
            {
                status = DDS::RETCODE_PRECONDITION_NOT_MET;
            }
        }
    }
    return status;
}


DDS_API DDS::ReturnCode_t 
deepTypes::nestedTypeDataReader_impl::get_key_value (
    deepTypes::nestedType & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS_API DDS::InstanceHandle_t 
deepTypes::nestedTypeDataReader_impl::lookup_instance (
    const deepTypes::nestedType & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS_API DDS::ReturnCode_t 
deepTypes::nestedTypeDataReader_impl::check_preconditions(
    deepTypes::nestedTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples
)
{
    DDS::ReturnCode_t status = DDS::RETCODE_PRECONDITION_NOT_MET;
    
    if ( received_data.length() == info_seq.length() &&
         received_data.maximum() == info_seq.maximum() &&
         received_data.release() == info_seq.release() )
    {
        if ( received_data.maximum() == 0 || received_data.release() )
        {
            if ( received_data.maximum() == 0 ||
		 max_samples <= static_cast<CORBA::Long>(received_data.maximum()) ||
	         max_samples == DDS::LENGTH_UNLIMITED )
            {
                status = DDS::RETCODE_OK;
            }
        }
    }
    return status;
}
extern void
__deepTypes_arrayType__copyIn(
    c_base base,
    struct deepTypes::arrayType *from,
    struct _deepTypes_arrayType *to
);

extern void
__deepTypes_arrayType__copyOut(
    void *_from,
    void *_to
);

// DDS deepTypes::arrayType TypeSupportFactory Object Body

DDS_API DDS::DataWriter_ptr 
deepTypes::arrayTypeTypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new deepTypes::arrayTypeDataWriter_impl(handle, statusConditionData);
};

DDS_API DDS::DataReader_ptr 
deepTypes::arrayTypeTypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new deepTypes::arrayTypeDataReader_impl (handle, statusConditionData);
};

// DDS deepTypes::arrayType TypeSupport Object Body

DDS_API deepTypes::arrayTypeTypeSupport::arrayTypeTypeSupport (void) :
    TypeSupport_impl(
        __deepTypes_arrayType__name(),
        __deepTypes_arrayType__keys(),
        deepTypes::arrayTypeTypeSupport::metaDescriptor,
        (gapi_copyIn) __deepTypes_arrayType__copyIn,
        (gapi_copyOut) __deepTypes_arrayType__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<deepTypes::arrayTypeSeq, deepTypes::arrayType>,
        new  deepTypes::arrayTypeTypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

DDS_API deepTypes::arrayTypeTypeSupport::~arrayTypeTypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS_API DDS::ReturnCode_t
deepTypes::arrayTypeTypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

DDS_API char *
deepTypes::arrayTypeTypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS deepTypes::arrayType DataWriter_impl Object Body

DDS_API deepTypes::arrayTypeDataWriter_impl::arrayTypeDataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

DDS_API deepTypes::arrayTypeDataWriter_impl::~arrayTypeDataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS_API DDS::InstanceHandle_t
deepTypes::arrayTypeDataWriter_impl::register_instance (
    const deepTypes::arrayType & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS_API DDS::InstanceHandle_t 
deepTypes::arrayTypeDataWriter_impl::register_instance_w_timestamp (
    const arrayType & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS_API DDS::ReturnCode_t
deepTypes::arrayTypeDataWriter_impl::unregister_instance (
    const deepTypes::arrayType & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS_API DDS::ReturnCode_t 
deepTypes::arrayTypeDataWriter_impl::unregister_instance_w_timestamp (
    const arrayType & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS_API DDS::ReturnCode_t
deepTypes::arrayTypeDataWriter_impl::write (
    const deepTypes::arrayType & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS_API DDS::ReturnCode_t
deepTypes::arrayTypeDataWriter_impl::write_w_timestamp (
    const arrayType & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS_API DDS::ReturnCode_t
deepTypes::arrayTypeDataWriter_impl::dispose (
    const deepTypes::arrayType & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS_API DDS::ReturnCode_t 
deepTypes::arrayTypeDataWriter_impl::dispose_w_timestamp (
    const arrayType & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS_API DDS::ReturnCode_t 
deepTypes::arrayTypeDataWriter_impl::get_key_value (
    arrayType & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS deepTypes::arrayType DataReader_impl Object Body

DDS_API deepTypes::arrayTypeDataReader_impl::arrayTypeDataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

DDS_API deepTypes::arrayTypeDataReader_impl::~arrayTypeDataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS_API DDS::ReturnCode_t
deepTypes::arrayTypeDataReader_impl::read (
    deepTypes::arrayTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::read( &received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

DDS_API DDS::ReturnCode_t
deepTypes::arrayTypeDataReader_impl::take (
    deepTypes::arrayTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::take( &received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

DDS_API DDS::ReturnCode_t
deepTypes::arrayTypeDataReader_impl::read_w_condition (
    deepTypes::arrayTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::read_w_condition( &received_data, info_seq, max_samples, a_condition);
    }
    return status;
}

DDS_API DDS::ReturnCode_t
deepTypes::arrayTypeDataReader_impl::take_w_condition (
    deepTypes::arrayTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::take_w_condition( &received_data, info_seq, max_samples, a_condition);
    }
    return status;
}


DDS_API DDS::ReturnCode_t 
deepTypes::arrayTypeDataReader_impl::read_next_sample (
    deepTypes::arrayType & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS_API DDS::ReturnCode_t 
deepTypes::arrayTypeDataReader_impl::take_next_sample (
    deepTypes::arrayType & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS_API DDS::ReturnCode_t
deepTypes::arrayTypeDataReader_impl::read_instance (
    deepTypes::arrayTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::read_instance( &received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

DDS_API DDS::ReturnCode_t
deepTypes::arrayTypeDataReader_impl::take_instance (
    deepTypes::arrayTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::take_instance( &received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

DDS_API DDS::ReturnCode_t
deepTypes::arrayTypeDataReader_impl::read_next_instance (
    deepTypes::arrayTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::read_next_instance( &received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

DDS_API DDS::ReturnCode_t
deepTypes::arrayTypeDataReader_impl::take_next_instance (
    deepTypes::arrayTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::take_next_instance( &received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}


DDS_API DDS::ReturnCode_t 
deepTypes::arrayTypeDataReader_impl::read_next_instance_w_condition (
    deepTypes::arrayTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::read_next_instance_w_condition( &received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


DDS_API DDS::ReturnCode_t 
deepTypes::arrayTypeDataReader_impl::take_next_instance_w_condition (
    deepTypes::arrayTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::take_next_instance_w_condition( &received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


DDS_API DDS::ReturnCode_t
deepTypes::arrayTypeDataReader_impl::return_loan (
    deepTypes::arrayTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status = DDS::RETCODE_OK;

    if ( received_data.length() > 0 && info_seq.length() > 0 && !received_data.release() && !info_seq.release() )
    {
        status = DataReader_impl::return_loan( received_data.get_buffer(), info_seq.get_buffer() );

        if ( status == DDS::RETCODE_OK )
        {
            if ( !received_data.release() )
            {
                deepTypes::arrayTypeSeq::freebuf( received_data.get_buffer(true) );
                received_data.replace(0, 0, NULL, false);
                DDS::SampleInfoSeq::freebuf( info_seq.get_buffer(true) );
                info_seq.replace(0, 0, NULL, false);
            }
        }
        else if ( status == DDS::RETCODE_NO_DATA )
        {
            if ( received_data.release() )
            {
                status = DDS::RETCODE_OK;
            } 
            else
            {
                status = DDS::RETCODE_PRECONDITION_NOT_MET;
            }
        }
    }
    return status;
}


DDS_API DDS::ReturnCode_t 
deepTypes::arrayTypeDataReader_impl::get_key_value (
    deepTypes::arrayType & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS_API DDS::InstanceHandle_t 
deepTypes::arrayTypeDataReader_impl::lookup_instance (
    const deepTypes::arrayType & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS_API DDS::ReturnCode_t 
deepTypes::arrayTypeDataReader_impl::check_preconditions(
    deepTypes::arrayTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples
)
{
    DDS::ReturnCode_t status = DDS::RETCODE_PRECONDITION_NOT_MET;
    
    if ( received_data.length() == info_seq.length() &&
         received_data.maximum() == info_seq.maximum() &&
         received_data.release() == info_seq.release() )
    {
        if ( received_data.maximum() == 0 || received_data.release() )
        {
            if ( received_data.maximum() == 0 ||
		 max_samples <= static_cast<CORBA::Long>(received_data.maximum()) ||
	         max_samples == DDS::LENGTH_UNLIMITED )
            {
                status = DDS::RETCODE_OK;
            }
        }
    }
    return status;
}
extern void
__deepTypes_stringType__copyIn(
    c_base base,
    struct deepTypes::stringType *from,
    struct _deepTypes_stringType *to
);

extern void
__deepTypes_stringType__copyOut(
    void *_from,
    void *_to
);

// DDS deepTypes::stringType TypeSupportFactory Object Body

DDS_API DDS::DataWriter_ptr 
deepTypes::stringTypeTypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new deepTypes::stringTypeDataWriter_impl(handle, statusConditionData);
};

DDS_API DDS::DataReader_ptr 
deepTypes::stringTypeTypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new deepTypes::stringTypeDataReader_impl (handle, statusConditionData);
};

// DDS deepTypes::stringType TypeSupport Object Body

DDS_API deepTypes::stringTypeTypeSupport::stringTypeTypeSupport (void) :
    TypeSupport_impl(
        __deepTypes_stringType__name(),
        __deepTypes_stringType__keys(),
        deepTypes::stringTypeTypeSupport::metaDescriptor,
        (gapi_copyIn) __deepTypes_stringType__copyIn,
        (gapi_copyOut) __deepTypes_stringType__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<deepTypes::stringTypeSeq, deepTypes::stringType>,
        new  deepTypes::stringTypeTypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

DDS_API deepTypes::stringTypeTypeSupport::~stringTypeTypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS_API DDS::ReturnCode_t
deepTypes::stringTypeTypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

DDS_API char *
deepTypes::stringTypeTypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS deepTypes::stringType DataWriter_impl Object Body

DDS_API deepTypes::stringTypeDataWriter_impl::stringTypeDataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

DDS_API deepTypes::stringTypeDataWriter_impl::~stringTypeDataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS_API DDS::InstanceHandle_t
deepTypes::stringTypeDataWriter_impl::register_instance (
    const deepTypes::stringType & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS_API DDS::InstanceHandle_t 
deepTypes::stringTypeDataWriter_impl::register_instance_w_timestamp (
    const stringType & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS_API DDS::ReturnCode_t
deepTypes::stringTypeDataWriter_impl::unregister_instance (
    const deepTypes::stringType & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS_API DDS::ReturnCode_t 
deepTypes::stringTypeDataWriter_impl::unregister_instance_w_timestamp (
    const stringType & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS_API DDS::ReturnCode_t
deepTypes::stringTypeDataWriter_impl::write (
    const deepTypes::stringType & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS_API DDS::ReturnCode_t
deepTypes::stringTypeDataWriter_impl::write_w_timestamp (
    const stringType & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS_API DDS::ReturnCode_t
deepTypes::stringTypeDataWriter_impl::dispose (
    const deepTypes::stringType & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS_API DDS::ReturnCode_t 
deepTypes::stringTypeDataWriter_impl::dispose_w_timestamp (
    const stringType & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS_API DDS::ReturnCode_t 
deepTypes::stringTypeDataWriter_impl::get_key_value (
    stringType & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS deepTypes::stringType DataReader_impl Object Body

DDS_API deepTypes::stringTypeDataReader_impl::stringTypeDataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

DDS_API deepTypes::stringTypeDataReader_impl::~stringTypeDataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS_API DDS::ReturnCode_t
deepTypes::stringTypeDataReader_impl::read (
    deepTypes::stringTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::read( &received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

DDS_API DDS::ReturnCode_t
deepTypes::stringTypeDataReader_impl::take (
    deepTypes::stringTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::take( &received_data, info_seq, max_samples, sample_states, view_states, instance_states);
    }
    return status;
}

DDS_API DDS::ReturnCode_t
deepTypes::stringTypeDataReader_impl::read_w_condition (
    deepTypes::stringTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::read_w_condition( &received_data, info_seq, max_samples, a_condition);
    }
    return status;
}

DDS_API DDS::ReturnCode_t
deepTypes::stringTypeDataReader_impl::take_w_condition (
    deepTypes::stringTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::ReadCondition_ptr a_condition
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::take_w_condition( &received_data, info_seq, max_samples, a_condition);
    }
    return status;
}


DDS_API DDS::ReturnCode_t 
deepTypes::stringTypeDataReader_impl::read_next_sample (
    deepTypes::stringType & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS_API DDS::ReturnCode_t 
deepTypes::stringTypeDataReader_impl::take_next_sample (
    deepTypes::stringType & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS_API DDS::ReturnCode_t
deepTypes::stringTypeDataReader_impl::read_instance (
    deepTypes::stringTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::read_instance( &received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

DDS_API DDS::ReturnCode_t
deepTypes::stringTypeDataReader_impl::take_instance (
    deepTypes::stringTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::take_instance( &received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

DDS_API DDS::ReturnCode_t
deepTypes::stringTypeDataReader_impl::read_next_instance (
    deepTypes::stringTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::read_next_instance( &received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}

DDS_API DDS::ReturnCode_t
deepTypes::stringTypeDataReader_impl::take_next_instance (
    deepTypes::stringTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::SampleStateMask sample_states,
    DDS::ViewStateMask view_states,
    DDS::InstanceStateMask instance_states
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::take_next_instance( &received_data, info_seq, max_samples, a_handle, sample_states, view_states, instance_states);
    }
    return status;
}


DDS_API DDS::ReturnCode_t 
deepTypes::stringTypeDataReader_impl::read_next_instance_w_condition (
    deepTypes::stringTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::read_next_instance_w_condition( &received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


DDS_API DDS::ReturnCode_t 
deepTypes::stringTypeDataReader_impl::take_next_instance_w_condition (
    deepTypes::stringTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples,
    DDS::InstanceHandle_t a_handle,
    DDS::ReadCondition_ptr a_condition
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status;
    
    status = check_preconditions(received_data, info_seq, max_samples);
    if ( status == DDS::RETCODE_OK )
    {
        status = DataReader_impl::take_next_instance_w_condition( &received_data, info_seq, max_samples, a_handle, a_condition);
    }
    return status;
}


DDS_API DDS::ReturnCode_t
deepTypes::stringTypeDataReader_impl::return_loan (
    deepTypes::stringTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq
) THROW_ORB_EXCEPTIONS
{
    DDS::ReturnCode_t status = DDS::RETCODE_OK;

    if ( received_data.length() > 0 && info_seq.length() > 0 && !received_data.release() && !info_seq.release() )
    {
        status = DataReader_impl::return_loan( received_data.get_buffer(), info_seq.get_buffer() );

        if ( status == DDS::RETCODE_OK )
        {
            if ( !received_data.release() )
            {
                deepTypes::stringTypeSeq::freebuf( received_data.get_buffer(true) );
                received_data.replace(0, 0, NULL, false);
                DDS::SampleInfoSeq::freebuf( info_seq.get_buffer(true) );
                info_seq.replace(0, 0, NULL, false);
            }
        }
        else if ( status == DDS::RETCODE_NO_DATA )
        {
            if ( received_data.release() )
            {
                status = DDS::RETCODE_OK;
            } 
            else
            {
                status = DDS::RETCODE_PRECONDITION_NOT_MET;
            }
        }
    }
    return status;
}


DDS_API DDS::ReturnCode_t 
deepTypes::stringTypeDataReader_impl::get_key_value (
    deepTypes::stringType & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS_API DDS::InstanceHandle_t 
deepTypes::stringTypeDataReader_impl::lookup_instance (
    const deepTypes::stringType & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS_API DDS::ReturnCode_t 
deepTypes::stringTypeDataReader_impl::check_preconditions(
    deepTypes::stringTypeSeq & received_data,
    DDS::SampleInfoSeq & info_seq,
    CORBA::Long max_samples
)
{
    DDS::ReturnCode_t status = DDS::RETCODE_PRECONDITION_NOT_MET;
    
    if ( received_data.length() == info_seq.length() &&
         received_data.maximum() == info_seq.maximum() &&
         received_data.release() == info_seq.release() )
    {
        if ( received_data.maximum() == 0 || received_data.release() )
        {
            if ( received_data.maximum() == 0 ||
		 max_samples <= static_cast<CORBA::Long>(received_data.maximum()) ||
	         max_samples == DDS::LENGTH_UNLIMITED )
            {
                status = DDS::RETCODE_OK;
            }
        }
    }
    return status;
}
const char * deepTypes::simpleTypeTypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"deepTypes\"><Struct name=\"simpleType\"><Member name=\"id\"><Long/></Member><Member name=\"payload\"><Long/></Member></Struct></Module></MetaData>";
const char * deepTypes::nestedTypeTypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"deepTypes\"><Struct name=\"innerStruct\"><Member name=\"value\"><Long/></Member></Struct><Struct name=\"nestedType\"><Member name=\"id\"><Long/></Member><Member name=\"payload\"><Type name=\"deepTypes::innerStruct\"/></Member></Struct></Module></MetaData>";
const char * deepTypes::arrayTypeTypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"deepTypes\"><Struct name=\"arrayType\"><Member name=\"id\"><Long/></Member><Member name=\"payload\"><Array size=\"10\"><Long/></Array></Member></Struct></Module></MetaData>";
const char * deepTypes::stringTypeTypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"deepTypes\"><Struct name=\"stringType\"><Member name=\"id\"><Long/></Member><Member name=\"payload\"><String/></Member></Struct></Module></MetaData>";
