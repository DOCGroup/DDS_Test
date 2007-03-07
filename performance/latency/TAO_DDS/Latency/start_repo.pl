#!/usr/bin/perl


eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;



# Author: Jeff Parsons
# Last Modified: May 18, 2006 by James Edmondson
# Purpose: Initialize a Repo for TAO-DDS

use Env (ACE_ROOT);
use Env (DDS_ROOT);
use lib "$ACE_ROOT/bin";
use PerlACE::Run_Test;
use Cwd;

require "/export/home/tczar/scripts/scripts.lib";


# no terminal? no problem...

chdir("/export/home/tczar/DDS/performance/throughput/TAO_DDS/TCP");


#print "REPO CWD: " . getcwd() . "\n";
#exit(0);

$status = 0;

$repo_port = 60001;

&readSettingsFromArgs();

$domains_file = PerlACE::LocalFile ("domain_ids");
$dcpsrepo_ior = PerlACE::LocalFile ("repo.ior");

unlink $dcpsrepo_ior;

$repo = "blade37.isislab.vanderbilt.edu";

if( $settings{'nodelist'} eq 'true' )
{
  $repo = $settings{'node0'};
}

# log the Repo's parameters and settings

$parameters =   "-NOBITS -o $dcpsrepo_ior "
                   . " -ORBDottedDecimalAddresses 1"
                   . " -ORBEndpoint iiop://$repo:$repo_port"
                   . " -ORBSvcConf repo.conf -d $domains_file -DCPSConfigFile \"conf.ini\"";

open( FILE, '>' . $settings{'results'} . '.params' );
  print FILE $parameters . "\n";
close(FILE);

&writeSettings($settings{'results'} . '.settings');


#die "Settings and Parameters have been written... Exiting";
#exit 0;


$DCPSREPO = new PerlACE::Process ("$DDS_ROOT/dds/InfoRepo/DCPSInfoRepo",
                                  $parameters);
print $DCPSREPO->CommandLine(), "\n";

$DCPSREPO->Spawn ();

if (PerlACE::waitforfile_timed ($dcpsrepo_ior, 30) == -1) {
    print STDERR "ERROR: waiting for DCPSInfo IOR file\n";
    $DCPSREPO->Kill ();
    exit 1;
}

sleep (99999999999);

exit $status;

