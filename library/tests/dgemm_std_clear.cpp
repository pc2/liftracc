
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

#include <sched.h>
#include <math.h>
#include <signal.h>

#include "liftracc.h"
#include "liftracc_logging.h"
#include "liftracc_profiling.h"

unsigned int error_count = 0;

const int max_runs = 30;
const int max_exp = 14;
const int max_dim = (int)pow(2, max_exp);
const int max_entries = max_dim * max_dim;

#ifdef _LIFTRACC_PROFILING_
    profiling_data_t data[max_exp+1] = { };
#endif /* _LIFTRACC_PROFILING_  */

void INThandler(int);

int main(int argc, char** argv)
{
    signal(SIGINT, INThandler);
/*
    pid_t pid = getpid();
    struct sched_param sparam;
    if (sched_getparam(pid, &sparam) > -1) {
        sparam.sched_priority = sched_get_priority_max(SCHED_FIFO);
        if (sched_setscheduler(pid, SCHED_FIFO, &sparam) == 0)
            MSG("Scheduler set to FIFO!\n");
        else
            MSG("Scheduler not set!\n");
    } else
        MSG("Scheduler not set!\n");
*/
#ifdef _LIFTRACC_PROFILING_
    for (int i=0; i<100; i++) {
        liftracc_function_timing_start(&(liftracc_profiling_data[MEASURING_ERROR]));
        liftracc_function_timing_stop(&(liftracc_profiling_data[MEASURING_ERROR]));
    }
#endif /* _LIFTRACC_PROFILING_  */
    double *dA = (double*) malloc( sizeof(double) * max_entries );
    double *dB = (double*) malloc( sizeof(double) * max_entries );
    double *dC = (double*) malloc( sizeof(double) * max_entries );
    double *dM = (double*) malloc( sizeof(double) * max_entries );

    double dAlpha = 1.3;
    double dBeta  = 3.7;

    srand(time(0));

    // init libraries
    void *csxl_handle = 0;
    char *error = 0;

    csxl_handle = dlopen("libcsxl_mkl.so", RTLD_LAZY);

    if (!csxl_handle)
        ERROR("%s", dlerror());

    if (csxl_handle) INFO("lib init ok.");

    // function init
    void (*csxl_dgemm)(const char *transa,
                       const char *transb,
                       const int *m,
                       const int *n,
                       const int *k,
                       const double *alpha,
                       const double *a,
                       const int *lda,
                       const double *b,
                       const int *ldb,
                       const double *beta,
                       double *c,
                       const int *ldc);

    *(void **) (&csxl_dgemm) = dlsym(csxl_handle, "DGEMM");

    if ((error = dlerror()) != 0)  {
        ERROR("%s", error);
    }

    MSG("Starting Benchmark.\n");
    int i, j, c;
    for (i=1; i<=max_exp; i++) {
      int p = (int)pow(2, i);
      for (j=0; j<max_runs; j++) {
        MSG("Generate Random Array.");
        for (c=0; c<p; c++) dA[c] = (double)(rand()%500/100.0);
        for (c=0; c<p; c++) dB[c] = (double)(rand()%500/100.0);
        for (c=0; c<p; c++) dM[c] = (double)(rand()%500/100.0);
        memcpy(dC, dM, p);
        MSG("Done.");
#ifdef _LIFTRACC_PROFILING_
        liftracc_function_timing_start(&(data[i]));
#endif /* _LIFTRACC_PROFILING_ */
        (*csxl_dgemm)("N", "N",
                       &p,&p,&p,
                       &dAlpha, dA, &p,
                       dB, &p,
                       &dBeta,
                       dC, &p);
#ifdef _LIFTRACC_PROFILING_        
        liftracc_function_timing_stop(&(data[i]));
#endif /* _LIFTRACC_PROFILING_ */
        memcpy(dC, dM, p);
        MSG("clear_%d_%d.run", p, j);
    }
   }

#ifdef _LIFTRACC_PROFILING_        
    print_profiling_data("clear_dgemm_result", &(liftracc_profiling_data[0]), prof_id_names, ID_COUNT);
    print_profiling_data("clear_dgemm_result", &(data[0]), 0, max_exp+1);
#endif /* _LIFTRACC_PROFILING_ */

    return error_count;
}

void  INThandler(int sig)
{
    signal(sig, SIG_IGN);

#ifdef _LIFTRACC_PROFILING_
    MSG("Saving partly collected data.\n");

    print_profiling_data("clear_dgemm_result", &(liftracc_profiling_data[0]), prof_id_names, ID_COUNT);
    print_profiling_data("clear_dgemm_result", &(data[0]), 0, max_exp+1);
#endif /* _LIFTRACC_PROFILING_ */

    exit(error_count);
}

