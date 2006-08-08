#!/usr/bin/perl

# resets all test data (ie erases all tests ever conducted.)
# for obvious reasons, this should probably never be called after
# the benchmark is out of beta.

# Author: James Edmondson

require "$DBE_SCRIPTS/scripts.lib";


if( @ARGV > 0 )
{
  if( @ARGV[0] eq "-h" )
  {
    print "\n" .
      "Usage:\n\n" .
      "  resetTestsList.pl [-h]
                         \n";
    print "  [-h] print usage information for this script.

    This command deletes all test results in ~/DDS/results. If you need
    to back anything up to another directory, see testCopy.pl.\n\n";
    exit(0);
  }
}



$current = &getId("$DBE_ROOT/settings/id.gen");

for( $i = 1; $i < $current; $i++ )
{
  system("rm -r $DBE_ROOT/results/$i");
}

system("rm $DBE_ROOT/results/tests.list");
system("echo 1 > $DBE_ROOT/settings/id.gen");

exit 0;
