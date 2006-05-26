#!/usr/bin/perl

#Report generating script.
#Author: Hieu Nguyen

#This script is expected to be run within the
#results directory on the NFS partition.
use IO::File;
use File::Copy;

print "+------------------------+\n";
print "|DDS Benchmark Report Gen|\n";
print "+------------------------+\n\n";

#directories and default file formats generated by each test
#path to NFS partition
$nfs = "/export/home/tczar/";

#first argument is the ID of the test we want to generate report for
if ($ARGV[0] != "") {
  $test_id = $ARGV[0];
} else {
  $test_id = 1;
}

$bagatel = "Grapha/";
$results_dir = $nfs . "DDS/results/";
$test_dir = $results_dir . $test_id . "/";
$settings_file = "settings.dat";
$platform = "Linux"; #default platform is Linux

if (-e $test_dir) {
  print "Generate report for test#" . $test_id . "\n";
} else {
  die "test '/" . $test_id . "' directory doesn't exist.\n";
}

$filehandle = new IO::File;

#open settings file
$filename = $test_dir . $settings_file;
$filehandle->open("<" . $filename)
    or die "settings.dat not found!\n";

#get platform, implementation & benchmark info from settings file
until ($filehandle->eof) {
  $line = $filehandle->getline;
  chomp $line;

  if ($line =~ /^impl=/) {
    @result = split ( /=/, $line);
    $impl = lc ($result [1]);    
    print "impl is " . $impl . "\n";
  } 
 
  if ($line =~ /^type=/) {
    @result = split ( /=/, $line);
    $benchtype = lc ($result [1]);
    print "benchmark type is " . $benchtype . "\n";
  }
  
  if ($line =~ /^platform/) {
    @result = split ( /=/, $line);
    $platform = lc ($result [1]);
    print "platform is " . $platform . "\n";
  }  
} 

$filehandle->close;


#get list of raw data files in current test directory
#assuming they have the following format:
#   pub[pubID].stats
#   sub[subID].stats
#along with the raw data files are settings files of
#each of the pub/sub:
#   pub[pubID].params
#   pub[pubID].settings
#or
#   sub[subID].params
#   sub[subID].settings

opendir (TESTDIR, $test_dir)
  or die "Can't open current test directory!\n";

while ($a_file = readdir (TESTDIR)) {
  if ($a_file =~ /^sub[0-9]+.stats$/)
  {
    push (@sublist, $a_file);
  }
  if ($a_file =~ /^pub[0-9]+.stats$/)
  {
    push (@publist, $a_file);
  }
}

@rawlist = (@sublist, @publist);

print "\nRaw data files:\n";
foreach $a_file (@rawlist) {
  print $a_file . "\n";
}
print "\n";

closedir TESTDIR;

#create subdirs under Bagatel tree so the converted
#results can be copied to their proper locations.
#(Display.php looks for subdirs "Round_Trip" or
#"Throughput" under each broker/platform dir.)

if ($benchtype eq "throughput" || $benchtype eq "thruput" || $benchtype eq "tput") {
  $convert = $results_dir . "Convert_tput ";
  $newdir = "Throughput";
}

if ($benchtype eq "roundtrip" || $benchtype eq "round_trip" ||
    $benchtype eq "rtrip" || $benchtype eq "latency") {
  $convert = $results_dir . "Convert_rtrip "; 
  $newdir = "Round_Trip";
}

if ($impl eq "tao" || $impl eq "tao-dds" || $impl eq "tao_dds") {
  $impl_plat_dir = "TAO_DDS_Linux";
  #remove old results if existed
  print "dir:\n" . $nfs . $bagatel . "Bunch_Of_Results/_Result/TAO_DDS_Linux/" . $newdir . "\n";
  chdir $nfs . $bagatel . "Bunch_Of_Results/_Result/TAO_DDS_Linux/" . $newdir;
  print "Deleted old results (if existed)...\n";
  unlink (<*>);
}
if ($impl eq "splice") {
  $impl_plat_dir = "Splice_Linux";
  #remove old results if existed
  chdir $nfs . $bagatel . "Bunch_Of_Results/_Result/Splice_Linux/" . $newdir;
  print 'Deleted old results (if existed): ', unlink (<*>), ' files.';
}
if ($impl eq "ndds") {
  $impl_plat_dir = "NDDS_Linux";
  #remove old results if existed
  chdir $nfs . $bagatel . "Bunch_Of_Results/_Result/NDDS_Linux/" . $newdir;
  print 'Deleted old results (if existed): ', unlink (<*>), ' files.';
}


#create new directory for results
print "dir = " . $nfs . $bagatel . "Bunch_Of_Results/_Result/" . $impl_plat_dir . "/" . $newdir . "\n";
$newdir_path = $nfs . $bagatel . "Bunch_Of_Results/_Result/" . $impl_plat_dir . "/" . $newdir;
mkdir $newdir_path;


#convert raw data files to Bagatel's format
print "\nUse convert script:\n" . $convert . "\n\n";

foreach $a_file (@rawlist) {
  system($convert . $test_dir . $a_file);
}


#copy the converted results to their designated directory
#the names of the converted results are generated by the Convert_rtrip
#or Convert_tput script (under NFS results directory).
#the names of the final results under Bagatel must be in the
#format that Bagatel expects in Display.php
print "\nCopy converted results to designated directory in Bagatel...\n";
foreach $a_file (@rawlist) {
    $old = $test_dir . $a_file . ".0";
    $new = $newdir_path . "/" . $a_file . ".0";
    print "File to copy: " . $old . "\n";
    print "Copy to: " . $new . "\n";
    copy($old, $new);
}


#let Bagatel take over,
#Bagatel will use the converted data to generate
#the graph images and putting the final report on the webserver.
chdir $nfs . $bagatel;
print "change dir to: " . $nfs . $bagatel . "\n";
print "\n(Bagatel) Generating images from data...\n";
system("perl ./makegraph.pl");
