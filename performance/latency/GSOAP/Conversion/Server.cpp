#include "ace/Get_Opt.h"
#include "ace/ACE.h"
#include "ace/SString.h"

#include "soapListener.h"
#include "Stats.h"

// Defines number of warm-up samples which are used 
// to avoid cold start issues.
unsigned long primer_samples = 5;

unsigned long stats_samples = 5;
unsigned long seq_len = 4;

// Name of data output file.
char *output_file = "server_results";

int
parse_args (int argc, char **argv)
{
  ACE_Get_Opt get_opts (argc, argv, "i:p:s:");
  int c;
  ACE_CString opt_string;

  while ((c = get_opts ()) != -1)
    switch (c)
      {
      case 'i':
        stats_samples = ACE_OS::atoi (get_opts.opt_arg ());
        break;
      case 'p':
        primer_samples = ACE_OS::atoi (get_opts.opt_arg ());
        break;
      case 's':
        seq_len = ACE_OS::atoi (get_opts.opt_arg ());
        break;
      case '?':
      default:
        ACE_ERROR_RETURN ((LM_ERROR,
                           "usage:  %s"
                           " [-i number of samples]"
                           " [-p number of primer samples]"
                           " [-s sample size]"
                           "\n",
                           argv [0]),
                          -1);
      }
      
  return 0;
}

// To run this program, enter ./EchoSingle.
int main (int argc, char *argv[])
{
  if (parse_args (argc, argv) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                          "(%N:%l) Server.cpp - "
                          "parse_args failed\n"),
                        -1);
    }

  SOAPListener sl (output_file,
                   primer_samples,
                   stats_samples,
                   seq_len);
  sl.listen ();
  
  return 0;
}
