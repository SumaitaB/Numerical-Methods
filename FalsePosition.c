/*
        False Position Method
*/
#include <stdio.h>
#define EPS 1e-7

double f( double x ) {
        return ( x*x + x - 2 );
}

void FalsePosition( double x1, double x2 ) {
        int i = 0;
        double x;
        for(i=1; i<=500; i++) {
                x = x1 - ( ( f( x1 ) * ( x2-x1 ) ) / ( f( x2 ) - f( x1 ) ) );
                if( f( x ) * f( x1 ) < 0 ) x2 = x;
                else x1 = x;
        }
        printf("\nRoot = %.6lf\n", x);
        printf("f( %.6lf ) = %.6lf\n", x, f( x ));
}

int main() {
        printf("\nFalse Position Method\n\n");
        printf("Enter the starting values\n");
        double x1, x2;
        scanf("%lf %lf", &x1, &x2);
        if( f( x1 ) * f( x2 ) >= 0.0 ) {
                printf("\nThere is no root in this interval\n");
        }
        else {
                FalsePosition( x1, x2 );
        }
        return 0;
}
