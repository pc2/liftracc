
/**
 * @file liftracc_level1.h
 * @brief [generated file]
 *
 * This file is generated automatically, do not edit manually!
 */

#ifndef __LIFTRACC_LEVEL1_H__
#define __LIFTRACC_LEVEL1_H__

#include "liftracc_common.h"



/**
 * @brief liftracc sdsdot function
 */
float liftracc_sdsdot(const int n, const float alpha, const float * x, const int incx, const float * y, const int incy);

/**
 * @brief liftracc sdsdot function with pointer interface
 */
float liftracc_sdsdot_(const int * n, const float * alpha, const float * x, const int * incx, const float * y, const int * incy);


/**
 * @brief liftracc dsdot function
 */
double liftracc_dsdot(const int n, const float * x, const int incx, const float * y, const int incy);

/**
 * @brief liftracc dsdot function with pointer interface
 */
double liftracc_dsdot_(const int * n, const float * x, const int * incx, const float * y, const int * incy);


/**
 * @brief liftracc sdot function
 */
float liftracc_sdot(const int n, const float * x, const int incx, const float * y, const int incy);

/**
 * @brief liftracc sdot function with pointer interface
 */
float liftracc_sdot_(const int * n, const float * x, const int * incx, const float * y, const int * incy);


/**
 * @brief liftracc ddot function
 */
double liftracc_ddot(const int n, const double * x, const int incx, const double * y, const int incy);

/**
 * @brief liftracc ddot function with pointer interface
 */
double liftracc_ddot_(const int * n, const double * x, const int * incx, const double * y, const int * incy);


/**
 * @brief liftracc cdotu_sub function
 */
void liftracc_cdotu_sub(const int n, const void * x, const int incx, const void * y, const int incy, void * dotu);

/**
 * @brief liftracc cdotu_sub function with pointer interface
 */
void liftracc_cdotu_sub_(const int * n, const void * x, const int * incx, const void * y, const int * incy, void * dotu);


/**
 * @brief liftracc cdotc_sub function
 */
void liftracc_cdotc_sub(const int n, const void * x, const int incx, const void * y, const int incy, void * dotc);

/**
 * @brief liftracc cdotc_sub function with pointer interface
 */
void liftracc_cdotc_sub_(const int * n, const void * x, const int * incx, const void * y, const int * incy, void * dotc);


/**
 * @brief liftracc zdotu_sub function
 */
void liftracc_zdotu_sub(const int n, const void * x, const int incx, const void * y, const int incy, void * dotu);

/**
 * @brief liftracc zdotu_sub function with pointer interface
 */
void liftracc_zdotu_sub_(const int * n, const void * x, const int * incx, const void * y, const int * incy, void * dotu);


/**
 * @brief liftracc zdotc_sub function
 */
void liftracc_zdotc_sub(const int n, const void * x, const int incx, const void * y, const int incy, void * dotc);

/**
 * @brief liftracc zdotc_sub function with pointer interface
 */
void liftracc_zdotc_sub_(const int * n, const void * x, const int * incx, const void * y, const int * incy, void * dotc);


/**
 * @brief liftracc snrm2 function
 */
float liftracc_snrm2(const int n, const float * x, const int incx);

/**
 * @brief liftracc snrm2 function with pointer interface
 */
float liftracc_snrm2_(const int * n, const float * x, const int * incx);


/**
 * @brief liftracc sasum function
 */
float liftracc_sasum(const int n, const float * x, const int incx);

/**
 * @brief liftracc sasum function with pointer interface
 */
float liftracc_sasum_(const int * n, const float * x, const int * incx);


/**
 * @brief liftracc dnrm2 function
 */
double liftracc_dnrm2(const int n, const double * x, const int incx);

/**
 * @brief liftracc dnrm2 function with pointer interface
 */
double liftracc_dnrm2_(const int * n, const double * x, const int * incx);


/**
 * @brief liftracc dasum function
 */
double liftracc_dasum(const int n, const double * x, const int incx);

/**
 * @brief liftracc dasum function with pointer interface
 */
double liftracc_dasum_(const int * n, const double * x, const int * incx);


/**
 * @brief liftracc scnrm2 function
 */
float liftracc_scnrm2(const int n, const void * x, const int incx);

/**
 * @brief liftracc scnrm2 function with pointer interface
 */
float liftracc_scnrm2_(const int * n, const void * x, const int * incx);


/**
 * @brief liftracc scasum function
 */
float liftracc_scasum(const int n, const void * x, const int incx);

/**
 * @brief liftracc scasum function with pointer interface
 */
float liftracc_scasum_(const int * n, const void * x, const int * incx);


/**
 * @brief liftracc dznrm2 function
 */
double liftracc_dznrm2(const int n, const void * x, const int incx);

/**
 * @brief liftracc dznrm2 function with pointer interface
 */
double liftracc_dznrm2_(const int * n, const void * x, const int * incx);


/**
 * @brief liftracc dzasum function
 */
double liftracc_dzasum(const int n, const void * x, const int incx);

/**
 * @brief liftracc dzasum function with pointer interface
 */
double liftracc_dzasum_(const int * n, const void * x, const int * incx);


/**
 * @brief liftracc isamax function
 */
liftracc_index_t liftracc_isamax(const int n, const float * x, const int incx);

/**
 * @brief liftracc isamax function with pointer interface
 */
liftracc_index_t liftracc_isamax_(const int * n, const float * x, const int * incx);


/**
 * @brief liftracc idamax function
 */
liftracc_index_t liftracc_idamax(const int n, const double * x, const int incx);

/**
 * @brief liftracc idamax function with pointer interface
 */
liftracc_index_t liftracc_idamax_(const int * n, const double * x, const int * incx);


/**
 * @brief liftracc icamax function
 */
liftracc_index_t liftracc_icamax(const int n, const void * x, const int incx);

/**
 * @brief liftracc icamax function with pointer interface
 */
liftracc_index_t liftracc_icamax_(const int * n, const void * x, const int * incx);


/**
 * @brief liftracc izamax function
 */
liftracc_index_t liftracc_izamax(const int n, const void * x, const int incx);

/**
 * @brief liftracc izamax function with pointer interface
 */
liftracc_index_t liftracc_izamax_(const int * n, const void * x, const int * incx);


/**
 * @brief liftracc sswap function
 */
void liftracc_sswap(const int n, float * x, const int incx, float * y, const int incy);

/**
 * @brief liftracc sswap function with pointer interface
 */
void liftracc_sswap_(const int * n, float * x, const int * incx, float * y, const int * incy);


/**
 * @brief liftracc scopy function
 */
void liftracc_scopy(const int n, const float * x, const int incx, float * y, const int incy);

/**
 * @brief liftracc scopy function with pointer interface
 */
void liftracc_scopy_(const int * n, const float * x, const int * incx, float * y, const int * incy);


/**
 * @brief liftracc saxpy function
 */
void liftracc_saxpy(const int n, const float alpha, const float * x, const int incx, float * y, const int incy);

/**
 * @brief liftracc saxpy function with pointer interface
 */
void liftracc_saxpy_(const int * n, const float * alpha, const float * x, const int * incx, float * y, const int * incy);


/**
 * @brief liftracc dswap function
 */
void liftracc_dswap(const int n, double * x, const int incx, double * y, const int incy);

/**
 * @brief liftracc dswap function with pointer interface
 */
void liftracc_dswap_(const int * n, double * x, const int * incx, double * y, const int * incy);


/**
 * @brief liftracc dcopy function
 */
void liftracc_dcopy(const int n, const double * x, const int incx, double * y, const int incy);

/**
 * @brief liftracc dcopy function with pointer interface
 */
void liftracc_dcopy_(const int * n, const double * x, const int * incx, double * y, const int * incy);


/**
 * @brief liftracc daxpy function
 */
void liftracc_daxpy(const int n, const double alpha, const double * x, const int incx, double * y, const int incy);

/**
 * @brief liftracc daxpy function with pointer interface
 */
void liftracc_daxpy_(const int * n, const double * alpha, const double * x, const int * incx, double * y, const int * incy);


/**
 * @brief liftracc cswap function
 */
void liftracc_cswap(const int n, void * x, const int incx, void * y, const int incy);

/**
 * @brief liftracc cswap function with pointer interface
 */
void liftracc_cswap_(const int * n, void * x, const int * incx, void * y, const int * incy);


/**
 * @brief liftracc ccopy function
 */
void liftracc_ccopy(const int n, const void * x, const int incx, void * y, const int incy);

/**
 * @brief liftracc ccopy function with pointer interface
 */
void liftracc_ccopy_(const int * n, const void * x, const int * incx, void * y, const int * incy);


/**
 * @brief liftracc caxpy function
 */
void liftracc_caxpy(const int n, const void * alpha, const void * x, const int incx, void * y, const int incy);

/**
 * @brief liftracc caxpy function with pointer interface
 */
void liftracc_caxpy_(const int * n, const void * alpha, const void * x, const int * incx, void * y, const int * incy);


/**
 * @brief liftracc zswap function
 */
void liftracc_zswap(const int n, void * x, const int incx, void * y, const int incy);

/**
 * @brief liftracc zswap function with pointer interface
 */
void liftracc_zswap_(const int * n, void * x, const int * incx, void * y, const int * incy);


/**
 * @brief liftracc zcopy function
 */
void liftracc_zcopy(const int n, const void * x, const int incx, void * y, const int incy);

/**
 * @brief liftracc zcopy function with pointer interface
 */
void liftracc_zcopy_(const int * n, const void * x, const int * incx, void * y, const int * incy);


/**
 * @brief liftracc zaxpy function
 */
void liftracc_zaxpy(const int n, const void * alpha, const void * x, const int incx, void * y, const int incy);

/**
 * @brief liftracc zaxpy function with pointer interface
 */
void liftracc_zaxpy_(const int * n, const void * alpha, const void * x, const int * incx, void * y, const int * incy);


/**
 * @brief liftracc srotg function
 */
void liftracc_srotg(float * a, float * b, float * c, float * s);

/**
 * @brief liftracc srotg function with pointer interface
 */
void liftracc_srotg_(float * a, float * b, float * c, float * s);


/**
 * @brief liftracc srotmg function
 */
void liftracc_srotmg(float * d1, float * d2, float * b1, const float b2, float * p);

/**
 * @brief liftracc srotmg function with pointer interface
 */
void liftracc_srotmg_(float * d1, float * d2, float * b1, const float * b2, float * p);


/**
 * @brief liftracc srot function
 */
void liftracc_srot(const int n, float * x, const int incx, float * y, const int incy, const float c, const float s);

/**
 * @brief liftracc srot function with pointer interface
 */
void liftracc_srot_(const int * n, float * x, const int * incx, float * y, const int * incy, const float * c, const float * s);


/**
 * @brief liftracc srotm function
 */
void liftracc_srotm(const int n, float * x, const int incx, float * y, const int incy, const float * p);

/**
 * @brief liftracc srotm function with pointer interface
 */
void liftracc_srotm_(const int * n, float * x, const int * incx, float * y, const int * incy, const float * p);


/**
 * @brief liftracc drotg function
 */
void liftracc_drotg(double * a, double * b, double * c, double * s);

/**
 * @brief liftracc drotg function with pointer interface
 */
void liftracc_drotg_(double * a, double * b, double * c, double * s);


/**
 * @brief liftracc drotmg function
 */
void liftracc_drotmg(double * d1, double * d2, double * b1, const double b2, double * p);

/**
 * @brief liftracc drotmg function with pointer interface
 */
void liftracc_drotmg_(double * d1, double * d2, double * b1, const double * b2, double * p);


/**
 * @brief liftracc drot function
 */
void liftracc_drot(const int n, double * x, const int incx, double * y, const int incy, const double c, const double s);

/**
 * @brief liftracc drot function with pointer interface
 */
void liftracc_drot_(const int * n, double * x, const int * incx, double * y, const int * incy, const double * c, const double * s);


/**
 * @brief liftracc drotm function
 */
void liftracc_drotm(const int n, double * x, const int incx, double * y, const int incy, const double * p);

/**
 * @brief liftracc drotm function with pointer interface
 */
void liftracc_drotm_(const int * n, double * x, const int * incx, double * y, const int * incy, const double * p);


/**
 * @brief liftracc sscal function
 */
void liftracc_sscal(const int n, const float alpha, float * x, const int incx);

/**
 * @brief liftracc sscal function with pointer interface
 */
void liftracc_sscal_(const int * n, const float * alpha, float * x, const int * incx);


/**
 * @brief liftracc dscal function
 */
void liftracc_dscal(const int n, const double alpha, double * x, const int incx);

/**
 * @brief liftracc dscal function with pointer interface
 */
void liftracc_dscal_(const int * n, const double * alpha, double * x, const int * incx);


/**
 * @brief liftracc cscal function
 */
void liftracc_cscal(const int n, const void * alpha, void * x, const int incx);

/**
 * @brief liftracc cscal function with pointer interface
 */
void liftracc_cscal_(const int * n, const void * alpha, void * x, const int * incx);


/**
 * @brief liftracc zscal function
 */
void liftracc_zscal(const int n, const void * alpha, void * x, const int incx);

/**
 * @brief liftracc zscal function with pointer interface
 */
void liftracc_zscal_(const int * n, const void * alpha, void * x, const int * incx);


/**
 * @brief liftracc csscal function
 */
void liftracc_csscal(const int n, const float alpha, void * x, const int incx);

/**
 * @brief liftracc csscal function with pointer interface
 */
void liftracc_csscal_(const int * n, const float * alpha, void * x, const int * incx);


/**
 * @brief liftracc zdscal function
 */
void liftracc_zdscal(const int n, const double alpha, void * x, const int incx);

/**
 * @brief liftracc zdscal function with pointer interface
 */
void liftracc_zdscal_(const int * n, const double * alpha, void * x, const int * incx);


#endif // __LIFTRACC_LEVEL1_H__


