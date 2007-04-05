// $Id: Consumer_Client.cpp,v 1.8 2005/08/30 14:23:42 jwillemsen Exp $

#include "Consumer_Client.h"
#include "Consumer.h"
#include "ORB_Run_Task.h"
#include "ace/Arg_Shifter.h"
#include "orbsvcs/NotifyExtC.h"
#include "orbsvcs/CosNamingC.h"
#include "tao/ORB_Core.h"
#include "ace/Sched_Params.h"
#include "ace/OS_NS_errno.h"
#include "ace/Streams.h"

ACE_RCSID (Notify, TAO_Notify_Lanes_Consumer_Client, "$Id: Consumer_Client.cpp,v 1.8 2005/08/30 14:23:42 jwillemsen Exp $")

TAO_Notify_Lanes_Consumer_Client::TAO_Notify_Lanes_Consumer_Client (TAO_Notify_ORB_Objects& orb_objects)
  : orb_objects_ (orb_objects)
  , lane_priority_ (0)
  , consumer_ (0)
{
}

TAO_Notify_Lanes_Consumer_Client::~TAO_Notify_Lanes_Consumer_Client ()
{
}

int
TAO_Notify_Lanes_Consumer_Client::parse_args (int argc, char *argv[])
{
  ACE_Arg_Shifter arg_shifter (argc, argv);

  const ACE_TCHAR *current_arg = 0;

  while (arg_shifter.is_anything_left ())
    {
      if ((current_arg = arg_shifter.get_the_parameter (ACE_TEXT("-LanePriority")))) // LanePriority
        {
          if (current_arg != 0)
            {
              this->lane_priority_ = ACE_OS::atoi (current_arg);

              char type[BUFSIZ];
              ACE_OS::sprintf (type, "T_PING");
              this->event_type_ = type;
            }

          arg_shifter.consume_arg ();
        }
      else
        {
          arg_shifter.ignore_arg ();
        }
    }

  return 0;
}

void
TAO_Notify_Lanes_Consumer_Client::initialize (ACE_ENV_SINGLE_ARG_DECL)
{
  ACE_DEBUG ((LM_DEBUG, "(%P, %t)Initializing Consumer Client with lane priority = %d, event type = (%s)\n"
              , this->lane_priority_, this->event_type_.c_str ()));

  PortableServer::POAManager_var poa_manager =
    this->orb_objects_.root_poa_->the_POAManager (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  poa_manager->activate (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  // Resolve the Notification Factory.
  CosNotifyChannelAdmin::EventChannelFactory_var ecf = this->orb_objects_.notify_factory (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  // Find the EventChannel created by the supplier.
  CosNotifyChannelAdmin::ChannelIDSeq_var channel_seq = ecf->get_all_channels (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  CosNotifyChannelAdmin::EventChannel_var ec;

  if (channel_seq->length() > 0)
    {
      ec = ecf->get_event_channel (channel_seq[0] ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;
    }
  else
    {
      ACE_DEBUG ((LM_DEBUG, "No Event Channel active!\n"));
      return;
    }

  // Create a Consumer Admin
  CosNotifyChannelAdmin::AdminID adminid = 0;

  CosNotifyChannelAdmin::SupplierAdmin_var supplier_admin =
    ec->new_for_suppliers (CosNotifyChannelAdmin::OR_OP, adminid ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  ACE_ASSERT (!CORBA::is_nil (supplier_admin.in ()));


  // Create a Consumer
  this->supplier_ = new TAO_Notify_Lanes_Supplier (this->orb_objects_);

  // Initialize it.
  this->supplier_->init (supplier_admin);




  CosNotifyChannelAdmin::ConsumerAdmin_var consumer_admin =
    ec->new_for_consumers (CosNotifyChannelAdmin::OR_OP, adminid ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  ACE_ASSERT (!CORBA::is_nil (consumer_admin.in ()));

  // Create a Consumer
  this->consumer_ = new TAO_Notify_Lanes_Consumer (this->orb_objects_);

  // Initialize it.
  this->consumer_->init (consumer_admin,
                         this->supplier_,
                         this->event_type_ ACE_ENV_ARG_PARAMETER);


}

PortableServer::POA_ptr
TAO_Notify_Lanes_Consumer_Client::create_rt_poa (ACE_ENV_SINGLE_ARG_DECL)
{
  PortableServer::POA_var rt_poa;

  PortableServer::POAManager_var poa_manager =
    this->orb_objects_.root_poa_->the_POAManager (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (rt_poa._retn ());

  rt_poa = this->orb_objects_.root_poa_->create_POA ("RT_POA",
                                                     poa_manager.in (),
                                                     NULL);

  ACE_CHECK_RETURN (rt_poa._retn ());

  return rt_poa._retn ();
}

void
TAO_Notify_Lanes_Consumer_Client::run (ACE_ENV_SINGLE_ARG_DECL)
{
  this->consumer_->run (ACE_ENV_SINGLE_ARG_PARAMETER);
}

int
TAO_Notify_Lanes_Consumer_Client::svc (void)
{
  ACE_TRY_NEW_ENV
    {
      this->initialize (ACE_ENV_SINGLE_ARG_PARAMETER); //Init the Client
      ACE_TRY_CHECK;

      this->run (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION(ACE_ANY_EXCEPTION,
                          ACE_TEXT ("Supplier error "));

    }
  ACE_ENDTRY;

  return 0;
}

/* void set_rt() */
/*      Attempt to set the real time priority and lock memory */
void set_rt() 
{
  int priority = 20;
  int rt_status =
    ACE_OS::sched_params (ACE_Sched_Params (ACE_SCHED_FIFO,
                                            priority,
                                            ACE_SCOPE_PROCESS));
  
  if (rt_status != 0)
    {
      switch (ACE_OS::last_error ())
        {
          case EPERM:
            cout << "user is not superuser, "
                 << "test runs in time-shared class" << endl;
            break;
          case EINVAL:
            cout << "priority " << priority
                 << " is invalid on this platform, test runs"
                 << " in time-shared class"
                 << endl;
            break;
          case ESRCH:
            cout << "process id " << ACE_SCOPE_PROCESS
                 << " not found, test runs in time-shared class"
                 << endl;
            break;
          default:
            // No other reasons why sched_params() can fail.
            break;
        }
    }
  else
    {
      cout << "real time priority successfully set!" << endl;
    }
}

int
main (int argc, char *argv [])
{
  ACE_TRY_NEW_ENV
    {
      // Initialize an ORB
      CORBA::ORB_var orb = CORBA::ORB_init (argc,
                                            argv,
                                            ""
                                            ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      TAO_Notify_ORB_Objects orb_objects;

      orb_objects.init (orb ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      TAO_Notify_ORB_Run_Task orb_run_task (orb_objects);

      TAO_Notify_Lanes_Consumer_Client client (orb_objects);

      if (client.parse_args (argc, argv) != 0)
        {
          ACE_DEBUG ((LM_DEBUG, "Consumer_Client::Error parsing options\n"));
          return -1;
        }

      set_rt ();
      
      long flags = THR_NEW_LWP | THR_JOINABLE;

      flags |=
        orb->orb_core ()->orb_params ()->thread_creation_flags ();


      if (orb_run_task.activate (flags) == -1 || client.activate (flags) == -1)
        {
          if (ACE_OS::last_error () == EPERM)
            ACE_ERROR_RETURN ((LM_ERROR,
                               ACE_TEXT ("Insufficient privilege to activate ACE_Task.\n")),
                              -1);
          else
            ACE_DEBUG ((LM_ERROR,
                        ACE_TEXT ("(%t) Task activation at priority %d failed. \n")));
        }

      orb_run_task.thr_mgr ()->wait ();
      client.thr_mgr ()->wait ();
    }
  ACE_CATCHANY
    {
      ACE_PRINT_EXCEPTION(ACE_ANY_EXCEPTION,
                          ACE_TEXT ("Consumer Client error "));
    }
  ACE_ENDTRY;

  return 0;
}
