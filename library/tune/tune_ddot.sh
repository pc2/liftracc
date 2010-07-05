#!/bin/bash
echo "Tuning cblas ddot"
export LIFTRACC_USE_PLUGIN=f4a17438-80ed-4f9f-90f1-1728df8ea630
tune/tune_ddot

echo "Tuning cublas ddot"
export LIFTRACC_USE_PLUGIN=4241c224-99c9-4c44-979f-32c6ac5fc9a4
tune/tune_ddot

echo "Tuning goto2 ddot"
export LIFTRACC_USE_PLUGIN=829a1670-46b0-450e-9f85-3d6a65a9efcb
tune/tune_ddot

echo "Tuning clearspeed ddot"
export LIFTRACC_USE_PLUGIN=7bedd79d-62b6-4210-b221-98ebf540057a
tune/tune_ddot

echo "Tuning atlas ddot"
export LIFTRACC_USE_PLUGIN=95cd6e1c-9f7e-4628-a265-5f9e1fab6abd
tune/tune_ddot

