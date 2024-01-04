
#include<stdio.h>
#include<math.h>
#define EPS 0.000001
#define F(x) (x)*(x) - (x) - 2
int cnt;
float root;
int fal(float a, float b)
{
    float x1, x2, x0, f0, f1, f2;
    x1 = a;
    x2 = b;
    f1 = F(x1);
    f2 = F(x2);
    if(f1 * f2 > 0)
    {
        return 0;
    }
    cnt = 1;
    while(1)
    {
        x0 = x1 - (f1 * (x2 - x1) / (f2 - f1));
        f0 = F(x0);
        if(f1 * f0 < 0)
        {
            x2 = x0;
            f2 = f0;
        }
        else
        {
            x1 = x0;
            f1 = f0;
        }

        if(fabs(f0) <EPS)
        {
            break;
        }
        else
        {
            cnt++;
        }
    }
    root=x0;
    return 1;
}
int main()
{
    int s;
    float a, b;
    printf("\nF(x) = (x)*(x) - (x) - 2\n\n");
    printf("SOLUTION BY FALSE POSITION METHOD\n\n");
    printf("Input starting with values : ");
    scanf("%f %f",&a,&b);
    printf("\n");
    s = fal(a, b);
    if(s == 0)
    {
        printf("\nStarting points do not bracket any root\n\n");
    }
    else
    {
        printf("\nRoot = %.6f\n",root);
        printf("F(root) = %.6f\n",F(root));
        printf("\nNO. OF ITERATIONS = %d\n",cnt - 1);
    }
    return 0;
}
