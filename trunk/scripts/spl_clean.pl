#!/usr/bin/perl

# rm splice's coredumps & stop all ospl services on blade 30-45

for( $i = 29; $i <= 45; $i++ )
{
  print "blade$i: clean coredumps, stop all ospl services.\n";
  #system("ssh tczar\@blade$i.isislab.vanderbilt.edu sudo sh /export/home/tczar/scripts/spl_clean_each.sh");

  system("ssh tczar\@blade$i.isislab.vanderbilt.edu sudo rm /home/tczar/DDS/performance/throughput/Splice/core*");
  system("ssh tczar\@blade$i.isislab.vanderbilt.edu sudo rm /home/tczar/DDS/performance/throughput/Splice/ospl-*");
  system("ssh tczar\@blade$i.isislab.vanderbilt.edu 'ospl stop'");
  system("ssh tczar\@blade$i.isislab.vanderbilt.edu 'sudo killall -s 9 -v durability'");
  system("ssh tczar\@blade$i.isislab.vanderbilt.edu 'sudo killall -s 9 -v spliced'");
  system("ssh tczar\@blade$i.isislab.vanderbilt.edu 'sudo killall -s 9 -v networking'");
  #kill subscribers' & publishers' process using terminate.pl instead
  #system("ssh tczar\@blade$i.isislab.vanderbilt.edu 'killall -s 9 -v publisher'");
  #system("ssh tczar\@blade$i.isislab.vanderbilt.edu 'killall -s 9 -v subscriber'");
}

