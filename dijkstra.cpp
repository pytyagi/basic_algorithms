/* Single source shortest path Dijkstra Algorithm O(VlgV+E)*/
#include<bits/stdc++.h>
using namespace std;
typedef long long int lln;

lln M=1e9+7;
lln INF=2*(1e9);

void add_edge(vector<pair<int,int> >g[],int u,int v,int w,int dir)
{
    if(dir==0)
    {
        g[u].push_back(make_pair(v,w));
        g[v].push_back(make_pair(u,w));
    }
    else if(dir==1)
    {
         g[u].push_back(make_pair(v,w));
    }
}

void dijkstra(vector<pair<int,int> >g[],int v)
{
    vector<int>dis(v+1,INF);
    vector<bool>vis(v+1,false);
    vector<int>parent(v+1,-1);
    cout<<"Enter the source vertex\n";
    int source;cin>>source;

    dis[source]=0;

    multiset<pair<int,int> >q;//multi set as min_priority queue
    q.insert(make_pair(0,source));// Source vertex dis=0

    multiset<pair<int,int> >::iterator it;
    while(!q.empty())
    {
        it=q.begin();//Extracting the min from queue
        int vx,wt;
        vx=it->second;

        q.erase(q.begin());
        if(vis[vx]==false)
        {
            vis[vx]=true;
            for(int i=0;i<g[vx].size();i++)
            {
                int neighbr=g[vx][i].first,w=g[vx][i].second;
                if(dis[neighbr]>dis[vx]+w)
                {
                    dis[neighbr]=dis[vx]+w;
                    parent[neighbr]=vx;
                }
                q.insert(make_pair(dis[neighbr],neighbr));
            }
        }
    }
    cout<<"Shortest Distance of each vertex from "<<source<<" is\n";

    for(int i=1;i<v+1;i++)
        cout<<dis[i]<<" ";
    cout<<endl;



}

int main()
{
    int V,E,u,v,w,dir;
    cout<<"Enter the no of Nodes\n";
    cin>>V;

    cout<<"Enter the no of Edges\n";
    cin>>E;

    cout<<"Press(1) for directed graph and press (0) for undirected\n";
    cin>>dir;

    vector<pair<int,int> >g[V+1];

    for(int i=1;i<=E;i++)
    {
        cin>>u>>v>>w;
        add_edge(g,u,v,w,dir);
    }

    dijkstra(g,V);

    return 0;
}
/*
Test Case
1(directed)

1
2
10

1
3
3

2
4
2

2
3
4

3
2
1

3
4
8

3
5
2

4
5
9

5
4
7
*/
