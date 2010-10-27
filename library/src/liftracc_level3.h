
/**
 * @file liftracc_level3.h
 * @brief [generated file]
 *
 * This file is generated automatically, do not edit manually!
 */

#ifndef __LIFTRACC_LEVEL3_H__
#define __LIFTRACC_LEVEL3_H__

#include "liftracc_common.h"



/**
 * @brief liftracc sgemm function
 */
void liftracc_sgemm(const liftracc_order_t order, const liftracc_transpose_t transa, const liftracc_transpose_t transb, const int m, const int n, const int k, const float alpha, const float * a, const int lda, const float * b, const int ldb, const float beta, float * c, const int ldc);

/**
 * @brief liftracc sgemm function with pointer interface
 */
void liftracc_sgemm_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const liftracc_transpose_t * transb, const int * m, const int * n, const int * k, const float * alpha, const float * a, const int * lda, const float * b, const int * ldb, const float * beta, float * c, const int * ldc);


/**
 * @brief liftracc ssymm function
 */
void liftracc_ssymm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const float alpha, const float * a, const int lda, const float * b, const int ldb, const float beta, float * c, const int ldc);

/**
 * @brief liftracc ssymm function with pointer interface
 */
void liftracc_ssymm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const int * m, const int * n, const float * alpha, const float * a, const int * lda, const float * b, const int * ldb, const float * beta, float * c, const int * ldc);


/**
 * @brief liftracc ssyrk function
 */
void liftracc_ssyrk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const float alpha, const float * a, const int lda, const float beta, float * c, const int ldc);

/**
 * @brief liftracc ssyrk function with pointer interface
 */
void liftracc_ssyrk_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const float * alpha, const float * a, const int * lda, const float * beta, float * c, const int * ldc);


/**
 * @brief liftracc ssyr2k function
 */
void liftracc_ssyr2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const float alpha, const float * a, const int lda, const float * b, const int ldb, const float beta, float * c, const int ldc);

/**
 * @brief liftracc ssyr2k function with pointer interface
 */
void liftracc_ssyr2k_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const float * alpha, const float * a, const int * lda, const float * b, const int * ldb, const float * beta, float * c, const int * ldc);


/**
 * @brief liftracc strmm function
 */
void liftracc_strmm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const float alpha, const float * a, const int lda, float * b, const int ldb);

/**
 * @brief liftracc strmm function with pointer interface
 */
void liftracc_strmm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * m, const int * n, const float * alpha, const float * a, const int * lda, float * b, const int * ldb);


/**
 * @brief liftracc strsm function
 */
void liftracc_strsm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const float alpha, const float * a, const int lda, float * b, const int ldb);

/**
 * @brief liftracc strsm function with pointer interface
 */
void liftracc_strsm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * m, const int * n, const float * alpha, const float * a, const int * lda, float * b, const int * ldb);


/**
 * @brief liftracc dgemm function
 */
void liftracc_dgemm(const liftracc_order_t order, const liftracc_transpose_t transa, const liftracc_transpose_t transb, const int m, const int n, const int k, const double alpha, const double * a, const int lda, const double * b, const int ldb, const double beta, double * c, const int ldc);

/**
 * @brief liftracc dgemm function with pointer interface
 */
void liftracc_dgemm_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const liftracc_transpose_t * transb, const int * m, const int * n, const int * k, const double * alpha, const double * a, const int * lda, const double * b, const int * ldb, const double * beta, double * c, const int * ldc);


/**
 * @brief liftracc dsymm function
 */
void liftracc_dsymm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const double alpha, const double * a, const int lda, const double * b, const int ldb, const double beta, double * c, const int ldc);

/**
 * @brief liftracc dsymm function with pointer interface
 */
void liftracc_dsymm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const int * m, const int * n, const double * alpha, const double * a, const int * lda, const double * b, const int * ldb, const double * beta, double * c, const int * ldc);


/**
 * @brief liftracc dsyrk function
 */
void liftracc_dsyrk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const double alpha, const double * a, const int lda, const double beta, double * c, const int ldc);

/**
 * @brief liftracc dsyrk function with pointer interface
 */
void liftracc_dsyrk_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const double * alpha, const double * a, const int * lda, const double * beta, double * c, const int * ldc);


/**
 * @brief liftracc dsyr2k function
 */
void liftracc_dsyr2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const double alpha, const double * a, const int lda, const double * b, const int ldb, const double beta, double * c, const int ldc);

/**
 * @brief liftracc dsyr2k function with pointer interface
 */
void liftracc_dsyr2k_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const double * alpha, const double * a, const int * lda, const double * b, const int * ldb, const double * beta, double * c, const int * ldc);


/**
 * @brief liftracc dtrmm function
 */
void liftracc_dtrmm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const double alpha, const double * a, const int lda, double * b, const int ldb);

/**
 * @brief liftracc dtrmm function with pointer interface
 */
void liftracc_dtrmm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * m, const int * n, const double * alpha, const double * a, const int * lda, double * b, const int * ldb);


/**
 * @brief liftracc dtrsm function
 */
void liftracc_dtrsm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const double alpha, const double * a, const int lda, double * b, const int ldb);

/**
 * @brief liftracc dtrsm function with pointer interface
 */
void liftracc_dtrsm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * m, const int * n, const double * alpha, const double * a, const int * lda, double * b, const int * ldb);


/**
 * @brief liftracc cgemm function
 */
void liftracc_cgemm(const liftracc_order_t order, const liftracc_transpose_t transa, const liftracc_transpose_t transb, const int m, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc);

/**
 * @brief liftracc cgemm function with pointer interface
 */
void liftracc_cgemm_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const liftracc_transpose_t * transb, const int * m, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const void * beta, void * c, const int * ldc);


/**
 * @brief liftracc csymm function
 */
void liftracc_csymm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc);

/**
 * @brief liftracc csymm function with pointer interface
 */
void liftracc_csymm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const int * m, const int * n, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const void * beta, void * c, const int * ldc);


/**
 * @brief liftracc csyrk function
 */
void liftracc_csyrk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * beta, void * c, const int ldc);

/**
 * @brief liftracc csyrk function with pointer interface
 */
void liftracc_csyrk_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * beta, void * c, const int * ldc);


/**
 * @brief liftracc csyr2k function
 */
void liftracc_csyr2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc);

/**
 * @brief liftracc csyr2k function with pointer interface
 */
void liftracc_csyr2k_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const void * beta, void * c, const int * ldc);


/**
 * @brief liftracc ctrmm function
 */
void liftracc_ctrmm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const void * alpha, const void * a, const int lda, void * b, const int ldb);

/**
 * @brief liftracc ctrmm function with pointer interface
 */
void liftracc_ctrmm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * m, const int * n, const void * alpha, const void * a, const int * lda, void * b, const int * ldb);


/**
 * @brief liftracc ctrsm function
 */
void liftracc_ctrsm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const void * alpha, const void * a, const int lda, void * b, const int ldb);

/**
 * @brief liftracc ctrsm function with pointer interface
 */
void liftracc_ctrsm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * m, const int * n, const void * alpha, const void * a, const int * lda, void * b, const int * ldb);


/**
 * @brief liftracc zgemm function
 */
void liftracc_zgemm(const liftracc_order_t order, const liftracc_transpose_t transa, const liftracc_transpose_t transb, const int m, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc);

/**
 * @brief liftracc zgemm function with pointer interface
 */
void liftracc_zgemm_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const liftracc_transpose_t * transb, const int * m, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const void * beta, void * c, const int * ldc);


/**
 * @brief liftracc zsymm function
 */
void liftracc_zsymm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc);

/**
 * @brief liftracc zsymm function with pointer interface
 */
void liftracc_zsymm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const int * m, const int * n, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const void * beta, void * c, const int * ldc);


/**
 * @brief liftracc zsyrk function
 */
void liftracc_zsyrk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * beta, void * c, const int ldc);

/**
 * @brief liftracc zsyrk function with pointer interface
 */
void liftracc_zsyrk_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * beta, void * c, const int * ldc);


/**
 * @brief liftracc zsyr2k function
 */
void liftracc_zsyr2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc);

/**
 * @brief liftracc zsyr2k function with pointer interface
 */
void liftracc_zsyr2k_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const void * beta, void * c, const int * ldc);


/**
 * @brief liftracc ztrmm function
 */
void liftracc_ztrmm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const void * alpha, const void * a, const int lda, void * b, const int ldb);

/**
 * @brief liftracc ztrmm function with pointer interface
 */
void liftracc_ztrmm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * m, const int * n, const void * alpha, const void * a, const int * lda, void * b, const int * ldb);


/**
 * @brief liftracc ztrsm function
 */
void liftracc_ztrsm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const void * alpha, const void * a, const int lda, void * b, const int ldb);

/**
 * @brief liftracc ztrsm function with pointer interface
 */
void liftracc_ztrsm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * m, const int * n, const void * alpha, const void * a, const int * lda, void * b, const int * ldb);


/**
 * @brief liftracc chemm function
 */
void liftracc_chemm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc);

/**
 * @brief liftracc chemm function with pointer interface
 */
void liftracc_chemm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const int * m, const int * n, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const void * beta, void * c, const int * ldc);


/**
 * @brief liftracc cherk function
 */
void liftracc_cherk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const float alpha, const void * a, const int lda, const float beta, void * c, const int ldc);

/**
 * @brief liftracc cherk function with pointer interface
 */
void liftracc_cherk_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const float * alpha, const void * a, const int * lda, const float * beta, void * c, const int * ldc);


/**
 * @brief liftracc cher2k function
 */
void liftracc_cher2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const float beta, void * c, const int ldc);

/**
 * @brief liftracc cher2k function with pointer interface
 */
void liftracc_cher2k_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const float * beta, void * c, const int * ldc);


/**
 * @brief liftracc zhemm function
 */
void liftracc_zhemm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc);

/**
 * @brief liftracc zhemm function with pointer interface
 */
void liftracc_zhemm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const int * m, const int * n, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const void * beta, void * c, const int * ldc);


/**
 * @brief liftracc zherk function
 */
void liftracc_zherk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const double alpha, const void * a, const int lda, const double beta, void * c, const int ldc);

/**
 * @brief liftracc zherk function with pointer interface
 */
void liftracc_zherk_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const double * alpha, const void * a, const int * lda, const double * beta, void * c, const int * ldc);


/**
 * @brief liftracc zher2k function
 */
void liftracc_zher2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const double beta, void * c, const int ldc);

/**
 * @brief liftracc zher2k function with pointer interface
 */
void liftracc_zher2k_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const double * beta, void * c, const int * ldc);


/**
 * @brief liftracc xerbla function
 */
void liftracc_xerbla(int p, const char * rout, const char * form, ...);

/**
 * @brief liftracc xerbla function with pointer interface
 */
void liftracc_xerbla_(int * p, const char * rout, const char * form, ...);


#endif // __LIFTRACC_LEVEL3_H__


