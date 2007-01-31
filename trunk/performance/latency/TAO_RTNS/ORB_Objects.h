/* -*- C++ -*- */
/**
 *  @file ORB_Objects.h
 *
 *  $Id: ORB_Objects.h,v 1.5 2004/08/16 23:53:12 jtc Exp $
 *
 *  @author Pradeep Gore <pradeep@oomworks.com>
 *
 *
 */

#ifndef TAO_Notify_ORB_OBJECTS_H
#define TAO_Notify_ORB_OBJECTS_H

#include /**/ "ace/pre.h"

#include "tao/RTCORBA/RTCORBA.h"
#include "tao/PortableServer/PortableServer.h"
#include "orbsvcs/NotifyExtC.h"
#include "orbsvcs/CosNamingC.h"

/**
 * @class TAO_Notify_ORB_Objects
 *
 * @brief Handy Objects that we keep asking the ORB for.
 *
 */
class TAO_Notify_ORB_Objects
{
public:
  /// Constuctor
  TAO_Notify_ORB_Objects (void);

  /// Destructor
  ~TAO_Notify_ORB_Objects ();

  /// Resolves all the references.
  void init (CORBA::ORB_var& orb ACE_ENV_ARG_DECL);

  /// Resolve Notification
  CosNotifyChannelAdmin::EventChannelFactory_ptr notify_factory (ACE_ENV_SINGLE_ARG_DECL);

  ///= Public Data
  CORBA::ORB_var orb_;

  PortableServer::POA_var root_poa_;

  CosNaming::NamingContextExt_var naming_;
};

#include /**/ "ace/post.h"
#endif /* TAO_Notify_ORB_OBJECTS_H */
