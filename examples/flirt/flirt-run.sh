#!/bin/bash
#. /etc/fsl/5.0/fsl.sh


export LD_PRELOAD=../../src/func_wrapping/libpreload.so

for p in 14 #12 10 8 6 4 2 0
do
  export VFC_BACKENDS="libinterflop_mca.so --precision-binary64=${p} --mode mca"
  for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
  do
    ${FSLDIR}/bin/flirt -in input.nii.gz -ref MNI152_T1_1mm.nii.gz -o test2-flirt-${i}-p${p}.nii.gz -omat test2-flirt-${i}-p${p}.nii.gz
  done
done

