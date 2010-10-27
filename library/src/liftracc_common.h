
/**
 * @file liftracc_common.h
 * @brief Some common used type definitions.
 *
 * This file is used to define some common types. The values set are the same
 * as they are in the cblas definition.
 */

#ifndef __LIFTRACC_COMMON_H__
#define __LIFTRACC_COMMON_H__

#include <stddef.h>

/* types definitions */

/**
 * @brief The liftracc size type
 */
typedef size_t liftracc_index_t;

/**
 * @brief The liftracc order type.
 *
 * Select between row major and column major order. Memory layout of matrices
 * is handled through function parameters of this type.
 */
typedef enum {
    liftracc_row_major = 101,
    liftracc_col_major = 102
} liftracc_order_t;

/**
 * @brief Represent transposition feature of matrices
 */
typedef enum {
    liftracc_no_trans   = 111,
    liftracc_trans      = 112,
    liftracc_conj_trans = 113
} liftracc_transpose_t;

/**
 * @brief Type to distinguish between upper or lower triangular matrices
 */
typedef enum {
    liftracc_upper = 121,
    liftracc_lower = 122
} liftracc_uplo_t;

/**
 * @brief Distinguish between unitary and non unitary matrices
 */
typedef enum {
    liftracc_non_unit = 131,
    liftracc_unit     = 132
} liftracc_diag_t;

/**
 * @brief Distinguish between left and right side matrices
 */
typedef enum {
    liftracc_left  = 141,
    liftracc_right = 142
} liftracc_side_t;

#endif // __LIFTRACC_COMMON_H__

