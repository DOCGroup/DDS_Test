#!/usr/bin/perl


require "$DBE_SCRIPTS/scripts.lib";


if( @ARGV > 0 )
{
  if( @ARGV[0] eq "-h" )
  {
    print "\n" .
      "Usage:\n\n" .
      "  testCopy.pl [-h] destinationDirectory testid1 testid2 ... testidN
             
  [-h] print usage information for this script.
  destinationDirectory - target directory for copies of the test results.
  testid1 ... testidN - test result directories to copy.\n";

    print "
    example:\n
     testCopy.pl ~/resultsBackup 1 10 17 43 29\n
     The preceding example would copy tests 1, 10, 17, 43, and 29 to
     ~/resultsBackup/1, ~/resultsBackup/10, etc.\n\n";
    exit(0);
  }
}

$destination = shift(@ARGV);
@listings = &getTestListing("$DBE_ROOT/results/tests.list");

while( @ARGV > 0 )
{
  $testid = shift(@ARGV);

  $description = &getDescriptionFromTestListing($testid,@listings);

  print "\nCopying $testid from $DBE_ROOT/results to $destination...";
  system("cp -r $DBE_ROOT/results/$testid $destination");
  print "Done.\n";

  print "Appending test information for $testid to test listing file...";
  &addSimpleTextToTestListing($destination . '/tests.list',$testid,
                              $description);  
  print "Done.\n";
}

