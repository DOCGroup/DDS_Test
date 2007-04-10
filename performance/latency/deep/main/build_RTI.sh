echo "Building $1 with g++"
g++ -g -m32 -DRTI_UNIX -DRTI_LINUX -I$DEEP_HOME/actors -I$DEEP_HOME/scenario -I$DEEP_HOME/settingsParser -I$DEEP_HOME/readerWriter -I$DEEP_HOME/readerWriter/RTI -I$DEEP_HOME/vendorAbstraction/RTI -I$DEEP_HOME/readerWriter/RTI/generated -I$NDDSHOME/include -I$NDDSHOME/include/ndds ../obj/*.o ../obj/RTI/*.o -L$NDDSHOME/lib/i86Linux2.6gcc3.4.3 -L$XERCESCROOT/lib -lnddscppz -lnddscz -lnddscorez -lxerces-c  $1.cpp -o ../exec/RTI/$1

