/**
 * \file liftracc_profiling.h
 * \brief Header file of the profiling component
 *
 * \author Manuel Niekamp <niekma@upb.de>
 * \version 0.1
 * \date 10/2009-03/2010
 *
 * This file defines the interface to the profiling component.
 * Profiling is used to measure timings. Functionality to start
 * and stop a time measurement is provided.
 * It is possible to save the collected data to a file.
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
typedef ticks time_data_t;
#else
typedef struct {
    struct timespec ts;
    ticks tks;
} time_data_t;
#endif /* _LIFTRACC_MEASURE_TICKS_ */

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

void liftracc_function_timing_start(profiling_data_t *pd);
void liftracc_function_timing_stop(profiling_data_t *pd);

time_data_t time_data_add(const time_data_t *a, const time_data_t *b);
time_data_t time_data_sub(const time_data_t *a, const time_data_t *b);
time_data_t time_data_mul(const time_data_t *a, const time_data_t *b);
time_data_t time_data_div(const time_data_t *a, const time_data_t *b);

void time_data_set(time_data_t *a, const time_data_t *b);
void time_data_set_av(time_data_t *a, const time_data_t *b, const unsigned long long count);

int time_data_islesser(const time_data_t *a, const time_data_t *b);
int time_data_isgreater(const time_data_t *a, const time_data_t *b);

void print_profiling_data(const char* title, profiling_data_t *pd, const char *names[], int count);

#ifdef __cplusplus
}
#endif

#endif // _LIFTRACC_PROFILING_

#endif // __LIFTRACC_PROFILING_H__

