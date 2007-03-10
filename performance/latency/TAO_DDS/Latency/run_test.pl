eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id: run_test.pl 461 2007-02-09 15:35:05Z mitza $
# -*- perl -*-

use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::Run_Test;

$status = 0;
$output_file = PerlACE::LocalFile ("results");
$num_invocations = 10000;
$num_primers = 100;
$data_size = 4;


$opts =  "-ORBSvcConf tcp.conf";
$pub_opts = "$opts -DCPSConfigFile pub.ini";
$sub_opts = "$opts -DCPSConfigFile sub.ini";
$test_type = "byte_seq";

if ($ARGV[0] eq '-tcp')
{
}
elsif ($ARGV[0] eq '-udp') {
    $opts =  "-ORBSvcConf udp.conf";
    $pub_opts = "$opts -DCPSConfigFile pub_udp.ini";
    $sub_opts = "$opts -DCPSConfigFile sub_udp.ini";
}
elsif ($ARGV[0] eq '-mcast') {
    $opts =  "-ORBSvcConf mcast.conf";
    $pub_opts = "$opts -DCPSConfigFile pub_mcast.ini";
    $sub_opts = "$opts -DCPSConfigFile sub_mcast.ini";
}

# Parse the arguments

for ($j = 0; $j <= $#ARGV; $j++) {
    if ($ARGV[$j] eq "-h" || $ARGV[$j] eq "-?") {
      print "Perl script for TAO DDS DCPS Latency Test\n\n";
      print "RUN.pl [-t test_type] [-r output_file] [-p num] [-s num] [-u]]\n";
      print "\n";
      print "-t <test type>        -- 'byte_seq' (default) or 'complex'\n";
      print "-r <output file>      -- set name of results output file\n";
      print "-p num                -- number of primer iterations\n";
      print "-s num                -- number of stat-gathering iterations\n";
      print "-d data_size          -- message size \n";
      exit 0;
    }
    elsif ($ARGV[$j] eq "-t") {
      $test_type = $ARGV[$j + 1];
      $j++;
    }
    elsif ($ARGV[$j] eq "-r") {
      $output_file = $ARGV[$j + 1];
      $j++;
    }
    elsif ($ARGV[$j] eq "-p") {
      $num_primers = $ARGV[$j + 1];
      $j++;
    }
    elsif ($ARGV[$j] eq "-s") {
      $num_invocations = $ARGV[$j + 1];
      $j++;
    }
    elsif ($ARGV[$j] eq "-d") {
      $data_size = $ARGV[$j + 1];
      $j++;
    }
    else {
      print STDERR "error: invalid argument.\n";
      exit 1;
    }
}

$domains_file = PerlACE::LocalFile ("domain_ids");
$dcpsrepo_ior = PerlACE::LocalFile ("repo.ior");

unlink $dcpsrepo_ior;
unlink $output_file;


$DCPSREPO = new PerlACE::Process ("$ENV{DDS_ROOT}/bin/DCPSInfoRepo",
				  "-NOBITS -o $dcpsrepo_ior -d $domains_file");
$DCPSREPO->Spawn ();

sleep (2);

if (PerlACE::waitforfile_timed ($dcpsrepo_ior, 30) == -1) {
    print STDERR "ERROR: waiting for DCPSInfo IOR file\n";
    $DCPSREPO->Kill ();
    exit 1;
}


$Subscriber = new PerlACE::Process ("tao_sub");
$Publisher = new PerlACE::Process ("tao_pub");



$Subscriber->Arguments ("$sub_opts -t $test_type");
$Subscriber->Spawn ();
 
sleep (2);
    
$Publisher->Arguments ("$pub_opts -t $test_type -r $output_file -p $num_primers -s $num_invocations -d $data_size");
$client = $Publisher->SpawnWaitKill (3600);

if ($client != 0) {
    print STDERR "ERROR: client returned $client\n";
    $status = 1;
}
  
$Subscriber->Kill (); 
$Subscriber->TimedWait (1);


$DCPSREPO->Kill ();

#unlink $output_file;

exit $status;
