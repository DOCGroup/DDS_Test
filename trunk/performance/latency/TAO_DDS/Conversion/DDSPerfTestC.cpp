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
// .\be\be_codegen.cpp:292


#include "DDSPerfTestC.h"
#include "tao/CDR.h"
#include "tao/ORB_Core.h"
#include "ace/OS_NS_string.h"

#include "Stats.h"

#if !defined (__ACE_INLINE__)
#include "DDSPerfTestC.inl"
#endif /* !defined INLINE */

PubSub_Stats *pub_stats = 0;
PubSub_Stats *sub_stats = 0;

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// TAO_IDL - Generated from
// .\be\be_visitor_arg_traits.cpp:70

// Arg traits specializations.
namespace TAO
{
}


// TAO_IDL - Generated from 
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_DDSPERFTEST_OCTETSEQ_CS_)
#define _DDSPERFTEST_OCTETSEQ_CS_

DDSPerfTest::OctetSeq::OctetSeq (void)
{}

DDSPerfTest::OctetSeq::OctetSeq (
    ::CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        CORBA::Octet
      >
    (max)
{}

DDSPerfTest::OctetSeq::OctetSeq (
    ::CORBA::ULong max,
    ::CORBA::ULong length,
    ::CORBA::Octet * buffer,
    ::CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        CORBA::Octet
      >
    (max, length, buffer, release)
{}

DDSPerfTest::OctetSeq::OctetSeq (
    const OctetSeq &seq
  )
  : TAO_Unbounded_Sequence<
        CORBA::Octet
      >
    (seq)
{}

DDSPerfTest::OctetSeq::~OctetSeq (void)
{}

#endif /* end #if !defined */

// TAO_IDL - Generated from 
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/structure_cs.cpp:66



// TAO_IDL - Generated from 
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_DDSPERFTEST_NESTEDSEQ_CS_)
#define _DDSPERFTEST_NESTEDSEQ_CS_

DDSPerfTest::NestedSeq::NestedSeq (void)
{}

DDSPerfTest::NestedSeq::NestedSeq (
    ::CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        Nested
      >
    (max)
{}

DDSPerfTest::NestedSeq::NestedSeq (
    ::CORBA::ULong max,
    ::CORBA::ULong length,
    DDSPerfTest::Nested * buffer,
    ::CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        Nested
      >
    (max, length, buffer, release)
{}

DDSPerfTest::NestedSeq::NestedSeq (
    const NestedSeq &seq
  )
  : TAO_Unbounded_Sequence<
        Nested
      >
    (seq)
{}

DDSPerfTest::NestedSeq::~NestedSeq (void)
{}

#endif /* end #if !defined */

// TAO_IDL - Generated from 
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/structure_cs.cpp:66



// TAO_IDL - Generated from 
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/sequence_cs.cpp:65

#if !defined (_DDSPERFTEST_OUTERSEQ_CS_)
#define _DDSPERFTEST_OUTERSEQ_CS_

DDSPerfTest::OuterSeq::OuterSeq (void)
{}

DDSPerfTest::OuterSeq::OuterSeq (
    ::CORBA::ULong max
  )
  : TAO_Unbounded_Sequence<
        Outer
      >
    (max)
{}

DDSPerfTest::OuterSeq::OuterSeq (
    ::CORBA::ULong max,
    ::CORBA::ULong length,
    DDSPerfTest::Outer * buffer,
    ::CORBA::Boolean release
  )
  : TAO_Unbounded_Sequence<
        Outer
      >
    (max, length, buffer, release)
{}

DDSPerfTest::OuterSeq::OuterSeq (
    const OuterSeq &seq
  )
  : TAO_Unbounded_Sequence<
        Outer
      >
    (seq)
{}

DDSPerfTest::OuterSeq::~OuterSeq (void)
{}

#endif /* end #if !defined */

// TAO_IDL - Generated from 
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/structure_cs.cpp:66



// TAO_IDL - Generated from 
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/structure_cs.cpp:66



// TAO_IDL - Generated from 
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/structure_cs.cpp:66



// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_DDSPerfTest_OctetSeq_CPP_
#define _TAO_CDR_OP_DDSPerfTest_OctetSeq_CPP_

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const DDSPerfTest::OctetSeq &_tao_sequence
  )
{
  const ::CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      
#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
      {
        TAO_Unbounded_Sequence< ::CORBA::Octet> *_tao_octet_seq = 
          static_cast<TAO_Unbounded_Sequence< ::CORBA::Octet> *> (const_cast<DDSPerfTest::OctetSeq *> (&_tao_sequence));
        if (_tao_octet_seq->mb ())
          return strm.write_octet_array_mb (_tao_octet_seq->mb ());
        else
          return strm.write_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
      }
      
#else /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
      return strm.write_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    
#endif /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
    }
  
  return false;
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    DDSPerfTest::OctetSeq &_tao_sequence
  )
{
  ::CORBA::ULong _tao_seq_len;
  
  if (strm >> _tao_seq_len)
    {
      // Add a check to the length of the sequence
      // to make sure it does not exceed the length
      // of the stream. (See bug 58.)
      if (_tao_seq_len > strm.length ())
        {
          return false;
        }
      
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return true;
        }
      
      // Retrieve all the elements.
      
#if (TAO_NO_COPY_OCTET_SEQUENCES == 1)
      if (ACE_BIT_DISABLED (strm.start ()->flags (),
      ACE_Message_Block::DONT_DELETE))
      {
        TAO_ORB_Core* orb_core = strm.orb_core ();
        if (orb_core != 0 &&
        strm.orb_core ()->resource_factory ()->
        input_cdr_allocator_type_locked () == 1)
        {
          TAO_Unbounded_Sequence< ::CORBA::Octet> *oseq = 
            static_cast<TAO_Unbounded_Sequence< ::CORBA::Octet> *> (&_tao_sequence);
          oseq->replace (_tao_seq_len, strm.start ());
          oseq->mb ()->wr_ptr (oseq->mb()->rd_ptr () + _tao_seq_len);
          strm.skip_bytes (_tao_seq_len);
          return 1;
        }
      }
      return strm.read_octet_array (_tao_sequence.get_buffer (), _tao_seq_len);
#else /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
      return strm.read_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    
#endif /* TAO_NO_COPY_OCTET_SEQUENCES == 0 */
    
    }
  
  return false;
}

#endif /* _TAO_CDR_OP_DDSPerfTest_OctetSeq_CPP_ */

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/cdr_op_cs.cpp:61

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const DDSPerfTest::Nested &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.info.in ()) &&
    (strm << _tao_aggregate.index);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    DDSPerfTest::Nested &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.info.out ()) &&
    (strm >> _tao_aggregate.index);
}

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_DDSPerfTest_NestedSeq_CPP_
#define _TAO_CDR_OP_DDSPerfTest_NestedSeq_CPP_

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const DDSPerfTest::NestedSeq &_tao_sequence
  )
{
  const ::CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      ::CORBA::Boolean _tao_marshal_flag = true;
      
      for ( ::CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm << _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    }
  
  return false;
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    DDSPerfTest::NestedSeq &_tao_sequence
  )
{
  ::CORBA::ULong _tao_seq_len;
  
  if (strm >> _tao_seq_len)
    {
      // Add a check to the length of the sequence
      // to make sure it does not exceed the length
      // of the stream. (See bug 58.)
      if (_tao_seq_len > strm.length ())
        {
          return false;
        }
      
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return true;
        }
      
      // Retrieve all the elements.
      ::CORBA::Boolean _tao_marshal_flag = true;
      
      for ( ::CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm >> _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    
    }
  
  return false;
}

#endif /* _TAO_CDR_OP_DDSPerfTest_NestedSeq_CPP_ */

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/cdr_op_cs.cpp:61

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const DDSPerfTest::Outer &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.length) &&
    (strm << _tao_aggregate.nested_member);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    DDSPerfTest::Outer &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.length) &&
    (strm >> _tao_aggregate.nested_member);
}

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/cdr_op_cs.cpp:96

#if !defined _TAO_CDR_OP_DDSPerfTest_OuterSeq_CPP_
#define _TAO_CDR_OP_DDSPerfTest_OuterSeq_CPP_

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const DDSPerfTest::OuterSeq &_tao_sequence
  )
{
  const ::CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      ::CORBA::Boolean _tao_marshal_flag = true;
      
      for ( ::CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm << _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    }
  
  return false;
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    DDSPerfTest::OuterSeq &_tao_sequence
  )
{
  ::CORBA::ULong _tao_seq_len;
  
  if (strm >> _tao_seq_len)
    {
      // Add a check to the length of the sequence
      // to make sure it does not exceed the length
      // of the stream. (See bug 58.)
      if (_tao_seq_len > strm.length ())
        {
          return false;
        }
      
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return true;
        }
      
      // Retrieve all the elements.
      ::CORBA::Boolean _tao_marshal_flag = true;
      
      for ( ::CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm >> _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    
    }
  
  return false;
}

#endif /* _TAO_CDR_OP_DDSPerfTest_OuterSeq_CPP_ */

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/cdr_op_cs.cpp:61

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const DDSPerfTest::PubMessage &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.seqnum) &&
    (strm << _tao_aggregate.data);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    DDSPerfTest::PubMessage &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.seqnum) &&
    (strm >> _tao_aggregate.data);
}

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/cdr_op_cs.cpp:61

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const DDSPerfTest::PubComplexMessage &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.seqnum) &&
    (strm << _tao_aggregate.data);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    DDSPerfTest::PubComplexMessage &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.seqnum) &&
    (strm >> _tao_aggregate.data);
}

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/cdr_op_cs.cpp:61

::CORBA::Boolean operator<< (
    TAO_OutputCDR &strm,
    const DDSPerfTest::AckMessage &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.seqnum);
}

::CORBA::Boolean operator>> (
    TAO_InputCDR &strm,
    DDSPerfTest::AckMessage &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.seqnum);
}

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/serializer_op_cs.cpp:96

#if !defined _TAO_SERIALIZER_OP_DDSPerfTest_OctetSeq_CPP_
#define _TAO_SERIALIZER_OP_DDSPerfTest_OctetSeq_CPP_

::CORBA::Boolean _tao_is_bounded_size (
    const DDSPerfTest::OctetSeq &_tao_sequence
  )
{
  ACE_UNUSED_ARG(_tao_sequence);
  return false; /* seq<predef'd> */
}

size_t _dcps_max_marshaled_size (
    const DDSPerfTest::OctetSeq &_tao_sequence
  )
{
  return _dcps_max_marshaled_size_ulong () + _dcps_max_marshaled_size_octet ()
       * _tao_sequence.maximum();
}

size_t _dcps_find_size (
    const DDSPerfTest::OctetSeq &_tao_sequence
  )
{
  //primitive types are fixed size so OK to call max_marshaled_size
  return _dcps_max_marshaled_size_ulong () + _dcps_max_marshaled_size_octet ()
       * _tao_sequence.length();
}

::CORBA::Boolean operator<< (
    TAO::DCPS::Serializer &strm,
    const DDSPerfTest::OctetSeq &_tao_sequence
  )
{
  const ::CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      return strm.write_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    }
  
  return 0;
}

::CORBA::Boolean operator>> (
    TAO::DCPS::Serializer &strm,
    DDSPerfTest::OctetSeq &_tao_sequence
  )
{
  ::CORBA::ULong _tao_seq_len;
  
  if (strm >> _tao_seq_len)
    {
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return 1;
        }
      
      // Retrieve all the elements.
      return strm.read_octet_array (_tao_sequence.get_buffer (), _tao_sequence.length ());
    
    }
  
  return 0;
}

#endif /* _TAO_SERIALIZER_OP_DDSPerfTest_OctetSeq_CPP_ */

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/serializer_op_cs.cpp:61

size_t _dcps_max_marshaled_size (const DDSPerfTest::Nested& _tao_aggregate)
{
  ACE_UNUSED_ARG (_tao_aggregate); // sometimes not used - avoid warning
  return 
    _dcps_max_marshaled_size_ulong () + 0 +
    _dcps_max_marshaled_size (_tao_aggregate.index);
}

::CORBA::Boolean _tao_is_bounded_size (const DDSPerfTest::Nested& _tao_aggregate)
{
  ACE_UNUSED_ARG (_tao_aggregate); // often not used - avoid warning
  return
    false /* unbounded string */ &&
     true ;
}

size_t _dcps_find_size(const DDSPerfTest::Nested& _tao_aggregate)
{
  ACE_UNUSED_ARG(_tao_aggregate); // sometimes not used - avoid warning
  return 
    _dcps_max_marshaled_size_ulong() + ACE_OS::strlen(_tao_aggregate.info.in ()) +
    _dcps_max_marshaled_size (_tao_aggregate.index);
}

::CORBA::Boolean operator<< (
    TAO::DCPS::Serializer &strm,
    const DDSPerfTest::Nested &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.info.in ()) &&
    (strm << _tao_aggregate.index);
}

::CORBA::Boolean operator>> (
    TAO::DCPS::Serializer &strm,
    DDSPerfTest::Nested &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.info.out ()) &&
    (strm >> _tao_aggregate.index);
}

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/serializer_op_cs.cpp:96

#if !defined _TAO_SERIALIZER_OP_DDSPerfTest_NestedSeq_CPP_
#define _TAO_SERIALIZER_OP_DDSPerfTest_NestedSeq_CPP_

::CORBA::Boolean _tao_is_bounded_size (
    const DDSPerfTest::NestedSeq &_tao_sequence
  )
{
  ACE_UNUSED_ARG(_tao_sequence);
  return false; /* unbounded sequence */
}

size_t _dcps_max_marshaled_size (
    const DDSPerfTest::NestedSeq &_tao_sequence
  )
{
  DDSPerfTest::Nested a_base_value;
  return _dcps_max_marshaled_size_ulong () + 
    _tao_sequence.maximum() * 
    _dcps_max_marshaled_size (a_base_value);
}

size_t _dcps_find_size (
    const DDSPerfTest::NestedSeq &_tao_sequence
  )
{
  //iterate over the sequence to find the current size
  size_t the_length = _dcps_max_marshaled_size_ulong ();
  for ( ::CORBA::ULong i = 0; i < _tao_sequence.length(); ++i)
    {
      the_length += _dcps_find_size (_tao_sequence[i]);
    }
  return the_length;
}

::CORBA::Boolean operator<< (
    TAO::DCPS::Serializer &strm,
    const DDSPerfTest::NestedSeq &_tao_sequence
  )
{
  const ::CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      ::CORBA::Boolean _tao_marshal_flag = 1;
      
      for ( ::CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm << _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    }
  
  return 0;
}

::CORBA::Boolean operator>> (
    TAO::DCPS::Serializer &strm,
    DDSPerfTest::NestedSeq &_tao_sequence
  )
{
  ::CORBA::ULong _tao_seq_len;
  
  if (strm >> _tao_seq_len)
    {
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return 1;
        }
      
      // Retrieve all the elements.
      ::CORBA::Boolean _tao_marshal_flag = 1;
      
      for ( ::CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm >> _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    
    }
  
  return 0;
}

#endif /* _TAO_SERIALIZER_OP_DDSPerfTest_NestedSeq_CPP_ */

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/serializer_op_cs.cpp:61

size_t _dcps_max_marshaled_size (const DDSPerfTest::Outer& _tao_aggregate)
{
  ACE_UNUSED_ARG (_tao_aggregate); // sometimes not used - avoid warning
  return 
    _dcps_max_marshaled_size (_tao_aggregate.length) +
    _dcps_max_marshaled_size (_tao_aggregate.nested_member);
}

::CORBA::Boolean _tao_is_bounded_size (const DDSPerfTest::Outer& _tao_aggregate)
{
  ACE_UNUSED_ARG (_tao_aggregate); // often not used - avoid warning
  return
     true  &&
    _tao_is_bounded_size (_tao_aggregate.nested_member);
}

size_t _dcps_find_size(const DDSPerfTest::Outer& _tao_aggregate)
{
  ACE_UNUSED_ARG(_tao_aggregate); // sometimes not used - avoid warning
  return 
    _dcps_max_marshaled_size (_tao_aggregate.length) +
    _dcps_find_size (_tao_aggregate.nested_member);
}

::CORBA::Boolean operator<< (
    TAO::DCPS::Serializer &strm,
    const DDSPerfTest::Outer &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.length) &&
    (strm << _tao_aggregate.nested_member);
}

::CORBA::Boolean operator>> (
    TAO::DCPS::Serializer &strm,
    DDSPerfTest::Outer &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.length) &&
    (strm >> _tao_aggregate.nested_member);
}

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_sequence/serializer_op_cs.cpp:96

#if !defined _TAO_SERIALIZER_OP_DDSPerfTest_OuterSeq_CPP_
#define _TAO_SERIALIZER_OP_DDSPerfTest_OuterSeq_CPP_

::CORBA::Boolean _tao_is_bounded_size (
    const DDSPerfTest::OuterSeq &_tao_sequence
  )
{
  ACE_UNUSED_ARG(_tao_sequence);
  return false; /* unbounded sequence */
}

size_t _dcps_max_marshaled_size (
    const DDSPerfTest::OuterSeq &_tao_sequence
  )
{
  DDSPerfTest::Outer a_base_value;
  return _dcps_max_marshaled_size_ulong () + 
    _tao_sequence.maximum() * 
    _dcps_max_marshaled_size (a_base_value);
}

size_t _dcps_find_size (
    const DDSPerfTest::OuterSeq &_tao_sequence
  )
{
  //iterate over the sequence to find the current size
  size_t the_length = _dcps_max_marshaled_size_ulong ();
  for ( ::CORBA::ULong i = 0; i < _tao_sequence.length(); ++i)
    {
      the_length += _dcps_find_size (_tao_sequence[i]);
    }
  return the_length;
}

::CORBA::Boolean operator<< (
    TAO::DCPS::Serializer &strm,
    const DDSPerfTest::OuterSeq &_tao_sequence
  )
{
  const ::CORBA::ULong _tao_seq_len = _tao_sequence.length ();
  
  if (strm << _tao_seq_len)
    {
      // Encode all elements.
      ::CORBA::Boolean _tao_marshal_flag = 1;
      
      for ( ::CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm << _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    }
  
  return 0;
}

::CORBA::Boolean operator>> (
    TAO::DCPS::Serializer &strm,
    DDSPerfTest::OuterSeq &_tao_sequence
  )
{
  ::CORBA::ULong _tao_seq_len;
  
  if (strm >> _tao_seq_len)
    {
      // Set the length of the sequence.
      _tao_sequence.length (_tao_seq_len);
      
      // If length is 0 we return true.
      if (0 >= _tao_seq_len) 
        {
          return 1;
        }
      
      // Retrieve all the elements.
      ::CORBA::Boolean _tao_marshal_flag = 1;
      
      for ( ::CORBA::ULong i = 0; i < _tao_seq_len && _tao_marshal_flag; ++i)
        {
          _tao_marshal_flag = (strm >> _tao_sequence[i]);
        }
      
      return _tao_marshal_flag;
    
    }
  
  return 0;
}

#endif /* _TAO_SERIALIZER_OP_DDSPerfTest_OuterSeq_CPP_ */

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/serializer_op_cs.cpp:61

::CORBA::Boolean _dcps_has_key (const DDSPerfTest::PubMessage& ) { 
  return false;
}
size_t _dcps_max_marshaled_size (const DDSPerfTest::PubMessage& _tao_aggregate)
{
  ACE_UNUSED_ARG (_tao_aggregate); // sometimes not used - avoid warning
  return 
    _dcps_max_marshaled_size (_tao_aggregate.seqnum) +
    _dcps_max_marshaled_size (_tao_aggregate.data);
}

::CORBA::Boolean _tao_is_bounded_size (const DDSPerfTest::PubMessage& _tao_aggregate)
{
  ACE_UNUSED_ARG (_tao_aggregate); // often not used - avoid warning
  return
     true  &&
    _tao_is_bounded_size (_tao_aggregate.data);
}

size_t _dcps_find_size(const DDSPerfTest::PubMessage& _tao_aggregate)
{
  ACE_UNUSED_ARG(_tao_aggregate); // sometimes not used - avoid warning
  return 
    _dcps_max_marshaled_size (_tao_aggregate.seqnum) +
    _dcps_find_size (_tao_aggregate.data);
}

::CORBA::Boolean operator<< (
    TAO::DCPS::Serializer &strm,
    const DDSPerfTest::PubMessage &_tao_aggregate
  )
{
  if (!(strm << _tao_aggregate.seqnum)) return false;
  pub_stats->start ();
  strm << _tao_aggregate.data;
  pub_stats->stop ();
  pub_stats->sample_usecs ();
  return true;
}

::CORBA::Boolean operator>> (
    TAO::DCPS::Serializer &strm,
    DDSPerfTest::PubMessage &_tao_aggregate
  )
{
  if (!(strm >> _tao_aggregate.seqnum)) return false;
  sub_stats->start ();
  strm >> _tao_aggregate.data;
  sub_stats->stop ();
  sub_stats->sample_usecs ();
  return true;
}

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/serializer_op_cs.cpp:61

::CORBA::Boolean _dcps_has_key (const DDSPerfTest::PubComplexMessage& ) { 
  return false;
}
size_t _dcps_max_marshaled_size (const DDSPerfTest::PubComplexMessage& _tao_aggregate)
{
  ACE_UNUSED_ARG (_tao_aggregate); // sometimes not used - avoid warning
  return 
    _dcps_max_marshaled_size (_tao_aggregate.seqnum) +
    _dcps_max_marshaled_size (_tao_aggregate.data);
}

::CORBA::Boolean _tao_is_bounded_size (const DDSPerfTest::PubComplexMessage& _tao_aggregate)
{
  ACE_UNUSED_ARG (_tao_aggregate); // often not used - avoid warning
  return
     true  &&
    _tao_is_bounded_size (_tao_aggregate.data);
}

size_t _dcps_find_size(const DDSPerfTest::PubComplexMessage& _tao_aggregate)
{
  ACE_UNUSED_ARG(_tao_aggregate); // sometimes not used - avoid warning
  return 
    _dcps_max_marshaled_size (_tao_aggregate.seqnum) +
    _dcps_find_size (_tao_aggregate.data);
}

::CORBA::Boolean operator<< (
    TAO::DCPS::Serializer &strm,
    const DDSPerfTest::PubComplexMessage &_tao_aggregate
  )
{
  if (!(strm << _tao_aggregate.seqnum)) return false;
  pub_stats->start ();
  strm << _tao_aggregate.data;
  pub_stats->stop ();
  pub_stats->sample_usecs ();
  return true;
}

::CORBA::Boolean operator>> (
    TAO::DCPS::Serializer &strm,
    DDSPerfTest::PubComplexMessage &_tao_aggregate
  )
{
  if (!(strm >> _tao_aggregate.seqnum)) return false;
  sub_stats->start ();
  strm >> _tao_aggregate.data;
  sub_stats->stop ();
  sub_stats->sample_usecs ();
  return true;
}

// TAO_IDL - Generated from
// w:\ace_wrappers\tao\tao_idl\be\be_visitor_structure/serializer_op_cs.cpp:61

::CORBA::Boolean _dcps_has_key (const DDSPerfTest::AckMessage& ) { 
  return false;
}
size_t _dcps_max_marshaled_size (const DDSPerfTest::AckMessage& _tao_aggregate)
{
  ACE_UNUSED_ARG (_tao_aggregate); // sometimes not used - avoid warning
  return 
    _dcps_max_marshaled_size (_tao_aggregate.seqnum);
}

::CORBA::Boolean _tao_is_bounded_size (const DDSPerfTest::AckMessage& _tao_aggregate)
{
  ACE_UNUSED_ARG (_tao_aggregate); // often not used - avoid warning
  return
     true ;
}

size_t _dcps_find_size(const DDSPerfTest::AckMessage& _tao_aggregate)
{
  ACE_UNUSED_ARG(_tao_aggregate); // sometimes not used - avoid warning
  return 
    _dcps_max_marshaled_size (_tao_aggregate.seqnum);
}

::CORBA::Boolean operator<< (
    TAO::DCPS::Serializer &strm,
    const DDSPerfTest::AckMessage &_tao_aggregate
  )
{
  return
    (strm << _tao_aggregate.seqnum);
}

::CORBA::Boolean operator>> (
    TAO::DCPS::Serializer &strm,
    DDSPerfTest::AckMessage &_tao_aggregate
  )
{
  return
    (strm >> _tao_aggregate.seqnum);
}


TAO_END_VERSIONED_NAMESPACE_DECL

