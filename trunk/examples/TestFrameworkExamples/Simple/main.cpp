// -*- C++ -*-
// ============================================================================
/**
 *  @file   main.cpp
 *
 *  $Id$
 *
 *
 */
// ============================================================================

int
main (int argc, char *argv[])
{
  if (test_ptr->Init (argc, argv) != 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("test init failed.\n")),
                        -1);
    }
    
  /* add custom listener (default overrides
  only on_data_available() so far), modify QoS,
  or plug in a data initializer or verifier
  here. Not all of this is supported yet. */

  if (test_ptr->Run () != 0)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("test run failed.\n")),
                        -1);
    }

  return 0;
}
