
#include <stdio.h>
#include <unistd.h>

/* because sizeof(decision_data_t) is 1 otherwise !!! */
#define _LIFTRACC_AUTOMODE_

#define LIFTRACC_BUILD_PATH "/home/niekma/liftracc/library/build"

#include "liftracc.h"
#include "liftracc_selector.h"

void print_data(const char *header, decision_data_t *data)
{
    printf("\n%s\n", header);
    int fc, i;
    int print_this;
    for (fc=0; fc<FUNCTION_COUNT; fc++) {
        print_this = 0;
        for (i=0; i<ARRAY_SIZE; i++) {
            if (data[fc*ARRAY_SIZE+i]) {
                print_this = 1;
                break;
            }
        }
        if (print_this) {
            printf("FUNCTION %s\n", liftracc_selector_funcnames[fc]);
            for (i=0; i<ARRAY_SIZE; i++) {
                printf("%d: %llu; ", i, data[fc*ARRAY_SIZE+i]);
            }
            printf("\n");
        }
    }
}

int main(int argc, char* argv[])
{
    decision_data_t cblas_data[FUNCTION_COUNT*ARRAY_SIZE] = { };
    decision_data_t atlas_data[FUNCTION_COUNT*ARRAY_SIZE] = { };
    decision_data_t cublas_data[FUNCTION_COUNT*ARRAY_SIZE] = { };
    decision_data_t clearspeed_data[FUNCTION_COUNT*ARRAY_SIZE] = { };
    decision_data_t goto2_data[FUNCTION_COUNT*ARRAY_SIZE] = { };

    int ret = 0;

    printf("Start of app...\n");

    if ((ret = liftracc_selector_loadinfo(LIFTRACC_BUILD_PATH"/plugins/cblas_plugin.pso.data", (decision_data_t*)&cblas_data[0])) != NO_ERROR)
        printf("Error on loading cblas_data: %d\n", ret);
    
    if ((ret = liftracc_selector_loadinfo(LIFTRACC_BUILD_PATH"/plugins/atlas_plugin.pso.data", (decision_data_t*)&atlas_data[0])) != NO_ERROR)
        printf("Error on loading atlas_data: %d\n", ret);
    
    if ((ret = liftracc_selector_loadinfo(LIFTRACC_BUILD_PATH"/plugins/cublas_plugin.pso.data", (decision_data_t*)&cublas_data[0])) != NO_ERROR)
        printf("Error on loading cublas_data: %d\n", ret);
    
    if ((ret = liftracc_selector_loadinfo(LIFTRACC_BUILD_PATH"/plugins/clearspeed_plugin.pso.data", (decision_data_t*)&clearspeed_data[0])) != NO_ERROR)
        printf("Error on loading clearspeed_data: %d\n", ret);
    
    if ((ret = liftracc_selector_loadinfo(LIFTRACC_BUILD_PATH"/plugins/goto2_plugin.pso.data", (decision_data_t*)&goto2_data[0])) != NO_ERROR)
        printf("Error on loading goto2_data: %d\n", ret);

    /* print cblas-array */
    print_data("cblas_data:", &cblas_data[0]);
    /* print atlas-array */
    print_data("atlas_data:", &atlas_data[0]);
    /* print cublas-array */
    print_data("cublas_data:", &cublas_data[0]);
    /* print clearspeed-array */
    print_data("clearspeed_data:", &clearspeed_data[0]);
    /* print goto2-array */
    print_data("goto2_data:", &goto2_data[0]);

    return 0;
}

