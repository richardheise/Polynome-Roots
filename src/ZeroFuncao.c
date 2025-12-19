#include <stdio.h>
#include <math.h>

#include "utils.h"
#include "ZeroFuncao.h"

double bisection (Polynomial p, double a, double b, double eps,
	       int *it, double *root) {

	double xm_old, xm_new, error = 0;

	xm_new = (a + b) / 2;
	double val1, val2;

	calcPolynomial_fast(p, a, &val1, NULL);
	calcPolynomial_fast(p, xm_new, &val2, NULL);

	double compare = val1 * val2;

	error = fabs((xm_new - xm_old) / xm_new) *100;

	if ( compare < 0)
		b = xm_new;
	else if ( compare > 0)
		a = xm_new;
	else {
		*root = xm_new;
		return error;
	}

	(*it)++;
	
	do {
		xm_old = xm_new;
		xm_new = (a + b) / 2;

		calcPolynomial_fast(p, a, &val1, NULL);
		calcPolynomial_fast(p, xm_new, &val2, NULL);

		compare = val1 * val2;

		error = fabs((xm_new - xm_old) / xm_new) *100;

		if ( compare < 0)
			b = xm_new;
		else if ( compare > 0)
			a = xm_new;
		else {
			*root = xm_new;
			return error;
		}

		(*it)++;

		
	} while ( error > eps && *it < MAXIT);

	*root = xm_new;
	return error;

}


double newtonRaphson (Polynomial p, double x0, double eps,
		   int *it, double *root)
{
	double x_new = x0, x_old, px, dpx, dpx_old, error = 0;
	int criteria1, criteria2, criteria3;

	do{
		x_old = x_new;
		dpx_old = dpx;

		calcPolynomial_fast(p, x_old, &px, &dpx);

		if(fabs(dpx) < DBL_MIN)
			dpx = dpx_old;

		x_new = x_old - px / dpx;
		
		error = fabs(x_old - x_new);
		criteria1 = error > eps;

		calcPolynomial_fast(p, x_new, &px, NULL);
		criteria2 = fabs(px) > eps;

		(*it)++;
		criteria3 = (*it) < MAXIT;

	} while(criteria1 && criteria2 && criteria3);

	*root = x_new;
	return error;
}


double secant (Polynomial p, double x0, double x1, double eps,
	     int *it, double *root)
{
	double x_new = x1, x_old = x0, x_older, px, px_older, px_temp, error;
	int criterion1, criterion2, criterion3;

	do{
		x_older = x_old;
		x_old = x_new;

		calcPolynomial_fast(p, x_old, &px, NULL);

		px_temp = px_older;
		calcPolynomial_fast(p, x_older, &px_older, NULL);

		if(!(fabs(px - px_older) > DBL_MIN)){
			px_older = px_temp;
		}

		x_new = x_old - (px * (x_old - x_older))/(px - px_older);
		
		error = fabs(x_old - x_new);
		criterion1 = error > eps;

		calcPolynomial_fast(p, x_new, &px, NULL);
		criterion2 = fabs(px) > eps;

		(*it)++;

		criterion3 = (*it) < MAXIT;

	}while(criterion1 && criterion2 && criterion3);

	*root = x_new;
	return error;
}


void calcPolynomial_fast(Polynomial p, double x, double *px, double *dpx) {
	double b = 0;
	double c = 0;
	for (int i = p.degree; i > 0; --i) {
		b = b*x + p.p[i];
		c = c*x + b;
	}

	b = b*x + p.p[0];
	*px = b;

	if(dpx){
		*dpx = c;
	}
}


void calcPolynomial_slow(Polynomial p, double x, double *px, double *dpx) {
	
}