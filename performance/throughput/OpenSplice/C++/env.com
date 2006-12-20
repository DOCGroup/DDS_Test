ACE_ROOT=/export/home/tczar/TAO_Splice
TAO_ROOT=/export/home/tczar/TAO_Splice
LD_LIBRARY_PATH=$TAO_ROOT/lib:/usr/local/lib:$LD_LIBRARY_PATH
PATH=$TAO_ROOT/bin:/usr/local/bin:$PATH

export ACE_ROOT
export TAO_ROOT
export LD_LIBRARY_PATH
export PATH

