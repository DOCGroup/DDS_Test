#! /bin/sh

if [ $1 == 'RTI' ]
then
 echo "Building $2 with g++"
 g++ -g -m32 -DRTI_UNIX -DRTI_LINUX  -I.. -I$DEEP_HOME/scenario -I$DEEP_HOME/readerWriter/generated/RTI -I$DEEP_HOME/vendorAbstraction/RTI -I$NDDSHOME/include -I$NDDSHOME/include/ndds  -c $2.cpp -o ../../obj/RTI/$2.o
elif [ $1 == 'OpenSplice' ]
then
 echo "Building $2 with g++3.2.3"
 g++3.2.3 -g -I.. -I$DEEP_HOME/scenario -I$DEEP_HOME/readerWriter/generated/OpenSplice -I$DEEP_HOME/vendorAbstraction/OpenSplice -I$OSPL_HOME/include/dcps/C++/SACPP -c $2.cpp -o ../../obj/OpenSplice/$2.o
else
 echo "$1 is NOT a valid vendor name, compilation not successful!"
fi
