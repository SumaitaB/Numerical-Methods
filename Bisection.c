/* Bisection Method */
#include <stdio.h>

float f( float x ) { 
        return ( x*x - 4*x - 10 );
}

void Bisection( float x1, float x2 ) {
        float x;
        int i;
        for(i=1; i<200; i++) {
                x = (x1+x2)/2.0;
                if( f(x1) * f(x) < 0 ) x2 = x;
                else x1 = x;
        }
        printf("\nRoot = %.6lf\n", x);
        printf("For x = %.6lf f(x) = %.6lf\n", x, f( x ));
}

int main() {
        printf("\nBisection Method\n\n");
        printf("Enter the starting values\n");
        float x1, x2;
        scanf("%f %f", &x1, &x2);
        if( f( x1 ) * f( x2 ) >= 0.0 ) {
                printf("\nThere is no root in this interval\n");
        }
        else {
                Bisection( x1, x2 );
        }
        return 0;
}
