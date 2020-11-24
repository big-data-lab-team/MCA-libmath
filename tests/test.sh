#!/bin/bash

export VFC_BACKENDS="libinterflop_mca.so"

# Compile program normally with gcc
gcc test.c -o test -lm

# Get several samples of the function
rm -f outputs
for i in $(seq 1 30); do
    ./test 1.0 >> outputs
done

# Compute standard deviation
cat outputs | awk '{delta = $1 - avg; avg += delta / NR; mean2 += delta * ($1 - avg); } 
                   END { print sqrt(mean2 / NR); }'

