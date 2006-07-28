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
system("/export/home/tczar/scripts/enable_cores.sh");


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
#$lib.=':/usr/bin';
#$ENV{'LD_LIBRARY_PATH'} = $lib;

system("printenv");

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



if( $settings{'nodelist'} eq 'true' )
{
  $repo = $settings{'node0'};
}

#NOTE: above 1000 queue samples does not give any better performance.
$parameters = "-i $pub_writer_id"
              . " -DCPSDebugLevel 0 -ORBVerboseLogging 1"
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

$parameters .= " -sub " . $settings{'subscribers'};

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

if( $settings{'results'} ne "" )
{
  $parameters .= ' -r ' . $settings{'results'}
}

if( $settings{'net'} ne "" )
{
  $parameters .= '.stats -n ' . $settings{'net'};
}

if( $settings{'reliability'} eq "keepall" )
{
  print "Keep all has been passed in\n";
  $parameters .= ' -keep_all';
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


#  print "./publisher $parameters -d $data_size -top test_topic_$data_size";
#  system("./publisher $parameters -d $data_size -top test_topic_$data_size");

  $Publisher = new PerlACE::Process ( 
             "publisher" ,  $parameters
              . " -d " . $data_size . " -top test_topic_" . $data_size);

  print $Publisher->CommandLine(), "\n";

  $Publisher->Spawn ();

  $PublisherResult = $Publisher->WaitKill (1200);

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
    for( $i = 0; $i < $settings{'subscribers'}; $i++)
    {
      if( -e $testDirectory . "/sub$i.$data_size" )
      {
        $done = 0;
      }
    }
  }

  print "Finished $data_size... Sleeping for 25 seconds before next round.\n";

  sleep(25);

}

unlink($settings{'results'} . '.exists');

exit $status;

