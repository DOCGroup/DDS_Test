#!/usr/bin/perl

eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;


# Author: Jeff Parsons, James Edmondson
# Purpose: Setup a Subscriber

use Env (ACE_ROOT);
use Env (DDS_ROOT);
use lib "$ACE_ROOT/bin";
use PerlACE::Run_Test;
use Cwd;

require  "/export/home/tczar/scripts/scripts.lib";

# no terminal? no problem...

chdir("/home/tczar/DDS/performance/throughput/TAO_DDS/TCP");
system("/export/home/tczar/scripts/enable_cores.sh");


#print "Subscriber CWD: " . getcwd() . "\n";
#exit(0);


&readSettingsFromArgs();

$status = 0;

PerlACE::add_lib_path('../TypeNoKeyBounded');

# if user wants the number of primer messages or stats messages
# modified, go ahead and change the defaults.

if( $settings{'primer'} ne "" )
{
  $primer_messages = $settings{'primer'};
}
else
{
  $primer_messages=100;
}

if( $settings{'statsmessages'} ne "" )
{
  $stats_messages = $settings{'statsmessages'};
}
else
{
  $stats_messages=10000;
}

$pub_writer_id=0;
$repo_port = 60001;
$repo = "blade30.isislab.vanderbilt.edu";

if( $settings{'nodelist'} eq 'true' )
{
  $repo = $settings{'node0'};
}

# (possibly allocated by not yet queue by the transport because of greedy read).$num_messages=$primer_messages + $stats_messages;


$parameters = "-DCPSConfigFile conf.ini -w 1"
              . " -DCPSDebugLevel 0  -ORBVerboseLogging 1"
              . " -ORBDottedDecimalAddresses 1"
              . " -DCPSInfoRepo corbaloc:iiop:$repo:$repo_port/DCPSInfoRepo"
              . " -p $primer_messages -s $stats_messages"
              . " -msi " . $settings{'samples.maxperinstance'}
              . ' -mxs ' . $settings{'samples.max'}
              . ' -r ' . $settings{'results'} . '.stats -n ' . $settings{'net'}
              . ' -q ' . $settings{'qos'};


# log parameters and settings used by the subscriber

@dataSizes = &generateDataSizes($settings{'minsize'},$settings{'maxsize'});

open( FILE, '>' . $settings{'results'} . '.params' );
  print FILE $parameters . "\n";
close(FILE);

&writeSettings($settings{'results'} . '.settings');

$testDirectory = &getTestDirectory();

#die "Settings and Parameters have been written... Exiting";
#exit 0;

#use -msi $num_messages to avoid rejected samples
#use -mxs $num_messages to avoid using the heap
#   (could be less than $num_messages but I am not sure of the limit).


foreach $data_size (@dataSizes)
{

  &touch($settings{'results'} . '.' .  $data_size);

  $Subscriber = new PerlACE::Process ("subscriber", $parameters
              . " -d " . $data_size . " -top test_topic_" . $data_size);
  print $Subscriber->CommandLine(), "\n";

  $SubscriberResult = $Subscriber->SpawnWaitKill (1200);

  if ($SubscriberResult != 0) {
      print STDERR "ERROR: subscriber returned $SubscriberResult \n";
      $status = 1;
  }

  # let everyone know that this subscriber is done with this data size

  unlink($settings{'results'} . '.' . $data_size);

  # don't start the next tests until all subscribers are done with this
  # data size

  $done = 0;

  while( $done == 0 )
  {
    $done = 1;
    for( $i = 0; $i < $settings{'subscribers'}; $i++)
    {
      if( -e $testDirectory . "/sub$i.$data_size" )
      {
        $done = 0;
      }
    }
  }

}

unlink($settings{'results'} . '.exists');

exit $status;

