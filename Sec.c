
#include<stdio.h>
#include<math.h>
#define EPS 0.000001
#define MAXIT 50
#define F(x) (x)*(x) - 4 * (x) - 10
int cnt;
float root, x1, x2;
int sec(float a, float b)
{
    float x3, f1, f2, err;
    x1 = a;
    x2 = b;
    cnt = 1;

    int c;
    do
    {
        f1 = F(x1);
        f2 = F(x2);
        if(fabs(f1 - f2) <=EPS) return 1;
        x3 = x2 - (f2 * (x2 - x1) / (f2 - f1));
        x1 = x2;
        f1 = f2;
        x2 = x3;
        f2 = F(x3);
        cnt++;
        if(cnt > MAXIT)
        {
            return 2;
        }
    }
    while(fabs(f1 - f2) >= EPS);
    root = x3;
    return 3;
}
int main()
{
    int s = 0;
    float a, b, x1, x2;
    printf("\n");
    printf("F(x) = (x)*(x) - 4 * (x) - 10\n\n");
    printf("SOLUTION BY SECANT METHOD\n\n");
    printf("Input starting with values : ");
    scanf("%f%f",&a,&b);
    printf("\n");
    s = sec(a, b);
    if(s == 1)
    {
        printf("\nDIVISION BY ZERO\n");
        printf("Last x1 = %.6f\n",x1);
        printf("Last x2 = %.6f\n",x2);
        printf("NO. OF ITERATIONS = %d\n\n",cnt - 1);
    }
    else if(s == 2)
    {

        printf("\nNO COVERGENCE IN %d ITERATIONS\n\n",MAXIT);
    }
    else
    {
        printf("\nRoot = %.6f\n",root);
        printf("F(root) = %.6f\n",F(root));
        printf("NO. OF ITERATIONS = %d\n\n",cnt - 1);
    }
    return 0;
}
