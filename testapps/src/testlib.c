
#include <stdio.h>

unsigned long long fib_rec(unsigned long long n) {
    if (n>1)
        return fib_rec(n-1)+fib_rec(n-2);
    else
        return n?1:0;
}

unsigned long long fib_iter(unsigned long long n) {
    unsigned long long c0=0;
    unsigned long long c1=1;
    unsigned long long ct=0;

    if (n<2) return n?1:0;

    n--;
    while(n) {
        ct=c1;
        c1=c0+c1;
        c0=ct;
        n--;
    }

    return c1;
}

