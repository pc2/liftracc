
/**
 * \file liftracc_autogen.c
 * \brief [generated file]
 */

/* This file is generated automatically, do not edit manually! */

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <limits.h>

#include "liftracc.h"
#include "liftracc_logging.h"
#include "liftracc_selector.h"

#if _LIFTRACC_PROFILING_ > 0
#include "liftracc_profiling.h"
extern profiling_data_t liftracc_function_profiling_data[];
#endif

liftracc_selector_problem_info_t pinfo = { };



/***
 * SDSDOT
 */

float liftracc_sdsdot(const int n, const float alpha, const float * x, const int incx, const float * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SDSDOT]));
#endif /* _LIFTRACC_PROFILING_ */
    float (*liftracc_plugin_func)();
    float ret = 0.0;
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SDSDOT, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_sdsdot");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        ret = (*liftracc_plugin_func)(n, alpha, x, incx, y, incy);
    } else
        ERROR("liftracc_sdsdot not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SDSDOT]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;
}

float liftracc_sdsdot_(const int * n, const float * alpha, const float * x, const int * incx, const float * y, const int * incy)
{
    return liftracc_sdsdot(*n, *alpha, x, *incx, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_sdsdot_) sdsdot __attribute__ ((alias("liftracc_sdsdot_"))); */
/* __typeof__ (liftracc_sdsdot_) sdsdot_ __attribute__ ((alias("liftracc_sdsdot_"))); */
__typeof__ (liftracc_sdsdot_) SDSDOT __attribute__ ((alias("liftracc_sdsdot_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_sdsdot) cblas_sdsdot __attribute__ ((alias("liftracc_sdsdot")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DSDOT
 */

double liftracc_dsdot(const int n, const float * x, const int incx, const float * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSDOT]));
#endif /* _LIFTRACC_PROFILING_ */
    double (*liftracc_plugin_func)();
    double ret = 0.0;
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DSDOT, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dsdot");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        ret = (*liftracc_plugin_func)(n, x, incx, y, incy);
    } else
        ERROR("liftracc_dsdot not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSDOT]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;
}

double liftracc_dsdot_(const int * n, const float * x, const int * incx, const float * y, const int * incy)
{
    return liftracc_dsdot(*n, x, *incx, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dsdot_) dsdot __attribute__ ((alias("liftracc_dsdot_"))); */
/* __typeof__ (liftracc_dsdot_) dsdot_ __attribute__ ((alias("liftracc_dsdot_"))); */
__typeof__ (liftracc_dsdot_) DSDOT __attribute__ ((alias("liftracc_dsdot_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dsdot) cblas_dsdot __attribute__ ((alias("liftracc_dsdot")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SDOT
 */

float liftracc_sdot(const int n, const float * x, const int incx, const float * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SDOT]));
#endif /* _LIFTRACC_PROFILING_ */
    float (*liftracc_plugin_func)();
    float ret = 0.0;
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SDOT, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_sdot");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        ret = (*liftracc_plugin_func)(n, x, incx, y, incy);
    } else
        ERROR("liftracc_sdot not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SDOT]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;
}

float liftracc_sdot_(const int * n, const float * x, const int * incx, const float * y, const int * incy)
{
    return liftracc_sdot(*n, x, *incx, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_sdot_) sdot __attribute__ ((alias("liftracc_sdot_"))); */
/* __typeof__ (liftracc_sdot_) sdot_ __attribute__ ((alias("liftracc_sdot_"))); */
__typeof__ (liftracc_sdot_) SDOT __attribute__ ((alias("liftracc_sdot_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_sdot) cblas_sdot __attribute__ ((alias("liftracc_sdot")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DDOT
 */

double liftracc_ddot(const int n, const double * x, const int incx, const double * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DDOT]));
#endif /* _LIFTRACC_PROFILING_ */
    double (*liftracc_plugin_func)();
    double ret = 0.0;
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DDOT, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ddot");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        ret = (*liftracc_plugin_func)(n, x, incx, y, incy);
    } else
        ERROR("liftracc_ddot not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DDOT]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;
}

double liftracc_ddot_(const int * n, const double * x, const int * incx, const double * y, const int * incy)
{
    return liftracc_ddot(*n, x, *incx, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ddot_) ddot __attribute__ ((alias("liftracc_ddot_"))); */
/* __typeof__ (liftracc_ddot_) ddot_ __attribute__ ((alias("liftracc_ddot_"))); */
__typeof__ (liftracc_ddot_) DDOT __attribute__ ((alias("liftracc_ddot_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ddot) cblas_ddot __attribute__ ((alias("liftracc_ddot")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CDOTU_SUB
 */

void liftracc_cdotu_sub(const int n, const void * x, const int incx, const void * y, const int incy, void * dotu)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CDOTU_SUB]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CDOTU_SUB, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_cdotu_sub");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, x, incx, y, incy, dotu);
    } else
        ERROR("liftracc_cdotu_sub not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CDOTU_SUB]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_cdotu_sub_(const int * n, const void * x, const int * incx, const void * y, const int * incy, void * dotu)
{
    liftracc_cdotu_sub(*n, x, *incx, y, *incy, dotu);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_cdotu_sub_) cdotu_sub __attribute__ ((alias("liftracc_cdotu_sub_"))); */
/* __typeof__ (liftracc_cdotu_sub_) cdotu_sub_ __attribute__ ((alias("liftracc_cdotu_sub_"))); */
__typeof__ (liftracc_cdotu_sub_) CDOTU_SUB __attribute__ ((alias("liftracc_cdotu_sub_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_cdotu_sub) cblas_cdotu_sub __attribute__ ((alias("liftracc_cdotu_sub")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CDOTC_SUB
 */

void liftracc_cdotc_sub(const int n, const void * x, const int incx, const void * y, const int incy, void * dotc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CDOTC_SUB]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CDOTC_SUB, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_cdotc_sub");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, x, incx, y, incy, dotc);
    } else
        ERROR("liftracc_cdotc_sub not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CDOTC_SUB]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_cdotc_sub_(const int * n, const void * x, const int * incx, const void * y, const int * incy, void * dotc)
{
    liftracc_cdotc_sub(*n, x, *incx, y, *incy, dotc);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_cdotc_sub_) cdotc_sub __attribute__ ((alias("liftracc_cdotc_sub_"))); */
/* __typeof__ (liftracc_cdotc_sub_) cdotc_sub_ __attribute__ ((alias("liftracc_cdotc_sub_"))); */
__typeof__ (liftracc_cdotc_sub_) CDOTC_SUB __attribute__ ((alias("liftracc_cdotc_sub_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_cdotc_sub) cblas_cdotc_sub __attribute__ ((alias("liftracc_cdotc_sub")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZDOTU_SUB
 */

void liftracc_zdotu_sub(const int n, const void * x, const int incx, const void * y, const int incy, void * dotu)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZDOTU_SUB]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZDOTU_SUB, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zdotu_sub");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, x, incx, y, incy, dotu);
    } else
        ERROR("liftracc_zdotu_sub not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZDOTU_SUB]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zdotu_sub_(const int * n, const void * x, const int * incx, const void * y, const int * incy, void * dotu)
{
    liftracc_zdotu_sub(*n, x, *incx, y, *incy, dotu);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zdotu_sub_) zdotu_sub __attribute__ ((alias("liftracc_zdotu_sub_"))); */
/* __typeof__ (liftracc_zdotu_sub_) zdotu_sub_ __attribute__ ((alias("liftracc_zdotu_sub_"))); */
__typeof__ (liftracc_zdotu_sub_) ZDOTU_SUB __attribute__ ((alias("liftracc_zdotu_sub_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zdotu_sub) cblas_zdotu_sub __attribute__ ((alias("liftracc_zdotu_sub")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZDOTC_SUB
 */

void liftracc_zdotc_sub(const int n, const void * x, const int incx, const void * y, const int incy, void * dotc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZDOTC_SUB]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZDOTC_SUB, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zdotc_sub");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, x, incx, y, incy, dotc);
    } else
        ERROR("liftracc_zdotc_sub not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZDOTC_SUB]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zdotc_sub_(const int * n, const void * x, const int * incx, const void * y, const int * incy, void * dotc)
{
    liftracc_zdotc_sub(*n, x, *incx, y, *incy, dotc);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zdotc_sub_) zdotc_sub __attribute__ ((alias("liftracc_zdotc_sub_"))); */
/* __typeof__ (liftracc_zdotc_sub_) zdotc_sub_ __attribute__ ((alias("liftracc_zdotc_sub_"))); */
__typeof__ (liftracc_zdotc_sub_) ZDOTC_SUB __attribute__ ((alias("liftracc_zdotc_sub_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zdotc_sub) cblas_zdotc_sub __attribute__ ((alias("liftracc_zdotc_sub")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SNRM2
 */

float liftracc_snrm2(const int n, const float * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SNRM2]));
#endif /* _LIFTRACC_PROFILING_ */
    float (*liftracc_plugin_func)();
    float ret = 0.0;
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SNRM2, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_snrm2");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        ret = (*liftracc_plugin_func)(n, x, incx);
    } else
        ERROR("liftracc_snrm2 not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SNRM2]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;
}

float liftracc_snrm2_(const int * n, const float * x, const int * incx)
{
    return liftracc_snrm2(*n, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_snrm2_) snrm2 __attribute__ ((alias("liftracc_snrm2_"))); */
/* __typeof__ (liftracc_snrm2_) snrm2_ __attribute__ ((alias("liftracc_snrm2_"))); */
__typeof__ (liftracc_snrm2_) SNRM2 __attribute__ ((alias("liftracc_snrm2_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_snrm2) cblas_snrm2 __attribute__ ((alias("liftracc_snrm2")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SASUM
 */

float liftracc_sasum(const int n, const float * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SASUM]));
#endif /* _LIFTRACC_PROFILING_ */
    float (*liftracc_plugin_func)();
    float ret = 0.0;
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SASUM, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_sasum");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        ret = (*liftracc_plugin_func)(n, x, incx);
    } else
        ERROR("liftracc_sasum not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SASUM]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;
}

float liftracc_sasum_(const int * n, const float * x, const int * incx)
{
    return liftracc_sasum(*n, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_sasum_) sasum __attribute__ ((alias("liftracc_sasum_"))); */
/* __typeof__ (liftracc_sasum_) sasum_ __attribute__ ((alias("liftracc_sasum_"))); */
__typeof__ (liftracc_sasum_) SASUM __attribute__ ((alias("liftracc_sasum_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_sasum) cblas_sasum __attribute__ ((alias("liftracc_sasum")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DNRM2
 */

double liftracc_dnrm2(const int n, const double * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DNRM2]));
#endif /* _LIFTRACC_PROFILING_ */
    double (*liftracc_plugin_func)();
    double ret = 0.0;
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DNRM2, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dnrm2");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        ret = (*liftracc_plugin_func)(n, x, incx);
    } else
        ERROR("liftracc_dnrm2 not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DNRM2]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;
}

double liftracc_dnrm2_(const int * n, const double * x, const int * incx)
{
    return liftracc_dnrm2(*n, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dnrm2_) dnrm2 __attribute__ ((alias("liftracc_dnrm2_"))); */
/* __typeof__ (liftracc_dnrm2_) dnrm2_ __attribute__ ((alias("liftracc_dnrm2_"))); */
__typeof__ (liftracc_dnrm2_) DNRM2 __attribute__ ((alias("liftracc_dnrm2_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dnrm2) cblas_dnrm2 __attribute__ ((alias("liftracc_dnrm2")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DASUM
 */

double liftracc_dasum(const int n, const double * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DASUM]));
#endif /* _LIFTRACC_PROFILING_ */
    double (*liftracc_plugin_func)();
    double ret = 0.0;
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DASUM, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dasum");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        ret = (*liftracc_plugin_func)(n, x, incx);
    } else
        ERROR("liftracc_dasum not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DASUM]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;
}

double liftracc_dasum_(const int * n, const double * x, const int * incx)
{
    return liftracc_dasum(*n, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dasum_) dasum __attribute__ ((alias("liftracc_dasum_"))); */
/* __typeof__ (liftracc_dasum_) dasum_ __attribute__ ((alias("liftracc_dasum_"))); */
__typeof__ (liftracc_dasum_) DASUM __attribute__ ((alias("liftracc_dasum_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dasum) cblas_dasum __attribute__ ((alias("liftracc_dasum")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SCNRM2
 */

float liftracc_scnrm2(const int n, const void * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SCNRM2]));
#endif /* _LIFTRACC_PROFILING_ */
    float (*liftracc_plugin_func)();
    float ret = 0.0;
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SCNRM2, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_scnrm2");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        ret = (*liftracc_plugin_func)(n, x, incx);
    } else
        ERROR("liftracc_scnrm2 not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SCNRM2]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;
}

float liftracc_scnrm2_(const int * n, const void * x, const int * incx)
{
    return liftracc_scnrm2(*n, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_scnrm2_) scnrm2 __attribute__ ((alias("liftracc_scnrm2_"))); */
/* __typeof__ (liftracc_scnrm2_) scnrm2_ __attribute__ ((alias("liftracc_scnrm2_"))); */
__typeof__ (liftracc_scnrm2_) SCNRM2 __attribute__ ((alias("liftracc_scnrm2_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_scnrm2) cblas_scnrm2 __attribute__ ((alias("liftracc_scnrm2")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SCASUM
 */

float liftracc_scasum(const int n, const void * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SCASUM]));
#endif /* _LIFTRACC_PROFILING_ */
    float (*liftracc_plugin_func)();
    float ret = 0.0;
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SCASUM, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_scasum");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        ret = (*liftracc_plugin_func)(n, x, incx);
    } else
        ERROR("liftracc_scasum not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SCASUM]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;
}

float liftracc_scasum_(const int * n, const void * x, const int * incx)
{
    return liftracc_scasum(*n, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_scasum_) scasum __attribute__ ((alias("liftracc_scasum_"))); */
/* __typeof__ (liftracc_scasum_) scasum_ __attribute__ ((alias("liftracc_scasum_"))); */
__typeof__ (liftracc_scasum_) SCASUM __attribute__ ((alias("liftracc_scasum_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_scasum) cblas_scasum __attribute__ ((alias("liftracc_scasum")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DZNRM2
 */

double liftracc_dznrm2(const int n, const void * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DZNRM2]));
#endif /* _LIFTRACC_PROFILING_ */
    double (*liftracc_plugin_func)();
    double ret = 0.0;
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DZNRM2, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dznrm2");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        ret = (*liftracc_plugin_func)(n, x, incx);
    } else
        ERROR("liftracc_dznrm2 not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DZNRM2]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;
}

double liftracc_dznrm2_(const int * n, const void * x, const int * incx)
{
    return liftracc_dznrm2(*n, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dznrm2_) dznrm2 __attribute__ ((alias("liftracc_dznrm2_"))); */
/* __typeof__ (liftracc_dznrm2_) dznrm2_ __attribute__ ((alias("liftracc_dznrm2_"))); */
__typeof__ (liftracc_dznrm2_) DZNRM2 __attribute__ ((alias("liftracc_dznrm2_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dznrm2) cblas_dznrm2 __attribute__ ((alias("liftracc_dznrm2")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DZASUM
 */

double liftracc_dzasum(const int n, const void * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DZASUM]));
#endif /* _LIFTRACC_PROFILING_ */
    double (*liftracc_plugin_func)();
    double ret = 0.0;
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DZASUM, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dzasum");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        ret = (*liftracc_plugin_func)(n, x, incx);
    } else
        ERROR("liftracc_dzasum not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DZASUM]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;
}

double liftracc_dzasum_(const int * n, const void * x, const int * incx)
{
    return liftracc_dzasum(*n, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dzasum_) dzasum __attribute__ ((alias("liftracc_dzasum_"))); */
/* __typeof__ (liftracc_dzasum_) dzasum_ __attribute__ ((alias("liftracc_dzasum_"))); */
__typeof__ (liftracc_dzasum_) DZASUM __attribute__ ((alias("liftracc_dzasum_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dzasum) cblas_dzasum __attribute__ ((alias("liftracc_dzasum")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ISAMAX
 */

liftracc_index_t liftracc_isamax(const int n, const float * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ISAMAX]));
#endif /* _LIFTRACC_PROFILING_ */
    liftracc_index_t (*liftracc_plugin_func)();
    liftracc_index_t ret = 0.0;
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ISAMAX, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_isamax");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        ret = (*liftracc_plugin_func)(n, x, incx);
    } else
        ERROR("liftracc_isamax not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ISAMAX]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;
}

liftracc_index_t liftracc_isamax_(const int * n, const float * x, const int * incx)
{
    return liftracc_isamax(*n, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_isamax_) isamax __attribute__ ((alias("liftracc_isamax_"))); */
/* __typeof__ (liftracc_isamax_) isamax_ __attribute__ ((alias("liftracc_isamax_"))); */
__typeof__ (liftracc_isamax_) ISAMAX __attribute__ ((alias("liftracc_isamax_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_isamax) cblas_isamax __attribute__ ((alias("liftracc_isamax")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * IDAMAX
 */

liftracc_index_t liftracc_idamax(const int n, const double * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_IDAMAX]));
#endif /* _LIFTRACC_PROFILING_ */
    liftracc_index_t (*liftracc_plugin_func)();
    liftracc_index_t ret = 0.0;
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_IDAMAX, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_idamax");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        ret = (*liftracc_plugin_func)(n, x, incx);
    } else
        ERROR("liftracc_idamax not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_IDAMAX]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;
}

liftracc_index_t liftracc_idamax_(const int * n, const double * x, const int * incx)
{
    return liftracc_idamax(*n, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_idamax_) idamax __attribute__ ((alias("liftracc_idamax_"))); */
/* __typeof__ (liftracc_idamax_) idamax_ __attribute__ ((alias("liftracc_idamax_"))); */
__typeof__ (liftracc_idamax_) IDAMAX __attribute__ ((alias("liftracc_idamax_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_idamax) cblas_idamax __attribute__ ((alias("liftracc_idamax")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ICAMAX
 */

liftracc_index_t liftracc_icamax(const int n, const void * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ICAMAX]));
#endif /* _LIFTRACC_PROFILING_ */
    liftracc_index_t (*liftracc_plugin_func)();
    liftracc_index_t ret = 0.0;
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ICAMAX, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_icamax");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        ret = (*liftracc_plugin_func)(n, x, incx);
    } else
        ERROR("liftracc_icamax not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ICAMAX]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;
}

liftracc_index_t liftracc_icamax_(const int * n, const void * x, const int * incx)
{
    return liftracc_icamax(*n, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_icamax_) icamax __attribute__ ((alias("liftracc_icamax_"))); */
/* __typeof__ (liftracc_icamax_) icamax_ __attribute__ ((alias("liftracc_icamax_"))); */
__typeof__ (liftracc_icamax_) ICAMAX __attribute__ ((alias("liftracc_icamax_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_icamax) cblas_icamax __attribute__ ((alias("liftracc_icamax")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * IZAMAX
 */

liftracc_index_t liftracc_izamax(const int n, const void * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_IZAMAX]));
#endif /* _LIFTRACC_PROFILING_ */
    liftracc_index_t (*liftracc_plugin_func)();
    liftracc_index_t ret = 0.0;
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_IZAMAX, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_izamax");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        ret = (*liftracc_plugin_func)(n, x, incx);
    } else
        ERROR("liftracc_izamax not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_IZAMAX]));
#endif /* _LIFTRACC_PROFILING_ */

    return ret;
}

liftracc_index_t liftracc_izamax_(const int * n, const void * x, const int * incx)
{
    return liftracc_izamax(*n, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_izamax_) izamax __attribute__ ((alias("liftracc_izamax_"))); */
/* __typeof__ (liftracc_izamax_) izamax_ __attribute__ ((alias("liftracc_izamax_"))); */
__typeof__ (liftracc_izamax_) IZAMAX __attribute__ ((alias("liftracc_izamax_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_izamax) cblas_izamax __attribute__ ((alias("liftracc_izamax")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SSWAP
 */

void liftracc_sswap(const int n, float * x, const int incx, float * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SSWAP]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SSWAP, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_sswap");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, x, incx, y, incy);
    } else
        ERROR("liftracc_sswap not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SSWAP]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_sswap_(const int * n, float * x, const int * incx, float * y, const int * incy)
{
    liftracc_sswap(*n, x, *incx, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_sswap_) sswap __attribute__ ((alias("liftracc_sswap_"))); */
/* __typeof__ (liftracc_sswap_) sswap_ __attribute__ ((alias("liftracc_sswap_"))); */
__typeof__ (liftracc_sswap_) SSWAP __attribute__ ((alias("liftracc_sswap_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_sswap) cblas_sswap __attribute__ ((alias("liftracc_sswap")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SCOPY
 */

void liftracc_scopy(const int n, const float * x, const int incx, float * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SCOPY]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SCOPY, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_scopy");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, x, incx, y, incy);
    } else
        ERROR("liftracc_scopy not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SCOPY]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_scopy_(const int * n, const float * x, const int * incx, float * y, const int * incy)
{
    liftracc_scopy(*n, x, *incx, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_scopy_) scopy __attribute__ ((alias("liftracc_scopy_"))); */
/* __typeof__ (liftracc_scopy_) scopy_ __attribute__ ((alias("liftracc_scopy_"))); */
__typeof__ (liftracc_scopy_) SCOPY __attribute__ ((alias("liftracc_scopy_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_scopy) cblas_scopy __attribute__ ((alias("liftracc_scopy")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SAXPY
 */

void liftracc_saxpy(const int n, const float alpha, const float * x, const int incx, float * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SAXPY]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SAXPY, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_saxpy");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, alpha, x, incx, y, incy);
    } else
        ERROR("liftracc_saxpy not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SAXPY]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_saxpy_(const int * n, const float * alpha, const float * x, const int * incx, float * y, const int * incy)
{
    liftracc_saxpy(*n, *alpha, x, *incx, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_saxpy_) saxpy __attribute__ ((alias("liftracc_saxpy_"))); */
/* __typeof__ (liftracc_saxpy_) saxpy_ __attribute__ ((alias("liftracc_saxpy_"))); */
__typeof__ (liftracc_saxpy_) SAXPY __attribute__ ((alias("liftracc_saxpy_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_saxpy) cblas_saxpy __attribute__ ((alias("liftracc_saxpy")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DSWAP
 */

void liftracc_dswap(const int n, double * x, const int incx, double * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSWAP]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DSWAP, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dswap");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, x, incx, y, incy);
    } else
        ERROR("liftracc_dswap not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSWAP]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dswap_(const int * n, double * x, const int * incx, double * y, const int * incy)
{
    liftracc_dswap(*n, x, *incx, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dswap_) dswap __attribute__ ((alias("liftracc_dswap_"))); */
/* __typeof__ (liftracc_dswap_) dswap_ __attribute__ ((alias("liftracc_dswap_"))); */
__typeof__ (liftracc_dswap_) DSWAP __attribute__ ((alias("liftracc_dswap_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dswap) cblas_dswap __attribute__ ((alias("liftracc_dswap")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DCOPY
 */

void liftracc_dcopy(const int n, const double * x, const int incx, double * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DCOPY]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DCOPY, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dcopy");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, x, incx, y, incy);
    } else
        ERROR("liftracc_dcopy not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DCOPY]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dcopy_(const int * n, const double * x, const int * incx, double * y, const int * incy)
{
    liftracc_dcopy(*n, x, *incx, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dcopy_) dcopy __attribute__ ((alias("liftracc_dcopy_"))); */
/* __typeof__ (liftracc_dcopy_) dcopy_ __attribute__ ((alias("liftracc_dcopy_"))); */
__typeof__ (liftracc_dcopy_) DCOPY __attribute__ ((alias("liftracc_dcopy_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dcopy) cblas_dcopy __attribute__ ((alias("liftracc_dcopy")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DAXPY
 */

void liftracc_daxpy(const int n, const double alpha, const double * x, const int incx, double * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DAXPY]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DAXPY, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_daxpy");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, alpha, x, incx, y, incy);
    } else
        ERROR("liftracc_daxpy not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DAXPY]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_daxpy_(const int * n, const double * alpha, const double * x, const int * incx, double * y, const int * incy)
{
    liftracc_daxpy(*n, *alpha, x, *incx, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_daxpy_) daxpy __attribute__ ((alias("liftracc_daxpy_"))); */
/* __typeof__ (liftracc_daxpy_) daxpy_ __attribute__ ((alias("liftracc_daxpy_"))); */
__typeof__ (liftracc_daxpy_) DAXPY __attribute__ ((alias("liftracc_daxpy_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_daxpy) cblas_daxpy __attribute__ ((alias("liftracc_daxpy")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CSWAP
 */

void liftracc_cswap(const int n, void * x, const int incx, void * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CSWAP]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CSWAP, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_cswap");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, x, incx, y, incy);
    } else
        ERROR("liftracc_cswap not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CSWAP]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_cswap_(const int * n, void * x, const int * incx, void * y, const int * incy)
{
    liftracc_cswap(*n, x, *incx, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_cswap_) cswap __attribute__ ((alias("liftracc_cswap_"))); */
/* __typeof__ (liftracc_cswap_) cswap_ __attribute__ ((alias("liftracc_cswap_"))); */
__typeof__ (liftracc_cswap_) CSWAP __attribute__ ((alias("liftracc_cswap_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_cswap) cblas_cswap __attribute__ ((alias("liftracc_cswap")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CCOPY
 */

void liftracc_ccopy(const int n, const void * x, const int incx, void * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CCOPY]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CCOPY, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ccopy");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, x, incx, y, incy);
    } else
        ERROR("liftracc_ccopy not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CCOPY]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_ccopy_(const int * n, const void * x, const int * incx, void * y, const int * incy)
{
    liftracc_ccopy(*n, x, *incx, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ccopy_) ccopy __attribute__ ((alias("liftracc_ccopy_"))); */
/* __typeof__ (liftracc_ccopy_) ccopy_ __attribute__ ((alias("liftracc_ccopy_"))); */
__typeof__ (liftracc_ccopy_) CCOPY __attribute__ ((alias("liftracc_ccopy_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ccopy) cblas_ccopy __attribute__ ((alias("liftracc_ccopy")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CAXPY
 */

void liftracc_caxpy(const int n, const void * alpha, const void * x, const int incx, void * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CAXPY]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CAXPY, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_caxpy");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, alpha, x, incx, y, incy);
    } else
        ERROR("liftracc_caxpy not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CAXPY]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_caxpy_(const int * n, const void * alpha, const void * x, const int * incx, void * y, const int * incy)
{
    liftracc_caxpy(*n, alpha, x, *incx, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_caxpy_) caxpy __attribute__ ((alias("liftracc_caxpy_"))); */
/* __typeof__ (liftracc_caxpy_) caxpy_ __attribute__ ((alias("liftracc_caxpy_"))); */
__typeof__ (liftracc_caxpy_) CAXPY __attribute__ ((alias("liftracc_caxpy_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_caxpy) cblas_caxpy __attribute__ ((alias("liftracc_caxpy")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZSWAP
 */

void liftracc_zswap(const int n, void * x, const int incx, void * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZSWAP]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZSWAP, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zswap");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, x, incx, y, incy);
    } else
        ERROR("liftracc_zswap not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZSWAP]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zswap_(const int * n, void * x, const int * incx, void * y, const int * incy)
{
    liftracc_zswap(*n, x, *incx, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zswap_) zswap __attribute__ ((alias("liftracc_zswap_"))); */
/* __typeof__ (liftracc_zswap_) zswap_ __attribute__ ((alias("liftracc_zswap_"))); */
__typeof__ (liftracc_zswap_) ZSWAP __attribute__ ((alias("liftracc_zswap_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zswap) cblas_zswap __attribute__ ((alias("liftracc_zswap")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZCOPY
 */

void liftracc_zcopy(const int n, const void * x, const int incx, void * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZCOPY]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZCOPY, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zcopy");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, x, incx, y, incy);
    } else
        ERROR("liftracc_zcopy not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZCOPY]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zcopy_(const int * n, const void * x, const int * incx, void * y, const int * incy)
{
    liftracc_zcopy(*n, x, *incx, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zcopy_) zcopy __attribute__ ((alias("liftracc_zcopy_"))); */
/* __typeof__ (liftracc_zcopy_) zcopy_ __attribute__ ((alias("liftracc_zcopy_"))); */
__typeof__ (liftracc_zcopy_) ZCOPY __attribute__ ((alias("liftracc_zcopy_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zcopy) cblas_zcopy __attribute__ ((alias("liftracc_zcopy")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZAXPY
 */

void liftracc_zaxpy(const int n, const void * alpha, const void * x, const int incx, void * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZAXPY]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZAXPY, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zaxpy");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, alpha, x, incx, y, incy);
    } else
        ERROR("liftracc_zaxpy not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZAXPY]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zaxpy_(const int * n, const void * alpha, const void * x, const int * incx, void * y, const int * incy)
{
    liftracc_zaxpy(*n, alpha, x, *incx, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zaxpy_) zaxpy __attribute__ ((alias("liftracc_zaxpy_"))); */
/* __typeof__ (liftracc_zaxpy_) zaxpy_ __attribute__ ((alias("liftracc_zaxpy_"))); */
__typeof__ (liftracc_zaxpy_) ZAXPY __attribute__ ((alias("liftracc_zaxpy_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zaxpy) cblas_zaxpy __attribute__ ((alias("liftracc_zaxpy")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SROTG
 */

void liftracc_srotg(float * a, float * b, float * c, float * s)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SROTG]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = 0;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SROTG, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_srotg");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(a, b, c, s);
    } else
        ERROR("liftracc_srotg not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SROTG]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_srotg_(float * a, float * b, float * c, float * s)
{
    liftracc_srotg(a, b, c, s);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_srotg_) srotg __attribute__ ((alias("liftracc_srotg_"))); */
/* __typeof__ (liftracc_srotg_) srotg_ __attribute__ ((alias("liftracc_srotg_"))); */
__typeof__ (liftracc_srotg_) SROTG __attribute__ ((alias("liftracc_srotg_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_srotg) cblas_srotg __attribute__ ((alias("liftracc_srotg")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SROTMG
 */

void liftracc_srotmg(float * d1, float * d2, float * b1, const float b2, float * p)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SROTMG]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = 0;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SROTMG, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_srotmg");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(d1, d2, b1, b2, p);
    } else
        ERROR("liftracc_srotmg not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SROTMG]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_srotmg_(float * d1, float * d2, float * b1, const float * b2, float * p)
{
    liftracc_srotmg(d1, d2, b1, *b2, p);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_srotmg_) srotmg __attribute__ ((alias("liftracc_srotmg_"))); */
/* __typeof__ (liftracc_srotmg_) srotmg_ __attribute__ ((alias("liftracc_srotmg_"))); */
__typeof__ (liftracc_srotmg_) SROTMG __attribute__ ((alias("liftracc_srotmg_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_srotmg) cblas_srotmg __attribute__ ((alias("liftracc_srotmg")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SROT
 */

void liftracc_srot(const int n, float * x, const int incx, float * y, const int incy, const float c, const float s)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SROT]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SROT, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_srot");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, x, incx, y, incy, c, s);
    } else
        ERROR("liftracc_srot not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SROT]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_srot_(const int * n, float * x, const int * incx, float * y, const int * incy, const float * c, const float * s)
{
    liftracc_srot(*n, x, *incx, y, *incy, *c, *s);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_srot_) srot __attribute__ ((alias("liftracc_srot_"))); */
/* __typeof__ (liftracc_srot_) srot_ __attribute__ ((alias("liftracc_srot_"))); */
__typeof__ (liftracc_srot_) SROT __attribute__ ((alias("liftracc_srot_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_srot) cblas_srot __attribute__ ((alias("liftracc_srot")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SROTM
 */

void liftracc_srotm(const int n, float * x, const int incx, float * y, const int incy, const float * p)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SROTM]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SROTM, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_srotm");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, x, incx, y, incy, p);
    } else
        ERROR("liftracc_srotm not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SROTM]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_srotm_(const int * n, float * x, const int * incx, float * y, const int * incy, const float * p)
{
    liftracc_srotm(*n, x, *incx, y, *incy, p);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_srotm_) srotm __attribute__ ((alias("liftracc_srotm_"))); */
/* __typeof__ (liftracc_srotm_) srotm_ __attribute__ ((alias("liftracc_srotm_"))); */
__typeof__ (liftracc_srotm_) SROTM __attribute__ ((alias("liftracc_srotm_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_srotm) cblas_srotm __attribute__ ((alias("liftracc_srotm")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DROTG
 */

void liftracc_drotg(double * a, double * b, double * c, double * s)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DROTG]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = 0;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DROTG, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_drotg");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(a, b, c, s);
    } else
        ERROR("liftracc_drotg not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DROTG]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_drotg_(double * a, double * b, double * c, double * s)
{
    liftracc_drotg(a, b, c, s);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_drotg_) drotg __attribute__ ((alias("liftracc_drotg_"))); */
/* __typeof__ (liftracc_drotg_) drotg_ __attribute__ ((alias("liftracc_drotg_"))); */
__typeof__ (liftracc_drotg_) DROTG __attribute__ ((alias("liftracc_drotg_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_drotg) cblas_drotg __attribute__ ((alias("liftracc_drotg")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DROTMG
 */

void liftracc_drotmg(double * d1, double * d2, double * b1, const double b2, double * p)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DROTMG]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = 0;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DROTMG, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_drotmg");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(d1, d2, b1, b2, p);
    } else
        ERROR("liftracc_drotmg not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DROTMG]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_drotmg_(double * d1, double * d2, double * b1, const double * b2, double * p)
{
    liftracc_drotmg(d1, d2, b1, *b2, p);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_drotmg_) drotmg __attribute__ ((alias("liftracc_drotmg_"))); */
/* __typeof__ (liftracc_drotmg_) drotmg_ __attribute__ ((alias("liftracc_drotmg_"))); */
__typeof__ (liftracc_drotmg_) DROTMG __attribute__ ((alias("liftracc_drotmg_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_drotmg) cblas_drotmg __attribute__ ((alias("liftracc_drotmg")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DROT
 */

void liftracc_drot(const int n, double * x, const int incx, double * y, const int incy, const double c, const double s)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DROT]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DROT, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_drot");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, x, incx, y, incy, c, s);
    } else
        ERROR("liftracc_drot not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DROT]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_drot_(const int * n, double * x, const int * incx, double * y, const int * incy, const double * c, const double * s)
{
    liftracc_drot(*n, x, *incx, y, *incy, *c, *s);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_drot_) drot __attribute__ ((alias("liftracc_drot_"))); */
/* __typeof__ (liftracc_drot_) drot_ __attribute__ ((alias("liftracc_drot_"))); */
__typeof__ (liftracc_drot_) DROT __attribute__ ((alias("liftracc_drot_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_drot) cblas_drot __attribute__ ((alias("liftracc_drot")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DROTM
 */

void liftracc_drotm(const int n, double * x, const int incx, double * y, const int incy, const double * p)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DROTM]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DROTM, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_drotm");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, x, incx, y, incy, p);
    } else
        ERROR("liftracc_drotm not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DROTM]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_drotm_(const int * n, double * x, const int * incx, double * y, const int * incy, const double * p)
{
    liftracc_drotm(*n, x, *incx, y, *incy, p);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_drotm_) drotm __attribute__ ((alias("liftracc_drotm_"))); */
/* __typeof__ (liftracc_drotm_) drotm_ __attribute__ ((alias("liftracc_drotm_"))); */
__typeof__ (liftracc_drotm_) DROTM __attribute__ ((alias("liftracc_drotm_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_drotm) cblas_drotm __attribute__ ((alias("liftracc_drotm")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SSCAL
 */

void liftracc_sscal(const int n, const float alpha, float * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SSCAL]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SSCAL, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_sscal");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, alpha, x, incx);
    } else
        ERROR("liftracc_sscal not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SSCAL]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_sscal_(const int * n, const float * alpha, float * x, const int * incx)
{
    liftracc_sscal(*n, *alpha, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_sscal_) sscal __attribute__ ((alias("liftracc_sscal_"))); */
/* __typeof__ (liftracc_sscal_) sscal_ __attribute__ ((alias("liftracc_sscal_"))); */
__typeof__ (liftracc_sscal_) SSCAL __attribute__ ((alias("liftracc_sscal_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_sscal) cblas_sscal __attribute__ ((alias("liftracc_sscal")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DSCAL
 */

void liftracc_dscal(const int n, const double alpha, double * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSCAL]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DSCAL, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dscal");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, alpha, x, incx);
    } else
        ERROR("liftracc_dscal not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSCAL]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dscal_(const int * n, const double * alpha, double * x, const int * incx)
{
    liftracc_dscal(*n, *alpha, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dscal_) dscal __attribute__ ((alias("liftracc_dscal_"))); */
/* __typeof__ (liftracc_dscal_) dscal_ __attribute__ ((alias("liftracc_dscal_"))); */
__typeof__ (liftracc_dscal_) DSCAL __attribute__ ((alias("liftracc_dscal_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dscal) cblas_dscal __attribute__ ((alias("liftracc_dscal")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CSCAL
 */

void liftracc_cscal(const int n, const void * alpha, void * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CSCAL]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CSCAL, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_cscal");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, alpha, x, incx);
    } else
        ERROR("liftracc_cscal not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CSCAL]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_cscal_(const int * n, const void * alpha, void * x, const int * incx)
{
    liftracc_cscal(*n, alpha, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_cscal_) cscal __attribute__ ((alias("liftracc_cscal_"))); */
/* __typeof__ (liftracc_cscal_) cscal_ __attribute__ ((alias("liftracc_cscal_"))); */
__typeof__ (liftracc_cscal_) CSCAL __attribute__ ((alias("liftracc_cscal_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_cscal) cblas_cscal __attribute__ ((alias("liftracc_cscal")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZSCAL
 */

void liftracc_zscal(const int n, const void * alpha, void * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZSCAL]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZSCAL, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zscal");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, alpha, x, incx);
    } else
        ERROR("liftracc_zscal not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZSCAL]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zscal_(const int * n, const void * alpha, void * x, const int * incx)
{
    liftracc_zscal(*n, alpha, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zscal_) zscal __attribute__ ((alias("liftracc_zscal_"))); */
/* __typeof__ (liftracc_zscal_) zscal_ __attribute__ ((alias("liftracc_zscal_"))); */
__typeof__ (liftracc_zscal_) ZSCAL __attribute__ ((alias("liftracc_zscal_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zscal) cblas_zscal __attribute__ ((alias("liftracc_zscal")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CSSCAL
 */

void liftracc_csscal(const int n, const float alpha, void * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CSSCAL]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CSSCAL, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_csscal");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, alpha, x, incx);
    } else
        ERROR("liftracc_csscal not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CSSCAL]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_csscal_(const int * n, const float * alpha, void * x, const int * incx)
{
    liftracc_csscal(*n, *alpha, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_csscal_) csscal __attribute__ ((alias("liftracc_csscal_"))); */
/* __typeof__ (liftracc_csscal_) csscal_ __attribute__ ((alias("liftracc_csscal_"))); */
__typeof__ (liftracc_csscal_) CSSCAL __attribute__ ((alias("liftracc_csscal_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_csscal) cblas_csscal __attribute__ ((alias("liftracc_csscal")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZDSCAL
 */

void liftracc_zdscal(const int n, const double alpha, void * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZDSCAL]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZDSCAL, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zdscal");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(n, alpha, x, incx);
    } else
        ERROR("liftracc_zdscal not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZDSCAL]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zdscal_(const int * n, const double * alpha, void * x, const int * incx)
{
    liftracc_zdscal(*n, *alpha, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zdscal_) zdscal __attribute__ ((alias("liftracc_zdscal_"))); */
/* __typeof__ (liftracc_zdscal_) zdscal_ __attribute__ ((alias("liftracc_zdscal_"))); */
__typeof__ (liftracc_zdscal_) ZDSCAL __attribute__ ((alias("liftracc_zdscal_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zdscal) cblas_zdscal __attribute__ ((alias("liftracc_zdscal")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SGEMV
 */

void liftracc_sgemv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const float alpha, const float * a, const int lda, const float * x, const int incx, const float beta, float * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SGEMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SGEMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_sgemv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, transa, m, n, alpha, a, lda, x, incx, beta, y, incy);
    } else
        ERROR("liftracc_sgemv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SGEMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_sgemv_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const int * m, const int * n, const float * alpha, const float * a, const int * lda, const float * x, const int * incx, const float * beta, float * y, const int * incy)
{
    liftracc_sgemv(*order, *transa, *m, *n, *alpha, a, *lda, x, *incx, *beta, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_sgemv_) sgemv __attribute__ ((alias("liftracc_sgemv_"))); */
/* __typeof__ (liftracc_sgemv_) sgemv_ __attribute__ ((alias("liftracc_sgemv_"))); */
__typeof__ (liftracc_sgemv_) SGEMV __attribute__ ((alias("liftracc_sgemv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_sgemv) cblas_sgemv __attribute__ ((alias("liftracc_sgemv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SGBMV
 */

void liftracc_sgbmv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const int kl, const int ku, const float alpha, const float * a, const int lda, const float * x, const int incx, const float beta, float * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SGBMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SGBMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_sgbmv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, transa, m, n, kl, ku, alpha, a, lda, x, incx, beta, y, incy);
    } else
        ERROR("liftracc_sgbmv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SGBMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_sgbmv_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const int * m, const int * n, const int * kl, const int * ku, const float * alpha, const float * a, const int * lda, const float * x, const int * incx, const float * beta, float * y, const int * incy)
{
    liftracc_sgbmv(*order, *transa, *m, *n, *kl, *ku, *alpha, a, *lda, x, *incx, *beta, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_sgbmv_) sgbmv __attribute__ ((alias("liftracc_sgbmv_"))); */
/* __typeof__ (liftracc_sgbmv_) sgbmv_ __attribute__ ((alias("liftracc_sgbmv_"))); */
__typeof__ (liftracc_sgbmv_) SGBMV __attribute__ ((alias("liftracc_sgbmv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_sgbmv) cblas_sgbmv __attribute__ ((alias("liftracc_sgbmv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * STRMV
 */

void liftracc_strmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const float * a, const int lda, float * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_STRMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_STRMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_strmv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, transa, diag, n, a, lda, x, incx);
    } else
        ERROR("liftracc_strmv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_STRMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_strmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const float * a, const int * lda, float * x, const int * incx)
{
    liftracc_strmv(*order, *uplo, *transa, *diag, *n, a, *lda, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_strmv_) strmv __attribute__ ((alias("liftracc_strmv_"))); */
/* __typeof__ (liftracc_strmv_) strmv_ __attribute__ ((alias("liftracc_strmv_"))); */
__typeof__ (liftracc_strmv_) STRMV __attribute__ ((alias("liftracc_strmv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_strmv) cblas_strmv __attribute__ ((alias("liftracc_strmv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * STBMV
 */

void liftracc_stbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const float * a, const int lda, float * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_STBMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_STBMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_stbmv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, transa, diag, n, k, a, lda, x, incx);
    } else
        ERROR("liftracc_stbmv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_STBMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_stbmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const int * k, const float * a, const int * lda, float * x, const int * incx)
{
    liftracc_stbmv(*order, *uplo, *transa, *diag, *n, *k, a, *lda, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_stbmv_) stbmv __attribute__ ((alias("liftracc_stbmv_"))); */
/* __typeof__ (liftracc_stbmv_) stbmv_ __attribute__ ((alias("liftracc_stbmv_"))); */
__typeof__ (liftracc_stbmv_) STBMV __attribute__ ((alias("liftracc_stbmv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_stbmv) cblas_stbmv __attribute__ ((alias("liftracc_stbmv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * STPMV
 */

void liftracc_stpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const float * ap, float * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_STPMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_STPMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_stpmv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, transa, diag, n, ap, x, incx);
    } else
        ERROR("liftracc_stpmv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_STPMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_stpmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const float * ap, float * x, const int * incx)
{
    liftracc_stpmv(*order, *uplo, *transa, *diag, *n, ap, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_stpmv_) stpmv __attribute__ ((alias("liftracc_stpmv_"))); */
/* __typeof__ (liftracc_stpmv_) stpmv_ __attribute__ ((alias("liftracc_stpmv_"))); */
__typeof__ (liftracc_stpmv_) STPMV __attribute__ ((alias("liftracc_stpmv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_stpmv) cblas_stpmv __attribute__ ((alias("liftracc_stpmv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * STRSV
 */

void liftracc_strsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const float * a, const int lda, float * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_STRSV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_STRSV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_strsv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, transa, diag, n, a, lda, x, incx);
    } else
        ERROR("liftracc_strsv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_STRSV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_strsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const float * a, const int * lda, float * x, const int * incx)
{
    liftracc_strsv(*order, *uplo, *transa, *diag, *n, a, *lda, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_strsv_) strsv __attribute__ ((alias("liftracc_strsv_"))); */
/* __typeof__ (liftracc_strsv_) strsv_ __attribute__ ((alias("liftracc_strsv_"))); */
__typeof__ (liftracc_strsv_) STRSV __attribute__ ((alias("liftracc_strsv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_strsv) cblas_strsv __attribute__ ((alias("liftracc_strsv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * STBSV
 */

void liftracc_stbsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const float * a, const int lda, float * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_STBSV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_STBSV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_stbsv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, transa, diag, n, k, a, lda, x, incx);
    } else
        ERROR("liftracc_stbsv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_STBSV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_stbsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const int * k, const float * a, const int * lda, float * x, const int * incx)
{
    liftracc_stbsv(*order, *uplo, *transa, *diag, *n, *k, a, *lda, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_stbsv_) stbsv __attribute__ ((alias("liftracc_stbsv_"))); */
/* __typeof__ (liftracc_stbsv_) stbsv_ __attribute__ ((alias("liftracc_stbsv_"))); */
__typeof__ (liftracc_stbsv_) STBSV __attribute__ ((alias("liftracc_stbsv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_stbsv) cblas_stbsv __attribute__ ((alias("liftracc_stbsv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * STPSV
 */

void liftracc_stpsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const float * ap, float * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_STPSV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_STPSV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_stpsv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, transa, diag, n, ap, x, incx);
    } else
        ERROR("liftracc_stpsv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_STPSV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_stpsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const float * ap, float * x, const int * incx)
{
    liftracc_stpsv(*order, *uplo, *transa, *diag, *n, ap, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_stpsv_) stpsv __attribute__ ((alias("liftracc_stpsv_"))); */
/* __typeof__ (liftracc_stpsv_) stpsv_ __attribute__ ((alias("liftracc_stpsv_"))); */
__typeof__ (liftracc_stpsv_) STPSV __attribute__ ((alias("liftracc_stpsv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_stpsv) cblas_stpsv __attribute__ ((alias("liftracc_stpsv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DGEMV
 */

void liftracc_dgemv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const double alpha, const double * a, const int lda, const double * x, const int incx, const double beta, double * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DGEMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DGEMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dgemv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, transa, m, n, alpha, a, lda, x, incx, beta, y, incy);
    } else
        ERROR("liftracc_dgemv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DGEMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dgemv_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const int * m, const int * n, const double * alpha, const double * a, const int * lda, const double * x, const int * incx, const double * beta, double * y, const int * incy)
{
    liftracc_dgemv(*order, *transa, *m, *n, *alpha, a, *lda, x, *incx, *beta, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dgemv_) dgemv __attribute__ ((alias("liftracc_dgemv_"))); */
/* __typeof__ (liftracc_dgemv_) dgemv_ __attribute__ ((alias("liftracc_dgemv_"))); */
__typeof__ (liftracc_dgemv_) DGEMV __attribute__ ((alias("liftracc_dgemv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dgemv) cblas_dgemv __attribute__ ((alias("liftracc_dgemv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DGBMV
 */

void liftracc_dgbmv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const int kl, const int ku, const double alpha, const double * a, const int lda, const double * x, const int incx, const double beta, double * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DGBMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DGBMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dgbmv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, transa, m, n, kl, ku, alpha, a, lda, x, incx, beta, y, incy);
    } else
        ERROR("liftracc_dgbmv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DGBMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dgbmv_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const int * m, const int * n, const int * kl, const int * ku, const double * alpha, const double * a, const int * lda, const double * x, const int * incx, const double * beta, double * y, const int * incy)
{
    liftracc_dgbmv(*order, *transa, *m, *n, *kl, *ku, *alpha, a, *lda, x, *incx, *beta, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dgbmv_) dgbmv __attribute__ ((alias("liftracc_dgbmv_"))); */
/* __typeof__ (liftracc_dgbmv_) dgbmv_ __attribute__ ((alias("liftracc_dgbmv_"))); */
__typeof__ (liftracc_dgbmv_) DGBMV __attribute__ ((alias("liftracc_dgbmv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dgbmv) cblas_dgbmv __attribute__ ((alias("liftracc_dgbmv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DTRMV
 */

void liftracc_dtrmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const double * a, const int lda, double * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DTRMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DTRMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dtrmv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, transa, diag, n, a, lda, x, incx);
    } else
        ERROR("liftracc_dtrmv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DTRMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dtrmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const double * a, const int * lda, double * x, const int * incx)
{
    liftracc_dtrmv(*order, *uplo, *transa, *diag, *n, a, *lda, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dtrmv_) dtrmv __attribute__ ((alias("liftracc_dtrmv_"))); */
/* __typeof__ (liftracc_dtrmv_) dtrmv_ __attribute__ ((alias("liftracc_dtrmv_"))); */
__typeof__ (liftracc_dtrmv_) DTRMV __attribute__ ((alias("liftracc_dtrmv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dtrmv) cblas_dtrmv __attribute__ ((alias("liftracc_dtrmv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DTBMV
 */

void liftracc_dtbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const double * a, const int lda, double * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DTBMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DTBMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dtbmv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, transa, diag, n, k, a, lda, x, incx);
    } else
        ERROR("liftracc_dtbmv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DTBMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dtbmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const int * k, const double * a, const int * lda, double * x, const int * incx)
{
    liftracc_dtbmv(*order, *uplo, *transa, *diag, *n, *k, a, *lda, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dtbmv_) dtbmv __attribute__ ((alias("liftracc_dtbmv_"))); */
/* __typeof__ (liftracc_dtbmv_) dtbmv_ __attribute__ ((alias("liftracc_dtbmv_"))); */
__typeof__ (liftracc_dtbmv_) DTBMV __attribute__ ((alias("liftracc_dtbmv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dtbmv) cblas_dtbmv __attribute__ ((alias("liftracc_dtbmv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DTPMV
 */

void liftracc_dtpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const double * ap, double * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DTPMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DTPMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dtpmv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, transa, diag, n, ap, x, incx);
    } else
        ERROR("liftracc_dtpmv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DTPMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dtpmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const double * ap, double * x, const int * incx)
{
    liftracc_dtpmv(*order, *uplo, *transa, *diag, *n, ap, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dtpmv_) dtpmv __attribute__ ((alias("liftracc_dtpmv_"))); */
/* __typeof__ (liftracc_dtpmv_) dtpmv_ __attribute__ ((alias("liftracc_dtpmv_"))); */
__typeof__ (liftracc_dtpmv_) DTPMV __attribute__ ((alias("liftracc_dtpmv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dtpmv) cblas_dtpmv __attribute__ ((alias("liftracc_dtpmv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DTRSV
 */

void liftracc_dtrsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const double * a, const int lda, double * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DTRSV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DTRSV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dtrsv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, transa, diag, n, a, lda, x, incx);
    } else
        ERROR("liftracc_dtrsv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DTRSV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dtrsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const double * a, const int * lda, double * x, const int * incx)
{
    liftracc_dtrsv(*order, *uplo, *transa, *diag, *n, a, *lda, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dtrsv_) dtrsv __attribute__ ((alias("liftracc_dtrsv_"))); */
/* __typeof__ (liftracc_dtrsv_) dtrsv_ __attribute__ ((alias("liftracc_dtrsv_"))); */
__typeof__ (liftracc_dtrsv_) DTRSV __attribute__ ((alias("liftracc_dtrsv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dtrsv) cblas_dtrsv __attribute__ ((alias("liftracc_dtrsv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DTBSV
 */

void liftracc_dtbsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const double * a, const int lda, double * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DTBSV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DTBSV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dtbsv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, transa, diag, n, k, a, lda, x, incx);
    } else
        ERROR("liftracc_dtbsv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DTBSV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dtbsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const int * k, const double * a, const int * lda, double * x, const int * incx)
{
    liftracc_dtbsv(*order, *uplo, *transa, *diag, *n, *k, a, *lda, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dtbsv_) dtbsv __attribute__ ((alias("liftracc_dtbsv_"))); */
/* __typeof__ (liftracc_dtbsv_) dtbsv_ __attribute__ ((alias("liftracc_dtbsv_"))); */
__typeof__ (liftracc_dtbsv_) DTBSV __attribute__ ((alias("liftracc_dtbsv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dtbsv) cblas_dtbsv __attribute__ ((alias("liftracc_dtbsv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DTPSV
 */

void liftracc_dtpsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const double * ap, double * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DTPSV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DTPSV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dtpsv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, transa, diag, n, ap, x, incx);
    } else
        ERROR("liftracc_dtpsv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DTPSV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dtpsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const double * ap, double * x, const int * incx)
{
    liftracc_dtpsv(*order, *uplo, *transa, *diag, *n, ap, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dtpsv_) dtpsv __attribute__ ((alias("liftracc_dtpsv_"))); */
/* __typeof__ (liftracc_dtpsv_) dtpsv_ __attribute__ ((alias("liftracc_dtpsv_"))); */
__typeof__ (liftracc_dtpsv_) DTPSV __attribute__ ((alias("liftracc_dtpsv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dtpsv) cblas_dtpsv __attribute__ ((alias("liftracc_dtpsv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CGEMV
 */

void liftracc_cgemv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CGEMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CGEMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_cgemv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, transa, m, n, alpha, a, lda, x, incx, beta, y, incy);
    } else
        ERROR("liftracc_cgemv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CGEMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_cgemv_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const int * m, const int * n, const void * alpha, const void * a, const int * lda, const void * x, const int * incx, const void * beta, void * y, const int * incy)
{
    liftracc_cgemv(*order, *transa, *m, *n, alpha, a, *lda, x, *incx, beta, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_cgemv_) cgemv __attribute__ ((alias("liftracc_cgemv_"))); */
/* __typeof__ (liftracc_cgemv_) cgemv_ __attribute__ ((alias("liftracc_cgemv_"))); */
__typeof__ (liftracc_cgemv_) CGEMV __attribute__ ((alias("liftracc_cgemv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_cgemv) cblas_cgemv __attribute__ ((alias("liftracc_cgemv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CGBMV
 */

void liftracc_cgbmv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const int kl, const int ku, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CGBMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CGBMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_cgbmv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, transa, m, n, kl, ku, alpha, a, lda, x, incx, beta, y, incy);
    } else
        ERROR("liftracc_cgbmv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CGBMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_cgbmv_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const int * m, const int * n, const int * kl, const int * ku, const void * alpha, const void * a, const int * lda, const void * x, const int * incx, const void * beta, void * y, const int * incy)
{
    liftracc_cgbmv(*order, *transa, *m, *n, *kl, *ku, alpha, a, *lda, x, *incx, beta, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_cgbmv_) cgbmv __attribute__ ((alias("liftracc_cgbmv_"))); */
/* __typeof__ (liftracc_cgbmv_) cgbmv_ __attribute__ ((alias("liftracc_cgbmv_"))); */
__typeof__ (liftracc_cgbmv_) CGBMV __attribute__ ((alias("liftracc_cgbmv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_cgbmv) cblas_cgbmv __attribute__ ((alias("liftracc_cgbmv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CTRMV
 */

void liftracc_ctrmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * a, const int lda, void * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CTRMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CTRMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ctrmv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, transa, diag, n, a, lda, x, incx);
    } else
        ERROR("liftracc_ctrmv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CTRMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_ctrmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const void * a, const int * lda, void * x, const int * incx)
{
    liftracc_ctrmv(*order, *uplo, *transa, *diag, *n, a, *lda, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ctrmv_) ctrmv __attribute__ ((alias("liftracc_ctrmv_"))); */
/* __typeof__ (liftracc_ctrmv_) ctrmv_ __attribute__ ((alias("liftracc_ctrmv_"))); */
__typeof__ (liftracc_ctrmv_) CTRMV __attribute__ ((alias("liftracc_ctrmv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ctrmv) cblas_ctrmv __attribute__ ((alias("liftracc_ctrmv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CTBMV
 */

void liftracc_ctbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const void * a, const int lda, void * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CTBMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CTBMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ctbmv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, transa, diag, n, k, a, lda, x, incx);
    } else
        ERROR("liftracc_ctbmv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CTBMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_ctbmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const int * k, const void * a, const int * lda, void * x, const int * incx)
{
    liftracc_ctbmv(*order, *uplo, *transa, *diag, *n, *k, a, *lda, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ctbmv_) ctbmv __attribute__ ((alias("liftracc_ctbmv_"))); */
/* __typeof__ (liftracc_ctbmv_) ctbmv_ __attribute__ ((alias("liftracc_ctbmv_"))); */
__typeof__ (liftracc_ctbmv_) CTBMV __attribute__ ((alias("liftracc_ctbmv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ctbmv) cblas_ctbmv __attribute__ ((alias("liftracc_ctbmv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CTPMV
 */

void liftracc_ctpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * ap, void * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CTPMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CTPMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ctpmv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, transa, diag, n, ap, x, incx);
    } else
        ERROR("liftracc_ctpmv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CTPMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_ctpmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const void * ap, void * x, const int * incx)
{
    liftracc_ctpmv(*order, *uplo, *transa, *diag, *n, ap, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ctpmv_) ctpmv __attribute__ ((alias("liftracc_ctpmv_"))); */
/* __typeof__ (liftracc_ctpmv_) ctpmv_ __attribute__ ((alias("liftracc_ctpmv_"))); */
__typeof__ (liftracc_ctpmv_) CTPMV __attribute__ ((alias("liftracc_ctpmv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ctpmv) cblas_ctpmv __attribute__ ((alias("liftracc_ctpmv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CTRSV
 */

void liftracc_ctrsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * a, const int lda, void * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CTRSV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CTRSV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ctrsv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, transa, diag, n, a, lda, x, incx);
    } else
        ERROR("liftracc_ctrsv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CTRSV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_ctrsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const void * a, const int * lda, void * x, const int * incx)
{
    liftracc_ctrsv(*order, *uplo, *transa, *diag, *n, a, *lda, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ctrsv_) ctrsv __attribute__ ((alias("liftracc_ctrsv_"))); */
/* __typeof__ (liftracc_ctrsv_) ctrsv_ __attribute__ ((alias("liftracc_ctrsv_"))); */
__typeof__ (liftracc_ctrsv_) CTRSV __attribute__ ((alias("liftracc_ctrsv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ctrsv) cblas_ctrsv __attribute__ ((alias("liftracc_ctrsv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CTBSV
 */

void liftracc_ctbsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const void * a, const int lda, void * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CTBSV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CTBSV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ctbsv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, transa, diag, n, k, a, lda, x, incx);
    } else
        ERROR("liftracc_ctbsv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CTBSV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_ctbsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const int * k, const void * a, const int * lda, void * x, const int * incx)
{
    liftracc_ctbsv(*order, *uplo, *transa, *diag, *n, *k, a, *lda, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ctbsv_) ctbsv __attribute__ ((alias("liftracc_ctbsv_"))); */
/* __typeof__ (liftracc_ctbsv_) ctbsv_ __attribute__ ((alias("liftracc_ctbsv_"))); */
__typeof__ (liftracc_ctbsv_) CTBSV __attribute__ ((alias("liftracc_ctbsv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ctbsv) cblas_ctbsv __attribute__ ((alias("liftracc_ctbsv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CTPSV
 */

void liftracc_ctpsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * ap, void * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CTPSV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CTPSV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ctpsv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, transa, diag, n, ap, x, incx);
    } else
        ERROR("liftracc_ctpsv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CTPSV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_ctpsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const void * ap, void * x, const int * incx)
{
    liftracc_ctpsv(*order, *uplo, *transa, *diag, *n, ap, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ctpsv_) ctpsv __attribute__ ((alias("liftracc_ctpsv_"))); */
/* __typeof__ (liftracc_ctpsv_) ctpsv_ __attribute__ ((alias("liftracc_ctpsv_"))); */
__typeof__ (liftracc_ctpsv_) CTPSV __attribute__ ((alias("liftracc_ctpsv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ctpsv) cblas_ctpsv __attribute__ ((alias("liftracc_ctpsv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZGEMV
 */

void liftracc_zgemv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZGEMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZGEMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zgemv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, transa, m, n, alpha, a, lda, x, incx, beta, y, incy);
    } else
        ERROR("liftracc_zgemv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZGEMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zgemv_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const int * m, const int * n, const void * alpha, const void * a, const int * lda, const void * x, const int * incx, const void * beta, void * y, const int * incy)
{
    liftracc_zgemv(*order, *transa, *m, *n, alpha, a, *lda, x, *incx, beta, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zgemv_) zgemv __attribute__ ((alias("liftracc_zgemv_"))); */
/* __typeof__ (liftracc_zgemv_) zgemv_ __attribute__ ((alias("liftracc_zgemv_"))); */
__typeof__ (liftracc_zgemv_) ZGEMV __attribute__ ((alias("liftracc_zgemv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zgemv) cblas_zgemv __attribute__ ((alias("liftracc_zgemv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZGBMV
 */

void liftracc_zgbmv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const int kl, const int ku, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZGBMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZGBMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zgbmv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, transa, m, n, kl, ku, alpha, a, lda, x, incx, beta, y, incy);
    } else
        ERROR("liftracc_zgbmv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZGBMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zgbmv_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const int * m, const int * n, const int * kl, const int * ku, const void * alpha, const void * a, const int * lda, const void * x, const int * incx, const void * beta, void * y, const int * incy)
{
    liftracc_zgbmv(*order, *transa, *m, *n, *kl, *ku, alpha, a, *lda, x, *incx, beta, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zgbmv_) zgbmv __attribute__ ((alias("liftracc_zgbmv_"))); */
/* __typeof__ (liftracc_zgbmv_) zgbmv_ __attribute__ ((alias("liftracc_zgbmv_"))); */
__typeof__ (liftracc_zgbmv_) ZGBMV __attribute__ ((alias("liftracc_zgbmv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zgbmv) cblas_zgbmv __attribute__ ((alias("liftracc_zgbmv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZTRMV
 */

void liftracc_ztrmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * a, const int lda, void * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZTRMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZTRMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ztrmv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, transa, diag, n, a, lda, x, incx);
    } else
        ERROR("liftracc_ztrmv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZTRMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_ztrmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const void * a, const int * lda, void * x, const int * incx)
{
    liftracc_ztrmv(*order, *uplo, *transa, *diag, *n, a, *lda, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ztrmv_) ztrmv __attribute__ ((alias("liftracc_ztrmv_"))); */
/* __typeof__ (liftracc_ztrmv_) ztrmv_ __attribute__ ((alias("liftracc_ztrmv_"))); */
__typeof__ (liftracc_ztrmv_) ZTRMV __attribute__ ((alias("liftracc_ztrmv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ztrmv) cblas_ztrmv __attribute__ ((alias("liftracc_ztrmv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZTBMV
 */

void liftracc_ztbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const void * a, const int lda, void * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZTBMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZTBMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ztbmv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, transa, diag, n, k, a, lda, x, incx);
    } else
        ERROR("liftracc_ztbmv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZTBMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_ztbmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const int * k, const void * a, const int * lda, void * x, const int * incx)
{
    liftracc_ztbmv(*order, *uplo, *transa, *diag, *n, *k, a, *lda, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ztbmv_) ztbmv __attribute__ ((alias("liftracc_ztbmv_"))); */
/* __typeof__ (liftracc_ztbmv_) ztbmv_ __attribute__ ((alias("liftracc_ztbmv_"))); */
__typeof__ (liftracc_ztbmv_) ZTBMV __attribute__ ((alias("liftracc_ztbmv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ztbmv) cblas_ztbmv __attribute__ ((alias("liftracc_ztbmv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZTPMV
 */

void liftracc_ztpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * ap, void * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZTPMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZTPMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ztpmv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, transa, diag, n, ap, x, incx);
    } else
        ERROR("liftracc_ztpmv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZTPMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_ztpmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const void * ap, void * x, const int * incx)
{
    liftracc_ztpmv(*order, *uplo, *transa, *diag, *n, ap, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ztpmv_) ztpmv __attribute__ ((alias("liftracc_ztpmv_"))); */
/* __typeof__ (liftracc_ztpmv_) ztpmv_ __attribute__ ((alias("liftracc_ztpmv_"))); */
__typeof__ (liftracc_ztpmv_) ZTPMV __attribute__ ((alias("liftracc_ztpmv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ztpmv) cblas_ztpmv __attribute__ ((alias("liftracc_ztpmv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZTRSV
 */

void liftracc_ztrsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * a, const int lda, void * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZTRSV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZTRSV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ztrsv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, transa, diag, n, a, lda, x, incx);
    } else
        ERROR("liftracc_ztrsv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZTRSV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_ztrsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const void * a, const int * lda, void * x, const int * incx)
{
    liftracc_ztrsv(*order, *uplo, *transa, *diag, *n, a, *lda, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ztrsv_) ztrsv __attribute__ ((alias("liftracc_ztrsv_"))); */
/* __typeof__ (liftracc_ztrsv_) ztrsv_ __attribute__ ((alias("liftracc_ztrsv_"))); */
__typeof__ (liftracc_ztrsv_) ZTRSV __attribute__ ((alias("liftracc_ztrsv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ztrsv) cblas_ztrsv __attribute__ ((alias("liftracc_ztrsv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZTBSV
 */

void liftracc_ztbsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const void * a, const int lda, void * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZTBSV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZTBSV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ztbsv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, transa, diag, n, k, a, lda, x, incx);
    } else
        ERROR("liftracc_ztbsv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZTBSV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_ztbsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const int * k, const void * a, const int * lda, void * x, const int * incx)
{
    liftracc_ztbsv(*order, *uplo, *transa, *diag, *n, *k, a, *lda, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ztbsv_) ztbsv __attribute__ ((alias("liftracc_ztbsv_"))); */
/* __typeof__ (liftracc_ztbsv_) ztbsv_ __attribute__ ((alias("liftracc_ztbsv_"))); */
__typeof__ (liftracc_ztbsv_) ZTBSV __attribute__ ((alias("liftracc_ztbsv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ztbsv) cblas_ztbsv __attribute__ ((alias("liftracc_ztbsv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZTPSV
 */

void liftracc_ztpsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * ap, void * x, const int incx)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZTPSV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZTPSV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ztpsv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, transa, diag, n, ap, x, incx);
    } else
        ERROR("liftracc_ztpsv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZTPSV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_ztpsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const void * ap, void * x, const int * incx)
{
    liftracc_ztpsv(*order, *uplo, *transa, *diag, *n, ap, x, *incx);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ztpsv_) ztpsv __attribute__ ((alias("liftracc_ztpsv_"))); */
/* __typeof__ (liftracc_ztpsv_) ztpsv_ __attribute__ ((alias("liftracc_ztpsv_"))); */
__typeof__ (liftracc_ztpsv_) ZTPSV __attribute__ ((alias("liftracc_ztpsv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ztpsv) cblas_ztpsv __attribute__ ((alias("liftracc_ztpsv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SSYMV
 */

void liftracc_ssymv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * a, const int lda, const float * x, const int incx, const float beta, float * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SSYMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SSYMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ssymv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, alpha, a, lda, x, incx, beta, y, incy);
    } else
        ERROR("liftracc_ssymv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SSYMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_ssymv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const float * alpha, const float * a, const int * lda, const float * x, const int * incx, const float * beta, float * y, const int * incy)
{
    liftracc_ssymv(*order, *uplo, *n, *alpha, a, *lda, x, *incx, *beta, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ssymv_) ssymv __attribute__ ((alias("liftracc_ssymv_"))); */
/* __typeof__ (liftracc_ssymv_) ssymv_ __attribute__ ((alias("liftracc_ssymv_"))); */
__typeof__ (liftracc_ssymv_) SSYMV __attribute__ ((alias("liftracc_ssymv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ssymv) cblas_ssymv __attribute__ ((alias("liftracc_ssymv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SSBMV
 */

void liftracc_ssbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const int k, const float alpha, const float * a, const int lda, const float * x, const int incx, const float beta, float * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SSBMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SSBMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ssbmv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, k, alpha, a, lda, x, incx, beta, y, incy);
    } else
        ERROR("liftracc_ssbmv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SSBMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_ssbmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const int * k, const float * alpha, const float * a, const int * lda, const float * x, const int * incx, const float * beta, float * y, const int * incy)
{
    liftracc_ssbmv(*order, *uplo, *n, *k, *alpha, a, *lda, x, *incx, *beta, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ssbmv_) ssbmv __attribute__ ((alias("liftracc_ssbmv_"))); */
/* __typeof__ (liftracc_ssbmv_) ssbmv_ __attribute__ ((alias("liftracc_ssbmv_"))); */
__typeof__ (liftracc_ssbmv_) SSBMV __attribute__ ((alias("liftracc_ssbmv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ssbmv) cblas_ssbmv __attribute__ ((alias("liftracc_ssbmv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SSPMV
 */

void liftracc_sspmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * ap, const float * x, const int incx, const float beta, float * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SSPMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SSPMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_sspmv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, alpha, ap, x, incx, beta, y, incy);
    } else
        ERROR("liftracc_sspmv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SSPMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_sspmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const float * alpha, const float * ap, const float * x, const int * incx, const float * beta, float * y, const int * incy)
{
    liftracc_sspmv(*order, *uplo, *n, *alpha, ap, x, *incx, *beta, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_sspmv_) sspmv __attribute__ ((alias("liftracc_sspmv_"))); */
/* __typeof__ (liftracc_sspmv_) sspmv_ __attribute__ ((alias("liftracc_sspmv_"))); */
__typeof__ (liftracc_sspmv_) SSPMV __attribute__ ((alias("liftracc_sspmv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_sspmv) cblas_sspmv __attribute__ ((alias("liftracc_sspmv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SGER
 */

void liftracc_sger(const liftracc_order_t order, const int m, const int n, const float alpha, const float * x, const int incx, const float * y, const int incy, float * a, const int lda)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SGER]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SGER, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_sger");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, m, n, alpha, x, incx, y, incy, a, lda);
    } else
        ERROR("liftracc_sger not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SGER]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_sger_(const liftracc_order_t * order, const int * m, const int * n, const float * alpha, const float * x, const int * incx, const float * y, const int * incy, float * a, const int * lda)
{
    liftracc_sger(*order, *m, *n, *alpha, x, *incx, y, *incy, a, *lda);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_sger_) sger __attribute__ ((alias("liftracc_sger_"))); */
/* __typeof__ (liftracc_sger_) sger_ __attribute__ ((alias("liftracc_sger_"))); */
__typeof__ (liftracc_sger_) SGER __attribute__ ((alias("liftracc_sger_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_sger) cblas_sger __attribute__ ((alias("liftracc_sger")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SSYR
 */

void liftracc_ssyr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * x, const int incx, float * a, const int lda)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SSYR]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SSYR, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ssyr");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, alpha, x, incx, a, lda);
    } else
        ERROR("liftracc_ssyr not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SSYR]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_ssyr_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const float * alpha, const float * x, const int * incx, float * a, const int * lda)
{
    liftracc_ssyr(*order, *uplo, *n, *alpha, x, *incx, a, *lda);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ssyr_) ssyr __attribute__ ((alias("liftracc_ssyr_"))); */
/* __typeof__ (liftracc_ssyr_) ssyr_ __attribute__ ((alias("liftracc_ssyr_"))); */
__typeof__ (liftracc_ssyr_) SSYR __attribute__ ((alias("liftracc_ssyr_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ssyr) cblas_ssyr __attribute__ ((alias("liftracc_ssyr")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SSPR
 */

void liftracc_sspr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * x, const int incx, float * ap)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SSPR]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SSPR, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_sspr");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, alpha, x, incx, ap);
    } else
        ERROR("liftracc_sspr not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SSPR]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_sspr_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const float * alpha, const float * x, const int * incx, float * ap)
{
    liftracc_sspr(*order, *uplo, *n, *alpha, x, *incx, ap);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_sspr_) sspr __attribute__ ((alias("liftracc_sspr_"))); */
/* __typeof__ (liftracc_sspr_) sspr_ __attribute__ ((alias("liftracc_sspr_"))); */
__typeof__ (liftracc_sspr_) SSPR __attribute__ ((alias("liftracc_sspr_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_sspr) cblas_sspr __attribute__ ((alias("liftracc_sspr")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SSYR2
 */

void liftracc_ssyr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * x, const int incx, const float * y, const int incy, float * a, const int lda)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SSYR2]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SSYR2, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ssyr2");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, alpha, x, incx, y, incy, a, lda);
    } else
        ERROR("liftracc_ssyr2 not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SSYR2]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_ssyr2_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const float * alpha, const float * x, const int * incx, const float * y, const int * incy, float * a, const int * lda)
{
    liftracc_ssyr2(*order, *uplo, *n, *alpha, x, *incx, y, *incy, a, *lda);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ssyr2_) ssyr2 __attribute__ ((alias("liftracc_ssyr2_"))); */
/* __typeof__ (liftracc_ssyr2_) ssyr2_ __attribute__ ((alias("liftracc_ssyr2_"))); */
__typeof__ (liftracc_ssyr2_) SSYR2 __attribute__ ((alias("liftracc_ssyr2_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ssyr2) cblas_ssyr2 __attribute__ ((alias("liftracc_ssyr2")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SSPR2
 */

void liftracc_sspr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * x, const int incx, const float * y, const int incy, float * a)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SSPR2]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SSPR2, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_sspr2");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, alpha, x, incx, y, incy, a);
    } else
        ERROR("liftracc_sspr2 not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SSPR2]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_sspr2_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const float * alpha, const float * x, const int * incx, const float * y, const int * incy, float * a)
{
    liftracc_sspr2(*order, *uplo, *n, *alpha, x, *incx, y, *incy, a);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_sspr2_) sspr2 __attribute__ ((alias("liftracc_sspr2_"))); */
/* __typeof__ (liftracc_sspr2_) sspr2_ __attribute__ ((alias("liftracc_sspr2_"))); */
__typeof__ (liftracc_sspr2_) SSPR2 __attribute__ ((alias("liftracc_sspr2_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_sspr2) cblas_sspr2 __attribute__ ((alias("liftracc_sspr2")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DSYMV
 */

void liftracc_dsymv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * a, const int lda, const double * x, const int incx, const double beta, double * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSYMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DSYMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dsymv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, alpha, a, lda, x, incx, beta, y, incy);
    } else
        ERROR("liftracc_dsymv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSYMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dsymv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const double * alpha, const double * a, const int * lda, const double * x, const int * incx, const double * beta, double * y, const int * incy)
{
    liftracc_dsymv(*order, *uplo, *n, *alpha, a, *lda, x, *incx, *beta, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dsymv_) dsymv __attribute__ ((alias("liftracc_dsymv_"))); */
/* __typeof__ (liftracc_dsymv_) dsymv_ __attribute__ ((alias("liftracc_dsymv_"))); */
__typeof__ (liftracc_dsymv_) DSYMV __attribute__ ((alias("liftracc_dsymv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dsymv) cblas_dsymv __attribute__ ((alias("liftracc_dsymv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DSBMV
 */

void liftracc_dsbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const int k, const double alpha, const double * a, const int lda, const double * x, const int incx, const double beta, double * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSBMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DSBMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dsbmv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, k, alpha, a, lda, x, incx, beta, y, incy);
    } else
        ERROR("liftracc_dsbmv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSBMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dsbmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const int * k, const double * alpha, const double * a, const int * lda, const double * x, const int * incx, const double * beta, double * y, const int * incy)
{
    liftracc_dsbmv(*order, *uplo, *n, *k, *alpha, a, *lda, x, *incx, *beta, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dsbmv_) dsbmv __attribute__ ((alias("liftracc_dsbmv_"))); */
/* __typeof__ (liftracc_dsbmv_) dsbmv_ __attribute__ ((alias("liftracc_dsbmv_"))); */
__typeof__ (liftracc_dsbmv_) DSBMV __attribute__ ((alias("liftracc_dsbmv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dsbmv) cblas_dsbmv __attribute__ ((alias("liftracc_dsbmv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DSPMV
 */

void liftracc_dspmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * ap, const double * x, const int incx, const double beta, double * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSPMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DSPMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dspmv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, alpha, ap, x, incx, beta, y, incy);
    } else
        ERROR("liftracc_dspmv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSPMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dspmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const double * alpha, const double * ap, const double * x, const int * incx, const double * beta, double * y, const int * incy)
{
    liftracc_dspmv(*order, *uplo, *n, *alpha, ap, x, *incx, *beta, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dspmv_) dspmv __attribute__ ((alias("liftracc_dspmv_"))); */
/* __typeof__ (liftracc_dspmv_) dspmv_ __attribute__ ((alias("liftracc_dspmv_"))); */
__typeof__ (liftracc_dspmv_) DSPMV __attribute__ ((alias("liftracc_dspmv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dspmv) cblas_dspmv __attribute__ ((alias("liftracc_dspmv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DGER
 */

void liftracc_dger(const liftracc_order_t order, const int m, const int n, const double alpha, const double * x, const int incx, const double * y, const int incy, double * a, const int lda)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DGER]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DGER, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dger");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, m, n, alpha, x, incx, y, incy, a, lda);
    } else
        ERROR("liftracc_dger not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DGER]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dger_(const liftracc_order_t * order, const int * m, const int * n, const double * alpha, const double * x, const int * incx, const double * y, const int * incy, double * a, const int * lda)
{
    liftracc_dger(*order, *m, *n, *alpha, x, *incx, y, *incy, a, *lda);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dger_) dger __attribute__ ((alias("liftracc_dger_"))); */
/* __typeof__ (liftracc_dger_) dger_ __attribute__ ((alias("liftracc_dger_"))); */
__typeof__ (liftracc_dger_) DGER __attribute__ ((alias("liftracc_dger_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dger) cblas_dger __attribute__ ((alias("liftracc_dger")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DSYR
 */

void liftracc_dsyr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * x, const int incx, double * a, const int lda)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSYR]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DSYR, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dsyr");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, alpha, x, incx, a, lda);
    } else
        ERROR("liftracc_dsyr not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSYR]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dsyr_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const double * alpha, const double * x, const int * incx, double * a, const int * lda)
{
    liftracc_dsyr(*order, *uplo, *n, *alpha, x, *incx, a, *lda);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dsyr_) dsyr __attribute__ ((alias("liftracc_dsyr_"))); */
/* __typeof__ (liftracc_dsyr_) dsyr_ __attribute__ ((alias("liftracc_dsyr_"))); */
__typeof__ (liftracc_dsyr_) DSYR __attribute__ ((alias("liftracc_dsyr_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dsyr) cblas_dsyr __attribute__ ((alias("liftracc_dsyr")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DSPR
 */

void liftracc_dspr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * x, const int incx, double * ap)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSPR]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DSPR, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dspr");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, alpha, x, incx, ap);
    } else
        ERROR("liftracc_dspr not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSPR]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dspr_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const double * alpha, const double * x, const int * incx, double * ap)
{
    liftracc_dspr(*order, *uplo, *n, *alpha, x, *incx, ap);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dspr_) dspr __attribute__ ((alias("liftracc_dspr_"))); */
/* __typeof__ (liftracc_dspr_) dspr_ __attribute__ ((alias("liftracc_dspr_"))); */
__typeof__ (liftracc_dspr_) DSPR __attribute__ ((alias("liftracc_dspr_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dspr) cblas_dspr __attribute__ ((alias("liftracc_dspr")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DSYR2
 */

void liftracc_dsyr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * x, const int incx, const double * y, const int incy, double * a, const int lda)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSYR2]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DSYR2, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dsyr2");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, alpha, x, incx, y, incy, a, lda);
    } else
        ERROR("liftracc_dsyr2 not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSYR2]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dsyr2_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const double * alpha, const double * x, const int * incx, const double * y, const int * incy, double * a, const int * lda)
{
    liftracc_dsyr2(*order, *uplo, *n, *alpha, x, *incx, y, *incy, a, *lda);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dsyr2_) dsyr2 __attribute__ ((alias("liftracc_dsyr2_"))); */
/* __typeof__ (liftracc_dsyr2_) dsyr2_ __attribute__ ((alias("liftracc_dsyr2_"))); */
__typeof__ (liftracc_dsyr2_) DSYR2 __attribute__ ((alias("liftracc_dsyr2_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dsyr2) cblas_dsyr2 __attribute__ ((alias("liftracc_dsyr2")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DSPR2
 */

void liftracc_dspr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * x, const int incx, const double * y, const int incy, double * a)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSPR2]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DSPR2, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dspr2");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, alpha, x, incx, y, incy, a);
    } else
        ERROR("liftracc_dspr2 not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSPR2]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dspr2_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const double * alpha, const double * x, const int * incx, const double * y, const int * incy, double * a)
{
    liftracc_dspr2(*order, *uplo, *n, *alpha, x, *incx, y, *incy, a);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dspr2_) dspr2 __attribute__ ((alias("liftracc_dspr2_"))); */
/* __typeof__ (liftracc_dspr2_) dspr2_ __attribute__ ((alias("liftracc_dspr2_"))); */
__typeof__ (liftracc_dspr2_) DSPR2 __attribute__ ((alias("liftracc_dspr2_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dspr2) cblas_dspr2 __attribute__ ((alias("liftracc_dspr2")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CHEMV
 */

void liftracc_chemv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CHEMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CHEMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_chemv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, alpha, a, lda, x, incx, beta, y, incy);
    } else
        ERROR("liftracc_chemv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CHEMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_chemv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const void * alpha, const void * a, const int * lda, const void * x, const int * incx, const void * beta, void * y, const int * incy)
{
    liftracc_chemv(*order, *uplo, *n, alpha, a, *lda, x, *incx, beta, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_chemv_) chemv __attribute__ ((alias("liftracc_chemv_"))); */
/* __typeof__ (liftracc_chemv_) chemv_ __attribute__ ((alias("liftracc_chemv_"))); */
__typeof__ (liftracc_chemv_) CHEMV __attribute__ ((alias("liftracc_chemv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_chemv) cblas_chemv __attribute__ ((alias("liftracc_chemv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CHBMV
 */

void liftracc_chbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const int k, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CHBMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CHBMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_chbmv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, k, alpha, a, lda, x, incx, beta, y, incy);
    } else
        ERROR("liftracc_chbmv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CHBMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_chbmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * x, const int * incx, const void * beta, void * y, const int * incy)
{
    liftracc_chbmv(*order, *uplo, *n, *k, alpha, a, *lda, x, *incx, beta, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_chbmv_) chbmv __attribute__ ((alias("liftracc_chbmv_"))); */
/* __typeof__ (liftracc_chbmv_) chbmv_ __attribute__ ((alias("liftracc_chbmv_"))); */
__typeof__ (liftracc_chbmv_) CHBMV __attribute__ ((alias("liftracc_chbmv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_chbmv) cblas_chbmv __attribute__ ((alias("liftracc_chbmv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CHPMV
 */

void liftracc_chpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * ap, const void * x, const int incx, const void * beta, void * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CHPMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CHPMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_chpmv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, alpha, ap, x, incx, beta, y, incy);
    } else
        ERROR("liftracc_chpmv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CHPMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_chpmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const void * alpha, const void * ap, const void * x, const int * incx, const void * beta, void * y, const int * incy)
{
    liftracc_chpmv(*order, *uplo, *n, alpha, ap, x, *incx, beta, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_chpmv_) chpmv __attribute__ ((alias("liftracc_chpmv_"))); */
/* __typeof__ (liftracc_chpmv_) chpmv_ __attribute__ ((alias("liftracc_chpmv_"))); */
__typeof__ (liftracc_chpmv_) CHPMV __attribute__ ((alias("liftracc_chpmv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_chpmv) cblas_chpmv __attribute__ ((alias("liftracc_chpmv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CGERU
 */

void liftracc_cgeru(const liftracc_order_t order, const int m, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CGERU]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CGERU, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_cgeru");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, m, n, alpha, x, incx, y, incy, a, lda);
    } else
        ERROR("liftracc_cgeru not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CGERU]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_cgeru_(const liftracc_order_t * order, const int * m, const int * n, const void * alpha, const void * x, const int * incx, const void * y, const int * incy, void * a, const int * lda)
{
    liftracc_cgeru(*order, *m, *n, alpha, x, *incx, y, *incy, a, *lda);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_cgeru_) cgeru __attribute__ ((alias("liftracc_cgeru_"))); */
/* __typeof__ (liftracc_cgeru_) cgeru_ __attribute__ ((alias("liftracc_cgeru_"))); */
__typeof__ (liftracc_cgeru_) CGERU __attribute__ ((alias("liftracc_cgeru_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_cgeru) cblas_cgeru __attribute__ ((alias("liftracc_cgeru")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CGERC
 */

void liftracc_cgerc(const liftracc_order_t order, const int m, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CGERC]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CGERC, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_cgerc");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, m, n, alpha, x, incx, y, incy, a, lda);
    } else
        ERROR("liftracc_cgerc not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CGERC]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_cgerc_(const liftracc_order_t * order, const int * m, const int * n, const void * alpha, const void * x, const int * incx, const void * y, const int * incy, void * a, const int * lda)
{
    liftracc_cgerc(*order, *m, *n, alpha, x, *incx, y, *incy, a, *lda);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_cgerc_) cgerc __attribute__ ((alias("liftracc_cgerc_"))); */
/* __typeof__ (liftracc_cgerc_) cgerc_ __attribute__ ((alias("liftracc_cgerc_"))); */
__typeof__ (liftracc_cgerc_) CGERC __attribute__ ((alias("liftracc_cgerc_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_cgerc) cblas_cgerc __attribute__ ((alias("liftracc_cgerc")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CHER
 */

void liftracc_cher(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const void * x, const int incx, void * a, const int lda)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CHER]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CHER, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_cher");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, alpha, x, incx, a, lda);
    } else
        ERROR("liftracc_cher not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CHER]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_cher_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const float * alpha, const void * x, const int * incx, void * a, const int * lda)
{
    liftracc_cher(*order, *uplo, *n, *alpha, x, *incx, a, *lda);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_cher_) cher __attribute__ ((alias("liftracc_cher_"))); */
/* __typeof__ (liftracc_cher_) cher_ __attribute__ ((alias("liftracc_cher_"))); */
__typeof__ (liftracc_cher_) CHER __attribute__ ((alias("liftracc_cher_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_cher) cblas_cher __attribute__ ((alias("liftracc_cher")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CHPR
 */

void liftracc_chpr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const void * x, const int incx, void * a)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CHPR]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CHPR, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_chpr");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, alpha, x, incx, a);
    } else
        ERROR("liftracc_chpr not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CHPR]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_chpr_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const float * alpha, const void * x, const int * incx, void * a)
{
    liftracc_chpr(*order, *uplo, *n, *alpha, x, *incx, a);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_chpr_) chpr __attribute__ ((alias("liftracc_chpr_"))); */
/* __typeof__ (liftracc_chpr_) chpr_ __attribute__ ((alias("liftracc_chpr_"))); */
__typeof__ (liftracc_chpr_) CHPR __attribute__ ((alias("liftracc_chpr_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_chpr) cblas_chpr __attribute__ ((alias("liftracc_chpr")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CHER2
 */

void liftracc_cher2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CHER2]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CHER2, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_cher2");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, alpha, x, incx, y, incy, a, lda);
    } else
        ERROR("liftracc_cher2 not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CHER2]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_cher2_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const void * alpha, const void * x, const int * incx, const void * y, const int * incy, void * a, const int * lda)
{
    liftracc_cher2(*order, *uplo, *n, alpha, x, *incx, y, *incy, a, *lda);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_cher2_) cher2 __attribute__ ((alias("liftracc_cher2_"))); */
/* __typeof__ (liftracc_cher2_) cher2_ __attribute__ ((alias("liftracc_cher2_"))); */
__typeof__ (liftracc_cher2_) CHER2 __attribute__ ((alias("liftracc_cher2_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_cher2) cblas_cher2 __attribute__ ((alias("liftracc_cher2")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CHPR2
 */

void liftracc_chpr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * ap)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CHPR2]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CHPR2, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_chpr2");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, alpha, x, incx, y, incy, ap);
    } else
        ERROR("liftracc_chpr2 not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CHPR2]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_chpr2_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const void * alpha, const void * x, const int * incx, const void * y, const int * incy, void * ap)
{
    liftracc_chpr2(*order, *uplo, *n, alpha, x, *incx, y, *incy, ap);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_chpr2_) chpr2 __attribute__ ((alias("liftracc_chpr2_"))); */
/* __typeof__ (liftracc_chpr2_) chpr2_ __attribute__ ((alias("liftracc_chpr2_"))); */
__typeof__ (liftracc_chpr2_) CHPR2 __attribute__ ((alias("liftracc_chpr2_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_chpr2) cblas_chpr2 __attribute__ ((alias("liftracc_chpr2")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZHEMV
 */

void liftracc_zhemv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZHEMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZHEMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zhemv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, alpha, a, lda, x, incx, beta, y, incy);
    } else
        ERROR("liftracc_zhemv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZHEMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zhemv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const void * alpha, const void * a, const int * lda, const void * x, const int * incx, const void * beta, void * y, const int * incy)
{
    liftracc_zhemv(*order, *uplo, *n, alpha, a, *lda, x, *incx, beta, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zhemv_) zhemv __attribute__ ((alias("liftracc_zhemv_"))); */
/* __typeof__ (liftracc_zhemv_) zhemv_ __attribute__ ((alias("liftracc_zhemv_"))); */
__typeof__ (liftracc_zhemv_) ZHEMV __attribute__ ((alias("liftracc_zhemv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zhemv) cblas_zhemv __attribute__ ((alias("liftracc_zhemv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZHBMV
 */

void liftracc_zhbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const int k, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZHBMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZHBMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zhbmv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, k, alpha, a, lda, x, incx, beta, y, incy);
    } else
        ERROR("liftracc_zhbmv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZHBMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zhbmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * x, const int * incx, const void * beta, void * y, const int * incy)
{
    liftracc_zhbmv(*order, *uplo, *n, *k, alpha, a, *lda, x, *incx, beta, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zhbmv_) zhbmv __attribute__ ((alias("liftracc_zhbmv_"))); */
/* __typeof__ (liftracc_zhbmv_) zhbmv_ __attribute__ ((alias("liftracc_zhbmv_"))); */
__typeof__ (liftracc_zhbmv_) ZHBMV __attribute__ ((alias("liftracc_zhbmv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zhbmv) cblas_zhbmv __attribute__ ((alias("liftracc_zhbmv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZHPMV
 */

void liftracc_zhpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * ap, const void * x, const int incx, const void * beta, void * y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZHPMV]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZHPMV, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zhpmv");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, alpha, ap, x, incx, beta, y, incy);
    } else
        ERROR("liftracc_zhpmv not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZHPMV]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zhpmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const void * alpha, const void * ap, const void * x, const int * incx, const void * beta, void * y, const int * incy)
{
    liftracc_zhpmv(*order, *uplo, *n, alpha, ap, x, *incx, beta, y, *incy);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zhpmv_) zhpmv __attribute__ ((alias("liftracc_zhpmv_"))); */
/* __typeof__ (liftracc_zhpmv_) zhpmv_ __attribute__ ((alias("liftracc_zhpmv_"))); */
__typeof__ (liftracc_zhpmv_) ZHPMV __attribute__ ((alias("liftracc_zhpmv_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zhpmv) cblas_zhpmv __attribute__ ((alias("liftracc_zhpmv")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZGERU
 */

void liftracc_zgeru(const liftracc_order_t order, const int m, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZGERU]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZGERU, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zgeru");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, m, n, alpha, x, incx, y, incy, a, lda);
    } else
        ERROR("liftracc_zgeru not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZGERU]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zgeru_(const liftracc_order_t * order, const int * m, const int * n, const void * alpha, const void * x, const int * incx, const void * y, const int * incy, void * a, const int * lda)
{
    liftracc_zgeru(*order, *m, *n, alpha, x, *incx, y, *incy, a, *lda);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zgeru_) zgeru __attribute__ ((alias("liftracc_zgeru_"))); */
/* __typeof__ (liftracc_zgeru_) zgeru_ __attribute__ ((alias("liftracc_zgeru_"))); */
__typeof__ (liftracc_zgeru_) ZGERU __attribute__ ((alias("liftracc_zgeru_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zgeru) cblas_zgeru __attribute__ ((alias("liftracc_zgeru")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZGERC
 */

void liftracc_zgerc(const liftracc_order_t order, const int m, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZGERC]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZGERC, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zgerc");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, m, n, alpha, x, incx, y, incy, a, lda);
    } else
        ERROR("liftracc_zgerc not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZGERC]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zgerc_(const liftracc_order_t * order, const int * m, const int * n, const void * alpha, const void * x, const int * incx, const void * y, const int * incy, void * a, const int * lda)
{
    liftracc_zgerc(*order, *m, *n, alpha, x, *incx, y, *incy, a, *lda);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zgerc_) zgerc __attribute__ ((alias("liftracc_zgerc_"))); */
/* __typeof__ (liftracc_zgerc_) zgerc_ __attribute__ ((alias("liftracc_zgerc_"))); */
__typeof__ (liftracc_zgerc_) ZGERC __attribute__ ((alias("liftracc_zgerc_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zgerc) cblas_zgerc __attribute__ ((alias("liftracc_zgerc")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZHER
 */

void liftracc_zher(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const void * x, const int incx, void * a, const int lda)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZHER]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZHER, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zher");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, alpha, x, incx, a, lda);
    } else
        ERROR("liftracc_zher not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZHER]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zher_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const double * alpha, const void * x, const int * incx, void * a, const int * lda)
{
    liftracc_zher(*order, *uplo, *n, *alpha, x, *incx, a, *lda);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zher_) zher __attribute__ ((alias("liftracc_zher_"))); */
/* __typeof__ (liftracc_zher_) zher_ __attribute__ ((alias("liftracc_zher_"))); */
__typeof__ (liftracc_zher_) ZHER __attribute__ ((alias("liftracc_zher_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zher) cblas_zher __attribute__ ((alias("liftracc_zher")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZHPR
 */

void liftracc_zhpr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const void * x, const int incx, void * a)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZHPR]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZHPR, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zhpr");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, alpha, x, incx, a);
    } else
        ERROR("liftracc_zhpr not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZHPR]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zhpr_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const double * alpha, const void * x, const int * incx, void * a)
{
    liftracc_zhpr(*order, *uplo, *n, *alpha, x, *incx, a);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zhpr_) zhpr __attribute__ ((alias("liftracc_zhpr_"))); */
/* __typeof__ (liftracc_zhpr_) zhpr_ __attribute__ ((alias("liftracc_zhpr_"))); */
__typeof__ (liftracc_zhpr_) ZHPR __attribute__ ((alias("liftracc_zhpr_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zhpr) cblas_zhpr __attribute__ ((alias("liftracc_zhpr")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZHER2
 */

void liftracc_zher2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZHER2]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZHER2, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zher2");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, alpha, x, incx, y, incy, a, lda);
    } else
        ERROR("liftracc_zher2 not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZHER2]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zher2_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const void * alpha, const void * x, const int * incx, const void * y, const int * incy, void * a, const int * lda)
{
    liftracc_zher2(*order, *uplo, *n, alpha, x, *incx, y, *incy, a, *lda);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zher2_) zher2 __attribute__ ((alias("liftracc_zher2_"))); */
/* __typeof__ (liftracc_zher2_) zher2_ __attribute__ ((alias("liftracc_zher2_"))); */
__typeof__ (liftracc_zher2_) ZHER2 __attribute__ ((alias("liftracc_zher2_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zher2) cblas_zher2 __attribute__ ((alias("liftracc_zher2")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZHPR2
 */

void liftracc_zhpr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * ap)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZHPR2]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZHPR2, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zhpr2");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, n, alpha, x, incx, y, incy, ap);
    } else
        ERROR("liftracc_zhpr2 not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZHPR2]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zhpr2_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const void * alpha, const void * x, const int * incx, const void * y, const int * incy, void * ap)
{
    liftracc_zhpr2(*order, *uplo, *n, alpha, x, *incx, y, *incy, ap);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zhpr2_) zhpr2 __attribute__ ((alias("liftracc_zhpr2_"))); */
/* __typeof__ (liftracc_zhpr2_) zhpr2_ __attribute__ ((alias("liftracc_zhpr2_"))); */
__typeof__ (liftracc_zhpr2_) ZHPR2 __attribute__ ((alias("liftracc_zhpr2_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zhpr2) cblas_zhpr2 __attribute__ ((alias("liftracc_zhpr2")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SGEMM
 */

void liftracc_sgemm(const liftracc_order_t order, const liftracc_transpose_t transa, const liftracc_transpose_t transb, const int m, const int n, const int k, const float alpha, const float * a, const int lda, const float * b, const int ldb, const float beta, float * c, const int ldc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SGEMM]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SGEMM, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_sgemm");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
    } else
        ERROR("liftracc_sgemm not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SGEMM]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_sgemm_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const liftracc_transpose_t * transb, const int * m, const int * n, const int * k, const float * alpha, const float * a, const int * lda, const float * b, const int * ldb, const float * beta, float * c, const int * ldc)
{
    liftracc_sgemm(*order, *transa, *transb, *m, *n, *k, *alpha, a, *lda, b, *ldb, *beta, c, *ldc);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_sgemm_) sgemm __attribute__ ((alias("liftracc_sgemm_"))); */
/* __typeof__ (liftracc_sgemm_) sgemm_ __attribute__ ((alias("liftracc_sgemm_"))); */
__typeof__ (liftracc_sgemm_) SGEMM __attribute__ ((alias("liftracc_sgemm_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_sgemm) cblas_sgemm __attribute__ ((alias("liftracc_sgemm")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SSYMM
 */

void liftracc_ssymm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const float alpha, const float * a, const int lda, const float * b, const int ldb, const float beta, float * c, const int ldc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SSYMM]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SSYMM, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ssymm");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, side, uplo, m, n, alpha, a, lda, b, ldb, beta, c, ldc);
    } else
        ERROR("liftracc_ssymm not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SSYMM]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_ssymm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const int * m, const int * n, const float * alpha, const float * a, const int * lda, const float * b, const int * ldb, const float * beta, float * c, const int * ldc)
{
    liftracc_ssymm(*order, *side, *uplo, *m, *n, *alpha, a, *lda, b, *ldb, *beta, c, *ldc);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ssymm_) ssymm __attribute__ ((alias("liftracc_ssymm_"))); */
/* __typeof__ (liftracc_ssymm_) ssymm_ __attribute__ ((alias("liftracc_ssymm_"))); */
__typeof__ (liftracc_ssymm_) SSYMM __attribute__ ((alias("liftracc_ssymm_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ssymm) cblas_ssymm __attribute__ ((alias("liftracc_ssymm")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SSYRK
 */

void liftracc_ssyrk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const float alpha, const float * a, const int lda, const float beta, float * c, const int ldc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SSYRK]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SSYRK, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ssyrk");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, trans, n, k, alpha, a, lda, beta, c, ldc);
    } else
        ERROR("liftracc_ssyrk not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SSYRK]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_ssyrk_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const float * alpha, const float * a, const int * lda, const float * beta, float * c, const int * ldc)
{
    liftracc_ssyrk(*order, *uplo, *trans, *n, *k, *alpha, a, *lda, *beta, c, *ldc);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ssyrk_) ssyrk __attribute__ ((alias("liftracc_ssyrk_"))); */
/* __typeof__ (liftracc_ssyrk_) ssyrk_ __attribute__ ((alias("liftracc_ssyrk_"))); */
__typeof__ (liftracc_ssyrk_) SSYRK __attribute__ ((alias("liftracc_ssyrk_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ssyrk) cblas_ssyrk __attribute__ ((alias("liftracc_ssyrk")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * SSYR2K
 */

void liftracc_ssyr2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const float alpha, const float * a, const int lda, const float * b, const int ldb, const float beta, float * c, const int ldc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SSYR2K]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_SSYR2K, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ssyr2k");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, trans, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
    } else
        ERROR("liftracc_ssyr2k not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_SSYR2K]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_ssyr2k_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const float * alpha, const float * a, const int * lda, const float * b, const int * ldb, const float * beta, float * c, const int * ldc)
{
    liftracc_ssyr2k(*order, *uplo, *trans, *n, *k, *alpha, a, *lda, b, *ldb, *beta, c, *ldc);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ssyr2k_) ssyr2k __attribute__ ((alias("liftracc_ssyr2k_"))); */
/* __typeof__ (liftracc_ssyr2k_) ssyr2k_ __attribute__ ((alias("liftracc_ssyr2k_"))); */
__typeof__ (liftracc_ssyr2k_) SSYR2K __attribute__ ((alias("liftracc_ssyr2k_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ssyr2k) cblas_ssyr2k __attribute__ ((alias("liftracc_ssyr2k")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * STRMM
 */

void liftracc_strmm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const float alpha, const float * a, const int lda, float * b, const int ldb)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_STRMM]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_STRMM, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_strmm");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
    } else
        ERROR("liftracc_strmm not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_STRMM]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_strmm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * m, const int * n, const float * alpha, const float * a, const int * lda, float * b, const int * ldb)
{
    liftracc_strmm(*order, *side, *uplo, *transa, *diag, *m, *n, *alpha, a, *lda, b, *ldb);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_strmm_) strmm __attribute__ ((alias("liftracc_strmm_"))); */
/* __typeof__ (liftracc_strmm_) strmm_ __attribute__ ((alias("liftracc_strmm_"))); */
__typeof__ (liftracc_strmm_) STRMM __attribute__ ((alias("liftracc_strmm_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_strmm) cblas_strmm __attribute__ ((alias("liftracc_strmm")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * STRSM
 */

void liftracc_strsm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const float alpha, const float * a, const int lda, float * b, const int ldb)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_STRSM]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_STRSM, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_strsm");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
    } else
        ERROR("liftracc_strsm not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_STRSM]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_strsm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * m, const int * n, const float * alpha, const float * a, const int * lda, float * b, const int * ldb)
{
    liftracc_strsm(*order, *side, *uplo, *transa, *diag, *m, *n, *alpha, a, *lda, b, *ldb);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_strsm_) strsm __attribute__ ((alias("liftracc_strsm_"))); */
/* __typeof__ (liftracc_strsm_) strsm_ __attribute__ ((alias("liftracc_strsm_"))); */
__typeof__ (liftracc_strsm_) STRSM __attribute__ ((alias("liftracc_strsm_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_strsm) cblas_strsm __attribute__ ((alias("liftracc_strsm")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DGEMM
 */

void liftracc_dgemm(const liftracc_order_t order, const liftracc_transpose_t transa, const liftracc_transpose_t transb, const int m, const int n, const int k, const double alpha, const double * a, const int lda, const double * b, const int ldb, const double beta, double * c, const int ldc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DGEMM]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DGEMM, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dgemm");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
    } else
        ERROR("liftracc_dgemm not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DGEMM]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dgemm_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const liftracc_transpose_t * transb, const int * m, const int * n, const int * k, const double * alpha, const double * a, const int * lda, const double * b, const int * ldb, const double * beta, double * c, const int * ldc)
{
    liftracc_dgemm(*order, *transa, *transb, *m, *n, *k, *alpha, a, *lda, b, *ldb, *beta, c, *ldc);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dgemm_) dgemm __attribute__ ((alias("liftracc_dgemm_"))); */
/* __typeof__ (liftracc_dgemm_) dgemm_ __attribute__ ((alias("liftracc_dgemm_"))); */
__typeof__ (liftracc_dgemm_) DGEMM __attribute__ ((alias("liftracc_dgemm_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dgemm) cblas_dgemm __attribute__ ((alias("liftracc_dgemm")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DSYMM
 */

void liftracc_dsymm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const double alpha, const double * a, const int lda, const double * b, const int ldb, const double beta, double * c, const int ldc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSYMM]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DSYMM, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dsymm");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, side, uplo, m, n, alpha, a, lda, b, ldb, beta, c, ldc);
    } else
        ERROR("liftracc_dsymm not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSYMM]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dsymm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const int * m, const int * n, const double * alpha, const double * a, const int * lda, const double * b, const int * ldb, const double * beta, double * c, const int * ldc)
{
    liftracc_dsymm(*order, *side, *uplo, *m, *n, *alpha, a, *lda, b, *ldb, *beta, c, *ldc);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dsymm_) dsymm __attribute__ ((alias("liftracc_dsymm_"))); */
/* __typeof__ (liftracc_dsymm_) dsymm_ __attribute__ ((alias("liftracc_dsymm_"))); */
__typeof__ (liftracc_dsymm_) DSYMM __attribute__ ((alias("liftracc_dsymm_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dsymm) cblas_dsymm __attribute__ ((alias("liftracc_dsymm")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DSYRK
 */

void liftracc_dsyrk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const double alpha, const double * a, const int lda, const double beta, double * c, const int ldc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSYRK]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DSYRK, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dsyrk");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, trans, n, k, alpha, a, lda, beta, c, ldc);
    } else
        ERROR("liftracc_dsyrk not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSYRK]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dsyrk_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const double * alpha, const double * a, const int * lda, const double * beta, double * c, const int * ldc)
{
    liftracc_dsyrk(*order, *uplo, *trans, *n, *k, *alpha, a, *lda, *beta, c, *ldc);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dsyrk_) dsyrk __attribute__ ((alias("liftracc_dsyrk_"))); */
/* __typeof__ (liftracc_dsyrk_) dsyrk_ __attribute__ ((alias("liftracc_dsyrk_"))); */
__typeof__ (liftracc_dsyrk_) DSYRK __attribute__ ((alias("liftracc_dsyrk_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dsyrk) cblas_dsyrk __attribute__ ((alias("liftracc_dsyrk")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DSYR2K
 */

void liftracc_dsyr2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const double alpha, const double * a, const int lda, const double * b, const int ldb, const double beta, double * c, const int ldc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSYR2K]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DSYR2K, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dsyr2k");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, trans, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
    } else
        ERROR("liftracc_dsyr2k not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSYR2K]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dsyr2k_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const double * alpha, const double * a, const int * lda, const double * b, const int * ldb, const double * beta, double * c, const int * ldc)
{
    liftracc_dsyr2k(*order, *uplo, *trans, *n, *k, *alpha, a, *lda, b, *ldb, *beta, c, *ldc);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dsyr2k_) dsyr2k __attribute__ ((alias("liftracc_dsyr2k_"))); */
/* __typeof__ (liftracc_dsyr2k_) dsyr2k_ __attribute__ ((alias("liftracc_dsyr2k_"))); */
__typeof__ (liftracc_dsyr2k_) DSYR2K __attribute__ ((alias("liftracc_dsyr2k_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dsyr2k) cblas_dsyr2k __attribute__ ((alias("liftracc_dsyr2k")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DTRMM
 */

void liftracc_dtrmm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const double alpha, const double * a, const int lda, double * b, const int ldb)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DTRMM]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DTRMM, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dtrmm");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
    } else
        ERROR("liftracc_dtrmm not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DTRMM]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dtrmm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * m, const int * n, const double * alpha, const double * a, const int * lda, double * b, const int * ldb)
{
    liftracc_dtrmm(*order, *side, *uplo, *transa, *diag, *m, *n, *alpha, a, *lda, b, *ldb);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dtrmm_) dtrmm __attribute__ ((alias("liftracc_dtrmm_"))); */
/* __typeof__ (liftracc_dtrmm_) dtrmm_ __attribute__ ((alias("liftracc_dtrmm_"))); */
__typeof__ (liftracc_dtrmm_) DTRMM __attribute__ ((alias("liftracc_dtrmm_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dtrmm) cblas_dtrmm __attribute__ ((alias("liftracc_dtrmm")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * DTRSM
 */

void liftracc_dtrsm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const double alpha, const double * a, const int lda, double * b, const int ldb)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DTRSM]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_DTRSM, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_dtrsm");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
    } else
        ERROR("liftracc_dtrsm not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DTRSM]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_dtrsm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * m, const int * n, const double * alpha, const double * a, const int * lda, double * b, const int * ldb)
{
    liftracc_dtrsm(*order, *side, *uplo, *transa, *diag, *m, *n, *alpha, a, *lda, b, *ldb);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_dtrsm_) dtrsm __attribute__ ((alias("liftracc_dtrsm_"))); */
/* __typeof__ (liftracc_dtrsm_) dtrsm_ __attribute__ ((alias("liftracc_dtrsm_"))); */
__typeof__ (liftracc_dtrsm_) DTRSM __attribute__ ((alias("liftracc_dtrsm_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_dtrsm) cblas_dtrsm __attribute__ ((alias("liftracc_dtrsm")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CGEMM
 */

void liftracc_cgemm(const liftracc_order_t order, const liftracc_transpose_t transa, const liftracc_transpose_t transb, const int m, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CGEMM]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CGEMM, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_cgemm");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
    } else
        ERROR("liftracc_cgemm not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CGEMM]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_cgemm_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const liftracc_transpose_t * transb, const int * m, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const void * beta, void * c, const int * ldc)
{
    liftracc_cgemm(*order, *transa, *transb, *m, *n, *k, alpha, a, *lda, b, *ldb, beta, c, *ldc);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_cgemm_) cgemm __attribute__ ((alias("liftracc_cgemm_"))); */
/* __typeof__ (liftracc_cgemm_) cgemm_ __attribute__ ((alias("liftracc_cgemm_"))); */
__typeof__ (liftracc_cgemm_) CGEMM __attribute__ ((alias("liftracc_cgemm_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_cgemm) cblas_cgemm __attribute__ ((alias("liftracc_cgemm")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CSYMM
 */

void liftracc_csymm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CSYMM]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CSYMM, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_csymm");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, side, uplo, m, n, alpha, a, lda, b, ldb, beta, c, ldc);
    } else
        ERROR("liftracc_csymm not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CSYMM]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_csymm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const int * m, const int * n, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const void * beta, void * c, const int * ldc)
{
    liftracc_csymm(*order, *side, *uplo, *m, *n, alpha, a, *lda, b, *ldb, beta, c, *ldc);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_csymm_) csymm __attribute__ ((alias("liftracc_csymm_"))); */
/* __typeof__ (liftracc_csymm_) csymm_ __attribute__ ((alias("liftracc_csymm_"))); */
__typeof__ (liftracc_csymm_) CSYMM __attribute__ ((alias("liftracc_csymm_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_csymm) cblas_csymm __attribute__ ((alias("liftracc_csymm")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CSYRK
 */

void liftracc_csyrk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * beta, void * c, const int ldc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CSYRK]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CSYRK, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_csyrk");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, trans, n, k, alpha, a, lda, beta, c, ldc);
    } else
        ERROR("liftracc_csyrk not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CSYRK]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_csyrk_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * beta, void * c, const int * ldc)
{
    liftracc_csyrk(*order, *uplo, *trans, *n, *k, alpha, a, *lda, beta, c, *ldc);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_csyrk_) csyrk __attribute__ ((alias("liftracc_csyrk_"))); */
/* __typeof__ (liftracc_csyrk_) csyrk_ __attribute__ ((alias("liftracc_csyrk_"))); */
__typeof__ (liftracc_csyrk_) CSYRK __attribute__ ((alias("liftracc_csyrk_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_csyrk) cblas_csyrk __attribute__ ((alias("liftracc_csyrk")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CSYR2K
 */

void liftracc_csyr2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CSYR2K]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CSYR2K, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_csyr2k");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, trans, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
    } else
        ERROR("liftracc_csyr2k not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CSYR2K]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_csyr2k_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const void * beta, void * c, const int * ldc)
{
    liftracc_csyr2k(*order, *uplo, *trans, *n, *k, alpha, a, *lda, b, *ldb, beta, c, *ldc);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_csyr2k_) csyr2k __attribute__ ((alias("liftracc_csyr2k_"))); */
/* __typeof__ (liftracc_csyr2k_) csyr2k_ __attribute__ ((alias("liftracc_csyr2k_"))); */
__typeof__ (liftracc_csyr2k_) CSYR2K __attribute__ ((alias("liftracc_csyr2k_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_csyr2k) cblas_csyr2k __attribute__ ((alias("liftracc_csyr2k")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CTRMM
 */

void liftracc_ctrmm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const void * alpha, const void * a, const int lda, void * b, const int ldb)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CTRMM]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CTRMM, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ctrmm");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
    } else
        ERROR("liftracc_ctrmm not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CTRMM]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_ctrmm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * m, const int * n, const void * alpha, const void * a, const int * lda, void * b, const int * ldb)
{
    liftracc_ctrmm(*order, *side, *uplo, *transa, *diag, *m, *n, alpha, a, *lda, b, *ldb);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ctrmm_) ctrmm __attribute__ ((alias("liftracc_ctrmm_"))); */
/* __typeof__ (liftracc_ctrmm_) ctrmm_ __attribute__ ((alias("liftracc_ctrmm_"))); */
__typeof__ (liftracc_ctrmm_) CTRMM __attribute__ ((alias("liftracc_ctrmm_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ctrmm) cblas_ctrmm __attribute__ ((alias("liftracc_ctrmm")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CTRSM
 */

void liftracc_ctrsm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const void * alpha, const void * a, const int lda, void * b, const int ldb)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CTRSM]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CTRSM, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ctrsm");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
    } else
        ERROR("liftracc_ctrsm not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CTRSM]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_ctrsm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * m, const int * n, const void * alpha, const void * a, const int * lda, void * b, const int * ldb)
{
    liftracc_ctrsm(*order, *side, *uplo, *transa, *diag, *m, *n, alpha, a, *lda, b, *ldb);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ctrsm_) ctrsm __attribute__ ((alias("liftracc_ctrsm_"))); */
/* __typeof__ (liftracc_ctrsm_) ctrsm_ __attribute__ ((alias("liftracc_ctrsm_"))); */
__typeof__ (liftracc_ctrsm_) CTRSM __attribute__ ((alias("liftracc_ctrsm_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ctrsm) cblas_ctrsm __attribute__ ((alias("liftracc_ctrsm")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZGEMM
 */

void liftracc_zgemm(const liftracc_order_t order, const liftracc_transpose_t transa, const liftracc_transpose_t transb, const int m, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZGEMM]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZGEMM, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zgemm");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, transa, transb, m, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
    } else
        ERROR("liftracc_zgemm not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZGEMM]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zgemm_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const liftracc_transpose_t * transb, const int * m, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const void * beta, void * c, const int * ldc)
{
    liftracc_zgemm(*order, *transa, *transb, *m, *n, *k, alpha, a, *lda, b, *ldb, beta, c, *ldc);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zgemm_) zgemm __attribute__ ((alias("liftracc_zgemm_"))); */
/* __typeof__ (liftracc_zgemm_) zgemm_ __attribute__ ((alias("liftracc_zgemm_"))); */
__typeof__ (liftracc_zgemm_) ZGEMM __attribute__ ((alias("liftracc_zgemm_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zgemm) cblas_zgemm __attribute__ ((alias("liftracc_zgemm")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZSYMM
 */

void liftracc_zsymm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZSYMM]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZSYMM, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zsymm");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, side, uplo, m, n, alpha, a, lda, b, ldb, beta, c, ldc);
    } else
        ERROR("liftracc_zsymm not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZSYMM]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zsymm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const int * m, const int * n, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const void * beta, void * c, const int * ldc)
{
    liftracc_zsymm(*order, *side, *uplo, *m, *n, alpha, a, *lda, b, *ldb, beta, c, *ldc);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zsymm_) zsymm __attribute__ ((alias("liftracc_zsymm_"))); */
/* __typeof__ (liftracc_zsymm_) zsymm_ __attribute__ ((alias("liftracc_zsymm_"))); */
__typeof__ (liftracc_zsymm_) ZSYMM __attribute__ ((alias("liftracc_zsymm_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zsymm) cblas_zsymm __attribute__ ((alias("liftracc_zsymm")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZSYRK
 */

void liftracc_zsyrk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * beta, void * c, const int ldc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZSYRK]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZSYRK, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zsyrk");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, trans, n, k, alpha, a, lda, beta, c, ldc);
    } else
        ERROR("liftracc_zsyrk not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZSYRK]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zsyrk_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * beta, void * c, const int * ldc)
{
    liftracc_zsyrk(*order, *uplo, *trans, *n, *k, alpha, a, *lda, beta, c, *ldc);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zsyrk_) zsyrk __attribute__ ((alias("liftracc_zsyrk_"))); */
/* __typeof__ (liftracc_zsyrk_) zsyrk_ __attribute__ ((alias("liftracc_zsyrk_"))); */
__typeof__ (liftracc_zsyrk_) ZSYRK __attribute__ ((alias("liftracc_zsyrk_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zsyrk) cblas_zsyrk __attribute__ ((alias("liftracc_zsyrk")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZSYR2K
 */

void liftracc_zsyr2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZSYR2K]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZSYR2K, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zsyr2k");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, trans, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
    } else
        ERROR("liftracc_zsyr2k not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZSYR2K]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zsyr2k_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const void * beta, void * c, const int * ldc)
{
    liftracc_zsyr2k(*order, *uplo, *trans, *n, *k, alpha, a, *lda, b, *ldb, beta, c, *ldc);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zsyr2k_) zsyr2k __attribute__ ((alias("liftracc_zsyr2k_"))); */
/* __typeof__ (liftracc_zsyr2k_) zsyr2k_ __attribute__ ((alias("liftracc_zsyr2k_"))); */
__typeof__ (liftracc_zsyr2k_) ZSYR2K __attribute__ ((alias("liftracc_zsyr2k_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zsyr2k) cblas_zsyr2k __attribute__ ((alias("liftracc_zsyr2k")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZTRMM
 */

void liftracc_ztrmm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const void * alpha, const void * a, const int lda, void * b, const int ldb)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZTRMM]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZTRMM, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ztrmm");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
    } else
        ERROR("liftracc_ztrmm not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZTRMM]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_ztrmm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * m, const int * n, const void * alpha, const void * a, const int * lda, void * b, const int * ldb)
{
    liftracc_ztrmm(*order, *side, *uplo, *transa, *diag, *m, *n, alpha, a, *lda, b, *ldb);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ztrmm_) ztrmm __attribute__ ((alias("liftracc_ztrmm_"))); */
/* __typeof__ (liftracc_ztrmm_) ztrmm_ __attribute__ ((alias("liftracc_ztrmm_"))); */
__typeof__ (liftracc_ztrmm_) ZTRMM __attribute__ ((alias("liftracc_ztrmm_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ztrmm) cblas_ztrmm __attribute__ ((alias("liftracc_ztrmm")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZTRSM
 */

void liftracc_ztrsm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const void * alpha, const void * a, const int lda, void * b, const int ldb)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZTRSM]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZTRSM, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_ztrsm");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, side, uplo, transa, diag, m, n, alpha, a, lda, b, ldb);
    } else
        ERROR("liftracc_ztrsm not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZTRSM]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_ztrsm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * m, const int * n, const void * alpha, const void * a, const int * lda, void * b, const int * ldb)
{
    liftracc_ztrsm(*order, *side, *uplo, *transa, *diag, *m, *n, alpha, a, *lda, b, *ldb);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_ztrsm_) ztrsm __attribute__ ((alias("liftracc_ztrsm_"))); */
/* __typeof__ (liftracc_ztrsm_) ztrsm_ __attribute__ ((alias("liftracc_ztrsm_"))); */
__typeof__ (liftracc_ztrsm_) ZTRSM __attribute__ ((alias("liftracc_ztrsm_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_ztrsm) cblas_ztrsm __attribute__ ((alias("liftracc_ztrsm")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CHEMM
 */

void liftracc_chemm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CHEMM]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CHEMM, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_chemm");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, side, uplo, m, n, alpha, a, lda, b, ldb, beta, c, ldc);
    } else
        ERROR("liftracc_chemm not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CHEMM]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_chemm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const int * m, const int * n, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const void * beta, void * c, const int * ldc)
{
    liftracc_chemm(*order, *side, *uplo, *m, *n, alpha, a, *lda, b, *ldb, beta, c, *ldc);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_chemm_) chemm __attribute__ ((alias("liftracc_chemm_"))); */
/* __typeof__ (liftracc_chemm_) chemm_ __attribute__ ((alias("liftracc_chemm_"))); */
__typeof__ (liftracc_chemm_) CHEMM __attribute__ ((alias("liftracc_chemm_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_chemm) cblas_chemm __attribute__ ((alias("liftracc_chemm")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CHERK
 */

void liftracc_cherk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const float alpha, const void * a, const int lda, const float beta, void * c, const int ldc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CHERK]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CHERK, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_cherk");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, trans, n, k, alpha, a, lda, beta, c, ldc);
    } else
        ERROR("liftracc_cherk not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CHERK]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_cherk_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const float * alpha, const void * a, const int * lda, const float * beta, void * c, const int * ldc)
{
    liftracc_cherk(*order, *uplo, *trans, *n, *k, *alpha, a, *lda, *beta, c, *ldc);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_cherk_) cherk __attribute__ ((alias("liftracc_cherk_"))); */
/* __typeof__ (liftracc_cherk_) cherk_ __attribute__ ((alias("liftracc_cherk_"))); */
__typeof__ (liftracc_cherk_) CHERK __attribute__ ((alias("liftracc_cherk_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_cherk) cblas_cherk __attribute__ ((alias("liftracc_cherk")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * CHER2K
 */

void liftracc_cher2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const float beta, void * c, const int ldc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CHER2K]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_CHER2K, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_cher2k");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, trans, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
    } else
        ERROR("liftracc_cher2k not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_CHER2K]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_cher2k_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const float * beta, void * c, const int * ldc)
{
    liftracc_cher2k(*order, *uplo, *trans, *n, *k, alpha, a, *lda, b, *ldb, *beta, c, *ldc);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_cher2k_) cher2k __attribute__ ((alias("liftracc_cher2k_"))); */
/* __typeof__ (liftracc_cher2k_) cher2k_ __attribute__ ((alias("liftracc_cher2k_"))); */
__typeof__ (liftracc_cher2k_) CHER2K __attribute__ ((alias("liftracc_cher2k_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_cher2k) cblas_cher2k __attribute__ ((alias("liftracc_cher2k")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZHEMM
 */

void liftracc_zhemm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZHEMM]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZHEMM, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zhemm");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, side, uplo, m, n, alpha, a, lda, b, ldb, beta, c, ldc);
    } else
        ERROR("liftracc_zhemm not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZHEMM]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zhemm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const int * m, const int * n, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const void * beta, void * c, const int * ldc)
{
    liftracc_zhemm(*order, *side, *uplo, *m, *n, alpha, a, *lda, b, *ldb, beta, c, *ldc);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zhemm_) zhemm __attribute__ ((alias("liftracc_zhemm_"))); */
/* __typeof__ (liftracc_zhemm_) zhemm_ __attribute__ ((alias("liftracc_zhemm_"))); */
__typeof__ (liftracc_zhemm_) ZHEMM __attribute__ ((alias("liftracc_zhemm_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zhemm) cblas_zhemm __attribute__ ((alias("liftracc_zhemm")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZHERK
 */

void liftracc_zherk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const double alpha, const void * a, const int lda, const double beta, void * c, const int ldc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZHERK]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZHERK, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zherk");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, trans, n, k, alpha, a, lda, beta, c, ldc);
    } else
        ERROR("liftracc_zherk not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZHERK]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zherk_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const double * alpha, const void * a, const int * lda, const double * beta, void * c, const int * ldc)
{
    liftracc_zherk(*order, *uplo, *trans, *n, *k, *alpha, a, *lda, *beta, c, *ldc);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zherk_) zherk __attribute__ ((alias("liftracc_zherk_"))); */
/* __typeof__ (liftracc_zherk_) zherk_ __attribute__ ((alias("liftracc_zherk_"))); */
__typeof__ (liftracc_zherk_) ZHERK __attribute__ ((alias("liftracc_zherk_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zherk) cblas_zherk __attribute__ ((alias("liftracc_zherk")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * ZHER2K
 */

void liftracc_zher2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const double beta, void * c, const int ldc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZHER2K]));
#endif /* _LIFTRACC_PROFILING_ */
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = n;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_ZHER2K, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_zher2k");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        (*liftracc_plugin_func)(order, uplo, trans, n, k, alpha, a, lda, b, ldb, beta, c, ldc);
    } else
        ERROR("liftracc_zher2k not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_ZHER2K]));
#endif /* _LIFTRACC_PROFILING_ */

    
}

void liftracc_zher2k_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const double * beta, void * c, const int * ldc)
{
    liftracc_zher2k(*order, *uplo, *trans, *n, *k, alpha, a, *lda, b, *ldb, *beta, c, *ldc);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_zher2k_) zher2k __attribute__ ((alias("liftracc_zher2k_"))); */
/* __typeof__ (liftracc_zher2k_) zher2k_ __attribute__ ((alias("liftracc_zher2k_"))); */
__typeof__ (liftracc_zher2k_) ZHER2K __attribute__ ((alias("liftracc_zher2k_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_zher2k) cblas_zher2k __attribute__ ((alias("liftracc_zher2k")));
#endif // _LIFTRACC_CBLAS_INTERFACE_


/***
 * XERBLA
 */

void liftracc_xerbla(int p, const char * rout, const char * form, ...)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_XERBLA]));
#endif /* _LIFTRACC_PROFILING_ */
    va_list argptr;
    char *str = 0;

    va_start(argptr, form);
    vasprintf(&str, form, argptr);
    va_end(argptr);
    
    void (*liftracc_plugin_func)();
    
   
#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_

    pinfo.info1 = 0;

    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(SELECT_XERBLA, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_xerbla");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

    if (liftracc_plugin_func != 0)  {
        // call func without '...'
        (*liftracc_plugin_func)(p, rout, str);
    } else
        ERROR("liftracc_xerbla not executed");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_XERBLA]));
#endif /* _LIFTRACC_PROFILING_ */

    free(str);
}

void liftracc_xerbla_(int * p, const char * rout, const char * form, ...)
{
    va_list argptr;
    char *str = 0;

    va_start(argptr, form);
    vasprintf(&str, form, argptr);
    va_end(argptr);

    // call func without '...'
    liftracc_xerbla(*p, rout, str);
    free(str);
}

#ifdef _LIFTRACC_MKL_INTERFACE_
/* __typeof__ (liftracc_xerbla_) xerbla __attribute__ ((alias("liftracc_xerbla_"))); */
/* __typeof__ (liftracc_xerbla_) xerbla_ __attribute__ ((alias("liftracc_xerbla_"))); */
__typeof__ (liftracc_xerbla_) XERBLA __attribute__ ((alias("liftracc_xerbla_")));
#endif // _LIFTRACC_MKL_INTERFACE_

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_xerbla) cblas_xerbla __attribute__ ((alias("liftracc_xerbla")));
#endif // _LIFTRACC_CBLAS_INTERFACE_

