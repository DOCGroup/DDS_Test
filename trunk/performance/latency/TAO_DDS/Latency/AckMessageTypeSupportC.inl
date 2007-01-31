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


TAO_BEGIN_VERSIONED_NAMESPACE_DECL



// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ci.cpp:70

#if !defined (_ACKMESSAGETYPESUPPORT___CI_)
#define _ACKMESSAGETYPESUPPORT___CI_

ACE_INLINE
AckMessageTypeSupport::AckMessageTypeSupport (
    TAO_Stub *objref,
    ::CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (
        objref,
        _tao_collocated,
        servant,
        oc
      ),
    the_TAO_AckMessageTypeSupport_Proxy_Broker_ (0)
{
  this->AckMessageTypeSupport_setup_collocation ();
}

ACE_INLINE
AckMessageTypeSupport::AckMessageTypeSupport (
    IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS ( ::CORBA, Object) (ior, oc),
    the_TAO_AckMessageTypeSupport_Proxy_Broker_ (0)
{
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ci.cpp:70

#if !defined (_ACKMESSAGEDATAWRITER___CI_)
#define _ACKMESSAGEDATAWRITER___CI_

ACE_INLINE
AckMessageDataWriter::AckMessageDataWriter (
    TAO_Stub *objref,
    ::CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (
        objref,
        _tao_collocated,
        servant,
        oc
      ),
    the_TAO_AckMessageDataWriter_Proxy_Broker_ (0)
{
  this->AckMessageDataWriter_setup_collocation ();
}

ACE_INLINE
AckMessageDataWriter::AckMessageDataWriter (
    IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS ( ::CORBA, Object) (ior, oc),
    the_TAO_AckMessageDataWriter_Proxy_Broker_ (0)
{
}

#endif /* end #if !defined */

// TAO_IDL - Generated from
// be/be_visitor_interface/interface_ci.cpp:70

#if !defined (_ACKMESSAGEDATAREADER___CI_)
#define _ACKMESSAGEDATAREADER___CI_

ACE_INLINE
AckMessageDataReader::AckMessageDataReader (
    TAO_Stub *objref,
    ::CORBA::Boolean _tao_collocated,
    TAO_Abstract_ServantBase *servant,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS (CORBA, Object) (
        objref,
        _tao_collocated,
        servant,
        oc
      ),
    the_TAO_AckMessageDataReader_Proxy_Broker_ (0)
{
  this->AckMessageDataReader_setup_collocation ();
}

ACE_INLINE
AckMessageDataReader::AckMessageDataReader (
    IOP::IOR *ior,
    TAO_ORB_Core *oc
  )
  : ACE_NESTED_CLASS ( ::CORBA, Object) (ior, oc),
    the_TAO_AckMessageDataReader_Proxy_Broker_ (0)
{
}

#endif /* end #if !defined */


TAO_END_VERSIONED_NAMESPACE_DECL


