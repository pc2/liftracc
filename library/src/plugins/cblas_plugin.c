
/**
 * \file cblas_plugin.c
 * \brief [generated file]
 */

/* This file is generated automatically, do not edit manually! */

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

#include <stdlib.h>

#include "cblas_autogen.h"

#if _LIFTRACC_PROFILING_ > 0
#include "liftracc_profiling.h"
#include "liftracc_selector.h"
profiling_data_t function_profiling_data[LIFTRACC_FUNCTIONS_COUNT] = { };
#endif  /* _LIFTRACC_PROFILING_ */

decision_data_t decision_data[FUNCTION_COUNT*ARRAY_SIZE] = { };

void *liftracc_plugin_fptr[CBLAS_FUNCTIONS_COUNT] = { };

plugin_info_t liftracc_plugin_info = {
    .uuid = "f4a17438-80ed-4f9f-90f1-1728df8ea630",
    .name = "liftracc_cblas_plugin",
    .desc = "wrapper to standard blas library",
    .prio = 1
};

void *handle = 0;
char *error = 0;

void __attribute__ ((constructor)) liftracc_plugin_load(void)
{
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_INIT]));
#endif /* _LIFTRACC_PROFILING_ */
    char *libname = getenv("USE_CBLAS_LIB");
    
    if (libname)
        handle = dlopen(libname, RTLD_LAZY);

    if (!handle)
        handle = dlopen("libcblas.so", RTLD_LAZY);

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
    for (i=0; i<CBLAS_FUNCTIONS_COUNT; i++) {
        liftracc_plugin_fptr[i] = dlsym(handle, liftracc_cblas_function_names[i]);
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

#if _LIFTRACC_PROFILING_ == 1
int liftracc_plugin_calltest_dynamic(int a, int b, int c)
{
    liftracc_function_timing_stop(&(liftracc_profiling_data[CALL_DYNAMIC]));
    /* INFO("liftracc_plugin_calltest_dynamic"); */
    return rand()-a*b+c;
}
#endif /* _LIFTRACC_PROFILING_  */


float liftracc_plugin_sdsdot(const int n, const float alpha, const float * x, const int incx, const float * y, const int incy)
{
    INFO("%s_sdsdot", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SDSDOT]));
#endif /* _LIFTRACC_PROFILING_ */

    float (*func)();
    float ret = 0.0;
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SDSDOT];
    
    if (func != 0) {
        ret = (*func)(n, alpha, x, incx, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SDSDOT]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SDSDOT, SELECT_SDSDOT);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


double liftracc_plugin_dsdot(const int n, const float * x, const int incx, const float * y, const int incy)
{
    INFO("%s_dsdot", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DSDOT]));
#endif /* _LIFTRACC_PROFILING_ */

    double (*func)();
    double ret = 0.0;
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DSDOT];
    
    if (func != 0) {
        ret = (*func)(n, x, incx, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DSDOT]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DSDOT, SELECT_DSDOT);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


float liftracc_plugin_sdot(const int n, const float * x, const int incx, const float * y, const int incy)
{
    INFO("%s_sdot", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SDOT]));
#endif /* _LIFTRACC_PROFILING_ */

    float (*func)();
    float ret = 0.0;
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SDOT];
    
    if (func != 0) {
        ret = (*func)(n, x, incx, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SDOT]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SDOT, SELECT_SDOT);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


double liftracc_plugin_ddot(const int n, const double * x, const int incx, const double * y, const int incy)
{
    INFO("%s_ddot", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DDOT]));
#endif /* _LIFTRACC_PROFILING_ */

    double (*func)();
    double ret = 0.0;
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DDOT];
    
    if (func != 0) {
        ret = (*func)(n, x, incx, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DDOT]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DDOT, SELECT_DDOT);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_cdotu_sub(const int n, const void * x, const int incx, const void * y, const int incy, void * dotu)
{
    INFO("%s_cdotu_sub", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CDOTU_SUB]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CDOTU_SUB];
    
    if (func != 0) {
        (*func)(n, x, incx, y, incy, dotu);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CDOTU_SUB]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CDOTU_SUB, SELECT_CDOTU_SUB);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_cdotc_sub(const int n, const void * x, const int incx, const void * y, const int incy, void * dotc)
{
    INFO("%s_cdotc_sub", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CDOTC_SUB]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CDOTC_SUB];
    
    if (func != 0) {
        (*func)(n, x, incx, y, incy, dotc);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CDOTC_SUB]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CDOTC_SUB, SELECT_CDOTC_SUB);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zdotu_sub(const int n, const void * x, const int incx, const void * y, const int incy, void * dotu)
{
    INFO("%s_zdotu_sub", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZDOTU_SUB]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZDOTU_SUB];
    
    if (func != 0) {
        (*func)(n, x, incx, y, incy, dotu);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZDOTU_SUB]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZDOTU_SUB, SELECT_ZDOTU_SUB);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zdotc_sub(const int n, const void * x, const int incx, const void * y, const int incy, void * dotc)
{
    INFO("%s_zdotc_sub", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZDOTC_SUB]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZDOTC_SUB];
    
    if (func != 0) {
        (*func)(n, x, incx, y, incy, dotc);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZDOTC_SUB]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZDOTC_SUB, SELECT_ZDOTC_SUB);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


float liftracc_plugin_snrm2(const int n, const float * x, const int incx)
{
    INFO("%s_snrm2", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SNRM2]));
#endif /* _LIFTRACC_PROFILING_ */

    float (*func)();
    float ret = 0.0;
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SNRM2];
    
    if (func != 0) {
        ret = (*func)(n, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SNRM2]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SNRM2, SELECT_SNRM2);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


float liftracc_plugin_sasum(const int n, const float * x, const int incx)
{
    INFO("%s_sasum", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SASUM]));
#endif /* _LIFTRACC_PROFILING_ */

    float (*func)();
    float ret = 0.0;
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SASUM];
    
    if (func != 0) {
        ret = (*func)(n, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SASUM]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SASUM, SELECT_SASUM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


double liftracc_plugin_dnrm2(const int n, const double * x, const int incx)
{
    INFO("%s_dnrm2", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DNRM2]));
#endif /* _LIFTRACC_PROFILING_ */

    double (*func)();
    double ret = 0.0;
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DNRM2];
    
    if (func != 0) {
        ret = (*func)(n, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DNRM2]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DNRM2, SELECT_DNRM2);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


double liftracc_plugin_dasum(const int n, const double * x, const int incx)
{
    INFO("%s_dasum", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DASUM]));
#endif /* _LIFTRACC_PROFILING_ */

    double (*func)();
    double ret = 0.0;
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DASUM];
    
    if (func != 0) {
        ret = (*func)(n, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DASUM]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DASUM, SELECT_DASUM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


float liftracc_plugin_scnrm2(const int n, const void * x, const int incx)
{
    INFO("%s_scnrm2", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SCNRM2]));
#endif /* _LIFTRACC_PROFILING_ */

    float (*func)();
    float ret = 0.0;
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SCNRM2];
    
    if (func != 0) {
        ret = (*func)(n, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SCNRM2]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SCNRM2, SELECT_SCNRM2);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


float liftracc_plugin_scasum(const int n, const void * x, const int incx)
{
    INFO("%s_scasum", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SCASUM]));
#endif /* _LIFTRACC_PROFILING_ */

    float (*func)();
    float ret = 0.0;
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SCASUM];
    
    if (func != 0) {
        ret = (*func)(n, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SCASUM]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SCASUM, SELECT_SCASUM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


double liftracc_plugin_dznrm2(const int n, const void * x, const int incx)
{
    INFO("%s_dznrm2", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DZNRM2]));
#endif /* _LIFTRACC_PROFILING_ */

    double (*func)();
    double ret = 0.0;
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DZNRM2];
    
    if (func != 0) {
        ret = (*func)(n, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DZNRM2]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DZNRM2, SELECT_DZNRM2);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


double liftracc_plugin_dzasum(const int n, const void * x, const int incx)
{
    INFO("%s_dzasum", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DZASUM]));
#endif /* _LIFTRACC_PROFILING_ */

    double (*func)();
    double ret = 0.0;
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DZASUM];
    
    if (func != 0) {
        ret = (*func)(n, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DZASUM]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DZASUM, SELECT_DZASUM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


liftracc_index_t liftracc_plugin_isamax(const int n, const float * x, const int incx)
{
    INFO("%s_isamax", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ISAMAX]));
#endif /* _LIFTRACC_PROFILING_ */

    liftracc_index_t (*func)();
    liftracc_index_t ret = 0.0;
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ISAMAX];
    
    if (func != 0) {
        ret = (*func)(n, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ISAMAX]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ISAMAX, SELECT_ISAMAX);
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
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_IDAMAX];
    
    if (func != 0) {
        ret = (*func)(n, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_IDAMAX]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_IDAMAX, SELECT_IDAMAX);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


liftracc_index_t liftracc_plugin_icamax(const int n, const void * x, const int incx)
{
    INFO("%s_icamax", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ICAMAX]));
#endif /* _LIFTRACC_PROFILING_ */

    liftracc_index_t (*func)();
    liftracc_index_t ret = 0.0;
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ICAMAX];
    
    if (func != 0) {
        ret = (*func)(n, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ICAMAX]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ICAMAX, SELECT_ICAMAX);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


liftracc_index_t liftracc_plugin_izamax(const int n, const void * x, const int incx)
{
    INFO("%s_izamax", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_IZAMAX]));
#endif /* _LIFTRACC_PROFILING_ */

    liftracc_index_t (*func)();
    liftracc_index_t ret = 0.0;
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_IZAMAX];
    
    if (func != 0) {
        ret = (*func)(n, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_IZAMAX]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_IZAMAX, SELECT_IZAMAX);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_sswap(const int n, float * x, const int incx, float * y, const int incy)
{
    INFO("%s_sswap", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SSWAP]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SSWAP];
    
    if (func != 0) {
        (*func)(n, x, incx, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SSWAP]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SSWAP, SELECT_SSWAP);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_scopy(const int n, const float * x, const int incx, float * y, const int incy)
{
    INFO("%s_scopy", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SCOPY]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SCOPY];
    
    if (func != 0) {
        (*func)(n, x, incx, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SCOPY]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SCOPY, SELECT_SCOPY);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_saxpy(const int n, const float alpha, const float * x, const int incx, float * y, const int incy)
{
    INFO("%s_saxpy", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SAXPY]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SAXPY];
    
    if (func != 0) {
        (*func)(n, alpha, x, incx, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SAXPY]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SAXPY, SELECT_SAXPY);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dswap(const int n, double * x, const int incx, double * y, const int incy)
{
    INFO("%s_dswap", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DSWAP]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DSWAP];
    
    if (func != 0) {
        (*func)(n, x, incx, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DSWAP]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DSWAP, SELECT_DSWAP);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dcopy(const int n, const double * x, const int incx, double * y, const int incy)
{
    INFO("%s_dcopy", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DCOPY]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DCOPY];
    
    if (func != 0) {
        (*func)(n, x, incx, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DCOPY]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DCOPY, SELECT_DCOPY);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_daxpy(const int n, const double alpha, const double * x, const int incx, double * y, const int incy)
{
    INFO("%s_daxpy", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DAXPY]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DAXPY];
    
    if (func != 0) {
        (*func)(n, alpha, x, incx, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DAXPY]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DAXPY, SELECT_DAXPY);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_cswap(const int n, void * x, const int incx, void * y, const int incy)
{
    INFO("%s_cswap", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CSWAP]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CSWAP];
    
    if (func != 0) {
        (*func)(n, x, incx, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CSWAP]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CSWAP, SELECT_CSWAP);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_ccopy(const int n, const void * x, const int incx, void * y, const int incy)
{
    INFO("%s_ccopy", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CCOPY]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CCOPY];
    
    if (func != 0) {
        (*func)(n, x, incx, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CCOPY]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CCOPY, SELECT_CCOPY);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_caxpy(const int n, const void * alpha, const void * x, const int incx, void * y, const int incy)
{
    INFO("%s_caxpy", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CAXPY]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CAXPY];
    
    if (func != 0) {
        (*func)(n, alpha, x, incx, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CAXPY]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CAXPY, SELECT_CAXPY);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zswap(const int n, void * x, const int incx, void * y, const int incy)
{
    INFO("%s_zswap", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZSWAP]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZSWAP];
    
    if (func != 0) {
        (*func)(n, x, incx, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZSWAP]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZSWAP, SELECT_ZSWAP);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zcopy(const int n, const void * x, const int incx, void * y, const int incy)
{
    INFO("%s_zcopy", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZCOPY]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZCOPY];
    
    if (func != 0) {
        (*func)(n, x, incx, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZCOPY]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZCOPY, SELECT_ZCOPY);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zaxpy(const int n, const void * alpha, const void * x, const int incx, void * y, const int incy)
{
    INFO("%s_zaxpy", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZAXPY]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZAXPY];
    
    if (func != 0) {
        (*func)(n, alpha, x, incx, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZAXPY]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZAXPY, SELECT_ZAXPY);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_srotg(float * a, float * b, float * c, float * s)
{
    INFO("%s_srotg", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SROTG]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SROTG];
    
    if (func != 0) {
        (*func)(a, b, c, s);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SROTG]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_
    int n = 0;
    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SROTG, SELECT_SROTG);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_srotmg(float * d1, float * d2, float * b1, const float b2, float * p)
{
    INFO("%s_srotmg", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SROTMG]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SROTMG];
    
    if (func != 0) {
        (*func)(d1, d2, b1, b2, p);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SROTMG]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_
    int n = 0;
    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SROTMG, SELECT_SROTMG);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_srot(const int n, float * x, const int incx, float * y, const int incy, const float c, const float s)
{
    INFO("%s_srot", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SROT]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SROT];
    
    if (func != 0) {
        (*func)(n, x, incx, y, incy, c, s);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SROT]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SROT, SELECT_SROT);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_srotm(const int n, float * x, const int incx, float * y, const int incy, const float * p)
{
    INFO("%s_srotm", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SROTM]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SROTM];
    
    if (func != 0) {
        (*func)(n, x, incx, y, incy, p);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SROTM]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SROTM, SELECT_SROTM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_drotg(double * a, double * b, double * c, double * s)
{
    INFO("%s_drotg", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DROTG]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DROTG];
    
    if (func != 0) {
        (*func)(a, b, c, s);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DROTG]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_
    int n = 0;
    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DROTG, SELECT_DROTG);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_drotmg(double * d1, double * d2, double * b1, const double b2, double * p)
{
    INFO("%s_drotmg", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DROTMG]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DROTMG];
    
    if (func != 0) {
        (*func)(d1, d2, b1, b2, p);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DROTMG]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_
    int n = 0;
    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DROTMG, SELECT_DROTMG);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_drot(const int n, double * x, const int incx, double * y, const int incy, const double c, const double s)
{
    INFO("%s_drot", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DROT]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DROT];
    
    if (func != 0) {
        (*func)(n, x, incx, y, incy, c, s);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DROT]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DROT, SELECT_DROT);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_drotm(const int n, double * x, const int incx, double * y, const int incy, const double * p)
{
    INFO("%s_drotm", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DROTM]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DROTM];
    
    if (func != 0) {
        (*func)(n, x, incx, y, incy, p);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DROTM]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DROTM, SELECT_DROTM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_sscal(const int n, const float alpha, float * x, const int incx)
{
    INFO("%s_sscal", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SSCAL]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SSCAL];
    
    if (func != 0) {
        (*func)(n, alpha, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SSCAL]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SSCAL, SELECT_SSCAL);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dscal(const int n, const double alpha, double * x, const int incx)
{
    INFO("%s_dscal", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DSCAL]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DSCAL];
    
    if (func != 0) {
        (*func)(n, alpha, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DSCAL]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DSCAL, SELECT_DSCAL);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_cscal(const int n, const void * alpha, void * x, const int incx)
{
    INFO("%s_cscal", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CSCAL]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CSCAL];
    
    if (func != 0) {
        (*func)(n, alpha, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CSCAL]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CSCAL, SELECT_CSCAL);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zscal(const int n, const void * alpha, void * x, const int incx)
{
    INFO("%s_zscal", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZSCAL]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZSCAL];
    
    if (func != 0) {
        (*func)(n, alpha, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZSCAL]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZSCAL, SELECT_ZSCAL);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_csscal(const int n, const float alpha, void * x, const int incx)
{
    INFO("%s_csscal", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CSSCAL]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CSSCAL];
    
    if (func != 0) {
        (*func)(n, alpha, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CSSCAL]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CSSCAL, SELECT_CSSCAL);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zdscal(const int n, const double alpha, void * x, const int incx)
{
    INFO("%s_zdscal", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZDSCAL]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZDSCAL];
    
    if (func != 0) {
        (*func)(n, alpha, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZDSCAL]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZDSCAL, SELECT_ZDSCAL);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_sgemv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const float alpha, const float * a, const int lda, const float * x, const int incx, const float beta, float * y, const int incy)
{
    INFO("%s_sgemv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SGEMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SGEMV];
    
    if (func != 0) {
        (*func)(order, transa, m, n, alpha, a, lda, x, incx, beta, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SGEMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SGEMV, SELECT_SGEMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_sgbmv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const int kl, const int ku, const float alpha, const float * a, const int lda, const float * x, const int incx, const float beta, float * y, const int incy)
{
    INFO("%s_sgbmv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SGBMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SGBMV];
    
    if (func != 0) {
        (*func)(order, transa, m, n, kl, ku, alpha, a, lda, x, incx, beta, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SGBMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SGBMV, SELECT_SGBMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_strmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const float * a, const int lda, float * x, const int incx)
{
    INFO("%s_strmv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_STRMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_STRMV];
    
    if (func != 0) {
        (*func)(order, uplo, transa, diag, n, a, lda, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_STRMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_STRMV, SELECT_STRMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_stbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const float * a, const int lda, float * x, const int incx)
{
    INFO("%s_stbmv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_STBMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_STBMV];
    
    if (func != 0) {
        (*func)(order, uplo, transa, diag, n, k, a, lda, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_STBMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_STBMV, SELECT_STBMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_stpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const float * ap, float * x, const int incx)
{
    INFO("%s_stpmv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_STPMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_STPMV];
    
    if (func != 0) {
        (*func)(order, uplo, transa, diag, n, ap, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_STPMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_STPMV, SELECT_STPMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_strsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const float * a, const int lda, float * x, const int incx)
{
    INFO("%s_strsv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_STRSV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_STRSV];
    
    if (func != 0) {
        (*func)(order, uplo, transa, diag, n, a, lda, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_STRSV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_STRSV, SELECT_STRSV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_stbsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const float * a, const int lda, float * x, const int incx)
{
    INFO("%s_stbsv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_STBSV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_STBSV];
    
    if (func != 0) {
        (*func)(order, uplo, transa, diag, n, k, a, lda, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_STBSV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_STBSV, SELECT_STBSV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_stpsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const float * ap, float * x, const int incx)
{
    INFO("%s_stpsv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_STPSV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_STPSV];
    
    if (func != 0) {
        (*func)(order, uplo, transa, diag, n, ap, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_STPSV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_STPSV, SELECT_STPSV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dgemv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const double alpha, const double * a, const int lda, const double * x, const int incx, const double beta, double * y, const int incy)
{
    INFO("%s_dgemv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DGEMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DGEMV];
    
    if (func != 0) {
        (*func)(order, transa, m, n, alpha, a, lda, x, incx, beta, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DGEMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DGEMV, SELECT_DGEMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dgbmv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const int kl, const int ku, const double alpha, const double * a, const int lda, const double * x, const int incx, const double beta, double * y, const int incy)
{
    INFO("%s_dgbmv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DGBMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DGBMV];
    
    if (func != 0) {
        (*func)(order, transa, m, n, kl, ku, alpha, a, lda, x, incx, beta, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DGBMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DGBMV, SELECT_DGBMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dtrmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const double * a, const int lda, double * x, const int incx)
{
    INFO("%s_dtrmv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DTRMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DTRMV];
    
    if (func != 0) {
        (*func)(order, uplo, transa, diag, n, a, lda, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DTRMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DTRMV, SELECT_DTRMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dtbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const double * a, const int lda, double * x, const int incx)
{
    INFO("%s_dtbmv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DTBMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DTBMV];
    
    if (func != 0) {
        (*func)(order, uplo, transa, diag, n, k, a, lda, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DTBMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DTBMV, SELECT_DTBMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dtpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const double * ap, double * x, const int incx)
{
    INFO("%s_dtpmv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DTPMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DTPMV];
    
    if (func != 0) {
        (*func)(order, uplo, transa, diag, n, ap, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DTPMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DTPMV, SELECT_DTPMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dtrsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const double * a, const int lda, double * x, const int incx)
{
    INFO("%s_dtrsv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DTRSV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DTRSV];
    
    if (func != 0) {
        (*func)(order, uplo, transa, diag, n, a, lda, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DTRSV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DTRSV, SELECT_DTRSV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dtbsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const double * a, const int lda, double * x, const int incx)
{
    INFO("%s_dtbsv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DTBSV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DTBSV];
    
    if (func != 0) {
        (*func)(order, uplo, transa, diag, n, k, a, lda, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DTBSV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DTBSV, SELECT_DTBSV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dtpsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const double * ap, double * x, const int incx)
{
    INFO("%s_dtpsv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DTPSV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DTPSV];
    
    if (func != 0) {
        (*func)(order, uplo, transa, diag, n, ap, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DTPSV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DTPSV, SELECT_DTPSV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_cgemv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy)
{
    INFO("%s_cgemv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CGEMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CGEMV];
    
    if (func != 0) {
        (*func)(order, transa, m, n, alpha, a, lda, x, incx, beta, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CGEMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CGEMV, SELECT_CGEMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_cgbmv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const int kl, const int ku, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy)
{
    INFO("%s_cgbmv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CGBMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CGBMV];
    
    if (func != 0) {
        (*func)(order, transa, m, n, kl, ku, alpha, a, lda, x, incx, beta, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CGBMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CGBMV, SELECT_CGBMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_ctrmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * a, const int lda, void * x, const int incx)
{
    INFO("%s_ctrmv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CTRMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CTRMV];
    
    if (func != 0) {
        (*func)(order, uplo, transa, diag, n, a, lda, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CTRMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CTRMV, SELECT_CTRMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_ctbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const void * a, const int lda, void * x, const int incx)
{
    INFO("%s_ctbmv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CTBMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CTBMV];
    
    if (func != 0) {
        (*func)(order, uplo, transa, diag, n, k, a, lda, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CTBMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CTBMV, SELECT_CTBMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_ctpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * ap, void * x, const int incx)
{
    INFO("%s_ctpmv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CTPMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CTPMV];
    
    if (func != 0) {
        (*func)(order, uplo, transa, diag, n, ap, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CTPMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CTPMV, SELECT_CTPMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_ctrsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * a, const int lda, void * x, const int incx)
{
    INFO("%s_ctrsv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CTRSV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CTRSV];
    
    if (func != 0) {
        (*func)(order, uplo, transa, diag, n, a, lda, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CTRSV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CTRSV, SELECT_CTRSV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_ctbsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const void * a, const int lda, void * x, const int incx)
{
    INFO("%s_ctbsv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CTBSV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CTBSV];
    
    if (func != 0) {
        (*func)(order, uplo, transa, diag, n, k, a, lda, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CTBSV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CTBSV, SELECT_CTBSV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_ctpsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * ap, void * x, const int incx)
{
    INFO("%s_ctpsv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CTPSV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CTPSV];
    
    if (func != 0) {
        (*func)(order, uplo, transa, diag, n, ap, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CTPSV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CTPSV, SELECT_CTPSV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zgemv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy)
{
    INFO("%s_zgemv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZGEMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZGEMV];
    
    if (func != 0) {
        (*func)(order, transa, m, n, alpha, a, lda, x, incx, beta, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZGEMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZGEMV, SELECT_ZGEMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zgbmv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const int kl, const int ku, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy)
{
    INFO("%s_zgbmv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZGBMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZGBMV];
    
    if (func != 0) {
        (*func)(order, transa, m, n, kl, ku, alpha, a, lda, x, incx, beta, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZGBMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZGBMV, SELECT_ZGBMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_ztrmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * a, const int lda, void * x, const int incx)
{
    INFO("%s_ztrmv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZTRMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZTRMV];
    
    if (func != 0) {
        (*func)(order, uplo, transa, diag, n, a, lda, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZTRMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZTRMV, SELECT_ZTRMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_ztbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const void * a, const int lda, void * x, const int incx)
{
    INFO("%s_ztbmv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZTBMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZTBMV];
    
    if (func != 0) {
        (*func)(order, uplo, transa, diag, n, k, a, lda, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZTBMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZTBMV, SELECT_ZTBMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_ztpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * ap, void * x, const int incx)
{
    INFO("%s_ztpmv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZTPMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZTPMV];
    
    if (func != 0) {
        (*func)(order, uplo, transa, diag, n, ap, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZTPMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZTPMV, SELECT_ZTPMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_ztrsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * a, const int lda, void * x, const int incx)
{
    INFO("%s_ztrsv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZTRSV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZTRSV];
    
    if (func != 0) {
        (*func)(order, uplo, transa, diag, n, a, lda, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZTRSV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZTRSV, SELECT_ZTRSV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_ztbsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const void * a, const int lda, void * x, const int incx)
{
    INFO("%s_ztbsv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZTBSV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZTBSV];
    
    if (func != 0) {
        (*func)(order, uplo, transa, diag, n, k, a, lda, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZTBSV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZTBSV, SELECT_ZTBSV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_ztpsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * ap, void * x, const int incx)
{
    INFO("%s_ztpsv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZTPSV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZTPSV];
    
    if (func != 0) {
        (*func)(order, uplo, transa, diag, n, ap, x, incx);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZTPSV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZTPSV, SELECT_ZTPSV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_ssymv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * a, const int lda, const float * x, const int incx, const float beta, float * y, const int incy)
{
    INFO("%s_ssymv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SSYMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SSYMV];
    
    if (func != 0) {
        (*func)(order, uplo, n, alpha, a, lda, x, incx, beta, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SSYMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SSYMV, SELECT_SSYMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_ssbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const int k, const float alpha, const float * a, const int lda, const float * x, const int incx, const float beta, float * y, const int incy)
{
    INFO("%s_ssbmv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SSBMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SSBMV];
    
    if (func != 0) {
        (*func)(order, uplo, n, k, alpha, a, lda, x, incx, beta, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SSBMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SSBMV, SELECT_SSBMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_sspmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * ap, const float * x, const int incx, const float beta, float * y, const int incy)
{
    INFO("%s_sspmv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SSPMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SSPMV];
    
    if (func != 0) {
        (*func)(order, uplo, n, alpha, ap, x, incx, beta, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SSPMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SSPMV, SELECT_SSPMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_sger(const liftracc_order_t order, const int m, const int n, const float alpha, const float * x, const int incx, const float * y, const int incy, float * a, const int lda)
{
    INFO("%s_sger", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SGER]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SGER];
    
    if (func != 0) {
        (*func)(order, m, n, alpha, x, incx, y, incy, a, lda);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SGER]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SGER, SELECT_SGER);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_ssyr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * x, const int incx, float * a, const int lda)
{
    INFO("%s_ssyr", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SSYR]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SSYR];
    
    if (func != 0) {
        (*func)(order, uplo, n, alpha, x, incx, a, lda);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SSYR]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SSYR, SELECT_SSYR);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_sspr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * x, const int incx, float * ap)
{
    INFO("%s_sspr", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SSPR]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SSPR];
    
    if (func != 0) {
        (*func)(order, uplo, n, alpha, x, incx, ap);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SSPR]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SSPR, SELECT_SSPR);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_ssyr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * x, const int incx, const float * y, const int incy, float * a, const int lda)
{
    INFO("%s_ssyr2", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SSYR2]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SSYR2];
    
    if (func != 0) {
        (*func)(order, uplo, n, alpha, x, incx, y, incy, a, lda);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SSYR2]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SSYR2, SELECT_SSYR2);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_sspr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * x, const int incx, const float * y, const int incy, float * a)
{
    INFO("%s_sspr2", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SSPR2]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SSPR2];
    
    if (func != 0) {
        (*func)(order, uplo, n, alpha, x, incx, y, incy, a);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SSPR2]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SSPR2, SELECT_SSPR2);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dsymv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * a, const int lda, const double * x, const int incx, const double beta, double * y, const int incy)
{
    INFO("%s_dsymv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DSYMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DSYMV];
    
    if (func != 0) {
        (*func)(order, uplo, n, alpha, a, lda, x, incx, beta, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DSYMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DSYMV, SELECT_DSYMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dsbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const int k, const double alpha, const double * a, const int lda, const double * x, const int incx, const double beta, double * y, const int incy)
{
    INFO("%s_dsbmv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DSBMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DSBMV];
    
    if (func != 0) {
        (*func)(order, uplo, n, k, alpha, a, lda, x, incx, beta, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DSBMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DSBMV, SELECT_DSBMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dspmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * ap, const double * x, const int incx, const double beta, double * y, const int incy)
{
    INFO("%s_dspmv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DSPMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DSPMV];
    
    if (func != 0) {
        (*func)(order, uplo, n, alpha, ap, x, incx, beta, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DSPMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DSPMV, SELECT_DSPMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dger(const liftracc_order_t order, const int m, const int n, const double alpha, const double * x, const int incx, const double * y, const int incy, double * a, const int lda)
{
    INFO("%s_dger", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DGER]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DGER];
    
    if (func != 0) {
        (*func)(order, m, n, alpha, x, incx, y, incy, a, lda);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DGER]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DGER, SELECT_DGER);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dsyr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * x, const int incx, double * a, const int lda)
{
    INFO("%s_dsyr", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DSYR]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DSYR];
    
    if (func != 0) {
        (*func)(order, uplo, n, alpha, x, incx, a, lda);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DSYR]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DSYR, SELECT_DSYR);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dspr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * x, const int incx, double * ap)
{
    INFO("%s_dspr", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DSPR]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DSPR];
    
    if (func != 0) {
        (*func)(order, uplo, n, alpha, x, incx, ap);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DSPR]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DSPR, SELECT_DSPR);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dsyr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * x, const int incx, const double * y, const int incy, double * a, const int lda)
{
    INFO("%s_dsyr2", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DSYR2]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DSYR2];
    
    if (func != 0) {
        (*func)(order, uplo, n, alpha, x, incx, y, incy, a, lda);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DSYR2]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DSYR2, SELECT_DSYR2);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dspr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * x, const int incx, const double * y, const int incy, double * a)
{
    INFO("%s_dspr2", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DSPR2]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DSPR2];
    
    if (func != 0) {
        (*func)(order, uplo, n, alpha, x, incx, y, incy, a);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DSPR2]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DSPR2, SELECT_DSPR2);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_chemv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy)
{
    INFO("%s_chemv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CHEMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CHEMV];
    
    if (func != 0) {
        (*func)(order, uplo, n, alpha, a, lda, x, incx, beta, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CHEMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CHEMV, SELECT_CHEMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_chbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const int k, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy)
{
    INFO("%s_chbmv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CHBMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CHBMV];
    
    if (func != 0) {
        (*func)(order, uplo, n, k, alpha, a, lda, x, incx, beta, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CHBMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CHBMV, SELECT_CHBMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_chpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * ap, const void * x, const int incx, const void * beta, void * y, const int incy)
{
    INFO("%s_chpmv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CHPMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CHPMV];
    
    if (func != 0) {
        (*func)(order, uplo, n, alpha, ap, x, incx, beta, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CHPMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CHPMV, SELECT_CHPMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_cgeru(const liftracc_order_t order, const int m, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda)
{
    INFO("%s_cgeru", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CGERU]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CGERU];
    
    if (func != 0) {
        (*func)(order, m, n, alpha, x, incx, y, incy, a, lda);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CGERU]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CGERU, SELECT_CGERU);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_cgerc(const liftracc_order_t order, const int m, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda)
{
    INFO("%s_cgerc", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CGERC]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CGERC];
    
    if (func != 0) {
        (*func)(order, m, n, alpha, x, incx, y, incy, a, lda);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CGERC]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CGERC, SELECT_CGERC);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_cher(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const void * x, const int incx, void * a, const int lda)
{
    INFO("%s_cher", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CHER]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CHER];
    
    if (func != 0) {
        (*func)(order, uplo, n, alpha, x, incx, a, lda);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CHER]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CHER, SELECT_CHER);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_chpr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const void * x, const int incx, void * a)
{
    INFO("%s_chpr", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CHPR]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CHPR];
    
    if (func != 0) {
        (*func)(order, uplo, n, alpha, x, incx, a);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CHPR]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CHPR, SELECT_CHPR);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_cher2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda)
{
    INFO("%s_cher2", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CHER2]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CHER2];
    
    if (func != 0) {
        (*func)(order, uplo, n, alpha, x, incx, y, incy, a, lda);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CHER2]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CHER2, SELECT_CHER2);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_chpr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * ap)
{
    INFO("%s_chpr2", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CHPR2]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CHPR2];
    
    if (func != 0) {
        (*func)(order, uplo, n, alpha, x, incx, y, incy, ap);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CHPR2]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CHPR2, SELECT_CHPR2);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zhemv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy)
{
    INFO("%s_zhemv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZHEMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZHEMV];
    
    if (func != 0) {
        (*func)(order, uplo, n, alpha, a, lda, x, incx, beta, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZHEMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZHEMV, SELECT_ZHEMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zhbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const int k, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy)
{
    INFO("%s_zhbmv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZHBMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZHBMV];
    
    if (func != 0) {
        (*func)(order, uplo, n, k, alpha, a, lda, x, incx, beta, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZHBMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZHBMV, SELECT_ZHBMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zhpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * ap, const void * x, const int incx, const void * beta, void * y, const int incy)
{
    INFO("%s_zhpmv", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZHPMV]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZHPMV];
    
    if (func != 0) {
        (*func)(order, uplo, n, alpha, ap, x, incx, beta, y, incy);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZHPMV]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZHPMV, SELECT_ZHPMV);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zgeru(const liftracc_order_t order, const int m, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda)
{
    INFO("%s_zgeru", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZGERU]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZGERU];
    
    if (func != 0) {
        (*func)(order, m, n, alpha, x, incx, y, incy, a, lda);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZGERU]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZGERU, SELECT_ZGERU);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zgerc(const liftracc_order_t order, const int m, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda)
{
    INFO("%s_zgerc", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZGERC]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZGERC];
    
    if (func != 0) {
        (*func)(order, m, n, alpha, x, incx, y, incy, a, lda);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZGERC]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZGERC, SELECT_ZGERC);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zher(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const void * x, const int incx, void * a, const int lda)
{
    INFO("%s_zher", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZHER]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZHER];
    
    if (func != 0) {
        (*func)(order, uplo, n, alpha, x, incx, a, lda);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZHER]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZHER, SELECT_ZHER);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zhpr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const void * x, const int incx, void * a)
{
    INFO("%s_zhpr", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZHPR]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZHPR];
    
    if (func != 0) {
        (*func)(order, uplo, n, alpha, x, incx, a);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZHPR]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZHPR, SELECT_ZHPR);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zher2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda)
{
    INFO("%s_zher2", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZHER2]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZHER2];
    
    if (func != 0) {
        (*func)(order, uplo, n, alpha, x, incx, y, incy, a, lda);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZHER2]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZHER2, SELECT_ZHER2);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zhpr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * ap)
{
    INFO("%s_zhpr2", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZHPR2]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZHPR2];
    
    if (func != 0) {
        (*func)(order, uplo, n, alpha, x, incx, y, incy, ap);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZHPR2]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZHPR2, SELECT_ZHPR2);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_sgemm(const liftracc_order_t order, const liftracc_transpose_t transa, const liftracc_transpose_t transb, const int m, const int n, const int k, const float alpha, const float * a, const int lda, const float * b, const int ldb, const float beta, float * c, const int ldc)
{
    INFO("%s_sgemm", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SGEMM]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SGEMM];
    
    if (func != 0) {
        (*func)(order, transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SGEMM]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SGEMM, SELECT_SGEMM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_ssymm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const float alpha, const float * a, const int lda, const float * b, const int ldb, const float beta, float * c, const int ldc)
{
    INFO("%s_ssymm", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SSYMM]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SSYMM];
    
    if (func != 0) {
        (*func)(order, side, uplo, m, n, alpha, a, lda, b, ldb, beta, c, ldc);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SSYMM]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SSYMM, SELECT_SSYMM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_ssyrk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const float alpha, const float * a, const int lda, const float beta, float * c, const int ldc)
{
    INFO("%s_ssyrk", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SSYRK]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SSYRK];
    
    if (func != 0) {
        (*func)(order, uplo, trans, n, k, alpha, a, lda, beta, c, ldc);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SSYRK]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SSYRK, SELECT_SSYRK);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_ssyr2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const float alpha, const float * a, const int lda, const float * b, const int ldb, const float beta, float * c, const int ldc)
{
    INFO("%s_ssyr2k", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_SSYR2K]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_SSYR2K];
    
    if (func != 0) {
        (*func)(order, uplo, trans, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_SSYR2K]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_SSYR2K, SELECT_SSYR2K);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_strmm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const float alpha, const float * a, const int lda, float * b, const int ldb)
{
    INFO("%s_strmm", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_STRMM]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_STRMM];
    
    if (func != 0) {
        (*func)(order, side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_STRMM]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_STRMM, SELECT_STRMM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_strsm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const float alpha, const float * a, const int lda, float * b, const int ldb)
{
    INFO("%s_strsm", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_STRSM]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_STRSM];
    
    if (func != 0) {
        (*func)(order, side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_STRSM]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_STRSM, SELECT_STRSM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dgemm(const liftracc_order_t order, const liftracc_transpose_t transa, const liftracc_transpose_t transb, const int m, const int n, const int k, const double alpha, const double * a, const int lda, const double * b, const int ldb, const double beta, double * c, const int ldc)
{
    INFO("%s_dgemm", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DGEMM]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DGEMM];
    
    if (func != 0) {
        (*func)(order, transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DGEMM]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DGEMM, SELECT_DGEMM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dsymm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const double alpha, const double * a, const int lda, const double * b, const int ldb, const double beta, double * c, const int ldc)
{
    INFO("%s_dsymm", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DSYMM]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DSYMM];
    
    if (func != 0) {
        (*func)(order, side, uplo, m, n, alpha, a, lda, b, ldb, beta, c, ldc);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DSYMM]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DSYMM, SELECT_DSYMM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dsyrk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const double alpha, const double * a, const int lda, const double beta, double * c, const int ldc)
{
    INFO("%s_dsyrk", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DSYRK]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DSYRK];
    
    if (func != 0) {
        (*func)(order, uplo, trans, n, k, alpha, a, lda, beta, c, ldc);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DSYRK]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DSYRK, SELECT_DSYRK);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dsyr2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const double alpha, const double * a, const int lda, const double * b, const int ldb, const double beta, double * c, const int ldc)
{
    INFO("%s_dsyr2k", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DSYR2K]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DSYR2K];
    
    if (func != 0) {
        (*func)(order, uplo, trans, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DSYR2K]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DSYR2K, SELECT_DSYR2K);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dtrmm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const double alpha, const double * a, const int lda, double * b, const int ldb)
{
    INFO("%s_dtrmm", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DTRMM]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DTRMM];
    
    if (func != 0) {
        (*func)(order, side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DTRMM]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DTRMM, SELECT_DTRMM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_dtrsm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const double alpha, const double * a, const int lda, double * b, const int ldb)
{
    INFO("%s_dtrsm", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_DTRSM]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_DTRSM];
    
    if (func != 0) {
        (*func)(order, side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_DTRSM]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_DTRSM, SELECT_DTRSM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_cgemm(const liftracc_order_t order, const liftracc_transpose_t transa, const liftracc_transpose_t transb, const int m, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc)
{
    INFO("%s_cgemm", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CGEMM]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CGEMM];
    
    if (func != 0) {
        (*func)(order, transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CGEMM]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CGEMM, SELECT_CGEMM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_csymm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc)
{
    INFO("%s_csymm", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CSYMM]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CSYMM];
    
    if (func != 0) {
        (*func)(order, side, uplo, m, n, alpha, a, lda, b, ldb, beta, c, ldc);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CSYMM]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CSYMM, SELECT_CSYMM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_csyrk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * beta, void * c, const int ldc)
{
    INFO("%s_csyrk", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CSYRK]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CSYRK];
    
    if (func != 0) {
        (*func)(order, uplo, trans, n, k, alpha, a, lda, beta, c, ldc);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CSYRK]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CSYRK, SELECT_CSYRK);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_csyr2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc)
{
    INFO("%s_csyr2k", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CSYR2K]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CSYR2K];
    
    if (func != 0) {
        (*func)(order, uplo, trans, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CSYR2K]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CSYR2K, SELECT_CSYR2K);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_ctrmm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const void * alpha, const void * a, const int lda, void * b, const int ldb)
{
    INFO("%s_ctrmm", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CTRMM]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CTRMM];
    
    if (func != 0) {
        (*func)(order, side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CTRMM]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CTRMM, SELECT_CTRMM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_ctrsm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const void * alpha, const void * a, const int lda, void * b, const int ldb)
{
    INFO("%s_ctrsm", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CTRSM]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CTRSM];
    
    if (func != 0) {
        (*func)(order, side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CTRSM]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CTRSM, SELECT_CTRSM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zgemm(const liftracc_order_t order, const liftracc_transpose_t transa, const liftracc_transpose_t transb, const int m, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc)
{
    INFO("%s_zgemm", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZGEMM]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZGEMM];
    
    if (func != 0) {
        (*func)(order, transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZGEMM]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZGEMM, SELECT_ZGEMM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zsymm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc)
{
    INFO("%s_zsymm", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZSYMM]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZSYMM];
    
    if (func != 0) {
        (*func)(order, side, uplo, m, n, alpha, a, lda, b, ldb, beta, c, ldc);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZSYMM]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZSYMM, SELECT_ZSYMM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zsyrk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * beta, void * c, const int ldc)
{
    INFO("%s_zsyrk", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZSYRK]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZSYRK];
    
    if (func != 0) {
        (*func)(order, uplo, trans, n, k, alpha, a, lda, beta, c, ldc);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZSYRK]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZSYRK, SELECT_ZSYRK);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zsyr2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc)
{
    INFO("%s_zsyr2k", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZSYR2K]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZSYR2K];
    
    if (func != 0) {
        (*func)(order, uplo, trans, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZSYR2K]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZSYR2K, SELECT_ZSYR2K);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_ztrmm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const void * alpha, const void * a, const int lda, void * b, const int ldb)
{
    INFO("%s_ztrmm", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZTRMM]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZTRMM];
    
    if (func != 0) {
        (*func)(order, side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZTRMM]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZTRMM, SELECT_ZTRMM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_ztrsm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const void * alpha, const void * a, const int lda, void * b, const int ldb)
{
    INFO("%s_ztrsm", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZTRSM]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZTRSM];
    
    if (func != 0) {
        (*func)(order, side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZTRSM]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZTRSM, SELECT_ZTRSM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_chemm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc)
{
    INFO("%s_chemm", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CHEMM]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CHEMM];
    
    if (func != 0) {
        (*func)(order, side, uplo, m, n, alpha, a, lda, b, ldb, beta, c, ldc);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CHEMM]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CHEMM, SELECT_CHEMM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_cherk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const float alpha, const void * a, const int lda, const float beta, void * c, const int ldc)
{
    INFO("%s_cherk", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CHERK]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CHERK];
    
    if (func != 0) {
        (*func)(order, uplo, trans, n, k, alpha, a, lda, beta, c, ldc);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CHERK]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CHERK, SELECT_CHERK);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_cher2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const float beta, void * c, const int ldc)
{
    INFO("%s_cher2k", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_CHER2K]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_CHER2K];
    
    if (func != 0) {
        (*func)(order, uplo, trans, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_CHER2K]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_CHER2K, SELECT_CHER2K);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zhemm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc)
{
    INFO("%s_zhemm", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZHEMM]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZHEMM];
    
    if (func != 0) {
        (*func)(order, side, uplo, m, n, alpha, a, lda, b, ldb, beta, c, ldc);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZHEMM]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZHEMM, SELECT_ZHEMM);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zherk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const double alpha, const void * a, const int lda, const double beta, void * c, const int ldc)
{
    INFO("%s_zherk", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZHERK]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZHERK];
    
    if (func != 0) {
        (*func)(order, uplo, trans, n, k, alpha, a, lda, beta, c, ldc);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZHERK]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZHERK, SELECT_ZHERK);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_zher2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const double beta, void * c, const int ldc)
{
    INFO("%s_zher2k", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_ZHER2K]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_ZHER2K];
    
    if (func != 0) {
        (*func)(order, uplo, trans, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_ZHER2K]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_

    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_ZHER2K, SELECT_ZHER2K);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


void liftracc_plugin_xerbla(int p, const char * rout, const char * form)
{
    INFO("%s_xerbla", liftracc_plugin_info.name);
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_start(&(function_profiling_data[LIFTRACC_FUNCTION_XERBLA]));
#endif /* _LIFTRACC_PROFILING_ */

    void (*func)();
    
    *(void **) (&func) = liftracc_plugin_fptr[CBLAS_FUNCTION_XERBLA];
    
    if (func != 0) {
        (*func)(p, rout, form);
    }
#if _LIFTRACC_PROFILING_ == 3
    liftracc_function_timing_stop(&(function_profiling_data[LIFTRACC_FUNCTION_XERBLA]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_
    int n = 0;
    set_decision_data(&decision_data[0], &function_profiling_data[0], n, LIFTRACC_FUNCTION_XERBLA, SELECT_XERBLA);
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

}


