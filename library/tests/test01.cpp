
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "liftracc.h"
#include "liftracc_logging.h"

int main(int argc, char** argv) {

    double *v1 = (double*) malloc( sizeof(double) * 4 );
    double *v2 = (double*) malloc( sizeof(double) * 4 );
    double dret = 0;

    v1[0] = 1;
    v1[1] = 3;
    v1[2] = 3;
    v1[3] = 7;

    v2[0] = 6;
    v2[1] = 7;
    v2[2] = 8;
    v2[3] = 6;

    float *v3 = (float*) malloc( sizeof(float) * 4 );
    float *v4 = (float*) malloc( sizeof(float) * 4 );
    float fret = 0;

    v3[0] = 1;
    v3[1] = 3;
    v3[2] = 3;
    v3[3] = 7;

    v4[0] = 6;
    v4[1] = 7;
    v4[2] = 8;
    v4[3] = 6;

    printf("test01 begin\n");
    
    dret = liftracc_ddot(4, v1, 1, v2, 1);
    
    printf("double ret = %f\n", dret);
    
    fret = liftracc_sdot(4, v3, 1, v4, 1);
    
    printf("float ret = %f\n", fret);
    
    printf("test01 end\n");

    free(v1);
    free(v2);
    free(v3);
    free(v4);

    sleep(2);
    
    return 0;
}

