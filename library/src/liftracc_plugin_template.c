
/**
 * \file liftracc_plugin_template.c
 * \brief [generated template file]
 */

/* Template file to create new plugins easily. */
/* Delete unneeded functions and fill in code to fulfill your functionality. */

#include "liftracc.h"
#include "plugin.h"
#include "logging.h"
#ifndef __USE_GNU
#define __USE_GNU
#endif
#include <dlfcn.h>

plugin_info_t liftracc_plugin_info = {
    "????????-????-????-????-????????????", // uuid
    "?", // name
    "?", // description
    ?, // priority 0-255 0:low
};

void __attribute__ ((constructor)) liftracc_plugin_load(void)
{
    INFO("%s loaded.", liftracc_plugin_info.name);
}

void __attribute__ ((destructor)) liftracc_plugin_unload(void)
{
    INFO("%s unloaded.", liftracc_plugin_info.name);    
}


float liftracc_plugin_sdsdot(const int n, const float alpha, const float * x, const int incx, const float * y, const int incy)
{
    INFO("%s_sdsdot", liftracc_plugin_info.name);

}


double liftracc_plugin_dsdot(const int n, const float * x, const int incx, const float * y, const int incy)
{
    INFO("%s_dsdot", liftracc_plugin_info.name);

}


float liftracc_plugin_sdot(const int n, const float * x, const int incx, const float * y, const int incy)
{
    INFO("%s_sdot", liftracc_plugin_info.name);

}


double liftracc_plugin_ddot(const int n, const double * x, const int incx, const double * y, const int incy)
{
    INFO("%s_ddot", liftracc_plugin_info.name);

}


void liftracc_plugin_cdotu_sub(const int n, const void * x, const int incx, const void * y, const int incy, void * dotu)
{
    INFO("%s_cdotu_sub", liftracc_plugin_info.name);

}


void liftracc_plugin_cdotc_sub(const int n, const void * x, const int incx, const void * y, const int incy, void * dotc)
{
    INFO("%s_cdotc_sub", liftracc_plugin_info.name);

}


void liftracc_plugin_zdotu_sub(const int n, const void * x, const int incx, const void * y, const int incy, void * dotu)
{
    INFO("%s_zdotu_sub", liftracc_plugin_info.name);

}


void liftracc_plugin_zdotc_sub(const int n, const void * x, const int incx, const void * y, const int incy, void * dotc)
{
    INFO("%s_zdotc_sub", liftracc_plugin_info.name);

}


float liftracc_plugin_snrm2(const int n, const float * x, const int incx)
{
    INFO("%s_snrm2", liftracc_plugin_info.name);

}


float liftracc_plugin_sasum(const int n, const float * x, const int incx)
{
    INFO("%s_sasum", liftracc_plugin_info.name);

}


double liftracc_plugin_dnrm2(const int n, const double * x, const int incx)
{
    INFO("%s_dnrm2", liftracc_plugin_info.name);

}


double liftracc_plugin_dasum(const int n, const double * x, const int incx)
{
    INFO("%s_dasum", liftracc_plugin_info.name);

}


float liftracc_plugin_scnrm2(const int n, const void * x, const int incx)
{
    INFO("%s_scnrm2", liftracc_plugin_info.name);

}


float liftracc_plugin_scasum(const int n, const void * x, const int incx)
{
    INFO("%s_scasum", liftracc_plugin_info.name);

}


double liftracc_plugin_dznrm2(const int n, const void * x, const int incx)
{
    INFO("%s_dznrm2", liftracc_plugin_info.name);

}


double liftracc_plugin_dzasum(const int n, const void * x, const int incx)
{
    INFO("%s_dzasum", liftracc_plugin_info.name);

}


liftracc_index_t liftracc_plugin_isamax(const int n, const float * x, const int incx)
{
    INFO("%s_isamax", liftracc_plugin_info.name);

}


liftracc_index_t liftracc_plugin_idamax(const int n, const double * x, const int incx)
{
    INFO("%s_idamax", liftracc_plugin_info.name);

}


liftracc_index_t liftracc_plugin_icamax(const int n, const void * x, const int incx)
{
    INFO("%s_icamax", liftracc_plugin_info.name);

}


liftracc_index_t liftracc_plugin_izamax(const int n, const void * x, const int incx)
{
    INFO("%s_izamax", liftracc_plugin_info.name);

}


void liftracc_plugin_sswap(const int n, float * x, const int incx, float * y, const int incy)
{
    INFO("%s_sswap", liftracc_plugin_info.name);

}


void liftracc_plugin_scopy(const int n, const float * x, const int incx, float * y, const int incy)
{
    INFO("%s_scopy", liftracc_plugin_info.name);

}


void liftracc_plugin_saxpy(const int n, const float alpha, const float * x, const int incx, float * y, const int incy)
{
    INFO("%s_saxpy", liftracc_plugin_info.name);

}


void liftracc_plugin_dswap(const int n, double * x, const int incx, double * y, const int incy)
{
    INFO("%s_dswap", liftracc_plugin_info.name);

}


void liftracc_plugin_dcopy(const int n, const double * x, const int incx, double * y, const int incy)
{
    INFO("%s_dcopy", liftracc_plugin_info.name);

}


void liftracc_plugin_daxpy(const int n, const double alpha, const double * x, const int incx, double * y, const int incy)
{
    INFO("%s_daxpy", liftracc_plugin_info.name);

}


void liftracc_plugin_cswap(const int n, void * x, const int incx, void * y, const int incy)
{
    INFO("%s_cswap", liftracc_plugin_info.name);

}


void liftracc_plugin_ccopy(const int n, const void * x, const int incx, void * y, const int incy)
{
    INFO("%s_ccopy", liftracc_plugin_info.name);

}


void liftracc_plugin_caxpy(const int n, const void * alpha, const void * x, const int incx, void * y, const int incy)
{
    INFO("%s_caxpy", liftracc_plugin_info.name);

}


void liftracc_plugin_zswap(const int n, void * x, const int incx, void * y, const int incy)
{
    INFO("%s_zswap", liftracc_plugin_info.name);

}


void liftracc_plugin_zcopy(const int n, const void * x, const int incx, void * y, const int incy)
{
    INFO("%s_zcopy", liftracc_plugin_info.name);

}


void liftracc_plugin_zaxpy(const int n, const void * alpha, const void * x, const int incx, void * y, const int incy)
{
    INFO("%s_zaxpy", liftracc_plugin_info.name);

}


void liftracc_plugin_srotg(float * a, float * b, float * c, float * s)
{
    INFO("%s_srotg", liftracc_plugin_info.name);

}


void liftracc_plugin_srotmg(float * d1, float * d2, float * b1, const float b2, float * p)
{
    INFO("%s_srotmg", liftracc_plugin_info.name);

}


void liftracc_plugin_srot(const int n, float * x, const int incx, float * y, const int incy, const float c, const float s)
{
    INFO("%s_srot", liftracc_plugin_info.name);

}


void liftracc_plugin_srotm(const int n, float * x, const int incx, float * y, const int incy, const float * p)
{
    INFO("%s_srotm", liftracc_plugin_info.name);

}


void liftracc_plugin_drotg(double * a, double * b, double * c, double * s)
{
    INFO("%s_drotg", liftracc_plugin_info.name);

}


void liftracc_plugin_drotmg(double * d1, double * d2, double * b1, const double b2, double * p)
{
    INFO("%s_drotmg", liftracc_plugin_info.name);

}


void liftracc_plugin_drot(const int n, double * x, const int incx, double * y, const int incy, const double c, const double s)
{
    INFO("%s_drot", liftracc_plugin_info.name);

}


void liftracc_plugin_drotm(const int n, double * x, const int incx, double * y, const int incy, const double * p)
{
    INFO("%s_drotm", liftracc_plugin_info.name);

}


void liftracc_plugin_sscal(const int n, const float alpha, float * x, const int incx)
{
    INFO("%s_sscal", liftracc_plugin_info.name);

}


void liftracc_plugin_dscal(const int n, const double alpha, double * x, const int incx)
{
    INFO("%s_dscal", liftracc_plugin_info.name);

}


void liftracc_plugin_cscal(const int n, const void * alpha, void * x, const int incx)
{
    INFO("%s_cscal", liftracc_plugin_info.name);

}


void liftracc_plugin_zscal(const int n, const void * alpha, void * x, const int incx)
{
    INFO("%s_zscal", liftracc_plugin_info.name);

}


void liftracc_plugin_csscal(const int n, const float alpha, void * x, const int incx)
{
    INFO("%s_csscal", liftracc_plugin_info.name);

}


void liftracc_plugin_zdscal(const int n, const double alpha, void * x, const int incx)
{
    INFO("%s_zdscal", liftracc_plugin_info.name);

}


void liftracc_plugin_sgemv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const float alpha, const float * a, const int lda, const float * x, const int incx, const float beta, float * y, const int incy)
{
    INFO("%s_sgemv", liftracc_plugin_info.name);

}


void liftracc_plugin_sgbmv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const int kl, const int ku, const float alpha, const float * a, const int lda, const float * x, const int incx, const float beta, float * y, const int incy)
{
    INFO("%s_sgbmv", liftracc_plugin_info.name);

}


void liftracc_plugin_strmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const float * a, const int lda, float * x, const int incx)
{
    INFO("%s_strmv", liftracc_plugin_info.name);

}


void liftracc_plugin_stbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const float * a, const int lda, float * x, const int incx)
{
    INFO("%s_stbmv", liftracc_plugin_info.name);

}


void liftracc_plugin_stpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const float * ap, float * x, const int incx)
{
    INFO("%s_stpmv", liftracc_plugin_info.name);

}


void liftracc_plugin_strsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const float * a, const int lda, float * x, const int incx)
{
    INFO("%s_strsv", liftracc_plugin_info.name);

}


void liftracc_plugin_stbsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const float * a, const int lda, float * x, const int incx)
{
    INFO("%s_stbsv", liftracc_plugin_info.name);

}


void liftracc_plugin_stpsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const float * ap, float * x, const int incx)
{
    INFO("%s_stpsv", liftracc_plugin_info.name);

}


void liftracc_plugin_dgemv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const double alpha, const double * a, const int lda, const double * x, const int incx, const double beta, double * y, const int incy)
{
    INFO("%s_dgemv", liftracc_plugin_info.name);

}


void liftracc_plugin_dgbmv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const int kl, const int ku, const double alpha, const double * a, const int lda, const double * x, const int incx, const double beta, double * y, const int incy)
{
    INFO("%s_dgbmv", liftracc_plugin_info.name);

}


void liftracc_plugin_dtrmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const double * a, const int lda, double * x, const int incx)
{
    INFO("%s_dtrmv", liftracc_plugin_info.name);

}


void liftracc_plugin_dtbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const double * a, const int lda, double * x, const int incx)
{
    INFO("%s_dtbmv", liftracc_plugin_info.name);

}


void liftracc_plugin_dtpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const double * ap, double * x, const int incx)
{
    INFO("%s_dtpmv", liftracc_plugin_info.name);

}


void liftracc_plugin_dtrsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const double * a, const int lda, double * x, const int incx)
{
    INFO("%s_dtrsv", liftracc_plugin_info.name);

}


void liftracc_plugin_dtbsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const double * a, const int lda, double * x, const int incx)
{
    INFO("%s_dtbsv", liftracc_plugin_info.name);

}


void liftracc_plugin_dtpsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const double * ap, double * x, const int incx)
{
    INFO("%s_dtpsv", liftracc_plugin_info.name);

}


void liftracc_plugin_cgemv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy)
{
    INFO("%s_cgemv", liftracc_plugin_info.name);

}


void liftracc_plugin_cgbmv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const int kl, const int ku, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy)
{
    INFO("%s_cgbmv", liftracc_plugin_info.name);

}


void liftracc_plugin_ctrmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * a, const int lda, void * x, const int incx)
{
    INFO("%s_ctrmv", liftracc_plugin_info.name);

}


void liftracc_plugin_ctbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const void * a, const int lda, void * x, const int incx)
{
    INFO("%s_ctbmv", liftracc_plugin_info.name);

}


void liftracc_plugin_ctpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * ap, void * x, const int incx)
{
    INFO("%s_ctpmv", liftracc_plugin_info.name);

}


void liftracc_plugin_ctrsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * a, const int lda, void * x, const int incx)
{
    INFO("%s_ctrsv", liftracc_plugin_info.name);

}


void liftracc_plugin_ctbsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const void * a, const int lda, void * x, const int incx)
{
    INFO("%s_ctbsv", liftracc_plugin_info.name);

}


void liftracc_plugin_ctpsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * ap, void * x, const int incx)
{
    INFO("%s_ctpsv", liftracc_plugin_info.name);

}


void liftracc_plugin_zgemv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy)
{
    INFO("%s_zgemv", liftracc_plugin_info.name);

}


void liftracc_plugin_zgbmv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const int kl, const int ku, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy)
{
    INFO("%s_zgbmv", liftracc_plugin_info.name);

}


void liftracc_plugin_ztrmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * a, const int lda, void * x, const int incx)
{
    INFO("%s_ztrmv", liftracc_plugin_info.name);

}


void liftracc_plugin_ztbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const void * a, const int lda, void * x, const int incx)
{
    INFO("%s_ztbmv", liftracc_plugin_info.name);

}


void liftracc_plugin_ztpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * ap, void * x, const int incx)
{
    INFO("%s_ztpmv", liftracc_plugin_info.name);

}


void liftracc_plugin_ztrsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * a, const int lda, void * x, const int incx)
{
    INFO("%s_ztrsv", liftracc_plugin_info.name);

}


void liftracc_plugin_ztbsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const void * a, const int lda, void * x, const int incx)
{
    INFO("%s_ztbsv", liftracc_plugin_info.name);

}


void liftracc_plugin_ztpsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * ap, void * x, const int incx)
{
    INFO("%s_ztpsv", liftracc_plugin_info.name);

}


void liftracc_plugin_ssymv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * a, const int lda, const float * x, const int incx, const float beta, float * y, const int incy)
{
    INFO("%s_ssymv", liftracc_plugin_info.name);

}


void liftracc_plugin_ssbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const int k, const float alpha, const float * a, const int lda, const float * x, const int incx, const float beta, float * y, const int incy)
{
    INFO("%s_ssbmv", liftracc_plugin_info.name);

}


void liftracc_plugin_sspmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * ap, const float * x, const int incx, const float beta, float * y, const int incy)
{
    INFO("%s_sspmv", liftracc_plugin_info.name);

}


void liftracc_plugin_sger(const liftracc_order_t order, const int m, const int n, const float alpha, const float * x, const int incx, const float * y, const int incy, float * a, const int lda)
{
    INFO("%s_sger", liftracc_plugin_info.name);

}


void liftracc_plugin_ssyr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * x, const int incx, float * a, const int lda)
{
    INFO("%s_ssyr", liftracc_plugin_info.name);

}


void liftracc_plugin_sspr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * x, const int incx, float * ap)
{
    INFO("%s_sspr", liftracc_plugin_info.name);

}


void liftracc_plugin_ssyr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * x, const int incx, const float * y, const int incy, float * a, const int lda)
{
    INFO("%s_ssyr2", liftracc_plugin_info.name);

}


void liftracc_plugin_sspr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * x, const int incx, const float * y, const int incy, float * a)
{
    INFO("%s_sspr2", liftracc_plugin_info.name);

}


void liftracc_plugin_dsymv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * a, const int lda, const double * x, const int incx, const double beta, double * y, const int incy)
{
    INFO("%s_dsymv", liftracc_plugin_info.name);

}


void liftracc_plugin_dsbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const int k, const double alpha, const double * a, const int lda, const double * x, const int incx, const double beta, double * y, const int incy)
{
    INFO("%s_dsbmv", liftracc_plugin_info.name);

}


void liftracc_plugin_dspmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * ap, const double * x, const int incx, const double beta, double * y, const int incy)
{
    INFO("%s_dspmv", liftracc_plugin_info.name);

}


void liftracc_plugin_dger(const liftracc_order_t order, const int m, const int n, const double alpha, const double * x, const int incx, const double * y, const int incy, double * a, const int lda)
{
    INFO("%s_dger", liftracc_plugin_info.name);

}


void liftracc_plugin_dsyr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * x, const int incx, double * a, const int lda)
{
    INFO("%s_dsyr", liftracc_plugin_info.name);

}


void liftracc_plugin_dspr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * x, const int incx, double * ap)
{
    INFO("%s_dspr", liftracc_plugin_info.name);

}


void liftracc_plugin_dsyr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * x, const int incx, const double * y, const int incy, double * a, const int lda)
{
    INFO("%s_dsyr2", liftracc_plugin_info.name);

}


void liftracc_plugin_dspr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * x, const int incx, const double * y, const int incy, double * a)
{
    INFO("%s_dspr2", liftracc_plugin_info.name);

}


void liftracc_plugin_chemv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy)
{
    INFO("%s_chemv", liftracc_plugin_info.name);

}


void liftracc_plugin_chbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const int k, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy)
{
    INFO("%s_chbmv", liftracc_plugin_info.name);

}


void liftracc_plugin_chpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * ap, const void * x, const int incx, const void * beta, void * y, const int incy)
{
    INFO("%s_chpmv", liftracc_plugin_info.name);

}


void liftracc_plugin_cgeru(const liftracc_order_t order, const int m, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda)
{
    INFO("%s_cgeru", liftracc_plugin_info.name);

}


void liftracc_plugin_cgerc(const liftracc_order_t order, const int m, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda)
{
    INFO("%s_cgerc", liftracc_plugin_info.name);

}


void liftracc_plugin_cher(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const void * x, const int incx, void * a, const int lda)
{
    INFO("%s_cher", liftracc_plugin_info.name);

}


void liftracc_plugin_chpr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const void * x, const int incx, void * a)
{
    INFO("%s_chpr", liftracc_plugin_info.name);

}


void liftracc_plugin_cher2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda)
{
    INFO("%s_cher2", liftracc_plugin_info.name);

}


void liftracc_plugin_chpr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * ap)
{
    INFO("%s_chpr2", liftracc_plugin_info.name);

}


void liftracc_plugin_zhemv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy)
{
    INFO("%s_zhemv", liftracc_plugin_info.name);

}


void liftracc_plugin_zhbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const int k, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy)
{
    INFO("%s_zhbmv", liftracc_plugin_info.name);

}


void liftracc_plugin_zhpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * ap, const void * x, const int incx, const void * beta, void * y, const int incy)
{
    INFO("%s_zhpmv", liftracc_plugin_info.name);

}


void liftracc_plugin_zgeru(const liftracc_order_t order, const int m, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda)
{
    INFO("%s_zgeru", liftracc_plugin_info.name);

}


void liftracc_plugin_zgerc(const liftracc_order_t order, const int m, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda)
{
    INFO("%s_zgerc", liftracc_plugin_info.name);

}


void liftracc_plugin_zher(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const void * x, const int incx, void * a, const int lda)
{
    INFO("%s_zher", liftracc_plugin_info.name);

}


void liftracc_plugin_zhpr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const void * x, const int incx, void * a)
{
    INFO("%s_zhpr", liftracc_plugin_info.name);

}


void liftracc_plugin_zher2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda)
{
    INFO("%s_zher2", liftracc_plugin_info.name);

}


void liftracc_plugin_zhpr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * ap)
{
    INFO("%s_zhpr2", liftracc_plugin_info.name);

}


void liftracc_plugin_sgemm(const liftracc_order_t order, const liftracc_transpose_t transa, const liftracc_transpose_t transb, const int m, const int n, const int k, const float alpha, const float * a, const int lda, const float * b, const int ldb, const float beta, float * c, const int ldc)
{
    INFO("%s_sgemm", liftracc_plugin_info.name);

}


void liftracc_plugin_ssymm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const float alpha, const float * a, const int lda, const float * b, const int ldb, const float beta, float * c, const int ldc)
{
    INFO("%s_ssymm", liftracc_plugin_info.name);

}


void liftracc_plugin_ssyrk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const float alpha, const float * a, const int lda, const float beta, float * c, const int ldc)
{
    INFO("%s_ssyrk", liftracc_plugin_info.name);

}


void liftracc_plugin_ssyr2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const float alpha, const float * a, const int lda, const float * b, const int ldb, const float beta, float * c, const int ldc)
{
    INFO("%s_ssyr2k", liftracc_plugin_info.name);

}


void liftracc_plugin_strmm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const float alpha, const float * a, const int lda, float * b, const int ldb)
{
    INFO("%s_strmm", liftracc_plugin_info.name);

}


void liftracc_plugin_strsm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const float alpha, const float * a, const int lda, float * b, const int ldb)
{
    INFO("%s_strsm", liftracc_plugin_info.name);

}


void liftracc_plugin_dgemm(const liftracc_order_t order, const liftracc_transpose_t transa, const liftracc_transpose_t transb, const int m, const int n, const int k, const double alpha, const double * a, const int lda, const double * b, const int ldb, const double beta, double * c, const int ldc)
{
    INFO("%s_dgemm", liftracc_plugin_info.name);

}


void liftracc_plugin_dsymm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const double alpha, const double * a, const int lda, const double * b, const int ldb, const double beta, double * c, const int ldc)
{
    INFO("%s_dsymm", liftracc_plugin_info.name);

}


void liftracc_plugin_dsyrk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const double alpha, const double * a, const int lda, const double beta, double * c, const int ldc)
{
    INFO("%s_dsyrk", liftracc_plugin_info.name);

}


void liftracc_plugin_dsyr2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const double alpha, const double * a, const int lda, const double * b, const int ldb, const double beta, double * c, const int ldc)
{
    INFO("%s_dsyr2k", liftracc_plugin_info.name);

}


void liftracc_plugin_dtrmm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const double alpha, const double * a, const int lda, double * b, const int ldb)
{
    INFO("%s_dtrmm", liftracc_plugin_info.name);

}


void liftracc_plugin_dtrsm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const double alpha, const double * a, const int lda, double * b, const int ldb)
{
    INFO("%s_dtrsm", liftracc_plugin_info.name);

}


void liftracc_plugin_cgemm(const liftracc_order_t order, const liftracc_transpose_t transa, const liftracc_transpose_t transb, const int m, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc)
{
    INFO("%s_cgemm", liftracc_plugin_info.name);

}


void liftracc_plugin_csymm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc)
{
    INFO("%s_csymm", liftracc_plugin_info.name);

}


void liftracc_plugin_csyrk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * beta, void * c, const int ldc)
{
    INFO("%s_csyrk", liftracc_plugin_info.name);

}


void liftracc_plugin_csyr2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc)
{
    INFO("%s_csyr2k", liftracc_plugin_info.name);

}


void liftracc_plugin_ctrmm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const void * alpha, const void * a, const int lda, void * b, const int ldb)
{
    INFO("%s_ctrmm", liftracc_plugin_info.name);

}


void liftracc_plugin_ctrsm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const void * alpha, const void * a, const int lda, void * b, const int ldb)
{
    INFO("%s_ctrsm", liftracc_plugin_info.name);

}


void liftracc_plugin_zgemm(const liftracc_order_t order, const liftracc_transpose_t transa, const liftracc_transpose_t transb, const int m, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc)
{
    INFO("%s_zgemm", liftracc_plugin_info.name);

}


void liftracc_plugin_zsymm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc)
{
    INFO("%s_zsymm", liftracc_plugin_info.name);

}


void liftracc_plugin_zsyrk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * beta, void * c, const int ldc)
{
    INFO("%s_zsyrk", liftracc_plugin_info.name);

}


void liftracc_plugin_zsyr2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc)
{
    INFO("%s_zsyr2k", liftracc_plugin_info.name);

}


void liftracc_plugin_ztrmm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const void * alpha, const void * a, const int lda, void * b, const int ldb)
{
    INFO("%s_ztrmm", liftracc_plugin_info.name);

}


void liftracc_plugin_ztrsm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const void * alpha, const void * a, const int lda, void * b, const int ldb)
{
    INFO("%s_ztrsm", liftracc_plugin_info.name);

}


void liftracc_plugin_chemm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc)
{
    INFO("%s_chemm", liftracc_plugin_info.name);

}


void liftracc_plugin_cherk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const float alpha, const void * a, const int lda, const float beta, void * c, const int ldc)
{
    INFO("%s_cherk", liftracc_plugin_info.name);

}


void liftracc_plugin_cher2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const float beta, void * c, const int ldc)
{
    INFO("%s_cher2k", liftracc_plugin_info.name);

}


void liftracc_plugin_zhemm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc)
{
    INFO("%s_zhemm", liftracc_plugin_info.name);

}


void liftracc_plugin_zherk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const double alpha, const void * a, const int lda, const double beta, void * c, const int ldc)
{
    INFO("%s_zherk", liftracc_plugin_info.name);

}


void liftracc_plugin_zher2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const double beta, void * c, const int ldc)
{
    INFO("%s_zher2k", liftracc_plugin_info.name);

}


void liftracc_plugin_xerbla(int p, const char * rout, const char * form)
{
    INFO("%s_xerbla", liftracc_plugin_info.name);

}


