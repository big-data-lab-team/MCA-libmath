#!/bin/bash

export VFC_BACKENDS="libinterflop_mca.so --mode=pb --precision-binary64=52 --precision-binary32=23"
export LD_PRELOAD=$PWD/../libmath.so

declare -A signature_a
declare -A type_a
signature_a=([univar]="univariate" [bivar]="bivariate" [lgamma_r]="lgamma_r" [sincos]="sincos")
type_a=([float]="binary32" [double]="binary64")

export VFC_BACKENDS_LOGGER="False"
export VFC_BACKENDS_SILENT_LOAD="True"

function assert_noise() {
    ./check_result.py outputs
    if [[ $? != 0 ]]; then
        echo "Failed"
        exit 1
    else
        echo "Successed"
    fi
}

function check_compilation() {
    if [[ $? != 0 ]]; then
        echo "Compilation failed"
        exit 1
    fi
}

function compile() {
    TYPE=$1
    SIG=$2
    FUNCTION=$3
    gcc test.c -lm -DREAL=$TYPE -D$SIG -DFUNCTION=$FUNCTION -o test
    check_compilation
}

function run() {
    LD_PRELOAD=$LD_PRELOAD ./test $* > outputs
}

IFS=" "
for TYPE in "${!type_a[@]}"; do
    while read -r FUNCTION POINT ; do
        echo "Evalue $FUNCTION on ${POINT}"
        compile $TYPE UNIVAR $FUNCTION
        run $POINT
        assert_noise
    done < math-functions-${type_a[$TYPE]}-${signature_a[univar]}.txt
done

IFS=" "
for TYPE in "${!type_a[@]}"; do
    while read -r FUNCTION POINT1 POINT2 ; do
        echo "Evalue $FUNCTION on ${POINT}"
        compile $TYPE BIVAR $FUNCTION
        run $POINT1 $POINT2
        assert_noise
    done < math-functions-${type_a[$TYPE]}-${signature_a[bivar]}.txt
done

# for TYPE in "${!type_a[@]}"; do
#     while read -r FUNCTION ; do
#         gcc test.c -DREAL=$TYPE -DBIVAR -DFUNCTION=$FUNCTION -o test
#         ./test 0.1 0.1 > outputs
#         res=$(std_1)
#         assert_noise $res
#         res=$(std_2)
#         assert_noise $res
#     done < math-functions-${type_a[$TYPE]}-${signature[BIVAR]}.txt
# done