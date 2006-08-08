#!/bin/bash


LD_LIBRARY_PATH=/home/tczar/OpenSplice/V2.0beta/x86.linux2.6/lib

echo LD_LIBRARY_PATH is now:
echo $LD_LIBRARY_PATH

ospl stop

killall -s 9 -v durability
killall -s 9 -v spliced
killall -s 9 -v networking
#killall -s 9 -v subscriber
#killall -s 9 -v publisher
