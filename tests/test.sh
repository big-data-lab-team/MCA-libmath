#!/bin/bash

export VFC_BACKENDS="libinterflop_mca.so"
export LD_PRELOAD=$PWD/../libmath.so

# Compile program normally with gcc
#ln -s /usr/bin/gcc-4.7 /usr/bin/gcc
gcc test.c -o test -lm

# Get several samples of the function
rm -f outputs
./test 1.0 >> outputs

# Compute standard deviation
res=$(cat outputs | awk '{delta = $1 - avg; avg += delta / NR; mean2 += delta * ($1 - avg); }
END { print sqrt(mean2 / NR); }')

if [[ ${res} == 0 ]]; then
    echo "Failed: res=${res}"
else
    echo "Successed: res=${res}"
fi

