
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#ifndef __USE_GNU
#define __USE_GNU
#endif
#include <dlfcn.h>

#include "liftracc.h"
#include "liftracc_logging.h"
#include "liftracc_profiling.h"

#include "cublas.h"

int main(int argc, char** argv)
{
#ifdef _LIFTRACC_PROFILING_
    for (int i=0; i<100; i++) {
        liftracc_function_timing_start(&(liftracc_profiling_data[MEASURING_ERROR]));
        liftracc_function_timing_stop(&(liftracc_profiling_data[MEASURING_ERROR]));
    }
#endif /* _LIFTRACC_PROFILING_  */
    unsigned int error_count = 0;

    const int max_runs = 10;
    const int max_dim = 1024; /* 16384; */
    const int max_entries = max_dim * max_dim;

#ifdef _LIFTRACC_PROFILING_
    profiling_data_t data[max_dim] = { };
#endif /* _LIFTRACC_PROFILING_  */

    double *dA = (double*) malloc( sizeof(double) * max_entries );
    double *dB = (double*) malloc( sizeof(double) * max_entries );

    srand(time(0));

    // init libraries
    if (cublasInit()==CUBLAS_STATUS_SUCCESS)
        INFO("cublasInit()");
    else
        ERROR("cublasInit() failed!");
    
    // benchmark
    int j,i;
   for (j=0;j<max_runs;j++) {
    for (i=0; i<max_entries; i++) dA[i] = (double)(rand()%500/100.0);
    for (i=0; i<max_entries; i++) dB[i] = (double)(rand()%500/100.0);
    for (i=2; i<max_dim; i++) {
#ifdef _LIFTRACC_PROFILING_
        liftracc_function_timing_start(&(data[i]));
#endif /* _LIFTRACC_PROFILING_ */
        double* dev_a;
        double* dev_b;

        int err;
        if ((err=cublasAlloc(i, sizeof(*dA), (void**)&dev_a))!=CUBLAS_STATUS_SUCCESS)
            ERROR("cublasAlloc ERROR %d", err);
        if ((err=cublasAlloc(i, sizeof(*dB), (void**)&dev_b))!=CUBLAS_STATUS_SUCCESS)
            ERROR("cublasAlloc ERROR %d", err);

        cublasSetVector(i, sizeof(*dA), dA, 1, dev_a, 1);
        cublasSetVector(i, sizeof(*dB), dB, 1, dev_b, 1);

        double ret = cublasDdot(i, dev_a, 1, dev_b, 1);
        
        if (cublasGetError()!=CUBLAS_STATUS_SUCCESS)
            ERROR("cublas ERROR");

        cublasFree(dev_a);
        cublasFree(dev_b);
#ifdef _LIFTRACC_PROFILING_        
        liftracc_function_timing_stop(&(data[i]));
#endif /* _LIFTRACC_PROFILING_ */
        MSG("RET: %f", ret);
        MSG("%d.run", i);
    }
   }

     if (cublasShutdown()==CUBLAS_STATUS_SUCCESS)
        MSG("cublasShutdown()");
     else
        ERROR("cublasShutdown() failed!");

#ifdef _LIFTRACC_PROFILING_        
    print_profiling_data("cublas_RESULT", &(data[0]), 0, max_dim);
#endif /* _LIFTRACC_PROFILING_ */

    return error_count;
}

