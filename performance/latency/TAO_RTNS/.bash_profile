# .bash_profile

# Get the aliases and functions
if [ -f ~/.bashrc ]; then
	. ~/.bashrc
fi

# User specific environment and startup programs

CVS_RSH=ssh
CVSROOT=cvs.doc.wustl.edu:/project/cvs-repository
#CVSROOT=/project/tangotmp/mxiong/cvshome
ACE_ROOT=/project/tangotmp/mxiong/ACE_wrappers
#ACE_ROOT=/project/tangotmp/mxiong/SPLICE/SPLICE_TAO
MY_ROOT=/project/tangotmp/mxiong
TAO_ROOT=$ACE_ROOT/TAO
DDS_ROOT=$TAO_ROOT/DDS
#TAO_ROOT=/project/tangotmp/mxiong/SPLICE/SPLICE_TAO
CIAO_ROOT=$TAO_ROOT/CIAO
ZIPARCHIVEROOT=~/ziplib
LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$ACE_ROOT/ace:$ACE_ROOT/lib:$ZIPARCHIVEROOT/lib:$ZIPARCHIVEROOT/include:$DDS_ROOT/lib
JAVA_HOME=/project/tangotmp/mxiong/SUNWappserver/jdk
J2EE_HOME=/project/tangotmp/mxiong/SUNWappserver
PATH=$PATH:$HOME/bin:$ACE_ROOT/bin:$TAO_ROOT/bin:$DDS_ROOT/bin
PATH=$PATH:$TAO_ROOT/TAO_IDL:/project/tangotmp/mxiong/SUNWappserver/jdk/bin:/project/tangotmp/mxiong/SUNWappserver/bin

export PATH
export CVS_RSH
export CVSROOT
export ACE_ROOT
export TAO_ROOT
export DDS_ROOT
export CIAO_ROOT
export ZIPARCHIVEROOT
export LD_LIBRARY_PATH
export MY_ROOT
unset USERNAME

alias cddance="cd $CIAO_ROOT/DAnCE"
alias cdace="cd $ACE_ROOT"
alias cdtao="cd $TAO_ROOT"
alias cdmycvs="cd /project/tangotmp/mxiong/cvshome"
alias cd258="cd /project/tangotmp/mxiong/course/cs258"
alias cdtango="cd /project/tangotmp/mxiong"
alias cdquoter="cd $CIAO_ROOT/DAnCE/examples/Quoter"
alias cdsplice="cd $MY_ROOT/splice-dds"
alias cddcps="cd /project/tangotmp/mxiong/splice-dds/x86.linux2.6/examples/dcps/C++/TAO"
alias totango="ssh tango.dre.vanderbilt.edu"
alias tojms="cd /project/tangotmp/mxiong/SUNWappserver/j2eetutorial14/examples/jms/simple"
alias totaodds="cd /project/tangotmp/mxiong/ACE_wrappers/TAO/DDS/examples/NewCodes"