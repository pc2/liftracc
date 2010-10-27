
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
#include "atlas_aux.h"
#include "atlas_level1.h"
#include "atlas_level2.h"
#include "atlas_level3.h"
}

unsigned int error_count = 0;

const int max_runs = 30;
const int max_exp = 14;
const int max_dim = (int)pow(2, max_exp);
const int max_entries = max_dim * max_dim;

void INThandler(int);

int main(int argc, char** argv)
{
    signal(SIGINT, INThandler);

    double *dA  = (double*) malloc( sizeof(double) * max_entries );
    double *dB  = (double*) malloc( sizeof(double) * max_entries );
    double *dC1 = (double*) malloc( sizeof(double) * max_entries );
    double *dC2 = (double*) malloc( sizeof(double) * max_entries );
    double *dC3 = (double*) malloc( sizeof(double) * max_entries );
    double *dCo = (double*) malloc( sizeof(double) * max_entries );

    double dAlpha = 1.3;
    double dBeta  = 3.7;

    srand(time(0));

    MSG("Starting Test.\n");
    MSG("Generate Random Array.");
    int c;
    int p = (int)pow(2, max_exp);
    for (c=0; c<p; c++) dA[c]  = (double)(rand()%500/100.0);
    for (c=0; c<p; c++) dB[c]  = (double)(rand()%500/100.0);
    for (c=0; c<p; c++) dC1[c] = (double)(rand()%500/100.0);
    memcpy(dC2, dC1, p*sizeof(double));
    memcpy(dC3, dC1, p*sizeof(double));
    memcpy(dCo, dC1, p*sizeof(double));
    MSG("Done.");
    
    MSG("ATL_dgemm");
    ATL_dgemm((CBLAS_TRANSPOSE)liftracc_no_trans,
              (CBLAS_TRANSPOSE)liftracc_no_trans,
              p, p, p,
              dAlpha, dA, p,
              dB, p,
              dBeta,
              dC1, p);
    MSG("end");
    MSG("cblas_dgemm");
    inner_cblas_dgemm((CBLAS_ORDER)liftracc_col_major,
                      (CBLAS_TRANSPOSE)liftracc_no_trans,
                      (CBLAS_TRANSPOSE)liftracc_no_trans,
                      p, p, p,
                      dAlpha, dA, p,
                      dB, p,
                      dBeta,
                      dC2, p);
    MSG("end");
    MSG("goto2_dgemm");
    void *goto2_handle = 0;
    if (!goto2_handle)
        goto2_handle = dlopen("libgoto2.so", RTLD_LAZY);
    void (*goto2_dgemm)(const liftracc_order_t order,
                        const liftracc_transpose_t transa,
                        const liftracc_transpose_t transb,
                        const int m,
                        const int n,
                        const int k,
                        const double alpha,
                        const double *a,
                        const int lda,
                        const double *b,
                        const int ldb,
                        const double beta,
                        double *c,
                        const int ldc);
    *(void **) (&goto2_dgemm) = dlsym(goto2_handle, "cblas_dgemm");
    (*goto2_dgemm)(liftracc_col_major,
                   liftracc_no_trans,
                   liftracc_no_trans,
                   p, p, p,
                   dAlpha, dA, p,
                   dB, p,
                   dBeta,
                   dC3, p);
    MSG("end");
    /*
    MSG("clearspeed_dgemm");
    void *clear_handle = 0;
    if (!clear_handle)
        clear_handle = dlopen("libcsxl_mkl.so", RTLD_LAZY);
    void (*clear_dgemm)(
    *(void **) (&clear_dgemm) = dlsym(handle, liftracc_clear_function_names[i]);
    MSG("end");
    */

    for (c=0; c<p; c++) {
        if (round(dC1[c]*1000)/1000 != round(dC2[c]*1000)/1000) {
            MSG("ERROR dCo[%d] = %f :: dC1[%d] = %f !=  dC2[%d] = %f -- dC3[%d] = %f", c, dCo[c], c, dC1[c], c, dC2[c], c, dC3[c]);
        }
    }

    MSG("Finish.");

    return error_count;
}

void  INThandler(int sig)
{
    signal(sig, SIG_IGN);

    exit(error_count);
}

