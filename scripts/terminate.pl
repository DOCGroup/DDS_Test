#!/usr/bin/perl


use Env (DBE_SCRIPTS);
use Env (DBE_ROOT);
use Env (DBE_LOCAL_ROOT);
use Env (DBE_RESULTS_BACKUP);


require "$DBE_SCRIPTS/scripts.lib";

# AUTHOR'S NOTE!!!

# THIS SCRIPT WILL KILL ANY PERL TRANSLATION THAT IS CURRENTLY RUNNING
# ON THE NODE AND IS KILLABLE BY THE USER! THERE ARE NO OTHER EXCEPTIONS!

# if @ARGV == 0, then no test file was specified. test files provide us
# with information about the test that was run, so we can make intelligent
# killall calls. If nothing is specified, we blindly kill anything on 30-45.

&setEnvironment("$DBE_ROOT/settings/environment");
&setEnvironment("$DBE_ROOT/settings/ospl_environment");

$node;

if( @ARGV > 0 )
{
  if( @ARGV[0] eq "-h" )
  {
    print "\n" .
      "Usage:\n\n" .
      "  terminate.pl [-h] [-s signal] [-i impl] 
             [-n netSettings] [-q defaultQoS] [-type testType]
             [testSettings]\n";
    print "
  [-h] print usage information for this command.
  [-s signal] specifies the signal to kill processes with.
  [-i impl] specifies the implementation of the processes to kill.
  [-n netSettings] specifies network settings of test to kill.
  [-q defaultQoS] specifies QoS settings of test to kill.
  [-type testType] specifies the test type (throughput, etc.).
  [testSettings] specifies the main test settings file.\n\n";

    exit(0);
  }
}


if( @ARGV[0] eq '-s' )
{
  shift(@ARGV);
  $signal = '-s ' . shift(@ARGV);
}
else
{
  $signal = '-s 9';
}

if( @ARGV[0] eq '-n' )
{
  shift(@ARGV);
  $node = shift(@ARGV);
}

print "Killing all processes with signal: $signal\n";


if( @ARGV == 0 )
{
  for( $i = 30; $i <= 45; $i++ )
  {
    print "\nTerminating processes on blade$i.\n";
    system("ssh tczar\@blade$i.isislab.vanderbilt.edu 'sudo killall $signal -v perl'");
    system("ssh tczar\@blade$i.isislab.vanderbilt.edu 'sudo killall $signal -v DCPSInfoRepo'");
    system("ssh tczar\@blade$i.isislab.vanderbilt.edu 'sudo killall $signal -v subscriber'");
    system("ssh tczar\@blade$i.isislab.vanderbilt.edu 'sudo killall $signal -v publisher'");

    sleep(4);

    system("ssh tczar\@blade$i.isislab.vanderbilt.edu $DBE_SCRIPTS/ospl_stop");
  }
  exit(0);
}

if( $ARGV[0] eq "-h" || $ARGV[0] eq "-u" || $ARGV[0] eq "--help" )
{
  print "Script that terminates all processes started by benchmark.pl\n";
  print "Note that instances of benchmark.pl are NOT terminated.\n";
  print "  usage:  terminate.pl [testfile]\n";
}

# a test file must have been specified. let's see if it has anything for us.

%settings = ();

&readSettingsFromArgs();

$impl = lc($settings{'impl'});

if( $impl eq "ndds" )
{
}
elsif( $impl eq "tao" || $impl eq "tao-dds" || $impl eq "tao_dds"
     || $impl eq "taodds" )
{
  $impl = 'tao';
}
elsif( $impl eq "splice" || $impl eq "opensplice" || $impl eq "open-splice"
     || $impl eq "open_splice" )
{
  $impl = 'splice';
}



if( $impl ne "tao" )
{
  $settings{'repos'} = 0;
}

if( $settings{'nodelist'} eq "true" )
{

  print "Repos: " . $settings{'repos'} . " Pubs: " .  $settings{'publishers'}
      . " Subs: " . $settings{'subscribers'} . "\n";

  $i = $settings{'repos'} % $settings{'nodes'};
  $j = 0;
  for( $j = 0; $j < $settings{'publishers'}; $j++, 
                                            $i = ($i + 1)%$settings{'nodes'} )
  {
    $host = "";
    if( $settings{"node$i"} ne "" )
    {
      $host = $settings{"node$i"};
    }
    elsif( $settings{"pub$j"} ne "" )
    {
      $host = $settings{"pub$j"};
    }

    if( $host ne "" )
    {
      print "Killing all publishers on $host...\n";
      system("ssh tczar\@$host 'sudo killall $signal -v perl'");
      sleep(1);
      system("ssh tczar\@$host 'sudo killall $signal -v publisher'");

      if( $impl eq "tao" )
      {
        system("ssh tczar\@$host 'sudo killall $signal -v tao_pub'");
      }

      if( $impl eq "splice" )
      {
        sleep(2);
        print "ssh tczar\@$host 'sudo ospl stop'\n";
        system("ssh tczar\@$host $DBE_SCRIPTS/ospl_stop");
      }
    }
    else
    {
      die "One of your publishers (node$i or pub$j) is not setup properly.\n";
    }

  }

  $i = $settings{'publishers'} + $settings{'repos'};
  $i = $i % $settings{'nodes'};

  $j = 0;
  for( $j = 0; $j < $settings{'subscribers'}; $j++, 
                                              $i = ($i + 1)%$settings{'nodes'} )
  {
    $host = "";
    if( $settings{"node$i"} ne "" )
    {
      $host = $settings{"node$i"};
    }
    elsif( $settings{"sub$j"} ne "" )
    {
      $host = $settings{"sub$j"};
    }

    if( $host ne "" )
    {
      print "Killing all subscribers on $host...\n";
      system("ssh tczar\@$host 'sudo killall $signal -v perl'");
      sleep(1);
      system("ssh tczar\@$host 'sudo killall $signal -v subscriber'");

      if( $impl eq "tao" )
      {
        system("ssh tczar\@$host 'sudo killall $signal -v tao_sub'");
      }

      if( $impl eq "splice" )
      {
        sleep(2);
        system("ssh tczar\@$host $DBE_SCRIPTS/ospl_stop");
      }
    }
    else
    {
      die "One of your subscribers (node$i or sub$j) is not setup properly.\n";
    }
  }

  $i = 0;
  $j = 0;
  for( $j = 0; $j < $settings{'repos'}; $j++,
                                        $i = ($i+1)%$settings{'nodes'} )
  {
    $host = "";
    if( $settings{"node$i"} ne "" )
    {
      $host = $settings{"node$i"};
    }
    elsif( $settings{"repo$j"} ne "" )
    {
      $host = $settings{"repo$j"};
    }

    if( $host ne "" )
    {
      print "Killing all repos on $host...\n";
      system("ssh tczar\@$host 'sudo killall $signal -v perl'");
      sleep(1);
      system("ssh tczar\@$host 'sudo killall $signal -v DCPSInfoRepo'");

    }
    else
    {
      die "One of your repos (node$i or repo$j) is not setup properly.\n";
    }

  }
}
else
{
  die "If you provide a test file, it must have a node listing.\n" .
      " usage:   terminate.pl [testfile]\n";
}
