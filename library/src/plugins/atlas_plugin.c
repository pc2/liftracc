
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

#include "atlas_aux.h"
#include "atlas_level1.h"
#include "atlas_level2.h"
#include "atlas_level3.h"

#if _LIFTRACC_PROFILING_ > 0
#include "liftracc_profiling.h"
profiling_data_t function_profiling_data[LIFTRACC_FUNCTIONS_COUNT] = {};
#endif

decision_data_t decision_data[FUNCTION_COUNT*ARRAY_SIZE] = {};

typedef enum {
    ATLAS_DAXPY_ID,
    ATLAS_DDOT_ID,
    ATLAS_DGEMM_ID,
    ATLAS_DSCAL_ID,
    ATLAS_IDAMAX_ID,
    ATLAS_FUNCTIONS_COUNT
} liftracc_atlas_functions_t;

const char *liftracc_atlas_function_names[] = {
    "ATL_daxpy",
    "ATL_ddot",
    "ATL_dgemm",
    "ATL_dscal",
    "ATL_idamax",
    "size_entry"
};

void *liftracc_plugin_fptr[ATLAS_FUNCTIONS_COUNT] = { };

plugin_info_t liftracc_plugin_info = {
    .uuid = "95cd6e1c-9f7e-4628-a265-5f9e1fab6abd",
    .name = "liftracc_atlas_plugin",
    .desc = "wrapper to atlas blas library",
    .prio = 10
};

void *handle = 0;
char *error = 0;

void __attribute__ ((constructor)) liftracc_plugin_load(void)
{
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_INIT]));
#endif /* _LIFTRACC_PROFILING_ */
    char *libname = getenv("USE_ATLAS_LIB");

    if (libname)
        handle = dlopen(libname, RTLD_LAZY);

    if (!handle)
        handle = dlopen("libatlas.so", RTLD_LAZY);

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
    for (i=0; i<ATLAS_FUNCTIONS_COUNT; i++) {
        liftracc_plugin_fptr[i] = dlsym(handle, liftracc_atlas_function_names[i]);
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

    void (*func)();

    *(void **) (&func) = liftracc_plugin_fptr[ATLAS_DAXPY_ID];

    if ((error = dlerror()) == 0) {
        (*func)(n, alpha, x, incx, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DAXPY]));
#endif /* _LIFTRACC_PROFILING_ */

#if _LIFTRACC_AUTOMODE_TRAINING_
    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DDOT, SELECT_DDOT);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}

double liftracc_plugin_ddot(const int n, const double *x, const int incx, const double *y, const int incy)
{
    INFO("%s_ddot", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DDOT]));
#endif /* _LIFTRACC_PROFILING_ */

    double (*func)();
    *(void **) (&func) = liftracc_plugin_fptr[ATLAS_DDOT_ID];

    if ((error = dlerror()) != 0)  {
        ERROR("%s", error);
        return 0.0;
    }
    double ret = (*func)(n, x, incx, y, incy);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DDOT]));
#endif /* _LIFTRACC_PROFILING_ */

#if _LIFTRACC_AUTOMODE_TRAINING_
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
    if (order != liftracc_col_major) {
        ERROR("Matrix not in column-major order.");
        return;
    }
    void (*func)();
    *(void **) (&func) = liftracc_plugin_fptr[ATLAS_DGEMM_ID];

    if ((error = dlerror()) != 0)  {
        ERROR("%s", error);
        return;
    }
    (*func)(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
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

    void (*func)();

    *(void **) (&func) = liftracc_plugin_fptr[ATLAS_DSCAL_ID];

    if ((error = dlerror()) == 0) {
        (*func)(n, alpha, x, incx);
    }
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

    liftracc_index_t (*func)();
    liftracc_index_t ret = 0.0;

    *(void **) (&func) = liftracc_plugin_fptr[ATLAS_IDAMAX_ID];

    if ((error = dlerror()) == 0) {
        ret = (*func)(n, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_IDAMAX]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_
    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_IDAMAX, SELECT_IDAMAX);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

    return ret;
}

