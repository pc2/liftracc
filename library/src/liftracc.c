/**
 * \file liftracc.c
 * \brief C file of the liftracc lib
 *
 * \author Manuel Niekamp <niekma@upb.de>
 * \version 0.1
 * \date Oct. 2009 - Mar. 2010
 *
 * This file contains the constructor and destructor
 * function. Some general functions are defined too.
 */
#include "liftracc.h"
#include "liftracc_logging.h"

#include "liftracc_selector.h"

#ifdef _LIFTRACC_PROFILING_
#include "liftracc_profiling.h"
profiling_data_t liftracc_function_profiling_data[LIFTRACC_FUNCTIONS_COUNT] = {};
#endif // _LIFTRACC_PROFILING_

/**
 * \brief Global init flag.
 * This variable is set to >0 if the library is initialized
 * correctly.
 */
int liftracc_initialized = 0;

/***
 * \brief The library constructor
 * This function is called automatically when the library
 * is loaded by the dynamic loader.
 */
void __attribute__ ((constructor)) liftracc_init(void)
{
#if _LIFTRACC_PROFILING_ > 0
    INFO("Library in profiling mode.");
#endif
#ifdef _LIFTRACC_AUTOMODE_
    INFO("Library in auto mode.");
#endif
#ifdef _LIFTRACC_TRAININGMODE_
    INFO("Library in training mode.");
#endif
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_INIT]));
#endif /* _LIFTRACC_PROFILING_ */
    
    /* init the selector */
    if (liftracc_selector_init()!=NO_ERROR)
        ERROR("liftracc_selector_init() error!");
    else
        liftracc_initialized = 1;
    INFO("libliftracc loaded.");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_INIT]));
#endif /* _LIFTRACC_PROFILING_ */
}

/**
 * \brief The library destructor
 * This function is called at the time the library is unloaded.
 */
void __attribute__ ((destructor)) liftracc_fini(void)
{
#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_start(&(liftracc_function_profiling_data[LIFTRACC_FINI]));
#endif /* _LIFTRACC_PROFILING_ */
    
    /* finialize the selector */
    if (liftracc_selector_fini()!=NO_ERROR)
        ERROR("liftracc_selector_fini() error!");
    
    INFO("libliftracc unloaded.");

#if _LIFTRACC_PROFILING_ == 1
    liftracc_function_timing_stop(&(liftracc_function_profiling_data[LIFTRACC_FINI]));
    /* print the collected profiling data */
    print_profiling_data("libliftracc", &(liftracc_function_profiling_data[0]), liftracc_function_names, LIFTRACC_FUNCTIONS_COUNT);
#endif // _LIFTRACC_PROFILING_
}

/**
 * \brief Check initialization state
 * Return the initialization state of the library
 *
 * \return
 *   init state
 */
int liftracc_is_initialized() {
    return liftracc_initialized;
}

#if _LIFTRACC_PROFILING_ == 1
/**
 * Only used to measure the time a dynamic call through the library
 * costs. This function is useless in any other manner.
 */
int liftracc_calltest_dynamic(int a, int b, int c)
{
    int (*liftracc_plugin_func)(); /* plugin function pointer */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_start(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_ */

#ifdef _LIFTRACC_SELECTOR_NEW_
    liftracc_selector_problem_info_t pinfo = { .info1 = 0 }; /* fill the info struct */
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select(CALLTEST_DYNAMIC, &pinfo);
#else
    *(void **) (&liftracc_plugin_func) = liftracc_selector_select("liftracc_plugin_calltest_dynamic");
#endif /* _LIFTRACC_SELECTOR_NEW_ */

#if _LIFTRACC_PROFILING_ == 2
    liftracc_function_timing_stop(&(liftracc_profiling_data[SELECT_CALL]));
#endif /* _LIFTRACC_PROFILING_ */

    if (liftracc_plugin_func != 0)  {
        /* in case we got a valid pointer, call the function */
        int ret = (*liftracc_plugin_func)(a, b, c);
        return ret;
    } else
        ERROR("liftracc_calltest_dynamic not executed");
    return 0;
}

#endif /* _LIFTRACC_PROFILING_ */

