#ifndef TPTDEFDCPS_IMPL_H_
#define TPTDEFDCPS_IMPL_H_

#include "ccpp.h"
#include "ccpp_TPTDef.h"
#include "ccpp_TypeSupport_impl.h"
#include "ccpp_DataWriter_impl.h"
#include "ccpp_DataReader_impl.h"

namespace TP_Test {

    class QuitMsgTypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        QuitMsgTypeSupportFactory() {};
        virtual ~QuitMsgTypeSupportFactory() {};
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
    
    class QuitMsgTypeSupport : public virtual QuitMsgTypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        QuitMsgTypeSupport (void);
        virtual ~QuitMsgTypeSupport (void);
    
    private:
        QuitMsgTypeSupport (const QuitMsgTypeSupport &);
        void operator= (const QuitMsgTypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef QuitMsgTypeSupportInterface_var QuitMsgTypeSupport_var;
    typedef QuitMsgTypeSupportInterface_ptr QuitMsgTypeSupport_ptr;
    
    class  QuitMsgDataWriter_impl : public virtual QuitMsgDataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const QuitMsg & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const QuitMsg & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const QuitMsg & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const QuitMsg & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const QuitMsg & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const QuitMsg & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const QuitMsg & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const QuitMsg & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            QuitMsg & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        QuitMsgDataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~QuitMsgDataWriter_impl (void);
    
    private:
        QuitMsgDataWriter_impl (const QuitMsgDataWriter_impl &);
        void operator= (const QuitMsgDataWriter &);
    };
    
    class  QuitMsgDataReader_impl : public virtual QuitMsgDataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            QuitMsgSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            QuitMsgSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            QuitMsgSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            QuitMsgSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            QuitMsg & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            QuitMsg & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            QuitMsgSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            QuitMsgSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            QuitMsgSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            QuitMsgSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            QuitMsgSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            QuitMsgSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            QuitMsgSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            QuitMsg & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const QuitMsg & instance
        ) THROW_ORB_EXCEPTIONS;
    
        QuitMsgDataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~QuitMsgDataReader_impl (void);
    
    private:
        QuitMsgDataReader_impl (const QuitMsgDataReader &);
        void operator= (const QuitMsgDataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            QuitMsgSeq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Bytes4TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Bytes4TypeSupportFactory() {};
        virtual ~Bytes4TypeSupportFactory() {};
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
    
    class Bytes4TypeSupport : public virtual Bytes4TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Bytes4TypeSupport (void);
        virtual ~Bytes4TypeSupport (void);
    
    private:
        Bytes4TypeSupport (const Bytes4TypeSupport &);
        void operator= (const Bytes4TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Bytes4TypeSupportInterface_var Bytes4TypeSupport_var;
    typedef Bytes4TypeSupportInterface_ptr Bytes4TypeSupport_ptr;
    
    class  Bytes4DataWriter_impl : public virtual Bytes4DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Bytes4 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Bytes4 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Bytes4 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Bytes4 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Bytes4 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Bytes4 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Bytes4 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Bytes4 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes4 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes4DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes4DataWriter_impl (void);
    
    private:
        Bytes4DataWriter_impl (const Bytes4DataWriter_impl &);
        void operator= (const Bytes4DataWriter &);
    };
    
    class  Bytes4DataReader_impl : public virtual Bytes4DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Bytes4Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Bytes4Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Bytes4Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Bytes4Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Bytes4 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Bytes4 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Bytes4Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Bytes4Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Bytes4Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Bytes4Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Bytes4Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Bytes4Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Bytes4Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes4 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Bytes4 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes4DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes4DataReader_impl (void);
    
    private:
        Bytes4DataReader_impl (const Bytes4DataReader &);
        void operator= (const Bytes4DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Bytes4Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Bytes8TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Bytes8TypeSupportFactory() {};
        virtual ~Bytes8TypeSupportFactory() {};
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
    
    class Bytes8TypeSupport : public virtual Bytes8TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Bytes8TypeSupport (void);
        virtual ~Bytes8TypeSupport (void);
    
    private:
        Bytes8TypeSupport (const Bytes8TypeSupport &);
        void operator= (const Bytes8TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Bytes8TypeSupportInterface_var Bytes8TypeSupport_var;
    typedef Bytes8TypeSupportInterface_ptr Bytes8TypeSupport_ptr;
    
    class  Bytes8DataWriter_impl : public virtual Bytes8DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Bytes8 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Bytes8 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Bytes8 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Bytes8 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Bytes8 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Bytes8 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Bytes8 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Bytes8 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes8 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes8DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes8DataWriter_impl (void);
    
    private:
        Bytes8DataWriter_impl (const Bytes8DataWriter_impl &);
        void operator= (const Bytes8DataWriter &);
    };
    
    class  Bytes8DataReader_impl : public virtual Bytes8DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Bytes8Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Bytes8Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Bytes8Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Bytes8Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Bytes8 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Bytes8 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Bytes8Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Bytes8Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Bytes8Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Bytes8Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Bytes8Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Bytes8Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Bytes8Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes8 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Bytes8 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes8DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes8DataReader_impl (void);
    
    private:
        Bytes8DataReader_impl (const Bytes8DataReader &);
        void operator= (const Bytes8DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Bytes8Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Bytes16TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Bytes16TypeSupportFactory() {};
        virtual ~Bytes16TypeSupportFactory() {};
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
    
    class Bytes16TypeSupport : public virtual Bytes16TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Bytes16TypeSupport (void);
        virtual ~Bytes16TypeSupport (void);
    
    private:
        Bytes16TypeSupport (const Bytes16TypeSupport &);
        void operator= (const Bytes16TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Bytes16TypeSupportInterface_var Bytes16TypeSupport_var;
    typedef Bytes16TypeSupportInterface_ptr Bytes16TypeSupport_ptr;
    
    class  Bytes16DataWriter_impl : public virtual Bytes16DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Bytes16 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Bytes16 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Bytes16 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Bytes16 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Bytes16 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Bytes16 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Bytes16 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Bytes16 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes16 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes16DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes16DataWriter_impl (void);
    
    private:
        Bytes16DataWriter_impl (const Bytes16DataWriter_impl &);
        void operator= (const Bytes16DataWriter &);
    };
    
    class  Bytes16DataReader_impl : public virtual Bytes16DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Bytes16Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Bytes16Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Bytes16Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Bytes16Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Bytes16 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Bytes16 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Bytes16Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Bytes16Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Bytes16Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Bytes16Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Bytes16Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Bytes16Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Bytes16Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes16 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Bytes16 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes16DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes16DataReader_impl (void);
    
    private:
        Bytes16DataReader_impl (const Bytes16DataReader &);
        void operator= (const Bytes16DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Bytes16Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Bytes32TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Bytes32TypeSupportFactory() {};
        virtual ~Bytes32TypeSupportFactory() {};
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
    
    class Bytes32TypeSupport : public virtual Bytes32TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Bytes32TypeSupport (void);
        virtual ~Bytes32TypeSupport (void);
    
    private:
        Bytes32TypeSupport (const Bytes32TypeSupport &);
        void operator= (const Bytes32TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Bytes32TypeSupportInterface_var Bytes32TypeSupport_var;
    typedef Bytes32TypeSupportInterface_ptr Bytes32TypeSupport_ptr;
    
    class  Bytes32DataWriter_impl : public virtual Bytes32DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Bytes32 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Bytes32 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Bytes32 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Bytes32 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Bytes32 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Bytes32 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Bytes32 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Bytes32 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes32 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes32DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes32DataWriter_impl (void);
    
    private:
        Bytes32DataWriter_impl (const Bytes32DataWriter_impl &);
        void operator= (const Bytes32DataWriter &);
    };
    
    class  Bytes32DataReader_impl : public virtual Bytes32DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Bytes32Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Bytes32Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Bytes32Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Bytes32Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Bytes32 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Bytes32 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Bytes32Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Bytes32Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Bytes32Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Bytes32Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Bytes32Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Bytes32Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Bytes32Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes32 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Bytes32 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes32DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes32DataReader_impl (void);
    
    private:
        Bytes32DataReader_impl (const Bytes32DataReader &);
        void operator= (const Bytes32DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Bytes32Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Bytes64TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Bytes64TypeSupportFactory() {};
        virtual ~Bytes64TypeSupportFactory() {};
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
    
    class Bytes64TypeSupport : public virtual Bytes64TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Bytes64TypeSupport (void);
        virtual ~Bytes64TypeSupport (void);
    
    private:
        Bytes64TypeSupport (const Bytes64TypeSupport &);
        void operator= (const Bytes64TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Bytes64TypeSupportInterface_var Bytes64TypeSupport_var;
    typedef Bytes64TypeSupportInterface_ptr Bytes64TypeSupport_ptr;
    
    class  Bytes64DataWriter_impl : public virtual Bytes64DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Bytes64 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Bytes64 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Bytes64 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Bytes64 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Bytes64 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Bytes64 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Bytes64 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Bytes64 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes64 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes64DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes64DataWriter_impl (void);
    
    private:
        Bytes64DataWriter_impl (const Bytes64DataWriter_impl &);
        void operator= (const Bytes64DataWriter &);
    };
    
    class  Bytes64DataReader_impl : public virtual Bytes64DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Bytes64Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Bytes64Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Bytes64Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Bytes64Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Bytes64 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Bytes64 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Bytes64Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Bytes64Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Bytes64Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Bytes64Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Bytes64Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Bytes64Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Bytes64Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes64 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Bytes64 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes64DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes64DataReader_impl (void);
    
    private:
        Bytes64DataReader_impl (const Bytes64DataReader &);
        void operator= (const Bytes64DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Bytes64Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Bytes128TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Bytes128TypeSupportFactory() {};
        virtual ~Bytes128TypeSupportFactory() {};
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
    
    class Bytes128TypeSupport : public virtual Bytes128TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Bytes128TypeSupport (void);
        virtual ~Bytes128TypeSupport (void);
    
    private:
        Bytes128TypeSupport (const Bytes128TypeSupport &);
        void operator= (const Bytes128TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Bytes128TypeSupportInterface_var Bytes128TypeSupport_var;
    typedef Bytes128TypeSupportInterface_ptr Bytes128TypeSupport_ptr;
    
    class  Bytes128DataWriter_impl : public virtual Bytes128DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Bytes128 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Bytes128 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Bytes128 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Bytes128 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Bytes128 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Bytes128 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Bytes128 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Bytes128 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes128 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes128DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes128DataWriter_impl (void);
    
    private:
        Bytes128DataWriter_impl (const Bytes128DataWriter_impl &);
        void operator= (const Bytes128DataWriter &);
    };
    
    class  Bytes128DataReader_impl : public virtual Bytes128DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Bytes128Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Bytes128Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Bytes128Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Bytes128Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Bytes128 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Bytes128 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Bytes128Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Bytes128Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Bytes128Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Bytes128Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Bytes128Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Bytes128Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Bytes128Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes128 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Bytes128 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes128DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes128DataReader_impl (void);
    
    private:
        Bytes128DataReader_impl (const Bytes128DataReader &);
        void operator= (const Bytes128DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Bytes128Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Bytes256TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Bytes256TypeSupportFactory() {};
        virtual ~Bytes256TypeSupportFactory() {};
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
    
    class Bytes256TypeSupport : public virtual Bytes256TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Bytes256TypeSupport (void);
        virtual ~Bytes256TypeSupport (void);
    
    private:
        Bytes256TypeSupport (const Bytes256TypeSupport &);
        void operator= (const Bytes256TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Bytes256TypeSupportInterface_var Bytes256TypeSupport_var;
    typedef Bytes256TypeSupportInterface_ptr Bytes256TypeSupport_ptr;
    
    class  Bytes256DataWriter_impl : public virtual Bytes256DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Bytes256 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Bytes256 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Bytes256 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Bytes256 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Bytes256 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Bytes256 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Bytes256 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Bytes256 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes256 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes256DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes256DataWriter_impl (void);
    
    private:
        Bytes256DataWriter_impl (const Bytes256DataWriter_impl &);
        void operator= (const Bytes256DataWriter &);
    };
    
    class  Bytes256DataReader_impl : public virtual Bytes256DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Bytes256Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Bytes256Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Bytes256Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Bytes256Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Bytes256 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Bytes256 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Bytes256Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Bytes256Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Bytes256Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Bytes256Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Bytes256Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Bytes256Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Bytes256Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes256 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Bytes256 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes256DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes256DataReader_impl (void);
    
    private:
        Bytes256DataReader_impl (const Bytes256DataReader &);
        void operator= (const Bytes256DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Bytes256Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Bytes512TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Bytes512TypeSupportFactory() {};
        virtual ~Bytes512TypeSupportFactory() {};
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
    
    class Bytes512TypeSupport : public virtual Bytes512TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Bytes512TypeSupport (void);
        virtual ~Bytes512TypeSupport (void);
    
    private:
        Bytes512TypeSupport (const Bytes512TypeSupport &);
        void operator= (const Bytes512TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Bytes512TypeSupportInterface_var Bytes512TypeSupport_var;
    typedef Bytes512TypeSupportInterface_ptr Bytes512TypeSupport_ptr;
    
    class  Bytes512DataWriter_impl : public virtual Bytes512DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Bytes512 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Bytes512 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Bytes512 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Bytes512 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Bytes512 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Bytes512 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Bytes512 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Bytes512 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes512 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes512DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes512DataWriter_impl (void);
    
    private:
        Bytes512DataWriter_impl (const Bytes512DataWriter_impl &);
        void operator= (const Bytes512DataWriter &);
    };
    
    class  Bytes512DataReader_impl : public virtual Bytes512DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Bytes512Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Bytes512Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Bytes512Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Bytes512Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Bytes512 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Bytes512 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Bytes512Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Bytes512Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Bytes512Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Bytes512Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Bytes512Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Bytes512Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Bytes512Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes512 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Bytes512 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes512DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes512DataReader_impl (void);
    
    private:
        Bytes512DataReader_impl (const Bytes512DataReader &);
        void operator= (const Bytes512DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Bytes512Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Bytes1024TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Bytes1024TypeSupportFactory() {};
        virtual ~Bytes1024TypeSupportFactory() {};
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
    
    class Bytes1024TypeSupport : public virtual Bytes1024TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Bytes1024TypeSupport (void);
        virtual ~Bytes1024TypeSupport (void);
    
    private:
        Bytes1024TypeSupport (const Bytes1024TypeSupport &);
        void operator= (const Bytes1024TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Bytes1024TypeSupportInterface_var Bytes1024TypeSupport_var;
    typedef Bytes1024TypeSupportInterface_ptr Bytes1024TypeSupport_ptr;
    
    class  Bytes1024DataWriter_impl : public virtual Bytes1024DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Bytes1024 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Bytes1024 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Bytes1024 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Bytes1024 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Bytes1024 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Bytes1024 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Bytes1024 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Bytes1024 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes1024 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes1024DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes1024DataWriter_impl (void);
    
    private:
        Bytes1024DataWriter_impl (const Bytes1024DataWriter_impl &);
        void operator= (const Bytes1024DataWriter &);
    };
    
    class  Bytes1024DataReader_impl : public virtual Bytes1024DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Bytes1024Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Bytes1024Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Bytes1024Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Bytes1024Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Bytes1024 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Bytes1024 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Bytes1024Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Bytes1024Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Bytes1024Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Bytes1024Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Bytes1024Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Bytes1024Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Bytes1024Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes1024 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Bytes1024 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes1024DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes1024DataReader_impl (void);
    
    private:
        Bytes1024DataReader_impl (const Bytes1024DataReader &);
        void operator= (const Bytes1024DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Bytes1024Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Bytes2048TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Bytes2048TypeSupportFactory() {};
        virtual ~Bytes2048TypeSupportFactory() {};
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
    
    class Bytes2048TypeSupport : public virtual Bytes2048TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Bytes2048TypeSupport (void);
        virtual ~Bytes2048TypeSupport (void);
    
    private:
        Bytes2048TypeSupport (const Bytes2048TypeSupport &);
        void operator= (const Bytes2048TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Bytes2048TypeSupportInterface_var Bytes2048TypeSupport_var;
    typedef Bytes2048TypeSupportInterface_ptr Bytes2048TypeSupport_ptr;
    
    class  Bytes2048DataWriter_impl : public virtual Bytes2048DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Bytes2048 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Bytes2048 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Bytes2048 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Bytes2048 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Bytes2048 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Bytes2048 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Bytes2048 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Bytes2048 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes2048 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes2048DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes2048DataWriter_impl (void);
    
    private:
        Bytes2048DataWriter_impl (const Bytes2048DataWriter_impl &);
        void operator= (const Bytes2048DataWriter &);
    };
    
    class  Bytes2048DataReader_impl : public virtual Bytes2048DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Bytes2048Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Bytes2048Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Bytes2048Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Bytes2048Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Bytes2048 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Bytes2048 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Bytes2048Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Bytes2048Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Bytes2048Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Bytes2048Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Bytes2048Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Bytes2048Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Bytes2048Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes2048 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Bytes2048 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes2048DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes2048DataReader_impl (void);
    
    private:
        Bytes2048DataReader_impl (const Bytes2048DataReader &);
        void operator= (const Bytes2048DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Bytes2048Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Bytes4096TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Bytes4096TypeSupportFactory() {};
        virtual ~Bytes4096TypeSupportFactory() {};
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
    
    class Bytes4096TypeSupport : public virtual Bytes4096TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Bytes4096TypeSupport (void);
        virtual ~Bytes4096TypeSupport (void);
    
    private:
        Bytes4096TypeSupport (const Bytes4096TypeSupport &);
        void operator= (const Bytes4096TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Bytes4096TypeSupportInterface_var Bytes4096TypeSupport_var;
    typedef Bytes4096TypeSupportInterface_ptr Bytes4096TypeSupport_ptr;
    
    class  Bytes4096DataWriter_impl : public virtual Bytes4096DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Bytes4096 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Bytes4096 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Bytes4096 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Bytes4096 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Bytes4096 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Bytes4096 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Bytes4096 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Bytes4096 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes4096 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes4096DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes4096DataWriter_impl (void);
    
    private:
        Bytes4096DataWriter_impl (const Bytes4096DataWriter_impl &);
        void operator= (const Bytes4096DataWriter &);
    };
    
    class  Bytes4096DataReader_impl : public virtual Bytes4096DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Bytes4096Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Bytes4096Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Bytes4096Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Bytes4096Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Bytes4096 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Bytes4096 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Bytes4096Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Bytes4096Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Bytes4096Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Bytes4096Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Bytes4096Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Bytes4096Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Bytes4096Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes4096 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Bytes4096 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes4096DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes4096DataReader_impl (void);
    
    private:
        Bytes4096DataReader_impl (const Bytes4096DataReader &);
        void operator= (const Bytes4096DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Bytes4096Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Bytes8192TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Bytes8192TypeSupportFactory() {};
        virtual ~Bytes8192TypeSupportFactory() {};
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
    
    class Bytes8192TypeSupport : public virtual Bytes8192TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Bytes8192TypeSupport (void);
        virtual ~Bytes8192TypeSupport (void);
    
    private:
        Bytes8192TypeSupport (const Bytes8192TypeSupport &);
        void operator= (const Bytes8192TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Bytes8192TypeSupportInterface_var Bytes8192TypeSupport_var;
    typedef Bytes8192TypeSupportInterface_ptr Bytes8192TypeSupport_ptr;
    
    class  Bytes8192DataWriter_impl : public virtual Bytes8192DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Bytes8192 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Bytes8192 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Bytes8192 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Bytes8192 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Bytes8192 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Bytes8192 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Bytes8192 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Bytes8192 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes8192 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes8192DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes8192DataWriter_impl (void);
    
    private:
        Bytes8192DataWriter_impl (const Bytes8192DataWriter_impl &);
        void operator= (const Bytes8192DataWriter &);
    };
    
    class  Bytes8192DataReader_impl : public virtual Bytes8192DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Bytes8192Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Bytes8192Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Bytes8192Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Bytes8192Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Bytes8192 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Bytes8192 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Bytes8192Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Bytes8192Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Bytes8192Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Bytes8192Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Bytes8192Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Bytes8192Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Bytes8192Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes8192 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Bytes8192 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes8192DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes8192DataReader_impl (void);
    
    private:
        Bytes8192DataReader_impl (const Bytes8192DataReader &);
        void operator= (const Bytes8192DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Bytes8192Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Bytes16384TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Bytes16384TypeSupportFactory() {};
        virtual ~Bytes16384TypeSupportFactory() {};
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
    
    class Bytes16384TypeSupport : public virtual Bytes16384TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Bytes16384TypeSupport (void);
        virtual ~Bytes16384TypeSupport (void);
    
    private:
        Bytes16384TypeSupport (const Bytes16384TypeSupport &);
        void operator= (const Bytes16384TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Bytes16384TypeSupportInterface_var Bytes16384TypeSupport_var;
    typedef Bytes16384TypeSupportInterface_ptr Bytes16384TypeSupport_ptr;
    
    class  Bytes16384DataWriter_impl : public virtual Bytes16384DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Bytes16384 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Bytes16384 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Bytes16384 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Bytes16384 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Bytes16384 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Bytes16384 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Bytes16384 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Bytes16384 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes16384 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes16384DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes16384DataWriter_impl (void);
    
    private:
        Bytes16384DataWriter_impl (const Bytes16384DataWriter_impl &);
        void operator= (const Bytes16384DataWriter &);
    };
    
    class  Bytes16384DataReader_impl : public virtual Bytes16384DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Bytes16384Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Bytes16384Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Bytes16384Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Bytes16384Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Bytes16384 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Bytes16384 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Bytes16384Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Bytes16384Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Bytes16384Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Bytes16384Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Bytes16384Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Bytes16384Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Bytes16384Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Bytes16384 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Bytes16384 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Bytes16384DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Bytes16384DataReader_impl (void);
    
    private:
        Bytes16384DataReader_impl (const Bytes16384DataReader &);
        void operator= (const Bytes16384DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Bytes16384Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Complex4TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Complex4TypeSupportFactory() {};
        virtual ~Complex4TypeSupportFactory() {};
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
    
    class Complex4TypeSupport : public virtual Complex4TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Complex4TypeSupport (void);
        virtual ~Complex4TypeSupport (void);
    
    private:
        Complex4TypeSupport (const Complex4TypeSupport &);
        void operator= (const Complex4TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Complex4TypeSupportInterface_var Complex4TypeSupport_var;
    typedef Complex4TypeSupportInterface_ptr Complex4TypeSupport_ptr;
    
    class  Complex4DataWriter_impl : public virtual Complex4DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Complex4 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Complex4 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Complex4 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Complex4 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Complex4 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Complex4 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Complex4 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Complex4 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex4 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Complex4DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex4DataWriter_impl (void);
    
    private:
        Complex4DataWriter_impl (const Complex4DataWriter_impl &);
        void operator= (const Complex4DataWriter &);
    };
    
    class  Complex4DataReader_impl : public virtual Complex4DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Complex4Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Complex4Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Complex4Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Complex4Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Complex4 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Complex4 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Complex4Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Complex4Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Complex4Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Complex4Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Complex4Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Complex4Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Complex4Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex4 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Complex4 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Complex4DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex4DataReader_impl (void);
    
    private:
        Complex4DataReader_impl (const Complex4DataReader &);
        void operator= (const Complex4DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Complex4Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Complex8TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Complex8TypeSupportFactory() {};
        virtual ~Complex8TypeSupportFactory() {};
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
    
    class Complex8TypeSupport : public virtual Complex8TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Complex8TypeSupport (void);
        virtual ~Complex8TypeSupport (void);
    
    private:
        Complex8TypeSupport (const Complex8TypeSupport &);
        void operator= (const Complex8TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Complex8TypeSupportInterface_var Complex8TypeSupport_var;
    typedef Complex8TypeSupportInterface_ptr Complex8TypeSupport_ptr;
    
    class  Complex8DataWriter_impl : public virtual Complex8DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Complex8 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Complex8 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Complex8 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Complex8 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Complex8 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Complex8 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Complex8 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Complex8 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex8 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Complex8DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex8DataWriter_impl (void);
    
    private:
        Complex8DataWriter_impl (const Complex8DataWriter_impl &);
        void operator= (const Complex8DataWriter &);
    };
    
    class  Complex8DataReader_impl : public virtual Complex8DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Complex8Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Complex8Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Complex8Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Complex8Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Complex8 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Complex8 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Complex8Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Complex8Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Complex8Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Complex8Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Complex8Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Complex8Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Complex8Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex8 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Complex8 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Complex8DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex8DataReader_impl (void);
    
    private:
        Complex8DataReader_impl (const Complex8DataReader &);
        void operator= (const Complex8DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Complex8Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Complex16TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Complex16TypeSupportFactory() {};
        virtual ~Complex16TypeSupportFactory() {};
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
    
    class Complex16TypeSupport : public virtual Complex16TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Complex16TypeSupport (void);
        virtual ~Complex16TypeSupport (void);
    
    private:
        Complex16TypeSupport (const Complex16TypeSupport &);
        void operator= (const Complex16TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Complex16TypeSupportInterface_var Complex16TypeSupport_var;
    typedef Complex16TypeSupportInterface_ptr Complex16TypeSupport_ptr;
    
    class  Complex16DataWriter_impl : public virtual Complex16DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Complex16 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Complex16 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Complex16 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Complex16 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Complex16 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Complex16 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Complex16 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Complex16 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex16 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Complex16DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex16DataWriter_impl (void);
    
    private:
        Complex16DataWriter_impl (const Complex16DataWriter_impl &);
        void operator= (const Complex16DataWriter &);
    };
    
    class  Complex16DataReader_impl : public virtual Complex16DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Complex16Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Complex16Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Complex16Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Complex16Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Complex16 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Complex16 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Complex16Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Complex16Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Complex16Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Complex16Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Complex16Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Complex16Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Complex16Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex16 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Complex16 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Complex16DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex16DataReader_impl (void);
    
    private:
        Complex16DataReader_impl (const Complex16DataReader &);
        void operator= (const Complex16DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Complex16Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Complex32TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Complex32TypeSupportFactory() {};
        virtual ~Complex32TypeSupportFactory() {};
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
    
    class Complex32TypeSupport : public virtual Complex32TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Complex32TypeSupport (void);
        virtual ~Complex32TypeSupport (void);
    
    private:
        Complex32TypeSupport (const Complex32TypeSupport &);
        void operator= (const Complex32TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Complex32TypeSupportInterface_var Complex32TypeSupport_var;
    typedef Complex32TypeSupportInterface_ptr Complex32TypeSupport_ptr;
    
    class  Complex32DataWriter_impl : public virtual Complex32DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Complex32 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Complex32 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Complex32 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Complex32 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Complex32 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Complex32 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Complex32 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Complex32 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex32 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Complex32DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex32DataWriter_impl (void);
    
    private:
        Complex32DataWriter_impl (const Complex32DataWriter_impl &);
        void operator= (const Complex32DataWriter &);
    };
    
    class  Complex32DataReader_impl : public virtual Complex32DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Complex32Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Complex32Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Complex32Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Complex32Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Complex32 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Complex32 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Complex32Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Complex32Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Complex32Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Complex32Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Complex32Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Complex32Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Complex32Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex32 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Complex32 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Complex32DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex32DataReader_impl (void);
    
    private:
        Complex32DataReader_impl (const Complex32DataReader &);
        void operator= (const Complex32DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Complex32Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Complex64TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Complex64TypeSupportFactory() {};
        virtual ~Complex64TypeSupportFactory() {};
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
    
    class Complex64TypeSupport : public virtual Complex64TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Complex64TypeSupport (void);
        virtual ~Complex64TypeSupport (void);
    
    private:
        Complex64TypeSupport (const Complex64TypeSupport &);
        void operator= (const Complex64TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Complex64TypeSupportInterface_var Complex64TypeSupport_var;
    typedef Complex64TypeSupportInterface_ptr Complex64TypeSupport_ptr;
    
    class  Complex64DataWriter_impl : public virtual Complex64DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Complex64 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Complex64 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Complex64 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Complex64 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Complex64 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Complex64 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Complex64 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Complex64 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex64 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Complex64DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex64DataWriter_impl (void);
    
    private:
        Complex64DataWriter_impl (const Complex64DataWriter_impl &);
        void operator= (const Complex64DataWriter &);
    };
    
    class  Complex64DataReader_impl : public virtual Complex64DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Complex64Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Complex64Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Complex64Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Complex64Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Complex64 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Complex64 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Complex64Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Complex64Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Complex64Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Complex64Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Complex64Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Complex64Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Complex64Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex64 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Complex64 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Complex64DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex64DataReader_impl (void);
    
    private:
        Complex64DataReader_impl (const Complex64DataReader &);
        void operator= (const Complex64DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Complex64Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Complex128TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Complex128TypeSupportFactory() {};
        virtual ~Complex128TypeSupportFactory() {};
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
    
    class Complex128TypeSupport : public virtual Complex128TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Complex128TypeSupport (void);
        virtual ~Complex128TypeSupport (void);
    
    private:
        Complex128TypeSupport (const Complex128TypeSupport &);
        void operator= (const Complex128TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Complex128TypeSupportInterface_var Complex128TypeSupport_var;
    typedef Complex128TypeSupportInterface_ptr Complex128TypeSupport_ptr;
    
    class  Complex128DataWriter_impl : public virtual Complex128DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Complex128 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Complex128 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Complex128 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Complex128 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Complex128 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Complex128 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Complex128 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Complex128 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex128 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Complex128DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex128DataWriter_impl (void);
    
    private:
        Complex128DataWriter_impl (const Complex128DataWriter_impl &);
        void operator= (const Complex128DataWriter &);
    };
    
    class  Complex128DataReader_impl : public virtual Complex128DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Complex128Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Complex128Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Complex128Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Complex128Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Complex128 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Complex128 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Complex128Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Complex128Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Complex128Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Complex128Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Complex128Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Complex128Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Complex128Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex128 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Complex128 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Complex128DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex128DataReader_impl (void);
    
    private:
        Complex128DataReader_impl (const Complex128DataReader &);
        void operator= (const Complex128DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Complex128Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Complex256TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Complex256TypeSupportFactory() {};
        virtual ~Complex256TypeSupportFactory() {};
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
    
    class Complex256TypeSupport : public virtual Complex256TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Complex256TypeSupport (void);
        virtual ~Complex256TypeSupport (void);
    
    private:
        Complex256TypeSupport (const Complex256TypeSupport &);
        void operator= (const Complex256TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Complex256TypeSupportInterface_var Complex256TypeSupport_var;
    typedef Complex256TypeSupportInterface_ptr Complex256TypeSupport_ptr;
    
    class  Complex256DataWriter_impl : public virtual Complex256DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Complex256 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Complex256 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Complex256 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Complex256 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Complex256 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Complex256 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Complex256 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Complex256 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex256 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Complex256DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex256DataWriter_impl (void);
    
    private:
        Complex256DataWriter_impl (const Complex256DataWriter_impl &);
        void operator= (const Complex256DataWriter &);
    };
    
    class  Complex256DataReader_impl : public virtual Complex256DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Complex256Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Complex256Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Complex256Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Complex256Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Complex256 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Complex256 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Complex256Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Complex256Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Complex256Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Complex256Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Complex256Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Complex256Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Complex256Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex256 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Complex256 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Complex256DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex256DataReader_impl (void);
    
    private:
        Complex256DataReader_impl (const Complex256DataReader &);
        void operator= (const Complex256DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Complex256Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Complex512TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Complex512TypeSupportFactory() {};
        virtual ~Complex512TypeSupportFactory() {};
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
    
    class Complex512TypeSupport : public virtual Complex512TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Complex512TypeSupport (void);
        virtual ~Complex512TypeSupport (void);
    
    private:
        Complex512TypeSupport (const Complex512TypeSupport &);
        void operator= (const Complex512TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Complex512TypeSupportInterface_var Complex512TypeSupport_var;
    typedef Complex512TypeSupportInterface_ptr Complex512TypeSupport_ptr;
    
    class  Complex512DataWriter_impl : public virtual Complex512DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Complex512 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Complex512 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Complex512 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Complex512 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Complex512 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Complex512 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Complex512 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Complex512 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex512 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Complex512DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex512DataWriter_impl (void);
    
    private:
        Complex512DataWriter_impl (const Complex512DataWriter_impl &);
        void operator= (const Complex512DataWriter &);
    };
    
    class  Complex512DataReader_impl : public virtual Complex512DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Complex512Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Complex512Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Complex512Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Complex512Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Complex512 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Complex512 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Complex512Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Complex512Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Complex512Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Complex512Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Complex512Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Complex512Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Complex512Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex512 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Complex512 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Complex512DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex512DataReader_impl (void);
    
    private:
        Complex512DataReader_impl (const Complex512DataReader &);
        void operator= (const Complex512DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Complex512Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Complex1024TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Complex1024TypeSupportFactory() {};
        virtual ~Complex1024TypeSupportFactory() {};
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
    
    class Complex1024TypeSupport : public virtual Complex1024TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Complex1024TypeSupport (void);
        virtual ~Complex1024TypeSupport (void);
    
    private:
        Complex1024TypeSupport (const Complex1024TypeSupport &);
        void operator= (const Complex1024TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Complex1024TypeSupportInterface_var Complex1024TypeSupport_var;
    typedef Complex1024TypeSupportInterface_ptr Complex1024TypeSupport_ptr;
    
    class  Complex1024DataWriter_impl : public virtual Complex1024DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Complex1024 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Complex1024 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Complex1024 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Complex1024 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Complex1024 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Complex1024 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Complex1024 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Complex1024 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex1024 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Complex1024DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex1024DataWriter_impl (void);
    
    private:
        Complex1024DataWriter_impl (const Complex1024DataWriter_impl &);
        void operator= (const Complex1024DataWriter &);
    };
    
    class  Complex1024DataReader_impl : public virtual Complex1024DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Complex1024Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Complex1024Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Complex1024Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Complex1024Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Complex1024 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Complex1024 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Complex1024Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Complex1024Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Complex1024Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Complex1024Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Complex1024Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Complex1024Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Complex1024Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex1024 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Complex1024 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Complex1024DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex1024DataReader_impl (void);
    
    private:
        Complex1024DataReader_impl (const Complex1024DataReader &);
        void operator= (const Complex1024DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Complex1024Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Complex2048TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Complex2048TypeSupportFactory() {};
        virtual ~Complex2048TypeSupportFactory() {};
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
    
    class Complex2048TypeSupport : public virtual Complex2048TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Complex2048TypeSupport (void);
        virtual ~Complex2048TypeSupport (void);
    
    private:
        Complex2048TypeSupport (const Complex2048TypeSupport &);
        void operator= (const Complex2048TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Complex2048TypeSupportInterface_var Complex2048TypeSupport_var;
    typedef Complex2048TypeSupportInterface_ptr Complex2048TypeSupport_ptr;
    
    class  Complex2048DataWriter_impl : public virtual Complex2048DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Complex2048 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Complex2048 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Complex2048 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Complex2048 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Complex2048 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Complex2048 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Complex2048 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Complex2048 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex2048 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Complex2048DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex2048DataWriter_impl (void);
    
    private:
        Complex2048DataWriter_impl (const Complex2048DataWriter_impl &);
        void operator= (const Complex2048DataWriter &);
    };
    
    class  Complex2048DataReader_impl : public virtual Complex2048DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Complex2048Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Complex2048Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Complex2048Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Complex2048Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Complex2048 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Complex2048 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Complex2048Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Complex2048Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Complex2048Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Complex2048Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Complex2048Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Complex2048Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Complex2048Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex2048 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Complex2048 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Complex2048DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex2048DataReader_impl (void);
    
    private:
        Complex2048DataReader_impl (const Complex2048DataReader &);
        void operator= (const Complex2048DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Complex2048Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Complex4096TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Complex4096TypeSupportFactory() {};
        virtual ~Complex4096TypeSupportFactory() {};
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
    
    class Complex4096TypeSupport : public virtual Complex4096TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Complex4096TypeSupport (void);
        virtual ~Complex4096TypeSupport (void);
    
    private:
        Complex4096TypeSupport (const Complex4096TypeSupport &);
        void operator= (const Complex4096TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Complex4096TypeSupportInterface_var Complex4096TypeSupport_var;
    typedef Complex4096TypeSupportInterface_ptr Complex4096TypeSupport_ptr;
    
    class  Complex4096DataWriter_impl : public virtual Complex4096DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Complex4096 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Complex4096 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Complex4096 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Complex4096 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Complex4096 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Complex4096 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Complex4096 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Complex4096 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex4096 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Complex4096DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex4096DataWriter_impl (void);
    
    private:
        Complex4096DataWriter_impl (const Complex4096DataWriter_impl &);
        void operator= (const Complex4096DataWriter &);
    };
    
    class  Complex4096DataReader_impl : public virtual Complex4096DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Complex4096Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Complex4096Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Complex4096Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Complex4096Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Complex4096 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Complex4096 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Complex4096Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Complex4096Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Complex4096Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Complex4096Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Complex4096Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Complex4096Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Complex4096Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex4096 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Complex4096 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Complex4096DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex4096DataReader_impl (void);
    
    private:
        Complex4096DataReader_impl (const Complex4096DataReader &);
        void operator= (const Complex4096DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Complex4096Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Complex8192TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Complex8192TypeSupportFactory() {};
        virtual ~Complex8192TypeSupportFactory() {};
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
    
    class Complex8192TypeSupport : public virtual Complex8192TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Complex8192TypeSupport (void);
        virtual ~Complex8192TypeSupport (void);
    
    private:
        Complex8192TypeSupport (const Complex8192TypeSupport &);
        void operator= (const Complex8192TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Complex8192TypeSupportInterface_var Complex8192TypeSupport_var;
    typedef Complex8192TypeSupportInterface_ptr Complex8192TypeSupport_ptr;
    
    class  Complex8192DataWriter_impl : public virtual Complex8192DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Complex8192 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Complex8192 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Complex8192 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Complex8192 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Complex8192 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Complex8192 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Complex8192 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Complex8192 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex8192 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Complex8192DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex8192DataWriter_impl (void);
    
    private:
        Complex8192DataWriter_impl (const Complex8192DataWriter_impl &);
        void operator= (const Complex8192DataWriter &);
    };
    
    class  Complex8192DataReader_impl : public virtual Complex8192DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Complex8192Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Complex8192Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Complex8192Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Complex8192Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Complex8192 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Complex8192 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Complex8192Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Complex8192Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Complex8192Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Complex8192Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Complex8192Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Complex8192Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Complex8192Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex8192 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Complex8192 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Complex8192DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex8192DataReader_impl (void);
    
    private:
        Complex8192DataReader_impl (const Complex8192DataReader &);
        void operator= (const Complex8192DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Complex8192Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
    class Complex16384TypeSupportFactory : public ::DDS::TypeSupportFactory_impl
    {
    public:
        Complex16384TypeSupportFactory() {};
        virtual ~Complex16384TypeSupportFactory() {};
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
    
    class Complex16384TypeSupport : public virtual Complex16384TypeSupportInterface,
                                   public ::DDS::TypeSupport_impl
    {
    public:
        virtual ::DDS::ReturnCode_t register_type (
            ::DDS::DomainParticipant_ptr participant,
            const char * type_name
        ) THROW_ORB_EXCEPTIONS;
    
        virtual char * get_type_name (
        ) THROW_ORB_EXCEPTIONS;    
    
        Complex16384TypeSupport (void);
        virtual ~Complex16384TypeSupport (void);
    
    private:
        Complex16384TypeSupport (const Complex16384TypeSupport &);
        void operator= (const Complex16384TypeSupport &);
    
        static const char *metaDescriptor;
    };
    
    typedef Complex16384TypeSupportInterface_var Complex16384TypeSupport_var;
    typedef Complex16384TypeSupportInterface_ptr Complex16384TypeSupport_ptr;
    
    class  Complex16384DataWriter_impl : public virtual Complex16384DataWriter,
                                        public ::DDS::DataWriter_impl
    {
    public:
    
        virtual ::DDS::InstanceHandle_t register_instance (
            const Complex16384 & instance_data
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
            const Complex16384 & instance_data,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
            
        virtual ::DDS::ReturnCode_t unregister_instance (
            const Complex16384 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
            const Complex16384 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write (
            const Complex16384 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t write_w_timestamp (
            const Complex16384 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose (
            const Complex16384 & instance_data,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t dispose_w_timestamp (
            const Complex16384 & instance_data,
            ::DDS::InstanceHandle_t handle,
            const ::DDS::Time_t & source_timestamp
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex16384 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
    
        Complex16384DataWriter_impl (
            gapi_dataWriter handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex16384DataWriter_impl (void);
    
    private:
        Complex16384DataWriter_impl (const Complex16384DataWriter_impl &);
        void operator= (const Complex16384DataWriter &);
    };
    
    class  Complex16384DataReader_impl : public virtual Complex16384DataReader,
                                        public ::DDS::DataReader_impl
    {
    public:
        virtual ::DDS::ReturnCode_t read (
            Complex16384Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take (
            Complex16384Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_w_condition (
            Complex16384Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_w_condition (
            Complex16384Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t read_next_sample (
            Complex16384 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_sample (
            Complex16384 & received_data,
            ::DDS::SampleInfo & sample_info
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_instance (
            Complex16384Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_instance (
            Complex16384Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance (
            Complex16384Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t take_next_instance (
            Complex16384Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::SampleStateMask sample_states,
            ::DDS::ViewStateMask view_states,
            ::DDS::InstanceStateMask instance_states
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
            Complex16384Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
            Complex16384Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples,
            ::DDS::InstanceHandle_t a_handle,
            ::DDS::ReadCondition_ptr a_condition
        ) THROW_ORB_EXCEPTIONS;
    
        virtual ::DDS::ReturnCode_t return_loan (
            Complex16384Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::ReturnCode_t get_key_value (
            Complex16384 & key_holder,
            ::DDS::InstanceHandle_t handle
        ) THROW_ORB_EXCEPTIONS;
        
        virtual ::DDS::InstanceHandle_t lookup_instance (
            const Complex16384 & instance
        ) THROW_ORB_EXCEPTIONS;
    
        Complex16384DataReader_impl (
            gapi_dataReader handle,
            ::DDS::ccpp_UserData_ptr &statusConditionData
        );
    
        virtual ~Complex16384DataReader_impl (void);
    
    private:
        Complex16384DataReader_impl (const Complex16384DataReader &);
        void operator= (const Complex16384DataReader &);
    
        ::DDS::ReturnCode_t check_preconditions(
            Complex16384Seq & received_data,
            ::DDS::SampleInfoSeq & info_seq,
            CORBA::Long max_samples
        );
    };
    
}

#endif
