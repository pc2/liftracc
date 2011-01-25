/**
 * @file liftracc_testing.c
 * @brief C file to test new functionality
 *
 * @author Manuel Niekamp <niekma@upb.de>
 * @version 0.1
 *
 * This file implements the main functionality of the library.
 * It is intended to use this file for testing purpose.
 * If the here implemented code works and is tested it can
 * be easily transfered to the xsl file to auto generate the
 * complete library.
 */
#include "liftracc.h"
#include "liftracc_logging.h"
#include "liftracc_selector.h"

#if _LIFTRACC_PROFILING_ > 0
#include "liftracc_profiling.h"
extern profiling_data_t liftracc_function_profiling_data[];
#endif

liftracc_selector_problem_info_t pinfo = { };

float liftracc_sdsdot(const int n, const float alpha, const float *x,
                     const int incx, const float *y, const int incy)
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

float liftracc_sdsdot_(const int *n, const float *alpha, const float *x,
                      const int *incx, const float *y, const int *incy)
{
    return liftracc_sdsdot(*n, *alpha, x, *incx, y, *incy);
}

double liftracc_dsdot(const int n, const float *x, const int incx, const float *y, const int incy)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DSDOT]));
#endif // _LIFTRACC_PROFILING_

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

double liftracc_dsdot_(const int *n, const float *x, const int *incx,
                      const float *y, const int *incy)
{
    return liftracc_dsdot(*n, x, *incx, y, *incy);
}

float liftracc_sdot(const int n, const float *x, const int incx,
                   const float *y, const int incy)
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

float liftracc_sdot_(const int *n, const float *x, const int *incx,
                    const float *y, const int *incy)
{
    return liftracc_sdot(*n, x, *incx, y, *incy);
}

liftracc_index_t liftracc_idamax(const int n, const double *x, const int incx)
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

liftracc_index_t liftracc_idamax_(const int *n, const double *x, const int *incx)
{
    return liftracc_idamax(*n, x, *incx);
}

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

void liftracc_dscal_(const int *n, const double *alpha, double *x, const int *incx)
{
    liftracc_dscal(*n, *alpha, x, *incx);
}

void liftracc_daxpy(const int n, const double alpha, const double *x,
                    const int incx, double *y, const int incy)
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

void liftracc_daxpy_(const int *n, const double *alpha, const double *x,
                     const int *incx, double *y, const int *incy)
{
        liftracc_daxpy(*n, *alpha, x, *incx, y, *incy);
}

double liftracc_ddot(const int n, const double *x, const int incx,
                    const double *y, const int incy)
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

double liftracc_ddot_(const int *n, const double *x, const int *incx,
                     const double *y, const int *incy)
{
    return liftracc_ddot(*n, x, *incx, y, *incy);
}

void liftracc_dgemm(const liftracc_order_t order,
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
                   const int ldc)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FUNCTION_DGEMM]));
#endif /* _LIFTRACC_PROFILING_ */

    printf("LIFTRACC_DGEMM_USED\n");

    void (*liftracc_plugin_func)();

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_  */

#ifdef _LIFTRACC_SELECTOR_NEW_
    pinfo.info1 = m;

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

void  liftracc_dgemm_(const char *transa,
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
                     const int *ldc)
{
    liftracc_transpose_t ta, tb;
    switch (*transa) {
        case 'N':
        case 'n': ta = liftracc_no_trans; break;
        case 'T':
        case 't': ta = liftracc_trans; break;
        case 'C':
        case 'c': ta = liftracc_conj_trans; break;
        default:  ta = liftracc_no_trans; break;
    }
    switch (*transb) {
        case 'N':
        case 'n': tb = liftracc_no_trans; break;
        case 'T':
        case 't': tb = liftracc_trans; break;
        case 'C':
        case 'c': tb = liftracc_conj_trans; break;
        default:  tb = liftracc_no_trans; break;
    }
    liftracc_dgemm(liftracc_col_major, ta, tb,
                  *m, *n, *k,
                  *alpha, a, *lda,
                  b, *ldb, *beta,
                  c, *ldc);
}

#ifdef _LIFTRACC_CBLAS_INTERFACE_
__typeof__ (liftracc_sdsdot) cblas_sdsdot __attribute__ ((alias("liftracc_sdsdot")));
__typeof__ (liftracc_dsdot) cblas_dsdot __attribute__ ((alias("liftracc_dsdot")));
__typeof__ (liftracc_sdot) cblas_sdot __attribute__ ((alias("liftracc_sdot")));
__typeof__ (liftracc_idamax) cblas_idamax __attribute__ ((alias("liftracc_idamax")));
__typeof__ (liftracc_dscal) cblas_dscal __attribute__ ((alias("liftracc_dscal")));
__typeof__ (liftracc_daxpy) cblas_daxpy __attribute__ ((alias("liftracc_daxpy")));
__typeof__ (liftracc_ddot) cblas_ddot __attribute__ ((alias("liftracc_ddot")));
__typeof__ (liftracc_dgemm) cblas_dgemm __attribute__ ((alias("liftracc_dgemm")));

__typeof__ (liftracc_sdsdot) f2c_sdsdot __attribute__ ((alias("liftracc_sdsdot")));
__typeof__ (liftracc_dsdot) f2c_dsdot __attribute__ ((alias("liftracc_dsdot")));
__typeof__ (liftracc_sdot) f2c_sdot __attribute__ ((alias("liftracc_sdot")));
__typeof__ (liftracc_idamax) f2c_idamax __attribute__ ((alias("liftracc_idamax")));
__typeof__ (liftracc_dscal) f2c_dscal __attribute__ ((alias("liftracc_dscal")));
__typeof__ (liftracc_daxpy) f2c_daxpy __attribute__ ((alias("liftracc_daxpy")));
__typeof__ (liftracc_ddot) f2c_ddot __attribute__ ((alias("liftracc_ddot")));
__typeof__ (liftracc_dgemm) f2c_dgemm __attribute__ ((alias("liftracc_dgemm")));
#endif // _LIFTRACC_CBLAS_INTERFACE_

#ifdef _LIFTRACC_MKL_INTERFACE_
__typeof__ (liftracc_dgemm_) DGEMM __attribute__ ((alias("liftracc_dgemm_")));
__typeof__ (liftracc_dgemm_) dgemm __attribute__ ((alias("liftracc_dgemm_")));
#endif // _LIFTRACC_MKL_INTERFACE_

