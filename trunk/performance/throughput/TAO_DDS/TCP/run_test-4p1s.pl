eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-

use Env (ACE_ROOT);
use Env (DDS_ROOT);
use lib "$ACE_ROOT/bin";
use PerlACE::Run_Test;

$status = 0;

PerlACE::add_lib_path('../TypeNoKeyBounded');

# single reader with single instances test
$primer_messages=100;
$stats_messages=10000;
$num_writers=4;
$num_readers=1;

$primer_samples=$primer_messages * $num_writers;
$stats_samples=$stats_messages * $num_writers;

# (possibly allocated by not yet queue by the transport because of greedy read).
$num_messages=$primer_messages + $stats_messages;
$num_samples=$primer_samples + $stats_samples;

$domains_file = PerlACE::LocalFile ("domain_ids");
$dcpsrepo_ior = PerlACE::LocalFile ("repo.ior");
$pub_outfile = PerlACE::LocalFile ("stats_pub");
$sub_outfile = PerlACE::LocalFile ("stats_sub");

$pub1_outfile = $pub_outfile . "1";
$pub2_outfile = $pub_outfile . "2";
$pub3_outfile = $pub_outfile . "3";
$pub4_outfile = $pub_outfile . "4";

unlink $dcpsrepo_ior; 
unlink $sub_outfile;
unlink $pub1_outfile;
unlink $pub2_outfile;
unlink $pub3_outfile;
unlink $pub4_outfile;

$DCPSREPO = new PerlACE::Process ("$DDS_ROOT/dds/InfoRepo/DCPSInfoRepo",
                             "-NOBITS -o $dcpsrepo_ior"
                             . " -d $domains_file -DCPSConfigFile \"\"");

print $DCPSREPO->CommandLine(), "\n";

$sub_parameters = "-DCPSConfigFile conf.ini -w $num_writers"
#                . " -DCPSDebugLevel 6"
                . " -p $primer_samples -s $stats_samples -o $sub_outfile"
                . " -msi $num_samples -mxs $num_samples";

#use -msi $num_samples to avoid rejected samples
#use -mxs $num_samples to avoid using the heap 
#   (could be less than $num_messages but I am not sure of the limit).

#NOTE: above 1000 queue samples does not give any better performance.
$pub_parameters = "-DCPSConfigFile conf.ini -p 1"
#              . " -DCPSDebugLevel 6"
              . " -p $primer_messages -s $stats_messages" 
              . " -r $num_readers -msi 1000 -mxs 1000";

$DCPSREPO->Spawn ();

if (PerlACE::waitforfile_timed ($dcpsrepo_ior, 30) == -1) {
    print STDERR "ERROR: waiting for DCPSInfo IOR file\n";
    $DCPSREPO->Kill ();
    exit 1;
}

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

foreach $data_size (@dataSizes) {
  $Sub1 = new PerlACE::Process ("subscriber", $sub_parameters
                                              . " -d $data_size");
  print $Sub1->CommandLine(), "\n";

  $pub_writer_id=0;
  
  $Pub1 = new PerlACE::Process ("publisher", $pub_parameters 
                                             . " -i $pub_writer_id"
                                             . " -o $pub1_outfile"
                                             . " -d $data_size");
  print $Pub1->CommandLine(), "\n";
  
  $pub_writer_id++;
  
  $Pub2 = new PerlACE::Process ("publisher", $pub_parameters 
                                             . " -i $pub_writer_id"
                                             . " -o $pub2_outfile"
                                             . " -d $data_size");
  print $Pub2->CommandLine(), "\n";
  
  $pub_writer_id++;
  
  $Pub3 = new PerlACE::Process ("publisher", $pub_parameters 
                                             . " -i $pub_writer_id"
                                             . " -o $pub3_outfile"
                                             . " -d $data_size");
  print $Pub3->CommandLine(), "\n";
  
  $pub_writer_id++;
  
  $Pub4 = new PerlACE::Process ("publisher", $pub_parameters 
                                             . " -i $pub_writer_id"
                                             . " -o $pub4_outfile"
                                             . " -d $data_size");
  print $Pub4->CommandLine(), "\n";

  $Sub1->Spawn ();

  $Pub1->Spawn ();
  $Pub2->Spawn ();
  $Pub3->Spawn ();
  $Pub4->Spawn ();

  $Pub1Result = $Pub1->WaitKill (1200);
  if ($Pub1Result != 0) {
      print STDERR "ERROR: publisher 1 returned $Pub1Result \n";
      $status = 1;
  }

  $Pub2Result = $Pub2->WaitKill (1200);
  if ($Pub2Result != 0) {
      print STDERR "ERROR: publisher 2 returned $Pub2Result \n";
      $status = 1;
  }

  $Pub3Result = $Pub3->WaitKill (1200);
  if ($Pub3Result != 0) {
      print STDERR "ERROR: publisher 3 returned $Pub3Result \n";
      $status = 1;
  }

  $Pub4Result = $Pub4->WaitKill (1200);
  if ($Pub4Result != 0) {
      print STDERR "ERROR: publisher 4 returned $Pub4Result \n";
      $status = 1;
  }

  $Sub1Result = $Sub1->WaitKill (1200);
  if ($Sub1Result != 0) {
      print STDERR "ERROR: subscriber 1 returned $Sub1Result\n";
      $status = 1;
  }
}

$ir = $DCPSREPO->TerminateWaitKill(5);
if ($ir != 0) {
    print STDERR "ERROR: DCPSInfoRepo returned $ir\n";
    $status = 1;
}

exit $status;
