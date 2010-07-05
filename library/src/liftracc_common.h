
#ifndef __LIFTRACC_COMMON_H__
#define __LIFTRACC_COMMON_H__

#include <stddef.h>

/* types definitions */

typedef size_t liftracc_index_t;

typedef enum {
    liftracc_row_major = 101,
    liftracc_col_major = 102
} liftracc_order_t;

typedef enum {
    liftracc_no_trans   = 111,
    liftracc_trans      = 112,
    liftracc_conj_trans = 113
} liftracc_transpose_t;

typedef enum {
    liftracc_upper = 121,
    liftracc_lower = 122
} liftracc_uplo_t;

typedef enum {
    liftracc_non_unit = 131,
    liftracc_unit     = 132
} liftracc_diag_t;

typedef enum {
    liftracc_left  = 141,
    liftracc_right = 142
} liftracc_side_t;

#endif // __LIFTRACC_COMMON_H__

