#! /bin/sh

if [ $1 == 'RTI' ]
then
 echo "Building $2 with g++"
# export XERCESCROOT=/export/home/tczar/xerces
 g++ -g -I.. -I$XERCESCROOT/include -c $2.cpp -o ../../obj/$2.o
# unset XERCESCROOT
elif [ $1 == 'OpenSplice' ]
then
 echo "Building $2 with g++3.2.3"
# export XERCESCROOT=/export/home/tczar/xerces-c-src_2_5_0
 g++3.2.3 -g -I.. -I$XERCESCROOT/include -c $2.cpp -o ../../obj/$2.o
# unset XERCESCROOT
else
 echo "$1 is NOT a valid vendor name, compilation not successful!"
fi


