/*
**
** LINPACK.C        Linpack benchmark, calculates FLOPS.
**                  (FLoating Point Operations Per Second)
**
** Translated to C by Bonnie Toy 5/88
**
** Modified by Will Menninger, 10/93, with these features:
**  (modified on 2/25/94  to fix a problem with daxpy  for
**   unequal increments or equal increments not equal to 1.
**     Jack Dongarra)
**
** Modified by Manuel Niekamp <niekma@upb.de>
** (modified on 19.11.2010)
**
** To compile: 
** gcc -O3 -I<liftracc_incdir> -L<liftracc_libdir> -lliftracc -o linpack linpack.c
**
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define ZERO       0.0e0
#define ONE        1.0e0

/* CBLAS selected */
#if defined(_SELECT_CBLAS_)

#include "cblas.h"
const char *info_str = "cblas version";
#define call_idamax cblas_idamax
#define call_dscal  cblas_dscal
#define call_daxpy  cblas_daxpy
#define call_ddot   cblas_ddot

/* LIFTRACC selected */
#elif defined(_SELECT_LIFTRACC_)

#include "liftracc.h"
const char *info_str = "liftracc version";
#define call_idamax liftracc_idamax
#define call_dscal  liftracc_dscal
#define call_daxpy  liftracc_daxpy
#define call_ddot   liftracc_ddot

/* nothing selected */
#else

#error "No compiler option -D_SELECT_(CBLAS|LIFTRACC)_ found."
#define call_idamax no_idamax
#define call_dscal  no_dscal
#define call_daxpy  no_daxpy
#define call_ddot   no_ddot

#endif

static double linpack_dyn(long nreps, int arsize);
static void matgen_dyn(double *a, int lda, int n, double *b, double *norma);
static void dgefa_dyn(double *a, int lda, int n, int *ipvt, int *info);
static void dgesl_dyn(double *a, int lda, int n, int *ipvt, double *b, int job);
static double second(void);

static void print_mempool(void *mempool, int ar2dsize, int arsize, int intsize);

static void *mempool;

#define MAX_DIM 16384

int main(void)
{
    char    buf[80];
    int     arsize;
    long    arsize2d, memreq, nreps;
    size_t  malloc_arg;
    
    printf("\n\nUsing %s.\n\n", info_str);
    printf("Average performance:\n");
    printf("N Reps Time(s) DGEFA DGESL OVERHEAD KFLOPS\n");
    printf("------------------------------------------\n");

    for (arsize=16; arsize<=MAX_DIM; arsize*=2) {
        arsize/=2;
        arsize*=2;
        arsize2d = (long)arsize*(long)arsize;
        memreq=arsize2d*sizeof(double)+(long)arsize*sizeof(double)+(long)arsize*sizeof(int);
        malloc_arg=(size_t)memreq;
        if (malloc_arg!=memreq || (mempool=malloc(malloc_arg))==NULL) {
            printf("Not enough memory available for given array size.\n\n");
            return 1;
        }
        nreps=1;
        while (linpack_dyn(nreps, arsize)<10.)
            nreps*=2;
        /* print mempool array */
        print_mempool(mempool, arsize2d*sizeof(double), (long)arsize*sizeof(double), (long)arsize*sizeof(int));
        free(mempool);
    }
}

static double linpack_dyn(long nreps, int arsize)
{
    double *a, *b;
    double norma, t1, kflops, tdgesl, tdgefa, totalt, toverhead, ops;
    int    *ipvt, n, info, lda;
    long   i, arsize2d;

    lda = arsize;
    n = arsize/2;
    arsize2d = (long)arsize*(long)arsize;
    ops=((2.0*n*n*n)/3.0+2.0*n*n);
    a=(double *)mempool;
    b=a+arsize2d;
    ipvt=(int *)&b[arsize];
    tdgesl=0;
    tdgefa=0;
    totalt=second();
    for (i=0; i<nreps; i++) {
        matgen_dyn(a, lda, n, b, &norma);
        t1 = second();
        dgefa_dyn(a, lda, n, ipvt, &info);
        tdgefa += second()-t1;
        t1 = second();
        dgesl_dyn(a, lda, n, ipvt, b, 0);
        tdgesl += second()-t1;
    }
    totalt=second()-totalt;
    if (totalt<0.5 || tdgefa+tdgesl<0.2)
        return(0.);
    kflops=2.*nreps*ops/(1000.*(tdgefa+tdgesl));
    toverhead=totalt-tdgefa-tdgesl;
    if (tdgefa<0.) tdgefa=0.;
    if (tdgesl<0.) tdgesl=0.;
    if (toverhead<0.) toverhead=0.;
    printf("%d %ld %.2f %.2f%% %.2f%% %.2f%% %.3f\n",
           arsize, nreps, totalt, 100.*tdgefa/totalt,
           100.*tdgesl/totalt, 100.*toverhead/totalt,
           kflops);
    
    return(totalt);
}

static void matgen_dyn(double *a, int lda, int n, double *b, double *norma)
{
    int init, i, j;

    init = 1325;
    *norma = 0.0;
    for (j = 0; j < n; j++)
        for (i = 0; i < n; i++) {
            init = (int)((long)3125*(long)init % 65536L);
            a[lda*j+i] = (init - 32768.0)/16384.0;
            *norma = (a[lda*j+i] > *norma) ? a[lda*j+i] : *norma;
        }
    for (i = 0; i < n; i++)
        b[i] = 0.0;
    for (j = 0; j < n; j++)
        for (i = 0; i < n; i++)
            b[i] = b[i] + a[lda*j+i];

    printf("Matrix A:\n");
    for (j=0; j<n; j++)
        for (i=0; i<n; i++)
            printf("%f ", a[lda*j+i]);
    printf("\n");

    printf("Matrix B:\n");
    for (j=0; j<n; j++)
        for (i=0; i<n; i++)
            printf("%f ", b[lda*j+i]);
    printf("\n");
}

static void dgefa_dyn(double *a, int lda, int n, int *ipvt, int *info)
{
    double t;
    int j, k, kp1, l, nm1;

    /* gaussian elimination with partial pivoting */
    *info = 0;
	nm1 = n - 1;
	if (nm1 >=  0)
		for (k = 0; k < nm1; k++) {
			kp1 = k + 1;
			/* find l = pivot index */
			l = call_idamax(n-k,&a[lda*k+k],1) + k;
			ipvt[k] = l;
			/* zero pivot implies this column already triangularized */
			if (a[lda*k+l] != ZERO) {
				/* interchange if necessary */
				if (l != k) {
					t = a[lda*k+l];
					a[lda*k+l] = a[lda*k+k];
					a[lda*k+k] = t;
				}
				/* compute multipliers */
				t = -ONE/a[lda*k+k];
				call_dscal(n-(k+1),t,&a[lda*k+k+1],1);
				/* row elimination with column indexing */
				for (j = kp1; j < n; j++) {
					t = a[lda*j+l];
					if (l != k) {
						a[lda*j+l] = a[lda*j+k];
						a[lda*j+k] = t;
					}
					call_daxpy(n-(k+1),t,&a[lda*k+k+1],1,&a[lda*j+k+1],1);
				}
			} else
				(*info) = k;
		}
	ipvt[n-1] = n-1;
	if (a[lda*(n-1)+(n-1)] == ZERO)
		(*info) = n-1;
}

static void dgesl_dyn(double *a, int lda, int n, int *ipvt, double *b, int job)
{
    double t;
    int    k, kb, l, nm1;

	nm1 = n - 1;
	if (job == 0) {
		/* job = 0 , solve  a * x = b   */
		/* first solve  l*y = b         */
		if (nm1 >= 1)
			for (k = 0; k < nm1; k++) {
				l = ipvt[k];
				t = b[l];
				if (l != k) {
					b[l] = b[k];
					b[k] = t;
				}
				call_daxpy(n-(k+1),t,&a[lda*k+k+1],1,&b[k+1],1);
			}
		/* now solve  u*x = y */
		for (kb = 0; kb < n; kb++) {
			k = n - (kb + 1);
			b[k] = b[k]/a[lda*k+k];
			t = -b[k];
			call_daxpy(k,t,&a[lda*k+0],1,&b[0],1);
		}
	} else {
		/* job = nonzero, solve  trans(a) * x = b  */
		/* first solve  trans(u)*y = b             */
		for (k = 0; k < n; k++) {
			t = call_ddot(k,&a[lda*k+0],1,&b[0],1);
			b[k] = (b[k] - t)/a[lda*k+k];
		}
		/* now solve trans(l)*x = y     */
		if (nm1 >= 1)
			for (kb = 1; kb < nm1; kb++) {
				k = n - (kb+1);
				b[k] = b[k] + call_ddot(n-(k+1),&a[lda*k+k+1],1,&b[k+1],1);
				l = ipvt[k];
				if (l != k) {
					t = b[l];
					b[l] = b[k];
					b[k] = t;
				}
			}
	}
}

static double second(void)
{
    return ((double)((double)clock()/(double)CLOCKS_PER_SEC));
}

static void print_mempool(void *mempool, int ar2dsize, int arsize, int intsize)
{
    /* TODO */
    double *a = (double*)mempool;
    double *b = (double*)a+ar2dsize;
    double *c = (double*)b+arsize;
}

