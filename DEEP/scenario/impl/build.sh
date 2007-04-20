#! /bin/sh

if [ $1 == 'RTI' ]
then
 echo "Building $2 with g++"
 g++ -g -I.. -I$DEEP_HOME/settingsParser -c $2.cpp -o ../../obj/$2.o
elif [ $1 == 'OpenSplice' ]
then
 echo "Building $2 with g++3.2.3"
 g++3.2.3 -g -I.. -I$DEEP_HOME/settingsParser -c $2.cpp -o ../../obj/$2.o
else
 echo "$1 is NOT a valid vendor name, compilation not successful!"
fi
