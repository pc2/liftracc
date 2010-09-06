
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "liftracc_logging.h"
extern "C"{
#include "cblas.h"
}

int main(int argc, char** argv) {

    float *v1 = (float*) malloc( sizeof(float) * 4 );
    float *v2 = (float*) malloc( sizeof(float) * 4 );
    float fret = 0;

    v1[0] = 1;
    v1[1] = 3;
    v1[2] = 3;
    v1[3] = 7;

    v2[0] = 6;
    v2[1] = 7;
    v2[2] = 8;
    v2[3] = 6;

    printf("test02 begin\n");
    
    fret = inner_cblas_sdot(4, v1, 1, v2, 1);
    
    printf("float ret = %f\n", fret);
    
    printf("test02 end\n");

    free(v1);
    free(v2);

    return 0;
}

