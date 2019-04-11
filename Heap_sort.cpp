/** Heapsort(Ascending order) requires Max heap and
    Descending Order requires Min Heap **/

#include<bits/stdc++.h>
using namespace std;
typedef long long int lln;

const lln M=1e9+7;

lln power(lln a,lln b)
{
    lln ans=1;
    while(b)
    {
        if(b&1)
        {
            ans=ans*a;
            b--;
        }
        else
        {
            a=a*a;
            b/=2;
        }
    }
    return ans;
}

void max_heapify(int *a,int i,int heap_size)
{
    int l,r,largest;
    l=2*i;
    r=2*i+1;

    if(l<=heap_size && a[l]>a[i])
        largest=l;
    else
        largest=i;

    if(r<=heap_size && a[r]>a[largest])
        largest=r;

    if(largest!=i)
    {
        swap(a[i],a[largest]);
        max_heapify(a,largest,heap_size);
    }

}

void build_max_heap(int *a,int n) //O(n)
{
    int heap_size=n;
    for(int i=floor(n/2);i>=1;i--)
    {
        max_heapify(a,i,heap_size);
    }

}

void heap_sort(int *a,int n) //O(nlogn)
{
    int heap_size=n,t0=0;
    for(int i=n;i>=2;i--)
    {
        swap(a[1],a[i]);
        heap_size-=1;
        max_heapify(a,1,heap_size);
    }
}


int main()
{
    int n;cin>>n;
    int a[n+1];
    a[0]=INT_MIN;
    for(int i=1;i<=n;i++)
        cin>>a[i];

    build_max_heap(a,n);

    cout<<"Element after building the heap\n";
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";

    cout<<endl;
    heap_sort(a,n);

    cout<<"After Heap Sort(Ascending) Elements are\n";
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";

    return 0;
}
/*
Input
8 // Array Size

3
5
2
7
11
4
1
19

*/
