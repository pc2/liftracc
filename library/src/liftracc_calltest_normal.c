
#if _LIFTRACC_PROFILING_ == 1

#include "liftracc_profiling.h"
#include "liftracc_logging.h"

#include <stdlib.h>

/**
 * Only used to measure the time a normal dynamic call
 * costs. This function is useless in any other manner.
 */
int liftracc_calltest_normal(int a, int b, int c)
{
    liftracc_function_timing_stop(&(liftracc_profiling_data[CALL_NORMAL]));
    /* INFO("liftracc_calltest_normal"); */
    return rand()-a*b+c;
}

#endif /* _LIFTRACC_PROFILING_  */

