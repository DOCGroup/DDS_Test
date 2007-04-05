// $Id: Supplier.cpp,v 1.4 2003/09/04 03:27:24 ossama Exp $

#include "Supplier.h"
#include <iostream>
#include <ace/streams.h>
#include "pubmessageC.h"

#include "tester.h"

#define EVENT_COUNT 200
#define EVENT_PRIMER 200

#define MSG_SIZE 4

ACE_RCSID (Notify, TAO_Notify_Lanes_Supplier, "$Id: Supplier.cpp,v 1.4 2003/09/04 03:27:24 ossama Exp $")

#include "tao/ORB_Core.h"

#include <math.h>

/* type definition */
typedef struct
{
    char name[20];
    double average;
    double min;
    double max;
    double sum;
    double sum2;
    int count;
} stats_type;


static stats_type round_trip;
static timeval round_pre_t;
static timeval round_post_t;



static void
add_stats (
    stats_type& stats,
    double data
    )
{
    stats.average = (stats.count * stats.average + data)/(stats.count + 1);
    stats.min     = (stats.count == 0 || data < stats.min) ? data : stats.min;
    stats.max     = (stats.count == 0 || data > stats.max) ? data : stats.max;
    stats.sum = stats.sum + data;
    stats.sum2 = stats.sum2 + data * data;
    stats.count++;
}

static void
init_stats (
    stats_type& stats,
    char *name)
{
    strncpy ((char *)stats.name, name, 19);
    stats.name[19] = '\0';
    stats.count    = 0;
    stats.average  = 0.0;
    stats.min      = 0.0;
    stats.max      = 0.0;
    stats.sum      = 0.0;
    stats.sum2     = 0.0;
}

static double
std_dev (stats_type& stats)
{
  if (stats.count >=2)
  {
    return sqrt ((static_cast<double>(stats.count) * stats.sum2 - stats.sum * stats.sum) / 
                (static_cast<double>(stats.count) * static_cast<double>(stats.count - 1)));
  }
  
  return 0.0;
}

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

  init_stats (round_trip, "round_trip");
}

void
TAO_Notify_Lanes_Supplier::run (ACE_ENV_SINGLE_ARG_DECL)
{
  ACE_GUARD (TAO_SYNCH_MUTEX, mon, this->lock_);
  
  while (this->consumer_count_ < 2)
    this->consumers_connected_.wait ();
  
  CosNotification::StructuredEvent event;

  
  event.header.fixed_header.event_type.domain_name = CORBA::string_dup("PING");
  event.header.fixed_header.event_type.type_name = CORBA::string_dup("T_PING");
  event.header.fixed_header.event_name = CORBA::string_dup ("");
  event.header.variable_header.length (0);
  event.filterable_data.length (0);

  /*  CORBA::OctetSeq data;
  data.length (MSG_SIZE + 4);
  data[0] = (CORBA::Long)1;
  event.remainder_of_body <<= data;*/

  pubdata::pubmessage pub_msg;
  pub_msg.seqnum = 1;
  pub_msg.data.length (MSG_SIZE);
  event.remainder_of_body <<= pub_msg;

  //  ACE_DEBUG ((LM_INFO,
  //            " the number is %d", pub_msg.seqnum));
  //ACE_DEBUG ((LM_DEBUG,
  //            "(%P, %t) Supplier is sending an event of type at priority 0\n"));

  // send the event

  round_pre_t = tester::get_time ();
  this->send_event (event ACE_ENV_ARG_PARAMETER);
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

  ACE_GUARD (TAO_SYNCH_MUTEX, mon, this->lock_);
  
  if (added.length () > 0)
    {
      ACE_DEBUG ((LM_INFO,
                  "We have suscription"));
      if (++this->consumer_count_ == 2)
      {
        this->consumers_connected_.signal ();
      }
    }
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




//************************************************************************


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
  added[0].domain_name = CORBA::string_dup ("PONG");
  added[0].type_name = CORBA::string_dup ("T_PONG");

  this->proxy_supplier_->subscription_change (added,
                                              removed ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  ACE_DEBUG ((LM_DEBUG,
              "Subscribed to PONG, T_PONG\n"));
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

      //std::cout << "\ngot message at supplier" << std::endl;

      const char* domain_name =
        notification.header.fixed_header.event_type.domain_name;

      const char* type_name =
        notification.header.fixed_header.event_type.type_name;

      CORBA::Long sequence_num;
      notification.remainder_of_body >>= sequence_num;

      round_post_t = tester::get_time ();



      if (sequence_num != this->sample_num_)
        {
          ACE_DEBUG ((LM_ERROR,
                      "Error - publisher: received sequence_num %d at %d",
                      sequence_num, this->sample_num_));
          exit (1);
        }

      if (sequence_num > EVENT_PRIMER)
        {
          add_stats (round_trip,
                     1E6 * tester::time_to_real (tester::get_time_diff (round_post_t, round_pre_t)));
        }
      

      // Event 1
      CosNotification::StructuredEvent data;
      data.header.fixed_header.event_type.domain_name =
        CORBA::string_dup("PING");
      data.header.fixed_header.event_type.type_name =
        CORBA::string_dup("T_PING");
      data.header.fixed_header.event_name = CORBA::string_dup("");
      data.header.variable_header.length (0); // put nothing here
      data.filterable_data.length (0);


      if (++this->sample_num_  > (EVENT_COUNT + EVENT_PRIMER))
      {
        std::cout << "Supplier: Done!!" << std::endl;



        ofstream result_file ("result");
        time_t clock = time (NULL);
        result_file << "# MY Pub Sub PONG measurements (in us) \n";
        result_file << "# Executed at:" <<  ctime(&clock);
        result_file << "#       Roundtrip time [us]\n";
        result_file << "Count     mean      min      max    std_dev\n";
        result_file << " "
                    << round_trip.count
                    << "        "
                    << round_trip.average
                    << "     "
                    << round_trip.min
                    << "      "
                    << round_trip.max
                    << "     "
                    << std_dev (round_trip)
                    << std::endl;

        result_file.close ();
        /*        CORBA::OctetSeq msg;
        msg.length (MSG_SIZE);
        msg[0] = (CORBA::Long)0;
        data.remainder_of_body <<= msg;*/

        pubdata::pubmessage quit_msg;
        quit_msg.seqnum = 0;
        data.remainder_of_body <<= quit_msg;

        this->pub->send_event (data);
  
        // Disconnect from the EC
        this->disconnect (ACE_ENV_SINGLE_ARG_PARAMETER);

        // Deactivate this object.
        this->deactivate (ACE_ENV_SINGLE_ARG_PARAMETER);

        // We received the event, shutdown the ORB.
        this->orb_objects_.orb_->shutdown (1);
      }
      else
      {

        /*        CORBA::OctetSeq msg;
        msg.length (MSG_SIZE + 4);
        msg[0] = (CORBA::Long) sequence_num + 1;
        data.remainder_of_body <<= msg;*/

        pubdata::pubmessage pub_msg;
        pub_msg.seqnum = sequence_num + 1;
        pub_msg.data.length (MSG_SIZE);
        data.remainder_of_body <<= pub_msg;

        //        ACE_DEBUG ((LM_DEBUG,
        //            "Supplier received event, domain = %s, type = %s, seq_num = %d\n",
        //            domain_name,
        //            type_name,
        //            sequence_num));
        round_pre_t = tester::get_time ();
        
        this->pub->send_event (data);
      }
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
