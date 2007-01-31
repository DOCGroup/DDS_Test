/* -*- C++ -*- */
/**
 *  @file Consumer.h
 *
 *  $Id: Consumer.h,v 1.6 2005/07/04 08:55:12 jwillemsen Exp $
 *
 *  @author Pradeep Gore <pradeep@oomworks.com>
 *
 *
 */

#ifndef TAO_Notify_CONSUMER_H
#define TAO_Notify_CONSUMER_H

#include /**/ "ace/pre.h"

#include "ORB_Objects.h"
#include "tao/RTCORBA/RTCORBA.h"
#include "orbsvcs/CosNotifyChannelAdminS.h"
#include "orbsvcs/CosNotifyCommC.h"
#include "ace/SString.h"
#include "ace/Condition_Thread_Mutex.h"


class TAO_Notify_Lanes_Supplier;

/**
 * @class TAO_Notify_Lanes_Consumer
 *
 * @brief Consumer
 *
 */

class TAO_Notify_Lanes_Consumer
  : public POA_CosNotifyComm::StructuredPushConsumer
{
public:
  /// Constuctor
  TAO_Notify_Lanes_Consumer (TAO_Notify_ORB_Objects& orb_objects);

  /// Init
  void init (CosNotifyChannelAdmin::ConsumerAdmin_var& admin_sub,
             TAO_Notify_Lanes_Supplier* publisher,
             ACE_CString& event_type ACE_ENV_ARG_DECL);

  /// Run
  void run (ACE_ENV_SINGLE_ARG_DECL_NOT_USED);


  // The Consumer Admin
  CosNotifyChannelAdmin::ConsumerAdmin_var admin_sub;

  // The Consumer Admin
  CosNotifyChannelAdmin::SupplierAdmin_var admin_pub;

  TAO_Notify_Lanes_Supplier* pub;

protected:
  // = Data members
  /// ORB Objects.
  TAO_Notify_ORB_Objects orb_objects_;

  /// The proxy that we are connected to.
  CosNotifyChannelAdmin::StructuredProxyPushSupplier_var proxy_supplier_;

  /// The proxy_supplier id.
  CosNotifyChannelAdmin::ProxyID proxy_supplier_id_;


  /// The Type the Consumer should subscribe to.
  ACE_CString event_type_;


  CORBA::Long sample_num_;

  // = Methods
  /// Destructor
  virtual ~TAO_Notify_Lanes_Consumer (void);


  /// Connect the Consumer to the EventChannel.
  /// Creates a new proxy supplier and connects to it.
  void connect (ACE_ENV_SINGLE_ARG_DECL);

  /// Disconnect the supplier.
  void disconnect (ACE_ENV_SINGLE_ARG_DECL);

  /// Deactivate.
  void deactivate (ACE_ENV_SINGLE_ARG_DECL);

  // = NotifyPublish method
  virtual void offer_change (
        const CosNotification::EventTypeSeq & added,
        const CosNotification::EventTypeSeq & removed
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        CosNotifyComm::InvalidEventType
      ));

  // = StructuredPushSupplier methods
  virtual void push_structured_event (
        const CosNotification::StructuredEvent & notification
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        CosEventComm::Disconnected
       ));

  virtual void disconnect_structured_push_consumer (
       ACE_ENV_SINGLE_ARG_DECL
        )
      ACE_THROW_SPEC ((
        CORBA::SystemException
      ));
};


/**
 * @class TAO_Notify_Lanes_Supplier
 *
 * @brief Implement a Structured Supplier.
 *
 */
class TAO_Notify_Lanes_Supplier
  : public POA_CosNotifyComm::StructuredPushSupplier
{
 public:
  // = Initialization and Termination code

  /// Constructor.
  TAO_Notify_Lanes_Supplier (TAO_Notify_ORB_Objects& orb_objects);

  /// Init
  void init (CosNotifyChannelAdmin::SupplierAdmin_var& admin);

  /// Run
  void run (ACE_ENV_SINGLE_ARG_DECL);

  /// Send one event.
  virtual void send_event (const CosNotification::StructuredEvent& event ACE_ENV_ARG_DECL);
protected:
  // = Protected Methods

  /// Connect the Supplier to the EventChannel.
  /// Creates a new proxy consumer and connects to it.
  void connect (ACE_ENV_SINGLE_ARG_DECL);

  /// Disconnect the supplier.
  void disconnect (ACE_ENV_SINGLE_ARG_DECL);

  /// Deactivate.
  void deactivate (ACE_ENV_SINGLE_ARG_DECL);


  // = NotifySubscribe
  virtual void subscription_change (
        const CosNotification::EventTypeSeq & added,
        const CosNotification::EventTypeSeq & removed
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        CosNotifyComm::InvalidEventType
      ));


  /// Destructor
  virtual ~TAO_Notify_Lanes_Supplier ();

  // = StructuredPushSupplier method
  virtual void disconnect_structured_push_supplier (ACE_ENV_SINGLE_ARG_DECL)
    ACE_THROW_SPEC ((
                     CORBA::SystemException
                     ));
  /// = Data members

  /// ORB Objects.
  TAO_Notify_ORB_Objects orb_objects_;

  /// The proxy that we are connected to.
  CosNotifyChannelAdmin::StructuredProxyPushConsumer_var proxy_consumer_;
  /// This supplier's id.
  CosNotifyChannelAdmin::ProxyID proxy_consumer_id_;

  // The ORB that we use.
  CORBA::ORB_var orb_;

  // The Supplier Admin
  CosNotifyChannelAdmin::SupplierAdmin_var admin_;

  /// Lock to serialize internal state.
  TAO_SYNCH_MUTEX lock_;

  /// Condition that consumers are connected.
  TAO_SYNCH_CONDITION consumers_connected_;

  int consumer_count_;
};

#include /**/ "ace/post.h"
#endif /* TAO_Notify_CONSUMER_H */
