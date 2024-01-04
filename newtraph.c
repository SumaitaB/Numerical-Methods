#include<stdio.h>
#include<math.h>
#define EPS 0.000001
#define MAXIT 20
#define F(x) (x)*(x)-3*(x)+2
#define FD(x) 2*x-3
void New_Raph(float x0, float fx, float fdx, float xn, int count)
{
    count=1;
    while(1)
    {
        fx=F(x0);
        fdx=FD(x0);
        xn= x0-(fx / fdx);
        if((fabs(xn-x0)/ xn) <EPS)
        {
            printf("Root = %f\n",xn);
            printf("Function Value = %f\n",F(xn));
            printf("Number of Iterations = %d\n",count);
            break;
        }
        else
        {
            x0 = xn;
            count=count+1;
            if(count<MAXIT)
            {
                continue;
            }
            else
            {
                printf("SOLUTION DOES NOT CONVERGE\n");
                printf("IN %d ITERATIONS\n",MAXIT);
            }
        }
    }
}
int main()
{
    int count;
    float x0,xn,fx,fdx;
    printf("The function is: x^2 - 3x +2\n");
    printf("Function derivative of first order is: 2x-3\n\n");
    printf("Input Initial value of x\n");
    scanf("%f",&x0);
    printf("\n");
    printf("SOLUTION BY NEWTON RAPHSON METHOD\n");
    printf("-------------------------------------\n");
    New_Raph(x0,fx,fdx,xn,count);
}

