/* Cycle Detection in Undirected Graph O(V+E)*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int lln;

class graph
{
    int V;
    unordered_map<int,list<int> >adjlist;
    public:
    graph(int v)
    {
        V=v;
    }
    void addedge(int u,int v,bool bidir=true)
    {
        adjlist[u].push_back(v);
        if(bidir)
            adjlist[v].push_back(u);
    }
    void print()
    {
        for(auto i:adjlist)
        {
            cout<<i.first<<"th list -> ";
            for(auto x:adjlist[i.first])
                 cout<<x<<" ";

            cout<<"\n";
        }
        cout<<"\n";
    }
    bool iscyclic(int src)
    {
        unordered_map<int,bool>visited;
        unordered_map<int,int>parent;

        queue<int>q;
        q.push(src);
        visited[src]=true;
        parent[src]=src;

        int vx;
        while(!q.empty())
        {
            vx=q.front();
            q.pop();

            for(auto neighbour:adjlist[vx])
            {
                if(visited[neighbour]==true && parent[vx]!=neighbour)
                    return true;

                else if(!visited[neighbour])
                {
                    q.push(neighbour);
                    visited[neighbour]=true;
                    parent[neighbour]=vx;
                }
            }
        }
        return false;
    }
};

int main()
{
    int n,e,u,v;
    cin>>n>>e;
    graph g(n);
    for(int i=0;i<e;i++)
    {
        cin>>u>>v;
        g.addedge(u,v,true);
    }
    g.print();
    if(g.iscyclic(0))
        cout<<"Cyclic\n";
    else
        cout<<"Non-Cyclic\n";


    return 0;
}
