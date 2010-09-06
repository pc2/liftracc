
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <math.h>
#ifndef __USE_GNU
#define __USE_GNU
#endif
#include <dlfcn.h>

#include <sched.h>

#include "liftracc.h"
#include "liftracc_logging.h"
#include "liftracc_profiling.h"
extern "C" {
#include "cblas.h"
}

int main(int argc, char** argv)
{
    /*printf("start in main\n");*/
    /*
    pid_t pid = getpid();
    struct sched_param sparam;
    if (sched_getparam(pid, &sparam) > -1) {
        sparam.sched_priority = sched_get_priority_max(SCHED_FIFO);
        if (sched_setscheduler(pid, SCHED_FIFO, &sparam) == 0) {
            printf("Scheduler set to FIFO!\n");
            sleep(1);
        } else
            printf("Scheduler not set!\n");
    } else
        printf("Scheduler not set!\n");
    */
#if _LIFTRACC_PROFILING_ > 0
    /*unsigned long long s1, s2;*/
    for (int i=0; i<1000; i++) {
        /*s1 = getticks();
        s2 = getticks();
        printf("%d NEW: %llu\n", i, s2-s1);*/
        liftracc_function_timing_start(&(liftracc_profiling_data[MEASURING_ERROR2]));
        liftracc_function_timing_start(&(liftracc_profiling_data[MEASURING_ERROR]));
        liftracc_function_timing_stop(&(liftracc_profiling_data[MEASURING_ERROR]));
        liftracc_function_timing_stop(&(liftracc_profiling_data[MEASURING_ERROR2]));
    }
#endif /* _LIFTRACC_PROFILING_  */
    unsigned int error_count = 0;

    double *double_x = (double*) malloc( sizeof(double) * 8192 );
    double *double_y = (double*) malloc( sizeof(double) * 8192 );

    float *float_x = (float*) malloc( sizeof(float) * 8192 );
    float *float_y = (float*) malloc( sizeof(float) * 8192 );

    //double double_alpha = 7.2;
    float float_alpha = 7.2;

    double double_liftracc_ret = 0;
    double double_cblas_ret = 0;
    
    float float_liftracc_ret = 0;
    float float_cblas_ret = 0;

    srand(time(0));

    int i, p;
    
    for (i=0;i<8192;i++) double_x[i] = (double)(rand()%500/100.0);
    for (i=0;i<8192;i++) double_y[i] = (double)(rand()%500/100.0);
    for (i=0;i<8192;i++) float_x[i] = (float)(rand()%500/100.0);
    for (i=0;i<8192;i++) float_y[i] = (float)(rand()%500/100.0);
    
    // init libraries

    if (!liftracc_is_initialized()) {
        ERROR("libliftracc is not initialized!");

        free(double_x);
        free(double_y);
        free(float_x);
        free(float_y);

        return -1;
    }

    void *cblas_handle = 0;
    char *error = 0;

    cblas_handle = dlopen("libcblas.so", RTLD_LAZY);

    if (!cblas_handle)
        ERROR("%s", dlerror());

    if (cblas_handle) INFO("lib init ok.");

#if _LIFTRACC_PROFILING_ == 1
    // function overhead test
    for (i=1;i<1001;i++) {
        liftracc_function_timing_start(&(liftracc_profiling_data[CALL_DYNAMIC]));
        int ret = liftracc_calltest_dynamic(1, 2, 3);
        MSG("RET: %d", ret);
    }
    for (i=1;i<1001;i++) {
        liftracc_function_timing_start(&(liftracc_profiling_data[CALL_NORMAL]));
        int ret = liftracc_calltest_normal(1, 2, 3);
        MSG("RET: %d", ret);
    }
#endif /* _LIFTRACC_PROFILING_  */

    // function init
    float (*cblas_sdsdot)(const int n, const float alpha, const float * x, const int incx, const float * y, const int incy);
    *(void **) (&cblas_sdsdot) = dlsym(cblas_handle, "inner_cblas_sdsdot");

    if ((error = dlerror()) != 0)  {
        ERROR("%s", error);
    }

    // function test
    for (i=1;i<101;i++) {
        p = (int)pow(2,i);
        p = 10;
        float_liftracc_ret = liftracc_sdsdot(p,float_alpha,float_x,1,float_y,1);
        float_cblas_ret = (*cblas_sdsdot)(p,float_alpha,float_x,1,float_y,1);

        float_liftracc_ret = round(float_liftracc_ret*10000)/10000;
        float_cblas_ret = round(float_cblas_ret*10000)/10000;

        if (float_liftracc_ret != float_cblas_ret) printf("ERROR\n");
        printf("liftracc_sdsdot = %f\n", float_liftracc_ret);
        printf("cblas_sdsdot   = %f\n\n", float_cblas_ret);

        if (float_liftracc_ret != float_cblas_ret) error_count++;
    }

    // function init
    double (*cblas_dsdot)(const int n, const float * x, const int incx, const float * y, const int incy);
    *(void **) (&cblas_dsdot) = dlsym(cblas_handle, "inner_cblas_dsdot");

    if ((error = dlerror()) != 0)  {
        ERROR("%s", error);
    }

    // function test
    for (i=1;i<101;i++) {
        p = (int)pow(2,i);
        p = 10;
        double_liftracc_ret = liftracc_dsdot(p,float_x,1,float_y,1);
        double_cblas_ret = (*cblas_dsdot)(p,float_x,1,float_y,1);

        double_liftracc_ret = round(double_liftracc_ret*10000)/10000;
        double_cblas_ret = round(double_cblas_ret*10000)/10000;

        if (double_liftracc_ret != double_cblas_ret) printf("ERROR\n");
        printf("liftracc_dsdot = %f\n", double_liftracc_ret);
        printf("cblas_dsdot   = %f\n\n", double_cblas_ret);

        if (double_liftracc_ret != double_cblas_ret) error_count++;
    }
    
    // function init
    float (*cblas_sdot)(const int n, const float * x, const int incx, const float * y, const int incy);
    *(void **) (&cblas_sdot) = dlsym(cblas_handle, "inner_cblas_sdot");

    if ((error = dlerror()) != 0)  {
        ERROR("%s", error);
    }

    // function test
    for (i=1;i<101;i++) {
        p = (int)pow(2,i);
        p = 10;
        float_liftracc_ret = liftracc_sdot(p,float_x,1,float_y,1);
        float_cblas_ret = (*cblas_sdot)(p,float_x,1,float_y,1);
        
        float_liftracc_ret = round(float_liftracc_ret*10000)/10000;
        float_cblas_ret = round(float_cblas_ret*10000)/10000;

        if (float_liftracc_ret != float_cblas_ret) printf("ERROR\n");
        printf("liftracc_sdot = %f\n", float_liftracc_ret);
        printf("cblas_sdot   = %f\n\n", float_cblas_ret);

        if (float_liftracc_ret != float_cblas_ret) error_count++;
    }

    // function init
    double (*cblas_ddot)(const int n, const double * x, const int incx, const double * y, const int incy);
    *(void **) (&cblas_ddot) = dlsym(cblas_handle, "inner_cblas_ddot");

    if ((error = dlerror()) != 0)  {
        ERROR("%s", error);
    }

    // function test
    for (i=1;i<101;i++) {
        p = (int)pow(2,i);
        p = 10;
#if _LIFTRACC_PROFILING_ == 10
        liftracc_function_timing_start(&(liftracc_profiling_data[CALL_DYNAMIC2]));
#endif /* _LIFTRACC_PROFILING_ */
        double_liftracc_ret = liftracc_ddot(p,double_x,1,double_y,1);
#if _LIFTRACC_PROFILING_ == 10
        liftracc_function_timing_stop(&(liftracc_profiling_data[CALL_DYNAMIC2]));
#endif /* _LIFTRACC_PROFILING_ */

#if _LIFTRACC_PROFILING_ == 10
        liftracc_function_timing_start(&(liftracc_profiling_data[CALL_NORMAL2]));
#endif /* _LIFTRACC_PROFILING_ */
        double_cblas_ret = (*cblas_ddot)(p,double_x,1,double_y,1);
#if _LIFTRACC_PROFILING_ == 10
        liftracc_function_timing_stop(&(liftracc_profiling_data[CALL_NORMAL2]));
#endif /* _LIFTRACC_PROFILING_ */
        double_liftracc_ret = round(double_liftracc_ret*10000)/10000;
        double_cblas_ret = round(double_cblas_ret*10000)/10000;

        if (double_liftracc_ret != double_cblas_ret) printf("ERROR\n");
        printf("liftracc_ddot = %f\n", double_liftracc_ret);
        printf("cblas_ddot   = %f\n\n", double_cblas_ret);

        if (double_liftracc_ret != double_cblas_ret) error_count++;
    }

    if (cblas_handle) dlclose(cblas_handle);
    cblas_handle = 0;

    free(double_x);
    free(double_y);
    free(float_x);
    free(float_y);

#if _LIFTRACC_PROFILING_ > 0
    print_profiling_data("overheads", &(liftracc_profiling_data[0]), prof_id_names, ID_COUNT);
#endif /* _LIFTRACC_PROFILING_ */
    return error_count;
}

