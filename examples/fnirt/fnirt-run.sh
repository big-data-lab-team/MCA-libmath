#!/bin/bash
#. /etc/fsl/5.0/fsl.sh


export LD_PRELOAD=../../src/func_wrapping/libpreload.so

for p in 14 #12 10 8 6 4 2 0
do
  export VFC_BACKENDS="libinterflop_mca.so --precision-binary64=${p} --mode mca"
  for i in 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15
  do
    ${FSLDIR}/bin/fnirt --in=T2w/T2w_acpc --ref=/usr/local/src/projects/Pipelines/global/templates/MNI152_T2_2mm.nii.gz --aff=T2w/BrainExtraction_FNIRTbased/roughlin.mat --refmask=/usr/local/src/projects/Pipelines/global/templates/MNI152_T1_2mm_brain_mask_dil.nii.gz --fout=T2w/BrainExtraction_FNIRTbased/str2standard.nii.gz --jout=T2w/BrainExtraction_FNIRTbased/NonlinearRegJacobians.nii.gz --refout=T2w/BrainExtraction_FNIRTbased/IntensityModulatedT1.nii.gz --iout=T2w/BrainExtraction_FNIRTbased/T2w_acpc_to_MNI_nonlin-i${i}.nii.gz --logout=T2w/BrainExtraction_FNIRTbased/NonlinearReg.txt --intout=T2w/BrainExtraction_FNIRTbased/NonlinearIntensities.nii.gz --cout=T2w/BrainExtraction_FNIRTbased/NonlinearReg.nii.gz --config=/usr/local/src/projects/Pipelines/global/config/T1_2_MNI152_2mm.cnf
    
  done
done

