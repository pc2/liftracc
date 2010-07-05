#!/bin/bash
echo "Tuning cblas daxpy"
export LIFTRACC_USE_PLUGIN=f4a17438-80ed-4f9f-90f1-1728df8ea630
tune/tune_daxpy

echo "Tuning cublas daxpy"
export LIFTRACC_USE_PLUGIN=4241c224-99c9-4c44-979f-32c6ac5fc9a4
tune/tune_daxpy

echo "Tuning goto2 daxpy"
export LIFTRACC_USE_PLUGIN=829a1670-46b0-450e-9f85-3d6a65a9efcb
tune/tune_daxpy

echo "Tuning clearspeed daxpy"
export LIFTRACC_USE_PLUGIN=7bedd79d-62b6-4210-b221-98ebf540057a
tune/tune_daxpy

echo "Tuning atlas daxpy"
export LIFTRACC_USE_PLUGIN=95cd6e1c-9f7e-4628-a265-5f9e1fab6abd
tune/tune_daxpy

