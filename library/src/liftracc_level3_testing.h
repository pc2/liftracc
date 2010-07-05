
/***
 * Testing version! Edit to your needs.
 */

#ifndef __LIFTRACC_LEVEL3_H__
#define __LIFTRACC_LEVEL3_H__

#include "liftracc_common.h"


void liftracc_sgemm(const liftracc_order_t order, const liftracc_transpose_t transa, const liftracc_transpose_t transb, const int m, const int n, const int k, const float alpha, const float * a, const int lda, const float * b, const int ldb, const float beta, float * c, const int ldc);
void liftracc_sgemm_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const liftracc_transpose_t * transb, const int * m, const int * n, const int * k, const float * alpha, const float * a, const int * lda, const float * b, const int * ldb, const float * beta, float * c, const int * ldc);

void liftracc_ssymm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const float alpha, const float * a, const int lda, const float * b, const int ldb, const float beta, float * c, const int ldc);
void liftracc_ssymm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const int * m, const int * n, const float * alpha, const float * a, const int * lda, const float * b, const int * ldb, const float * beta, float * c, const int * ldc);

void liftracc_ssyrk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const float alpha, const float * a, const int lda, const float beta, float * c, const int ldc);
void liftracc_ssyrk_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const float * alpha, const float * a, const int * lda, const float * beta, float * c, const int * ldc);

void liftracc_ssyr2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const float alpha, const float * a, const int lda, const float * b, const int ldb, const float beta, float * c, const int ldc);
void liftracc_ssyr2k_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const float * alpha, const float * a, const int * lda, const float * b, const int * ldb, const float * beta, float * c, const int * ldc);

void liftracc_strmm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const float alpha, const float * a, const int lda, float * b, const int ldb);
void liftracc_strmm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * m, const int * n, const float * alpha, const float * a, const int * lda, float * b, const int * ldb);

void liftracc_strsm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const float alpha, const float * a, const int lda, float * b, const int ldb);
void liftracc_strsm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * m, const int * n, const float * alpha, const float * a, const int * lda, float * b, const int * ldb);

void liftracc_dgemm(const liftracc_order_t order, const liftracc_transpose_t transa, const liftracc_transpose_t transb, const int m, const int n, const int k, const double alpha, const double * a, const int lda, const double * b, const int ldb, const double beta, double * c, const int ldc);
void liftracc_dgemm_(const char * transa, const char * transb, const int * m, const int * n, const int * k, const double * alpha, const double * a, const int * lda, const double * b, const int * ldb, const double * beta, double * c, const int * ldc);

void liftracc_dsymm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const double alpha, const double * a, const int lda, const double * b, const int ldb, const double beta, double * c, const int ldc);
void liftracc_dsymm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const int * m, const int * n, const double * alpha, const double * a, const int * lda, const double * b, const int * ldb, const double * beta, double * c, const int * ldc);

void liftracc_dsyrk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const double alpha, const double * a, const int lda, const double beta, double * c, const int ldc);
void liftracc_dsyrk_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const double * alpha, const double * a, const int * lda, const double * beta, double * c, const int * ldc);

void liftracc_dsyr2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const double alpha, const double * a, const int lda, const double * b, const int ldb, const double beta, double * c, const int ldc);
void liftracc_dsyr2k_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const double * alpha, const double * a, const int * lda, const double * b, const int * ldb, const double * beta, double * c, const int * ldc);

void liftracc_dtrmm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const double alpha, const double * a, const int lda, double * b, const int ldb);
void liftracc_dtrmm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * m, const int * n, const double * alpha, const double * a, const int * lda, double * b, const int * ldb);

void liftracc_dtrsm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const double alpha, const double * a, const int lda, double * b, const int ldb);
void liftracc_dtrsm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * m, const int * n, const double * alpha, const double * a, const int * lda, double * b, const int * ldb);

void liftracc_cgemm(const liftracc_order_t order, const liftracc_transpose_t transa, const liftracc_transpose_t transb, const int m, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc);
void liftracc_cgemm_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const liftracc_transpose_t * transb, const int * m, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const void * beta, void * c, const int * ldc);

void liftracc_csymm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc);
void liftracc_csymm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const int * m, const int * n, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const void * beta, void * c, const int * ldc);

void liftracc_csyrk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * beta, void * c, const int ldc);
void liftracc_csyrk_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * beta, void * c, const int * ldc);

void liftracc_csyr2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc);
void liftracc_csyr2k_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const void * beta, void * c, const int * ldc);

void liftracc_ctrmm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const void * alpha, const void * a, const int lda, void * b, const int ldb);
void liftracc_ctrmm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * m, const int * n, const void * alpha, const void * a, const int * lda, void * b, const int * ldb);

void liftracc_ctrsm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const void * alpha, const void * a, const int lda, void * b, const int ldb);
void liftracc_ctrsm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * m, const int * n, const void * alpha, const void * a, const int * lda, void * b, const int * ldb);

void liftracc_zgemm(const liftracc_order_t order, const liftracc_transpose_t transa, const liftracc_transpose_t transb, const int m, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc);
void liftracc_zgemm_(const liftracc_order_t * order, const liftracc_transpose_t * transa, const liftracc_transpose_t * transb, const int * m, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const void * beta, void * c, const int * ldc);

void liftracc_zsymm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc);
void liftracc_zsymm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const int * m, const int * n, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const void * beta, void * c, const int * ldc);

void liftracc_zsyrk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * beta, void * c, const int ldc);
void liftracc_zsyrk_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * beta, void * c, const int * ldc);

void liftracc_zsyr2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc);
void liftracc_zsyr2k_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const void * beta, void * c, const int * ldc);

void liftracc_ztrmm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const void * alpha, const void * a, const int lda, void * b, const int ldb);
void liftracc_ztrmm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * m, const int * n, const void * alpha, const void * a, const int * lda, void * b, const int * ldb);

void liftracc_ztrsm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const liftracc_transpose_t transa, const liftracc_diag_t diag, const int m, const int n, const void * alpha, const void * a, const int lda, void * b, const int ldb);
void liftracc_ztrsm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const liftracc_transpose_t * transa, const liftracc_diag_t * diag, const int * m, const int * n, const void * alpha, const void * a, const int * lda, void * b, const int * ldb);

void liftracc_chemm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc);
void liftracc_chemm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const int * m, const int * n, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const void * beta, void * c, const int * ldc);

void liftracc_cherk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const float alpha, const void * a, const int lda, const float beta, void * c, const int ldc);
void liftracc_cherk_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const float * alpha, const void * a, const int * lda, const float * beta, void * c, const int * ldc);

void liftracc_cher2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const float beta, void * c, const int ldc);
void liftracc_cher2k_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const float * beta, void * c, const int * ldc);

void liftracc_zhemm(const liftracc_order_t order, const liftracc_side_t side, const liftracc_uplo_t uplo, const int m, const int n, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const void * beta, void * c, const int ldc);
void liftracc_zhemm_(const liftracc_order_t * order, const liftracc_side_t * side, const liftracc_uplo_t * uplo, const int * m, const int * n, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const void * beta, void * c, const int * ldc);

void liftracc_zherk(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const double alpha, const void * a, const int lda, const double beta, void * c, const int ldc);
void liftracc_zherk_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const double * alpha, const void * a, const int * lda, const double * beta, void * c, const int * ldc);

void liftracc_zher2k(const liftracc_order_t order, const liftracc_uplo_t uplo, const liftracc_transpose_t trans, const int n, const int k, const void * alpha, const void * a, const int lda, const void * b, const int ldb, const double beta, void * c, const int ldc);
void liftracc_zher2k_(const liftracc_order_t * order, const liftracc_uplo_t * uplo, const liftracc_transpose_t * trans, const int * n, const int * k, const void * alpha, const void * a, const int * lda, const void * b, const int * ldb, const double * beta, void * c, const int * ldc);

void liftracc_xerbla(int p, const char * rout, const char * form, ...);
void liftracc_xerbla_(int * p, const char * rout, const char * form, ...);


#endif // __LIFTRACC_LEVEL3_H__


