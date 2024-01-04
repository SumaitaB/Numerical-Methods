/* Secant Method */
#include <stdio.h>
#include <math.h>
#define eps 1e-10

double f( double x ) {
        return ( x*x - 4*x - 10 );
}
void Secant( double x1, double x2 ) {
        double x3;
        int i;
        for(i=1; i<=300; i++) {
                x3 = x2 - f(x2)*( ( x2 - x1 ) / ( f(x2) - f(x1) ) );
                x1 = x2, x2 = x3;
                if( fabs( (x2-x1)/x2 ) < eps ) {
                        printf("\nRoot = %.6lf\n", x3);
                        printf("Number of iterations %d\n", i);
                        break;
                }
        }
}

int main() {
        printf("\nSecant Method\n\n");
        printf("Enter the initial estimates\n");
        double x1, x2;
        scanf("%lf %lf", &x1, &x2);
        Secant( x1, x2 );
        return 0;
}
