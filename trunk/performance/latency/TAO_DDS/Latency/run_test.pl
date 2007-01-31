eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id: RUN.pl,v 1.42 2005/04/15 12:31:25 mcorino Exp $
# -*- perl -*-

use lib "$ENV{ACE_ROOT}/bin";
use PerlACE::Run_Test;

$status = 0;
$output_file = PerlACE::LocalFile ("results");
$num_invocations = 10000;
$num_primers = 100;
$test_type = "byte_seq";
$use_udp = "";

# Parse the arguments

for ($j = 0; $j <= $#ARGV; $j++) {
    if ($ARGV[$j] eq "-h" || $ARGV[$j] eq "-?") {
      print "Perl script for TAO DDS DCPS Latency Test\n\n";
      print "RUN.pl [-t test_type] [-o output_file] [-p num] [-i num] [-u]]\n";
      print "\n";
      print "-t <test type>        -- 'byte_seq' (default) or 'complex'\n";
      print "-o <output file>      -- set name of results output file\n";
      print "-p num                -- number of primer iterations\n";
      print "-i num                -- number of stat-gathering iterations\n";
      print "-u                    -- forces UDP connection (default is TCP)\n";
      exit 0;
    }
    elsif ($ARGV[$j] eq "-t") {
      $test_type = $ARGV[$j + 1];
      $j++;
    }
    elsif ($ARGV[$j] eq "-o") {
      $output_file = $ARGV[$j + 1];
      $j++;
    }
    elsif ($ARGV[$j] eq "-p") {
      $num_primers = $ARGV[$j + 1];
      $j++;
    }
    elsif ($ARGV[$j] eq "-i") {
      $num_invocations = $ARGV[$j + 1];
      $j++;
    }
    elsif ($ARGV[$j] eq "-u") {
      $use_udp = "-u";
    }
}

unlink $output_file;

$REPO = new PerlACE::Process ("$ENV{DDS_ROOT}/dds/InfoRepo/DCPSInfoRepo");
$REPO->Arguments ("-NOBITS -o repo.ior -d domain_ids");
$REPO->Spawn ();

sleep (2);

$SV = new PerlACE::Process ("tao_sub");
$CL = new PerlACE::Process ("tao_pub");

@dataSizes =
  qw'4
     8
     16
     32
     64
     128
     256
     512
     1024
     2048
     4096
     8192
     16384';

foreach $seq_len (@dataSizes) {

  $SV->Arguments ("-t $test_type $use_udp");

  $SV->Spawn ();
  
  sleep (2);

  $CL->Arguments ("-t $test_type -o $output_file -p $num_primers -i $num_invocations -s $seq_len $use_udp");

  $client = $CL->SpawnWaitKill (3600);

  if ($client != 0) {
      print STDERR "ERROR: client returned $client\n";
      $status = 1;
  }
  
  $SV->Kill (); 
  $SV->TimedWait (1);
}

$REPO->Kill ();

#unlink $output_file;

exit $status;
