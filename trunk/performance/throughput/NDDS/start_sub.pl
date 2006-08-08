#!/usr/bin/perl

eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;


# Author: Jeff Parsons, James Edmondson
# Purpose: Setup a Subscriber

use Env (ACE_ROOT);
use Env (DDS_ROOT);
use Env (DBE_SCRIPTS);
use Env (DBE_ROOT);
use lib "$ACE_ROOT/bin";
use PerlACE::Run_Test;

require  "$DBE_SCRIPTS/scripts.lib";

chdir("$DBE_ROOT/performance/throughput/NDDS");
system("$DBE_SCRIPTS/enable_cores.sh");


# Because we now have to use sudo on our tests, we have to reset some
# environment variables that sudo clears for 'security' reasons
# see the manpage for sudo for details.

$lib='/home/tczar/ACE_wrappers/ace';
$lib.=':/home/tczar/ACE_wrappers/lib'; $lib.=':/home/tczar/ACE_wrappers/TAO/TAO_IDL'; $lib.=':/export/home/tczar/ACE_wrappers/TAO/DDS/lib'; $lib.=':/home/tczar/rti/ndds.4.1c/lib/i86Linux2.6gcc3.4.3'; $lib.=':/export/home/tczar/DDS/Stats';
$lib.=':/export/home/tczar/DDS/performance/throughput/TAO_DDS/TypeNoKeyBounded';$lib.=':/home/tczar/OpenSplice/V2.0beta/x86.linux2.6/lib';

$ENV{'LD_LIBRARY_PATH'} = $lib;



&readSettingsFromArgs();

#&setupNDDSDiscovery(2);

#print "DISCOVERY = " . $ENV{'NDDS_DISCOVERY_PEERS'} . "\n";

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

# New and untested - timers and scripts per subscriber
# The following sets up default start and stop timers
# (if none are provided).

if( $settings{'default.start'} eq "" )
{
  $settings{'default.start'} = 0;
}

if( $settings{'default.stop'} eq "" )
{
  $settings{'default.stop'} = 1200;
}


# Because our settings files no longer allow simple QoS labels in the
# settings files, convert our QoS key/values into simpler ones

$settings{'samples.maxperinstance'} = $settings{'datareader.resourcelimits.' .
                                    'maxsamplesperinstance'};
$settings{'samples.max'} = $settings{'datareader.resourcelimits.' .
                                    'maxsamples'};
$settings{'instances.max'} = $settings{'datareader.resourcelimits.' .
                                    'maxinstances'};
$settings{'reliability'} = $settings{'datareader.reliability.kind'};
$settings{'durability'} = $settings{'datareader.durability.kind'};
$settings{'history'} = $settings{'datareader.history.kind'};
$settings{'history.depth'} = $settings{'datareader.history.depth'};

#foreach $key (sort(keys %settings))
#{
#  print $key . " = " . $settings{$key} . "\n";
#}

# (possibly allocated by not yet queue by the transport because of greedy read).$num_messages=$primer_messages + $stats_messages;

# setup the parameter string to the executable.

$parameters = "";
$parameters .= " -pn $primer_messages -sn $stats_messages";

if( $settings{'samples.maxperinstance'} )
{
  $parameters .= " -msi " . $settings{'samples.maxperinstance'};
}

if( $settings{'samples.max'} )
{
  $parameters .= ' -mxs ' . $settings{'samples.max'};
}

if( $settings{'instances.max'} )
{
  $parameters .= ' -mxi ' . $settings{'instances.max'};
}

$parameters .= ' -r ' . $settings{'results'} . '.stats -n ' . $settings{'net'};
$parameters .= ' -q ' . $settings{'qos'};

$settings{'transport'} =~ s/ //g;

@transports = split(/\|/,$settings{'transport'});
$done = 0;
while( $done == 0 && @transports > 0)
{
  $transport = shift(@transports);
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
    $parameters .= " -reliable";
    $done = 1;
  }
  elsif( $reliability eq "best" || $reliability eq "best-effort" || 
         $reliability eq "best effort" || $reliability eq "besteffort" )
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
    $parameters .= ' -wait';
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
    $parameters .= ' -keep_all';
    $done = 1;
  }
}

if( $settings{'history.depth'} ne "" )
{
  $parameters .= ' -depth ' . $settings{'history.depth'};
}

# log all subscriber settings and parameters

@dataSizes = &generateDataSizes($settings{'minsize'},$settings{'maxsize'});

open( FILE, '>' . $settings{'results'} . '.params' );
  print FILE $parameters . "\n";
close(FILE);

&writeSettings($settings{'results'} . '.settings');

#unlink($settings{'results'} . '.exists');
#exit(0);

# find out where this test's result directory is, and
# grab our subscriber id

$testDirectory = &getTestDirectory();
$id = &getIndividualId();

#unlink($settings{'results'} . '.exists');
#print "Settings and Parameters have been written... Exiting";
#exit 0;

#use -msi $num_messages to avoid rejected samples
#use -mxs $num_messages to avoid using the heap
#   (could be less than $num_messages but I am not sure of the limit).

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


  $exe = "./objs/i86Linux2.6gcc3.4.3/subscriber";


  &touch($settings{'results'} . '.' . $data_size);

  $Subscriber = new PerlACE::Process (
        $exe ,  $parameters . " -role " . ($id + 1) .
        " -Size $data_size -top test_topic_$data_size");
  print $Subscriber->CommandLine(), "\n";


  # pause for $start seconds

  if( $start > 0 )
  {
    sleep($start);
  }          

  $Subscriber->Spawn();

  $Subscriber->Wait($stop);

  $SubscriberResult = $Subscriber->TerminateWaitKill (0);

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

}

unlink($settings{'results'} . '.exists');

exit $status;

