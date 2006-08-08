#!/usr/bin/perl

require "/export/home/tczar/scripts/scripts.lib";


if( @ARGV > 0 )
{
  if( @ARGV[0] eq "-h" )
  {
    print "\n" .
      "Usage:\n\n" .
      "  tester.pl [-h]
                         \n";
    print "  [-h] print usage information for this script.

    This script is for development purposes only and is just used
    for testing specific features of a new library call from scripts.lib
    or some other type of test for which benchmark.pl or associated scripts
    do not really need to be modified.

    Use of this script is not necessarily recommended for end-users.\n\n";
    exit(0);
  }
}



%settings = ();
&readSettingsFromArgs();

setupNDDSDiscovery(1);

print $ENV{'NDDS_DISCOVERY_PEERS'} . "\n";

setupNDDSDiscovery(2);

print $ENV{'NDDS_DISCOVERY_PEERS'} . "\n";

