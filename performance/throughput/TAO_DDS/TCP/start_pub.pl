#!/usr/bin/perl

eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;


# Authors: Jeff Parsons, James Edmondson
# Purpose: Setup a Publisher

use Env (ACE_ROOT);
use Env (DDS_ROOT);
use lib "$ACE_ROOT/bin";
use PerlACE::Run_Test;
use Cwd;

require  "/export/home/tczar/scripts/scripts.lib";

# no terminal? no problem...

chdir("/home/tczar/DDS/performance/throughput/TAO_DDS/TCP");
#system("ulimit -c unlimited");
system("/export/home/tczar/scripts/enable_cores.sh");


#print "Publisher CWD: " . getcwd() . "\n";
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

#NOTE: above 1000 queue samples does not give any better performance.
$parameters = "-DCPSConfigFile conf.ini -i $pub_writer_id"
              . " -DCPSDebugLevel 0 -ORBVerboseLogging 1"
              . " -ORBDottedDecimalAddresses 1"
              . " -DCPSInfoRepo corbaloc:iiop:$repo:$repo_port/DCPSInfoRepo"
              . " -p $primer_messages -s $stats_messages"
              . " -msi " . $settings{'samples.maxperinstance'}
              . ' -mxs ' . $settings{'samples.max'}
              . ' -mxi ' . $settings{'instances.max'}
              . ' -sub ' . $settings{'subscribers'}
              . ' -r ' . $settings{'results'} . '.stats -n ' . $settings{'net'}
              . ' -q ' . $settings{'qos'};


# log parameters passed to the publisher and settings passed by command
# line and settings files

@dataSizes = &generateDataSizes($settings{'minsize'},$settings{'maxsize'});

open( FILE, '>' . $settings{'results'} . '.params' );
  print FILE $parameters . "\n";
close(FILE);

&writeSettings($settings{'results'} . '.settings');

# figure out the test directory we're writing to from our result file path

$testDirectory = &getTestDirectory();

print "Test directory is $testDirectory, from " . $settings{'results'} . "\n";

#die "Settings and Parameters have been written... Exiting";
#exit 0;


foreach $data_size (@dataSizes)
{

  &touch( $settings{'results'} . '.' . $data_size );


  print "./publisher $parameters -d $data_size -top test_topic_$data_size";
  system("./publisher $parameters -d $data_size -top test_topic_$data_size");

#  $Publisher = new PerlACE::Process ("publisher", $parameters
#              . " -d " . $data_size . " -top test_topic_" . $data_size);

#  print $Publisher->CommandLine(), "\n";

#  $Publisher->Spawn ();

#  $PublisherResult = $Publisher->WaitKill (1200);

#  if ($PublisherResult != 0) {
#      print STDERR "ERROR: publisher returned $PublisherResult \n";
#      $status = 1;
#  }

  unlink( $settings{'results'} . '.' . $data_size );

  # give the subscribers time to restart and get read for the next test.

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

  print "Finished $data_size... Sleeping for 3 seconds before next round.\n";

  sleep(10);

}

unlink($settings{'results'} . '.exists');

exit $status;

