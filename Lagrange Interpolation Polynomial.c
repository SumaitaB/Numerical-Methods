
#include<stdio.h>
#define MAX 10
int main()
{
    int n,i,j;
    float x[MAX], f[MAX], fp, lf, sum, xp;
    printf("\nInput number of data points, n : ");
    scanf("%d",&n);
    printf("\nInput data points x(i) and values f(i) [one set per line]\n\n");
    for(i = 1; i <= n; i++)
    {
        scanf("%f %f",&x[i],&f[i]);
    }
    printf("\nInput x at which interpolation is required : ");
    scanf("%f",&xp);
    printf("\n\n");
    sum = 0.0;
    for(i = 1; i <= n; i++)
    {
        lf = 1.0;
        for(j = 1; j <= n; j++)
        {
            if(i != j) lf = lf * (xp - x[j]) / (x[i] - x[j]);
        }
        sum += (lf * f[i]);
    }
    fp = sum;
    printf("\tLAGRAGIAN INTERPOLATION\t\n\n");
    printf("Interpolated function value at x = %.6f is %.6f\n",xp,fp);
}
