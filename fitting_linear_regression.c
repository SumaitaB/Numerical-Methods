#include<stdio.h>
#include<math.h>
#define MAX 10
#define EPS 0.000001
int main()
{
    int i,n;
    float x[10],y[10];
    float sumx,sumy,sumxx,sumxy,xmean,ymean,denom,a,b;
    printf("\n    linear regression \n\n");
    printf("\n Input number of data points,n\n");
    scanf("%d",&n);
    printf("\n Input x and y values\n");
    printf("One set on each line \n");
    for (i=1; i<=n; i++)
    {
        scanf("%f %f",&x[i],&y[i]);
    }
    sumx=0.0;
    sumy=0.0;
    sumxx=0.0;
    sumxy=0.0;
    for(i=1; i<=n; i++)
    {
        sumx=sumx+x[i];
        sumy=sumy+y[i];
        sumxx=sumxx+x[i]*x[i];
        sumxy=sumxy+x[i]*y[i];
    }
    xmean=sumx/n;
    ymean=sumy/n;
    denom=n*sumxx-sumx*sumx;
    if(fabs(denom)>EPS)
    {
        b=(n*sumxy-sumx*sumy)/denom;
        a=ymean-b*xmean;
        printf("\n  Linear regression line y=a+bx\n");
        printf("\nThe coefficients are: \n");
        printf("a = %f \n",a);
        printf("b = %f \n",b);
    }
    else
    {
        printf("\n No solution \n");
    }
}

