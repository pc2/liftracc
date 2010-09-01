/**
 * \file liftracc_profiling_tks.c
 * \brief C file of the profiling component (ticks version)
 *
 * \author Manuel Niekamp <niekma@upb.de>
 * \version 0.1
 * \date 10/2009-03/2010
 *
 * This file implements the profiling component. The version
 * using ticks to measure time.
 * Profiling is used to measure timings. Functionality to start
 * and stop a time measurement is provided.
 * It is possible to save the collected data to a file.
 */
#ifdef _LIFTRACC_PROFILING_

#include <stdio.h>

#include "liftracc_logging.h"
#include "liftracc_profiling.h"

const char *prof_id_names[] = {
    "measuring_error",
    "measuring_error2",
    "call_dynamic",
    "call_dynamic2",
    "call_normal",
    "call_normal2",
    "lut_init",
    "select_call",
    "param_conv",
    "size_entry"
};

profiling_data_t liftracc_profiling_data[ID_COUNT] = {};

time_data_t tmp_time;

void liftracc_function_timing_start(profiling_data_t *pd)
{
    if (pd->measuring) {
        ERROR("Another Measurement is already running for this ID!");
        return;
    }
    pd->measuring = 1;
    if (pd->count < MAX_VALUES-1) pd->count++;
    pd->start_time = getticks(); /* start point of measurment */
}

void liftracc_function_timing_stop(profiling_data_t *pd)
{
    tmp_time = getticks() - pd->start_time; /* stop point of measurment */

    if (!pd->measuring) {
        ERROR("No Measurement running for this ID!");
        return;
    }
    pd->measuring = 0;

    pd->times[pd->count] = tmp_time;
    pd->last_time = tmp_time;
}

void print_profiling_data(const char* title, profiling_data_t *pd, const char *names[], int count)
{
    char file_name[50];
    sprintf(file_name, "tks_%s.log", title);

    FILE *log = fopen(file_name, "a+");
    /*printf("[P] ### %s ###\n", title);
    printf("[P] Name   Count   Min-Time   Max-Time   Av-Time   [ticks]\n");*/
    int c;
    for (c=0; c<count; c++) {
      if (pd[c].count) {
        int z;
        if (!names) {
            /*printf("[P] %d %d   ", c, z);*/
            if (log!=0) fprintf(log, "%d %llu", c, pd[c].count);
        } else {
            /*printf("[P] %s_%s   ", title, names[c]);*/
            if (log!=0) fprintf(log, "%s_%s %llu", title, names[c], pd[c].count);
        }
        for (z=1; z<=pd[c].count; z++) {
            /*printf("%llu", pd[c].times[z]);*/
            if (log!=0) fprintf(log, " %llu", pd[c].times[z]);
        }
        /*printf("\n");*/
        if (log!=0) fprintf(log, "\n");
      }
    }
    if (log!=0) {
        fclose(log);
    }
}

#endif // _LIFTRACC_PROFILING_

