// -*- C++ -*-
//
// $Id$

// ****  Code generated by the The ACE ORB (TAO) IDL Compiler ****
// TAO and the TAO IDL Compiler have been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// and
//       Distributed Object Computing Laboratory
//       University of California at Irvine
//       Irvine, CA
//       USA
//       http://doc.ece.uci.edu/
// and
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about TAO is available at:
//     http://www.cs.wustl.edu/~schmidt/TAO.html

// TAO_IDL - Generated from
// .\be\be_codegen.cpp:396

#ifndef _TAO_IDL_PUBCOMPLEXMESSAGETYPESUPPORTS_H_
#define _TAO_IDL_PUBCOMPLEXMESSAGETYPESUPPORTS_H_

#include /**/ "ace/pre.h"

#include "PubComplexMessageTypeSupportC.h"
#include "dds/DdsDcpsInfrastructureS.h"
#include "dds/DdsDcpsTopicS.h"
#include "dds/DdsDcpsDataWriterRemoteS.h"
#include "dds/DdsDcpsDataReaderRemoteS.h"
#include "dds/DdsDcpsTypeSupportTaoS.h"
#include "DDSPerfTestS.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/Collocation_Proxy_Broker.h"
#include "tao/PortableServer/PortableServer.h"
#include "tao/PortableServer/Servant_Base.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_sh.cpp:87

class POA_PubComplexMessageTypeSupport;
typedef POA_PubComplexMessageTypeSupport *POA_PubComplexMessageTypeSupport_ptr;


class  POA_PubComplexMessageTypeSupport
  : public virtual POA_TAO::DCPS::TypeSupport
{
protected:
  POA_PubComplexMessageTypeSupport (void);

public:
  // Useful for template programming.
  typedef ::PubComplexMessageTypeSupport _stub_type;
  typedef ::PubComplexMessageTypeSupport_ptr _stub_ptr_type;
  typedef ::PubComplexMessageTypeSupport_var _stub_var_type;
  
  POA_PubComplexMessageTypeSupport (const POA_PubComplexMessageTypeSupport& rhs);
  virtual ~POA_PubComplexMessageTypeSupport (void);
  
  virtual ::CORBA::Boolean _is_a (
      const char* logical_type_id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  static void _is_a_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  static void _non_existent_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  static void _interface_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  static void _component_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  static void _repository_id_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  virtual void _dispatch (
      TAO_ServerRequest & req,
      void * servant_upcall
      ACE_ENV_ARG_DECL
    );
  
  ::PubComplexMessageTypeSupport *_this (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    );
  
  virtual const char* _interface_repository_id (void) const;
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual ::DDS::ReturnCode_t register_type (
      ::DDS::DomainParticipant_ptr participant,
      const char * type_name
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    )) = 0;
  
  static void register_type_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  create_datawriter_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  create_datareader_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
};

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_sh.cpp:87

class POA_PubComplexMessageDataWriter;
typedef POA_PubComplexMessageDataWriter *POA_PubComplexMessageDataWriter_ptr;


class  POA_PubComplexMessageDataWriter
  : public virtual POA_TAO::DCPS::DataWriterRemote
{
protected:
  POA_PubComplexMessageDataWriter (void);

public:
  // Useful for template programming.
  typedef ::PubComplexMessageDataWriter _stub_type;
  typedef ::PubComplexMessageDataWriter_ptr _stub_ptr_type;
  typedef ::PubComplexMessageDataWriter_var _stub_var_type;
  
  POA_PubComplexMessageDataWriter (const POA_PubComplexMessageDataWriter& rhs);
  virtual ~POA_PubComplexMessageDataWriter (void);
  
  virtual ::CORBA::Boolean _is_a (
      const char* logical_type_id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  static void _is_a_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  static void _non_existent_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  static void _interface_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  static void _component_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  static void _repository_id_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  virtual void _dispatch (
      TAO_ServerRequest & req,
      void * servant_upcall
      ACE_ENV_ARG_DECL
    );
  
  ::PubComplexMessageDataWriter *_this (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    );
  
  virtual const char* _interface_repository_id (void) const;
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual ::DDS::InstanceHandle_t _cxx_register (
      const ::DDSPerfTest::PubComplexMessage & instance_data
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    )) = 0;
  
  static void _cxx_register_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual ::DDS::InstanceHandle_t register_w_timestamp (
      const ::DDSPerfTest::PubComplexMessage & instance_data,
      ::DDS::InstanceHandle_t handle,
      const ::DDS::Time_t & source_timestamp
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    )) = 0;
  
  static void register_w_timestamp_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual ::DDS::ReturnCode_t unregister (
      const ::DDSPerfTest::PubComplexMessage & instance_data,
      ::DDS::InstanceHandle_t handle
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    )) = 0;
  
  static void unregister_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual ::DDS::ReturnCode_t unregister_w_timestamp (
      const ::DDSPerfTest::PubComplexMessage & instance_data,
      ::DDS::InstanceHandle_t handle,
      const ::DDS::Time_t & source_timestamp
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    )) = 0;
  
  static void unregister_w_timestamp_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual ::DDS::ReturnCode_t write (
      const ::DDSPerfTest::PubComplexMessage & instance_data,
      ::DDS::InstanceHandle_t handle
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    )) = 0;
  
  static void write_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual ::DDS::ReturnCode_t write_w_timestamp (
      const ::DDSPerfTest::PubComplexMessage & instance_data,
      ::DDS::InstanceHandle_t handle,
      const ::DDS::Time_t & source_timestamp
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    )) = 0;
  
  static void write_w_timestamp_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual ::DDS::ReturnCode_t dispose (
      const ::DDSPerfTest::PubComplexMessage & instance_data,
      ::DDS::InstanceHandle_t instance_handle
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    )) = 0;
  
  static void dispose_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual ::DDS::ReturnCode_t dispose_w_timestamp (
      const ::DDSPerfTest::PubComplexMessage & instance_data,
      ::DDS::InstanceHandle_t instance_handle,
      const ::DDS::Time_t & source_timestamp
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    )) = 0;
  
  static void dispose_w_timestamp_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual ::DDS::ReturnCode_t get_key_value (
      ::DDSPerfTest::PubComplexMessage & key_holder,
      ::DDS::InstanceHandle_t handle
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    )) = 0;
  
  static void get_key_value_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  enable_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  get_status_changes_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  set_qos_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  get_qos_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  set_listener_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  get_listener_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  get_topic_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  get_publisher_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  get_liveliness_lost_status_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  get_offered_deadline_missed_status_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  get_offered_incompatible_qos_status_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  get_publication_match_status_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  assert_liveliness_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  get_matched_subscriptions_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  get_matched_subscription_data_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  add_associations_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  remove_associations_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  update_incompatible_qos_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
};

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_interface/interface_sh.cpp:87

class POA_PubComplexMessageDataReader;
typedef POA_PubComplexMessageDataReader *POA_PubComplexMessageDataReader_ptr;


class  POA_PubComplexMessageDataReader
  : public virtual POA_TAO::DCPS::DataReaderRemote
{
protected:
  POA_PubComplexMessageDataReader (void);

public:
  // Useful for template programming.
  typedef ::PubComplexMessageDataReader _stub_type;
  typedef ::PubComplexMessageDataReader_ptr _stub_ptr_type;
  typedef ::PubComplexMessageDataReader_var _stub_var_type;
  
  POA_PubComplexMessageDataReader (const POA_PubComplexMessageDataReader& rhs);
  virtual ~POA_PubComplexMessageDataReader (void);
  
  virtual ::CORBA::Boolean _is_a (
      const char* logical_type_id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  static void _is_a_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  static void _non_existent_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  static void _interface_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  static void _component_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  static void _repository_id_skel (
      TAO_ServerRequest & req,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  virtual void _dispatch (
      TAO_ServerRequest & req,
      void * servant_upcall
      ACE_ENV_ARG_DECL
    );
  
  ::PubComplexMessageDataReader *_this (
      ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS
    );
  
  virtual const char* _interface_repository_id (void) const;
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual ::DDS::ReturnCode_t read (
      ::PubComplexMessageSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    )) = 0;
  
  static void read_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual ::DDS::ReturnCode_t take (
      ::PubComplexMessageSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    )) = 0;
  
  static void take_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual ::DDS::ReturnCode_t read_next_sample (
      ::DDSPerfTest::PubComplexMessage & received_data,
      ::DDS::SampleInfo & sample_info
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    )) = 0;
  
  static void read_next_sample_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual ::DDS::ReturnCode_t take_next_sample (
      ::DDSPerfTest::PubComplexMessage & received_data,
      ::DDS::SampleInfo & sample_info
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    )) = 0;
  
  static void take_next_sample_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual ::DDS::ReturnCode_t read_instance (
      ::PubComplexMessageSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    )) = 0;
  
  static void read_instance_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual ::DDS::ReturnCode_t take_instance (
      ::PubComplexMessageSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    )) = 0;
  
  static void take_instance_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual ::DDS::ReturnCode_t read_next_instance (
      ::PubComplexMessageSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    )) = 0;
  
  static void read_next_instance_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual ::DDS::ReturnCode_t take_next_instance (
      ::PubComplexMessageSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    )) = 0;
  
  static void take_next_instance_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual ::DDS::ReturnCode_t return_loan (
      ::PubComplexMessageSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    )) = 0;
  
  static void return_loan_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // w:\ace_wrappers\tao\tao_idl\be\be_visitor_operation/operation_sh.cpp:45
  
  virtual ::DDS::ReturnCode_t get_key_value (
      ::DDSPerfTest::PubComplexMessage & key_holder,
      ::DDS::InstanceHandle_t handle
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    )) = 0;
  
  static void get_key_value_skel (
      TAO_ServerRequest & server_request,
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  enable_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  get_status_changes_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  delete_contained_entities_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  set_qos_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  get_qos_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  set_listener_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  get_listener_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  get_topicdescription_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  get_subscriber_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  get_sample_rejected_status_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  get_liveliness_changed_status_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  get_requested_deadline_missed_status_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  get_requested_incompatible_qos_status_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  get_subscription_match_status_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  get_sample_lost_status_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  wait_for_historical_data_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  get_matched_publications_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  get_matched_publication_data_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  add_associations_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  remove_associations_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  // TAO_IDL - Generated from
  // .\be\be_interface.cpp:1917
  
  static void
  update_incompatible_qos_skel (
      TAO_ServerRequest & server_request, 
      void * servant_upcall,
      void * servant
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
};

// TAO_IDL - Generated from 
// .\be\be_codegen.cpp:1157



TAO_END_VERSIONED_NAMESPACE_DECL


#if defined (__ACE_INLINE__)
#include "PubComplexMessageTypeSupportS.inl"
#endif /* defined INLINE */

#include /**/ "ace/post.h"
#endif /* ifndef */

