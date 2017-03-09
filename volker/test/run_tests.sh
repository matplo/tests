#!/bin/bash

function abspath()
{
  case "${1}" in
    [./]*)
    echo "$(cd ${1%/*}; pwd)/${1##*/}"
    ;;
    *)
    echo "${PWD}/${1}"
    ;;
  esac
}

THISFILE=`abspath $BASH_SOURCE`
XDIR=`dirname $THISFILE`
if [ -L ${THISFILE} ];
then
    target=`readlink $THISFILE`
    XDIR=`dirname $target`
fi

THISDIR=$XDIR

export VOLKERDIR=`dirname $THISDIR`
echo "[i] we sit in..." $VOLKERDIR

ldpath=":$LD_LIBRARY_PATH"
[ -z $LD_LIBRARY_PATH ] && ldpath=''
dyldpath=":$LD_LIBRARY_PATH"
[ -z $DYLD_LIBRARY_PATH ] && dyldpath=''

export LD_LIBRARY_PATH=$VOLKERDIR/lib$ldpath
export DYLD_LIBRARY_PATH=$VOLKERDIR/lib$dyldpath

export PATH=$VOLKERDIR/bin:$PATH

echo "... root ..."
root -l test.C -q
echo
echo "... python ..."
./test.py
echo

if [ -z $ROOTSYS ];
then

	"echo Need to set ROOTSYS here... trying something with module tool..."
	module load root
else
    export LD_LIBRARY_PATH=$ROOTSYS/lib:$LD_LIBRARY_PATH
    export DYLD_LIBRARY_PATH=$ROOTSYS/lib:$DYLD_LIBRARY_PATH
fi

if [ ! -z $ROOTSYS ];
then
	echo "... exec ..."
	Volker
    echo
fi

$THISDIR/draw.py

