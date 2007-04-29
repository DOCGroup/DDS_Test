#!/bin/sh
#
#
# Author: Ming Xiong
# Description: Conduct build/test for RT-DEEP and update the scoreboard
#

INDEX_FILE=/export/home/tczar/DDS/DEEP/autobuild/index.html
RTI_RESULT_FILE=/export/home/tczar/DDS/DEEP/autobuild/RTI_BUILD_RESULT
OpenSplice_RESULT_FILE=/export/home/tczar/DDS/DEEP/autobuild/OpenSplice_BUILD_RESULT
MPC_RESULT_FILE=/export/home/tczar/DDS/DEEP/autobuild/MPC_BUILD_RESULT
RTI_TEST_RESULT_FILE=/export/home/tczar/DDS/DEEP/autobuild/RTI_TEST_RESULT
OpenSplice_TEST_RESULT_FILE=/export/home/tczar/DDS/DEEP/autobuild/OpenSplice_TEST_RESULT

cd /export/home/tczar/DDS/DEEP
. /export/home/tczar/.bashrc

echo "Start updating the scoreboard.."
echo "step 1: Updating current working copy.."
(svn up 1>/dev/null)

echo "step 2: Building RTI using build_RTI.sh.."
(
echo "Last updated: `date -u`" > $RTI_RESULT_FILE
sh ./build_RTI.sh 1>>$RTI_RESULT_FILE 2>&1
)

echo "step 3: Building OpenSplice using build_OpenSplice.sh.."
(
echo "Last updated: `date -u`" >$OpenSplice_RESULT_FILE
sh ./build_OpenSplice.sh 1>>$OpenSplice_RESULT_FILE 2>&1
)

(
echo "Last updated: `date -u`" > $MPC_RESULT_FILE

echo "step 4: (Re)Generating makefile using MPC.."
$MPC_ROOT/mwc.pl -type make DEEP.mwc 1>>$MPC_RESULT_FILE 2>&1

echo "step 5: Building RT-DEEP using makefile.."
make 1>>$MPC_RESULT_FILE 2>&1
)

echo "step 6: Running RTI 1-to-1 intranode test.."
(
echo "Last updated: `date -u`" > $RTI_TEST_RESULT_FILE
echo "1 to 1 intranode latency test (run.sh) run at `hostname`" >> $RTI_TEST_RESULT_FILE
cd $DEEP_HOME/exec/RTI
if [ -e "OneSink" ];then
  rm OneSink
fi
sh ./run.sh 1>>$RTI_TEST_RESULT_FILE 2>&1
sleep 5 # Wait for result file to be written
if [ -e "OneSink" ];then
  cat OneSink >> $RTI_TEST_RESULT_FILE
fi
)

echo "step 7: Running OpenSplice 1-to-1 intranode test.."

echo "step 8: Updating WWW repository.."


echo "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\">" > $INDEX_FILE
echo "<html><head><title>RT-DEEP Scoreboard</title>" >> $INDEX_FILE



echo "<link rel=\"alternate\" title=\"Scoreboard RSS\" href=\"http://www.dre.vanderbilt.edu/scoreboard/ciao.rss\" type=\"application/rss+xml\"></head><body bgcolor=\"white\">" >> $INDEX_FILE
echo " <center><h1>RT-DEEP Scoreboard</h1></center>" >> $INDEX_FILE
echo "<hr>" >> $INDEX_FILE
echo "This page contains RT-DEEP scoreboard statistics. It shows the latest build/test results of RT-DEEP applications.For an overview of RT-DEEP, please see <a href="http://www.dre.vanderbilt.edu/DDS/html/deep.html">here</a>" >> $INDEX_FILE
echo "<hr>" >> $INDEX_FILE

echo "<h2><a name=\"Linux\">Linux</a></h2>" >> $INDEX_FILE
echo "<table border=\"1\">" >> $INDEX_FILE
echo "<tbody><tr>" >> $INDEX_FILE
echo "<th>Build Name</th><th>Config</th><th>Compile</th><th>Tests</th><th>Graph Results</th>" >> $INDEX_FILE
echo "</tr>" >> $INDEX_FILE

echo "<tr><td>RTI 4.1e</td><td>build_RTI.sh </td><td bgcolor=\"lime\">[<a href=\"http://www.dre.vanderbilt.edu/DDS/html/BUILD/RTI_BUILD_RESULT\">Full</a>] </td><td bgcolor=\"lime\">[<a href=\"http://www.dre.vanderbilt.edu/DDS/html/BUILD/RTI_TEST_RESULT\">Full</a>]</td><td bgcolor=\"white\">N/A</td></tr>" >> $INDEX_FILE
echo "<tr><td>OpenSplice 2.2.5b02</td><td>build_OpenSplice.sh </td><td bgcolor=\"lime\">[<a href=\"http://www.dre.vanderbilt.edu/DDS/html/BUILD/OpenSplice_BUILD_RESULT\">Full</a>] </td><td bgcolor=\"white\">N/A</td><td bgcolor=\"white\">N/A</td></tr>" >> $INDEX_FILE
echo "<tr><td>MPC Build</td><td>DEEP.mwc </td><td bgcolor=\"lime\">[<a href=\"http://www.dre.vanderbilt.edu/DDS/html/BUILD/MPC_BUILD_RESULT\">Full</a>] </td><td bgcolor=\"white\">N/A</td><td bgcolor=\"white\">N/A</td></tr>" >> $INDEX_FILE
echo "</tbody></table>" >> $INDEX_FILE

echo "<br>Last built and test at `date -u`<br>" >> $INDEX_FILE

echo "</body></html>" >> $INDEX_FILE


(cp -f $RTI_RESULT_FILE /home/tczar/WWW/trunk/DDS/html/BUILD/RTI_BUILD_RESULT)
(cp -f $OpenSplice_RESULT_FILE /home/tczar/WWW/trunk/DDS/html/BUILD/OpenSplice_BUILD_RESULT)
(cp -f $MPC_RESULT_FILE /home/tczar/WWW/trunk/DDS/html/BUILD/MPC_BUILD_RESULT)
(cp -f $RTI_TEST_RESULT_FILE /home/tczar/WWW/trunk/DDS/html/BUILD/RTI_TEST_RESULT)

(cp -f $INDEX_FILE /home/tczar/WWW/trunk/DDS/scoreboard/index.html)

(cd /home/tczar/WWW/trunk/DDS/html/BUILD
svn commit -m "update build results file" 1>/dev/null)

(cd /home/tczar/WWW/trunk/DDS/scoreboard
svn commit -m "update scoreboard index" 1>/dev/null)


echo "Update is complete!!"
echo "Note: Check out scoreboard update at  http://www.dre.vanderbilt.edu/DDS/html/deep.html" 
