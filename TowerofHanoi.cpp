#include<bits/stdc++.h>
using namespace std;
typedef long long lln;

void towerofhanoi(int n,char src,char desc,char helper)
{
    if(n==0)
        return ;

    towerofhanoi(n-1,src,helper,desc);
    cout<<"Move "<<n<<" disk from "<<src<<" to "<<desc<<endl;
    towerofhanoi(n-1,helper,desc,src);

}

int main()
{
    int n;cin>>n;
    towerofhanoi(n,'A','C','B');

    return 0;
}
