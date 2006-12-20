#include "TPTDefSplDcps.h"
#include "TPTDefDcps_impl.h"
#include "ccpp_DataReader_impl.h"
#include "gapi.h"




extern void
__TP_Test_QuitMsg__copyIn(
    c_base base,
    struct TP_Test::QuitMsg *from,
    struct _TP_Test_QuitMsg *to
);

extern void
__TP_Test_QuitMsg__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::QuitMsg TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::QuitMsgTypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::QuitMsgDataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::QuitMsgTypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::QuitMsgDataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::QuitMsg TypeSupport Object Body

TP_Test::QuitMsgTypeSupport::QuitMsgTypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_QuitMsg__name(),
        __TP_Test_QuitMsg__keys(),
        TP_Test::QuitMsgTypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_QuitMsg__copyIn,
        (gapi_copyOut) __TP_Test_QuitMsg__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::QuitMsgSeq, TP_Test::QuitMsg>,
        new  TP_Test::QuitMsgTypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::QuitMsgTypeSupport::~QuitMsgTypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::QuitMsgTypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::QuitMsgTypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::QuitMsg DataWriter_impl Object Body

TP_Test::QuitMsgDataWriter_impl::QuitMsgDataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::QuitMsgDataWriter_impl::~QuitMsgDataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::QuitMsgDataWriter_impl::register_instance (
    const TP_Test::QuitMsg & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::QuitMsgDataWriter_impl::register_instance_w_timestamp (
    const QuitMsg & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::QuitMsgDataWriter_impl::unregister_instance (
    const TP_Test::QuitMsg & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::QuitMsgDataWriter_impl::unregister_instance_w_timestamp (
    const QuitMsg & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::QuitMsgDataWriter_impl::write (
    const TP_Test::QuitMsg & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::QuitMsgDataWriter_impl::write_w_timestamp (
    const QuitMsg & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::QuitMsgDataWriter_impl::dispose (
    const TP_Test::QuitMsg & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::QuitMsgDataWriter_impl::dispose_w_timestamp (
    const QuitMsg & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::QuitMsgDataWriter_impl::get_key_value (
    QuitMsg & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::QuitMsg DataReader_impl Object Body

TP_Test::QuitMsgDataReader_impl::QuitMsgDataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::QuitMsgDataReader_impl::~QuitMsgDataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::QuitMsgDataReader_impl::read (
    TP_Test::QuitMsgSeq & received_data,
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

DDS::ReturnCode_t
TP_Test::QuitMsgDataReader_impl::take (
    TP_Test::QuitMsgSeq & received_data,
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

DDS::ReturnCode_t
TP_Test::QuitMsgDataReader_impl::read_w_condition (
    TP_Test::QuitMsgSeq & received_data,
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

DDS::ReturnCode_t
TP_Test::QuitMsgDataReader_impl::take_w_condition (
    TP_Test::QuitMsgSeq & received_data,
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


DDS::ReturnCode_t 
TP_Test::QuitMsgDataReader_impl::read_next_sample (
    TP_Test::QuitMsg & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::QuitMsgDataReader_impl::take_next_sample (
    TP_Test::QuitMsg & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::QuitMsgDataReader_impl::read_instance (
    TP_Test::QuitMsgSeq & received_data,
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

DDS::ReturnCode_t
TP_Test::QuitMsgDataReader_impl::take_instance (
    TP_Test::QuitMsgSeq & received_data,
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

DDS::ReturnCode_t
TP_Test::QuitMsgDataReader_impl::read_next_instance (
    TP_Test::QuitMsgSeq & received_data,
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

DDS::ReturnCode_t
TP_Test::QuitMsgDataReader_impl::take_next_instance (
    TP_Test::QuitMsgSeq & received_data,
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


DDS::ReturnCode_t 
TP_Test::QuitMsgDataReader_impl::read_next_instance_w_condition (
    TP_Test::QuitMsgSeq & received_data,
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


DDS::ReturnCode_t 
TP_Test::QuitMsgDataReader_impl::take_next_instance_w_condition (
    TP_Test::QuitMsgSeq & received_data,
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


DDS::ReturnCode_t
TP_Test::QuitMsgDataReader_impl::return_loan (
    TP_Test::QuitMsgSeq & received_data,
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
                TP_Test::QuitMsgSeq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::QuitMsgDataReader_impl::get_key_value (
    TP_Test::QuitMsg & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::QuitMsgDataReader_impl::lookup_instance (
    const TP_Test::QuitMsg & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::QuitMsgDataReader_impl::check_preconditions(
    TP_Test::QuitMsgSeq & received_data,
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
__TP_Test_Bytes4__copyIn(
    c_base base,
    struct TP_Test::Bytes4 *from,
    struct _TP_Test_Bytes4 *to
);

extern void
__TP_Test_Bytes4__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Bytes4 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Bytes4TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes4DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Bytes4TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes4DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Bytes4 TypeSupport Object Body

TP_Test::Bytes4TypeSupport::Bytes4TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Bytes4__name(),
        __TP_Test_Bytes4__keys(),
        TP_Test::Bytes4TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Bytes4__copyIn,
        (gapi_copyOut) __TP_Test_Bytes4__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Bytes4Seq, TP_Test::Bytes4>,
        new  TP_Test::Bytes4TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Bytes4TypeSupport::~Bytes4TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Bytes4TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Bytes4TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Bytes4 DataWriter_impl Object Body

TP_Test::Bytes4DataWriter_impl::Bytes4DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes4DataWriter_impl::~Bytes4DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Bytes4DataWriter_impl::register_instance (
    const TP_Test::Bytes4 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Bytes4DataWriter_impl::register_instance_w_timestamp (
    const Bytes4 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Bytes4DataWriter_impl::unregister_instance (
    const TP_Test::Bytes4 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Bytes4DataWriter_impl::unregister_instance_w_timestamp (
    const Bytes4 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes4DataWriter_impl::write (
    const TP_Test::Bytes4 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Bytes4DataWriter_impl::write_w_timestamp (
    const Bytes4 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes4DataWriter_impl::dispose (
    const TP_Test::Bytes4 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Bytes4DataWriter_impl::dispose_w_timestamp (
    const Bytes4 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Bytes4DataWriter_impl::get_key_value (
    Bytes4 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Bytes4 DataReader_impl Object Body

TP_Test::Bytes4DataReader_impl::Bytes4DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes4DataReader_impl::~Bytes4DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Bytes4DataReader_impl::read (
    TP_Test::Bytes4Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes4DataReader_impl::take (
    TP_Test::Bytes4Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes4DataReader_impl::read_w_condition (
    TP_Test::Bytes4Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes4DataReader_impl::take_w_condition (
    TP_Test::Bytes4Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes4DataReader_impl::read_next_sample (
    TP_Test::Bytes4 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Bytes4DataReader_impl::take_next_sample (
    TP_Test::Bytes4 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Bytes4DataReader_impl::read_instance (
    TP_Test::Bytes4Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes4DataReader_impl::take_instance (
    TP_Test::Bytes4Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes4DataReader_impl::read_next_instance (
    TP_Test::Bytes4Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes4DataReader_impl::take_next_instance (
    TP_Test::Bytes4Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes4DataReader_impl::read_next_instance_w_condition (
    TP_Test::Bytes4Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes4DataReader_impl::take_next_instance_w_condition (
    TP_Test::Bytes4Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Bytes4DataReader_impl::return_loan (
    TP_Test::Bytes4Seq & received_data,
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
                TP_Test::Bytes4Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Bytes4DataReader_impl::get_key_value (
    TP_Test::Bytes4 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Bytes4DataReader_impl::lookup_instance (
    const TP_Test::Bytes4 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Bytes4DataReader_impl::check_preconditions(
    TP_Test::Bytes4Seq & received_data,
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
__TP_Test_Bytes8__copyIn(
    c_base base,
    struct TP_Test::Bytes8 *from,
    struct _TP_Test_Bytes8 *to
);

extern void
__TP_Test_Bytes8__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Bytes8 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Bytes8TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes8DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Bytes8TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes8DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Bytes8 TypeSupport Object Body

TP_Test::Bytes8TypeSupport::Bytes8TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Bytes8__name(),
        __TP_Test_Bytes8__keys(),
        TP_Test::Bytes8TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Bytes8__copyIn,
        (gapi_copyOut) __TP_Test_Bytes8__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Bytes8Seq, TP_Test::Bytes8>,
        new  TP_Test::Bytes8TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Bytes8TypeSupport::~Bytes8TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Bytes8TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Bytes8TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Bytes8 DataWriter_impl Object Body

TP_Test::Bytes8DataWriter_impl::Bytes8DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes8DataWriter_impl::~Bytes8DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Bytes8DataWriter_impl::register_instance (
    const TP_Test::Bytes8 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Bytes8DataWriter_impl::register_instance_w_timestamp (
    const Bytes8 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Bytes8DataWriter_impl::unregister_instance (
    const TP_Test::Bytes8 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Bytes8DataWriter_impl::unregister_instance_w_timestamp (
    const Bytes8 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes8DataWriter_impl::write (
    const TP_Test::Bytes8 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Bytes8DataWriter_impl::write_w_timestamp (
    const Bytes8 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes8DataWriter_impl::dispose (
    const TP_Test::Bytes8 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Bytes8DataWriter_impl::dispose_w_timestamp (
    const Bytes8 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Bytes8DataWriter_impl::get_key_value (
    Bytes8 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Bytes8 DataReader_impl Object Body

TP_Test::Bytes8DataReader_impl::Bytes8DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes8DataReader_impl::~Bytes8DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Bytes8DataReader_impl::read (
    TP_Test::Bytes8Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes8DataReader_impl::take (
    TP_Test::Bytes8Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes8DataReader_impl::read_w_condition (
    TP_Test::Bytes8Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes8DataReader_impl::take_w_condition (
    TP_Test::Bytes8Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes8DataReader_impl::read_next_sample (
    TP_Test::Bytes8 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Bytes8DataReader_impl::take_next_sample (
    TP_Test::Bytes8 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Bytes8DataReader_impl::read_instance (
    TP_Test::Bytes8Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes8DataReader_impl::take_instance (
    TP_Test::Bytes8Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes8DataReader_impl::read_next_instance (
    TP_Test::Bytes8Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes8DataReader_impl::take_next_instance (
    TP_Test::Bytes8Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes8DataReader_impl::read_next_instance_w_condition (
    TP_Test::Bytes8Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes8DataReader_impl::take_next_instance_w_condition (
    TP_Test::Bytes8Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Bytes8DataReader_impl::return_loan (
    TP_Test::Bytes8Seq & received_data,
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
                TP_Test::Bytes8Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Bytes8DataReader_impl::get_key_value (
    TP_Test::Bytes8 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Bytes8DataReader_impl::lookup_instance (
    const TP_Test::Bytes8 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Bytes8DataReader_impl::check_preconditions(
    TP_Test::Bytes8Seq & received_data,
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
__TP_Test_Bytes16__copyIn(
    c_base base,
    struct TP_Test::Bytes16 *from,
    struct _TP_Test_Bytes16 *to
);

extern void
__TP_Test_Bytes16__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Bytes16 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Bytes16TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes16DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Bytes16TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes16DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Bytes16 TypeSupport Object Body

TP_Test::Bytes16TypeSupport::Bytes16TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Bytes16__name(),
        __TP_Test_Bytes16__keys(),
        TP_Test::Bytes16TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Bytes16__copyIn,
        (gapi_copyOut) __TP_Test_Bytes16__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Bytes16Seq, TP_Test::Bytes16>,
        new  TP_Test::Bytes16TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Bytes16TypeSupport::~Bytes16TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Bytes16TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Bytes16TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Bytes16 DataWriter_impl Object Body

TP_Test::Bytes16DataWriter_impl::Bytes16DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes16DataWriter_impl::~Bytes16DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Bytes16DataWriter_impl::register_instance (
    const TP_Test::Bytes16 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Bytes16DataWriter_impl::register_instance_w_timestamp (
    const Bytes16 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Bytes16DataWriter_impl::unregister_instance (
    const TP_Test::Bytes16 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Bytes16DataWriter_impl::unregister_instance_w_timestamp (
    const Bytes16 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes16DataWriter_impl::write (
    const TP_Test::Bytes16 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Bytes16DataWriter_impl::write_w_timestamp (
    const Bytes16 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes16DataWriter_impl::dispose (
    const TP_Test::Bytes16 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Bytes16DataWriter_impl::dispose_w_timestamp (
    const Bytes16 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Bytes16DataWriter_impl::get_key_value (
    Bytes16 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Bytes16 DataReader_impl Object Body

TP_Test::Bytes16DataReader_impl::Bytes16DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes16DataReader_impl::~Bytes16DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Bytes16DataReader_impl::read (
    TP_Test::Bytes16Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes16DataReader_impl::take (
    TP_Test::Bytes16Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes16DataReader_impl::read_w_condition (
    TP_Test::Bytes16Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes16DataReader_impl::take_w_condition (
    TP_Test::Bytes16Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes16DataReader_impl::read_next_sample (
    TP_Test::Bytes16 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Bytes16DataReader_impl::take_next_sample (
    TP_Test::Bytes16 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Bytes16DataReader_impl::read_instance (
    TP_Test::Bytes16Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes16DataReader_impl::take_instance (
    TP_Test::Bytes16Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes16DataReader_impl::read_next_instance (
    TP_Test::Bytes16Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes16DataReader_impl::take_next_instance (
    TP_Test::Bytes16Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes16DataReader_impl::read_next_instance_w_condition (
    TP_Test::Bytes16Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes16DataReader_impl::take_next_instance_w_condition (
    TP_Test::Bytes16Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Bytes16DataReader_impl::return_loan (
    TP_Test::Bytes16Seq & received_data,
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
                TP_Test::Bytes16Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Bytes16DataReader_impl::get_key_value (
    TP_Test::Bytes16 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Bytes16DataReader_impl::lookup_instance (
    const TP_Test::Bytes16 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Bytes16DataReader_impl::check_preconditions(
    TP_Test::Bytes16Seq & received_data,
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
__TP_Test_Bytes32__copyIn(
    c_base base,
    struct TP_Test::Bytes32 *from,
    struct _TP_Test_Bytes32 *to
);

extern void
__TP_Test_Bytes32__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Bytes32 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Bytes32TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes32DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Bytes32TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes32DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Bytes32 TypeSupport Object Body

TP_Test::Bytes32TypeSupport::Bytes32TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Bytes32__name(),
        __TP_Test_Bytes32__keys(),
        TP_Test::Bytes32TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Bytes32__copyIn,
        (gapi_copyOut) __TP_Test_Bytes32__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Bytes32Seq, TP_Test::Bytes32>,
        new  TP_Test::Bytes32TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Bytes32TypeSupport::~Bytes32TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Bytes32TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Bytes32TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Bytes32 DataWriter_impl Object Body

TP_Test::Bytes32DataWriter_impl::Bytes32DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes32DataWriter_impl::~Bytes32DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Bytes32DataWriter_impl::register_instance (
    const TP_Test::Bytes32 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Bytes32DataWriter_impl::register_instance_w_timestamp (
    const Bytes32 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Bytes32DataWriter_impl::unregister_instance (
    const TP_Test::Bytes32 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Bytes32DataWriter_impl::unregister_instance_w_timestamp (
    const Bytes32 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes32DataWriter_impl::write (
    const TP_Test::Bytes32 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Bytes32DataWriter_impl::write_w_timestamp (
    const Bytes32 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes32DataWriter_impl::dispose (
    const TP_Test::Bytes32 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Bytes32DataWriter_impl::dispose_w_timestamp (
    const Bytes32 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Bytes32DataWriter_impl::get_key_value (
    Bytes32 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Bytes32 DataReader_impl Object Body

TP_Test::Bytes32DataReader_impl::Bytes32DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes32DataReader_impl::~Bytes32DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Bytes32DataReader_impl::read (
    TP_Test::Bytes32Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes32DataReader_impl::take (
    TP_Test::Bytes32Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes32DataReader_impl::read_w_condition (
    TP_Test::Bytes32Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes32DataReader_impl::take_w_condition (
    TP_Test::Bytes32Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes32DataReader_impl::read_next_sample (
    TP_Test::Bytes32 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Bytes32DataReader_impl::take_next_sample (
    TP_Test::Bytes32 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Bytes32DataReader_impl::read_instance (
    TP_Test::Bytes32Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes32DataReader_impl::take_instance (
    TP_Test::Bytes32Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes32DataReader_impl::read_next_instance (
    TP_Test::Bytes32Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes32DataReader_impl::take_next_instance (
    TP_Test::Bytes32Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes32DataReader_impl::read_next_instance_w_condition (
    TP_Test::Bytes32Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes32DataReader_impl::take_next_instance_w_condition (
    TP_Test::Bytes32Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Bytes32DataReader_impl::return_loan (
    TP_Test::Bytes32Seq & received_data,
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
                TP_Test::Bytes32Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Bytes32DataReader_impl::get_key_value (
    TP_Test::Bytes32 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Bytes32DataReader_impl::lookup_instance (
    const TP_Test::Bytes32 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Bytes32DataReader_impl::check_preconditions(
    TP_Test::Bytes32Seq & received_data,
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
__TP_Test_Bytes64__copyIn(
    c_base base,
    struct TP_Test::Bytes64 *from,
    struct _TP_Test_Bytes64 *to
);

extern void
__TP_Test_Bytes64__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Bytes64 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Bytes64TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes64DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Bytes64TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes64DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Bytes64 TypeSupport Object Body

TP_Test::Bytes64TypeSupport::Bytes64TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Bytes64__name(),
        __TP_Test_Bytes64__keys(),
        TP_Test::Bytes64TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Bytes64__copyIn,
        (gapi_copyOut) __TP_Test_Bytes64__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Bytes64Seq, TP_Test::Bytes64>,
        new  TP_Test::Bytes64TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Bytes64TypeSupport::~Bytes64TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Bytes64TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Bytes64TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Bytes64 DataWriter_impl Object Body

TP_Test::Bytes64DataWriter_impl::Bytes64DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes64DataWriter_impl::~Bytes64DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Bytes64DataWriter_impl::register_instance (
    const TP_Test::Bytes64 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Bytes64DataWriter_impl::register_instance_w_timestamp (
    const Bytes64 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Bytes64DataWriter_impl::unregister_instance (
    const TP_Test::Bytes64 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Bytes64DataWriter_impl::unregister_instance_w_timestamp (
    const Bytes64 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes64DataWriter_impl::write (
    const TP_Test::Bytes64 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Bytes64DataWriter_impl::write_w_timestamp (
    const Bytes64 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes64DataWriter_impl::dispose (
    const TP_Test::Bytes64 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Bytes64DataWriter_impl::dispose_w_timestamp (
    const Bytes64 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Bytes64DataWriter_impl::get_key_value (
    Bytes64 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Bytes64 DataReader_impl Object Body

TP_Test::Bytes64DataReader_impl::Bytes64DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes64DataReader_impl::~Bytes64DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Bytes64DataReader_impl::read (
    TP_Test::Bytes64Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes64DataReader_impl::take (
    TP_Test::Bytes64Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes64DataReader_impl::read_w_condition (
    TP_Test::Bytes64Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes64DataReader_impl::take_w_condition (
    TP_Test::Bytes64Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes64DataReader_impl::read_next_sample (
    TP_Test::Bytes64 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Bytes64DataReader_impl::take_next_sample (
    TP_Test::Bytes64 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Bytes64DataReader_impl::read_instance (
    TP_Test::Bytes64Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes64DataReader_impl::take_instance (
    TP_Test::Bytes64Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes64DataReader_impl::read_next_instance (
    TP_Test::Bytes64Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes64DataReader_impl::take_next_instance (
    TP_Test::Bytes64Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes64DataReader_impl::read_next_instance_w_condition (
    TP_Test::Bytes64Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes64DataReader_impl::take_next_instance_w_condition (
    TP_Test::Bytes64Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Bytes64DataReader_impl::return_loan (
    TP_Test::Bytes64Seq & received_data,
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
                TP_Test::Bytes64Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Bytes64DataReader_impl::get_key_value (
    TP_Test::Bytes64 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Bytes64DataReader_impl::lookup_instance (
    const TP_Test::Bytes64 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Bytes64DataReader_impl::check_preconditions(
    TP_Test::Bytes64Seq & received_data,
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
__TP_Test_Bytes128__copyIn(
    c_base base,
    struct TP_Test::Bytes128 *from,
    struct _TP_Test_Bytes128 *to
);

extern void
__TP_Test_Bytes128__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Bytes128 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Bytes128TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes128DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Bytes128TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes128DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Bytes128 TypeSupport Object Body

TP_Test::Bytes128TypeSupport::Bytes128TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Bytes128__name(),
        __TP_Test_Bytes128__keys(),
        TP_Test::Bytes128TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Bytes128__copyIn,
        (gapi_copyOut) __TP_Test_Bytes128__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Bytes128Seq, TP_Test::Bytes128>,
        new  TP_Test::Bytes128TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Bytes128TypeSupport::~Bytes128TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Bytes128TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Bytes128TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Bytes128 DataWriter_impl Object Body

TP_Test::Bytes128DataWriter_impl::Bytes128DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes128DataWriter_impl::~Bytes128DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Bytes128DataWriter_impl::register_instance (
    const TP_Test::Bytes128 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Bytes128DataWriter_impl::register_instance_w_timestamp (
    const Bytes128 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Bytes128DataWriter_impl::unregister_instance (
    const TP_Test::Bytes128 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Bytes128DataWriter_impl::unregister_instance_w_timestamp (
    const Bytes128 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes128DataWriter_impl::write (
    const TP_Test::Bytes128 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Bytes128DataWriter_impl::write_w_timestamp (
    const Bytes128 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes128DataWriter_impl::dispose (
    const TP_Test::Bytes128 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Bytes128DataWriter_impl::dispose_w_timestamp (
    const Bytes128 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Bytes128DataWriter_impl::get_key_value (
    Bytes128 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Bytes128 DataReader_impl Object Body

TP_Test::Bytes128DataReader_impl::Bytes128DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes128DataReader_impl::~Bytes128DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Bytes128DataReader_impl::read (
    TP_Test::Bytes128Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes128DataReader_impl::take (
    TP_Test::Bytes128Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes128DataReader_impl::read_w_condition (
    TP_Test::Bytes128Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes128DataReader_impl::take_w_condition (
    TP_Test::Bytes128Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes128DataReader_impl::read_next_sample (
    TP_Test::Bytes128 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Bytes128DataReader_impl::take_next_sample (
    TP_Test::Bytes128 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Bytes128DataReader_impl::read_instance (
    TP_Test::Bytes128Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes128DataReader_impl::take_instance (
    TP_Test::Bytes128Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes128DataReader_impl::read_next_instance (
    TP_Test::Bytes128Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes128DataReader_impl::take_next_instance (
    TP_Test::Bytes128Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes128DataReader_impl::read_next_instance_w_condition (
    TP_Test::Bytes128Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes128DataReader_impl::take_next_instance_w_condition (
    TP_Test::Bytes128Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Bytes128DataReader_impl::return_loan (
    TP_Test::Bytes128Seq & received_data,
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
                TP_Test::Bytes128Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Bytes128DataReader_impl::get_key_value (
    TP_Test::Bytes128 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Bytes128DataReader_impl::lookup_instance (
    const TP_Test::Bytes128 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Bytes128DataReader_impl::check_preconditions(
    TP_Test::Bytes128Seq & received_data,
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
__TP_Test_Bytes256__copyIn(
    c_base base,
    struct TP_Test::Bytes256 *from,
    struct _TP_Test_Bytes256 *to
);

extern void
__TP_Test_Bytes256__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Bytes256 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Bytes256TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes256DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Bytes256TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes256DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Bytes256 TypeSupport Object Body

TP_Test::Bytes256TypeSupport::Bytes256TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Bytes256__name(),
        __TP_Test_Bytes256__keys(),
        TP_Test::Bytes256TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Bytes256__copyIn,
        (gapi_copyOut) __TP_Test_Bytes256__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Bytes256Seq, TP_Test::Bytes256>,
        new  TP_Test::Bytes256TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Bytes256TypeSupport::~Bytes256TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Bytes256TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Bytes256TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Bytes256 DataWriter_impl Object Body

TP_Test::Bytes256DataWriter_impl::Bytes256DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes256DataWriter_impl::~Bytes256DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Bytes256DataWriter_impl::register_instance (
    const TP_Test::Bytes256 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Bytes256DataWriter_impl::register_instance_w_timestamp (
    const Bytes256 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Bytes256DataWriter_impl::unregister_instance (
    const TP_Test::Bytes256 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Bytes256DataWriter_impl::unregister_instance_w_timestamp (
    const Bytes256 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes256DataWriter_impl::write (
    const TP_Test::Bytes256 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Bytes256DataWriter_impl::write_w_timestamp (
    const Bytes256 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes256DataWriter_impl::dispose (
    const TP_Test::Bytes256 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Bytes256DataWriter_impl::dispose_w_timestamp (
    const Bytes256 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Bytes256DataWriter_impl::get_key_value (
    Bytes256 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Bytes256 DataReader_impl Object Body

TP_Test::Bytes256DataReader_impl::Bytes256DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes256DataReader_impl::~Bytes256DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Bytes256DataReader_impl::read (
    TP_Test::Bytes256Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes256DataReader_impl::take (
    TP_Test::Bytes256Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes256DataReader_impl::read_w_condition (
    TP_Test::Bytes256Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes256DataReader_impl::take_w_condition (
    TP_Test::Bytes256Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes256DataReader_impl::read_next_sample (
    TP_Test::Bytes256 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Bytes256DataReader_impl::take_next_sample (
    TP_Test::Bytes256 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Bytes256DataReader_impl::read_instance (
    TP_Test::Bytes256Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes256DataReader_impl::take_instance (
    TP_Test::Bytes256Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes256DataReader_impl::read_next_instance (
    TP_Test::Bytes256Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes256DataReader_impl::take_next_instance (
    TP_Test::Bytes256Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes256DataReader_impl::read_next_instance_w_condition (
    TP_Test::Bytes256Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes256DataReader_impl::take_next_instance_w_condition (
    TP_Test::Bytes256Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Bytes256DataReader_impl::return_loan (
    TP_Test::Bytes256Seq & received_data,
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
                TP_Test::Bytes256Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Bytes256DataReader_impl::get_key_value (
    TP_Test::Bytes256 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Bytes256DataReader_impl::lookup_instance (
    const TP_Test::Bytes256 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Bytes256DataReader_impl::check_preconditions(
    TP_Test::Bytes256Seq & received_data,
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
__TP_Test_Bytes512__copyIn(
    c_base base,
    struct TP_Test::Bytes512 *from,
    struct _TP_Test_Bytes512 *to
);

extern void
__TP_Test_Bytes512__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Bytes512 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Bytes512TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes512DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Bytes512TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes512DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Bytes512 TypeSupport Object Body

TP_Test::Bytes512TypeSupport::Bytes512TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Bytes512__name(),
        __TP_Test_Bytes512__keys(),
        TP_Test::Bytes512TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Bytes512__copyIn,
        (gapi_copyOut) __TP_Test_Bytes512__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Bytes512Seq, TP_Test::Bytes512>,
        new  TP_Test::Bytes512TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Bytes512TypeSupport::~Bytes512TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Bytes512TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Bytes512TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Bytes512 DataWriter_impl Object Body

TP_Test::Bytes512DataWriter_impl::Bytes512DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes512DataWriter_impl::~Bytes512DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Bytes512DataWriter_impl::register_instance (
    const TP_Test::Bytes512 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Bytes512DataWriter_impl::register_instance_w_timestamp (
    const Bytes512 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Bytes512DataWriter_impl::unregister_instance (
    const TP_Test::Bytes512 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Bytes512DataWriter_impl::unregister_instance_w_timestamp (
    const Bytes512 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes512DataWriter_impl::write (
    const TP_Test::Bytes512 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Bytes512DataWriter_impl::write_w_timestamp (
    const Bytes512 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes512DataWriter_impl::dispose (
    const TP_Test::Bytes512 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Bytes512DataWriter_impl::dispose_w_timestamp (
    const Bytes512 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Bytes512DataWriter_impl::get_key_value (
    Bytes512 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Bytes512 DataReader_impl Object Body

TP_Test::Bytes512DataReader_impl::Bytes512DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes512DataReader_impl::~Bytes512DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Bytes512DataReader_impl::read (
    TP_Test::Bytes512Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes512DataReader_impl::take (
    TP_Test::Bytes512Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes512DataReader_impl::read_w_condition (
    TP_Test::Bytes512Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes512DataReader_impl::take_w_condition (
    TP_Test::Bytes512Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes512DataReader_impl::read_next_sample (
    TP_Test::Bytes512 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Bytes512DataReader_impl::take_next_sample (
    TP_Test::Bytes512 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Bytes512DataReader_impl::read_instance (
    TP_Test::Bytes512Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes512DataReader_impl::take_instance (
    TP_Test::Bytes512Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes512DataReader_impl::read_next_instance (
    TP_Test::Bytes512Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes512DataReader_impl::take_next_instance (
    TP_Test::Bytes512Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes512DataReader_impl::read_next_instance_w_condition (
    TP_Test::Bytes512Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes512DataReader_impl::take_next_instance_w_condition (
    TP_Test::Bytes512Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Bytes512DataReader_impl::return_loan (
    TP_Test::Bytes512Seq & received_data,
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
                TP_Test::Bytes512Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Bytes512DataReader_impl::get_key_value (
    TP_Test::Bytes512 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Bytes512DataReader_impl::lookup_instance (
    const TP_Test::Bytes512 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Bytes512DataReader_impl::check_preconditions(
    TP_Test::Bytes512Seq & received_data,
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
__TP_Test_Bytes1024__copyIn(
    c_base base,
    struct TP_Test::Bytes1024 *from,
    struct _TP_Test_Bytes1024 *to
);

extern void
__TP_Test_Bytes1024__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Bytes1024 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Bytes1024TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes1024DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Bytes1024TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes1024DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Bytes1024 TypeSupport Object Body

TP_Test::Bytes1024TypeSupport::Bytes1024TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Bytes1024__name(),
        __TP_Test_Bytes1024__keys(),
        TP_Test::Bytes1024TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Bytes1024__copyIn,
        (gapi_copyOut) __TP_Test_Bytes1024__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Bytes1024Seq, TP_Test::Bytes1024>,
        new  TP_Test::Bytes1024TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Bytes1024TypeSupport::~Bytes1024TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Bytes1024TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Bytes1024TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Bytes1024 DataWriter_impl Object Body

TP_Test::Bytes1024DataWriter_impl::Bytes1024DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes1024DataWriter_impl::~Bytes1024DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Bytes1024DataWriter_impl::register_instance (
    const TP_Test::Bytes1024 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Bytes1024DataWriter_impl::register_instance_w_timestamp (
    const Bytes1024 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Bytes1024DataWriter_impl::unregister_instance (
    const TP_Test::Bytes1024 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Bytes1024DataWriter_impl::unregister_instance_w_timestamp (
    const Bytes1024 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes1024DataWriter_impl::write (
    const TP_Test::Bytes1024 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Bytes1024DataWriter_impl::write_w_timestamp (
    const Bytes1024 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes1024DataWriter_impl::dispose (
    const TP_Test::Bytes1024 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Bytes1024DataWriter_impl::dispose_w_timestamp (
    const Bytes1024 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Bytes1024DataWriter_impl::get_key_value (
    Bytes1024 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Bytes1024 DataReader_impl Object Body

TP_Test::Bytes1024DataReader_impl::Bytes1024DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes1024DataReader_impl::~Bytes1024DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Bytes1024DataReader_impl::read (
    TP_Test::Bytes1024Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes1024DataReader_impl::take (
    TP_Test::Bytes1024Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes1024DataReader_impl::read_w_condition (
    TP_Test::Bytes1024Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes1024DataReader_impl::take_w_condition (
    TP_Test::Bytes1024Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes1024DataReader_impl::read_next_sample (
    TP_Test::Bytes1024 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Bytes1024DataReader_impl::take_next_sample (
    TP_Test::Bytes1024 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Bytes1024DataReader_impl::read_instance (
    TP_Test::Bytes1024Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes1024DataReader_impl::take_instance (
    TP_Test::Bytes1024Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes1024DataReader_impl::read_next_instance (
    TP_Test::Bytes1024Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes1024DataReader_impl::take_next_instance (
    TP_Test::Bytes1024Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes1024DataReader_impl::read_next_instance_w_condition (
    TP_Test::Bytes1024Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes1024DataReader_impl::take_next_instance_w_condition (
    TP_Test::Bytes1024Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Bytes1024DataReader_impl::return_loan (
    TP_Test::Bytes1024Seq & received_data,
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
                TP_Test::Bytes1024Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Bytes1024DataReader_impl::get_key_value (
    TP_Test::Bytes1024 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Bytes1024DataReader_impl::lookup_instance (
    const TP_Test::Bytes1024 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Bytes1024DataReader_impl::check_preconditions(
    TP_Test::Bytes1024Seq & received_data,
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
__TP_Test_Bytes2048__copyIn(
    c_base base,
    struct TP_Test::Bytes2048 *from,
    struct _TP_Test_Bytes2048 *to
);

extern void
__TP_Test_Bytes2048__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Bytes2048 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Bytes2048TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes2048DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Bytes2048TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes2048DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Bytes2048 TypeSupport Object Body

TP_Test::Bytes2048TypeSupport::Bytes2048TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Bytes2048__name(),
        __TP_Test_Bytes2048__keys(),
        TP_Test::Bytes2048TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Bytes2048__copyIn,
        (gapi_copyOut) __TP_Test_Bytes2048__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Bytes2048Seq, TP_Test::Bytes2048>,
        new  TP_Test::Bytes2048TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Bytes2048TypeSupport::~Bytes2048TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Bytes2048TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Bytes2048TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Bytes2048 DataWriter_impl Object Body

TP_Test::Bytes2048DataWriter_impl::Bytes2048DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes2048DataWriter_impl::~Bytes2048DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Bytes2048DataWriter_impl::register_instance (
    const TP_Test::Bytes2048 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Bytes2048DataWriter_impl::register_instance_w_timestamp (
    const Bytes2048 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Bytes2048DataWriter_impl::unregister_instance (
    const TP_Test::Bytes2048 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Bytes2048DataWriter_impl::unregister_instance_w_timestamp (
    const Bytes2048 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes2048DataWriter_impl::write (
    const TP_Test::Bytes2048 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Bytes2048DataWriter_impl::write_w_timestamp (
    const Bytes2048 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes2048DataWriter_impl::dispose (
    const TP_Test::Bytes2048 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Bytes2048DataWriter_impl::dispose_w_timestamp (
    const Bytes2048 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Bytes2048DataWriter_impl::get_key_value (
    Bytes2048 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Bytes2048 DataReader_impl Object Body

TP_Test::Bytes2048DataReader_impl::Bytes2048DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes2048DataReader_impl::~Bytes2048DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Bytes2048DataReader_impl::read (
    TP_Test::Bytes2048Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes2048DataReader_impl::take (
    TP_Test::Bytes2048Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes2048DataReader_impl::read_w_condition (
    TP_Test::Bytes2048Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes2048DataReader_impl::take_w_condition (
    TP_Test::Bytes2048Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes2048DataReader_impl::read_next_sample (
    TP_Test::Bytes2048 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Bytes2048DataReader_impl::take_next_sample (
    TP_Test::Bytes2048 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Bytes2048DataReader_impl::read_instance (
    TP_Test::Bytes2048Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes2048DataReader_impl::take_instance (
    TP_Test::Bytes2048Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes2048DataReader_impl::read_next_instance (
    TP_Test::Bytes2048Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes2048DataReader_impl::take_next_instance (
    TP_Test::Bytes2048Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes2048DataReader_impl::read_next_instance_w_condition (
    TP_Test::Bytes2048Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes2048DataReader_impl::take_next_instance_w_condition (
    TP_Test::Bytes2048Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Bytes2048DataReader_impl::return_loan (
    TP_Test::Bytes2048Seq & received_data,
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
                TP_Test::Bytes2048Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Bytes2048DataReader_impl::get_key_value (
    TP_Test::Bytes2048 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Bytes2048DataReader_impl::lookup_instance (
    const TP_Test::Bytes2048 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Bytes2048DataReader_impl::check_preconditions(
    TP_Test::Bytes2048Seq & received_data,
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
__TP_Test_Bytes4096__copyIn(
    c_base base,
    struct TP_Test::Bytes4096 *from,
    struct _TP_Test_Bytes4096 *to
);

extern void
__TP_Test_Bytes4096__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Bytes4096 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Bytes4096TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes4096DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Bytes4096TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes4096DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Bytes4096 TypeSupport Object Body

TP_Test::Bytes4096TypeSupport::Bytes4096TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Bytes4096__name(),
        __TP_Test_Bytes4096__keys(),
        TP_Test::Bytes4096TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Bytes4096__copyIn,
        (gapi_copyOut) __TP_Test_Bytes4096__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Bytes4096Seq, TP_Test::Bytes4096>,
        new  TP_Test::Bytes4096TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Bytes4096TypeSupport::~Bytes4096TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Bytes4096TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Bytes4096TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Bytes4096 DataWriter_impl Object Body

TP_Test::Bytes4096DataWriter_impl::Bytes4096DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes4096DataWriter_impl::~Bytes4096DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Bytes4096DataWriter_impl::register_instance (
    const TP_Test::Bytes4096 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Bytes4096DataWriter_impl::register_instance_w_timestamp (
    const Bytes4096 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Bytes4096DataWriter_impl::unregister_instance (
    const TP_Test::Bytes4096 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Bytes4096DataWriter_impl::unregister_instance_w_timestamp (
    const Bytes4096 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes4096DataWriter_impl::write (
    const TP_Test::Bytes4096 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Bytes4096DataWriter_impl::write_w_timestamp (
    const Bytes4096 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes4096DataWriter_impl::dispose (
    const TP_Test::Bytes4096 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Bytes4096DataWriter_impl::dispose_w_timestamp (
    const Bytes4096 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Bytes4096DataWriter_impl::get_key_value (
    Bytes4096 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Bytes4096 DataReader_impl Object Body

TP_Test::Bytes4096DataReader_impl::Bytes4096DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes4096DataReader_impl::~Bytes4096DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Bytes4096DataReader_impl::read (
    TP_Test::Bytes4096Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes4096DataReader_impl::take (
    TP_Test::Bytes4096Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes4096DataReader_impl::read_w_condition (
    TP_Test::Bytes4096Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes4096DataReader_impl::take_w_condition (
    TP_Test::Bytes4096Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes4096DataReader_impl::read_next_sample (
    TP_Test::Bytes4096 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Bytes4096DataReader_impl::take_next_sample (
    TP_Test::Bytes4096 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Bytes4096DataReader_impl::read_instance (
    TP_Test::Bytes4096Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes4096DataReader_impl::take_instance (
    TP_Test::Bytes4096Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes4096DataReader_impl::read_next_instance (
    TP_Test::Bytes4096Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes4096DataReader_impl::take_next_instance (
    TP_Test::Bytes4096Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes4096DataReader_impl::read_next_instance_w_condition (
    TP_Test::Bytes4096Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes4096DataReader_impl::take_next_instance_w_condition (
    TP_Test::Bytes4096Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Bytes4096DataReader_impl::return_loan (
    TP_Test::Bytes4096Seq & received_data,
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
                TP_Test::Bytes4096Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Bytes4096DataReader_impl::get_key_value (
    TP_Test::Bytes4096 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Bytes4096DataReader_impl::lookup_instance (
    const TP_Test::Bytes4096 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Bytes4096DataReader_impl::check_preconditions(
    TP_Test::Bytes4096Seq & received_data,
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
__TP_Test_Bytes8192__copyIn(
    c_base base,
    struct TP_Test::Bytes8192 *from,
    struct _TP_Test_Bytes8192 *to
);

extern void
__TP_Test_Bytes8192__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Bytes8192 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Bytes8192TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes8192DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Bytes8192TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes8192DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Bytes8192 TypeSupport Object Body

TP_Test::Bytes8192TypeSupport::Bytes8192TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Bytes8192__name(),
        __TP_Test_Bytes8192__keys(),
        TP_Test::Bytes8192TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Bytes8192__copyIn,
        (gapi_copyOut) __TP_Test_Bytes8192__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Bytes8192Seq, TP_Test::Bytes8192>,
        new  TP_Test::Bytes8192TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Bytes8192TypeSupport::~Bytes8192TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Bytes8192TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Bytes8192TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Bytes8192 DataWriter_impl Object Body

TP_Test::Bytes8192DataWriter_impl::Bytes8192DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes8192DataWriter_impl::~Bytes8192DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Bytes8192DataWriter_impl::register_instance (
    const TP_Test::Bytes8192 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Bytes8192DataWriter_impl::register_instance_w_timestamp (
    const Bytes8192 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Bytes8192DataWriter_impl::unregister_instance (
    const TP_Test::Bytes8192 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Bytes8192DataWriter_impl::unregister_instance_w_timestamp (
    const Bytes8192 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes8192DataWriter_impl::write (
    const TP_Test::Bytes8192 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Bytes8192DataWriter_impl::write_w_timestamp (
    const Bytes8192 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes8192DataWriter_impl::dispose (
    const TP_Test::Bytes8192 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Bytes8192DataWriter_impl::dispose_w_timestamp (
    const Bytes8192 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Bytes8192DataWriter_impl::get_key_value (
    Bytes8192 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Bytes8192 DataReader_impl Object Body

TP_Test::Bytes8192DataReader_impl::Bytes8192DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes8192DataReader_impl::~Bytes8192DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Bytes8192DataReader_impl::read (
    TP_Test::Bytes8192Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes8192DataReader_impl::take (
    TP_Test::Bytes8192Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes8192DataReader_impl::read_w_condition (
    TP_Test::Bytes8192Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes8192DataReader_impl::take_w_condition (
    TP_Test::Bytes8192Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes8192DataReader_impl::read_next_sample (
    TP_Test::Bytes8192 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Bytes8192DataReader_impl::take_next_sample (
    TP_Test::Bytes8192 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Bytes8192DataReader_impl::read_instance (
    TP_Test::Bytes8192Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes8192DataReader_impl::take_instance (
    TP_Test::Bytes8192Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes8192DataReader_impl::read_next_instance (
    TP_Test::Bytes8192Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes8192DataReader_impl::take_next_instance (
    TP_Test::Bytes8192Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes8192DataReader_impl::read_next_instance_w_condition (
    TP_Test::Bytes8192Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes8192DataReader_impl::take_next_instance_w_condition (
    TP_Test::Bytes8192Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Bytes8192DataReader_impl::return_loan (
    TP_Test::Bytes8192Seq & received_data,
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
                TP_Test::Bytes8192Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Bytes8192DataReader_impl::get_key_value (
    TP_Test::Bytes8192 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Bytes8192DataReader_impl::lookup_instance (
    const TP_Test::Bytes8192 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Bytes8192DataReader_impl::check_preconditions(
    TP_Test::Bytes8192Seq & received_data,
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
__TP_Test_Bytes16384__copyIn(
    c_base base,
    struct TP_Test::Bytes16384 *from,
    struct _TP_Test_Bytes16384 *to
);

extern void
__TP_Test_Bytes16384__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Bytes16384 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Bytes16384TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes16384DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Bytes16384TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Bytes16384DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Bytes16384 TypeSupport Object Body

TP_Test::Bytes16384TypeSupport::Bytes16384TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Bytes16384__name(),
        __TP_Test_Bytes16384__keys(),
        TP_Test::Bytes16384TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Bytes16384__copyIn,
        (gapi_copyOut) __TP_Test_Bytes16384__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Bytes16384Seq, TP_Test::Bytes16384>,
        new  TP_Test::Bytes16384TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Bytes16384TypeSupport::~Bytes16384TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Bytes16384TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Bytes16384TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Bytes16384 DataWriter_impl Object Body

TP_Test::Bytes16384DataWriter_impl::Bytes16384DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes16384DataWriter_impl::~Bytes16384DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Bytes16384DataWriter_impl::register_instance (
    const TP_Test::Bytes16384 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Bytes16384DataWriter_impl::register_instance_w_timestamp (
    const Bytes16384 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Bytes16384DataWriter_impl::unregister_instance (
    const TP_Test::Bytes16384 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Bytes16384DataWriter_impl::unregister_instance_w_timestamp (
    const Bytes16384 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes16384DataWriter_impl::write (
    const TP_Test::Bytes16384 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Bytes16384DataWriter_impl::write_w_timestamp (
    const Bytes16384 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Bytes16384DataWriter_impl::dispose (
    const TP_Test::Bytes16384 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Bytes16384DataWriter_impl::dispose_w_timestamp (
    const Bytes16384 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Bytes16384DataWriter_impl::get_key_value (
    Bytes16384 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Bytes16384 DataReader_impl Object Body

TP_Test::Bytes16384DataReader_impl::Bytes16384DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Bytes16384DataReader_impl::~Bytes16384DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Bytes16384DataReader_impl::read (
    TP_Test::Bytes16384Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes16384DataReader_impl::take (
    TP_Test::Bytes16384Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes16384DataReader_impl::read_w_condition (
    TP_Test::Bytes16384Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes16384DataReader_impl::take_w_condition (
    TP_Test::Bytes16384Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes16384DataReader_impl::read_next_sample (
    TP_Test::Bytes16384 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Bytes16384DataReader_impl::take_next_sample (
    TP_Test::Bytes16384 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Bytes16384DataReader_impl::read_instance (
    TP_Test::Bytes16384Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes16384DataReader_impl::take_instance (
    TP_Test::Bytes16384Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes16384DataReader_impl::read_next_instance (
    TP_Test::Bytes16384Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Bytes16384DataReader_impl::take_next_instance (
    TP_Test::Bytes16384Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes16384DataReader_impl::read_next_instance_w_condition (
    TP_Test::Bytes16384Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Bytes16384DataReader_impl::take_next_instance_w_condition (
    TP_Test::Bytes16384Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Bytes16384DataReader_impl::return_loan (
    TP_Test::Bytes16384Seq & received_data,
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
                TP_Test::Bytes16384Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Bytes16384DataReader_impl::get_key_value (
    TP_Test::Bytes16384 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Bytes16384DataReader_impl::lookup_instance (
    const TP_Test::Bytes16384 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Bytes16384DataReader_impl::check_preconditions(
    TP_Test::Bytes16384Seq & received_data,
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
__TP_Test_Complex4__copyIn(
    c_base base,
    struct TP_Test::Complex4 *from,
    struct _TP_Test_Complex4 *to
);

extern void
__TP_Test_Complex4__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Complex4 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Complex4TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex4DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Complex4TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex4DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Complex4 TypeSupport Object Body

TP_Test::Complex4TypeSupport::Complex4TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Complex4__name(),
        __TP_Test_Complex4__keys(),
        TP_Test::Complex4TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Complex4__copyIn,
        (gapi_copyOut) __TP_Test_Complex4__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Complex4Seq, TP_Test::Complex4>,
        new  TP_Test::Complex4TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Complex4TypeSupport::~Complex4TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Complex4TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Complex4TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Complex4 DataWriter_impl Object Body

TP_Test::Complex4DataWriter_impl::Complex4DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex4DataWriter_impl::~Complex4DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Complex4DataWriter_impl::register_instance (
    const TP_Test::Complex4 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Complex4DataWriter_impl::register_instance_w_timestamp (
    const Complex4 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Complex4DataWriter_impl::unregister_instance (
    const TP_Test::Complex4 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Complex4DataWriter_impl::unregister_instance_w_timestamp (
    const Complex4 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex4DataWriter_impl::write (
    const TP_Test::Complex4 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Complex4DataWriter_impl::write_w_timestamp (
    const Complex4 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex4DataWriter_impl::dispose (
    const TP_Test::Complex4 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Complex4DataWriter_impl::dispose_w_timestamp (
    const Complex4 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Complex4DataWriter_impl::get_key_value (
    Complex4 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Complex4 DataReader_impl Object Body

TP_Test::Complex4DataReader_impl::Complex4DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex4DataReader_impl::~Complex4DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Complex4DataReader_impl::read (
    TP_Test::Complex4Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex4DataReader_impl::take (
    TP_Test::Complex4Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex4DataReader_impl::read_w_condition (
    TP_Test::Complex4Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex4DataReader_impl::take_w_condition (
    TP_Test::Complex4Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex4DataReader_impl::read_next_sample (
    TP_Test::Complex4 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Complex4DataReader_impl::take_next_sample (
    TP_Test::Complex4 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Complex4DataReader_impl::read_instance (
    TP_Test::Complex4Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex4DataReader_impl::take_instance (
    TP_Test::Complex4Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex4DataReader_impl::read_next_instance (
    TP_Test::Complex4Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex4DataReader_impl::take_next_instance (
    TP_Test::Complex4Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex4DataReader_impl::read_next_instance_w_condition (
    TP_Test::Complex4Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex4DataReader_impl::take_next_instance_w_condition (
    TP_Test::Complex4Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Complex4DataReader_impl::return_loan (
    TP_Test::Complex4Seq & received_data,
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
                TP_Test::Complex4Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Complex4DataReader_impl::get_key_value (
    TP_Test::Complex4 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Complex4DataReader_impl::lookup_instance (
    const TP_Test::Complex4 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Complex4DataReader_impl::check_preconditions(
    TP_Test::Complex4Seq & received_data,
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
__TP_Test_Complex8__copyIn(
    c_base base,
    struct TP_Test::Complex8 *from,
    struct _TP_Test_Complex8 *to
);

extern void
__TP_Test_Complex8__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Complex8 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Complex8TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex8DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Complex8TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex8DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Complex8 TypeSupport Object Body

TP_Test::Complex8TypeSupport::Complex8TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Complex8__name(),
        __TP_Test_Complex8__keys(),
        TP_Test::Complex8TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Complex8__copyIn,
        (gapi_copyOut) __TP_Test_Complex8__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Complex8Seq, TP_Test::Complex8>,
        new  TP_Test::Complex8TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Complex8TypeSupport::~Complex8TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Complex8TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Complex8TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Complex8 DataWriter_impl Object Body

TP_Test::Complex8DataWriter_impl::Complex8DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex8DataWriter_impl::~Complex8DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Complex8DataWriter_impl::register_instance (
    const TP_Test::Complex8 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Complex8DataWriter_impl::register_instance_w_timestamp (
    const Complex8 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Complex8DataWriter_impl::unregister_instance (
    const TP_Test::Complex8 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Complex8DataWriter_impl::unregister_instance_w_timestamp (
    const Complex8 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex8DataWriter_impl::write (
    const TP_Test::Complex8 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Complex8DataWriter_impl::write_w_timestamp (
    const Complex8 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex8DataWriter_impl::dispose (
    const TP_Test::Complex8 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Complex8DataWriter_impl::dispose_w_timestamp (
    const Complex8 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Complex8DataWriter_impl::get_key_value (
    Complex8 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Complex8 DataReader_impl Object Body

TP_Test::Complex8DataReader_impl::Complex8DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex8DataReader_impl::~Complex8DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Complex8DataReader_impl::read (
    TP_Test::Complex8Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex8DataReader_impl::take (
    TP_Test::Complex8Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex8DataReader_impl::read_w_condition (
    TP_Test::Complex8Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex8DataReader_impl::take_w_condition (
    TP_Test::Complex8Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex8DataReader_impl::read_next_sample (
    TP_Test::Complex8 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Complex8DataReader_impl::take_next_sample (
    TP_Test::Complex8 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Complex8DataReader_impl::read_instance (
    TP_Test::Complex8Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex8DataReader_impl::take_instance (
    TP_Test::Complex8Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex8DataReader_impl::read_next_instance (
    TP_Test::Complex8Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex8DataReader_impl::take_next_instance (
    TP_Test::Complex8Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex8DataReader_impl::read_next_instance_w_condition (
    TP_Test::Complex8Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex8DataReader_impl::take_next_instance_w_condition (
    TP_Test::Complex8Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Complex8DataReader_impl::return_loan (
    TP_Test::Complex8Seq & received_data,
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
                TP_Test::Complex8Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Complex8DataReader_impl::get_key_value (
    TP_Test::Complex8 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Complex8DataReader_impl::lookup_instance (
    const TP_Test::Complex8 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Complex8DataReader_impl::check_preconditions(
    TP_Test::Complex8Seq & received_data,
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
__TP_Test_Complex16__copyIn(
    c_base base,
    struct TP_Test::Complex16 *from,
    struct _TP_Test_Complex16 *to
);

extern void
__TP_Test_Complex16__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Complex16 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Complex16TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex16DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Complex16TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex16DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Complex16 TypeSupport Object Body

TP_Test::Complex16TypeSupport::Complex16TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Complex16__name(),
        __TP_Test_Complex16__keys(),
        TP_Test::Complex16TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Complex16__copyIn,
        (gapi_copyOut) __TP_Test_Complex16__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Complex16Seq, TP_Test::Complex16>,
        new  TP_Test::Complex16TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Complex16TypeSupport::~Complex16TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Complex16TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Complex16TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Complex16 DataWriter_impl Object Body

TP_Test::Complex16DataWriter_impl::Complex16DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex16DataWriter_impl::~Complex16DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Complex16DataWriter_impl::register_instance (
    const TP_Test::Complex16 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Complex16DataWriter_impl::register_instance_w_timestamp (
    const Complex16 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Complex16DataWriter_impl::unregister_instance (
    const TP_Test::Complex16 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Complex16DataWriter_impl::unregister_instance_w_timestamp (
    const Complex16 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex16DataWriter_impl::write (
    const TP_Test::Complex16 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Complex16DataWriter_impl::write_w_timestamp (
    const Complex16 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex16DataWriter_impl::dispose (
    const TP_Test::Complex16 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Complex16DataWriter_impl::dispose_w_timestamp (
    const Complex16 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Complex16DataWriter_impl::get_key_value (
    Complex16 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Complex16 DataReader_impl Object Body

TP_Test::Complex16DataReader_impl::Complex16DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex16DataReader_impl::~Complex16DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Complex16DataReader_impl::read (
    TP_Test::Complex16Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex16DataReader_impl::take (
    TP_Test::Complex16Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex16DataReader_impl::read_w_condition (
    TP_Test::Complex16Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex16DataReader_impl::take_w_condition (
    TP_Test::Complex16Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex16DataReader_impl::read_next_sample (
    TP_Test::Complex16 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Complex16DataReader_impl::take_next_sample (
    TP_Test::Complex16 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Complex16DataReader_impl::read_instance (
    TP_Test::Complex16Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex16DataReader_impl::take_instance (
    TP_Test::Complex16Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex16DataReader_impl::read_next_instance (
    TP_Test::Complex16Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex16DataReader_impl::take_next_instance (
    TP_Test::Complex16Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex16DataReader_impl::read_next_instance_w_condition (
    TP_Test::Complex16Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex16DataReader_impl::take_next_instance_w_condition (
    TP_Test::Complex16Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Complex16DataReader_impl::return_loan (
    TP_Test::Complex16Seq & received_data,
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
                TP_Test::Complex16Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Complex16DataReader_impl::get_key_value (
    TP_Test::Complex16 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Complex16DataReader_impl::lookup_instance (
    const TP_Test::Complex16 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Complex16DataReader_impl::check_preconditions(
    TP_Test::Complex16Seq & received_data,
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
__TP_Test_Complex32__copyIn(
    c_base base,
    struct TP_Test::Complex32 *from,
    struct _TP_Test_Complex32 *to
);

extern void
__TP_Test_Complex32__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Complex32 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Complex32TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex32DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Complex32TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex32DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Complex32 TypeSupport Object Body

TP_Test::Complex32TypeSupport::Complex32TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Complex32__name(),
        __TP_Test_Complex32__keys(),
        TP_Test::Complex32TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Complex32__copyIn,
        (gapi_copyOut) __TP_Test_Complex32__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Complex32Seq, TP_Test::Complex32>,
        new  TP_Test::Complex32TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Complex32TypeSupport::~Complex32TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Complex32TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Complex32TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Complex32 DataWriter_impl Object Body

TP_Test::Complex32DataWriter_impl::Complex32DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex32DataWriter_impl::~Complex32DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Complex32DataWriter_impl::register_instance (
    const TP_Test::Complex32 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Complex32DataWriter_impl::register_instance_w_timestamp (
    const Complex32 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Complex32DataWriter_impl::unregister_instance (
    const TP_Test::Complex32 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Complex32DataWriter_impl::unregister_instance_w_timestamp (
    const Complex32 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex32DataWriter_impl::write (
    const TP_Test::Complex32 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Complex32DataWriter_impl::write_w_timestamp (
    const Complex32 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex32DataWriter_impl::dispose (
    const TP_Test::Complex32 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Complex32DataWriter_impl::dispose_w_timestamp (
    const Complex32 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Complex32DataWriter_impl::get_key_value (
    Complex32 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Complex32 DataReader_impl Object Body

TP_Test::Complex32DataReader_impl::Complex32DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex32DataReader_impl::~Complex32DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Complex32DataReader_impl::read (
    TP_Test::Complex32Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex32DataReader_impl::take (
    TP_Test::Complex32Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex32DataReader_impl::read_w_condition (
    TP_Test::Complex32Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex32DataReader_impl::take_w_condition (
    TP_Test::Complex32Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex32DataReader_impl::read_next_sample (
    TP_Test::Complex32 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Complex32DataReader_impl::take_next_sample (
    TP_Test::Complex32 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Complex32DataReader_impl::read_instance (
    TP_Test::Complex32Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex32DataReader_impl::take_instance (
    TP_Test::Complex32Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex32DataReader_impl::read_next_instance (
    TP_Test::Complex32Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex32DataReader_impl::take_next_instance (
    TP_Test::Complex32Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex32DataReader_impl::read_next_instance_w_condition (
    TP_Test::Complex32Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex32DataReader_impl::take_next_instance_w_condition (
    TP_Test::Complex32Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Complex32DataReader_impl::return_loan (
    TP_Test::Complex32Seq & received_data,
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
                TP_Test::Complex32Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Complex32DataReader_impl::get_key_value (
    TP_Test::Complex32 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Complex32DataReader_impl::lookup_instance (
    const TP_Test::Complex32 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Complex32DataReader_impl::check_preconditions(
    TP_Test::Complex32Seq & received_data,
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
__TP_Test_Complex64__copyIn(
    c_base base,
    struct TP_Test::Complex64 *from,
    struct _TP_Test_Complex64 *to
);

extern void
__TP_Test_Complex64__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Complex64 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Complex64TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex64DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Complex64TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex64DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Complex64 TypeSupport Object Body

TP_Test::Complex64TypeSupport::Complex64TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Complex64__name(),
        __TP_Test_Complex64__keys(),
        TP_Test::Complex64TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Complex64__copyIn,
        (gapi_copyOut) __TP_Test_Complex64__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Complex64Seq, TP_Test::Complex64>,
        new  TP_Test::Complex64TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Complex64TypeSupport::~Complex64TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Complex64TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Complex64TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Complex64 DataWriter_impl Object Body

TP_Test::Complex64DataWriter_impl::Complex64DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex64DataWriter_impl::~Complex64DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Complex64DataWriter_impl::register_instance (
    const TP_Test::Complex64 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Complex64DataWriter_impl::register_instance_w_timestamp (
    const Complex64 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Complex64DataWriter_impl::unregister_instance (
    const TP_Test::Complex64 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Complex64DataWriter_impl::unregister_instance_w_timestamp (
    const Complex64 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex64DataWriter_impl::write (
    const TP_Test::Complex64 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Complex64DataWriter_impl::write_w_timestamp (
    const Complex64 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex64DataWriter_impl::dispose (
    const TP_Test::Complex64 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Complex64DataWriter_impl::dispose_w_timestamp (
    const Complex64 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Complex64DataWriter_impl::get_key_value (
    Complex64 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Complex64 DataReader_impl Object Body

TP_Test::Complex64DataReader_impl::Complex64DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex64DataReader_impl::~Complex64DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Complex64DataReader_impl::read (
    TP_Test::Complex64Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex64DataReader_impl::take (
    TP_Test::Complex64Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex64DataReader_impl::read_w_condition (
    TP_Test::Complex64Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex64DataReader_impl::take_w_condition (
    TP_Test::Complex64Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex64DataReader_impl::read_next_sample (
    TP_Test::Complex64 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Complex64DataReader_impl::take_next_sample (
    TP_Test::Complex64 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Complex64DataReader_impl::read_instance (
    TP_Test::Complex64Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex64DataReader_impl::take_instance (
    TP_Test::Complex64Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex64DataReader_impl::read_next_instance (
    TP_Test::Complex64Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex64DataReader_impl::take_next_instance (
    TP_Test::Complex64Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex64DataReader_impl::read_next_instance_w_condition (
    TP_Test::Complex64Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex64DataReader_impl::take_next_instance_w_condition (
    TP_Test::Complex64Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Complex64DataReader_impl::return_loan (
    TP_Test::Complex64Seq & received_data,
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
                TP_Test::Complex64Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Complex64DataReader_impl::get_key_value (
    TP_Test::Complex64 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Complex64DataReader_impl::lookup_instance (
    const TP_Test::Complex64 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Complex64DataReader_impl::check_preconditions(
    TP_Test::Complex64Seq & received_data,
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
__TP_Test_Complex128__copyIn(
    c_base base,
    struct TP_Test::Complex128 *from,
    struct _TP_Test_Complex128 *to
);

extern void
__TP_Test_Complex128__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Complex128 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Complex128TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex128DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Complex128TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex128DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Complex128 TypeSupport Object Body

TP_Test::Complex128TypeSupport::Complex128TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Complex128__name(),
        __TP_Test_Complex128__keys(),
        TP_Test::Complex128TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Complex128__copyIn,
        (gapi_copyOut) __TP_Test_Complex128__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Complex128Seq, TP_Test::Complex128>,
        new  TP_Test::Complex128TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Complex128TypeSupport::~Complex128TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Complex128TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Complex128TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Complex128 DataWriter_impl Object Body

TP_Test::Complex128DataWriter_impl::Complex128DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex128DataWriter_impl::~Complex128DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Complex128DataWriter_impl::register_instance (
    const TP_Test::Complex128 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Complex128DataWriter_impl::register_instance_w_timestamp (
    const Complex128 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Complex128DataWriter_impl::unregister_instance (
    const TP_Test::Complex128 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Complex128DataWriter_impl::unregister_instance_w_timestamp (
    const Complex128 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex128DataWriter_impl::write (
    const TP_Test::Complex128 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Complex128DataWriter_impl::write_w_timestamp (
    const Complex128 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex128DataWriter_impl::dispose (
    const TP_Test::Complex128 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Complex128DataWriter_impl::dispose_w_timestamp (
    const Complex128 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Complex128DataWriter_impl::get_key_value (
    Complex128 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Complex128 DataReader_impl Object Body

TP_Test::Complex128DataReader_impl::Complex128DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex128DataReader_impl::~Complex128DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Complex128DataReader_impl::read (
    TP_Test::Complex128Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex128DataReader_impl::take (
    TP_Test::Complex128Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex128DataReader_impl::read_w_condition (
    TP_Test::Complex128Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex128DataReader_impl::take_w_condition (
    TP_Test::Complex128Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex128DataReader_impl::read_next_sample (
    TP_Test::Complex128 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Complex128DataReader_impl::take_next_sample (
    TP_Test::Complex128 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Complex128DataReader_impl::read_instance (
    TP_Test::Complex128Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex128DataReader_impl::take_instance (
    TP_Test::Complex128Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex128DataReader_impl::read_next_instance (
    TP_Test::Complex128Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex128DataReader_impl::take_next_instance (
    TP_Test::Complex128Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex128DataReader_impl::read_next_instance_w_condition (
    TP_Test::Complex128Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex128DataReader_impl::take_next_instance_w_condition (
    TP_Test::Complex128Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Complex128DataReader_impl::return_loan (
    TP_Test::Complex128Seq & received_data,
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
                TP_Test::Complex128Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Complex128DataReader_impl::get_key_value (
    TP_Test::Complex128 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Complex128DataReader_impl::lookup_instance (
    const TP_Test::Complex128 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Complex128DataReader_impl::check_preconditions(
    TP_Test::Complex128Seq & received_data,
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
__TP_Test_Complex256__copyIn(
    c_base base,
    struct TP_Test::Complex256 *from,
    struct _TP_Test_Complex256 *to
);

extern void
__TP_Test_Complex256__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Complex256 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Complex256TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex256DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Complex256TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex256DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Complex256 TypeSupport Object Body

TP_Test::Complex256TypeSupport::Complex256TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Complex256__name(),
        __TP_Test_Complex256__keys(),
        TP_Test::Complex256TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Complex256__copyIn,
        (gapi_copyOut) __TP_Test_Complex256__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Complex256Seq, TP_Test::Complex256>,
        new  TP_Test::Complex256TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Complex256TypeSupport::~Complex256TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Complex256TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Complex256TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Complex256 DataWriter_impl Object Body

TP_Test::Complex256DataWriter_impl::Complex256DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex256DataWriter_impl::~Complex256DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Complex256DataWriter_impl::register_instance (
    const TP_Test::Complex256 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Complex256DataWriter_impl::register_instance_w_timestamp (
    const Complex256 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Complex256DataWriter_impl::unregister_instance (
    const TP_Test::Complex256 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Complex256DataWriter_impl::unregister_instance_w_timestamp (
    const Complex256 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex256DataWriter_impl::write (
    const TP_Test::Complex256 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Complex256DataWriter_impl::write_w_timestamp (
    const Complex256 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex256DataWriter_impl::dispose (
    const TP_Test::Complex256 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Complex256DataWriter_impl::dispose_w_timestamp (
    const Complex256 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Complex256DataWriter_impl::get_key_value (
    Complex256 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Complex256 DataReader_impl Object Body

TP_Test::Complex256DataReader_impl::Complex256DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex256DataReader_impl::~Complex256DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Complex256DataReader_impl::read (
    TP_Test::Complex256Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex256DataReader_impl::take (
    TP_Test::Complex256Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex256DataReader_impl::read_w_condition (
    TP_Test::Complex256Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex256DataReader_impl::take_w_condition (
    TP_Test::Complex256Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex256DataReader_impl::read_next_sample (
    TP_Test::Complex256 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Complex256DataReader_impl::take_next_sample (
    TP_Test::Complex256 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Complex256DataReader_impl::read_instance (
    TP_Test::Complex256Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex256DataReader_impl::take_instance (
    TP_Test::Complex256Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex256DataReader_impl::read_next_instance (
    TP_Test::Complex256Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex256DataReader_impl::take_next_instance (
    TP_Test::Complex256Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex256DataReader_impl::read_next_instance_w_condition (
    TP_Test::Complex256Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex256DataReader_impl::take_next_instance_w_condition (
    TP_Test::Complex256Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Complex256DataReader_impl::return_loan (
    TP_Test::Complex256Seq & received_data,
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
                TP_Test::Complex256Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Complex256DataReader_impl::get_key_value (
    TP_Test::Complex256 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Complex256DataReader_impl::lookup_instance (
    const TP_Test::Complex256 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Complex256DataReader_impl::check_preconditions(
    TP_Test::Complex256Seq & received_data,
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
__TP_Test_Complex512__copyIn(
    c_base base,
    struct TP_Test::Complex512 *from,
    struct _TP_Test_Complex512 *to
);

extern void
__TP_Test_Complex512__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Complex512 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Complex512TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex512DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Complex512TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex512DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Complex512 TypeSupport Object Body

TP_Test::Complex512TypeSupport::Complex512TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Complex512__name(),
        __TP_Test_Complex512__keys(),
        TP_Test::Complex512TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Complex512__copyIn,
        (gapi_copyOut) __TP_Test_Complex512__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Complex512Seq, TP_Test::Complex512>,
        new  TP_Test::Complex512TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Complex512TypeSupport::~Complex512TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Complex512TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Complex512TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Complex512 DataWriter_impl Object Body

TP_Test::Complex512DataWriter_impl::Complex512DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex512DataWriter_impl::~Complex512DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Complex512DataWriter_impl::register_instance (
    const TP_Test::Complex512 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Complex512DataWriter_impl::register_instance_w_timestamp (
    const Complex512 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Complex512DataWriter_impl::unregister_instance (
    const TP_Test::Complex512 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Complex512DataWriter_impl::unregister_instance_w_timestamp (
    const Complex512 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex512DataWriter_impl::write (
    const TP_Test::Complex512 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Complex512DataWriter_impl::write_w_timestamp (
    const Complex512 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex512DataWriter_impl::dispose (
    const TP_Test::Complex512 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Complex512DataWriter_impl::dispose_w_timestamp (
    const Complex512 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Complex512DataWriter_impl::get_key_value (
    Complex512 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Complex512 DataReader_impl Object Body

TP_Test::Complex512DataReader_impl::Complex512DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex512DataReader_impl::~Complex512DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Complex512DataReader_impl::read (
    TP_Test::Complex512Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex512DataReader_impl::take (
    TP_Test::Complex512Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex512DataReader_impl::read_w_condition (
    TP_Test::Complex512Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex512DataReader_impl::take_w_condition (
    TP_Test::Complex512Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex512DataReader_impl::read_next_sample (
    TP_Test::Complex512 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Complex512DataReader_impl::take_next_sample (
    TP_Test::Complex512 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Complex512DataReader_impl::read_instance (
    TP_Test::Complex512Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex512DataReader_impl::take_instance (
    TP_Test::Complex512Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex512DataReader_impl::read_next_instance (
    TP_Test::Complex512Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex512DataReader_impl::take_next_instance (
    TP_Test::Complex512Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex512DataReader_impl::read_next_instance_w_condition (
    TP_Test::Complex512Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex512DataReader_impl::take_next_instance_w_condition (
    TP_Test::Complex512Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Complex512DataReader_impl::return_loan (
    TP_Test::Complex512Seq & received_data,
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
                TP_Test::Complex512Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Complex512DataReader_impl::get_key_value (
    TP_Test::Complex512 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Complex512DataReader_impl::lookup_instance (
    const TP_Test::Complex512 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Complex512DataReader_impl::check_preconditions(
    TP_Test::Complex512Seq & received_data,
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
__TP_Test_Complex1024__copyIn(
    c_base base,
    struct TP_Test::Complex1024 *from,
    struct _TP_Test_Complex1024 *to
);

extern void
__TP_Test_Complex1024__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Complex1024 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Complex1024TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex1024DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Complex1024TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex1024DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Complex1024 TypeSupport Object Body

TP_Test::Complex1024TypeSupport::Complex1024TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Complex1024__name(),
        __TP_Test_Complex1024__keys(),
        TP_Test::Complex1024TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Complex1024__copyIn,
        (gapi_copyOut) __TP_Test_Complex1024__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Complex1024Seq, TP_Test::Complex1024>,
        new  TP_Test::Complex1024TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Complex1024TypeSupport::~Complex1024TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Complex1024TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Complex1024TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Complex1024 DataWriter_impl Object Body

TP_Test::Complex1024DataWriter_impl::Complex1024DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex1024DataWriter_impl::~Complex1024DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Complex1024DataWriter_impl::register_instance (
    const TP_Test::Complex1024 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Complex1024DataWriter_impl::register_instance_w_timestamp (
    const Complex1024 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Complex1024DataWriter_impl::unregister_instance (
    const TP_Test::Complex1024 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Complex1024DataWriter_impl::unregister_instance_w_timestamp (
    const Complex1024 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex1024DataWriter_impl::write (
    const TP_Test::Complex1024 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Complex1024DataWriter_impl::write_w_timestamp (
    const Complex1024 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex1024DataWriter_impl::dispose (
    const TP_Test::Complex1024 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Complex1024DataWriter_impl::dispose_w_timestamp (
    const Complex1024 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Complex1024DataWriter_impl::get_key_value (
    Complex1024 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Complex1024 DataReader_impl Object Body

TP_Test::Complex1024DataReader_impl::Complex1024DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex1024DataReader_impl::~Complex1024DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Complex1024DataReader_impl::read (
    TP_Test::Complex1024Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex1024DataReader_impl::take (
    TP_Test::Complex1024Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex1024DataReader_impl::read_w_condition (
    TP_Test::Complex1024Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex1024DataReader_impl::take_w_condition (
    TP_Test::Complex1024Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex1024DataReader_impl::read_next_sample (
    TP_Test::Complex1024 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Complex1024DataReader_impl::take_next_sample (
    TP_Test::Complex1024 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Complex1024DataReader_impl::read_instance (
    TP_Test::Complex1024Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex1024DataReader_impl::take_instance (
    TP_Test::Complex1024Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex1024DataReader_impl::read_next_instance (
    TP_Test::Complex1024Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex1024DataReader_impl::take_next_instance (
    TP_Test::Complex1024Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex1024DataReader_impl::read_next_instance_w_condition (
    TP_Test::Complex1024Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex1024DataReader_impl::take_next_instance_w_condition (
    TP_Test::Complex1024Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Complex1024DataReader_impl::return_loan (
    TP_Test::Complex1024Seq & received_data,
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
                TP_Test::Complex1024Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Complex1024DataReader_impl::get_key_value (
    TP_Test::Complex1024 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Complex1024DataReader_impl::lookup_instance (
    const TP_Test::Complex1024 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Complex1024DataReader_impl::check_preconditions(
    TP_Test::Complex1024Seq & received_data,
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
__TP_Test_Complex2048__copyIn(
    c_base base,
    struct TP_Test::Complex2048 *from,
    struct _TP_Test_Complex2048 *to
);

extern void
__TP_Test_Complex2048__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Complex2048 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Complex2048TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex2048DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Complex2048TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex2048DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Complex2048 TypeSupport Object Body

TP_Test::Complex2048TypeSupport::Complex2048TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Complex2048__name(),
        __TP_Test_Complex2048__keys(),
        TP_Test::Complex2048TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Complex2048__copyIn,
        (gapi_copyOut) __TP_Test_Complex2048__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Complex2048Seq, TP_Test::Complex2048>,
        new  TP_Test::Complex2048TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Complex2048TypeSupport::~Complex2048TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Complex2048TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Complex2048TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Complex2048 DataWriter_impl Object Body

TP_Test::Complex2048DataWriter_impl::Complex2048DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex2048DataWriter_impl::~Complex2048DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Complex2048DataWriter_impl::register_instance (
    const TP_Test::Complex2048 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Complex2048DataWriter_impl::register_instance_w_timestamp (
    const Complex2048 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Complex2048DataWriter_impl::unregister_instance (
    const TP_Test::Complex2048 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Complex2048DataWriter_impl::unregister_instance_w_timestamp (
    const Complex2048 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex2048DataWriter_impl::write (
    const TP_Test::Complex2048 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Complex2048DataWriter_impl::write_w_timestamp (
    const Complex2048 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex2048DataWriter_impl::dispose (
    const TP_Test::Complex2048 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Complex2048DataWriter_impl::dispose_w_timestamp (
    const Complex2048 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Complex2048DataWriter_impl::get_key_value (
    Complex2048 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Complex2048 DataReader_impl Object Body

TP_Test::Complex2048DataReader_impl::Complex2048DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex2048DataReader_impl::~Complex2048DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Complex2048DataReader_impl::read (
    TP_Test::Complex2048Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex2048DataReader_impl::take (
    TP_Test::Complex2048Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex2048DataReader_impl::read_w_condition (
    TP_Test::Complex2048Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex2048DataReader_impl::take_w_condition (
    TP_Test::Complex2048Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex2048DataReader_impl::read_next_sample (
    TP_Test::Complex2048 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Complex2048DataReader_impl::take_next_sample (
    TP_Test::Complex2048 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Complex2048DataReader_impl::read_instance (
    TP_Test::Complex2048Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex2048DataReader_impl::take_instance (
    TP_Test::Complex2048Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex2048DataReader_impl::read_next_instance (
    TP_Test::Complex2048Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex2048DataReader_impl::take_next_instance (
    TP_Test::Complex2048Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex2048DataReader_impl::read_next_instance_w_condition (
    TP_Test::Complex2048Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex2048DataReader_impl::take_next_instance_w_condition (
    TP_Test::Complex2048Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Complex2048DataReader_impl::return_loan (
    TP_Test::Complex2048Seq & received_data,
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
                TP_Test::Complex2048Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Complex2048DataReader_impl::get_key_value (
    TP_Test::Complex2048 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Complex2048DataReader_impl::lookup_instance (
    const TP_Test::Complex2048 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Complex2048DataReader_impl::check_preconditions(
    TP_Test::Complex2048Seq & received_data,
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
__TP_Test_Complex4096__copyIn(
    c_base base,
    struct TP_Test::Complex4096 *from,
    struct _TP_Test_Complex4096 *to
);

extern void
__TP_Test_Complex4096__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Complex4096 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Complex4096TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex4096DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Complex4096TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex4096DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Complex4096 TypeSupport Object Body

TP_Test::Complex4096TypeSupport::Complex4096TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Complex4096__name(),
        __TP_Test_Complex4096__keys(),
        TP_Test::Complex4096TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Complex4096__copyIn,
        (gapi_copyOut) __TP_Test_Complex4096__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Complex4096Seq, TP_Test::Complex4096>,
        new  TP_Test::Complex4096TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Complex4096TypeSupport::~Complex4096TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Complex4096TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Complex4096TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Complex4096 DataWriter_impl Object Body

TP_Test::Complex4096DataWriter_impl::Complex4096DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex4096DataWriter_impl::~Complex4096DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Complex4096DataWriter_impl::register_instance (
    const TP_Test::Complex4096 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Complex4096DataWriter_impl::register_instance_w_timestamp (
    const Complex4096 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Complex4096DataWriter_impl::unregister_instance (
    const TP_Test::Complex4096 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Complex4096DataWriter_impl::unregister_instance_w_timestamp (
    const Complex4096 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex4096DataWriter_impl::write (
    const TP_Test::Complex4096 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Complex4096DataWriter_impl::write_w_timestamp (
    const Complex4096 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex4096DataWriter_impl::dispose (
    const TP_Test::Complex4096 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Complex4096DataWriter_impl::dispose_w_timestamp (
    const Complex4096 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Complex4096DataWriter_impl::get_key_value (
    Complex4096 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Complex4096 DataReader_impl Object Body

TP_Test::Complex4096DataReader_impl::Complex4096DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex4096DataReader_impl::~Complex4096DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Complex4096DataReader_impl::read (
    TP_Test::Complex4096Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex4096DataReader_impl::take (
    TP_Test::Complex4096Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex4096DataReader_impl::read_w_condition (
    TP_Test::Complex4096Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex4096DataReader_impl::take_w_condition (
    TP_Test::Complex4096Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex4096DataReader_impl::read_next_sample (
    TP_Test::Complex4096 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Complex4096DataReader_impl::take_next_sample (
    TP_Test::Complex4096 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Complex4096DataReader_impl::read_instance (
    TP_Test::Complex4096Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex4096DataReader_impl::take_instance (
    TP_Test::Complex4096Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex4096DataReader_impl::read_next_instance (
    TP_Test::Complex4096Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex4096DataReader_impl::take_next_instance (
    TP_Test::Complex4096Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex4096DataReader_impl::read_next_instance_w_condition (
    TP_Test::Complex4096Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex4096DataReader_impl::take_next_instance_w_condition (
    TP_Test::Complex4096Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Complex4096DataReader_impl::return_loan (
    TP_Test::Complex4096Seq & received_data,
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
                TP_Test::Complex4096Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Complex4096DataReader_impl::get_key_value (
    TP_Test::Complex4096 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Complex4096DataReader_impl::lookup_instance (
    const TP_Test::Complex4096 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Complex4096DataReader_impl::check_preconditions(
    TP_Test::Complex4096Seq & received_data,
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
__TP_Test_Complex8192__copyIn(
    c_base base,
    struct TP_Test::Complex8192 *from,
    struct _TP_Test_Complex8192 *to
);

extern void
__TP_Test_Complex8192__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Complex8192 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Complex8192TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex8192DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Complex8192TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex8192DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Complex8192 TypeSupport Object Body

TP_Test::Complex8192TypeSupport::Complex8192TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Complex8192__name(),
        __TP_Test_Complex8192__keys(),
        TP_Test::Complex8192TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Complex8192__copyIn,
        (gapi_copyOut) __TP_Test_Complex8192__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Complex8192Seq, TP_Test::Complex8192>,
        new  TP_Test::Complex8192TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Complex8192TypeSupport::~Complex8192TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Complex8192TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Complex8192TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Complex8192 DataWriter_impl Object Body

TP_Test::Complex8192DataWriter_impl::Complex8192DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex8192DataWriter_impl::~Complex8192DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Complex8192DataWriter_impl::register_instance (
    const TP_Test::Complex8192 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Complex8192DataWriter_impl::register_instance_w_timestamp (
    const Complex8192 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Complex8192DataWriter_impl::unregister_instance (
    const TP_Test::Complex8192 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Complex8192DataWriter_impl::unregister_instance_w_timestamp (
    const Complex8192 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex8192DataWriter_impl::write (
    const TP_Test::Complex8192 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Complex8192DataWriter_impl::write_w_timestamp (
    const Complex8192 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex8192DataWriter_impl::dispose (
    const TP_Test::Complex8192 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Complex8192DataWriter_impl::dispose_w_timestamp (
    const Complex8192 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Complex8192DataWriter_impl::get_key_value (
    Complex8192 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Complex8192 DataReader_impl Object Body

TP_Test::Complex8192DataReader_impl::Complex8192DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex8192DataReader_impl::~Complex8192DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Complex8192DataReader_impl::read (
    TP_Test::Complex8192Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex8192DataReader_impl::take (
    TP_Test::Complex8192Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex8192DataReader_impl::read_w_condition (
    TP_Test::Complex8192Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex8192DataReader_impl::take_w_condition (
    TP_Test::Complex8192Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex8192DataReader_impl::read_next_sample (
    TP_Test::Complex8192 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Complex8192DataReader_impl::take_next_sample (
    TP_Test::Complex8192 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Complex8192DataReader_impl::read_instance (
    TP_Test::Complex8192Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex8192DataReader_impl::take_instance (
    TP_Test::Complex8192Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex8192DataReader_impl::read_next_instance (
    TP_Test::Complex8192Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex8192DataReader_impl::take_next_instance (
    TP_Test::Complex8192Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex8192DataReader_impl::read_next_instance_w_condition (
    TP_Test::Complex8192Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex8192DataReader_impl::take_next_instance_w_condition (
    TP_Test::Complex8192Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Complex8192DataReader_impl::return_loan (
    TP_Test::Complex8192Seq & received_data,
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
                TP_Test::Complex8192Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Complex8192DataReader_impl::get_key_value (
    TP_Test::Complex8192 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Complex8192DataReader_impl::lookup_instance (
    const TP_Test::Complex8192 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Complex8192DataReader_impl::check_preconditions(
    TP_Test::Complex8192Seq & received_data,
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
__TP_Test_Complex16384__copyIn(
    c_base base,
    struct TP_Test::Complex16384 *from,
    struct _TP_Test_Complex16384 *to
);

extern void
__TP_Test_Complex16384__copyOut(
    void *_from,
    void *_to
);

// DDS TP_Test::Complex16384 TypeSupportFactory Object Body

DDS::DataWriter_ptr 
TP_Test::Complex16384TypeSupportFactory::create_datawriter (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex16384DataWriter_impl(handle, statusConditionData);
};

DDS::DataReader_ptr 
TP_Test::Complex16384TypeSupportFactory::create_datareader (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
)
{
    return new TP_Test::Complex16384DataReader_impl (handle, statusConditionData);
};

// DDS TP_Test::Complex16384 TypeSupport Object Body

TP_Test::Complex16384TypeSupport::Complex16384TypeSupport (void) :
    TypeSupport_impl(
        __TP_Test_Complex16384__name(),
        __TP_Test_Complex16384__keys(),
        TP_Test::Complex16384TypeSupport::metaDescriptor,
        (gapi_copyIn) __TP_Test_Complex16384__copyIn,
        (gapi_copyOut) __TP_Test_Complex16384__copyOut,
        (gapi_readerCopy) DDS::ccpp_DataReaderCopy<TP_Test::Complex16384Seq, TP_Test::Complex16384>,
        new  TP_Test::Complex16384TypeSupportFactory()
    )
{
    // Parent constructor takes care of everything.
};

TP_Test::Complex16384TypeSupport::~Complex16384TypeSupport (void)
{
    // Parent destructor takes care of everything.
}

DDS::ReturnCode_t
TP_Test::Complex16384TypeSupport::register_type (
    DDS::DomainParticipant_ptr domain,
    const char * type_name
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::register_type(domain, type_name);
}

char *
TP_Test::Complex16384TypeSupport::get_type_name (
) THROW_ORB_EXCEPTIONS
{
    return TypeSupport_impl::get_type_name();
}

// DDS TP_Test::Complex16384 DataWriter_impl Object Body

TP_Test::Complex16384DataWriter_impl::Complex16384DataWriter_impl (
    gapi_dataWriter handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataWriter_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex16384DataWriter_impl::~Complex16384DataWriter_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::InstanceHandle_t
TP_Test::Complex16384DataWriter_impl::register_instance (
    const TP_Test::Complex16384 & instance_data
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance(&instance_data);
};

DDS::InstanceHandle_t 
TP_Test::Complex16384DataWriter_impl::register_instance_w_timestamp (
    const Complex16384 & instance_data,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::register_instance_w_timestamp(&instance_data, source_timestamp);
}


DDS::ReturnCode_t
TP_Test::Complex16384DataWriter_impl::unregister_instance (
    const TP_Test::Complex16384 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance(&instance_data, handle);    
}


DDS::ReturnCode_t 
TP_Test::Complex16384DataWriter_impl::unregister_instance_w_timestamp (
    const Complex16384 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::unregister_instance_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex16384DataWriter_impl::write (
    const TP_Test::Complex16384 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write(&instance_data, handle);
}


DDS::ReturnCode_t
TP_Test::Complex16384DataWriter_impl::write_w_timestamp (
    const Complex16384 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::write_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t
TP_Test::Complex16384DataWriter_impl::dispose (
    const TP_Test::Complex16384 & instance_data,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose(&instance_data, handle);
}


DDS::ReturnCode_t 
TP_Test::Complex16384DataWriter_impl::dispose_w_timestamp (
    const Complex16384 & instance_data,
    DDS::InstanceHandle_t handle,
    const DDS::Time_t & source_timestamp
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::dispose_w_timestamp(&instance_data, handle, source_timestamp);    
}


DDS::ReturnCode_t 
TP_Test::Complex16384DataWriter_impl::get_key_value (
    Complex16384 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataWriter_impl::get_key_value(&key_holder, handle);
}


// DDS TP_Test::Complex16384 DataReader_impl Object Body

TP_Test::Complex16384DataReader_impl::Complex16384DataReader_impl (
    gapi_dataReader handle,
    DDS::ccpp_UserData_ptr &statusConditionData
) : DDS::DataReader_impl(handle, statusConditionData)
{
    // Parent constructor takes care of everything.
}

TP_Test::Complex16384DataReader_impl::~Complex16384DataReader_impl (void)
{
    // Parent destructor takes care of everything.
}


DDS::ReturnCode_t
TP_Test::Complex16384DataReader_impl::read (
    TP_Test::Complex16384Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex16384DataReader_impl::take (
    TP_Test::Complex16384Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex16384DataReader_impl::read_w_condition (
    TP_Test::Complex16384Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex16384DataReader_impl::take_w_condition (
    TP_Test::Complex16384Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex16384DataReader_impl::read_next_sample (
    TP_Test::Complex16384 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::read_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t 
TP_Test::Complex16384DataReader_impl::take_next_sample (
    TP_Test::Complex16384 & received_data,
    DDS::SampleInfo & sample_info
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::take_next_sample( &received_data, sample_info);
}


DDS::ReturnCode_t
TP_Test::Complex16384DataReader_impl::read_instance (
    TP_Test::Complex16384Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex16384DataReader_impl::take_instance (
    TP_Test::Complex16384Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex16384DataReader_impl::read_next_instance (
    TP_Test::Complex16384Seq & received_data,
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

DDS::ReturnCode_t
TP_Test::Complex16384DataReader_impl::take_next_instance (
    TP_Test::Complex16384Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex16384DataReader_impl::read_next_instance_w_condition (
    TP_Test::Complex16384Seq & received_data,
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


DDS::ReturnCode_t 
TP_Test::Complex16384DataReader_impl::take_next_instance_w_condition (
    TP_Test::Complex16384Seq & received_data,
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


DDS::ReturnCode_t
TP_Test::Complex16384DataReader_impl::return_loan (
    TP_Test::Complex16384Seq & received_data,
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
                TP_Test::Complex16384Seq::freebuf( received_data.get_buffer(true) );
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


DDS::ReturnCode_t 
TP_Test::Complex16384DataReader_impl::get_key_value (
    TP_Test::Complex16384 & key_holder,
    DDS::InstanceHandle_t handle
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::get_key_value( &key_holder, handle);
}

DDS::InstanceHandle_t 
TP_Test::Complex16384DataReader_impl::lookup_instance (
    const TP_Test::Complex16384 & instance
) THROW_ORB_EXCEPTIONS
{
    return DataReader_impl::lookup_instance(&instance);
}

DDS::ReturnCode_t 
TP_Test::Complex16384DataReader_impl::check_preconditions(
    TP_Test::Complex16384Seq & received_data,
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
const char * TP_Test::QuitMsgTypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"QuitMsg\"><Member name=\"quit\"><Boolean/></Member></Struct></Module></MetaData>";
const char * TP_Test::Bytes4TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes4Sequence\"><Sequence size=\"4\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes4\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes4Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Bytes8TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes8Sequence\"><Sequence size=\"8\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes8\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes8Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Bytes16TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes16Sequence\"><Sequence size=\"16\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes16\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes16Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Bytes32TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes32Sequence\"><Sequence size=\"32\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes32\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes32Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Bytes64TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes64Sequence\"><Sequence size=\"64\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes64\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes64Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Bytes128TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes128Sequence\"><Sequence size=\"128\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes128\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes128Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Bytes256TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes256Sequence\"><Sequence size=\"256\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes256\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes256Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Bytes512TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes512Sequence\"><Sequence size=\"512\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes512\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes512Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Bytes1024TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes1024Sequence\"><Sequence size=\"1024\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes1024\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes1024Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Bytes2048TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes2048Sequence\"><Sequence size=\"2048\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes2048\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes2048Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Bytes4096TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes4096Sequence\"><Sequence size=\"4096\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes4096\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes4096Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Bytes8192TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes8192Sequence\"><Sequence size=\"8192\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes8192\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes8192Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Bytes16384TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><TypeDef name=\"Bytes16384Sequence\"><Sequence size=\"16384\"><Octet/></Sequence></TypeDef><Struct name=\"Bytes16384\"><Member name=\"timestamp\"><ULong/></Member><Member name=\"data\"><Type name=\"TP_Test::Bytes16384Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Complex4TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSequence\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSequence\"/></Member></Struct><TypeDef name=\"Complex4Sequence\"><Sequence size=\"4\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex4\"><Member name=\"data\"><Type name=\"TP_Test::Complex4Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Complex8TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSequence\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSequence\"/></Member></Struct><TypeDef name=\"Complex8Sequence\"><Sequence size=\"8\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex8\"><Member name=\"data\"><Type name=\"TP_Test::Complex8Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Complex16TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSequence\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSequence\"/></Member></Struct><TypeDef name=\"Complex16Sequence\"><Sequence size=\"16\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex16\"><Member name=\"data\"><Type name=\"TP_Test::Complex16Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Complex32TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSequence\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSequence\"/></Member></Struct><TypeDef name=\"Complex32Sequence\"><Sequence size=\"32\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex32\"><Member name=\"data\"><Type name=\"TP_Test::Complex32Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Complex64TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSequence\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSequence\"/></Member></Struct><TypeDef name=\"Complex64Sequence\"><Sequence size=\"64\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex64\"><Member name=\"data\"><Type name=\"TP_Test::Complex64Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Complex128TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSequence\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSequence\"/></Member></Struct><TypeDef name=\"Complex128Sequence\"><Sequence size=\"128\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex128\"><Member name=\"data\"><Type name=\"TP_Test::Complex128Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Complex256TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSequence\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSequence\"/></Member></Struct><TypeDef name=\"Complex256Sequence\"><Sequence size=\"256\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex256\"><Member name=\"data\"><Type name=\"TP_Test::Complex256Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Complex512TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSequence\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSequence\"/></Member></Struct><TypeDef name=\"Complex512Sequence\"><Sequence size=\"512\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex512\"><Member name=\"data\"><Type name=\"TP_Test::Complex512Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Complex1024TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSequence\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSequence\"/></Member></Struct><TypeDef name=\"Complex1024Sequence\"><Sequence size=\"1024\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex1024\"><Member name=\"data\"><Type name=\"TP_Test::Complex1024Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Complex2048TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSequence\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSequence\"/></Member></Struct><TypeDef name=\"Complex2048Sequence\"><Sequence size=\"2048\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex2048\"><Member name=\"data\"><Type name=\"TP_Test::Complex2048Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Complex4096TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSequence\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSequence\"/></Member></Struct><TypeDef name=\"Complex4096Sequence\"><Sequence size=\"4096\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex4096\"><Member name=\"data\"><Type name=\"TP_Test::Complex4096Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Complex8192TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSequence\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSequence\"/></Member></Struct><TypeDef name=\"Complex8192Sequence\"><Sequence size=\"8192\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex8192\"><Member name=\"data\"><Type name=\"TP_Test::Complex8192Sequence\"/></Member></Struct></Module></MetaData>";
const char * TP_Test::Complex16384TypeSupport::metaDescriptor = "<MetaData version=\"1.0.0\"><Module name=\"TP_Test\"><Struct name=\"Nested\"><Member name=\"info\"><String/></Member><Member name=\"index\"><Long/></Member></Struct><TypeDef name=\"NestedSequence\"><Sequence><Type name=\"TP_Test::Nested\"/></Sequence></TypeDef><Struct name=\"Outer\"><Member name=\"length\"><Long/></Member><Member name=\"nested_member\"><Type name=\"TP_Test::NestedSequence\"/></Member></Struct><TypeDef name=\"Complex16384Sequence\"><Sequence size=\"16384\"><Type name=\"TP_Test::Outer\"/></Sequence></TypeDef><Struct name=\"Complex16384\"><Member name=\"data\"><Type name=\"TP_Test::Complex16384Sequence\"/></Member></Struct></Module></MetaData>";
