
/***
 * This file is generated automatically, do not edit manually!
 */

#ifndef __LIFTRACC_LEVEL1_H__
#define __LIFTRACC_LEVEL1_H__

#include "liftracc_common.h"


float liftracc_sdsdot(const int n, const float alpha, const float * x, const int incx, const float * y, const int incy);
float liftracc_sdsdot_(const int * n, const float * alpha, const float * x, const int * incx, const float * y, const int * incy);

double liftracc_dsdot(const int n, const float * x, const int incx, const float * y, const int incy);
double liftracc_dsdot_(const int * n, const float * x, const int * incx, const float * y, const int * incy);

float liftracc_sdot(const int n, const float * x, const int incx, const float * y, const int incy);
float liftracc_sdot_(const int * n, const float * x, const int * incx, const float * y, const int * incy);

double liftracc_ddot(const int n, const double * x, const int incx, const double * y, const int incy);
double liftracc_ddot_(const int * n, const double * x, const int * incx, const double * y, const int * incy);

void liftracc_cdotu_sub(const int n, const void * x, const int incx, const void * y, const int incy, void * dotu);
void liftracc_cdotu_sub_(const int * n, const void * x, const int * incx, const void * y, const int * incy, void * dotu);

void liftracc_cdotc_sub(const int n, const void * x, const int incx, const void * y, const int incy, void * dotc);
void liftracc_cdotc_sub_(const int * n, const void * x, const int * incx, const void * y, const int * incy, void * dotc);

void liftracc_zdotu_sub(const int n, const void * x, const int incx, const void * y, const int incy, void * dotu);
void liftracc_zdotu_sub_(const int * n, const void * x, const int * incx, const void * y, const int * incy, void * dotu);

void liftracc_zdotc_sub(const int n, const void * x, const int incx, const void * y, const int incy, void * dotc);
void liftracc_zdotc_sub_(const int * n, const void * x, const int * incx, const void * y, const int * incy, void * dotc);

float liftracc_snrm2(const int n, const float * x, const int incx);
float liftracc_snrm2_(const int * n, const float * x, const int * incx);

float liftracc_sasum(const int n, const float * x, const int incx);
float liftracc_sasum_(const int * n, const float * x, const int * incx);

double liftracc_dnrm2(const int n, const double * x, const int incx);
double liftracc_dnrm2_(const int * n, const double * x, const int * incx);

double liftracc_dasum(const int n, const double * x, const int incx);
double liftracc_dasum_(const int * n, const double * x, const int * incx);

float liftracc_scnrm2(const int n, const void * x, const int incx);
float liftracc_scnrm2_(const int * n, const void * x, const int * incx);

float liftracc_scasum(const int n, const void * x, const int incx);
float liftracc_scasum_(const int * n, const void * x, const int * incx);

double liftracc_dznrm2(const int n, const void * x, const int incx);
double liftracc_dznrm2_(const int * n, const void * x, const int * incx);

double liftracc_dzasum(const int n, const void * x, const int incx);
double liftracc_dzasum_(const int * n, const void * x, const int * incx);

liftracc_index_t liftracc_isamax(const int n, const float * x, const int incx);
liftracc_index_t liftracc_isamax_(const int * n, const float * x, const int * incx);

liftracc_index_t liftracc_idamax(const int n, const double * x, const int incx);
liftracc_index_t liftracc_idamax_(const int * n, const double * x, const int * incx);

liftracc_index_t liftracc_icamax(const int n, const void * x, const int incx);
liftracc_index_t liftracc_icamax_(const int * n, const void * x, const int * incx);

liftracc_index_t liftracc_izamax(const int n, const void * x, const int incx);
liftracc_index_t liftracc_izamax_(const int * n, const void * x, const int * incx);

void liftracc_sswap(const int n, float * x, const int incx, float * y, const int incy);
void liftracc_sswap_(const int * n, float * x, const int * incx, float * y, const int * incy);

void liftracc_scopy(const int n, const float * x, const int incx, float * y, const int incy);
void liftracc_scopy_(const int * n, const float * x, const int * incx, float * y, const int * incy);

void liftracc_saxpy(const int n, const float alpha, const float * x, const int incx, float * y, const int incy);
void liftracc_saxpy_(const int * n, const float * alpha, const float * x, const int * incx, float * y, const int * incy);

void liftracc_dswap(const int n, double * x, const int incx, double * y, const int incy);
void liftracc_dswap_(const int * n, double * x, const int * incx, double * y, const int * incy);

void liftracc_dcopy(const int n, const double * x, const int incx, double * y, const int incy);
void liftracc_dcopy_(const int * n, const double * x, const int * incx, double * y, const int * incy);

void liftracc_daxpy(const int n, const double alpha, const double * x, const int incx, double * y, const int incy);
void liftracc_daxpy_(const int * n, const double * alpha, const double * x, const int * incx, double * y, const int * incy);

void liftracc_cswap(const int n, void * x, const int incx, void * y, const int incy);
void liftracc_cswap_(const int * n, void * x, const int * incx, void * y, const int * incy);

void liftracc_ccopy(const int n, const void * x, const int incx, void * y, const int incy);
void liftracc_ccopy_(const int * n, const void * x, const int * incx, void * y, const int * incy);

void liftracc_caxpy(const int n, const void * alpha, const void * x, const int incx, void * y, const int incy);
void liftracc_caxpy_(const int * n, const void * alpha, const void * x, const int * incx, void * y, const int * incy);

void liftracc_zswap(const int n, void * x, const int incx, void * y, const int incy);
void liftracc_zswap_(const int * n, void * x, const int * incx, void * y, const int * incy);

void liftracc_zcopy(const int n, const void * x, const int incx, void * y, const int incy);
void liftracc_zcopy_(const int * n, const void * x, const int * incx, void * y, const int * incy);

void liftracc_zaxpy(const int n, const void * alpha, const void * x, const int incx, void * y, const int incy);
void liftracc_zaxpy_(const int * n, const void * alpha, const void * x, const int * incx, void * y, const int * incy);

void liftracc_srotg(float * a, float * b, float * c, float * s);
void liftracc_srotg_(float * a, float * b, float * c, float * s);

void liftracc_srotmg(float * d1, float * d2, float * b1, const float b2, float * p);
void liftracc_srotmg_(float * d1, float * d2, float * b1, const float * b2, float * p);

void liftracc_srot(const int n, float * x, const int incx, float * y, const int incy, const float c, const float s);
void liftracc_srot_(const int * n, float * x, const int * incx, float * y, const int * incy, const float * c, const float * s);

void liftracc_srotm(const int n, float * x, const int incx, float * y, const int incy, const float * p);
void liftracc_srotm_(const int * n, float * x, const int * incx, float * y, const int * incy, const float * p);

void liftracc_drotg(double * a, double * b, double * c, double * s);
void liftracc_drotg_(double * a, double * b, double * c, double * s);

void liftracc_drotmg(double * d1, double * d2, double * b1, const double b2, double * p);
void liftracc_drotmg_(double * d1, double * d2, double * b1, const double * b2, double * p);

void liftracc_drot(const int n, double * x, const int incx, double * y, const int incy, const double c, const double s);
void liftracc_drot_(const int * n, double * x, const int * incx, double * y, const int * incy, const double * c, const double * s);

void liftracc_drotm(const int n, double * x, const int incx, double * y, const int incy, const double * p);
void liftracc_drotm_(const int * n, double * x, const int * incx, double * y, const int * incy, const double * p);

void liftracc_sscal(const int n, const float alpha, float * x, const int incx);
void liftracc_sscal_(const int * n, const float * alpha, float * x, const int * incx);

void liftracc_dscal(const int n, const double alpha, double * x, const int incx);
void liftracc_dscal_(const int * n, const double * alpha, double * x, const int * incx);

void liftracc_cscal(const int n, const void * alpha, void * x, const int incx);
void liftracc_cscal_(const int * n, const void * alpha, void * x, const int * incx);

void liftracc_zscal(const int n, const void * alpha, void * x, const int incx);
void liftracc_zscal_(const int * n, const void * alpha, void * x, const int * incx);

void liftracc_csscal(const int n, const float alpha, void * x, const int incx);
void liftracc_csscal_(const int * n, const float * alpha, void * x, const int * incx);

void liftracc_zdscal(const int n, const double alpha, void * x, const int incx);
void liftracc_zdscal_(const int * n, const double * alpha, void * x, const int * incx);


#endif // __LIFTRACC_LEVEL1_H__


