#include <bits/stdc++.h>
using namespace std;
int main()
{
    long double x,err,fx;
    long long int n,i,j,flag;
    cout<<"\nEnter number of equations : ";
    cin>>n;
    cout<<endl<<endl;
    long double mat[n+2][n+2], arr1[n+2], arr2[n+2];
    for(i=1; i<=n; i++)
    {
        cout<<"Enter "<<n<<" coefficients and the value of equation "<<i<<" one by one - "<<endl<<endl;
        for(j=1; j<=n+1; j++)
        {
            cin>>mat[i][j];
        }
        cout<<endl;
    }
    cout<<"Enter "<<n<<" initial approximations one by one - "<<endl<<endl;
    for(i=1; i<=n; i++)
    {
        cin>>arr1[i];
    }
    cout<<endl;
    cout<<"Enter tolerable error - ";
    cin>>err;
    cout<<endl<<endl;
    do
    {
        flag = 0;
        for(i=1; i<=n; i++)
        {
            x = 0.0;
            for(j=1; j<=n; j++)
            {
                if(i!=j)
                {
                    x += (arr1[j]*mat[i][j]);
                }
            }
            fx = (mat[i][n+1]-x)/mat[i][i];
            arr2[i] = fx;
        }
        for(i=1; i<=n; i++)
        {
            x = 0.0;
            for(j=1; j<=n; j++)
            {
                x += (arr2[j]*mat[i][j]);
            }
            if(fabs(x-mat[i][n+1])>err)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            cout<<"The roots of the given system of linear equations -"<<endl;
            for(i=1; i<=n; i++)
            {
                cout<<"X"<<i<<" : "<<arr2[i]<<endl;
            }
        }
        else
        {
            for(i=1; i<=n; i++)arr1[i] = arr2[i];
        }
    }
    while(flag==1);
}
