
#include <stdio.h>
#include <unistd.h>

/* because sizeof(decision_data_t) is 1 otherwise !!! */
#define _LIFTRACC_AUTOMODE_

#include "liftracc.h"
#include "liftracc_selector.h"

int main(int argc, char* argv[])
{
    decision_data_t cblas_data[FUNCTION_COUNT*ARRAY_SIZE] = { };
    decision_data_t atlas_data[FUNCTION_COUNT*ARRAY_SIZE] = { };
    decision_data_t cublas_data[FUNCTION_COUNT*ARRAY_SIZE] = { };
    decision_data_t clearspeed_data[FUNCTION_COUNT*ARRAY_SIZE] = { };
    decision_data_t goto2_data[FUNCTION_COUNT*ARRAY_SIZE] = { };

    int i,j;
    int c=0;
    for (i=0;i<FUNCTION_COUNT;i++)
        for (j=0;j<ARRAY_SIZE;j++)
            cblas_data[i*ARRAY_SIZE+j]=++c;

    int ret = 0;

    printf("Start of app...\n");

    if ((ret = liftracc_selector_loadinfo("/home/niekma/diplomarbeit/sourcecode/libdynblas/build/plugins/cblas_plugin.pso.data", (decision_data_t*)&cblas_data[0])) != NO_ERROR)
        printf("Error on loading cblas_data: %d\n", ret);
    
    if ((ret = liftracc_selector_loadinfo("/home/niekma/diplomarbeit/sourcecode/libdynblas/build/plugins/atlas_plugin.pso.data", (decision_data_t*)&atlas_data[0])) != NO_ERROR)
        printf("Error on loading atlas_data: %d\n", ret);
    
    if ((ret = liftracc_selector_loadinfo("/home/niekma/diplomarbeit/sourcecode/libdynblas/build/plugins/cublas_plugin.pso.data", (decision_data_t*)&cublas_data[0])) != NO_ERROR)
        printf("Error on loading cublas_data: %d\n", ret);
    
    if ((ret = liftracc_selector_loadinfo("/home/niekma/diplomarbeit/sourcecode/libdynblas/build/plugins/clearspeed_plugin.pso.data", (decision_data_t*)&clearspeed_data[0])) != NO_ERROR)
        printf("Error on loading clearspeed_data: %d\n", ret);
    
    if ((ret = liftracc_selector_loadinfo("/home/niekma/diplomarbeit/sourcecode/libdynblas/build/plugins/goto2_plugin.pso.data", (decision_data_t*)&goto2_data[0])) != NO_ERROR)
        printf("Error on loading goto2_data: %d\n", ret);

    // TODO

    return 0;
}

