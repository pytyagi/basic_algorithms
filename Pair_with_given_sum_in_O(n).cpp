#include<bits/stdc++.h>
using namespace std;
typedef long long int lln;

int main()
{
    cout<<"Enter no of Array Elements\n";
    int n,sum,temp;cin>>n;
    int a[n];

    cout<<"Enter no of Array Elements\n";

    for(int i=0;i<n;i++)
        cin>>a[i];

    cout<<"Sum\n"; cin>>sum;

    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        temp=sum-a[i];
        if(mp.find(temp)!=mp.end())
        {
            cout<<"Pair("<<temp<<","<< a[i]<<")" <<"found at index ["<<mp[temp]<<" ,"<<i<<"]"<<endl;
        }
        mp[a[i]]=i;
    }

    return 0;
}
