g++ -g -I$DEEP_HOME/actors -I$DEEP_HOME/scenario -I$DEEP_HOME/settingsParser -I$DEEP_HOME/readerWriter -I$DEEP_HOME/vendorAbstraction/OpenSplice -I$DEEP_HOME/readerWriter/generated -I$OSPL_HOME/include/dcps/C++/SACPP ../obj/*.o -L$OSPL_HOME/lib -L$XERCES_HOME/lib -ldcpssacpp -lxerces-c  $1.cpp -o ../exec/$1

