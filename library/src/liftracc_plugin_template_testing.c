
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

/* TODO: add needed include files here */

#if _LIFTRACC_PROFILING_ > 0
#include "liftracc_profiling.h"
profiling_data_t function_profiling_data[LIFTRACC_FUNCTIONS_COUNT] = {};
#endif

decision_data_t decision_data[FUNCTION_COUNT][ARRAY_SIZE] = {};

plugin_info_t liftracc_plugin_info = {
    .uuid = "??", /* TODO: add uuid here (you can use uuidgen shell commande) */
    .name = "??", /* TODO: add name of plugin here */
    .desc = "??", /* TODO: add description here */
    .prio = ??    /* TODO: add standard priority here */
};

void *handle = 0;
char *error = 0;

void __attribute__ ((constructor)) liftracc_plugin_load(void)
{
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_INIT]));
#endif /* _LIFTRACC_PROFILING_ */
    char *libname = getenv("USE_????_LIB"); /* TODO: customize if needed */

    if (libname)
        handle = dlopen(libname, RTLD_LAZY);

    if (!handle)
        handle = dlopen("????", RTLD_LAZY); /* TODO: fill in library to load */

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

    liftracc_selector_loadinfo(plugin_data_filename, &(decision_data[0][0]));

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

#ifdef _LIFTRACC_AUTOMODE_PROFILING_
    char plugin_data_filename[PATH_MAX];

    Dl_info info;
    dladdr(liftracc_plugin_load, &info);
    strncpy(plugin_data_filename, info.dli_fname, PATH_MAX);
    strncat(plugin_data_filename, ".data", PATH_MAX-strlen(plugin_data_filename)-1);

    MSG("plugin_data_filename: %s", plugin_data_filename);

    liftracc_selector_saveinfo(plugin_data_filename, &(decision_data[0][0]));
#endif /* _LIFTRACC_AUTOMODE_PROFILING_ */

    INFO("%s unloaded.", liftracc_plugin_info.name);

#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FINI]));
    print_profiling_data(liftracc_plugin_info.name, &(function_profiling_data[0]), liftracc_function_names, LIFTRACC_FUNCTIONS_COUNT);
#endif /* _LIFTRACC_PROFILING_ */
}

#ifdef _LIFTRACC_AUTOMODE_PROFILING_
void set_decision_data(int value, int func_id, int select_id) {
    ticks new_tks = function_profiling_data[func_id].last_time.tks;
    ticks old_tks;
    if (value <= MAX_PROBE_SIZE) {
        old_tks = decision_data[select_id][value].tks;
        decision_data[select_id][value].count++;
        unsigned int c = decision_data[select_id][value].count;
        new_tks = ((old_tks*(c-1))+new_tks)/c;
        decision_data[select_id][value].tks = new_tks;
    } else {
        old_tks = decision_data[select_id][0].tks;
        decision_data[select_id][0].count++;
        unsigned int c = decision_data[select_id][0].count;
        new_tks = ((old_tks*(c-1))+new_tks)/c;
        decision_data[select_id][0].tks = new_tks;
    }
}
#endif /* _LIFTRACC_AUTOMODE_PROFILING_ */

decision_data_t liftracc_plugin_getdecision(liftracc_selector_funcid_t id, int index)
{
#ifdef _LIFTRACC_AUTOMODE_
    decision_data_t ret = { };
    if (decision_data[id][index].count > 0)
        return decision_data[id][index];
    return ret;
#else
    if (decision_data[id][index] > 0)
        return decision_data[id][index];
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

    *(void **) (&func) = dlsym(handle, "????"); /* TODO: fill in symbol name */

    if ((error = dlerror()) == 0) {
        (*func)(n, alpha, x, incx, y, incy); /* TODO: change parameter if needed */
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DAXPY]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_PROFILING_
    set_decision_data(((n/STEPPING)+1), LIFTRACC_FUNCTION_DDOT, SELECT_DDOT);
#endif /* _LIFTRACC_AUTOMODE_PROFILING_ */

}

double liftracc_plugin_ddot(const int n, const double *x, const int incx, const double *y, const int incy)
{
    INFO("%s_ddot", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DDOT]));
#endif /* _LIFTRACC_PROFILING_ */

    double (*func)();
    *(void **) (&func) = dlsym(handle, "????"); /* TODO: fill in symbol name */

    if ((error = dlerror()) != 0)  {
        ERROR("%s", error);
        return 0.0;
    }
    double ret = (*func)(n, x, incx, y, incy); /* TODO: change parameter if needed */

#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DDOT]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_PROFILING_
    set_decision_data(((n/STEPPING)+1), LIFTRACC_FUNCTION_DDOT, SELECT_DDOT);
#endif /* _LIFTRACC_AUTOMODE_PROFILING_ */

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
    *(void **) (&func) = dlsym(handle, "????"); /* TODO: fill in symbol name */

    if ((error = dlerror()) != 0)  {
        ERROR("%s", error);
        return;
    }
    (*func)(transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc); /* TODO: change parameter if needed */

#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DGEMM]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_PROFILING_
    set_decision_data(((n/STEPPING)+1), LIFTRACC_FUNCTION_DGEMM, SELECT_DGEMM);
#endif /* _LIFTRACC_AUTOMODE_PROFILING_ */
}

void liftracc_plugin_dscal(const int n, const double alpha, double * x, const int incx)
{
    INFO("%s_dscal", liftracc_plugin_info.name);

#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DSCAL]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();

    *(void **) (&func) = dlsym(handle, "????"); /* TODO: fill in symbol name */

    if ((error = dlerror()) == 0) {
        (*func)(n, alpha, x, incx); /* TODO: change parameter if needed */
    }

#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DSCAL]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_PROFILING_
    set_decision_data(((n/STEPPING)+1), LIFTRACC_FUNCTION_DSCAL, SELECT_DSCAL);
#endif /* _LIFTRACC_AUTOMODE_PROFILING_ */
}

liftracc_index_t liftracc_plugin_idamax(const int n, const double * x, const int incx)
{
    INFO("%s_idamax", liftracc_plugin_info.name);

#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_IDAMAX]));
#endif /* _LIFTRACC_PROFILING_ */

    liftracc_index_t (*func)();
    liftracc_index_t ret = 0.0;

    *(void **) (&func) = dlsym(handle, "????"); /* TODO: fill in symbol name */

    if ((error = dlerror()) == 0) {
        ret = (*func)(n, x, incx); /* TODO: change parameter if needed */
    }

#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_IDAMAX]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_PROFILING_
    set_decision_data(((n/STEPPING)+1), LIFTRACC_FUNCTION_IDAMAX, SELECT_IDAMAX);
#endif /* _LIFTRACC_AUTOMODE_PROFILING_ */

    return ret;
}

