/**
 * @file liftracc.h
 * @brief Header file of the liftracc lib.
 *
 * @author Manuel Niekamp <niekma@upb.de>
 * @version 0.1
 *
 * Main header file of the complete library.
 * Users should include this file to use
 * libliftracc.
 */

/**
 * @defgroup liftracc_init Library initialization/finalization
 * @{
 */

#ifndef __LIFTRACC_H__
#define __LIFTRACC_H__

#ifdef __cplusplus
extern "C" {
#endif

/* #include "liftracc_common.h" */
#include "liftracc_level1.h"
#include "liftracc_level2.h"
#ifdef _LIFTRACC_TESTING_
#include "liftracc_level3_testing.h"
#else
#include "liftracc_level3.h"
#endif /* _LIFTRACC_TESTING_ */

int liftracc_is_initialized(void);

/** @} */

#if _LIFTRACC_PROFILING_ > 0
int liftracc_calltest_dynamic(int a, int b, int c);
extern int liftracc_calltest_normal(int a, int b, int c);
#endif /* _LIFTRACC_PROFILING_  */

#ifdef __cplusplus
}
#endif

#endif // __LIFTRACC_H__

