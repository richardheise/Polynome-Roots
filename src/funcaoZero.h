#ifndef __ZEROFUNCAO_H__
#define __ZEROFUNCAO_H__

#include <float.h>

// Aproximação aceitável como valor zero
#define ZERO DBL_EPSILON

// Parâmetros para teste de convergência
#define MAXIT 500
#define EPS 1.0e-8

typedef struct {
  double *p;
  int degree;
} Polynomial;

// Methods
double bisection (Polynomial p, double a, double b, double eps, int *it, double *root);
double newtonRaphson (Polynomial p, double x0, double eps, int *it, double *root);
double secant (Polynomial p, double x0, double x1, double eps, int *it, double *root);

// Polynomial Calculation
void calcPolynomial_fast(Polynomial p, double x, double *px, double *dpx );
void calcPolynomial_slow(Polynomial p, double x, double *px, double *dpx );

#endif // __ZEROFUNCAO_H__