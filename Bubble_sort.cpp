/*  Worst case descending order(for asc sort ) O(N^2)
    Best Case Ascending order O(N) using flag variable;
*/

#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(0)
using namespace std;
typedef long long lln;

void print(int *a,int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

    cout<<endl;
}
void bubblesort(int *a,int n)
{
    int count_swap=0;
    for(int k=1; k<=n-1; k++)
    {
        int flag=0;
        for(int j=0;j<=n-k-1;j++)
        {
            if(a[j]>a[j+1])
            {
                flag=1;
                swap(a[j],a[j+1]);
            }
        }
        if(flag==0)
            break;
    }
    cout<<"Total swaps are "<<count_swap<<endl;
}
int main()
{
    int n;cin>>n;
    int *a=(int*)malloc(n*sizeof(int));
    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<"Before Sorting\n";
    print(a,n);

    bubblesort(a,n);

    cout<<"After Sorting\n";
    print(a,n);

    return 0;
}
