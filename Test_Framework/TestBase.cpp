// $Id$

#include "TestBase.h"
#include "ace/Sched_Params.h"
#include "ace/Streams.h"
#include "ace/Log_Msg.h"

TestBase::TestBase (void)
  : domain_id_ (0),
    test_description_ ("DBE_default_test"),
    entity_id_ (0),
    payload_item_size_ (1UL),
    payload_length_ (1UL),
    topic_name_ ("DBE_default_topic"),
    protocol_ ("UDP"),
    transport_ ("multicast"),
    notification_ ("listener"),
    nreaders_ (1UL),
    nwriters_ (1UL),
    primer_samples_ (100UL),
    stats_samples_ (10000UL),
    net_settings_file_ ("net_default.settings"),
    qos_settings_file_ ("qos_default.settings"),
    results_file_ ("default_stats"),
    priority_ ((ACE_Sched_Params::priority_min (ACE_SCHED_FIFO)
                + ACE_Sched_Params::priority_max (ACE_SCHED_FIFO)) / 2),
    use_waitset_ (false)
{
}

TestBase::~TestBase (void)
{
}

int
TestBase::ParseArgsBase (ACE_Arg_Shifter &arg_shifter)
{
  const char *currentArg = 0;
  
  if ((currentArg = arg_shifter.get_the_parameter ("-domain")) != 0) 
    {
      this->domain_id_ = ACE_OS::atoi (currentArg);
      arg_shifter.consume_arg ();
    }
  else if ((currentArg = arg_shifter.get_the_parameter ("-test")) != 0) 
    {
      this->test_description_ = currentArg;
      arg_shifter.consume_arg ();
    }
  else if ((currentArg = arg_shifter.get_the_parameter ("-id")) != 0)
    {
      this->entity_id_ = ACE_OS::atoi (currentArg);
      arg_shifter.consume_arg ();
    }
  else if ((currentArg = arg_shifter.get_the_parameter ("-size")) != 0) 
    {
      this->payload_length_ = ACE_OS::atoi (currentArg);
      arg_shifter.consume_arg ();
    }
  else if ((currentArg = arg_shifter.get_the_parameter ("-topic")) != 0)
    {
      this->topic_name_ = currentArg;
      arg_shifter.consume_arg ();
    }
  else if ((currentArg = arg_shifter.get_the_parameter ("-protocol")) != 0) 
    {
      this->protocol_ = currentArg;
      arg_shifter.consume_arg ();
    }
  else if ((currentArg = arg_shifter.get_the_parameter ("-transport")) != 0)
    {
      this->transport_ = currentArg;
      arg_shifter.consume_arg ();
    }
  else if ((currentArg = arg_shifter.get_the_parameter ("-notify")) != 0)
    {
      this->notification_ = currentArg;
      arg_shifter.consume_arg ();
    }
  else if ((currentArg = arg_shifter.get_the_parameter ("-readers")) != 0)
    {
      this->nreaders_ = ACE_OS::atoi (currentArg);
      arg_shifter.consume_arg ();
    }
  else if ((currentArg = arg_shifter.get_the_parameter ("-writers")) != 0)
    {
      this->nwriters_ = ACE_OS::atoi (currentArg);
      arg_shifter.consume_arg ();
    }
  else if ((currentArg = arg_shifter.get_the_parameter ("-primer")) != 0)
    {
      this->primer_samples_ = ACE_OS::atoi (currentArg);
      arg_shifter.consume_arg ();
    }
  else if ((currentArg = arg_shifter.get_the_parameter ("-stats")) != 0)
    {
      this->stats_samples_ = ACE_OS::atoi (currentArg);
      arg_shifter.consume_arg ();
    }
  else if ((currentArg = arg_shifter.get_the_parameter ("-net")) != 0) 
    {
      this->net_settings_file_ = currentArg;
      arg_shifter.consume_arg ();
    }
  else if ((currentArg = arg_shifter.get_the_parameter ("-qos")) != 0)
    {
      this->qos_settings_file_ = currentArg;
      arg_shifter.consume_arg ();
    }
  else if ((currentArg = arg_shifter.get_the_parameter ("-results")) != 0)
    {
      this->results_file_ = currentArg;
      arg_shifter.consume_arg ();
    }
  else 
    {
      ACE_ERROR ((LM_ERROR,
                  ACE_TEXT ("ParseArgsBase: unexpected parameter %s\n"),
                  arg_shifter.get_current ()));
      return -1;
    }
    
  // Indicates sucessful parsing of the command line.
  return 0;
}

void
TestBase::UsageBase (void) const
{
  cout << "General Usage:" << endl
       << "\t[-domain #]       - domain id" << endl
       << "\t[-test \"\"]      - test description" << endl
       << "\t[-id #]           - DDS entity id" << endl
       << "\t[-size #]         - length of payload sequence" << endl
       << "\t[-topic \"\"]     - topic name" << endl
       << "\t[-protocol \"\"]  - name of transport protocol" << endl
       << "\t[-transport \"\"] - unicast | multicast | broadcast" << endl
       << "\t[-notify \"\"]    - listener | waitset" << endl
       << "\t[-readers #]      - number of data readers" << endl
       << "\t[-writers #]      - number of data writers" << endl
       << "\t[-primer #]       - number of primer samples" << endl
       << "\t[-stats #]        - number of stats samples" << endl
       << "\t[-net \"\"]       - network settings filename" << endl
       << "\t[-qos \"\"]       - QoS settings filename" << endl
       << "\t[-results \"\"]   - results output filename" << endl;
}

void
TestBase::SetSchedParams (void)
{
  int rt_status =
    ACE_OS::sched_params (ACE_Sched_Params (ACE_SCHED_FIFO,
                                            this->priority_,
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
            cout << "priority " << this->priority_
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

void
TestBase::NullReturnErrorMsg (const char *where, const char *what) const
{
  ACE_ERROR ((LM_ERROR,
              ACE_TEXT ("%s::%s - %s failed\n"),
              this->ClassName (),
              where,
              what));
}

void
TestBase::RetcodeErrorMsg (const char *where,
                           const char *what,
                           long retcode) const
{
  std::string retcode_msg;
  
  switch (retcode)
    {
      case 0:
        retcode_msg = "ok";
        break;
      case 1:
        retcode_msg = "error";
        break;
      case 2:
        retcode_msg = "unsupported";
        break;
      case 3:
        retcode_msg = "parameter";
        break;
      case 4:
        retcode_msg = "precondition not met";
        break;
      case 5:
        retcode_msg = "out of resources";
        break;
      case 6:
        retcode_msg = "not enabled";
        break;
      case 7:
        retcode_msg = "immutable policy";
        break;
      case 8:
        retcode_msg = "inconsistent policy";
        break;
      case 9:
        retcode_msg = "already deleted";
        break;
      case 10:
        retcode_msg = "timeout";
        break;
      case 11:
        retcode_msg = "no data";
        break;
      case 12:
        retcode_msg = "illegal operation";
        break;
      default:
        retcode_msg = "unknown retcode";
        break;
    }
    
  ACE_ERROR ((LM_ERROR,
              ACE_TEXT ("%s::%s - %s returned \"%s\""),
              this->ClassName (),
              where,
              what,
              retcode_msg.c_str ()));
}

void
TestBase::ExceptionErrorMsg (const char *where) const
{
  ACE_ERROR ((LM_ERROR,
              ACE_TEXT ("%s::%s - caught unknown exception\n"),
              this->ClassName (),
              where));
}

void
TestBase::NotExistErrorMsg (const char *where, const char *what) const
{
  ACE_ERROR ((LM_ERROR,
              ACE_TEXT ("%s::%s - %s does not exist\n"),
              this->ClassName (),
              where,
              what));
}