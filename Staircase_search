/* Staircase Search in Sorted Matrix in O(n+m)*/

#include<iostream>
#include<algorithm>

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
    cout<<"Enter the element to be searched\n";
    int x;cin>>x;

    int r=0,c=m-1,ele,k=0;
    ele=a[r][c];


    while((r<n) && (c>=0))
    {
        ele=a[r][c];
        if(ele<x)
            r++;

        else if(ele>x)
            c--;

        else if((ele)==x)
        {
            k=1;
            break;
        }
    }
    if(k==1)
        cout<<"Element found at(0 based index) row = "<<r<<" column = "<<c<<endl;
    else
        cout<<"Element doesn't exist\n";

        return 0;
}
