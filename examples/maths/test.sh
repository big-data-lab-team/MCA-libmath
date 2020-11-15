#!/bin/bash

# Example of Running: 
#    ./test.sh ../../src/func_wrapping/libpreload.so ./func/bin/


if [ $# != 2 ]
then
echo "usage: $0 <shared_library.so> <func_bin>"
exit 1
fi

shared_lib=$1
func_bins=$2

export LD_PRELOAD=${shared_lib}
#export VFC_BACKENDS_SILENT_LOAD=False
rm -f sigd*
for p in 53;do
    #export VFC_BACKENDS="libinterflop_ieee.so --debug" #--precision-binary64 ${p} --mode mca
    export VFC_BACKENDS="libinterflop_mca.so -p ${p} -m mca"
    for fun in sin cos; do
        rm -f points
        for x in $(seq -50 1 50); do
            echo $x >> points
            rm -f tmp
            for i in `seq 20`; do
	        ${func_bins}/bin/${fun} $x >> tmp
            done
            ./compute_sigdig.py tmp ${fun}-${p}
        done
    done
done
#./plot.py points sigd
