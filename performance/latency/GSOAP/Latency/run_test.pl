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

# Parse the arguments

for ($i = 0; $i <= $#ARGV; $i++) {
    if ($ARGV[$i] eq "-h" || $ARGV[$i] eq "-?") {
      print "Perl script for gSOAP Latency Test\n\n";
      print "RUN.pl [-t data_type] [-o output_file] [-p num] [-i num]\n";
      print "\n";
      print "-t <data type>        -- 'byte_seq' (default) or 'complex'\n";
      print "-o <output file>      -- set name of results output file\n";
      print "-p num                -- number of primer iterations\n";
      print "-i num                -- number of stat-gathering iterations\n";
      exit 0;
    }
    elsif ($ARGV[$i] eq "-t") {
      $test_type = $ARGV[$i + 1];
      $i++;
    }
    elsif ($ARGV[$i] eq "-o") {
      $output_file = $ARGV[$i + 1];
      $i++;
    }
    elsif ($ARGV[$i] eq "-p") {
      $num_primers = $ARGV[$i + 1];
      $i++;
    }
    elsif ($ARGV[$i] eq "-i") {
      $num_invocations = $ARGV[$i + 1];
      $i++;
    }
}

unlink $output_file;

$SV = new PerlACE::Process ("server");
$CL = new PerlACE::Process ("client");

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

foreach $sample_size (@dataSizes) {

  $SV->Spawn ();

  sleep (1);

  $CL->Arguments ("-t $test_type -o $output_file -p $num_primers -i $num_invocations -s $sample_size");

  $client = $CL->SpawnWaitKill (3600); 

  if ($client != 0) {
      print STDERR "ERROR: client returned $client\n";
      $status = 1;
  }

  $SV->Kill (); 
  $SV->TimedWait (1);
}

exit $status;
