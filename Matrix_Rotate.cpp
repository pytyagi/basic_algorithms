#include<bits/stdc++.h>
using namespace std;

typedef long long int lln;

int main()
{
    int n,m;cin>>n>>m;
    int a[n][m];
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>a[i][j];
    }

    //Transpose of matrix

    int c=1;
    for(int i=0;i<n-1;i++)
    {
        for(int j=c;j<m;j++)
            swap(a[i][j],a[j][i]);

        c++;
    }

    //Matrix Rotate by reversing rows
    int col=(m/2)-1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=col;j++)
            swap(a[i][j],a[i][m-j-1]);
    }

    cout<<"Matrix rotation by 90 degree\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<a[i][j]<<" ";
        }
            cout<<"\n";
    }


    return 0;
}
