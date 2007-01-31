// $Id: Consumer.cpp,v 1.5 2003/10/28 18:34:05 bala Exp $

#include "Consumer.h"
#include <iostream>
#include "pubmessageC.h"

#define EVENT_COUNT 500


ACE_RCSID (Notify,
           TAO_Notify_Lanes_Consumer,
           "$Id: Consumer.cpp,v 1.5 2003/10/28 18:34:05 bala Exp $")


TAO_Notify_Lanes_Consumer::TAO_Notify_Lanes_Consumer (TAO_Notify_ORB_Objects& orb_objects)
  : orb_objects_ (orb_objects),
    sample_num_ (1)
{
}

TAO_Notify_Lanes_Consumer::~TAO_Notify_Lanes_Consumer (void)
{
}

void
TAO_Notify_Lanes_Consumer::init (CosNotifyChannelAdmin::ConsumerAdmin_var& admin1,
                                 TAO_Notify_Lanes_Supplier* supplier, 
                                 ACE_CString& event_type ACE_ENV_ARG_DECL)
{
  this->admin_sub = admin1;
  this->pub = supplier;
  this->event_type_ = event_type;

  this->connect (ACE_ENV_SINGLE_ARG_PARAMETER);
}


void
TAO_Notify_Lanes_Consumer::run (ACE_ENV_SINGLE_ARG_DECL_NOT_USED)
{
  // Nothing to do.
}

void
TAO_Notify_Lanes_Consumer::connect (ACE_ENV_SINGLE_ARG_DECL)
{
  // Activate the consumer with the default_POA_
  CosNotifyComm::StructuredPushConsumer_var objref =
    this->_this (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  CosNotifyChannelAdmin::ProxySupplier_var proxysupplier =
    this->admin_sub->obtain_notification_push_supplier (CosNotifyChannelAdmin::STRUCTURED_EVENT
                                                     , proxy_supplier_id_ ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  ACE_ASSERT (!CORBA::is_nil (proxysupplier.in ()));

  // narrow
  this->proxy_supplier_ =
    CosNotifyChannelAdmin::StructuredProxyPushSupplier::_narrow (proxysupplier.in () ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  ACE_ASSERT (!CORBA::is_nil (proxy_supplier_.in ()));

  this->proxy_supplier_->connect_structured_push_consumer (objref.in ()
                                                     ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  // Call subscription_change to inform the supplier that this consumer is available.
  CosNotification::EventTypeSeq added (1);
  CosNotification::EventTypeSeq removed;

  added.length (1);
  added[0].domain_name = CORBA::string_dup ("PING");
  added[0].type_name = CORBA::string_dup ("T_PING");

  this->proxy_supplier_->subscription_change (added,
                                              removed ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  ACE_DEBUG ((LM_DEBUG,
              "Subscribed to PING, T_PING\n"));
}

void
TAO_Notify_Lanes_Consumer::disconnect (ACE_ENV_SINGLE_ARG_DECL)
{
  this->proxy_supplier_->disconnect_structured_push_supplier(ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;
}

void
TAO_Notify_Lanes_Consumer::offer_change (const CosNotification::EventTypeSeq & /*added*/,
                               const CosNotification::EventTypeSeq & /*removed*/
                               ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((
                   CORBA::SystemException,
                   CosNotifyComm::InvalidEventType
                   ))
{
  // No-Op.
}

void
TAO_Notify_Lanes_Consumer::push_structured_event (const CosNotification::StructuredEvent & notification
                                        ACE_ENV_ARG_DECL_NOT_USED)
  ACE_THROW_SPEC ((
                   CORBA::SystemException,
                   CosEventComm::Disconnected
                   ))
{
  ACE_TRY_NEW_ENV
    {
      //      std::cout << "\ngot message at consumer" << std::endl;


      //const char* domain_name =
      //notification.header.fixed_header.event_type.domain_name;

      //const char* type_name =
      //notification.header.fixed_header.event_type.type_name;


      /*      CORBA::OctetSeq *msg;
      //      data.length (4);
      CORBA::Long sequence_num;
      notification.remainder_of_body >>= msg;
      sequence_num = (CORBA::Long)(*msg)[0]; */

      pubdata::pubmessage_var pub_msg;
      notification.remainder_of_body >>=pub_msg;
      CORBA::Long sequence_num = pub_msg->seqnum;


      if (sequence_num == 0)
        {
          std::cout << "Consumer: Done!!" << std::endl;
          
          // Disconnect from the EC
          this->disconnect (ACE_ENV_SINGLE_ARG_PARAMETER);

          // Deactivate this object.
          this->deactivate (ACE_ENV_SINGLE_ARG_PARAMETER);

          // We received the event, shutdown the ORB.
          this->orb_objects_.orb_->shutdown (1);
        }

      if (sequence_num != this->sample_num_)
        {
          ACE_DEBUG ((LM_ERROR,
                      "Error - subscriber: received sequence_num %d at %d",
                      sequence_num, this->sample_num_));
          exit (1);
        }

  
      // Create the events - one of each type
      // Event 1
      CosNotification::StructuredEvent data;
      data.header.fixed_header.event_type.domain_name =
        CORBA::string_dup("PONG");
      data.header.fixed_header.event_type.type_name =
        CORBA::string_dup("T_PONG");
      data.header.fixed_header.event_name = CORBA::string_dup("");
      data.header.variable_header.length (0); // put nothing here
      data.filterable_data.length (0);
      data.remainder_of_body <<= sequence_num;


      this->sample_num_++;
      
      /*ACE_DEBUG ((LM_DEBUG,
                  "Consumer  received event, domain = %s, type = %s, seq_num = %d\n",
                  domain_name,
                  type_name,
                  sequence_num));*/

      this->pub->send_event (data);
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION(ACE_ANY_EXCEPTION,
                          ACE_TEXT ("Consumer error "));

      return;
    }
  ACE_ENDTRY;
}

void
TAO_Notify_Lanes_Consumer::deactivate (ACE_ENV_SINGLE_ARG_DECL)
{
  PortableServer::POA_var poa (this->_default_POA (ACE_ENV_SINGLE_ARG_PARAMETER));
  ACE_CHECK;

  PortableServer::ObjectId_var id (poa->servant_to_id (this
                                                       ACE_ENV_ARG_PARAMETER));
  ACE_CHECK;

  poa->deactivate_object (id.in()
                          ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

void
TAO_Notify_Lanes_Consumer::disconnect_structured_push_consumer (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  this->deactivate (ACE_ENV_SINGLE_ARG_PARAMETER);
}

//**************************************************************************************


TAO_Notify_Lanes_Supplier::TAO_Notify_Lanes_Supplier  (TAO_Notify_ORB_Objects& orb_objects)
  : orb_objects_ (orb_objects)
  , proxy_consumer_id_ (0)
  , consumers_connected_ (lock_)
  , consumer_count_ (0)
{
}

TAO_Notify_Lanes_Supplier::~TAO_Notify_Lanes_Supplier ()
{
}

void
TAO_Notify_Lanes_Supplier::init (CosNotifyChannelAdmin::SupplierAdmin_var& admin)
{
  // First initialize the class members.
  this->admin_ = admin;
  this->connect (ACE_ENV_SINGLE_ARG_PARAMETER);
}

void
TAO_Notify_Lanes_Supplier::run (ACE_ENV_SINGLE_ARG_DECL)
{
}

void
TAO_Notify_Lanes_Supplier::connect (ACE_ENV_SINGLE_ARG_DECL)
{
  // Activate the supplier object.
  CosNotifyComm::StructuredPushSupplier_var objref = this->_this (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  // Obtain the proxy.
  CosNotifyChannelAdmin::ProxyConsumer_var proxyconsumer =
    this->admin_->obtain_notification_push_consumer (CosNotifyChannelAdmin::STRUCTURED_EVENT
                                                     , proxy_consumer_id_ ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  ACE_ASSERT (!CORBA::is_nil (proxyconsumer.in ()));
  // narrow
  this->proxy_consumer_ =
    CosNotifyChannelAdmin::StructuredProxyPushConsumer::_narrow (proxyconsumer.in () ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  ACE_ASSERT (!CORBA::is_nil (proxy_consumer_.in ()));

  // connect to the proxyconsumer.
  this->proxy_consumer_->connect_structured_push_supplier (objref.in ()
                                                     ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

void
TAO_Notify_Lanes_Supplier::disconnect (ACE_ENV_SINGLE_ARG_DECL)
{
  ACE_ASSERT (!CORBA::is_nil (this->proxy_consumer_.in ()));

  this->proxy_consumer_->disconnect_structured_push_consumer(ACE_ENV_SINGLE_ARG_PARAMETER);
}

void
TAO_Notify_Lanes_Supplier::deactivate (ACE_ENV_SINGLE_ARG_DECL)
{
  PortableServer::POA_var poa (this->_default_POA (ACE_ENV_SINGLE_ARG_PARAMETER));
  ACE_CHECK;

  PortableServer::ObjectId_var id (poa->servant_to_id (this
                                                       ACE_ENV_ARG_PARAMETER));
  ACE_CHECK;

  poa->deactivate_object (id.in()
                          ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}


void 
TAO_Notify_Lanes_Supplier::subscription_change (
        const CosNotification::EventTypeSeq & added,
        const CosNotification::EventTypeSeq & removed
        ACE_ENV_ARG_DECL
      )
      ACE_THROW_SPEC ((
        CORBA::SystemException,
        CosNotifyComm::InvalidEventType
      ))
{
  // no-op
}



void
TAO_Notify_Lanes_Supplier::send_event (const CosNotification::StructuredEvent& event ACE_ENV_ARG_DECL)
{
  ACE_ASSERT (!CORBA::is_nil (this->proxy_consumer_.in ()));

  proxy_consumer_->push_structured_event (event ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;
}

void
TAO_Notify_Lanes_Supplier::disconnect_structured_push_supplier (ACE_ENV_SINGLE_ARG_DECL)
  ACE_THROW_SPEC ((
                   CORBA::SystemException
                   ))
{
  this->deactivate (ACE_ENV_SINGLE_ARG_PARAMETER);
}
