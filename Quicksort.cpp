#include<bits/stdc++.h>
using namespace std;
typedef long long lln;

void print(int *a,int n)
{
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
}

int partition_array(int *a,int s,int e)
{
    int p = a[e];

    int i=s-1;// To denote the last index of region having elements less than pivot

    for(int j = s; j < e; j++)
    {
        if(a[j] <= p)
        {
            i++;
            swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[e]);
    return i+1;
}

void quicksort(int *a,int s,int e,int n=7)
{
    if(s<=e)
    {
        int pivot_index = partition_array(a,s,e);
        quicksort(a,s,pivot_index-1);
        quicksort(a,pivot_index+1,e);
    }
}



int main()
{
    int n;cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<"Before Sorting array is: ";
    print(a,n);

    quicksort(a,0,n-1);

    cout<<"\nAfter Sorting array is: ";
    print(a,n);

    return 0;
}

