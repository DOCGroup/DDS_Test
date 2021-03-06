#!/usr/bin/perl

use Env (DBE_SCRIPTS);
use Env (DBE_ROOT);
use Env (DBE_LOCAL_ROOT);
use Env (DBE_RESULTS_BACKUP);

require "$DBE_SCRIPTS/scripts.lib";


if( @ARGV > 0 )
{
  if( @ARGV[0] eq "-h" )
  {
    print "\n" .
      "Usage:\n\n" .
      "  resetSSHEnvironment.pl [-h]
                         \n";
    print "  [-h] print usage information for this script.

    This script writes the current environment variables to
    ~/.ssh/environment. This file is required to properly setup
    environment variables during terminal-less remote ssh execution.\n\n";
    exit(0);
  }
}



&writeEnvironmentForSSH();

exit(0);
