/** 
 * @file liftracc_selector.h
 * @brief Header file of the selector module
 *
 * @author Manuel Niekamp <niekma@upb.de>
 * @version 0.1
 *
 * This file defines the interface to the selector component.
 * The selector is used inside the wrapper library to select
 * the best function out of a function pool. The functions
 * selected match the calling one from the wrapper library.
 */

/**
 * @defgroup liftracc_select Selector Component
 * @{
 */

#ifndef __LIFTRACC_SELECTOR_H__
#define __LIFTRACC_SELECTOR_H__

#include "cycle.h"

#define ARRAY_SIZE 15 /* 2^14 problem size should be supported */

#ifdef _LIFTRACC_AUTOMODE_
/** in auto mode ticks are used to find the fastest function */
typedef ticks decision_data_t;
#else
/** if in prio mode prios go from 1-255 */
typedef unsigned char decision_data_t;
#endif /* _LIFTRACC_AUTOMODE_ */

/**
 * @brief Enumeration of error states.
 *
 * This enum covers all possible error states the
 * selector can get in.
 */
typedef enum {
    NO_ERROR,
    NO_LIBS_FOUND_ERROR,
    LIBS_OPEN_ERROR,
    LIBS_CLOSE_ERROR,
    FUNCTION_NOT_FOUND_ERROR,
    FILE_NOT_FOUND_ERROR,
    DATA_READ_ERROR,
    DATA_WRITE_ERROR
} liftracc_selector_error_t;

/**
 * @brief Enumeration of selector function ids.
 *
 * There is an id to every blas function supported.
 * One of these ids is passed to the selector in order
 * to decide which function should be selected.
 * (candidate for autogen!)
 */
typedef enum {
    SELECT_SDSDOT,
    SELECT_DSDOT,
    SELECT_SDOT,
    SELECT_DDOT,
    SELECT_CDOTU_SUB,
    SELECT_CDOTC_SUB,
    SELECT_ZDOTU_SUB,
    SELECT_ZDOTC_SUB,
    SELECT_SNRM2,
    SELECT_SASUM,
    SELECT_DNRM2,
    SELECT_DASUM,
    SELECT_SCNRM2,
    SELECT_SCASUM,
    SELECT_DZNRM2,
    SELECT_DZASUM,
    SELECT_ISAMAX,
    SELECT_IDAMAX,
    SELECT_ICAMAX,
    SELECT_IZAMAX,
    SELECT_SSWAP,
    SELECT_SCOPY,
    SELECT_SAXPY,
    SELECT_DSWAP,
    SELECT_DCOPY,
    SELECT_DAXPY,
    SELECT_CSWAP,
    SELECT_CCOPY,
    SELECT_CAXPY,
    SELECT_ZSWAP,
    SELECT_ZCOPY,
    SELECT_ZAXPY,
    SELECT_SROTG,
    SELECT_SROTMG,
    SELECT_SROT,
    SELECT_SROTM,
    SELECT_DROTG,
    SELECT_DROTMG,
    SELECT_DROT,
    SELECT_DROTM,
    SELECT_SSCAL,
    SELECT_DSCAL,
    SELECT_CSCAL,
    SELECT_ZSCAL,
    SELECT_CSSCAL,
    SELECT_ZDSCAL,
    SELECT_SGEMV,
    SELECT_SGBMV,
    SELECT_STRMV,
    SELECT_STBMV,
    SELECT_STPMV,
    SELECT_STRSV,
    SELECT_STBSV,
    SELECT_STPSV,
    SELECT_DGEMV,
    SELECT_DGBMV,
    SELECT_DTRMV,
    SELECT_DTBMV,
    SELECT_DTPMV,
    SELECT_DTRSV,
    SELECT_DTBSV,
    SELECT_DTPSV,
    SELECT_CGEMV,
    SELECT_CGBMV,
    SELECT_CTRMV,
    SELECT_CTBMV,
    SELECT_CTPMV,
    SELECT_CTRSV,
    SELECT_CTBSV,
    SELECT_CTPSV,
    SELECT_ZGEMV,
    SELECT_ZGBMV,
    SELECT_ZTRMV,
    SELECT_ZTBMV,
    SELECT_ZTPMV,
    SELECT_ZTRSV,
    SELECT_ZTBSV,
    SELECT_ZTPSV,
    SELECT_SSYMV,
    SELECT_SSBMV,
    SELECT_SSPMV,
    SELECT_SGER,
    SELECT_SSYR,
    SELECT_SSPR,
    SELECT_SSYR2,
    SELECT_SSPR2,
    SELECT_DSYMV,
    SELECT_DSBMV,
    SELECT_DSPMV,
    SELECT_DGER,
    SELECT_DSYR,
    SELECT_DSPR,
    SELECT_DSYR2,
    SELECT_DSPR2,
    SELECT_CHEMV,
    SELECT_CHBMV,
    SELECT_CHPMV,
    SELECT_CGERU,
    SELECT_CGERC,
    SELECT_CHER,
    SELECT_CHPR,
    SELECT_CHER2,
    SELECT_CHPR2,
    SELECT_ZHEMV,
    SELECT_ZHBMV,
    SELECT_ZHPMV,
    SELECT_ZGERU,
    SELECT_ZGERC,
    SELECT_ZHER,
    SELECT_ZHPR,
    SELECT_ZHER2,
    SELECT_ZHPR2,
    SELECT_SGEMM,
    SELECT_SSYMM,
    SELECT_SSYRK,
    SELECT_SSYR2K,
    SELECT_STRMM,
    SELECT_STRSM,
    SELECT_DGEMM,
    SELECT_DSYMM,
    SELECT_DSYRK,
    SELECT_DSYR2K,
    SELECT_DTRMM,
    SELECT_DTRSM,
    SELECT_CGEMM,
    SELECT_CSYMM,
    SELECT_CSYRK,
    SELECT_CSYR2K,
    SELECT_CTRMM,
    SELECT_CTRSM,
    SELECT_ZGEMM,
    SELECT_ZSYMM,
    SELECT_ZSYRK,
    SELECT_ZSYR2K,
    SELECT_ZTRMM,
    SELECT_ZTRSM,
    SELECT_CHEMM,
    SELECT_CHERK,
    SELECT_CHER2K,
    SELECT_ZHEMM,
    SELECT_ZHERK,
    SELECT_ZHER2K,
    SELECT_XERBLA,
    CALLTEST_DYNAMIC,
    FUNCTION_COUNT
} liftracc_selector_funcid_t;

/**
 * @brief Struct to describe the problem.
 *
 * At the moment this is only one integer value. This struct is
 * used by the selector to find the best function.
 * Currently the matrix or vector dimension is saved in info1.
 */
typedef struct {
    int info1;
} liftracc_selector_problem_info_t;

/* maybe the library path is needed somewere outside */
extern char liftracc_library_path[];

/* the function names are needed to write proper log infos.
   array can be found in liftracc_selector_autogen.c */
extern const char *liftracc_selector_funcnames[];

/**
 * @brief Selector component init function.
 *
 * All init stuff is done here. This includes loading the
 * plugins and generating the look up table.
 *
 * @return
 *   Error state or NO_ERROR
 */
liftracc_selector_error_t liftracc_selector_init();

/**
 * @brief Selector component finalize function.
 *
 * Clean up is done here.
 *
 * @return
 *   Error state or NO_ERROR
 */
liftracc_selector_error_t liftracc_selector_fini();

#ifdef _LIFTRACC_SELECTOR_NEW_

/**
 * @brief Selects function pointer to use from LUT
 *
 * This function selects the function pointer that is stored in
 * the LUT. The returned function pointer depends on the given
 * parameter.
 *
 * @param func_id
 *   Indentifies the function that should be returned.
 * @param problem_info
 *   Decision data that is used to select the best
 *   function fron the sublibraries.
 *
 * @return
 *   The selected function pointer
 *
 * @todo
 *   More and different versions of the selector mechanism should be
 *   implemented.
 */
void *liftracc_selector_select(const liftracc_selector_funcid_t func_id,
                               const liftracc_selector_problem_info_t *problem_info);

#else /* _LIFTRACC_SELECTOR_NEW_ */

/**
 * @brief Select function pointer to use in LUT
 *
 * This function selects a function pointer. It is one of
 * the function pointers available in one of the sublibraries.
 * The selection is based on a per library priority.
 *
 * @param symbol_name
 *   Symbol name of function that should be selected.
 *
 * @return
 *   The selected function pointer
 */
void *liftracc_selector_select(const char *symbol_name);

#endif /* _LIFTRACC_SELECTOR_NEW_ */

/**
 * @brief Load decision info's from file
 *
 * This method loads the array containing infos used by the selector
 * to decide with function is the fastest an should therefor be used
 * as entry in the function pointer LUT.
 *
 * @param file_name
 *   Name of file to load data from
 * @param array
 *   Pointer to array to store data into
 *
 * @return
 *   liftracc selector error code
 */
liftracc_selector_error_t liftracc_selector_loadinfo(const char *file_name, 
                                                     decision_data_t *array);

#ifdef _LIFTRACC_AUTOMODE_

/**
 * @brief Save decision info's to file
 *
 * This method saves the array containing infos used by the selector
 * to decide with function is the fastest an should therefor be used
 * as entry in the function pointer LUT.
 *
 * @param file_name
 *   Name of file to save data to
 * @param array
 *   Pointer to array that contains the data
 *
 * @return
 *   liftracc selector error code
 */
liftracc_selector_error_t liftracc_selector_saveinfo(const char *file_name,
                                                     decision_data_t *array);

#endif /* _LIFTRACC_AUTOMODE_ */

#endif // __LIFTRACC_SELECTOR_H__

/** @} */

