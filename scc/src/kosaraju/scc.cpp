#include "kosaraju/scc.hpp"

Kosaraju::Kosaraju(int n, int m)
{
    // Intialization
    this->n = n;
    this->m = m;
    graph = new vector<int>[n+1];
    grapht = new vector<int>[n+1];
    vis.resize(n+1);
}

void Kosaraju::addEdge(int u, int v)
{
    graph[u].push_back(v);
    grapht[v].push_back(u);
}

void Kosaraju::dfsG(int u)
{
    vis[u] = 1;
    for(int &v: graph[u])
        if(!vis[v])
            dfsG(v);
    st.push(u);
}

void Kosaraju::dfsGt(int u, vector<int> &comp)
{
    vis[u] = 1;
    comp.push_back(u);
    for(int &v: grapht[u])
        if(!vis[v])
            dfsGt(v, comp);
}

vector<vector<int>> Kosaraju::computeSCCs(void)
{
    // compute finish time order (graph could be disconnected)
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            dfsG(i);
    for(int i = 1; i <= n; i++)
        vis[i] = 0;
    vector<vector<int>> comps;
    while(!st.empty()) 
    {
        int u = st.top();
        st.pop();
        if(!vis[u])
        {
            vector<int> comp;
            dfsGt(u, comp);
            comps.push_back(comp);
        }
    }
    return comps;
}