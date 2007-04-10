echo "Building $1 with g++3.2.3"
g++3.2.3 -g -DDDS_OpenFusion_1_4_1 -I$DEEP_HOME/readerWriter -I$DEEP_HOME/scenario -I$DEEP_HOME/readerWriter/OpenSplice/generated -I$DEEP_HOME/vendorAbstraction/OpenSplice -I$OSPL_HOME/include/dcps/C++/SACPP -c $1.cpp -o ../../../obj/OpenSplice/$1.o
