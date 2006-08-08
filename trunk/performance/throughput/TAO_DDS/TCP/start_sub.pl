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

chdir("$DBE_ROOT/performance/throughput/TAO_DDS/TCP");
system("$DBE_SCRIPTS/enable_cores.sh");


# Because we now have to use sudo on our tests, we have to reset some
# environment variables that sudo clears for 'security' reasons
# see the manpage for sudo for details.

#$lib='/home/tczar/ACE_wrappers/ace';
#$lib.=':/home/tczar/ACE_wrappers/lib';
#$lib.=':/home/tczar/ACE_wrappers/TAO/TAO_IDL';
#$lib.=':/export/home/tczar/ACE_wrappers/TAO/DDS/lib';
#$lib.=':/home/tczar/rti/ndds.4.1c/lib/i86Linux2.6gcc3.4.3';
#$lib.=':/export/home/tczar/DDS/Stats';
#$lib.=':/export/home/tczar/DDS/performance/throughput/TAO_DDS/TypeNoKeyBounded';

#$lib.=':/home/tczar/OpenSplice/V2.0beta/x86.linux2.6/lib';
#
#$ENV{'LD_LIBRARY_PATH'} = $lib;




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
$repo = "blade37.isislab.vanderbilt.edu";


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

if( $settings{'results'} eq "" )
{
  $settings{'results'} = "sub0";
}

if( $settings{'nodelist'} eq 'true' )
{
  $repo = $settings{'node0'};
}

# (possibly allocated by not yet queue by the transport because of greedy read).$num_messages=$primer_messages + $stats_messages;



$parameters = " -w 1"
              . " -DCPSDebugLevel 0  -ORBVerboseLogging 1"
              . " -ORBDottedDecimalAddresses 1"
              . " -DCPSInfoRepo corbaloc:iiop:$repo:$repo_port/DCPSInfoRepo"
              . " -p $primer_messages -s $stats_messages";

$settings{'protocol'} =~ s/ //g;

@protocols = split(/\|/,$settings{'protocol'});
$done = 0;
while( $done == 0 && @protocols > 0 )
{
  $protocol = shift(@protocols);
  if( $protocol eq "udp" )
  {
    $parameters .= ' -DCPSConfigFile udp.ini';
    $parameters .= ' -ORBSvcConf udp.conf';
    $parameters .= ' -udp';
    $done = 1;
  }
  elsif( $protocol eq "tcp" )
  {
    $parameters .= ' -DCPSConfigFile tcp.ini';
    $done = 1;
  }
}


if( $settings{'subscribers'} eq "" )
{
  $settings{'subscribers'} = 1;
}

if( $settings{'samples.maxperinstance'} ne "" )
{
  $parameters .= " -msi " . $settings{'samples.maxperinstance'};
}

if( $settings{'samples.max'} ne "" )
{
  $parameters .= ' -mxs ' . $settings{'samples.max'};
}

if( $settings{'instances.max'} ne "" )
{
  $parameters .= ' -mxi ' . $settings{'instances.max'};
}

if( $settings{'reliability'} eq "keepall" )
{
  $parameters .= ' -keep_all';
}


if( $settings{'results'} ne "" )
{
  $parameters .= ' -r ' . $settings{'results'} 
}

if( $settings{'net'} ne "" )
{
  $parameters .= '.stats -n ' . $settings{'net'};
}

if( $settings{'qos'} ne "" )
{
  $parameters .= ' -q ' . $settings{'qos'};
}

if( $settings{'minsize'} eq "" )
{
  $settings{'minsize'} = 4;
}

if( $settings{'maxsize'} eq "" )
{
  $settings{'maxsize'} = 256;
}

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

  $Subscriber = new PerlACE::Process( 
              "subscriber" ,  $parameters
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

