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

chdir("/home/tczar/DDS/performance/throughput/Splice");
system("/export/home/tczar/scripts/enable_cores.sh");



# Because we now have to use sudo on our tests, we have to reset some
# environment variables that sudo clears for 'security' reasons
# see the manpage for sudo for details.

$lib='/home/tczar/ACE_wrappers/ace';
$lib.=':/home/tczar/ACE_wrappers/lib';
 $lib.=':/home/tczar/ACE_wrappers/TAO/TAO_IDL'; 
$lib.=':/export/home/tczar/ACE_wrappers/TAO/DDS/lib'; 
$lib.=':/home/tczar/rti/ndds.4.1c/lib/i86Linux2.6gcc3.4.3'; 
$lib.=':/export/home/tczar/DDS/Stats';
$lib.=':/export/home/tczar/DDS/performance/throughput/TAO_DDS/TypeNoKeyBounded';
$lib.=':/home/tczar/OpenSplice/V2.0beta/x86.linux2.6/lib';

$ENV{'LD_LIBRARY_PATH'} = $lib;

# attempt to export the new LD_LIBRARY_PATH - Hieu, June 24th, 4:41AM
# result: This DOES reset sudo's environment to what we want.
# to check, run:
#     ~/DDS/performance/throughput/Splice/start_sub.pl
# or look into pub's and sub's log after each test
#system("sh /export/home/tczar/sudo_env.sh");

#print "LD_LIBRARY is " . $ENV{'LD_LIBRARY_PATH'} . "\n";

&readSettingsFromArgs();

$status = 0;


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
$readers=1;

# (possibly allocated by not yet queue by the transport because of greedy read).$num_messages=$primer_messages + $stats_messages;


$parameters = ""
              . " -p $primer_messages -s $stats_messages"
              . ' -r ' . $settings{'results'} . '.stats -n ' . $settings{'net'}
              . ' -q ' . $settings{'qos'} . " -readers $readers";


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


$exe = "listener/subscriber";

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
    $exe = "waitset/subscriber";
    $done = 1;
  }
}



system("ospl stop");
#system("killall -s 9 -v durability");
#system("killall -s 9 -v spliced");
#system("killall -s 9 -v networking");

sleep(6);

foreach $data_size (@dataSizes)
{

  # Slice has an interesting 'feature'. It requires that one of its
  # services be started on each node for that data size. This service
  # must be started and stopped with the ospl call.

  system("ospl start");

  sleep(2);

  &touch($settings{'results'} . '.' .  $data_size);

  print "reduced command:\n";
  print "./suscriber -p $primer_messages -s $stats_messages -d $data_size -top test_topic_$data_size\n";

  $Subscriber = new PerlACE::Process (
              $exe , $parameters
              . " -d " . $data_size . " -top test_topic_" . $data_size);
  print $Subscriber->CommandLine(), "\n";

  $SubscriberResult = $Subscriber->SpawnWaitKill (600);

  if ($SubscriberResult != 0) {
      print STDERR "ERROR: subscriber returned $SubscriberResult \n";
      $status = 1;
  }

  sleep(6);

  system("ospl stop");
#  system("killall -s 9 -v durability");
#  system("killall -s 9 -v spliced");
#  system("killall -s 9 -v networking");

  sleep(4);

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

