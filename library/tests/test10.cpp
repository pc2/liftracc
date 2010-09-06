
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
extern "C" {
#include "cblas.h"
}

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
    void *cblas_handle = 0;
    char *error = 0;

    cblas_handle = dlopen("libcblas.so", RTLD_LAZY);

    if (!cblas_handle)
        ERROR("%s", dlerror());

    if (cblas_handle) INFO("lib init ok.");

    // function init
    double (*cblas_ddot)(const int n, const double *x, const int incx, const double *y, const int incy);
    
    *(void **) (&cblas_ddot) = dlsym(cblas_handle, "inner_cblas_ddot");

    if ((error = dlerror()) != 0)  {
        ERROR("%s", error);
    }

    // benchmark
   int j,i;
   for (j=0;j<max_runs;j++) {
    for (i=0; i<max_entries; i++) dA[i] = (double)(rand()%500/100.0);
    for (i=0; i<max_entries; i++) dB[i] = (double)(rand()%500/100.0);
    for (i=2; i<max_dim; i++) {
#ifdef _LIFTRACC_PROFILING_
        liftracc_function_timing_start(&(data[i]));
#endif /* _LIFTRACC_PROFILING_ */
        double ret = (*cblas_ddot)(i, dA, 1, dB, 1);
#ifdef _LIFTRACC_PROFILING_        
        liftracc_function_timing_stop(&(data[i]));
#endif /* _LIFTRACC_PROFILING_ */
        MSG("RET: %f", ret);
        MSG("%d.run", i);
    }
   }

#ifdef _LIFTRACC_PROFILING_        
    print_profiling_data("cblas_ddot_RESULT", &(data[0]), 0, max_dim);
#endif /* _LIFTRACC_PROFILING_ */

    return error_count;
}

