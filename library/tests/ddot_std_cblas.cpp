
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
extern "C" {
#include "cblas.h"
}

unsigned int error_count = 0;

const int max_runs = 30;
const int max_exp = 25;
const int max_dim = (int)pow(2, max_exp);
const int max_entries = max_dim;

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
    for (int i=0; i<1000; i++) {
        liftracc_function_timing_start(&(liftracc_profiling_data[MEASURING_ERROR]));
        liftracc_function_timing_stop(&(liftracc_profiling_data[MEASURING_ERROR]));
    }
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

    if (cblas_handle) MSG("lib init ok.");

    // function init
    double (*cblas_ddot)(const int n, const double *x, const int incx, const double *y, const int incy);

    *(void **) (&cblas_ddot) = dlsym(cblas_handle, "inner_cblas_ddot");

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
        MSG("Done.");
#ifdef _LIFTRACC_PROFILING_
        liftracc_function_timing_start(&(data[i]));
#endif /* _LIFTRACC_PROFILING_ */
        double ret = (*cblas_ddot)(p, dA, 1, dB, 1);
#ifdef _LIFTRACC_PROFILING_        
        liftracc_function_timing_stop(&(data[i]));
#endif /* _LIFTRACC_PROFILING_ */
        MSG("RET: %f", ret);
        MSG("cblas_%d_%d.run", p, j);
      }
    }

#ifdef _LIFTRACC_PROFILING_
    print_profiling_data("cblas_ddot_result", &(liftracc_profiling_data[0]), prof_id_names, ID_COUNT);
    print_profiling_data("cblas_ddot_result", &(data[0]), 0, max_exp+1);
#endif /* _LIFTRACC_PROFILING_ */

    return error_count;
}

void  INThandler(int sig)
{
    signal(sig, SIG_IGN);

#ifdef _LIFTRACC_PROFILING_
    MSG("Saving partly collected data.\n");

    print_profiling_data("cblas_ddot_result", &(liftracc_profiling_data[0]), prof_id_names, ID_COUNT);
    print_profiling_data("cblas_ddot_result", &(data[0]), 0, max_exp+1);
#endif /* _LIFTRACC_PROFILING_ */
    
    exit(error_count);
}

