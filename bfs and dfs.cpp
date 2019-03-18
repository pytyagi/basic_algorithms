/** BFS and DFS Implementation**/

#include<bits/stdc++.h>
using namespace std;

typedef long long int lln;

void add_edge(vector<pair<int,int> >g[],int u,int v,int w)
{
    g[u].push_back(make_pair(v,w));
    g[v].push_back(make_pair(u,w));

}
void bfs(vector<pair<int,int> >g[],int V)
{
    queue<int>q;
    cout<<"Enter the starting vertex for bfs\n";
    int s,vx;cin>>s;
    q.push(s);

    int dis[V+1]={0};

    vector<string>color(V+1,"white");

    int parent[V+1]={0};

    dis[s]=0;
    color[s]="grey";
    parent[s]=-1;// no parent
    while(!q.empty())
    {
        vx=q.front();
        q.pop();

        cout<<vx<<" ";

        for(int i=0;i<g[vx].size();i++)
        {
            if(color[g[vx][i].first]=="white")
            {
                color[g[vx][i].first]="grey";
                parent[g[vx][i].first]=vx;
                dis[g[vx][i].first]=dis[vx]+1;
                q.push(g[vx][i].first);

            }
        }
        color[vx]="black";
    }

    cout<<endl;
    for(int k=1;k<=V;k++)
        cout<<dis[k]<<" ";
    cout<<endl;
}
void dfs(vector<pair<int,int> >g[],int V)
{
    cout<<"Enter the starting vertex\n";
    int st,vx;cin>>st;
    vector<string>color(V+1,"white");
    stack<int>s;
    s.push(st);
    color[st]="grey";
    while(!s.empty())
    {
        vx=s.top();
        cout<<vx<<" ";
        s.pop();

        if(color[vx]=="white")
        {
            color[vx]="grey";
        }

        for(int i=0;i<g[vx].size();i++)
        {
            if(color[g[vx][i].first] == "white")
            {
                color[g[vx][i].first]="grey";
                s.push(g[vx][i].first);
            }
        }
       // color[vx]="black";
        //st.pop();
    }
}
vector<int>visited;
void initialize(int V)
{
    for(int i=0;i<V+1;i++)
        visited.push_back(0);

}
void dfs_recursive(vector<pair<int,int> >G[],int V,int S)
{
    visited[S]=1;
    cout<<S<<" ";
    for(int i=0;i<G[S].size();i++)
    {
        if(visited[G[S][i].first]==0)
        {
            dfs_recursive(G,V,G[S][i].first);
        }
    }
}

void print(vector<pair<int,int> >g[],int V)
{
    for(int u=0;u<V+1;u++)
    {
        int c=0;
        cout<<"Node "<<u<<" makes an edge with: \n";
        for(int v=0;v<g[u].size();v++)
        {
            c++;
            cout<<"Node "<<g[u][v].first<<" with weight "<<g[u][v].second<<endl;
        }
        if(c==0)
            cout<<"None"<<endl;
    }
}
int main()
{
    int V,E,u,v,w;
    cout<<"Enter the no of vertices\n";
    cin>>V;
    cout<<"Enter the no of Edges\n";
    cin>>E;

    vector<pair<int,int> >G[V+1];
    cout<<"Enter the edge(u-v) and it's weight\n";
    for(int i=1;i<=E;i++)
    {
        cin>>u>>v>>w;
        add_edge(G,u,v,w);
    }
    //print(G,V);
   // bfs(G,V);
    //dfs_iterative(G,V);
    cout<<"Enter the starting vertex for DFS\n";
    initialize(V);
    int S;cin>>S;
    dfs_recursive(G,V,S);

    return 0;
}
