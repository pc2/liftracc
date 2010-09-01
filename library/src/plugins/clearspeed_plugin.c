
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

#if _LIFTRACC_PROFILING_ > 0
#include "liftracc_profiling.h"
profiling_data_t function_profiling_data[LIFTRACC_FUNCTIONS_COUNT] = {};
#endif

decision_data_t decision_data[FUNCTION_COUNT*ARRAY_SIZE] = {};

typedef enum {
    CLEAR_DGEMM_ID,
    CLEAR_FUNCTIONS_COUNT
} liftracc_clear_functions_t;

const char *liftracc_clear_function_names[] = {
    "DGEMM",
    "size_entry"
};

void *liftracc_plugin_fptr[CLEAR_FUNCTIONS_COUNT] = { };

plugin_info_t liftracc_plugin_info = {
    .uuid = "7bedd79d-62b6-4210-b221-98ebf540057a",
    .name = "liftracc_clearspeed_plugin",
    .desc = "wrapper to clearspeed blas library",
    .prio = 30
};

void *handle = 0;
char *error = 0;

void __attribute__ ((constructor)) liftracc_plugin_load(void)
{
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_INIT]));
#endif /* _LIFTRACC_PROFILING_ */
    char *libname = getenv("USE_CSXL_LIB");

    if (libname)
        handle = dlopen(libname, RTLD_LAZY);

    if (!handle)
        handle = dlopen("libcsxl_mkl.so", RTLD_LAZY);

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
    for (i=0; i<CLEAR_FUNCTIONS_COUNT; i++) {
        liftracc_plugin_fptr[i] = dlsym(handle, liftracc_clear_function_names[i]);
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

#ifdef _LIFTRACC_AUTOMODE_TRAINING_
void set_decision_data(int value, int func_id, int select_id) {
    ERROR("set_decision_data(%d, %d, %d)", value, func_id, select_id);
    ticks new_tks = function_profiling_data[func_id].last_time;
    ticks old_tks = decision_data[select_id*ARRAY_SIZE+get_inx(value, ARRAY_SIZE)];
    decision_data[select_id*ARRAY_SIZE+get_inx(value, ARRAY_SIZE)] = (new_tks+old_tks)/2;
}
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

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
    *(void **) (&func) = liftracc_plugin_fptr[CLEAR_DGEMM_ID];

    if ((error = dlerror()) != 0)  {
        ERROR("%s", error);
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

    (*func)((const char *) &ta, (const char *) &tb,
            &m, &n, &k,
            &alpha, a, &lda,
            b, &ldb, &beta,
            c, &ldc);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DGEMM]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef  _LIFTRACC_AUTOMODE_TRAINING_
    set_decision_data(n, LIFTRACC_FUNCTION_DGEMM, SELECT_DGEMM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */
}

