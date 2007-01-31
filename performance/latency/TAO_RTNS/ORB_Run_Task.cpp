// $Id: ORB_Run_Task.cpp,v 1.4 2003/09/04 03:27:24 ossama Exp $

#include "ORB_Run_Task.h"

ACE_RCSID (Notify, TAO_Notify_ORB_Run_Task, "$Id: ORB_Run_Task.cpp,v 1.4 2003/09/04 03:27:24 ossama Exp $")

TAO_Notify_ORB_Run_Task::TAO_Notify_ORB_Run_Task (TAO_Notify_ORB_Objects& orb_objects)
  : orb_objects_ (orb_objects)
{
}

TAO_Notify_ORB_Run_Task::~TAO_Notify_ORB_Run_Task ()
{
}

int
TAO_Notify_ORB_Run_Task::svc (void)
{
  ACE_TRY_NEW_ENV
    {
      this->orb_objects_.orb_->run (ACE_ENV_SINGLE_ARG_PARAMETER);
      ACE_TRY_CHECK;
    }
  ACE_CATCHANY
    {
    }
  ACE_ENDTRY;

  return 0;
}
