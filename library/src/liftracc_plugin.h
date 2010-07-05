/**
 * \file liftracc_plugin.h
 * \brief Definitions needed by the plugins
 *
 * \author Manuel Niekamp <niekma@upb.de>
 * \version 0.1
 * \date 10/2009-03/2010
 *
 * This File defines things related to the plugins.
 * Mainly this is the plugin info structur.
 */
#ifndef __LIFTRACC_PLUGIN_H__
#define __LIFTRACC_PLUGIN_H__

#include "liftracc_selector.h"

/**
 * \brief Plugin information structur
 * This struct contains all the info to describe a
 * plugin in detail.
 */
typedef const struct {
    char *uuid;          /**< unique id generated for example by uuidgen */
    char *name;          /**< short name to identify the plugin */
    char *desc;          /**< long description with additional info */
    unsigned char prio;  /**< plugin priority 0:reserved! 1-255:from low to high */
} plugin_info_t;


/**
 * \brief Calculate the index in array.
 *
 * Inline assembler function to calculate the index in LUT.
 * As numbers to the power of two are used, this can be done
 * with the bsr instruction.
 *
 * \param probsize
 *   Get the index to this number
 * \param max
 *   To not jump behind the bounds of the array, the maximum
 *   index return is max.
 *
 * \return
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

#endif // __LIFTRACC_PLUGIN_H__

