
DDS Benchmark Environment (DBE) Scripts User Manual:

1. Installation
2. Running Benchmark.pl
3. Settings
4. Results
5. Termination
6. Automation



--------------------------------------------------------------------





1. Installation

  (not covered yet)



2. Running Benchmark.pl

  location: ~/scripts/benchmark.pl
  usage:

    ~/scripts/benchmark.pl [-i impl] [-minsize #] [-maxsize #]
             [-n netSettingsFile] [-q defaultQoSFile] [-type testType]
             [-primer numPrimerMessages] [-statsmessages numStatsMessages]
             [testSettingsFile] 

    There are lots of arguments you can include at the command line to
    customize tests to your liking, but the basic options you should know
    about are:

    [-i impl]  : this specifies the implementation that you'd like
                 to test

    [testfile] : this file contains test parameters to use. Any setting
                 defined here can be overridden using a command line arg.
                 For instance, if you want to test NDDS and TAO DDS and
                 you have a test file created that has all the settings that
                 you want, but it specifies impl=NDDS, you can get the
                 functionality you want by doing the following for TAO DDS.

                 ~/scripts/benchmark.pl -i TAO-DDS myTestFile.test

    [-minsize #] : specifies the minimum size of packet to test. This
                   is typically more useful in throughput tests than in others.

    [-maxsize #] : specifies the maximum size of packet to test. This
                   is typically more useful in throughput tests than in others.
               

3. Settings

  We have a system setup for isolating the three different types of settings
  files.

    Network Settings Files:  ~/DDS/settings/net/
    QoS Settings Files:      ~/DDS/settings/qos/
    Test Settings Files:     ~/DDS/settings/test/

  If you want to add a test file or network settings file, please place them
  in the appropriate directories.


  Settings File Layout:

    Each settings file consists of a sequence of keys and values paired
    together with '=' and separated from each other by newlines. Comments
    are allowed by using the '#' character. 

    impl=NDDS and IMPL=ndds are treated the same (case insensitive),
    although we'd recommend making everything as legible as possible.
    The exception is the 'net' and 'qos' values which will not be converted
    as they are actual directory locations. Obviously, if you have a
    settings file located at "/home/myaccount/Test.settings", we can't
    reach the file if we're trying to reach "/home/myaccount/test.settings"
    on a Linux box.
    
    EXAMPLE TEST SETTINGS FILE:


      # what is expected here:
      # impl - specifies implementation
      # type - type of benchmark: throughput is currently supported
      # minSize - minimum packet size
      # maxSize - maximum packet size

      #implementation
      #impl=TAO-DDS
      impl=NDDS

      type=throughput

      minSize=4
      maxSize=1024
      primer=100
      statsMessages=10000

      #QoS settings file
      qos=/export/home/tczar/DDS/settings/qos/defaults.txt

      #Network settings file
      net=/export/home/tczar/DDS/settings/net/blade30-34.settings


    Summary of file. The default qos settings are stored to be loaded from
    /export/home/tczar/DDS/settings/qos/defaults.txt. The network settings
    are loaded from /export/home/tczar/DDS/settings/net/blade30-34.settings.
    There are 100 primer messages and 10,000 actual messages where stats are
    logged. The packets will begin at 4 bytes and go up to 1024 bytes. The
    test will be run on NDDS and the type of test will test throughput.

                   
4. Results

  Results are stored in a special directory (~/DDS/results). If you're
  trying to find the results for a test you ran, you can find the specific
  results directory two ways.

    I. Check ~/DDS/results/tests.list for the test id. The tests.list file
       stores human readable information about each test that is run.
       Currently, it logs the test id, test type, minsize-maxsize, and
       the number of subscribers. This format is governed by the function
       "updateTestsListingFile" in ~/scripts/scripts.lib.
   II. Check the printout from your console. The test id should be printed
       to the screen in the first couple of lines, and it should be presented
       in a format that is very similar to the one in tests.list.

  If you have the test id, you can access your results by looking in:

    ~/DDS/results/#id                 where #id is the test id

  So, if you ran test id 103, you can find your results in:

    ~/DDS/results/103/


  What is actually stored in the directory?

    STDOUT and STDERR are logged for each publisher and subscriber. Also,
    stats files, settings for the entire test, parameters passed to each
    domain participant, etc. can all be found in this directory.

    STDOUT is logged to the extension *.log
    STDERR is logged to the extension *.err
    Settings for the entire tests are stored in settings.dat
    The implementation (if that's all you want) is stored in impl.dat
    Stats are logged to the extension *.stats
    Settings for each participant is logged to the extension *.settings
    Parameters passed to each start_sub/pub are stored in *.params


5. Termination


    If the test hangs indefinitely, or if you are running TAO DDS tests,
    you will probabaly want to make sure that all executables are shutdown
    before running your next tests.

    ~/scripts/terminate.pl is a script designed to kill any benchmark process
    running on blade30 - blade45. To kill all, simply run terminate.pl
    with no parameters. The script kills any process on the blades that is
    running under the username tczar and fits the filename of one of the
    test executables. Specifically, the terminate script kills all perl,
    publisher, and subscriber executables. It calls 'ospl stop' for Splice
    and kills the InfoRepo that is started by TAO-DDS.



    USAGE:

    ~/scripts/terminate.pl [-s signal] [-i impl] [-minsize #] [-maxsize #]
             [-n netSettingsFile] [-q defaultQoSFile] [-type testType]
             [-primer numPrimerMessages] [-statsmessages numStatsMessages]
             [testSettingsFile]

    PARAMETERS

    -s           specifies a signal to kill the processes with. If you want
                 to simulate a SEGV for instance, provide "-s 11"
    -i           specifies the implementation. eg. NDDS, TAO-DDS, and SPLICE.
    testSettingsFile      specifies the testSettingsFile which was used with
                          benchmark.pl to start the test.
    -n           specifies the network settings file.
    


6. Automation

Another script is provided to help run large numbers of different tests
with varied test settings. This scripts is automateRun.pl and it has the
following syntax:


  automatedRun.pl [-h] [-subs numSubs] [-unicast] [-multicast]
                         [-listener] [-wait] [-i impl]
  [-subs numSubs] specifies the number of subscribers to test.
  [-unicast] specifies to test only unicast.
  [-multicast] specifies to test only multicast.
  [-listener] specifies to test only listener based.
  [-wait] specifies to test only wait based.
  [-i impl] specifies the implementation to test.


Running this tool is only advised if the implementation to be tested is
stable and not prone to failure. If one of the tests fails, you will likely
need to first kill automatedRun.pl, then benchmark.pl, and then run
terminate.pl with the test settings you used on the still running test.
    
