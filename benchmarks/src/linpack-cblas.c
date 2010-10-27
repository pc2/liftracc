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
** (modified on 06.02.2010 to direct calls through
** liftracc wrapper-library)
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

#include "cblas.h"

/* only testing */
/*
#define cblas_idamax inner_cblas_idamax
#define cblas_dscal  inner_cblas_dscal
#define cblas_daxpy  inner_cblas_daxpy
#define cblas_ddot   inner_cblas_ddot
*/
static double linpack_dyn(long nreps, int arsize);
static void matgen_dyn(double *a, int lda, int n, double *b, double *norma);
static void dgefa_dyn(double *a, int lda, int n, int *ipvt, int *info);
static void dgesl_dyn(double *a, int lda, int n, int *ipvt, double *b, int job);
static double second(void);

static void *mempool;

#define MAX_DIM 16384

int main(void)
{
    char    buf[80];
    int     arsize;
    long    arsize2d, memreq, nreps;
    size_t  malloc_arg;

    printf("Average performance:\n\n");
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

/*
** For matgen,
** We would like to declare a[][lda], but c does not allow it.  In this
** function, references to a[i][j] are written a[lda*i+j].
*/
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
}

/*
**
** DGEFA benchmark
**
** We would like to declare a[][lda], but c does not allow it.  In this
** function, references to a[i][j] are written a[lda*i+j].
**
**   dgefa factors a double precision matrix by gaussian elimination.
**
**   dgefa is usually called by dgeco, but it can be called
**   directly with a saving in time if  rcond  is not needed.
**   (time for dgeco) = (1 + 9/n)*(time for dgefa) .
**
**   on entry
**
**      a       REAL precision[n][lda]
**              the matrix to be factored.
**
**      lda     integer
**              the leading dimension of the array  a .
**
**      n       integer
**              the order of the matrix  a .
**
**   on return
**
**      a       an upper triangular matrix and the multipliers
**              which were used to obtain it.
**              the factorization can be written  a = l*u  where
**              l  is a product of permutation and unit lower
**              triangular matrices and  u  is upper triangular.
**
**      ipvt    integer[n]
**              an integer vector of pivot indices.
**
**      info    integer
**              = 0  normal value.
**              = k  if  u[k][k] .eq. 0.0 .  this is not an error
**                   condition for this subroutine, but it does
**                   indicate that dgesl or dgedi will divide by zero
**                   if called.  use  rcond  in dgeco for a reliable
**                   indication of singularity.
**
**   linpack. this version dated 08/14/78 .
**   cleve moler, university of New Mexico, argonne national lab.
**
**   functions
**
**   blas daxpy, dscal, idamax
**
*/
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
			l = cblas_idamax(n-k,&a[lda*k+k],1) + k;
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
				cblas_dscal(n-(k+1),t,&a[lda*k+k+1],1);
				/* row elimination with column indexing */
				for (j = kp1; j < n; j++) {
					t = a[lda*j+l];
					if (l != k) {
						a[lda*j+l] = a[lda*j+k];
						a[lda*j+k] = t;
					}
					cblas_daxpy(n-(k+1),t,&a[lda*k+k+1],1,&a[lda*j+k+1],1);
				}
			} else
				(*info) = k;
		}
	ipvt[n-1] = n-1;
	if (a[lda*(n-1)+(n-1)] == ZERO)
		(*info) = n-1;
}

/*
**
** DGESL benchmark
**
** We would like to declare a[][lda], but c does not allow it.  In this
** function, references to a[i][j] are written a[lda*i+j].
**
**   dgesl solves the double precision system
**   a * x = b  or  trans(a) * x = b
**   using the factors computed by dgeco or dgefa.
**
**   on entry
**
**      a       double precision[n][lda]
**              the output from dgeco or dgefa.
**
**      lda     integer
**              the leading dimension of the array  a .
**
**      n       integer
**              the order of the matrix  a .
**
**      ipvt    integer[n]
**              the pivot vector from dgeco or dgefa.
**
**      b       double precision[n]
**              the right hand side vector.
**
**      job     integer
**              = 0         to solve  a*x = b ,
**              = nonzero   to solve  trans(a)*x = b  where
**                          trans(a)  is the transpose.
**
**  on return
**
**      b       the solution vector  x .
**
**   error condition
**
**      a division by zero will occur if the input factor contains a
**      zero on the diagonal.  technically this indicates singularity
**      but it is often caused by improper arguments or improper
**      setting of lda .  it will not occur if the subroutines are
**      called correctly and if dgeco has set rcond .gt. 0.0
**      or dgefa has set info .eq. 0 .
**
**   to compute  inverse(a) * c  where  c  is a matrix
**   with  p  columns
**         dgeco(a,lda,n,ipvt,rcond,z)
**         if (!rcond is too small){
**              for (j=0,j<p,j++)
**                      dgesl(a,lda,n,ipvt,c[j][0],0);
**         }
**
**   linpack. this version dated 08/14/78 .
**   cleve moler, university of new mexico, argonne national lab.
**
**   functions
**
**   blas daxpy, ddot
*/
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
				cblas_daxpy(n-(k+1),t,&a[lda*k+k+1],1,&b[k+1],1);
			}
		/* now solve  u*x = y */
		for (kb = 0; kb < n; kb++) {
			k = n - (kb + 1);
			b[k] = b[k]/a[lda*k+k];
			t = -b[k];
			cblas_daxpy(k,t,&a[lda*k+0],1,&b[0],1);
		}
	} else {
		/* job = nonzero, solve  trans(a) * x = b  */
		/* first solve  trans(u)*y = b             */
		for (k = 0; k < n; k++) {
			t = cblas_ddot(k,&a[lda*k+0],1,&b[0],1);
			b[k] = (b[k] - t)/a[lda*k+k];
		}
		/* now solve trans(l)*x = y     */
		if (nm1 >= 1)
			for (kb = 1; kb < nm1; kb++) {
				k = n - (kb+1);
				b[k] = b[k] + cblas_ddot(n-(k+1),&a[lda*k+k+1],1,&b[k+1],1);
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

