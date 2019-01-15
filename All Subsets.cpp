#include<bits/stdc++.h>

using namespace std;

int main()
{
    char a[]={'a','b','c','d'};
    int sz=4;
    for(int i=0;i<(1<<sz);i++)
    {

        for(int j=0;j<4;j++)
        {
            if((i)&(1<<j))//checking the set bit
            {
                cout<<a[j]<<" ";
            }

        }
        cout<<"\n";
    }


    return 0;
}
