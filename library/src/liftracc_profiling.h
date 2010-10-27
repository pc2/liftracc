/**
 * @file liftracc_profiling.h
 * @brief Header file of the profiling component
 *
 * @author Manuel Niekamp <niekma@upb.de>
 * @version 0.1
 *
 * This file defines the interface to the profiling component.
 * Profiling is used to measure timings. Functionality to start
 * and stop a time measurement is provided.
 * It is possible to save the collected data to a file.
 */

/**
 * @defgroup liftracc_prof Profiling
 * @{
 */
#ifndef __LIFTRACC_PROFILING_H__
#define __LIFTRACC_PROFILING_H__

#if _LIFTRACC_PROFILING_ > 0

#ifdef __cplusplus
extern "C" {
#endif

#include <time.h>
#include "cycle.h"

#include "liftracc_profiling_autogen.h"

#define MAX_VALUES 1024

#ifdef _LIFTRACC_MEASURE_TICKS_
/**
 * @brief Time data definition for ticks measurement
 */
typedef ticks time_data_t;
#else
/**
 * @brief Time data definition for tickless measurement
 */
typedef struct {
    struct timespec ts;
    ticks tks;
} time_data_t;
#endif /* _LIFTRACC_MEASURE_TICKS_ */

/**
 * @brief Profiling data structure
 *
 * This data structure is one entity of profiling data.
 */
typedef struct {
    time_data_t start_time; /* last start time */
    int measuring;          /* is a measure running */
/* profiling data: */
    unsigned long long count;
    time_data_t last_time;
#ifdef _LIFTRACC_MEASURE_TICKS_
    time_data_t times[MAX_VALUES];
#else
    time_data_t min_time;
    time_data_t max_time;
    time_data_t av_time;
#endif /* _LIFTRACC_MEASURE_TICKS_ */
} profiling_data_t;

/**
 * @brief Enumeration to distinguish profiling measure points
 *
 * Enumeration is used to log more than one profiling record at the same time.
 */
typedef enum {
    MEASURING_ERROR,
    MEASURING_ERROR2,
    CALL_DYNAMIC,
    CALL_DYNAMIC2,
    CALL_NORMAL,
    CALL_NORMAL2,
    LUT_INIT,
    SELECT_CALL,
    PARAM_CONV,
    ID_COUNT
} prof_id_t;

extern const char *liftracc_function_names[];
extern const char *prof_id_names[];

extern profiling_data_t liftracc_profiling_data[];

/**
 * @brief Set the start time of a measurement
 *
 * This function saves the point in time at that moment when the function is
 * called. The time value is stored in a datastructure of type
 * @ref profiling_data_t.
 */
void liftracc_function_timing_start(profiling_data_t *pd);

/**
 * @brief Calculate duration of measurement
 *
 * This function calculates the duration of a measurement. Duration is from a
 * point in time previously set by @ref liftracc_function_timing_start.
 */
void liftracc_function_timing_stop(profiling_data_t *pd);

/** @brief Add two time_data_t values and return result. */
time_data_t time_data_add(const time_data_t *a, const time_data_t *b);

/** @brief Subtract two time_data_t values and return result. */
time_data_t time_data_sub(const time_data_t *a, const time_data_t *b);

/** @brief Multiply two time_data_t values and return result. */
time_data_t time_data_mul(const time_data_t *a, const time_data_t *b);

/** @brief Divide two time_data_t values and return result. */
time_data_t time_data_div(const time_data_t *a, const time_data_t *b);

/** @brief Set time_data_t value a to the values stored in b. */
void time_data_set(time_data_t *a, const time_data_t *b);

/** @brief Set average time and store it in time_data_t a. */
void time_data_set_av(time_data_t *a, const time_data_t *b, const unsigned long long count);

/** @brief a<b return true. */
int time_data_islesser(const time_data_t *a, const time_data_t *b);

/** @brief a>b return true. */
int time_data_isgreater(const time_data_t *a, const time_data_t *b);

/**
 * @brief Print an array of profiling data to stdout.
 *
 * Print the given profiling data in formated way to stdout.
 * @param title
 *   Title to display above the printed data.
 * @param pd
 *   Array that stores the profiling data
 * @param names
 *   Meaningful names for the profiling data
 * @param count
 *   number of entries to print
 */
void print_profiling_data(const char* title, profiling_data_t *pd, const char *names[], int count);

#ifdef __cplusplus
}
#endif

#endif // _LIFTRACC_PROFILING_

#endif // __LIFTRACC_PROFILING_H__

/** @} */

