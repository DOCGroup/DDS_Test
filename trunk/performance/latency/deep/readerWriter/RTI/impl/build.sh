echo "Building $1 with g++"
g++ -g -m32 -DRTI_UNIX -DRTI_LINUX  -I../.. -I$DEEP_HOME/scenario -I$DEEP_HOME/readerWriter/RTI/generated -I$DEEP_HOME/vendorAbstraction/RTI -I$NDDSHOME/include -I$NDDSHOME/include/ndds  -c $1.cpp -o ../../../obj/RTI/$1.o

