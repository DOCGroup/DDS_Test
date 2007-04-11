echo "Compiling IDL with Splice IDL compiler"
idlpp -I../ -I$OSPL_HOME/include/dcps/C++/SACPP -l cpp -S ../deepTypes.idl
