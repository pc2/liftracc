
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "cycle.h"

int main(int argc, char** argv) {

    struct timespec t1;
    struct timespec t2;
    
    ticks x1, x2, x3;

    x1 = getticks();
    x3 = getticks();
    clock_gettime(CLOCK_MONOTONIC, &t1); // CLOCK_MONOTONIC because unaffected by clock_settime()
    x2 = getticks();
    clock_gettime(CLOCK_MONOTONIC, &t2);

    struct timespec t10;
    struct timespec t20;

    ticks x10, x20, x30;

    x10 = getticks();
    x30 = getticks();
    clock_gettime(CLOCK_MONOTONIC, &t10);
    clock_gettime(CLOCK_MONOTONIC, &t20);
    x20 = getticks();
    
    printf("Res: %d sec %ld nsec -- %llu\n", (int)t1.tv_sec, t1.tv_nsec, x1);
    printf("Res: %d sec %ld nsec -- %llu\n", (int)t2.tv_sec, t2.tv_nsec, x2);
    printf("delta: %llu\n", x2-x3);

    printf("Res: %d sec %ld nsec -- %llu\n", (int)t10.tv_sec, t10.tv_nsec, x10);
    printf("Res: %d sec %ld nsec -- %llu\n", (int)t20.tv_sec, t20.tv_nsec, x20);
    printf("delta: %llu\n", x20-x30);

    printf("CLOCKS_PER_SEC %ld\n", CLOCKS_PER_SEC);

    int i;
    double average = 0.0;
    for (i=1;i<1001;i++) {
        x10 = getticks();
        sleep(1);
        x20 = getticks();

        printf("ticks per sec: %llu\n", x20-x10);
        average = ( ( average * (i-1) ) + (x20-x10) ) / (double) i;
        printf("average ticks: %f\n", average);
    }

    return 0;
}

