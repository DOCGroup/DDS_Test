#!usr/bin/perl

use IO::File;

my $output = "subs_range.stats.0";
my ($path, @datalist) = @ARGV;

chdir $path
  or die "$path does not exist.\n";

print "path: " . $path . "\n";

$filehandle = new IO::File;

print "Collecting data...\n";
#read files one by one and push the throughput
#samples to the hash of arrays
foreach $a_file (@datalist) {
  $filehandle->open ("<" . $a_file);

  until ($filehandle->eof) {
    #read 2 lines at a time
    #1st line is the size, 2nd line is the throughput sample.
    $size = $filehandle->getline;
    chomp $size;
    $sample = $filehandle->getline;
    chomp $sample;
    if ($sample ne "") {
      push (@{$alldata{$size}}, $sample);  
    }
  }

  $filehandle->close;
}

#write to output file in Bagatel's format
$filehandle->open (">" . $output);

$filehandle->print ("[BENCHMARK]\t[STR]\tVersion\tNo particular version\t[STR]\tSuite\tNo particular suite\t\n");
$filehandle->print ("[CONFIGURATION]\t[1]\tScale\t1000000\t[1]\tGranularity\t1\t\n");

foreach $size (sort {$a <=> $b} keys %alldata) 
{
  my $min = $alldata{$size}[0];
  my $max = $alldata{$size}[0];
  my $sum = 0;
  my $num_samples = @{$alldata{$size}};

  for $i ( 0 .. ($num_samples - 1) ) {
    if ($alldata{$size}[$i] < $min)
    {
      $min = $alldata{$size}[$i];
    }
    if ($alldata{$size}[$i] > $max)
    {
      $max = $alldata{$size}[$i];
    }
    $sum += $alldata{$size}[$i];
  }
 
  my $avg = $sum / $num_samples;
  
  $filehandle->print ("[MEASUREMENT]\t[1]\tSamples\t1\t[1]\tBytes\t$size\t\n");
  $filehandle->print ("[SAMPLE]\t[3]\tThroughputAverage\t$min\t$avg\t$max\t[$num_samples]\tThroughputSolo\t");

  foreach $sample (@{$alldata{$size}}) {
    $filehandle->print ($sample . "\t");
  }    
  $filehandle->print ("\n");
}

$filehandle->close;
print "$output successfully generated.\n"
