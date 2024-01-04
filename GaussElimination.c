#include<stdio.h>

int main()
{
    int i,j,k,n;
    float A[20][20],c,x[10],sum=0.0;
    printf("\tSOLUtioN BY SIMPLE GAUSS METHOD\n");
    printf("\nWhat is the size of the system(n)?\n");
    scanf("%d",&n);
    printf("\nInput coefficients a(i,j) , row-wise, one row on each line\n\n");
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {

            scanf("%f",&A[i][j]);
        }
    }
    printf("\nInput vector\n");
    for(i=1;i<=n;i++)scanf("%f",&A[i][n+1]);
    for(j=1; j<=n; j++) /* loop for the generation of upper triangular matrix*/
    {
        for(i=1; i<=n; i++)
        {
            if(i>j)
            {
                c=A[i][j]/A[j][j];
                for(k=1; k<=n+1; k++)
                {
                    A[i][k]=A[i][k]-c*A[j][k];
                }
            }
        }
    }
    x[n]=A[n][n+1]/A[n][n];
    /* this loop is for backward substitution*/
    for(i=n-1; i>=1; i--)
    {
        sum=0;
        for(j=i+1; j<=n; j++)
        {
            sum=sum+A[i][j]*x[j];
        }
        x[i]=(A[i][n+1]-sum)/A[i][i];
    }
    printf("\nThe solution is: \n");
    for(i=1; i<=n; i++)
    {
        printf("\nx%d=%f\t",i,x[i]); /* x1, x2, x3 are the required solutions*/
    }
    return(0);
}
