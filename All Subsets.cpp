/**Power Set**/
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int set_size;cin>>set_size; //Denotes number of elements in the set
    int a[set_size]; // Stores all elements of a set
    for(int i=0;i<set_size;i++)
        cin>>a[i];

    for(int i=0;i<(1<<set_size);i++) //(1<<set_size) is actually 2^set_size as we have total this much of elements in a Power_set
    {

        for(int j=0;j<set_size;j++)
        {
            if((i)&(1<<j))//checking the set bit if it is 1 then it is included in the Power_set
            {
                cout<<a[j]<<" ";
            }

        }
        cout<<"\n";
    }


    return 0;
}
