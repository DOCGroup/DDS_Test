echo "Building $1 with g++3.2.3"
g++3.2.3 -g -I$DEEP_HOME/actors -I$DEEP_HOME/scenario -I$DEEP_HOME/settingsParser -I$DEEP_HOME/readerWriter -I$DEEP_HOME/readerWriter/OpenSplice -I$DEEP_HOME/vendorAbstraction/OpenSplice -I$DEEP_HOME/readerWriter/OpenSplice/generated -I$OSPL_HOME/include/dcps/C++/SACPP ../obj/*.o ../obj/OpenSplice/*.o -L$OSPL_HOME/lib -L$XERCESCROOT/lib -ldcpssacpp -lxerces-c  $1.cpp -o ../exec/OpenSplice/$1

