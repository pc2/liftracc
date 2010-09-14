
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

#include "cblas.h"

#if _LIFTRACC_PROFILING_ > 0
#include "liftracc_profiling.h"
profiling_data_t function_profiling_data[LIFTRACC_FUNCTIONS_COUNT] = {};
#endif

decision_data_t decision_data[FUNCTION_COUNT*ARRAY_SIZE] = {};

typedef enum {
    GOTO_DAXPY_ID,
    GOTO_DDOT_ID,
    GOTO_DGEMM_ID,
    GOTO_DSCAL_ID,
    GOTO_IDAMAX_ID,
    GOTO_FUNCTIONS_COUNT
} liftracc_atlas_functions_t;

const char *liftracc_goto_function_names[] = {
    "cblas_daxpy",
    "cblas_ddot",
    "cblas_dgemm",
    "cblas_dscal",
    "cblas_idamax",
    "size_entry"
};

void *liftracc_plugin_fptr[GOTO_FUNCTIONS_COUNT] = { };

plugin_info_t liftracc_plugin_info = {
    .uuid = "829a1670-46b0-450e-9f85-3d6a65a9efcb",
    .name = "liftracc_libgoto2_plugin",
    .desc = "wrapper to libgoto2 blas library",
    .prio = 40,
};

void *handle = 0;
char *error = 0;

void __attribute__ ((constructor)) liftracc_plugin_load(void)
{
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_INIT]));
#endif /* _LIFTRACC_PROFILING_ */
    char *libname = getenv("USE_GOTO2_LIB");

    if (libname)
        handle = dlopen(libname, RTLD_LAZY);

    if (!handle)
        handle = dlopen("libgoto2.so", RTLD_LAZY);

    if (!handle)
        ERROR("%s", dlerror());
    else
        INFO("%s loaded.", liftracc_plugin_info.name);

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

    int i;
    for (i=0; i<GOTO_FUNCTIONS_COUNT; i++) {
        liftracc_plugin_fptr[i] = dlsym(handle, liftracc_goto_function_names[i]);
    }

#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_INIT]));
#endif /* _LIFTRACC_PROFILING_ */
}

void __attribute__ ((destructor)) liftracc_plugin_unload(void)
{
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FINI]));
#endif /* _LIFTRACC_PROFILING_ */
    if (handle) dlclose(handle);
    handle = 0;

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

    int success = 1;
    void (*func)();
    *(void **) (&func) = liftracc_plugin_fptr[GOTO_DAXPY_ID];

    if (func != 0) {
        (*func)(n, alpha, x, incx, y, incy);
    } else {
        success = 0;
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DAXPY]));
#endif /* _LIFTRACC_PROFILING_ */

#if _LIFTRACC_AUTOMODE_TRAINING_
    set_decision_data(success, &decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DAXPY, SELECT_DAXPY);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}

double liftracc_plugin_ddot(const int n, const double *x, const int incx, const double *y, const int incy)
{
    INFO("%s_ddot", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DDOT]));
#endif /* _LIFTRACC_PROFILING_ */

    int success = 1;
    double ret = 0.0;
    double (*func)();
    *(void **) (&func) = liftracc_plugin_fptr[GOTO_DDOT_ID];

    if (func != 0)  {
        ret = (*func)(n, x, incx, y, incy);
    } else {
        success = 0;
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DDOT]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_
    set_decision_data(success, &decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DDOT, SELECT_DDOT);
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
    
    int success = 1;
    void (*func)();
    *(void **) (&func) = liftracc_plugin_fptr[GOTO_DGEMM_ID];

    if (func != 0)  {
        (*func)(order, transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
    } else {
        success = 0;
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DGEMM]));
#endif /* _LIFTRACC_PROFILING_ */

#if _LIFTRACC_AUTOMODE_TRAINING_
    set_decision_data(success, &decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DGEMM, SELECT_DGEMM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */
}

void liftracc_plugin_dscal(const int n, const double alpha, double * x, const int incx)
{
    INFO("%s_dscal", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DSCAL]));
#endif /* _LIFTRACC_PROFILING_ */

    int success = 1;
    void (*func)();
    *(void **) (&func) = liftracc_plugin_fptr[GOTO_DSCAL_ID];

    if (func != 0) {
        (*func)(n, alpha, x, incx);
    } else {
        success = 0;
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DSCAL]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_
    set_decision_data(success, &decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DSCAL, SELECT_DSCAL);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */
}

liftracc_index_t liftracc_plugin_idamax(const int n, const double * x, const int incx)
{
    INFO("%s_idamax", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_IDAMAX]));
#endif /* _LIFTRACC_PROFILING_ */

    int success = 1;
    liftracc_index_t ret = 0;
    liftracc_index_t (*func)();
    *(void **) (&func) = liftracc_plugin_fptr[GOTO_IDAMAX_ID];

    if (func != 0) {
        ret = (*func)(n, x, incx);
    } else {
        success = 0;
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_IDAMAX]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_
    set_decision_data(success, &decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_IDAMAX, SELECT_IDAMAX);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

    return ret;
}

