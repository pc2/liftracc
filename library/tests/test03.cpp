
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

// cblas signature
extern "C" double cblas_ddot(const int, const double *, const int, const double *, const int);

// MKL,Clearspeed signature
extern "C" double DDOT(const int*, const double *, const int*, const double *, const int*);

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

    const int c1 = 4;
    const int c2 = 1;

    printf("test03 begin\n");
    
    dret = DDOT(&c1, v1, &c2, v2, &c2);
    
    printf("ret = %f\n", dret);
    
    printf("test03 end\n");

    free(v1);
    free(v2);

    return 0;
}

