#ifndef DEEPTYPESDCPS_IMPL_H_
#define DEEPTYPESDCPS_IMPL_H_

#include "ccpp.h"
#include "ccpp_deepTypes.h"
#include "ccpp_TypeSupport_impl.h"
#include "ccpp_DataWriter_impl.h"
#include "ccpp_DataReader_impl.h"
#include "os_if.h"

#ifndef DDS_API
#define DDS_API
#endif

namespace deepTypes {

    class DDS_API simpleTypeTypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        simpleTypeTypeSupportFactory() {};
        virtual ~simpleTypeTypeSupportFactory() {};
    private:
        ::DDS::DataWriter_ptr 
        create_datawriter (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        ::DDS::DataReader_ptr 
        create_datareader (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    };
    
    class DDS_API simpleTypeTypeSupport : public virtual simpleTypeTypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        simpleTypeTypeSupport (void);
        virtual ~simpleTypeTypeSupport (void);
    
    private:
        simpleTypeTypeSupport (const simpleTypeTypeSupport &);
        void operator= (const simpleTypeTypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef simpleTypeTypeSupportInterface_var simpleTypeTypeSupport_var;
    typedef simpleTypeTypeSupportInterface_ptr simpleTypeTypeSupport_ptr;
    
    class DDS_API simpleTypeDataWriter_impl : public virtual simpleTypeDataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const simpleType & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const simpleType & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const simpleType & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const simpleType & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const simpleType & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const simpleType & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const simpleType & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const simpleType & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            simpleType & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        simpleTypeDataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~simpleTypeDataWriter_impl (void);
    
    private:
        simpleTypeDataWriter_impl (const simpleTypeDataWriter_impl &);
        void operator= (const simpleTypeDataWriter &);
    };
    
    class DDS_API simpleTypeDataReader_impl : public virtual simpleTypeDataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            simpleTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            simpleTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            simpleTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            simpleTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            simpleType & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            simpleType & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            simpleTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            simpleTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            simpleTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            simpleTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            simpleTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            simpleTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            simpleTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            simpleType & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const simpleType & instance
        ) THROW_ORB_EXCEPTIONS;
    
        simpleTypeDataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~simpleTypeDataReader_impl (void);
    
    private:
        simpleTypeDataReader_impl (const simpleTypeDataReader &);
        void operator= (const simpleTypeDataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            simpleTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class DDS_API nestedTypeTypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        nestedTypeTypeSupportFactory() {};
        virtual ~nestedTypeTypeSupportFactory() {};
    private:
        ::DDS::DataWriter_ptr 
        create_datawriter (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        ::DDS::DataReader_ptr 
        create_datareader (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    };
    
    class DDS_API nestedTypeTypeSupport : public virtual nestedTypeTypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        nestedTypeTypeSupport (void);
        virtual ~nestedTypeTypeSupport (void);
    
    private:
        nestedTypeTypeSupport (const nestedTypeTypeSupport &);
        void operator= (const nestedTypeTypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef nestedTypeTypeSupportInterface_var nestedTypeTypeSupport_var;
    typedef nestedTypeTypeSupportInterface_ptr nestedTypeTypeSupport_ptr;
    
    class DDS_API nestedTypeDataWriter_impl : public virtual nestedTypeDataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const nestedType & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const nestedType & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const nestedType & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const nestedType & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const nestedType & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const nestedType & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const nestedType & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const nestedType & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            nestedType & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        nestedTypeDataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~nestedTypeDataWriter_impl (void);
    
    private:
        nestedTypeDataWriter_impl (const nestedTypeDataWriter_impl &);
        void operator= (const nestedTypeDataWriter &);
    };
    
    class DDS_API nestedTypeDataReader_impl : public virtual nestedTypeDataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            nestedTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            nestedTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            nestedTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            nestedTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            nestedType & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            nestedType & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            nestedTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            nestedTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            nestedTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            nestedTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            nestedTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            nestedTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            nestedTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            nestedType & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const nestedType & instance
        ) THROW_ORB_EXCEPTIONS;
    
        nestedTypeDataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~nestedTypeDataReader_impl (void);
    
    private:
        nestedTypeDataReader_impl (const nestedTypeDataReader &);
        void operator= (const nestedTypeDataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            nestedTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class DDS_API arrayTypeTypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        arrayTypeTypeSupportFactory() {};
        virtual ~arrayTypeTypeSupportFactory() {};
    private:
        ::DDS::DataWriter_ptr 
        create_datawriter (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        ::DDS::DataReader_ptr 
        create_datareader (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    };
    
    class DDS_API arrayTypeTypeSupport : public virtual arrayTypeTypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        arrayTypeTypeSupport (void);
        virtual ~arrayTypeTypeSupport (void);
    
    private:
        arrayTypeTypeSupport (const arrayTypeTypeSupport &);
        void operator= (const arrayTypeTypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef arrayTypeTypeSupportInterface_var arrayTypeTypeSupport_var;
    typedef arrayTypeTypeSupportInterface_ptr arrayTypeTypeSupport_ptr;
    
    class DDS_API arrayTypeDataWriter_impl : public virtual arrayTypeDataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const arrayType & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const arrayType & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const arrayType & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const arrayType & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const arrayType & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const arrayType & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const arrayType & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const arrayType & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            arrayType & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        arrayTypeDataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~arrayTypeDataWriter_impl (void);
    
    private:
        arrayTypeDataWriter_impl (const arrayTypeDataWriter_impl &);
        void operator= (const arrayTypeDataWriter &);
    };
    
    class DDS_API arrayTypeDataReader_impl : public virtual arrayTypeDataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            arrayTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            arrayTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            arrayTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            arrayTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            arrayType & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            arrayType & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            arrayTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            arrayTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            arrayTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            arrayTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            arrayTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            arrayTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            arrayTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            arrayType & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const arrayType & instance
        ) THROW_ORB_EXCEPTIONS;
    
        arrayTypeDataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~arrayTypeDataReader_impl (void);
    
    private:
        arrayTypeDataReader_impl (const arrayTypeDataReader &);
        void operator= (const arrayTypeDataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            arrayTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class DDS_API stringTypeTypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        stringTypeTypeSupportFactory() {};
        virtual ~stringTypeTypeSupportFactory() {};
    private:
        ::DDS::DataWriter_ptr 
        create_datawriter (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        ::DDS::DataReader_ptr 
        create_datareader (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    };
    
    class DDS_API stringTypeTypeSupport : public virtual stringTypeTypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        stringTypeTypeSupport (void);
        virtual ~stringTypeTypeSupport (void);
    
    private:
        stringTypeTypeSupport (const stringTypeTypeSupport &);
        void operator= (const stringTypeTypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef stringTypeTypeSupportInterface_var stringTypeTypeSupport_var;
    typedef stringTypeTypeSupportInterface_ptr stringTypeTypeSupport_ptr;
    
    class DDS_API stringTypeDataWriter_impl : public virtual stringTypeDataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const stringType & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const stringType & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const stringType & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const stringType & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const stringType & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const stringType & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const stringType & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const stringType & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            stringType & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        stringTypeDataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~stringTypeDataWriter_impl (void);
    
    private:
        stringTypeDataWriter_impl (const stringTypeDataWriter_impl &);
        void operator= (const stringTypeDataWriter &);
    };
    
    class DDS_API stringTypeDataReader_impl : public virtual stringTypeDataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            stringTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            stringTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            stringTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            stringTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            stringType & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            stringType & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            stringTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            stringTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            stringTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            stringTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            stringTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            stringTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            stringTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            stringType & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const stringType & instance
        ) THROW_ORB_EXCEPTIONS;
    
        stringTypeDataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~stringTypeDataReader_impl (void);
    
    private:
        stringTypeDataReader_impl (const stringTypeDataReader &);
        void operator= (const stringTypeDataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            stringTypeSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
}

#endif
