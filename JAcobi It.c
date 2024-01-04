
#include<stdio.h>
#include<math.h>
#define EPS 0.000001
#define MAXIT 200

void Jacobi(int n,float a[10][10],float b[10], float x[10], int
            *count, int *status)
{
    int i,j,key;
    float sum, x0[10];

    for(i=1; i<=n; i++)
        x0[i]=b[i]/(a[i][i]*1.0);

    *count=1;
    while(1)
    {
        key=0;
        /*Computing values of x[i]
        --------------------------------------------
        x1=(b1-a12 x2-a13 x3-......a1n xn)/ a11
        x2=(b2-a21 x1-a23 x3-......a2n xn)/a22
        */
        for(i=1; i<=n; i++)
        {
            sum=b[i];
            for(j=1; j<=n; j++)
            {
                if(i==j)
                    continue;
                sum=sum-a[i][j]*x0[j];
            }
            x[i]=sum/(a[i][i]*1.0);
            if(key==0)
            {
//Testing for accuracy
                if(fabs((x[i]-x0[i])/x[i])>EPS)
                    key=1;
            }
        }

        if(key==1)
        {
            if(*count==MAXIT)
            {
                *status=2;
                return;
            }

            else
            {
                *status=1;
                for(i=1; i<=n; i++)
                {
                    x0[i]=x[i];
                }
            }
            *count=*count+1;
        }
        else
        {
            break;
        }
    }
    return;
}
int main()
{
    int i,j,n,count,status;
    float a[10][10],b[10],x[10];
    printf("\nSOLUTION BY JACOBI ITERATION \n");
    printf("------------------------------------");
    printf("\n What is the size of n of the system? \n");
    scanf("%d",&n);
    printf("\nInput coefficients a(i,j), row by row \n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            scanf("%f",&a[i][j]);
        }
    }
    printf("\nInput vector b\n");
    for(i=1; i<=n; i++)
    {
        scanf("%f",&b[i]);
    }
    Jacobi(n,a,b,x,&count,&status);
    if(status==2)
    {
        printf("\nNo convergence in %d iterations",MAXIT);
        printf("\n\n");
    }
    else

    {
        printf("\nSOLUTION VECTOR X\n\n");
        for(i=1; i<=n; i++)
        {
            printf("X%d = %.6f\n",i,x[i]);
        }
        printf("\n\nIterations = %d ",count);
    }
    return 0;
}
