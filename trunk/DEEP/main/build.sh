#! /bin/sh

if [ $1 == 'RTI' ]
then
  echo "Building $2 with g++"
  g++ -g -m32 -DRTI_UNIX -DRTI_LINUX -I$DEEP_HOME/actors -I$DEEP_HOME/scenario -I$DEEP_HOME/settingsParser -I$DEEP_HOME/readerWriter -I$DEEP_HOME/readerWriter/RTI -I$DEEP_HOME/vendorAbstraction/RTI -I$DEEP_HOME/readerWriter/RTI/generated -I$NDDSHOME/include -I$NDDSHOME/include/ndds ../obj/*.o ../obj/RTI/*.o -L$NDDSHOME/lib/i86Linux2.6gcc3.4.3 -L$XERCESCROOT/lib -lnddscppz -lnddscz -lnddscorez -lxerces-c  $2.cpp -o ../exec/RTI/$2
elif [ $1 == 'OpenSplice' ]
then
  echo "Building $2 with g++3.2.3"
  g++3.2.3 -g -I$DEEP_HOME/actors -I$DEEP_HOME/scenario -I$DEEP_HOME/settingsParser -I$DEEP_HOME/readerWriter -I$DEEP_HOME/readerWriter/OpenSplice -I$DEEP_HOME/vendorAbstraction/OpenSplice -I$DEEP_HOME/readerWriter/OpenSplice/generated -I$OSPL_HOME/include/dcps/C++/SACPP ../obj/*.o ../obj/OpenSplice/*.o -L$OSPL_HOME/lib -L$XERCESCROOT/lib -ldcpssacpp -lxerces-c  $2.cpp -o ../exec/OpenSplice/$2
else
 echo "$1 is NOT a valid vendor name, compilation not successful!"
fi
