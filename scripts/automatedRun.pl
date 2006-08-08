#!/usr/bin/perl

$command = "$DBE_SCRIPTS/benchmark.pl";
$terminate = "$DBE_SCRIPTS/terminate.pl";

@subs = ("4","8","12");
@implementations = ("TAO-DDS","NDDS","SPLICE");
@notifications = ("listener","wait");
@transports = ("unicast","multicast");

# implementations

$i = 0;
$nodes = 6;

$notify = 0;
$transport = 0;

$testprefix = "~/DDS/settings/test/official_";

$NUM_IMPL = @implementations;

# check args


if( @ARGV > 0 )
{
  if( @ARGV[0] eq "-h" )
  {
    print "\n" .
      "Usage:\n\n" .
      "  automatedRun.pl [-h] [-subs numSubs] [-unicast] [-multicast]
                         [-listener] [-wait]\n";
    print "  [-subs numSubs] specifies the number of subscribers to test.\n";
    print "  [-unicast] specifies to test only unicast.\n";
    print "  [-multicast] specifies to test only multicast.\n";
    print "  [-listener] specifies to test only listener based.\n";
    print "  [-wait] specifies to test only wait based.\n";
    print "\n";
    exit(0);
  }
}



while( @ARGV > 0 )
{
  $temp = shift(@ARGV);
  if( $temp eq "-i" )
  {
    $impl = uc(shift(@ARGV));

    if( $impl eq "TAO" || $impl eq "TAODDS" || $impl eq "TAO_DDS" )
    {
      $impl = "TAO-DDS";
    }
    elsif( $impl eq "OPENSPLICE" || $impl eq "OPEN-SPLICE" )
    {
      $impl = "SPLICE";
    }

    @implementations = ($impl);
  }
  elsif( $temp eq "-subs" )
  {
    @subs = (shift(@ARGV));
  }
  elsif( $temp eq "-unicast" || $temp eq "-broadcast" )
  {
    @transports = ("unicast");
  }
  elsif( $temp eq "-multicast" )
  {
    @transports = ("multicast");
  }
  elsif( $temp eq "-listener" )
  {
    @notifications = ("listener");
  }
  elsif( $temp eq "-wait" )
  {
    @notifications = ("wait");
  }
}

# first test - Unicast/broadcast

for( $i = 0; $i < @implementations; $i++ )
{
  $impl = @implementations[$i];

  print "impl == $impl\n";

  $subs_i = 0;
  $nodes = @subs[$subs_i] + 2;

  for( ; $subs_i < @subs; ++$subs_i, $nodes = @subs[$subs_i] + 2 )
  {
  for( $transport = 0; $transport < @transports; $transport++ )
  {
    for( $notify = 0; $notify < @notifications; $notify++ )
    {
      $testfile = $testprefix . @transports[$transport] . '_';
      $testfile .= @notifications[$notify] . '.test';

      $sub = @subs[$subs_i];

#      print "$command -i $impl -nodes $nodes -subs $subs $testfile\n";
      system("$command -i $impl -nodes $nodes -subs $sub $testfile");
      system("$terminate -i $impl -nodes $nodes -subs $sub $testfile");

      if( $impl eq "TAO-DDS" )
      {
        $notify = @notifications + 1;
      }
    }
    if( $impl eq "TAO-DDS" )
    {
      $transport = @transports + 1;
    }
  }
  }
}
