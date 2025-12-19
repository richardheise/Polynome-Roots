#include <stdio.h>
#include <math.h>

#include "utils.h"
#include "funcaoZero.h"

int main () {

    // leitura de dados
    Polynomial input;
    double x = 0, x_initial = 0, x_final = 0;
    int iterations = 0;

    printf("Enter the degree of the polynomial: ");
    scanf("%d", &input.degree);

    input.p = malloc(sizeof(double) * (input.degree+1));

    for (int i = input.degree; i >= 0; i--) {
      printf("Enter the value of coefficient %d\n", input.degree-i+1);
      scanf("%lf", &input.p[i]);
    }

    printf("Enter the initial x of the interval: ");
    scanf("%lf", &x_initial);

    printf("Enter the final x for the interval: ");
    scanf("%lf", &x_final);

    // ---------------------------------------------------------------------------------- //

    double time;

    // ---------------------------------------------------------------------------------- //

    printf("\n===================================================================\n");
    printf("Bisection method execution summary\n\n");

    time = timestamp();
    printf("The error is: %.15lf\n", bisection(input, x_initial, x_final, EPS, &iterations, &x) );
    printf("root: %.15lf\n", x);
    printf("iterations: %d\n", iterations);
    time = timestamp() - time;
    printf("Duration: %lf\n\n\n", time);
    iterations = 0;


    // ---------------------------------------------------------------------------------- //

    printf("\n===================================================================\n");
    printf("Newton-Raphson method execution summary\n\n");
    
    time = timestamp();
    printf("The error is: %.15lf\n", newtonRaphson(input, x_initial, EPS, &iterations, &x) );
    printf("root: %.15lf\n", x);
    printf("iterations: %d\n\n\n", iterations);
    time = timestamp() - time;
    printf("Duration: %lf\n\n\n", time);
    iterations = 0;

    // ---------------------------------------------------------------------------------- //

    printf("\n===================================================================\n");
    printf("Secant method execution summary\n\n");

    time = timestamp();
    printf("The error is: %.15lf\n", secant(input, x_initial, x_final, EPS, &iterations, &x) );
    printf("root: %.15lf\n", x);
    printf("iterations: %d\n\n\n", iterations);
    time = timestamp() - time;
    printf("Duration: %lf\n\n\n", time);

    printf("\n===================================================================\n");

    // ---------------------------------------------------------------------------------- //

    return 0;

}