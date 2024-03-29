#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include <math.h>
#include <limits.h> /* INT_MAX */
#include <stdlib.h> /* abs */
#include <Rmath.h> /* for imin2 and imax2 */
#include <R_ext/Print.h> /* for Rprintf */
#include <R_ext/Utils.h> /* for R_rsort */
#include <R_ext/Applic.h>


static void stem_print(int close, int dist, int ndigits)
{
    if((close/10 == 0) && (dist < 0))
	Rprintf("  %*s | ", ndigits, "-0");
    else
	Rprintf("  %*d | ", ndigits, close/10);
}

static Rboolean stem_leaf(double *x, int n, double scale, int width, double atom)
{
    double r, c, x1, x2;
    int mm, mu, k, i, j, hi, lo, xi;
    int ldigits, hdigits, ndigits, pdigits;

    R_rsort(x,n);

    if(n <= 1)
	return FALSE;

    Rprintf("\n");
    if(x[n-1] > x[0]) {
	r = atom+(x[n-1]-x[0])/scale;
	c = pow(10.,(11.-(int)(log10(r)+10)));
	mm = imin2(2, imax2(0, (int)(r*c/25)));
	k = 3*mm + 2 - 150/(n+50);
	if ((k-1)*(k-2)*(k-5)==0)
	    c *= 10.;
	/* need to ensure that x[i]*c does not integer overflow */
	x1 = fabs(x[0]); x2 = fabs(x[n-1]);
	if(x2 > x1) x1 = x2;
	while(x1*c > INT_MAX) c /= 10;
	if (k*(k-4)*(k-8)==0) mu = 5;
	if ((k-1)*(k-5)*(k-6)==0) mu = 20;
    } else {
	r = atom + fabs(x[0])/scale;
	c = pow(10.,(11.-(int)(log10(r)+10)));
	k = 2; /* not important what */
    }
    
    mu = 10;
    if (k*(k-4)*(k-8)==0) mu = 5;
    if ((k-1)*(k-5)*(k-6)==0) mu = 20;

    /* Find the print width of the stem. */

    lo = floor(x[0]  *c/mu)*mu;
    hi = floor(x[n-1]*c/mu)*mu;
    ldigits = (lo < 0) ? floor(log10(-lo))+1 : 0;
    hdigits = (hi > 0) ? floor(log10(hi))    : 0;
    ndigits = (ldigits < hdigits) ? hdigits : ldigits;

    /* Starting cell */

    if(lo < 0 && floor(x[0]*c) == lo)
	lo=lo-mu;
    hi = lo+mu;
    if(floor(x[0]*c+0.5) > hi) {
	lo = hi;
	hi = lo+mu;
    }

    /* Print out the info about the decimal place */

    pdigits= 1 - floor(log10(c)+0.5);

    Rprintf("  O ponto decimal está ");
    if(pdigits == 0)
	Rprintf("na |\n\n");
    else
	Rprintf("%d dígito(s) para a %s da |\n\n",abs(pdigits),
		(pdigits > 0) ? "direita" : "esquerda");
    i = 0;
    do {
	if(lo < 0)
	    stem_print(hi,lo,ndigits);
	else
	    stem_print(lo,hi,ndigits);
	j = 0;
	do {
	    if(x[i] < 0)xi = x[i]*c - .5;
	    else	xi = x[i]*c + .5;

	    if( (hi == 0 && x[i] >= 0)||
		(lo <  0 && xi >  hi) ||
		(lo >= 0 && xi >= hi) )
		break;

	    j++;
	    if(j <= width-12) {
		Rprintf("%1d", abs(xi)%10);
	    }
	    i++;
	} while(i < n);
	if(j > width) {
	    Rprintf("+%d", j-width);
	}
	Rprintf("\n");
	if(i >= n)
	    break;
	hi += mu;
	lo += mu;
    } while(1);
    Rprintf("\n");
    return TRUE;
}

Rboolean stemleaf(double *x, int *n, double *scale, int *width, double *atom)
{
    return stem_leaf(x, *n, *scale, *width, *atom);
}
