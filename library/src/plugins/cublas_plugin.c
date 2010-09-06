
#include "liftracc.h"
#include "liftracc_plugin.h"
#include "liftracc_logging.h"

#ifndef __USE_GNU
#define __USE_GNU
#endif
#include <dlfcn.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include "cublas.h"

#if _LIFTRACC_PROFILING_ > 0
#include "liftracc_profiling.h"
profiling_data_t function_profiling_data[LIFTRACC_FUNCTIONS_COUNT] = {};
#endif

decision_data_t decision_data[FUNCTION_COUNT*ARRAY_SIZE] = {};

plugin_info_t liftracc_plugin_info = {
    .uuid = "4241c224-99c9-4c44-979f-32c6ac5fc9a4",
    .name = "liftracc_cublas_plugin",
    .desc = "wrapper to cublas library",
    .prio = 20
};

void *handle = 0;
char *error = 0;

void __attribute__ ((constructor)) liftracc_plugin_load(void)
{
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_INIT]));
#endif /* _LIFTRACC_PROFILING_ */
    
    if (cublasInit()==CUBLAS_STATUS_SUCCESS)
        INFO("%s loaded.", liftracc_plugin_info.name);
    else
        ERROR("cublasInit() failed!");

    char plugin_data_filename[PATH_MAX];
    Dl_info info;
    dladdr(liftracc_plugin_load, &info);
    strncpy(plugin_data_filename, info.dli_fname, PATH_MAX);
#ifdef _LIFTRACC_AUTOMODE_
    strncat(plugin_data_filename, ".data", PATH_MAX-strlen(plugin_data_filename)-1);
    MSG("plugin_data_filename: %s", plugin_data_filename);
#else /* _LIFTRACC_AUTOMODE_ */
    strncat(plugin_data_filename, ".txt", PATH_MAX-strlen(plugin_data_filename)-1);
    MSG("plugin_data_filename: %s", plugin_data_filename);
#endif /* _LIFTRACC_AUTOMODE_ */
    liftracc_selector_loadinfo(plugin_data_filename, &decision_data[0]);

#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_INIT]));
#endif /* _LIFTRACC_PROFILING_ */
}

void __attribute__ ((destructor)) liftracc_plugin_unload(void)
{
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FINI]));
#endif /* _LIFTRACC_PROFILING_ */
    
    if (cublasShutdown()==CUBLAS_STATUS_SUCCESS)
        INFO("%s unloaded.", liftracc_plugin_info.name);
    else
        ERROR("cublasShutdown() failed!");

#ifdef _LIFTRACC_AUTOMODE_TRAINING_
    char plugin_data_filename[PATH_MAX];

    Dl_info info;
    dladdr(liftracc_plugin_load, &info);
    strncpy(plugin_data_filename, info.dli_fname, PATH_MAX);
    strncat(plugin_data_filename, ".data", PATH_MAX-strlen(plugin_data_filename)-1);

    MSG("plugin_data_filename: %s", plugin_data_filename);

    liftracc_selector_saveinfo(plugin_data_filename, &decision_data[0]);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

    INFO("%s unloaded.", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FINI]));
    print_profiling_data(liftracc_plugin_info.name, &(function_profiling_data[0]), liftracc_function_names, LIFTRACC_FUNCTIONS_COUNT);
#endif /* _LIFTRACC_PROFILING_ */
}

decision_data_t liftracc_plugin_getdecision(liftracc_selector_funcid_t id, int index)
{
#ifdef _LIFTRACC_AUTOMODE_
    return decision_data[id*ARRAY_SIZE+index];
#else
    if (decision_data[id*ARRAY_SIZE+index] > 0)
        return decision_data[id*ARRAY_SIZE+index];
    return liftracc_plugin_info.prio;
#endif /* _LIFTRACC_AUTOMODE_ */
}

/* START OF BLAS FUNCTION IMPLEMENTATION */

void liftracc_plugin_daxpy(const int n, const double alpha, const double * x, const int incx, double * y, const int incy)
{
    INFO("%s_daxpy", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DAXPY]));
#endif /* _LIFTRACC_PROFILING_ */

    double* dev_x;
    double* dev_y;

    cublasAlloc(n, sizeof(*x), (void**)&dev_x);
    cublasAlloc(n, sizeof(*y), (void**)&dev_y);
    
    cublasSetVector(n, sizeof(*x), x, incx, dev_x, incx);
    cublasSetVector(n, sizeof(*y), y, incy, dev_y, incy);

    cublasDaxpy(n, alpha, dev_x, incx, dev_y, incy);

    if (cublasGetError()!=CUBLAS_STATUS_SUCCESS)
        ERROR("cublas function ERROR");

    cublasGetVector(n, sizeof(*y), dev_y, incy, y, incy);

    cublasFree(dev_x);
    cublasFree(dev_y);

#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DAXPY]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_
    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DDOT, SELECT_DDOT);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}

double liftracc_plugin_ddot(const int n, const double *x, const int incx, const double *y, const int incy)
{
    INFO("%s_ddot", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DDOT]));
#endif /* _LIFTRACC_PROFILING_ */

    double* dev_x;
    double* dev_y;

    cublasAlloc(n, sizeof(*x), (void**)&dev_x);
    cublasAlloc(n, sizeof(*y), (void**)&dev_y);

    cublasSetVector(n, sizeof(*x), x, incx, dev_x, incx);
    cublasSetVector(n, sizeof(*y), y, incy, dev_y, incy);

    double ret = cublasDdot(n, dev_x, incx, dev_y, incy);

    if (cublasGetError()!=CUBLAS_STATUS_SUCCESS)
        ERROR("cublas function ERROR");

    cublasFree(dev_x);
    cublasFree(dev_y);

#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DDOT]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_
    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DDOT, SELECT_DDOT);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

    return ret;
}

void liftracc_plugin_dgemm(const liftracc_order_t order,
                          const liftracc_transpose_t transa, const liftracc_transpose_t transb,
                          const int m, const int n, const int k,
                          const double alpha, const double *a, const int lda,
                          const double *b, const int ldb, const double beta,
                          double *c, const int ldc)
{
    INFO("%s_dgemm", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DGEMM]));
#endif /* _LIFTRACC_PROFILING_ */

#if _LIFTRACC_PROFILING_ == 10
    liftracc_function_timing_start(&(liftracc_profiling_data[PARAM_CONV]));
#endif /* _LIFTRACC_PROFILING_ */
    if (order != liftracc_col_major) {
        ERROR("Matrix not in column-major order.");
        return;
    }

    char ta, tb;
    switch (transa) {
        case liftracc_no_trans:   ta = 'N'; break;
        case liftracc_trans:      ta = 'T'; break;
        case liftracc_conj_trans: ta = 'C'; break;
        default: ta = 'N'; break;
    }
    switch (transb) {
       case liftracc_no_trans:   tb = 'N'; break;
       case liftracc_trans:      tb = 'T'; break;
       case liftracc_conj_trans: tb = 'C'; break;
       default: tb = 'N'; break;
    }

#if _LIFTRACC_PROFILING_ == 10
    liftracc_function_timing_stop(&(liftracc_profiling_data[PARAM_CONV]));
#endif /* _LIFTRACC_PROFILING_ */

    double* dev_a;
    double* dev_b;
    double* dev_c;

    cublasAlloc(m*k, sizeof(*a), (void**)&dev_a);
    cublasAlloc(k*n, sizeof(*b), (void**)&dev_b);
    cublasAlloc(m*n, sizeof(*c), (void**)&dev_c);

    cublasSetMatrix(m, k, sizeof(*a), a, lda, dev_a, lda);
    cublasSetMatrix(k, n, sizeof(*a), a, ldb, dev_b, ldb);
    cublasSetMatrix(m, n, sizeof(*a), a, ldc, dev_c, ldc);

    cublasDgemm(ta, tb, m, n, k,
                alpha, dev_a, lda,
                dev_b, ldb, beta,
                dev_c, ldc);

    if (cublasGetError()!=CUBLAS_STATUS_SUCCESS)
        ERROR("cublas function ERROR");

    cublasGetMatrix(m, n, sizeof(*c), dev_c, ldc, c, ldc);

    cublasFree(dev_a);
    cublasFree(dev_b);
    cublasFree(dev_c);

#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DGEMM]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_
    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DGEMM, SELECT_DGEMM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */
}

void liftracc_plugin_dscal(const int n, const double alpha, double * x, const int incx)
{
    INFO("%s_dscal", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DSCAL]));
#endif /* _LIFTRACC_PROFILING_ */

    double* dev_x;

    cublasAlloc(n, sizeof(*x), (void**)&dev_x);
    cublasSetVector(n, sizeof(*x), x, incx, dev_x, incx);

    cublasDscal(n, alpha, dev_x, incx);

    if (cublasGetError()!=CUBLAS_STATUS_SUCCESS)
        ERROR("cublas function ERROR");

    cublasGetVector(n, sizeof(*x), dev_x, incx, x, incx);

    cublasFree(dev_x);

#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DSCAL]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_
    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DSCAL, SELECT_DSCAL);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */
}

liftracc_index_t liftracc_plugin_idamax(const int n, const double * x, const int incx)
{
    INFO("%s_idamax", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_IDAMAX]));
#endif /* _LIFTRACC_PROFILING_ */

    double* dev_x;

    cublasAlloc(n, sizeof(*x), (void**)&dev_x);
    cublasSetVector(n, sizeof(*x), x, incx, dev_x, incx);

    int ret = cublasIdamax(n, dev_x, incx);

    if (cublasGetError()!=CUBLAS_STATUS_SUCCESS)
        ERROR("cublas function ERROR");

    cublasFree(dev_x);

#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_IDAMAX]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_
    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_IDAMAX, SELECT_IDAMAX);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

    return ret;
}

