/**
 * @file liftracc_selector.c
 * @brief C file of the selector module
 *
 * @author Manuel Niekamp <niekma@upb.de>
 * @version 0.1
 *
 * This file implements the interface to the selector component.
 * The selector is used inside the wrapper library to select
 * the best function out of a function pool. The functions
 * selected match the calling one from the wrapper library.
 */

/**
 * @addtogroup liftracc_select
 * @{
 */

#include "liftracc_selector.h"
#include "liftracc_plugin.h"
#include "liftracc_logging.h"

#if _LIFTRACC_PROFILING_ > 0
#include "liftracc_profiling.h"
#endif /* _LIFTRACC_PROFILING_ */

#ifndef __USE_GNU
#define __USE_GNU
#endif
#include <dlfcn.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

#include <glob.h>

/* global data */

char *error                          = 0;    /**< Pointer to error message.        */
int  liftracc_found_libs             = 0;    /**< Number of found libraries.       */
char liftracc_library_path[PATH_MAX] = { };  /**< Path to lib liftracc.             */
void **liftracc_plugin_handles       = 0;    /**< Pointer to all plugin handlers   */

/**
 * @brief The decision table.
 *
 * Two dimentional array containing the information
 * in order to find the best function out of the set of
 * plugins. In auto mode the collected data is the time
 * in ticks, the functions have run in average.
 */
decision_data_t liftracc_decision_table[FUNCTION_COUNT][ARRAY_SIZE] = { };

/**
 * @brief The look up table.
 *
 * The function pointer look up table.
 * In order to get super fast access to the needed
 * functions, this array contains a function pointer
 * to ever blas function supported.
 * The stored pointer is that one to the fastest
 * function. (Found in init phase)
 */
void *liftracc_fptr_lut[FUNCTION_COUNT][ARRAY_SIZE] = { };

/**
 * @brief Preferred function pointers.
 *
 * Array that contains the pointers to the functions
 * in the plugin that should be used in prefered manner.
 * The Plugin is selectable through the environment
 * variable LIFTRACC_USE_PLUGIN. The string passed to
 * this variable must be the plugins' uuid.
 */
void *liftracc_preferred_fptr[FUNCTION_COUNT] = {};

/* function prototypes */

liftracc_selector_error_t liftracc_selector_load_plugins();

/* function definitions */

liftracc_selector_error_t liftracc_selector_init()
{
    dlerror(); /* clear possible dlerror message */

    /* load all found plugins. hopefully without error */
    if (liftracc_selector_load_plugins()!=NO_ERROR) {
        ERROR("LIBS_OPEN_ERROR");
        return LIBS_OPEN_ERROR;
    }

#if _LIFTRACC_PROFILING_ == 4
    liftracc_function_timing_start(&(liftracc_profiling_data[LUT_INIT]));
#endif /* _LIFTRACC_PROFILING_ */
    
    /* init look up table */
    int cp, cf, ca; /* cp: counter plugins, cf: counter functions, ca: counter array size */

    for (cp=0; cp<liftracc_found_libs; cp++) {
        void *handle = liftracc_plugin_handles[cp]; /* handle to current plugin */
        decision_data_t (*plugin_getdecision)();   /* getdecision function prototype */
        
        /* get function from current plugin */
        *(void **) (&plugin_getdecision) = dlsym(handle, "liftracc_plugin_getdecision");

        if ((error = dlerror()) != 0) {
            ERROR("FUNCTION_NOT_FOUND_ERROR");
            return FUNCTION_NOT_FOUND_ERROR;
        }
        
        /* if no error has occured get a decision value for
           every function and for every decision entry in array */
        for (cf=0; cf<FUNCTION_COUNT; cf++)
            for (ca=0; ca<ARRAY_SIZE; ca++) {
                decision_data_t tmp = (*plugin_getdecision)(cf, ca);
                /* if data is better set new value in liftracc_decision_table
                   and set function pointer in liftracc_fptr_lut */
#ifdef _LIFTRACC_AUTOMODE_
                if ((tmp < liftracc_decision_table[cf][ca]) ||
                    (liftracc_fptr_lut[cf][ca] == 0)) {
#else
                if (tmp > liftracc_decision_table[cf][ca]) {
#endif /* _LIFTRACC_AUTOMODE_ */
                    /* try to get a valid function pointer */
                    void *func = dlsym(handle, liftracc_selector_funcnames[cf]);
                    if (func != 0) {
                        liftracc_fptr_lut[cf][ca] = func;
                        liftracc_decision_table[cf][ca] = tmp;
                        /* INFO("PRIO %d %d FUNC %d %s", tmp.tks, ca, cf, liftracc_selector_funcnames[cf]); */
                    }
                }
            }
    }
#if _LIFTRACC_PROFILING_ == 4
    liftracc_function_timing_stop(&(liftracc_profiling_data[LUT_INIT]));
#endif /* _LIFTRACC_PROFILING_ */

    return NO_ERROR;
}

liftracc_selector_error_t liftracc_selector_fini()
{
    dlerror();

    int i;
    for (i=0; i<liftracc_found_libs; i++) {
        if (liftracc_plugin_handles[i]) {
            dlclose(liftracc_plugin_handles[i]);
            liftracc_plugin_handles[i] = 0;
        }
    }

    free(liftracc_plugin_handles);
    liftracc_plugin_handles = 0;

    if ((error = dlerror()) != 0)  {
        ERROR("%s", error);
        return LIBS_CLOSE_ERROR;
    }

    return NO_ERROR;
}

void *liftracc_selector_select(const liftracc_selector_funcid_t func_id,
                               const liftracc_selector_problem_info_t *problem_info)
{
#ifdef _LIFTRACC_USE_PLUGIN_
    /* if use plugin is enabled use a pointer out of the
       preferred function pointer table */
    if (liftracc_preferred_fptr[func_id])
        return liftracc_preferred_fptr[func_id];
#endif /* _LIFTRACC_USE_PLUGIN_ */
    
    /* the normal case is to use one from the lut */
    return liftracc_fptr_lut[func_id][get_inx(problem_info->info1, ARRAY_SIZE-1)];
}

liftracc_selector_error_t liftracc_selector_load_plugins()
{
#if _LIFTRACC_USE_PLUGIN_
    char *use_plugin_uuid = getenv("LIFTRACC_USE_PLUGIN");
#endif /* _LIFTRACC_USE_PLUGIN_ */

    /* get the path of the library  */
    Dl_info info;
    dladdr(liftracc_selector_init, &info);
    strncpy(liftracc_library_path, info.dli_fname, PATH_MAX);
    *(strrchr(liftracc_library_path, '/')) = '\0';

    MSG("LIB_PATH: %s", liftracc_library_path);

    /* generate glob pattern for later use */
    char plugin_pattern[PATH_MAX];
    strncpy(plugin_pattern, liftracc_library_path, PATH_MAX);
    strncat(plugin_pattern, "/plugins/*.pso", PATH_MAX-strlen(plugin_pattern)-1);

    glob_t gbuff;

    /* in order to find the plugins glob is used */
    if (!glob(plugin_pattern, GLOB_ERR|GLOB_NOSORT, 0, &gbuff)) {
        /* whoopee we found some plugins */
        liftracc_found_libs = gbuff.gl_pathc;

        liftracc_plugin_handles = (void**) malloc(liftracc_found_libs * sizeof(void*));

        /* for all found plugins, load them */
        int i;
        for (i=0;i<liftracc_found_libs;i++) {
            MSG("PLUGIN: %s", gbuff.gl_pathv[i]);

            liftracc_plugin_handles[i] = dlopen(gbuff.gl_pathv[i], RTLD_LAZY);
            if (!liftracc_plugin_handles[i]) {
                ERROR("%s", dlerror());
            } else {
                plugin_info_t *plugin_info = dlsym(liftracc_plugin_handles[i], "liftracc_plugin_info");
                MSG("UUID: %s", plugin_info->uuid);
                MSG("NAME: %s", plugin_info->name);
                MSG("DESC: %s", plugin_info->desc);
                MSG("PRIO: %u", plugin_info->prio);
#ifdef _LIFTRACC_USE_PLUGIN_
                /* fill liftracc_preferred_fptr */
                if (use_plugin_uuid) {
                    if (!strcmp(use_plugin_uuid, plugin_info->uuid)) {
                        MSG("THIS PLUGIN IS PREFERRED");
                        int x;
                        for(x=0; x<FUNCTION_COUNT; x++) {
                            void *func = dlsym(liftracc_plugin_handles[i], liftracc_selector_funcnames[x]);
                            if (func != 0) liftracc_preferred_fptr[x] = func;
                        }
                    }
                }
#endif /* _LIFTRACC_USE_PLUGIN_ */
            }
        }
    } else return NO_LIBS_FOUND_ERROR;

    return NO_ERROR;
}

#ifdef _LIFTRACC_AUTOMODE_

liftracc_selector_error_t liftracc_selector_loadinfo(const char *file_name, decision_data_t *array)
{
    /* load decision data from HDD */
    /* ERROR("LOAD FROM: %s", file_name); */

    FILE *data_file = 0;

    data_file = fopen(file_name, "rb");

    if (data_file == 0) {
        return FILE_NOT_FOUND_ERROR;
    }
    
    size_t num = 0;
    int fc;
    decision_data_t tmp[ARRAY_SIZE] = { };

    for (fc=0; fc<FUNCTION_COUNT; fc++) {
        size_t count = fread((void*)(&tmp[0]), sizeof(decision_data_t), ARRAY_SIZE, data_file);
        num += count;
        /* ERROR("READ %d", (int)count); */
        if (count != ARRAY_SIZE) {
            ERROR("READ: count != ARRAY_SIZE !!!");
            if (data_file != 0) {
                fclose(data_file);
                data_file = 0;
            }
            return DATA_READ_ERROR;
        } else {
            int i;
            for (i=0; i<ARRAY_SIZE; i++) {
                /* ERROR("LOAD: array[fc=%d*ARRAY_SIZE+i=%d] = %u", fc, i, (unsigned int)array[fc*ARRAY_SIZE+i]); */
                array[fc*ARRAY_SIZE+i] = tmp[i];
            }
        }
        /* if ((feof(data_file) != 0) || (ferror(data_file) != 0)) break; */
        if (feof(data_file)) {
            ERROR("EOF");
            break;
        }
        if (ferror(data_file)) {
            ERROR("FERROR");
            break;
        }
    }
    
    if (num != (FUNCTION_COUNT*ARRAY_SIZE)) {
        ERROR("READ: num != (FUNCTION_COUNT*ARRAY_SIZE); %d != %d", (int)num, (FUNCTION_COUNT*ARRAY_SIZE));
        if (data_file != 0) {
            fclose(data_file);
            data_file = 0;
        }
        return DATA_READ_ERROR;
    }

    if (data_file != 0) {
        fclose(data_file);
        data_file = 0;
    }

    return NO_ERROR;
}

liftracc_selector_error_t liftracc_selector_saveinfo(const char *file_name, decision_data_t *array)
{
    /* save decision data to HDD */
    FILE *data_file = 0;

    data_file = fopen(file_name, "w+b");

    if (data_file == 0) {
        return FILE_NOT_FOUND_ERROR;
    }

    size_t num = 0;
    int fc;
    decision_data_t tmp[ARRAY_SIZE] = { };

    for (fc=0; fc<FUNCTION_COUNT; fc++) {
        int i;
        for (i=0; i<ARRAY_SIZE; i++) {
            /* ERROR("SAVE: tmp[fc=%d*ARRAY_SIZE+i=%d] = %u", fc, i, (unsigned int)array[fc*ARRAY_SIZE+i]); */
            tmp[i] = array[fc*ARRAY_SIZE+i];
        }
        size_t count = fwrite((void*)(&tmp[0]), sizeof(decision_data_t), ARRAY_SIZE, data_file);
        num += count;
        /* ERROR("WRITE %d", (int)count); */
        if (count != ARRAY_SIZE) {
            ERROR("WRITE: count != ARRAY_SIZE !!!");
            if (data_file != 0) {
                fclose(data_file);
                data_file = 0;
            }
            return DATA_WRITE_ERROR;
        }
        if (feof(data_file)) {
            ERROR("EOF");
            break;
        }
        if (ferror(data_file)) {
            ERROR("FERROR");
            break;
        }
    }
    
    if (num != (FUNCTION_COUNT*ARRAY_SIZE)) {
        ERROR("WRITE: num != (FUNCTION_COUNT*ARRAY_SIZE); %d != %d", (int)num, (FUNCTION_COUNT*ARRAY_SIZE));
        if (data_file != 0) {
            fclose(data_file);
            data_file = 0;
        }
        return DATA_WRITE_ERROR;
    }

    if (data_file != 0) {
        fclose(data_file);
        data_file = 0;
    }

    return NO_ERROR;
}

#else /* _LIFTRACC_AUTOMODE_ */

liftracc_selector_error_t liftracc_selector_loadinfo(const char *file_name, decision_data_t *array)
{
    /* TODO: prio mode loading from text file */
}

#endif /* _LIFTRACC_AUTOMODE_ */

/** @} */

