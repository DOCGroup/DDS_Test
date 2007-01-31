
// $Id: Supplier_Client.cpp,v 1.8 2005/08/30 14:23:42 jwillemsen Exp $

#include "Supplier_Client.h"

#include "ORB_Run_Task.h"
#include "ace/Arg_Shifter.h"
#include "tao/ORB_Core.h"
#include "ace/Sched_Params.h"
#include "Supplier.h"
#include "orbsvcs/NotifyExtC.h"
#include "orbsvcs/CosNamingC.h"
#include "ace/OS_NS_errno.h"

ACE_RCSID (Notify, TAO_Notify_Lanes_Supplier_Client, "$Id: Supplier_Client.cpp,v 1.8 2005/08/30 14:23:42 jwillemsen Exp $")

TAO_Notify_Lanes_Supplier_Client::TAO_Notify_Lanes_Supplier_Client (TAO_Notify_ORB_Objects& orb_objects)
  : orb_objects_ (orb_objects)
    ,supplier_ (0)
    , consumer_count_ (1)
{
}

TAO_Notify_Lanes_Supplier_Client::~TAO_Notify_Lanes_Supplier_Client ()
{
}

int
TAO_Notify_Lanes_Supplier_Client::parse_args (int argc, char *argv[])
{
  ACE_Arg_Shifter arg_shifter (argc, argv);

  const ACE_TCHAR *current_arg = 0;

  while (arg_shifter.is_anything_left ())
    {
      if ((current_arg = arg_shifter.get_the_parameter (ACE_TEXT("-IORoutput")))) // The file to output the supplier ior to.
        {
          if (current_arg != 0)
            {
              this->ior_file_name_ = current_arg;
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
TAO_Notify_Lanes_Supplier_Client::initialize (ACE_ENV_SINGLE_ARG_DECL)
{
  PortableServer::POAManager_var poa_manager =
    this->orb_objects_.root_poa_->the_POAManager (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  poa_manager->activate (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  CosNotifyChannelAdmin::EventChannel_var ec = this->create_ec (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  // Create a Supplier Admin
  CosNotifyChannelAdmin::AdminID adminid = 0;

  CosNotifyChannelAdmin::SupplierAdmin_var supplier_admin =
    ec->new_for_suppliers (CosNotifyChannelAdmin::AND_OP, adminid ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  ACE_ASSERT (!CORBA::is_nil (supplier_admin.in ()));

  // Create a Supplier
  this->supplier_ = new TAO_Notify_Lanes_Supplier (this->orb_objects_);

  // Initialize it.
  this->supplier_->init (supplier_admin);

  CosNotifyChannelAdmin::ConsumerAdmin_var consumer_admin =
    ec->new_for_consumers (CosNotifyChannelAdmin::AND_OP, adminid ACE_ENV_ARG_PARAMETER);
  ACE_CHECK;

  ACE_ASSERT (!CORBA::is_nil (consumer_admin.in ()));

  // Create a Supplier
  this->consumer_ = new TAO_Notify_Lanes_Consumer (this->orb_objects_);


  char type[BUFSIZ];
  ACE_OS::sprintf (type, "T_PONG");
  this->event_type_ = type;
  // Initialize it.
  this->consumer_->init (consumer_admin,
                         this->supplier_,
                         this->event_type_);

  
}

CosNotifyChannelAdmin::EventChannel_ptr
TAO_Notify_Lanes_Supplier_Client::create_ec (ACE_ENV_SINGLE_ARG_DECL)
{
  CosNotifyChannelAdmin::EventChannel_var ec;

  CosNotifyChannelAdmin::EventChannelFactory_var ecf = this->orb_objects_.notify_factory (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK_RETURN (ec._retn ());

  // Create an EventChannel
  CosNotification::QoSProperties qos;
  CosNotification::AdminProperties admin;

  // Create an event channel
  CosNotifyChannelAdmin::ChannelID id;

  ec = ecf->create_channel (qos,
                            admin,
                            id
                            ACE_ENV_ARG_PARAMETER);
  ACE_CHECK_RETURN (ec._retn ());

  return ec._retn ();
}

void
TAO_Notify_Lanes_Supplier_Client::run (ACE_ENV_SINGLE_ARG_DECL)
{
  /// First, signal that the supplier is ready.
  this->write_ior (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  this->supplier_->run (ACE_ENV_SINGLE_ARG_PARAMETER);
}

void
TAO_Notify_Lanes_Supplier_Client::write_ior (ACE_ENV_SINGLE_ARG_DECL)
{
  CosNotifyComm::StructuredPushSupplier_var objref = this->supplier_->_this (ACE_ENV_SINGLE_ARG_PARAMETER);
  ACE_CHECK;

  // Write the ior to a file to signal waiting consumers.
  FILE *ior_output_file = ACE_OS::fopen (this->ior_file_name_.c_str (), ACE_TEXT("w"));

  if (ior_output_file != 0)
    {
      CORBA::String_var str =
        this->orb_objects_.orb_->object_to_string (objref.in () ACE_ENV_ARG_PARAMETER);
      ACE_CHECK;

      ACE_OS::fprintf (ior_output_file,
                       "%s",
                       str.in ());
      ACE_OS::fclose (ior_output_file);
    }
}

int
TAO_Notify_Lanes_Supplier_Client::svc (void)
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
        struct sched_param p;

        p.sched_priority = 20;
        if (-1 == sched_setscheduler(0, SCHED_FIFO, &p)) {
          perror("sched_setscheduler");
        }
        if (mlockall(MCL_CURRENT || MCL_FUTURE)) {
          fprintf(stderr, 
            "== Could not lock memory - Run with root access.\n");
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

      // Create a holder for the common ORB Objects.
      TAO_Notify_ORB_Objects orb_objects;

      orb_objects.init (orb ACE_ENV_ARG_PARAMETER);
      ACE_TRY_CHECK;

      /* Run the ORB in a seperate thread */
      TAO_Notify_ORB_Run_Task orb_run_task (orb_objects);

      /* Create a Client */
      TAO_Notify_Lanes_Supplier_Client client (orb_objects);

      if (client.parse_args (argc, argv) != 0)
        {
          ACE_DEBUG ((LM_DEBUG, "Supplier_Client::Error parsing options\n"));
          return -1;
        }

      set_rt ();

      long flags = THR_NEW_LWP | THR_JOINABLE;

      flags |=
        orb->orb_core ()->orb_params ()->thread_creation_flags ();

      /* Both the tasks initialize themselves at Priority 0*/
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
                          ACE_TEXT ("Supplier Client error "));
    }
  ACE_ENDTRY;

  return 0;
}
