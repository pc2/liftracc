/**
 * @file liftracc_plugin.h
 * @brief Definitions needed by the plugins
 *
 * @author Manuel Niekamp <niekma@upb.de>
 * @version 0.1
 *
 * This File defines things related to the plugins.
 * Mainly this is the plugin info structur.
 */

/**
 * @defgroup liftracc_plugin Plugins
 * @{
 */

#ifndef __LIFTRACC_PLUGIN_H__
#define __LIFTRACC_PLUGIN_H__

#include "liftracc_selector.h"
#include "liftracc_logging.h"

#if _LIFTRACC_PROFILING_ > 0
#include "liftracc_profiling.h"
#endif

/**
 * @brief Plugin information structur
 *
 * This struct contains all the info to describe a
 * plugin in detail.
 */
typedef const struct {
    char *uuid;          /**< unique id generated for example by uuidgen */
    char *name;          /**< short name to identify the plugin */
    char *desc;          /**< long description with additional info */
    unsigned char prio;  /**< plugin priority 0:reserved! 1-255:from low to high */
} plugin_info_t;

/** @} */

/**
 * @addtogroup liftracc_select
 * @{
 */

/**
 * @brief Calculate the index in array.
 *
 * Inline assembler function to calculate the index in LUT.
 * As numbers to the power of two are used, this can be done
 * with the bsr instruction.
 *
 * @param probsize
 *   Get the index to this number
 * @param max
 *   To not jump behind the bounds of the array, the maximum
 *   index return is max.
 *
 * @return
 *   The index to use in LUT array
 */
static __inline__ unsigned int get_inx(unsigned int probsize, unsigned int max) {
    unsigned int ret = 0;
    __asm__ __volatile__ (          /* "Op-code src dst" AT&T syntax !!! */
        "bsr %1, %0;"               /* get left most 1 in bit field      */
        "cmp %2, %0;"               /* compare to max (%0-%2)            */
        "jb 0f;"                    /* jump if below ((%0-%2)<0)         */
        "mov %2, %0;"               /* else set output to max            */
        "0:"
        : "+r" (ret)                /* outputs */
        : "r" (probsize), "r" (max) /* inputs  */
    );
    return (unsigned int) ret;
}

/** @} */

/**
 * @addtogroup liftracc_plugin
 * @{
 */

#ifdef _LIFTRACC_AUTOMODE_TRAINING_
void set_decision_data(int success,
                       decision_data_t *data,
                       profiling_data_t *func_data,
                       int value,
                       int func_id,
                       int select_id)
{
    decision_data_t new_value = func_data[func_id].last_time;
    decision_data_t old_value = data[select_id*ARRAY_SIZE+get_inx(value, ARRAY_SIZE)];
    if (old_value == 0) old_value = new_value;
    data[select_id*ARRAY_SIZE+get_inx(value, ARRAY_SIZE)] = (new_value+old_value)/2;
    if (!success || new_value == 0) data[select_id*ARRAY_SIZE+get_inx(value, ARRAY_SIZE)] = 0 - 1;
    ERROR("set_decision_data(%d, %d, %d) = (%llu+%llu)/2", value, func_id, select_id, new_value, old_value);
}
#endif /* _LIFTRACC_AUTOMODE_TRAINING_ */

#endif // __LIFTRACC_PLUGIN_H__

/** @} */

