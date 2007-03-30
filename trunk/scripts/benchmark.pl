#!/usr/bin/perl

# author: James Edmondson
# purpose: program to run scriptable DDS benchmarks

# usage:

#
# benchmark.pl [-q qosFile] [-n netFile] [-i implementation] [-type testType]
#              [-minSize #] [-maxSize #] [-primer #] [-statsMessages #]
#              [settingsFile]

# ARG LIST
# 1. -i               implementation (NDDS | TAO-DDS - can be mixed case)
# 2. -n               network settings file
# 3. -q               qos settings file
# 4. -minsize         minimum packet size
# 5. -maxsize         maximum packet size
# 6. -type            type of test to run (throughput | latency)
# 7. -primer          number of primer messages to send before stats start
# 8. -statsMessages   number of messages to log stats for 
# n.                  if any othe parameter is passed, it is treated as a
#                     settings file

use Fcntl ':flock';
use Env (DBE_SCRIPTS);
use Env (DBE_ROOT);
use Env (DBE_LOCAL_ROOT);
use Env (DBE_RESULTS_BACKUP);

require "$DBE_SCRIPTS/scripts.lib";

# check to see if the user needs help

if( @ARGV > 0 )
{
  if( @ARGV[0] eq "-h" )
  {
    print "\n" . 
      "Usage:\n\n" .
      "  benchmark.pl [-h] [-i impl] [-minsize #] [-maxsize #]
             [-n netSettings] [-q defaultQoS] [-type testType]
             [-primer numPrimerMessages] [-stats numStatsMessages]
             [testSettingsFile]\n";
    print "  [-h] prints usage information for this script.\n";
    print "  [-i impl] specifies the DDS implementation to test (NDDS, etc.)\n";
    print "  [-minsize #] specifies the min data size to test (4, 8, etc.)\n";
    print "  [-maxsize #] specifies the max data size to test (16384, etc.)\n";
    print "  [-n netSettings] specifies the network settings to test.\n";
    print "  [-q defaultQoS] specifies the default QoS settings to test.\n";
    print "  [-type testType] specifies the type of test (throughput).\n";
    print "  [-primer #] specifies the number of primer messages.\n";
    print "  [-stats #] specifies the number of messages to actually record
                        data for, after primer messages have been received.\n";
    print "  [testSettingsFile] specifies the test settings file to test.\n";
    print "\n";
    exit(0);
  }
}


print "Made it to the read settings function..\n";

%settings = ();

&setEnvironment("$DBE_ROOT/settings/environment");
&readSettingsFromArgs();

print "Settings have been read..\n";

# used for debugging if we need to know hash keys and values
#foreach $key (keys %settings)
#{
#  print $key . " = " . $settings{$key} . "\n";
#}


# setup base path for all executables

$path = "$DBE_LOCAL_ROOT/performance/";

$type = lc($settings{'type'});

if( $type eq "latency" )
{
  $path .= "latency/";
}
else
{
  $path .= "throughput/";
}

#$settings{'results'} = $path;

#$testing = &getTestDirectory();

#print "Test directory is $testing.\n";
#exit(0);

# add implementation specific path information. notice that implementations
# may be upper or lower case.

$impl = lc($settings{'impl'});

if( $impl eq "ndds" )
{
  if( $type eq "throughput" )
  {
    $path .= "NDDS/";
  }
  elsif( $type eq "latency" )
  {
    $path .= "NDDS/latency/";
  }
}
elsif( $impl eq "tao" || $impl eq "tao-dds" || $impl eq "tao_dds"
     || $impl eq "taodds" )
{
  $impl = 'tao';
  if( $type eq "throughput" )
  {
    $path .= "TAO_DDS/TCP/";
  }
  else
  {
    $path .= "TAO_DDS/Latency/";
  }
}
elsif( $impl eq "splice" || $impl eq "opensplice" || $impl eq "open-splice"
     || $impl eq "open_splice" )
{
  $impl = 'splice';
  $path .= "OpenSplice/";
}
else
{
  die "Sorry, but implementation type '$impl' is not supported" .
      " by this script. Try TAO-DDS, SPLICE or NDDS. Use -h for usage info.\n";
}


# make sure that all the important arguments were provided

$settings{'nodes'} ne "" || die "You must include the number of nodes" . 
                                " to test on in args.\n";
$settings{'subscribers'} ne "" || die "You must include the number of" .
                                " subscribers in args.\n";
$settings{'publishers'}  ne "" || die "You must include the number of" .
                                " publishers in args.\n";

# we are officially starting. all parameters have superficially passed.
# assign a test id.

$settings{'id'} = $testid = &getId("$DBE_ROOT/settings/id.gen");
 
# now, make sure the results directories exist, and go ahead and make our
# test id directory for results.


$resultsDir = "$DBE_ROOT/results/$testid";
mkdir("$DBE_ROOT");
mkdir("$DBE_ROOT/results");
mkdir($resultsDir) || print "unable to create $resultsDir\n";

open(FILE,">$DBE_ROOT/results/$testid/impl.dat");
  print FILE uc($impl) . "\n";
close(FILE);

&writeSettings($resultsDir . "/settings.dat");
&updateTestsListingFile();
#&writeEnvironmentForSSH();

#&printSummary();

$NUM_NODES = $settings{'nodes'};

# was a node listing provided? if so, we don't need to generate one.

if( $settings{'nodelisting'} )
{
  $settings{'nodelist'} = $settings{'nodelisting'};
}

if( $settings{'nodelist'} ne 'true'  )
{
  # no node listing was provided by user, so generate our own
  # from knowledge of our own cluster nodes (blade30-44)

  for( $i = 0; $i < $NUM_NODES; $i++ )
  {
    $settings{'node' . $i} = "blade" . ($i + 30) . ".isislab.vanderbilt.edu";
  }
}

# Hieu's suggestion to copy executables to local directories


if( $impl eq "splice" )
{

#  &writeSpliceConfig($resultsDir . '/splice_config.xml');
#  copy the config file to each node

  for( $i = 0; $i < $settings{'nodes'}; $i++ )
  {
    #$sourcePath = "/export/home/tczar/OpenSpliceV2.1/HDE/x86.linux2.6/etc/" .
    #            "config";
    #$destPath = "/home/tczar/OpenSplice/V2.0beta/x86.linux2.6/etc/config";
    #$file = "ospl.xml";

    ##$node = $settings{"node$i"};
#    print "scp $node:$sourcePath/$file $node:$destPath/$file";
    #system("scp $node:$sourcePath/$file $node:$destPath/$file");

    #print "ssh -f tczar\@$node $DBE_SCRIPTS/spl_multicast_route.pl 225.3.2.1";
    #system("ssh -f tczar\@$node $DBE_SCRIPTS/spl_multicast_route.pl 225.3.2.1");


  }

  # setup multicast support on blades. If this has already been done,
  # the OS will just report back that a "file already exists"
  # If you see this message, don't be alarmed. It's just a quick fix
  # we did for Splice's unusual multicast requirements.


}



@files;

if( $type eq 'throughput' )
{
  if( $impl eq 'tao' )
  {
    $sourcePath = '$DBE_ROOT/performance/throughput/TAO_DDS/TCP';
    @files = ( 'subscriber', 'publisher', 'start_sub.pl' ,
                   'start_pub.pl' , 'start_repo.pl', 'repo.conf',
                   'udp.ini', 'udp.conf', 'tcp.ini'
              );
    $destPath = '$DBE_LOCAL_ROOT/performance/throughput/TAO_DDS/TCP';
  }
  elsif( $impl eq 'ndds' )
  {
    $sourcePath = '$DBE_ROOT/performance/throughput/NDDS';
    @files = ( 'objs/i86Linux2.6gcc3.4.3/subscriber',
               'objs/i86Linux2.6gcc3.4.3/publisher', 'start_sub.pl' ,
                   'start_pub.pl' 
              );
    $destPath = '$DBE_LOCAL_ROOT/performance/throughput/NDDS';
  }
  elsif( $impl eq 'splice' )
  {
    $sourcePath = '$DBE_ROOT/performance/throughput/OpenSplice';
    @files = ( 'listener/subscriber', 'listener/publisher',
               'waitset/subscriber', 'waitset/publisher',
               'start_sub.pl', 'start_pub.pl' );
    $destPath = '$DBE_LOCAL_ROOT/performance/throughput/OpenSplice';
  }
}
else
{
  if( $impl eq 'splice' )
  {
    $sourcePath = '$DBE_ROOT/performance/latency/OpenSplice';
    @files = ( 'exec/subscriber', 'exec/publisher',
               'start_sub.pl', 'start_pub.pl' );
    $destPath = '$DBE_LOCAL_ROOT/performance/latency/OpenSplice';
  }
  elsif( $impl eq 'ndds' )
  {
    $sourcePath = '$DBE_ROOT/performance/latency/NDDS/latency';
    @files = ( 'objs/i86Linux2.6gcc3.4.3/subscriber', 
               'objs/i86Linux2.6gcc3.4.3/publisher',
               'start_sub.pl', 'start_pub.pl' );
    $destPath = '$DBE_LOCAL_ROOT/performance/latency/NDDS/latency';
  }
  elsif( $impl eq 'tao' )
  {
    $sourcePath = '$DBE_ROOT/performance/latency/TAO_DDS/Latency';
    @files = ( 'domain_ids', 'tcp.conf', 'udp.conf', 'mcast.conf', 
               'pub.ini', 'sub.ini', 'pub_udp.ini', 'sub_udp.ini',
               'pub_mcast.ini', 'sub_mcast.ini',
               'tao_sub', 'tao_pub',
               'start_sub.pl', 'start_pub.pl', 'start_repo.pl' );
    $destPath = '$DBE_LOCAL_ROOT/performance/latency/TAO_DDS/Latency';
  }
}


# Only TAO-DDS requires a repo. So, if this is any other implementation,
# set the number of repos to zero. 

if ($impl ne 'tao')
{
  $settings{'repos'} = 0;
}


# copy all of the necessary files

for( $i = 0; $i < $settings{'nodes'}; $i++ )
{
  $node = $settings{"node$i"};
  foreach $file (@files)
  {
#    print "scp $node:$sourcePath/$file $node:$destPath/$file";
    system("scp $node:$sourcePath/$file $node:$destPath/$file");
  }
}



for( $i = 0, $j = 0; 
     $j < $settings{'repos'}; 
     $i = ($i + 1) % $NUM_NODES , $j++ )
{
  print "Starting Repo (" . $settings{'node' . $i} . ")...\n";

  $command = "'sudo perl " . $path . 'start_repo.pl' .
             " -r $DBE_ROOT/results/$testid/repo$j" .
             ' -n ' . $settings{'net'} . ' -minSize ' . $settings{'minsize'} .
             ' -maxSize ' . $settings{'maxsize'} . ' -type ' .
             $settings{'type'} . ' -primer ' . $settings{'primer'} .
             ' -stats ' . $settings{'statsmessages'} .
             ' -nodes ' . $settings{'nodes'} .
             ' -subs ' . $settings{'subscribers'} .
             ' -test ' . $settings{'testsettings'};

  if( $settings{"repo$j.qos"} ne "" )
  {
    $command .= ' -q ' . $settings{"repo$j.qos"};
  }
  elsif( $settings{"node$i" . '.qos'} ne "" )
  {
    $command .= ' -q ' . $settings{"node$i" . '.qos'}; 
  }
  else
  {
    $command .= ' -q ' . $settings{'qos'};
  }

  if( $settings{"repo$j.script"} ne "" )
  {
    $command .= ' -script ' . $settings{"repo$j.script"};
  }

  $command .= " & '";


  system('ssh -f tczar@' . $settings{"node$i"} . " $command" .
         ' > ' . $resultsDir . '/repo' . $j . '.log'   . ' 2>&1');
}

# wait for a few seconds before starting up the subscribers. 

sleep(3);

# setup the subscribers

$temp = $settings{'repos'} + $settings{'publishers'};
$lastsub = $temp + $settings{'subscribers'};
for( $i = $temp % $NUM_NODES, $j = 0; 
     $j < $settings{'subscribers'}; 
     $i = ($i + 1) % $NUM_NODES, $j++ )
{
  print "Starting Subscriber (" . $settings{'node' . $i} . ")...\n";

  touch($resultsDir . "/sub$j" . '.exists');

  $command = "'sudo perl " . $path . 'start_sub.pl' .
             " -r $DBE_ROOT/results/$testid/sub$j" .
             ' -n ' . $settings{'net'}  . ' -minSize ' . $settings{'minsize'} .
             ' -maxSize ' . $settings{'maxsize'} . ' -type ' .
             $settings{'type'} . ' -primer ' . $settings{'primer'} .
             ' -stats ' . $settings{'statsmessages'} .
             ' -nodes ' . $settings{'nodes'} .
             ' -subs ' . $settings{'subscribers'} .
             ' -test ' . $settings{'testsettings'};


  if( $settings{"sub$j.qos"} ne "" )
  {
    $command .= ' -q ' . $settings{"sub$j.qos"};
  }
  elsif( $settings{"node$i" . '.qos'} ne "" )
  {
    $command .= ' -q ' . $settings{"node$i" . '.qos'};
  }
  else
  {
    $command .= ' -q ' . $settings{'qos'};
  }

  if( $settings{"sub$j.script"} ne "" )
  {
    $command .= ' -script ' . $settings{"sub$j.script"};
  }

  $command .= " & '";

  system('ssh -f tczar@' . $settings{"node$i"} . " $command" .
         ' > ' . $resultsDir . '/sub' . $j . '.log'  . ' 2> '
       . $resultsDir . "/sub$j.err");
}

# sleep for 5 seconds before we start up the publishers. We'd 
# like for the subscribers to already be in place when the publishers
# start passing out data.

sleep(5);


# setup the publishers

for( $i = $settings{'repos'} % $NUM_NODES,  $j = 0;
     $j < $settings{'publishers'};
     $i = ($i + 1) % $NUM_NODES, $j++ )
{
  print "Starting Publisher (" . $settings{'node' . $i} . ")...\n";

  touch($resultsDir . "/pub$j" . '.exists');

  $command = "'sudo perl " . $path . 'start_pub.pl' .
             " -r $DBE_ROOT/results/$testid/pub$j" .
             ' -n ' . $settings{'net'}  . ' -minSize ' . $settings{'minsize'} .
             ' -maxSize ' . $settings{'maxsize'} . ' -type ' .
             $settings{'type'} . ' -primer ' . $settings{'primer'} .
             ' -stats ' . $settings{'statsmessages'} .
             ' -nodes ' . $settings{'nodes'} .
             ' -subs ' . $settings{'subscribers'} .
             ' -test ' . $settings{'testsettings'};

  if( $settings{"pub$j.qos"} ne "" )
  {
    $command .= ' -q ' . $settings{"pub$j.qos"};
  }
  elsif( $settings{"node$i" . '.qos'} ne "" )
  {
    $command .= ' -q ' . $settings{"node$i" . '.qos'};
  }
  else
  {
    $command .= ' -q ' . $settings{'qos'};
  }

  if( $settings{"pub$j.script"} ne "" )
  {
    $command .= ' -script ' . $settings{'script'};
  }

  $command .= " & '";

#  print $command . "\n";
#  sleep(5);


  system('ssh -f tczar@' . $settings{"node$i"} . " $command" .
         ' > ' . $resultsDir . '/pub' . $j . '.log' . ' 2> '
       . $resultsDir . "/pub$j.err");


}

# give everything a little bit of time before we start checking if anything
# is finished / wrong.

sleep(5);

print "Waiting for processes to terminate (" .
      $settings{'publishers'} . ')(' . $settings{'subscribers'} . ") ...\n";

$done = 0;

$numPubs = $settings{'publishers'};
$numSubs = $settings{'subscribers'};

%errors = {};

while( !$done )
{

  $pubsRunning = 0;
  $subsRunning = 0;

  # check to see if publisher is still running. If anything has been
  # printed to stderr, let the user know about it. Publisher errors
  # tend to be more important than Subscriber errors, so we distinguish
  # between the two explicitly. The publisher message is "ERROR: ..."
  # and the subscriber just reports that there might have been an error.

  for( $i = 0; $i < $numPubs; $i++ )
  {
    if( -e $resultsDir . "/pub$i.exists" )
    {
      $pubsRunning++;
    }

    # only report an error in a publisher once. Repeating this (especially
    # for TAO-DDS gets annoying.

    if( !$errors{"pub$i"} &&  -s $resultsDir . "/pub$i.err" )
    {
      $errors{"pub$i"} = 1;

      print "ERROR: Publisher has encountered an error (pub$i.err).\n";
    }
  }

  # check to see if subscribers are still running. Also check if there
  # was anything printed to stderr. Report to the user if errors are possible.

  for( $i = 0; $i < $numSubs; $i++ )
  {
    if( -e $resultsDir . "/sub$i.exists" )
    {
      $pubsRunning++;
    }
    if( !$errors{"sub$i"} && -s $resultsDir . "/sub$i.err" )
    {
      $errors{"sub$i"} = 1;

      print "Subscriber may have encountered an error (check sub$i.err).\n";
    }
  }

  if( $pubsRunning == 0 && $subsRunning == 0 )
  {
    print "All publishers and subscribers have completed. Exiting...\n";
    $done = 1;
  }

  # wait a few seconds before checking again

  sleep(2);
}

system("$DBE_SCRIPTS/testCopy.pl $DBE_RESULTS_BACKUP $testid");

exit 0;
