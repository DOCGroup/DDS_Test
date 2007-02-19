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

#chdir("$DBE_ROOT/performance/throughput/Splice");
system("$DBE_SCRIPTS/enable_cores.sh");

print "Current working directory is " . getcwd() . "\n";
print '$0 is ' . $0 . "....\n";
print 'getPath is ' . &getPath($0) . "\n";
print "Current working directory is " . getcwd() . "\n";
chdir(&getPath($0));

# load environment variables. this may help us get around the rt class
# problems.



# Because we now have to use sudo on our tests, we have to reset some
# environment variables that sudo clears for 'security' reasons
# see the manpage for sudo for details.


# attempt to export the new LD_LIBRARY_PATH - Hieu, June 24th, 4:41AM
# result: This DOES reset sudo's LD_LIBRARY_PATH to what we want
# to check: run 
#   ~/DDS/performance/throughput/Splice/start_pub.pl
# or look into pub's and sub's log after each run
#system("sh /export/home/tczar/sudo_env.sh");


#print "LD_LIBRARY is " . $ENV{'LD_LIBRARY_PATH'} . "\n";


&setEnvironment("$DBE_ROOT/settings/environment");
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
$writers = 1;

#NOTE: above 1000 queue samples does not give any better performance.
$parameters = ""
              . " -p $primer_messages -s $stats_messages"
              . ' -r ' . $settings{'results'} . '.stats -n ' . $settings{'net'}
              . ' -q ' . $settings{'qos'} . " -writers $writers";
$parameters = ' -r ' . $settings{'results'} . ".stats -s $stats_messages";

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

$exe = &getPath($0) . "/exec/publisher";

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
#    $exe = "waitset/publisher";
    $done = 1;
  }
}


&setEnvironment("$DBE_ROOT/settings/ospl_environment");


system("env");

system("ospl stop");
#system("killall -s 9 -v durability");
#system("killall -s 9 -v spliced");
#system("killall -s 9 -v networking");

&writeEnvironment($settings{'results'} . '.env');

foreach $data_size (@dataSizes)
{

  # Slice has an interesting 'feature'. It requires that one of its
  # services be started on each node for that data size. This service
  # must be started and stopped with the ospl call.


  sleep(4);

  system("$DBE_SCRIPTS/ospl_start");

  sleep(2);
  
  &touch( $settings{'results'} . '.' . $data_size );


  print "reduced command:\n";
  print "./splice_pub -p $primer_messages -s $stats_messages -d $data_size\n";
#  system("./publisher $parameters -d $data_size -top test_topic_$data_size");

  $Publisher = new PerlACE::Process ( 
              $exe , $parameters
              . " -d " . $data_size);

  print $Publisher->CommandLine(), "\n";

  $Publisher->Spawn ();

  $PublisherResult = $Publisher->WaitKill (90);

  if ($PublisherResult != 0) {
      print STDERR "ERROR: publisher returned $PublisherResult \n";
      $status = 1;
  }

  sleep(6);

#  system("killall -s 9 -v durability");
#  system("killall -s 9 -v spliced");
#  system("killall -s 9 -v networking");

  #tell everyone im finished  
  unlink( $settings{'results'} . '.' . $data_size );

  # Hieu says he has problems stopping the Splice service immediately
  # after the test is over. Our solution is to sleep for 6 seconds
  # to make sure.

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

  system("$DBE_SCRIPTS/ospl_stop");
  print "Finished $data_size...\n";

}

unlink($settings{'results'} . '.exists');

exit $status;

