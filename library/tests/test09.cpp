
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
    for (int c=0; c<100; c++) {
        liftracc_function_timing_start(&(liftracc_profiling_data[MEASURING_ERROR]));
        liftracc_function_timing_stop(&(liftracc_profiling_data[MEASURING_ERROR]));
    }
#endif /* _LIFTRACC_PROFILING_  */
    unsigned int error_count = 0;

    const int max_runs = 10;
    const int max_dim = 1024;
    const int max_entries = max_dim * max_dim;

#ifdef _LIFTRACC_PROFILING_
    profiling_data_t data[max_dim] = { };
#endif /* _LIFTRACC_PROFILING_  */

    double *dA = (double*) malloc( sizeof(double) * max_entries );
    double *dB = (double*) malloc( sizeof(double) * max_entries );
    double *dC = (double*) malloc( sizeof(double) * max_entries );
    double *dM = (double*) malloc( sizeof(double) * max_entries );

    double dAlpha = 1.3;
    double dBeta  = 3.7;

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
    for (i=0; i<max_entries; i++) dM[i] = (double)(rand()%500/100.0);
    memcpy(dC, dM, max_entries);
    for (i=2; i<max_dim; i++) {
#ifdef _LIFTRACC_PROFILING_
        liftracc_function_timing_start(&(data[i]));
#endif /* _LIFTRACC_PROFILING_ */
        double* dev_a;
        double* dev_b;
        double* dev_c;
        
        int err;
        if ((err=cublasAlloc(i*i, sizeof(*dA), (void**)&dev_a))!=CUBLAS_STATUS_SUCCESS)
            ERROR("cublasAlloc ERROR %d", err);
        if ((err=cublasAlloc(i*i, sizeof(*dB), (void**)&dev_b))!=CUBLAS_STATUS_SUCCESS)
            ERROR("cublasAlloc ERROR %d", err);
        if ((err=cublasAlloc(i*i, sizeof(*dC), (void**)&dev_c))!=CUBLAS_STATUS_SUCCESS)
            ERROR("cublasAlloc ERROR %d", err);

        cublasSetMatrix(i, i, sizeof(*dA), dA, i, dev_a, i);
        cublasSetMatrix(i, i, sizeof(*dB), dB, i, dev_b, i);
        cublasSetMatrix(i, i, sizeof(*dC), dC, i, dev_c, i);

        cublasDgemm('N', 'N', i, i, i,
                    dAlpha, dev_a, i,
                    dev_b, i, dBeta,
                    dev_c, i);
        
        if (cublasGetError()!=CUBLAS_STATUS_SUCCESS)
            ERROR("cublas ERROR");

        cublasGetMatrix(i, i, sizeof(*dC), dev_c, i, dC, i);
        
        cublasFree(dev_a);
        cublasFree(dev_b);
        cublasFree(dev_c);
#ifdef _LIFTRACC_PROFILING_        
        liftracc_function_timing_stop(&(data[i]));
#endif /* _LIFTRACC_PROFILING_ */
        memcpy(dC, dM, max_entries);
        MSG("%d.run", i);
    }
   }

     if (cublasShutdown()==CUBLAS_STATUS_SUCCESS)
        INFO("cublasShutdown()");
     else
        ERROR("cublasShutdown() failed!");

#ifdef _LIFTRACC_PROFILING_        
    print_profiling_data("cublas_RESULT", &(data[0]), 0, max_dim);
#endif /* _LIFTRACC_PROFILING_ */

    return error_count;
}

