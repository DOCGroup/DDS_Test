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
// be/be_codegen.cpp:164

#ifndef _TAO_IDL_PUBCOMPLEXMESSAGETYPESUPPORTC_H_
#define _TAO_IDL_PUBCOMPLEXMESSAGETYPESUPPORTC_H_

#include /**/ "ace/pre.h"


#include "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Environment.h"
#include "dds/DCPS/Serializer.h"
#include "tao/Object.h"
#include "tao/Sequence_T.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"
#include "tao/Versioned_Namespace.h"

#include "dds/DdsDcpsInfrastructureC.h"
#include "dds/DdsDcpsTopicC.h"
#include "dds/DdsDcpsDataWriterRemoteC.h"
#include "dds/DdsDcpsDataReaderRemoteC.h"
#include "dds/DdsDcpsTypeSupportTaoC.h"
#include "DDSPerfTestC.h"

#if defined (TAO_EXPORT_MACRO)
#undef TAO_EXPORT_MACRO
#endif
#define TAO_EXPORT_MACRO 

TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from 
// be/be_visitor_root/root_ch.cpp:62

namespace TAO
{
  class Collocation_Proxy_Broker;
  template<typename T> class Narrow_Utils;
}

// TAO_IDL - Generated from
// be/be_visitor_sequence/sequence_ch.cpp:101

#if !defined (_PUBCOMPLEXMESSAGESEQ_CH_)
#define _PUBCOMPLEXMESSAGESEQ_CH_

class PubComplexMessageSeq;

typedef
  TAO_VarSeq_Var_T<
      PubComplexMessageSeq,
      DDSPerfTest::PubComplexMessage
    >
  PubComplexMessageSeq_var;

typedef
  TAO_Seq_Out_T<
      PubComplexMessageSeq,
      PubComplexMessageSeq_var,
      DDSPerfTest::PubComplexMessage
    >
  PubComplexMessageSeq_out;

class  PubComplexMessageSeq
  : public
      TAO_Unbounded_Sequence<
          DDSPerfTest::PubComplexMessage
        >
{
public:
  PubComplexMessageSeq (void);
  PubComplexMessageSeq ( ::CORBA::ULong max);
  PubComplexMessageSeq (
      ::CORBA::ULong max,
      ::CORBA::ULong length,
      DDSPerfTest::PubComplexMessage* buffer, 
      ::CORBA::Boolean release = 0
    );
  PubComplexMessageSeq (const PubComplexMessageSeq &);
  ~PubComplexMessageSeq (void);
  
  typedef PubComplexMessageSeq_var _var_type;
};

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_interface.cpp:646

#if !defined (_PUBCOMPLEXMESSAGETYPESUPPORT__VAR_OUT_CH_)
#define _PUBCOMPLEXMESSAGETYPESUPPORT__VAR_OUT_CH_

class PubComplexMessageTypeSupport;
typedef PubComplexMessageTypeSupport *PubComplexMessageTypeSupport_ptr;

typedef
  TAO_Objref_Var_T<
      PubComplexMessageTypeSupport
    >
  PubComplexMessageTypeSupport_var;

typedef
  TAO_Objref_Out_T<
      PubComplexMessageTypeSupport
    >
  PubComplexMessageTypeSupport_out;

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ch.cpp:54

#if !defined (_PUBCOMPLEXMESSAGETYPESUPPORT_CH_)
#define _PUBCOMPLEXMESSAGETYPESUPPORT_CH_

class  PubComplexMessageTypeSupport
  : public virtual ::TAO::DCPS::TypeSupport
{
public:
  friend class TAO::Narrow_Utils<PubComplexMessageTypeSupport>;
  typedef PubComplexMessageTypeSupport_ptr _ptr_type;
  typedef PubComplexMessageTypeSupport_var _var_type;
  
  // The static operations.
  static PubComplexMessageTypeSupport_ptr _duplicate (PubComplexMessageTypeSupport_ptr obj);
  
  static void _tao_release (PubComplexMessageTypeSupport_ptr obj);
  
  static PubComplexMessageTypeSupport_ptr _narrow (
      ::CORBA::Object_ptr obj
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  static PubComplexMessageTypeSupport_ptr _unchecked_narrow (
      ::CORBA::Object_ptr obj
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  static PubComplexMessageTypeSupport_ptr _nil (void)
  {
    return static_cast<PubComplexMessageTypeSupport_ptr> (0);
  }
  
  
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_ch.cpp:46
  
  virtual ::DDS::ReturnCode_t register_type (
      ::DDS::DomainParticipant_ptr participant,
      const char * type_name
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    ));
  
  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:210
  
  virtual ::CORBA::Boolean _is_a (
      const char *type_id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  virtual const char* _interface_repository_id (void) const;
  virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
private:
  TAO::Collocation_Proxy_Broker *the_TAO_PubComplexMessageTypeSupport_Proxy_Broker_;

protected:
  // Concrete interface only.
  PubComplexMessageTypeSupport (void);
  
  // These methods travese the inheritance tree and set the
  // parents piece of the given class in the right mode.
  virtual void PubComplexMessageTypeSupport_setup_collocation (void);
  
  // Concrete non-local interface only.
  PubComplexMessageTypeSupport (
      IOP::IOR *ior,
      TAO_ORB_Core *orb_core = 0
    );
  
  // Non-local interface only.
  PubComplexMessageTypeSupport (
      TAO_Stub *objref,
      ::CORBA::Boolean _tao_collocated = 0,
      TAO_Abstract_ServantBase *servant = 0,
      TAO_ORB_Core *orb_core = 0
    );
  
  virtual ~PubComplexMessageTypeSupport (void);

private:
  // Private and unimplemented for concrete interfaces.
  PubComplexMessageTypeSupport (const PubComplexMessageTypeSupport &);
  
  void operator= (const PubComplexMessageTypeSupport &);
};

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_interface.cpp:646

#if !defined (_PUBCOMPLEXMESSAGEDATAWRITER__VAR_OUT_CH_)
#define _PUBCOMPLEXMESSAGEDATAWRITER__VAR_OUT_CH_

class PubComplexMessageDataWriter;
typedef PubComplexMessageDataWriter *PubComplexMessageDataWriter_ptr;

typedef
  TAO_Objref_Var_T<
      PubComplexMessageDataWriter
    >
  PubComplexMessageDataWriter_var;

typedef
  TAO_Objref_Out_T<
      PubComplexMessageDataWriter
    >
  PubComplexMessageDataWriter_out;

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ch.cpp:54

#if !defined (_PUBCOMPLEXMESSAGEDATAWRITER_CH_)
#define _PUBCOMPLEXMESSAGEDATAWRITER_CH_

class  PubComplexMessageDataWriter
  : public virtual ::TAO::DCPS::DataWriterRemote
{
public:
  friend class TAO::Narrow_Utils<PubComplexMessageDataWriter>;
  typedef PubComplexMessageDataWriter_ptr _ptr_type;
  typedef PubComplexMessageDataWriter_var _var_type;
  
  // The static operations.
  static PubComplexMessageDataWriter_ptr _duplicate (PubComplexMessageDataWriter_ptr obj);
  
  static void _tao_release (PubComplexMessageDataWriter_ptr obj);
  
  static PubComplexMessageDataWriter_ptr _narrow (
      ::CORBA::Object_ptr obj
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  static PubComplexMessageDataWriter_ptr _unchecked_narrow (
      ::CORBA::Object_ptr obj
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  static PubComplexMessageDataWriter_ptr _nil (void)
  {
    return static_cast<PubComplexMessageDataWriter_ptr> (0);
  }
  
  
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_ch.cpp:46
  
  virtual ::DDS::InstanceHandle_t _cxx_register (
      const ::DDSPerfTest::PubComplexMessage & instance_data
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    ));
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_ch.cpp:46
  
  virtual ::DDS::InstanceHandle_t register_w_timestamp (
      const ::DDSPerfTest::PubComplexMessage & instance_data,
      ::DDS::InstanceHandle_t handle,
      const ::DDS::Time_t & source_timestamp
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    ));
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_ch.cpp:46
  
  virtual ::DDS::ReturnCode_t unregister (
      const ::DDSPerfTest::PubComplexMessage & instance_data,
      ::DDS::InstanceHandle_t handle
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    ));
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_ch.cpp:46
  
  virtual ::DDS::ReturnCode_t unregister_w_timestamp (
      const ::DDSPerfTest::PubComplexMessage & instance_data,
      ::DDS::InstanceHandle_t handle,
      const ::DDS::Time_t & source_timestamp
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    ));
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_ch.cpp:46
  
  virtual ::DDS::ReturnCode_t write (
      const ::DDSPerfTest::PubComplexMessage & instance_data,
      ::DDS::InstanceHandle_t handle
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    ));
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_ch.cpp:46
  
  virtual ::DDS::ReturnCode_t write_w_timestamp (
      const ::DDSPerfTest::PubComplexMessage & instance_data,
      ::DDS::InstanceHandle_t handle,
      const ::DDS::Time_t & source_timestamp
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    ));
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_ch.cpp:46
  
  virtual ::DDS::ReturnCode_t dispose (
      const ::DDSPerfTest::PubComplexMessage & instance_data,
      ::DDS::InstanceHandle_t instance_handle
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    ));
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_ch.cpp:46
  
  virtual ::DDS::ReturnCode_t dispose_w_timestamp (
      const ::DDSPerfTest::PubComplexMessage & instance_data,
      ::DDS::InstanceHandle_t instance_handle,
      const ::DDS::Time_t & source_timestamp
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    ));
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_ch.cpp:46
  
  virtual ::DDS::ReturnCode_t get_key_value (
      ::DDSPerfTest::PubComplexMessage & key_holder,
      ::DDS::InstanceHandle_t handle
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    ));
  
  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:210
  
  virtual ::CORBA::Boolean _is_a (
      const char *type_id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  virtual const char* _interface_repository_id (void) const;
  virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
private:
  TAO::Collocation_Proxy_Broker *the_TAO_PubComplexMessageDataWriter_Proxy_Broker_;

protected:
  // Concrete interface only.
  PubComplexMessageDataWriter (void);
  
  // These methods travese the inheritance tree and set the
  // parents piece of the given class in the right mode.
  virtual void PubComplexMessageDataWriter_setup_collocation (void);
  
  // Concrete non-local interface only.
  PubComplexMessageDataWriter (
      IOP::IOR *ior,
      TAO_ORB_Core *orb_core = 0
    );
  
  // Non-local interface only.
  PubComplexMessageDataWriter (
      TAO_Stub *objref,
      ::CORBA::Boolean _tao_collocated = 0,
      TAO_Abstract_ServantBase *servant = 0,
      TAO_ORB_Core *orb_core = 0
    );
  
  virtual ~PubComplexMessageDataWriter (void);

private:
  // Private and unimplemented for concrete interfaces.
  PubComplexMessageDataWriter (const PubComplexMessageDataWriter &);
  
  void operator= (const PubComplexMessageDataWriter &);
};

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_interface.cpp:646

#if !defined (_PUBCOMPLEXMESSAGEDATAREADER__VAR_OUT_CH_)
#define _PUBCOMPLEXMESSAGEDATAREADER__VAR_OUT_CH_

class PubComplexMessageDataReader;
typedef PubComplexMessageDataReader *PubComplexMessageDataReader_ptr;

typedef
  TAO_Objref_Var_T<
      PubComplexMessageDataReader
    >
  PubComplexMessageDataReader_var;

typedef
  TAO_Objref_Out_T<
      PubComplexMessageDataReader
    >
  PubComplexMessageDataReader_out;

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ch.cpp:54

#if !defined (_PUBCOMPLEXMESSAGEDATAREADER_CH_)
#define _PUBCOMPLEXMESSAGEDATAREADER_CH_

class  PubComplexMessageDataReader
  : public virtual ::TAO::DCPS::DataReaderRemote
{
public:
  friend class TAO::Narrow_Utils<PubComplexMessageDataReader>;
  typedef PubComplexMessageDataReader_ptr _ptr_type;
  typedef PubComplexMessageDataReader_var _var_type;
  
  // The static operations.
  static PubComplexMessageDataReader_ptr _duplicate (PubComplexMessageDataReader_ptr obj);
  
  static void _tao_release (PubComplexMessageDataReader_ptr obj);
  
  static PubComplexMessageDataReader_ptr _narrow (
      ::CORBA::Object_ptr obj
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  static PubComplexMessageDataReader_ptr _unchecked_narrow (
      ::CORBA::Object_ptr obj
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  static PubComplexMessageDataReader_ptr _nil (void)
  {
    return static_cast<PubComplexMessageDataReader_ptr> (0);
  }
  
  
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_ch.cpp:46
  
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
    ));
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_ch.cpp:46
  
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
    ));
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_ch.cpp:46
  
  virtual ::DDS::ReturnCode_t read_next_sample (
      ::DDSPerfTest::PubComplexMessage & received_data,
      ::DDS::SampleInfo & sample_info
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    ));
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_ch.cpp:46
  
  virtual ::DDS::ReturnCode_t take_next_sample (
      ::DDSPerfTest::PubComplexMessage & received_data,
      ::DDS::SampleInfo & sample_info
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    ));
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_ch.cpp:46
  
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
    ));
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_ch.cpp:46
  
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
    ));
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_ch.cpp:46
  
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
    ));
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_ch.cpp:46
  
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
    ));
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_ch.cpp:46
  
  virtual ::DDS::ReturnCode_t return_loan (
      ::PubComplexMessageSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    ));
  
  // TAO_IDL - Generated from
  // be/be_visitor_operation/operation_ch.cpp:46
  
  virtual ::DDS::ReturnCode_t get_key_value (
      ::DDSPerfTest::PubComplexMessage & key_holder,
      ::DDS::InstanceHandle_t handle
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    )
    ACE_THROW_SPEC ((
      ::CORBA::SystemException
    ));
  
  // TAO_IDL - Generated from
  // be/be_visitor_interface/interface_ch.cpp:210
  
  virtual ::CORBA::Boolean _is_a (
      const char *type_id
      ACE_ENV_ARG_DECL_WITH_DEFAULTS
    );
  
  virtual const char* _interface_repository_id (void) const;
  virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
private:
  TAO::Collocation_Proxy_Broker *the_TAO_PubComplexMessageDataReader_Proxy_Broker_;

protected:
  // Concrete interface only.
  PubComplexMessageDataReader (void);
  
  // These methods travese the inheritance tree and set the
  // parents piece of the given class in the right mode.
  virtual void PubComplexMessageDataReader_setup_collocation (void);
  
  // Concrete non-local interface only.
  PubComplexMessageDataReader (
      IOP::IOR *ior,
      TAO_ORB_Core *orb_core = 0
    );
  
  // Non-local interface only.
  PubComplexMessageDataReader (
      TAO_Stub *objref,
      ::CORBA::Boolean _tao_collocated = 0,
      TAO_Abstract_ServantBase *servant = 0,
      TAO_ORB_Core *orb_core = 0
    );
  
  virtual ~PubComplexMessageDataReader (void);

private:
  // Private and unimplemented for concrete interfaces.
  PubComplexMessageDataReader (const PubComplexMessageDataReader &);
  
  void operator= (const PubComplexMessageDataReader &);
};

#endif /* end #if !defined */

// Proxy Broker Factory function pointer declarations.

// TAO_IDL - Generated from
// be/be_visitor_root/root.cpp:139

extern 
TAO::Collocation_Proxy_Broker *
(*_TAO_PubComplexMessageTypeSupport_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj
  );

extern 
TAO::Collocation_Proxy_Broker *
(*_TAO_PubComplexMessageDataWriter_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj
  );

extern 
TAO::Collocation_Proxy_Broker *
(*_TAO_PubComplexMessageDataReader_Proxy_Broker_Factory_function_pointer) (
    ::CORBA::Object_ptr obj
  );

// TAO_IDL - Generated from
// be/be_visitor_traits.cpp:61

// Traits specializations.
namespace TAO
{

#if !defined (_PUBCOMPLEXMESSAGETYPESUPPORT__TRAITS_)
#define _PUBCOMPLEXMESSAGETYPESUPPORT__TRAITS_
  
  template<>
  struct  Objref_Traits< ::PubComplexMessageTypeSupport>
  {
    static ::PubComplexMessageTypeSupport_ptr duplicate (
        ::PubComplexMessageTypeSupport_ptr
      );
    static void release (
        ::PubComplexMessageTypeSupport_ptr
      );
    static ::PubComplexMessageTypeSupport_ptr nil (void);
    static ::CORBA::Boolean marshal (
        ::PubComplexMessageTypeSupport_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */

#if !defined (_PUBCOMPLEXMESSAGEDATAWRITER__TRAITS_)
#define _PUBCOMPLEXMESSAGEDATAWRITER__TRAITS_
  
  template<>
  struct  Objref_Traits< ::PubComplexMessageDataWriter>
  {
    static ::PubComplexMessageDataWriter_ptr duplicate (
        ::PubComplexMessageDataWriter_ptr
      );
    static void release (
        ::PubComplexMessageDataWriter_ptr
      );
    static ::PubComplexMessageDataWriter_ptr nil (void);
    static ::CORBA::Boolean marshal (
        ::PubComplexMessageDataWriter_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */

#if !defined (_PUBCOMPLEXMESSAGEDATAREADER__TRAITS_)
#define _PUBCOMPLEXMESSAGEDATAREADER__TRAITS_
  
  template<>
  struct  Objref_Traits< ::PubComplexMessageDataReader>
  {
    static ::PubComplexMessageDataReader_ptr duplicate (
        ::PubComplexMessageDataReader_ptr
      );
    static void release (
        ::PubComplexMessageDataReader_ptr
      );
    static ::PubComplexMessageDataReader_ptr nil (void);
    static ::CORBA::Boolean marshal (
        ::PubComplexMessageDataReader_ptr p,
        TAO_OutputCDR & cdr
      );
  };

#endif /* end #if !defined */
}

// TAO_IDL - Generated from
// be/be_visitor_sequence/cdr_op_ch.cpp:71

#if !defined _TAO_CDR_OP_PubComplexMessageSeq_H_
#define _TAO_CDR_OP_PubComplexMessageSeq_H_

 ::CORBA::Boolean operator<< (
    TAO_OutputCDR &,
    const PubComplexMessageSeq &
  );
 ::CORBA::Boolean operator>> (
    TAO_InputCDR &,
    PubComplexMessageSeq &
  );

#endif /* _TAO_CDR_OP_PubComplexMessageSeq_H_ */

// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_ch.cpp:55

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const PubComplexMessageTypeSupport_ptr );
 ::CORBA::Boolean operator>> (TAO_InputCDR &, PubComplexMessageTypeSupport_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_ch.cpp:55

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const PubComplexMessageDataWriter_ptr );
 ::CORBA::Boolean operator>> (TAO_InputCDR &, PubComplexMessageDataWriter_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_interface/cdr_op_ch.cpp:55

 ::CORBA::Boolean operator<< (TAO_OutputCDR &, const PubComplexMessageDataReader_ptr );
 ::CORBA::Boolean operator>> (TAO_InputCDR &, PubComplexMessageDataReader_ptr &);

// TAO_IDL - Generated from
// be/be_visitor_sequence/serializer_op_ch.cpp:71

#if !defined _TAO_SERIALIZER_OP_PubComplexMessageSeq_H_
#define _TAO_SERIALIZER_OP_PubComplexMessageSeq_H_

 ::CORBA::Boolean _tao_is_bounded_size (
    const PubComplexMessageSeq &
  );
 size_t _dcps_max_marshaled_size (
    const PubComplexMessageSeq &
  );
 size_t _dcps_find_size (
    const PubComplexMessageSeq &
  );


 ::CORBA::Boolean operator<< (
    TAO::DCPS::Serializer &,
    const PubComplexMessageSeq &
  );
 ::CORBA::Boolean operator>> (
    TAO::DCPS::Serializer &,
    PubComplexMessageSeq &
  );

#endif /* _TAO_SERIALIZER_OP_PubComplexMessageSeq_H_ */

// TAO_IDL - Generated from
// be/be_codegen.cpp:1101

TAO_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "PubComplexMessageTypeSupportC.inl"
#endif /* defined INLINE */

#include /**/ "ace/post.h"

#endif /* ifndef */

