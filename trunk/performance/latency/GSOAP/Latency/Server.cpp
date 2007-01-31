#include "soapListener.h"
#include "ace/config-lite.h"

// To run this program, enter ./EchoSingle.
int main (int argc, char *argv[])
{
  SOAPListener sl;
  sl.listen ();
  
  ACE_UNUSED_ARG (argc);
  ACE_UNUSED_ARG (argv);
  
  return 0;
}
