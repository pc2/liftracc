/**
 * \file liftracc_profiling.c
 * \brief C file of the profiling component
 *
 * \author Manuel Niekamp <niekma@upb.de>
 * \version 0.1
 * \date 10/2009-03/2010
 *
 * This file implements the profiling component.
 * Profiling is used to measure timings. Functionality to start
 * and stop a time measurement is provided.
 * It is possible to save the collected data to a file.
 */
#ifdef _LIFTRACC_PROFILING_ > 0

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
    pd->count++;
    clock_gettime(CLOCK_MONOTONIC, &(pd->start_time.ts)); /* start point of measurment */
    pd->start_time.tks = getticks();
}

void liftracc_function_timing_stop(profiling_data_t *pd)
{
    clock_gettime(CLOCK_MONOTONIC, &(tmp_time.ts)); /* stop point of measurment */
    tmp_time.tks = getticks();

    if (!pd->measuring) {
        ERROR("No Measurement running for this ID!");
        return;
    }
    pd->measuring = 0;

    time_data_t delta_time;
    delta_time = time_data_sub(&tmp_time, &(pd->start_time));
    time_data_set(&(pd->last_time), &delta_time);

    if (pd->av_time.tks == 0 || time_data_islesser(&delta_time, &(pd->min_time))) {
        time_data_set(&(pd->min_time), &delta_time);
    }
    if (time_data_isgreater(&delta_time, &(pd->max_time))) {
        time_data_set(&(pd->max_time), &delta_time);
    }
    time_data_set_av(&(pd->av_time), &delta_time, pd->count);
}

time_data_t time_data_add(const time_data_t *a, const time_data_t *b)
{
    time_data_t tmp = {};

    tmp.ts.tv_sec = a->ts.tv_sec + b->ts.tv_sec;
    tmp.ts.tv_nsec = a->ts.tv_nsec + b->ts.tv_nsec;
    tmp.tks = a->tks + b->tks;

    return tmp;
}

time_data_t time_data_sub(const time_data_t *a, const time_data_t *b)
{
    time_data_t tmp = {};

    tmp.ts.tv_sec = a->ts.tv_sec - b->ts.tv_sec;
    tmp.ts.tv_nsec = a->ts.tv_nsec - b->ts.tv_nsec;
    if (tmp.ts.tv_nsec<0) {
        tmp.ts.tv_nsec = tmp.ts.tv_nsec+1000000000L;
        tmp.ts.tv_sec = tmp.ts.tv_sec-1;
    }
    tmp.tks = a->tks - b->tks;

    return tmp;
}

time_data_t time_data_mul(const time_data_t *a, const time_data_t *b)
{
    time_data_t tmp = {};

    tmp.ts.tv_sec = a->ts.tv_sec * b->ts.tv_sec;
    tmp.ts.tv_nsec = a->ts.tv_nsec * b->ts.tv_nsec;
    tmp.tks = a->tks * b->tks;

    return tmp;
}

time_data_t time_data_div(const time_data_t *a, const time_data_t *b)
{
    time_data_t tmp = {};

    tmp.ts.tv_sec = a->ts.tv_sec / b->ts.tv_sec;
    tmp.ts.tv_nsec = a->ts.tv_nsec / b->ts.tv_nsec;
    tmp.tks = a->tks / b->tks;

    return tmp;
}

void time_data_set(time_data_t *a, const time_data_t *b)
{
    a->ts.tv_sec = b->ts.tv_sec;
    a->ts.tv_nsec = b->ts.tv_nsec;
    a->tks = b->tks;
}

void time_data_set_av(time_data_t *a, const time_data_t *b, unsigned long long count)
{
    a->ts.tv_sec = (a->ts.tv_sec * (count-1) + b->ts.tv_sec) / count;
    a->ts.tv_nsec = (a->ts.tv_nsec * (count-1) + b->ts.tv_nsec) / count;
    a->tks = (a->tks * (count-1) + b->tks) / count;
}

int time_data_islesser(const time_data_t *a, const time_data_t *b)
{
    if ((a->ts.tv_sec <= b->ts.tv_sec) && (a->ts.tv_nsec < b->ts.tv_nsec))
        return 1;
    
    return 0;
}

int time_data_isgreater(const time_data_t *a, const time_data_t *b)
{
    if ((a->ts.tv_sec >= b->ts.tv_sec) && (a->ts.tv_nsec > b->ts.tv_nsec))
        return 1;

    return 0;
}


void print_profiling_data(const char* title, profiling_data_t *pd, const char *names[], int count)
{
    time_t rawtime;
    struct tm *ti;

    time(&rawtime);
    ti = localtime(&rawtime);

    char file_name[50];
    sprintf(file_name, "profiling_%04d%02d%02d%02d%02d%02d.log",
                       1900+ti->tm_year,
                       ti->tm_mon,
                       ti->tm_mday,
                       ti->tm_hour,
                       ti->tm_min,
                       ti->tm_sec);

    FILE *log = fopen(file_name, "a+");
    printf("\n\n[P] ### %s ###\n", title);
    if (log!=0) fprintf(log, "\n\n### %s ###\n", title);
    printf("[P]              Name  Count, Min-Time, Max-Time, Av-Time. (Time: sec[nsec](ticks))\n");
    if (log!=0) fprintf(log, "Name Count Min-Time Max-Time Av-Time (Time: sec nsec ticks)\n");
    int c;
    for (c=0; c<count; c++) {
      if (pd[c].count) {
        if (!names) {
            printf("[P]%18d  ", c);
            if (log!=0) fprintf(log, "%d ", c);
        } else {
            printf("[P]%18s  ", names[c]);
            if (log!=0) fprintf(log, "%s%s ", title, names[c]);
        }
        printf("%llu, %ld[%ld](%llu), %ld[%ld](%llu), %ld[%ld](%llu)\n",
               pd[c].count,
               (long)pd[c].min_time.ts.tv_sec,
               pd[c].min_time.ts.tv_nsec,
               pd[c].min_time.tks,
               (long)pd[c].max_time.ts.tv_sec,
               pd[c].max_time.ts.tv_nsec,
               pd[c].max_time.tks,
               (long)pd[c].av_time.ts.tv_sec,
               pd[c].av_time.ts.tv_nsec,
               pd[c].av_time.tks
        );
        if (log!=0) fprintf(log, "%llu %ld %ld %llu %ld %ld %llu %ld %ld %llu\n",
                            pd[c].count,
                            (long)pd[c].min_time.ts.tv_sec,
                            pd[c].min_time.ts.tv_nsec,
                            pd[c].min_time.tks,
                            (long)pd[c].max_time.ts.tv_sec,
                            pd[c].max_time.ts.tv_nsec,
                            pd[c].max_time.tks,
                            (long)pd[c].av_time.ts.tv_sec,
                            pd[c].av_time.ts.tv_nsec,
                            pd[c].av_time.tks
                    );
      }
    }
    printf("\n\n");
    if (log!=0) {
        fprintf(log, "\n\n");
        fclose(log);
    }

}

/*
void print_profiling_data(const char* title, profiling_data_t *pd, const char *names[], int count)
{
    printf("\n\n ### %s ###\n", title);
    printf("              Name  Count, Min-Time, Max-Time, Av-Time. (Time: sec (ticks))\n");
    int c;
    for (c=0; c<count; c++) {
      if (pd[c].count)  
        printf("%18s  %llu, %Lf (%llu), %Lf (%llu), %Lf (%llu)\n",
            names[c],
            pd[c].count,
            (long double)pd[c].min_time.ts.tv_sec + (pd[c].min_time.ts.tv_nsec/10.0E9L),
            pd[c].min_time.tks,
            (long double)pd[c].max_time.ts.tv_sec + (pd[c].max_time.ts.tv_nsec/10.0E9L),
            pd[c].max_time.tks,
            (long double)pd[c].av_time.ts.tv_sec + (pd[c].av_time.ts.tv_nsec/10.0E9L),
            pd[c].av_time.tks
        );
    }
    printf("\n\n");
}
*/
#endif // _LIFTRACC_PROFILING_

