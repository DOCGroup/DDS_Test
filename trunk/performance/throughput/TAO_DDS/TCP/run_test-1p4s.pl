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

# multiple readers with single instances test
$primer_messages=100;
$stats_messages=10000;
$num_writers=1;
$num_readers=4;
$pub_writer_id=0;

$num_messages=$primer_messages + $stats_messages;

$domains_file = PerlACE::LocalFile ("domain_ids");
$dcpsrepo_ior = PerlACE::LocalFile ("repo.ior");
$pub_outfile = PerlACE::LocalFile ("stats_pub");
$sub_outfile = PerlACE::LocalFile ("stats_sub");

$sub1_outfile = $sub_outfile . "1";
$sub2_outfile = $sub_outfile . "2";
$sub3_outfile = $sub_outfile . "3";
$sub4_outfile = $sub_outfile . "4";

unlink $dcpsrepo_ior; 
unlink $pub_outfile;
unlink $sub1_outfile;
unlink $sub2_outfile;
unlink $sub3_outfile;
unlink $sub4_outfile;

$DCPSREPO = new PerlACE::Process ("$DDS_ROOT/dds/InfoRepo/DCPSInfoRepo",
                             "-NOBITS -o $dcpsrepo_ior"
                             . " -d $domains_file -DCPSConfigFile \"\"");

print $DCPSREPO->CommandLine(), "\n";

$sub_parameters = "-DCPSConfigFile conf.ini -w $num_writers"
#                . " -DCPSDebugLevel 6"
                . " -p $primer_messages -s $stats_messages"
                . " -msi $num_messages -mxs $num_messages";
#use -msi $num_messages to avoid rejected samples
#use -mxs $num_messages to avoid using the heap 
#   (could be less than $num_messages but I am not sure of the limit).

#NOTE: above 1000 queue samples does not give any better performance.
$pub_parameters = "-DCPSConfigFile conf.ini -p 1 -i $pub_writer_id"
#              . " -DCPSDebugLevel 6"
              . " -p $primer_messages -s $stats_messages" 
              . " -r $pub_outfile -msi 1000 -mxs 1000";

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
                                              . " -r $sub1_outfile" 
                                              . " -d $data_size");
  print $Sub1->CommandLine(), "\n";
  $Sub2 = new PerlACE::Process ("subscriber", $sub_parameters 
                                              . " -r $sub2_outfile" 
                                              . " -d $data_size");
  print $Sub2->CommandLine(), "\n";
  $Sub3 = new PerlACE::Process ("subscriber", $sub_parameters 
                                              . " -r $sub3_outfile" 
                                              . " -d $data_size");
  print $Sub3->CommandLine(), "\n";
  $Sub4 = new PerlACE::Process ("subscriber", $sub_parameters 
                                              . " -r $sub4_outfile" 
                                              . " -d $data_size");
  print $Sub4->CommandLine(), "\n";

  $Publisher = new PerlACE::Process ("publisher", $pub_parameters 
                                                  . " -d $data_size");
  print $Publisher->CommandLine(), "\n";

  $Sub1->Spawn ();
  $Sub2->Spawn ();
  $Sub3->Spawn ();
  $Sub4->Spawn ();

  $Publisher->Spawn ();

  $PublisherResult = $Publisher->WaitKill (1200);
  if ($PublisherResult != 0) {
      print STDERR "ERROR: publisher returned $PublisherResult \n";
      $status = 1;
  }

  $Sub1Result = $Sub1->WaitKill (1200);
  if ($Sub1Result != 0) {
      print STDERR "ERROR: subscriber 1 returned $Sub1Result\n";
      $status = 1;
  }

  $Sub2Result = $Sub2->WaitKill (1200);
  if ($Sub2Result != 0) {
      print STDERR "ERROR: subscriber 2 returned $Sub2Result \n";
      $status = 1;
  }

  $Sub3Result = $Sub3->WaitKill (1200);
  if ($Sub3Result != 0) {
      print STDERR "ERROR: subscriber 3 returned $Sub3Result \n";
      $status = 1;
  }

  $Sub4Result = $Sub4->WaitKill (1200);
  if ($Sub4Result != 0) {
      print STDERR "ERROR: subscriber 4 returned $Sub4Result \n";
      $status = 1;
  }
}

$ir = $DCPSREPO->TerminateWaitKill(5);
if ($ir != 0) {
    print STDERR "ERROR: DCPSInfoRepo returned $ir\n";
    $status = 1;
}

exit $status;
