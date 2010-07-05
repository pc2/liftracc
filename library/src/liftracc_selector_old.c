
#include "liftracc_selector.h"
#include "liftracc_plugin.h"
#include "liftracc_logging.h"

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
char *error = 0;
void **library_handles = 0;
int found_libs = 0;
unsigned char *prio_list = 0;
char library_path[PATH_MAX];

/* function definitions */
liftracc_selector_error_t liftracc_selector_init()
{
    dlerror(); // clear possible dlerror message

    Dl_info info;
    dladdr(liftracc_selector_init, &info);
    strncpy(library_path, info.dli_fname, PATH_MAX);
    *(strrchr(library_path, '/')) = '\0';

    MSG("LIB_PATH: %s", library_path);

    char plugin_pattern[PATH_MAX];
    strncpy(plugin_pattern, library_path, PATH_MAX);
    strncat(plugin_pattern, "/plugins/*.pso", PATH_MAX-strlen(plugin_pattern)-1);

    glob_t gbuff;

    if (!glob(plugin_pattern, GLOB_ERR|GLOB_NOSORT, 0, &gbuff)) {

        found_libs = gbuff.gl_pathc;

        library_handles = (void**) malloc(found_libs * sizeof(void*));

        prio_list = (unsigned char *) malloc(found_libs * sizeof(unsigned char));
        memset(prio_list, 0, found_libs * sizeof(unsigned char));

        int prio_tmp[256];
        memset(prio_tmp, -1, 256 * sizeof(int));

        int i;
        for (i=0;i<found_libs;i++) {
            MSG("PLUGIN: %s", gbuff.gl_pathv[i]);

            library_handles[i] = dlopen(gbuff.gl_pathv[i], RTLD_LAZY);
            if (!library_handles[i]) {
                ERROR("%s", dlerror());
            } else {
                plugin_info_t *plugin_info = dlsym(library_handles[i], "liftracc_plugin_info");
                MSG("UUID: %s", plugin_info->uuid);
                MSG("NAME: %s", plugin_info->name);
                MSG("DESC: %s", plugin_info->desc);
                MSG("PRIO: %u", plugin_info->prio);

                prio_tmp[plugin_info->prio] = i;
            }
        }

        int p = 0;
        for (i=255;i>=0;i--) {
            if (prio_tmp[i]>-1) {
                prio_list[p] = prio_tmp[i];
                MSG("PRIO_ENTRY(%d): %d - [%d]", p, prio_tmp[i], i);
                p++;
            }
        }
    } else return NO_LIBS_FOUND_ERROR;

    return NO_ERROR;
}

liftracc_selector_error_t liftracc_selector_fini()
{
    dlerror();

    int i;
    for (i=0; i<found_libs; i++) {
        if (library_handles[i]) {
            dlclose(library_handles[i]);
            library_handles[i] = 0;
        }
    }

    free(library_handles);
    library_handles = 0;
    free(prio_list);
    prio_list = 0;

    if ((error = dlerror()) != 0)  {
        ERROR("%s", error);
        return LIBS_CLOSE_ERROR;
    }

    return NO_ERROR;
}

void *liftracc_selector_select(const char *symbol_name)
{
    void *func = 0;

    int i = 0;
    for (i=0; i<found_libs; i++) {
        func = dlsym(library_handles[prio_list[i]], symbol_name);
        if ((error = dlerror()) == 0)
            return func;
    }

    return 0;
}

