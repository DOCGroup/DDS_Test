// $Id: ORB_Objects.cpp,v 1.4 2003/09/04 03:27:24 ossama Exp $

#include "ORB_Objects.h"

ACE_RCSID (Notify, TAO_Notify_ORB_Objects, "$Id: ORB_Objects.cpp,v 1.4 2003/09/04 03:27:24 ossama Exp $")

TAO_Notify_ORB_Objects::TAO_Notify_ORB_Objects (void)
{
}

void
TAO_Notify_ORB_Objects::init (CORBA::ORB_var& orb ACE_ENV_ARG_DECL)
{
  this->orb_ = orb;

  CORBA::Object_var object =  this->orb_->resolve_initial_references("RootPOA"
                                                                     ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  this->root_poa_ = PortableServer::POA::_narrow (object.in () ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  // Resolve the Naming service
  object = this->orb_->resolve_initial_references ("NameService" ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  this->naming_ = CosNaming::NamingContextExt::_narrow (object.in ()
                                                                    ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

TAO_Notify_ORB_Objects::~TAO_Notify_ORB_Objects ()
{
}

CosNotifyChannelAdmin::EventChannelFactory_ptr
TAO_Notify_ORB_Objects::notify_factory (ACE_ENV_SINGLE_ARG_DECL)
{
  CosNotifyChannelAdmin::EventChannelFactory_var ecf;

  // Look for the Notification Service
  CosNaming::Name name (1);
  name.length (1);
  name[0].id = CORBA::string_dup ("NotifyEventChannelFactory");

  CORBA::Object_var object = this->naming_->resolve (name ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (ecf._retn ());

  ecf = CosNotifyChannelAdmin::EventChannelFactory::_narrow (object.in() ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (ecf._retn ());

  return ecf._retn ();
}
