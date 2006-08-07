// $Id$

#include "TestBase.h"
#include "ace/Sched_Params.h"
#include "ace/Streams.h"

TestBase::TestBase (void)
  : priority_ ((ACE_Sched_Params::priority_min (ACE_SCHED_FIFO)
                + ACE_Sched_Params::priority_max (ACE_SCHED_FIFO)) / 2)
{
}

TestBase::~TestBase (void)
{
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

int
TestBase::ParseArgs (int argc, char *argv[])
{
  ACE_Arg_Shifter arg_shifter (argc, argv);
  int status = 0;
  
  // Ignore the command - argv[0].
  arg_shifter.ignore_arg ();
  
  while (arg_shifter.is_anything_left ()) 
    {
      status = this->ParseArgsBase (arg_shifter);
      
      if (0 != status)
        {
          return status;
        }
    }
    
  return 0;
}

int
TestBase::priority (void) const
{
  return this->priority_;
}

void
TestBase::priority (int val)
{
  this->priority_ = val;
}

int
TestBase::ParseArgsBase (ACE_Arg_Shifter &arg_shifter)
{
  const char *currentArg = 0;
  // Indicates sucessful parsing of the command line
  return 0;
}

