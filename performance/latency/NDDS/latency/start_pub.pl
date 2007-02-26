#!/usr/bin/perl

eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;


# Authors: Jeff Parsons, James Edmondson
# Purpose: Setup a Publisher

use Env (ACE_ROOT);
use Env (TAO_ROOT);
use Env (LD_LIBRARY_PATH);
use Env (PATH);
use Env (DDS_ROOT);
use Env (DBE_SCRIPTS);
use Env (DBE_ROOT);
use lib "$ACE_ROOT/bin";
use PerlACE::Run_Test;
use Cwd;

require  "$DBE_SCRIPTS/scripts.lib";

#chdir("$DBE_ROOT/performance/throughput/NDDS");
system("$DBE_SCRIPTS/enable_cores.sh");

print "Current working directory is " . getcwd() . "\n";
print '$0 is ' . $0 . "....\n";
print 'getPath is ' . &getPath($0) . "\n";
print "Current working directory is " . getcwd() . "\n";

chdir(&getPath($0));


# Because we now have to use sudo on our tests, we have to reset some
# environment variables that sudo clears for 'security' reasons
# see the manpage for sudo for details.


&setEnvironment("$DBE_ROOT/settings/environment");
&readSettingsFromArgs();

#&setupNDDSDiscovery(1);
$status = 0;

#print "Discovery is " . $ENV{'NDDS_DISCOVERY_PEERS'} . "\n";

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

# New and untested - timers and scripts per publisher
# The following sets up default start and stop timers
# (if none are provided)

if( $settings{'default.start'} eq "" )
{
  $settings{'default.start'} = 0;
}

if( $settings{'default.stop'} eq "" )
{
  $settings{'default.stop'} = 1200;
}

print "Defaults for start/stop: " . $settings{'default.start'} .
      "/" . $settings{'default.stop'} . "\n";

# Because our settings files no longer allow simple QoS labels in the
# settings files, convert our QoS key/values into simpler ones

$settings{'samples.maxperinstance'} = $settings{'datawriter.resourcelimits.' .
                                    'maxsamplesperinstance'};
$settings{'samples.max'} = $settings{'datawriter.resourcelimits.' .
                                    'maxsamples'};
$settings{'instances.max'} = $settings{'datawriter.resourcelimits.' .
                                    'maxinstances'};
$settings{'reliability'} = $settings{'datawriter.reliability.kind'};
$settings{'durability'} = $settings{'datawriter.durability.kind'};
$settings{'history'} = $settings{'datawriter.history.kind'};
$settings{'history.depth'} = $settings{'datawriter.history.depth'};


# setup the parameter string to the executable.

$parameters = "";
$parameters .= " -s $stats_messages";

if( $settings{'samples.maxperinstance'} )
{
#  $parameters .= " -msi " . $settings{'samples.maxperinstance'};
}

if( $settings{'samples.max'} )
{
#  $parameters .= ' -mxs ' . $settings{'samples.max'};
}

if( $settings{'instances.max'} )
{
#  $parameters .= ' -mxi ' . $settings{'instances.max'};
}

$parameters .= ' -r ' . $settings{'results'} . '.stats';
#. '.stats -n ' . $settings{'net'};
#$parameters .= ' -q ' . $settings{'qos'};


$settings{'transport'} =~ s/ //g;

@transports = split(/\|/,$settings{'transport'});
$done = 0;

print "Transport is " . $settings{'transport'} . "\n";

while( $done == 0 && @transports > 0 )
{
  $transport = shift(@transports);

  print "Accessing first transport ($transport)...\n";

  if( $transport eq "multicast" || $transport eq "multi-cast"  )
  {
    $parameters .= " -multicast";
    $done = 1;
  }
  elsif( $transport eq "unicast" || $transport eq "uni-cast" )
  {
    $done = 1;
  }
}


$settings{'reliability'} =~ s/ //g;

@reliabilities = split(/\|/,$settings{'reliability'});
$done = 0;
while( $done == 0 && @reliabilities > 0 )
{
  $reliability = shift(@reliabilities);
  if( $reliability eq "reliable" )
  {
    $parameters .= " -e";
    $done = 1;
  }
  elsif( $reliability eq "best" || $reliability eq "best-effort" ||
         $reliability eq "best effort"|| $reliability eq "besteffort" )
  {
    $done = 1;
  }
}

$settings{'notify'} =~ s/ //g;

@notifies = split(/\|/,$settings{'notify'});
$done = 0;
while( $done == 0 && @notifies > 0 )
{
  $notify = shift(@notifies);
  if( $notify eq "listener" )
  {
    $done = 1;
  }
  elsif( $notify eq "wait" || $notify eq "wait-based" ||
         $notify eq "waitbased" )
  {
#    $parameters .= ' -wait';
    $done = 1;
  }
}

$settings{'history'} =~ s/ //g;

@histories = split(/\|/,$settings{'history'});
$done = 0;
while( $done == 0 && @histories > 0 )
{
  $history = shift(@histories);
  if( $history eq "keeplast" || $history eq "last" )
  {
    $done = 1;
  }
  elsif( $history eq "keepall" || $history eq "all" )
  {
#    $parameters .= ' -keep_all';
    $done = 1;
  }
}

if( $settings{'history.depth'} ne "" )
{
#  $parameters .= ' -depth ' . $settings{'history.depth'};
}




# log all Publisher parameters and settings

@dataSizes = &generateDataSizes($settings{'minsize'},$settings{'maxsize'});

open( FILE, '>' . $settings{'results'} . '.params' );
  print FILE $parameters . "\n";
close(FILE);

&writeSettings($settings{'results'} . '.settings');

#unlink($settings{'results'} . '.exists');
#exit(0);

$testDirectory = &getTestDirectory();
$id = &getIndividualId();

#unlink($settings{'results'} . '.exists');
#print "Settings and Parameters have been written... Exiting";
#exit 0;

$test_num = 0;
$start = 0;
$stop = 0;

foreach $data_size (@dataSizes)
{

  # setup the test timer parameters (start)

  if( $settings{"test$test_num.start"} ne "" )
  {
    $start = $settings{"test$test_num.start"};
  }
  else
  {
    $start = $settings{'default.start'};
  }

  # setup the test timer parameters (stop)

  if( $settings{"test$test_num.stop"} ne "" )
  {
    $stop = $settings{"test$test_num.stop"};
  }
  else
  {
    $stop = $settings{'default.stop'};
  }

  $exe = "objs/i86Linux2.6gcc3.4.3" .
         "/NDDSLatencyPacket_publisher";
  $outfile = $testDirectory . "/pub0." . "strace.$data_size";

  &touch( $settings{'results'} . '.' . $data_size );

#  system("strace -o pub0.strace.$data_size $exe " .
#         "$parameters -Size $data_size -top test_topic_$data_size" .
#         " -num_of_sub " . $settings{'subscribers'} );

  $Publisher = new PerlACE::Process ( 
     $exe , $parameters  . " -d $data_size"
      );

  print $Publisher->CommandLine(), "\n";

  # pause for $start seconds

  print STDERR "Start is $start\n";

  if( $start > 0 )
  {
    print STDERR "Sleeping for $start\n";
    sleep($start);
  }

  $Publisher->Spawn ();

  print STDERR "Stop is $stop\n";

  $Publisher->Wait($stop);

  $PublisherResult = $Publisher->TerminateWaitKill (0);

  if ($PublisherResult != 0) {
      print STDERR "ERROR: publisher returned $PublisherResult \n";
      $status = 1;
  }

  unlink( $settings{'results'} . '.' . $data_size );

  # give the subscribers time to restart and get read for the next test.

  $done = 0;

  while( $done == 0 )
  {
    $done = 1;

    # check for subscribers that are still working on data size
    
    for( $i = 0; $i < $settings{'subscribers'} && $done != 0; $i++)
    {
      if( -e $testDirectory . "/sub$i.$data_size" )
      {
        $done = 0;
      }
    }

    # check for publishers that are still working on data size

    for( $i = 0; $i < $settings{'publishers'} && $done != 0; $i++ )
    {
      if( -e $testDirectory . "/pub$i.$data_size" )
      {
        $done = 0;
      }
    }
  }

  print "Finished $data_size... Sleeping for 5 seconds before next round.\n";

  sleep(5);

  $Publisher = "";
}

unlink($settings{'results'} . '.exists');

exit $status;

