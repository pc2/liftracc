
/**
 * @file liftracc_level2.h
 * @brief [generated file]
 *
 * This file is generated automatically, do not edit manually!
 */

#ifndef __LIFTRACC_LEVEL2_H__
#define __LIFTRACC_LEVEL2_H__

#include "liftracc_common.h"



/**
 * @brief liftracc sgemv function
 */
void liftracc_sgemv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const float alpha, const float * a, const int lda, const float * x, const int incx, const float beta, float * y, const int incy);

/**
 * @brief liftracc sgemv function with pointer interface
 */
void liftracc_sgemv_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const int * m, const int * n, const float * alpha, const float * a, const int * lda, const float * x, const int * incx, const float * beta, float * y, const int * incy);


/**
 * @brief liftracc sgbmv function
 */
void liftracc_sgbmv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const int kl, const int ku, const float alpha, const float * a, const int lda, const float * x, const int incx, const float beta, float * y, const int incy);

/**
 * @brief liftracc sgbmv function with pointer interface
 */
void liftracc_sgbmv_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const int * m, const int * n, const int * kl, const int * ku, const float * alpha, const float * a, const int * lda, const float * x, const int * incx, const float * beta, float * y, const int * incy);


/**
 * @brief liftracc strmv function
 */
void liftracc_strmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const float * a, const int lda, float * x, const int incx);

/**
 * @brief liftracc strmv function with pointer interface
 */
void liftracc_strmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const float * a, const int * lda, float * x, const int * incx);


/**
 * @brief liftracc stbmv function
 */
void liftracc_stbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const float * a, const int lda, float * x, const int incx);

/**
 * @brief liftracc stbmv function with pointer interface
 */
void liftracc_stbmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const int * k, const float * a, const int * lda, float * x, const int * incx);


/**
 * @brief liftracc stpmv function
 */
void liftracc_stpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const float * ap, float * x, const int incx);

/**
 * @brief liftracc stpmv function with pointer interface
 */
void liftracc_stpmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const float * ap, float * x, const int * incx);


/**
 * @brief liftracc strsv function
 */
void liftracc_strsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const float * a, const int lda, float * x, const int incx);

/**
 * @brief liftracc strsv function with pointer interface
 */
void liftracc_strsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const float * a, const int * lda, float * x, const int * incx);


/**
 * @brief liftracc stbsv function
 */
void liftracc_stbsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const float * a, const int lda, float * x, const int incx);

/**
 * @brief liftracc stbsv function with pointer interface
 */
void liftracc_stbsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const int * k, const float * a, const int * lda, float * x, const int * incx);


/**
 * @brief liftracc stpsv function
 */
void liftracc_stpsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const float * ap, float * x, const int incx);

/**
 * @brief liftracc stpsv function with pointer interface
 */
void liftracc_stpsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const float * ap, float * x, const int * incx);


/**
 * @brief liftracc dgemv function
 */
void liftracc_dgemv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const double alpha, const double * a, const int lda, const double * x, const int incx, const double beta, double * y, const int incy);

/**
 * @brief liftracc dgemv function with pointer interface
 */
void liftracc_dgemv_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const int * m, const int * n, const double * alpha, const double * a, const int * lda, const double * x, const int * incx, const double * beta, double * y, const int * incy);


/**
 * @brief liftracc dgbmv function
 */
void liftracc_dgbmv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const int kl, const int ku, const double alpha, const double * a, const int lda, const double * x, const int incx, const double beta, double * y, const int incy);

/**
 * @brief liftracc dgbmv function with pointer interface
 */
void liftracc_dgbmv_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const int * m, const int * n, const int * kl, const int * ku, const double * alpha, const double * a, const int * lda, const double * x, const int * incx, const double * beta, double * y, const int * incy);


/**
 * @brief liftracc dtrmv function
 */
void liftracc_dtrmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const double * a, const int lda, double * x, const int incx);

/**
 * @brief liftracc dtrmv function with pointer interface
 */
void liftracc_dtrmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const double * a, const int * lda, double * x, const int * incx);


/**
 * @brief liftracc dtbmv function
 */
void liftracc_dtbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const double * a, const int lda, double * x, const int incx);

/**
 * @brief liftracc dtbmv function with pointer interface
 */
void liftracc_dtbmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const int * k, const double * a, const int * lda, double * x, const int * incx);


/**
 * @brief liftracc dtpmv function
 */
void liftracc_dtpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const double * ap, double * x, const int incx);

/**
 * @brief liftracc dtpmv function with pointer interface
 */
void liftracc_dtpmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const double * ap, double * x, const int * incx);


/**
 * @brief liftracc dtrsv function
 */
void liftracc_dtrsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const double * a, const int lda, double * x, const int incx);

/**
 * @brief liftracc dtrsv function with pointer interface
 */
void liftracc_dtrsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const double * a, const int * lda, double * x, const int * incx);


/**
 * @brief liftracc dtbsv function
 */
void liftracc_dtbsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const double * a, const int lda, double * x, const int incx);

/**
 * @brief liftracc dtbsv function with pointer interface
 */
void liftracc_dtbsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const int * k, const double * a, const int * lda, double * x, const int * incx);


/**
 * @brief liftracc dtpsv function
 */
void liftracc_dtpsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const double * ap, double * x, const int incx);

/**
 * @brief liftracc dtpsv function with pointer interface
 */
void liftracc_dtpsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const double * ap, double * x, const int * incx);


/**
 * @brief liftracc cgemv function
 */
void liftracc_cgemv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy);

/**
 * @brief liftracc cgemv function with pointer interface
 */
void liftracc_cgemv_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const int * m, const int * n, const void * alpha, const void * a, const int * lda, const void * x, const int * incx, const void * beta, void * y, const int * incy);


/**
 * @brief liftracc cgbmv function
 */
void liftracc_cgbmv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const int kl, const int ku, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy);

/**
 * @brief liftracc cgbmv function with pointer interface
 */
void liftracc_cgbmv_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const int * m, const int * n, const int * kl, const int * ku, const void * alpha, const void * a, const int * lda, const void * x, const int * incx, const void * beta, void * y, const int * incy);


/**
 * @brief liftracc ctrmv function
 */
void liftracc_ctrmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * a, const int lda, void * x, const int incx);

/**
 * @brief liftracc ctrmv function with pointer interface
 */
void liftracc_ctrmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const void * a, const int * lda, void * x, const int * incx);


/**
 * @brief liftracc ctbmv function
 */
void liftracc_ctbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const void * a, const int lda, void * x, const int incx);

/**
 * @brief liftracc ctbmv function with pointer interface
 */
void liftracc_ctbmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const int * k, const void * a, const int * lda, void * x, const int * incx);


/**
 * @brief liftracc ctpmv function
 */
void liftracc_ctpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * ap, void * x, const int incx);

/**
 * @brief liftracc ctpmv function with pointer interface
 */
void liftracc_ctpmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const void * ap, void * x, const int * incx);


/**
 * @brief liftracc ctrsv function
 */
void liftracc_ctrsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * a, const int lda, void * x, const int incx);

/**
 * @brief liftracc ctrsv function with pointer interface
 */
void liftracc_ctrsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const void * a, const int * lda, void * x, const int * incx);


/**
 * @brief liftracc ctbsv function
 */
void liftracc_ctbsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const void * a, const int lda, void * x, const int incx);

/**
 * @brief liftracc ctbsv function with pointer interface
 */
void liftracc_ctbsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const int * k, const void * a, const int * lda, void * x, const int * incx);


/**
 * @brief liftracc ctpsv function
 */
void liftracc_ctpsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * ap, void * x, const int incx);

/**
 * @brief liftracc ctpsv function with pointer interface
 */
void liftracc_ctpsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const void * ap, void * x, const int * incx);


/**
 * @brief liftracc zgemv function
 */
void liftracc_zgemv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy);

/**
 * @brief liftracc zgemv function with pointer interface
 */
void liftracc_zgemv_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const int * m, const int * n, const void * alpha, const void * a, const int * lda, const void * x, const int * incx, const void * beta, void * y, const int * incy);


/**
 * @brief liftracc zgbmv function
 */
void liftracc_zgbmv(const liftracc_order_t order, const liftracc_transpose_t transa, const int m, const int n, const int kl, const int ku, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy);

/**
 * @brief liftracc zgbmv function with pointer interface
 */
void liftracc_zgbmv_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const int * m, const int * n, const int * kl, const int * ku, const void * alpha, const void * a, const int * lda, const void * x, const int * incx, const void * beta, void * y, const int * incy);


/**
 * @brief liftracc ztrmv function
 */
void liftracc_ztrmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * a, const int lda, void * x, const int incx);

/**
 * @brief liftracc ztrmv function with pointer interface
 */
void liftracc_ztrmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const void * a, const int * lda, void * x, const int * incx);


/**
 * @brief liftracc ztbmv function
 */
void liftracc_ztbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const void * a, const int lda, void * x, const int incx);

/**
 * @brief liftracc ztbmv function with pointer interface
 */
void liftracc_ztbmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const int * k, const void * a, const int * lda, void * x, const int * incx);


/**
 * @brief liftracc ztpmv function
 */
void liftracc_ztpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * ap, void * x, const int incx);

/**
 * @brief liftracc ztpmv function with pointer interface
 */
void liftracc_ztpmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const void * ap, void * x, const int * incx);


/**
 * @brief liftracc ztrsv function
 */
void liftracc_ztrsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * a, const int lda, void * x, const int incx);

/**
 * @brief liftracc ztrsv function with pointer interface
 */
void liftracc_ztrsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const void * a, const int * lda, void * x, const int * incx);


/**
 * @brief liftracc ztbsv function
 */
void liftracc_ztbsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const int k, const void * a, const int lda, void * x, const int incx);

/**
 * @brief liftracc ztbsv function with pointer interface
 */
void liftracc_ztbsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const int * k, const void * a, const int * lda, void * x, const int * incx);


/**
 * @brief liftracc ztpsv function
 */
void liftracc_ztpsv(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int n, const void * ap, void * x, const int incx);

/**
 * @brief liftracc ztpsv function with pointer interface
 */
void liftracc_ztpsv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * n, const void * ap, void * x, const int * incx);


/**
 * @brief liftracc ssymv function
 */
void liftracc_ssymv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * a, const int lda, const float * x, const int incx, const float beta, float * y, const int incy);

/**
 * @brief liftracc ssymv function with pointer interface
 */
void liftracc_ssymv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const float * alpha, const float * a, const int * lda, const float * x, const int * incx, const float * beta, float * y, const int * incy);


/**
 * @brief liftracc ssbmv function
 */
void liftracc_ssbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const int k, const float alpha, const float * a, const int lda, const float * x, const int incx, const float beta, float * y, const int incy);

/**
 * @brief liftracc ssbmv function with pointer interface
 */
void liftracc_ssbmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const int * k, const float * alpha, const float * a, const int * lda, const float * x, const int * incx, const float * beta, float * y, const int * incy);


/**
 * @brief liftracc sspmv function
 */
void liftracc_sspmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * ap, const float * x, const int incx, const float beta, float * y, const int incy);

/**
 * @brief liftracc sspmv function with pointer interface
 */
void liftracc_sspmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const float * alpha, const float * ap, const float * x, const int * incx, const float * beta, float * y, const int * incy);


/**
 * @brief liftracc sger function
 */
void liftracc_sger(const liftracc_order_t order, const int m, const int n, const float alpha, const float * x, const int incx, const float * y, const int incy, float * a, const int lda);

/**
 * @brief liftracc sger function with pointer interface
 */
void liftracc_sger_(const liftracc_order_t * order, const int * m, const int * n, const float * alpha, const float * x, const int * incx, const float * y, const int * incy, float * a, const int * lda);


/**
 * @brief liftracc ssyr function
 */
void liftracc_ssyr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * x, const int incx, float * a, const int lda);

/**
 * @brief liftracc ssyr function with pointer interface
 */
void liftracc_ssyr_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const float * alpha, const float * x, const int * incx, float * a, const int * lda);


/**
 * @brief liftracc sspr function
 */
void liftracc_sspr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * x, const int incx, float * ap);

/**
 * @brief liftracc sspr function with pointer interface
 */
void liftracc_sspr_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const float * alpha, const float * x, const int * incx, float * ap);


/**
 * @brief liftracc ssyr2 function
 */
void liftracc_ssyr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * x, const int incx, const float * y, const int incy, float * a, const int lda);

/**
 * @brief liftracc ssyr2 function with pointer interface
 */
void liftracc_ssyr2_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const float * alpha, const float * x, const int * incx, const float * y, const int * incy, float * a, const int * lda);


/**
 * @brief liftracc sspr2 function
 */
void liftracc_sspr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const float * x, const int incx, const float * y, const int incy, float * a);

/**
 * @brief liftracc sspr2 function with pointer interface
 */
void liftracc_sspr2_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const float * alpha, const float * x, const int * incx, const float * y, const int * incy, float * a);


/**
 * @brief liftracc dsymv function
 */
void liftracc_dsymv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * a, const int lda, const double * x, const int incx, const double beta, double * y, const int incy);

/**
 * @brief liftracc dsymv function with pointer interface
 */
void liftracc_dsymv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const double * alpha, const double * a, const int * lda, const double * x, const int * incx, const double * beta, double * y, const int * incy);


/**
 * @brief liftracc dsbmv function
 */
void liftracc_dsbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const int k, const double alpha, const double * a, const int lda, const double * x, const int incx, const double beta, double * y, const int incy);

/**
 * @brief liftracc dsbmv function with pointer interface
 */
void liftracc_dsbmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const int * k, const double * alpha, const double * a, const int * lda, const double * x, const int * incx, const double * beta, double * y, const int * incy);


/**
 * @brief liftracc dspmv function
 */
void liftracc_dspmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * ap, const double * x, const int incx, const double beta, double * y, const int incy);

/**
 * @brief liftracc dspmv function with pointer interface
 */
void liftracc_dspmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const double * alpha, const double * ap, const double * x, const int * incx, const double * beta, double * y, const int * incy);


/**
 * @brief liftracc dger function
 */
void liftracc_dger(const liftracc_order_t order, const int m, const int n, const double alpha, const double * x, const int incx, const double * y, const int incy, double * a, const int lda);

/**
 * @brief liftracc dger function with pointer interface
 */
void liftracc_dger_(const liftracc_order_t * order, const int * m, const int * n, const double * alpha, const double * x, const int * incx, const double * y, const int * incy, double * a, const int * lda);


/**
 * @brief liftracc dsyr function
 */
void liftracc_dsyr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * x, const int incx, double * a, const int lda);

/**
 * @brief liftracc dsyr function with pointer interface
 */
void liftracc_dsyr_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const double * alpha, const double * x, const int * incx, double * a, const int * lda);


/**
 * @brief liftracc dspr function
 */
void liftracc_dspr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * x, const int incx, double * ap);

/**
 * @brief liftracc dspr function with pointer interface
 */
void liftracc_dspr_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const double * alpha, const double * x, const int * incx, double * ap);


/**
 * @brief liftracc dsyr2 function
 */
void liftracc_dsyr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * x, const int incx, const double * y, const int incy, double * a, const int lda);

/**
 * @brief liftracc dsyr2 function with pointer interface
 */
void liftracc_dsyr2_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const double * alpha, const double * x, const int * incx, const double * y, const int * incy, double * a, const int * lda);


/**
 * @brief liftracc dspr2 function
 */
void liftracc_dspr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const double * x, const int incx, const double * y, const int incy, double * a);

/**
 * @brief liftracc dspr2 function with pointer interface
 */
void liftracc_dspr2_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const double * alpha, const double * x, const int * incx, const double * y, const int * incy, double * a);


/**
 * @brief liftracc chemv function
 */
void liftracc_chemv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy);

/**
 * @brief liftracc chemv function with pointer interface
 */
void liftracc_chemv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const void * alpha, const void * a, const int * lda, const void * x, const int * incx, const void * beta, void * y, const int * incy);


/**
 * @brief liftracc chbmv function
 */
void liftracc_chbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const int k, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy);

/**
 * @brief liftracc chbmv function with pointer interface
 */
void liftracc_chbmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * x, const int * incx, const void * beta, void * y, const int * incy);


/**
 * @brief liftracc chpmv function
 */
void liftracc_chpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * ap, const void * x, const int incx, const void * beta, void * y, const int incy);

/**
 * @brief liftracc chpmv function with pointer interface
 */
void liftracc_chpmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const void * alpha, const void * ap, const void * x, const int * incx, const void * beta, void * y, const int * incy);


/**
 * @brief liftracc cgeru function
 */
void liftracc_cgeru(const liftracc_order_t order, const int m, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda);

/**
 * @brief liftracc cgeru function with pointer interface
 */
void liftracc_cgeru_(const liftracc_order_t * order, const int * m, const int * n, const void * alpha, const void * x, const int * incx, const void * y, const int * incy, void * a, const int * lda);


/**
 * @brief liftracc cgerc function
 */
void liftracc_cgerc(const liftracc_order_t order, const int m, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda);

/**
 * @brief liftracc cgerc function with pointer interface
 */
void liftracc_cgerc_(const liftracc_order_t * order, const int * m, const int * n, const void * alpha, const void * x, const int * incx, const void * y, const int * incy, void * a, const int * lda);


/**
 * @brief liftracc cher function
 */
void liftracc_cher(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const void * x, const int incx, void * a, const int lda);

/**
 * @brief liftracc cher function with pointer interface
 */
void liftracc_cher_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const float * alpha, const void * x, const int * incx, void * a, const int * lda);


/**
 * @brief liftracc chpr function
 */
void liftracc_chpr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const float alpha, const void * x, const int incx, void * a);

/**
 * @brief liftracc chpr function with pointer interface
 */
void liftracc_chpr_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const float * alpha, const void * x, const int * incx, void * a);


/**
 * @brief liftracc cher2 function
 */
void liftracc_cher2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda);

/**
 * @brief liftracc cher2 function with pointer interface
 */
void liftracc_cher2_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const void * alpha, const void * x, const int * incx, const void * y, const int * incy, void * a, const int * lda);


/**
 * @brief liftracc chpr2 function
 */
void liftracc_chpr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * ap);

/**
 * @brief liftracc chpr2 function with pointer interface
 */
void liftracc_chpr2_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const void * alpha, const void * x, const int * incx, const void * y, const int * incy, void * ap);


/**
 * @brief liftracc zhemv function
 */
void liftracc_zhemv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy);

/**
 * @brief liftracc zhemv function with pointer interface
 */
void liftracc_zhemv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const void * alpha, const void * a, const int * lda, const void * x, const int * incx, const void * beta, void * y, const int * incy);


/**
 * @brief liftracc zhbmv function
 */
void liftracc_zhbmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const int k, const void * alpha, const void * a, const int lda, const void * x, const int incx, const void * beta, void * y, const int incy);

/**
 * @brief liftracc zhbmv function with pointer interface
 */
void liftracc_zhbmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * x, const int * incx, const void * beta, void * y, const int * incy);


/**
 * @brief liftracc zhpmv function
 */
void liftracc_zhpmv(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * ap, const void * x, const int incx, const void * beta, void * y, const int incy);

/**
 * @brief liftracc zhpmv function with pointer interface
 */
void liftracc_zhpmv_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const void * alpha, const void * ap, const void * x, const int * incx, const void * beta, void * y, const int * incy);


/**
 * @brief liftracc zgeru function
 */
void liftracc_zgeru(const liftracc_order_t order, const int m, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda);

/**
 * @brief liftracc zgeru function with pointer interface
 */
void liftracc_zgeru_(const liftracc_order_t * order, const int * m, const int * n, const void * alpha, const void * x, const int * incx, const void * y, const int * incy, void * a, const int * lda);


/**
 * @brief liftracc zgerc function
 */
void liftracc_zgerc(const liftracc_order_t order, const int m, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda);

/**
 * @brief liftracc zgerc function with pointer interface
 */
void liftracc_zgerc_(const liftracc_order_t * order, const int * m, const int * n, const void * alpha, const void * x, const int * incx, const void * y, const int * incy, void * a, const int * lda);


/**
 * @brief liftracc zher function
 */
void liftracc_zher(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const void * x, const int incx, void * a, const int lda);

/**
 * @brief liftracc zher function with pointer interface
 */
void liftracc_zher_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const double * alpha, const void * x, const int * incx, void * a, const int * lda);


/**
 * @brief liftracc zhpr function
 */
void liftracc_zhpr(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const double alpha, const void * x, const int incx, void * a);

/**
 * @brief liftracc zhpr function with pointer interface
 */
void liftracc_zhpr_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const double * alpha, const void * x, const int * incx, void * a);


/**
 * @brief liftracc zher2 function
 */
void liftracc_zher2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * a, const int lda);

/**
 * @brief liftracc zher2 function with pointer interface
 */
void liftracc_zher2_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const void * alpha, const void * x, const int * incx, const void * y, const int * incy, void * a, const int * lda);


/**
 * @brief liftracc zhpr2 function
 */
void liftracc_zhpr2(const liftracc_order_t order, const liftracc_uplo_t uplo, const int n, const void * alpha, const void * x, const int incx, const void * y, const int incy, void * ap);

/**
 * @brief liftracc zhpr2 function with pointer interface
 */
void liftracc_zhpr2_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const int * n, const void * alpha, const void * x, const int * incx, const void * y, const int * incy, void * ap);


#endif // __LIFTRACC_LEVEL2_H__


