/** Implementing Max and Min Binary Heap using Array **/

#include<bits/stdc++.h>
using namespace std;
typedef long long int lln;

void max_heapify(int *a,int i,int heap_size)
{
    int l,r,largest;
    l=2*i;
    r=(2*i)+1;

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

void build_max_heap(int *a,int n)
{
    int heap_size=n;

    for(int i=floor(n/2);i>=1;i--) // for array indexing
    {
        max_heapify(a,i,heap_size);//O(log n)
    }
}

void min_heapify(int *a,int i,int min_heap_size)
{
    int l,r,smallest;
    l=2*i;
    r=2*i+1;

    if(l<=min_heap_size && a[l]<a[i])
        smallest=l;
    else
        smallest=i;

    if(r<=min_heap_size && a[r]<a[smallest])
        smallest=r;

    if(smallest!=i)
    {
        swap(a[i],a[smallest]);
        min_heapify(a,smallest,min_heap_size);
    }

}

void build_min_heap(int *a,int n)
{
    int min_heap_size=n;
    for(int i=floor(n/2);i>=1;i--)
    {
        min_heapify(a,i,min_heap_size);
    }
}


int main()
{
    int n;cin>>n;
    int a[n+1];
    a[0]=INT_MIN;//Just want to start the index from  1
    for(int i=1;i<n+1;i++)
        cin>>a[i];

    build_max_heap(a,n);//O(n)

    cout<<"Elements in the max heap are\n";
    for(int i=1;i<n+1;i++)
        cout<<a[i]<<" ";

    build_min_heap(a,n);


    cout<<"\nElements in the min heap are\n";
    for(int i=1;i<n+1;i++)
        cout<<a[i]<<" ";

    return 0;
}
