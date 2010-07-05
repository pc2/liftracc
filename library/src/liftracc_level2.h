
/**
 * \file liftracc_level2.h
 * \brief [generated file]
 */

/* This file is generated automatically, do not edit manually! */

#ifndef __LIFTRACC_LEVEL2_H__
#define __LIFTRACC_LEVEL2_H__

#include "liftracc_common.h"


void liftracc_sgemv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const float alpha, const float * a, const int lda, const float * x, const int incx, const float beta, float * y, const int incy);
void liftracc_sgemv_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const int * m, const int * n, const float * alpha, const float * a, const int * lda, const float * x, const int * incx, const float * beta, float * y, const int * incy);

void liftracc_sgbmv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const int kl, const int ku, const float alpha, const float * a, const int lda, const float * x, const int incx, const float beta, float * y, const int incy);
void liftracc_sgbmv_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const int * m, const int * n, const int * kl, const int * ku, const float * alpha, const float * a, const int * lda, const float * x, const int * incx, const float * beta, float * y, const int * incy);

void liftracc_strmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const float * a, const int lda, float * x, const int incx);
void liftracc_strmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const float * a, const int * lda, float * x, const int * incx);

void liftracc_stbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const float * a, const int lda, float * x, const int incx);
void liftracc_stbmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const int * k, const float * a, const int * lda, float * x, const int * incx);

void liftracc_stpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const float * ap, float * x, const int incx);
void liftracc_stpmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const float * ap, float * x, const int * incx);

void liftracc_strsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const float * a, const int lda, float * x, const int incx);
void liftracc_strsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const float * a, const int * lda, float * x, const int * incx);

void liftracc_stbsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const float * a, const int lda, float * x, const int incx);
void liftracc_stbsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const int * k, const float * a, const int * lda, float * x, const int * incx);

void liftracc_stpsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const float * ap, float * x, const int incx);
void liftracc_stpsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const float * ap, float * x, const int * incx);

void liftracc_dgemv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const double alpha, const double * a, const int lda, const double * x, const int incx, const double beta, double * y, const int incy);
void liftracc_dgemv_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const int * m, const int * n, const double * alpha, const double * a, const int * lda, const double * x, const int * incx, const double * beta, double * y, const int * incy);

void liftracc_dgbmv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const int kl, const int ku, const double alpha, const double * a, const int lda, const double * x, const int incx, const double beta, double * y, const int incy);
void liftracc_dgbmv_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const int * m, const int * n, const int * kl, const int * ku, const double * alpha, const double * a, const int * lda, const double * x, const int * incx, const double * beta, double * y, const int * incy);

void liftracc_dtrmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const double * a, const int lda, double * x, const int incx);
void liftracc_dtrmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const double * a, const int * lda, double * x, const int * incx);

void liftracc_dtbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const double * a, const int lda, double * x, const int incx);
void liftracc_dtbmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const int * k, const double * a, const int * lda, double * x, const int * incx);

void liftracc_dtpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const double * ap, double * x, const int incx);
void liftracc_dtpmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const double * ap, double * x, const int * incx);

void liftracc_dtrsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const double * a, const int lda, double * x, const int incx);
void liftracc_dtrsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const double * a, const int * lda, double * x, const int * incx);

void liftracc_dtbsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const double * a, const int lda, double * x, const int incx);
void liftracc_dtbsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const int * k, const double * a, const int * lda, double * x, const int * incx);

void liftracc_dtpsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const double * ap, double * x, const int incx);
void liftracc_dtpsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const double * ap, double * x, const int * incx);

void liftracc_cgemv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy);
void liftracc_cgemv_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const int * m, const int * n, const void * alpha, const void * a, const int * lda, const void * x, const int * incx, const void * beta, void * y, const int * incy);

void liftracc_cgbmv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const int kl, const int ku, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy);
void liftracc_cgbmv_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const int * m, const int * n, const int * kl, const int * ku, const void * alpha, const void * a, const int * lda, const void * x, const int * incx, const void * beta, void * y, const int * incy);

void liftracc_ctrmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * a, const int lda, void * x, const int incx);
void liftracc_ctrmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const void * a, const int * lda, void * x, const int * incx);

void liftracc_ctbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const void * a, const int lda, void * x, const int incx);
void liftracc_ctbmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const int * k, const void * a, const int * lda, void * x, const int * incx);

void liftracc_ctpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * ap, void * x, const int incx);
void liftracc_ctpmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const void * ap, void * x, const int * incx);

void liftracc_ctrsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * a, const int lda, void * x, const int incx);
void liftracc_ctrsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const void * a, const int * lda, void * x, const int * incx);

void liftracc_ctbsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const void * a, const int lda, void * x, const int incx);
void liftracc_ctbsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const int * k, const void * a, const int * lda, void * x, const int * incx);

void liftracc_ctpsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * ap, void * x, const int incx);
void liftracc_ctpsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const void * ap, void * x, const int * incx);

void liftracc_zgemv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy);
void liftracc_zgemv_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const int * m, const int * n, const void * alpha, const void * a, const int * lda, const void * x, const int * incx, const void * beta, void * y, const int * incy);

void liftracc_zgbmv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const int kl, const int ku, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy);
void liftracc_zgbmv_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const int * m, const int * n, const int * kl, const int * ku, const void * alpha, const void * a, const int * lda, const void * x, const int * incx, const void * beta, void * y, const int * incy);

void liftracc_ztrmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * a, const int lda, void * x, const int incx);
void liftracc_ztrmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const void * a, const int * lda, void * x, const int * incx);

void liftracc_ztbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const void * a, const int lda, void * x, const int incx);
void liftracc_ztbmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const int * k, const void * a, const int * lda, void * x, const int * incx);

void liftracc_ztpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * ap, void * x, const int incx);
void liftracc_ztpmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const void * ap, void * x, const int * incx);

void liftracc_ztrsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * a, const int lda, void * x, const int incx);
void liftracc_ztrsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const void * a, const int * lda, void * x, const int * incx);

void liftracc_ztbsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const void * a, const int lda, void * x, const int incx);
void liftracc_ztbsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const int * k, const void * a, const int * lda, void * x, const int * incx);

void liftracc_ztpsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * ap, void * x, const int incx);
void liftracc_ztpsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const void * ap, void * x, const int * incx);

void liftracc_ssymv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * a, const int lda, const float * x, const int incx, const float beta, float * y, const int incy);
void liftracc_ssymv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const float * alpha, const float * a, const int * lda, const float * x, const int * incx, const float * beta, float * y, const int * incy);

void liftracc_ssbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const int k, const float alpha, const float * a, const int lda, const float * x, const int incx, const float beta, float * y, const int incy);
void liftracc_ssbmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const int * k, const float * alpha, const float * a, const int * lda, const float * x, const int * incx, const float * beta, float * y, const int * incy);

void liftracc_sspmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * ap, const float * x, const int incx, const float beta, float * y, const int incy);
void liftracc_sspmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const float * alpha, const float * ap, const float * x, const int * incx, const float * beta, float * y, const int * incy);

void liftracc_sger(const liftracc_order_t order, const int m, const int n, const float alpha, const float * x, const int incx, const float * y, const int incy, float * a, const int lda);
void liftracc_sger_(const liftracc_order_t * order, const int * m, const int * n, const float * alpha, const float * x, const int * incx, const float * y, const int * incy, float * a, const int * lda);

void liftracc_ssyr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * x, const int incx, float * a, const int lda);
void liftracc_ssyr_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const float * alpha, const float * x, const int * incx, float * a, const int * lda);

void liftracc_sspr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * x, const int incx, float * ap);
void liftracc_sspr_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const float * alpha, const float * x, const int * incx, float * ap);

void liftracc_ssyr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * x, const int incx, const float * y, const int incy, float * a, const int lda);
void liftracc_ssyr2_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const float * alpha, const float * x, const int * incx, const float * y, const int * incy, float * a, const int * lda);

void liftracc_sspr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * x, const int incx, const float * y, const int incy, float * a);
void liftracc_sspr2_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const float * alpha, const float * x, const int * incx, const float * y, const int * incy, float * a);

void liftracc_dsymv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * a, const int lda, const double * x, const int incx, const double beta, double * y, const int incy);
void liftracc_dsymv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const double * alpha, const double * a, const int * lda, const double * x, const int * incx, const double * beta, double * y, const int * incy);

void liftracc_dsbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const int k, const double alpha, const double * a, const int lda, const double * x, const int incx, const double beta, double * y, const int incy);
void liftracc_dsbmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const int * k, const double * alpha, const double * a, const int * lda, const double * x, const int * incx, const double * beta, double * y, const int * incy);

void liftracc_dspmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * ap, const double * x, const int incx, const double beta, double * y, const int incy);
void liftracc_dspmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const double * alpha, const double * ap, const double * x, const int * incx, const double * beta, double * y, const int * incy);

void liftracc_dger(const liftracc_order_t order, const int m, const int n, const double alpha, const double * x, const int incx, const double * y, const int incy, double * a, const int lda);
void liftracc_dger_(const liftracc_order_t * order, const int * m, const int * n, const double * alpha, const double * x, const int * incx, const double * y, const int * incy, double * a, const int * lda);

void liftracc_dsyr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * x, const int incx, double * a, const int lda);
void liftracc_dsyr_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const double * alpha, const double * x, const int * incx, double * a, const int * lda);

void liftracc_dspr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * x, const int incx, double * ap);
void liftracc_dspr_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const double * alpha, const double * x, const int * incx, double * ap);

void liftracc_dsyr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * x, const int incx, const double * y, const int incy, double * a, const int lda);
void liftracc_dsyr2_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const double * alpha, const double * x, const int * incx, const double * y, const int * incy, double * a, const int * lda);

void liftracc_dspr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * x, const int incx, const double * y, const int incy, double * a);
void liftracc_dspr2_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const double * alpha, const double * x, const int * incx, const double * y, const int * incy, double * a);

void liftracc_chemv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy);
void liftracc_chemv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const void * alpha, const void * a, const int * lda, const void * x, const int * incx, const void * beta, void * y, const int * incy);

void liftracc_chbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const int k, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy);
void liftracc_chbmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * x, const int * incx, const void * beta, void * y, const int * incy);

void liftracc_chpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * ap, const void * x, const int incx, const void * beta, void * y, const int incy);
void liftracc_chpmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const void * alpha, const void * ap, const void * x, const int * incx, const void * beta, void * y, const int * incy);

void liftracc_cgeru(const liftracc_order_t order, const int m, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda);
void liftracc_cgeru_(const liftracc_order_t * order, const int * m, const int * n, const void * alpha, const void * x, const int * incx, const void * y, const int * incy, void * a, const int * lda);

void liftracc_cgerc(const liftracc_order_t order, const int m, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda);
void liftracc_cgerc_(const liftracc_order_t * order, const int * m, const int * n, const void * alpha, const void * x, const int * incx, const void * y, const int * incy, void * a, const int * lda);

void liftracc_cher(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const void * x, const int incx, void * a, const int lda);
void liftracc_cher_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const float * alpha, const void * x, const int * incx, void * a, const int * lda);

void liftracc_chpr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const void * x, const int incx, void * a);
void liftracc_chpr_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const float * alpha, const void * x, const int * incx, void * a);

void liftracc_cher2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda);
void liftracc_cher2_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const void * alpha, const void * x, const int * incx, const void * y, const int * incy, void * a, const int * lda);

void liftracc_chpr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * ap);
void liftracc_chpr2_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const void * alpha, const void * x, const int * incx, const void * y, const int * incy, void * ap);

void liftracc_zhemv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy);
void liftracc_zhemv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const void * alpha, const void * a, const int * lda, const void * x, const int * incx, const void * beta, void * y, const int * incy);

void liftracc_zhbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const int k, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy);
void liftracc_zhbmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * x, const int * incx, const void * beta, void * y, const int * incy);

void liftracc_zhpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * ap, const void * x, const int incx, const void * beta, void * y, const int incy);
void liftracc_zhpmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const void * alpha, const void * ap, const void * x, const int * incx, const void * beta, void * y, const int * incy);

void liftracc_zgeru(const liftracc_order_t order, const int m, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda);
void liftracc_zgeru_(const liftracc_order_t * order, const int * m, const int * n, const void * alpha, const void * x, const int * incx, const void * y, const int * incy, void * a, const int * lda);

void liftracc_zgerc(const liftracc_order_t order, const int m, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda);
void liftracc_zgerc_(const liftracc_order_t * order, const int * m, const int * n, const void * alpha, const void * x, const int * incx, const void * y, const int * incy, void * a, const int * lda);

void liftracc_zher(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const void * x, const int incx, void * a, const int lda);
void liftracc_zher_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const double * alpha, const void * x, const int * incx, void * a, const int * lda);

void liftracc_zhpr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const void * x, const int incx, void * a);
void liftracc_zhpr_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const double * alpha, const void * x, const int * incx, void * a);

void liftracc_zher2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda);
void liftracc_zher2_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const void * alpha, const void * x, const int * incx, const void * y, const int * incy, void * a, const int * lda);

void liftracc_zhpr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * ap);
void liftracc_zhpr2_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const void * alpha, const void * x, const int * incx, const void * y, const int * incy, void * ap);


#endif // __LIFTRACC_LEVEL2_H__


