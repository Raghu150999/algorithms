#include "scc.hpp"

Kosaraju::Kosaraju(int n, int m)
{
    // Intialization
    this->n = n;
    this->m = m;
    graph = new vector<int>[n+1];
    grapht = new vector<int>[n+1];
    ft.resize(n+1);
    st.resize(n+1);
    vis.resize(n+1);
}

void Kosaraju::addEdge(int u, int v)
{
    graph[u].push_back(v);
    grapht[v].push_back(u);
}

void Kosaraju::dfsG(int u)
{
    static int time = 0;
    time++;
    // start time
    st[u] = time;
    vis[u] = 1;
    for(int &v: graph[u])
        if(!vis[v])
            dfsG(v);
    time++;
    // finish time
    ft[u] = time;
}

void Kosaraju::dfsGt(int u, vector<int> &comp)
{
    vis[u] = 1;
    comp.push_back(u);
    vector<pair<int, int>> tmp;
    for(int &v: grapht[u])
        tmp.push_back({ft[v], v});
    // sort children by decreasing order of finish time
    sort(tmp.begin(), tmp.end(), greater<pair<int, int>>());
    for(auto &p: tmp)
        if(!vis[p.second])
            dfsGt(p.second, comp);
}

vector<vector<int>> Kosaraju::computeSCCs(void)
{
    // compute finish times (graph could be disconnected)
    for(int i = 1; i <= n; i++)
        if(!vis[i])
            dfsG(i);
    vector<pair<int, int>> tmp;
    for(int i = 0; i <= n; i++)
    {
        vis[i] = 0;
        tmp.push_back({ft[i], i});
    }
    sort(tmp.begin(), tmp.end(), greater<pair<int, int>>());
    vector<vector<int>> comps;
    for(int i = 0; i < n; i++)
    {
        int u = tmp[i].second;
        // for each unvisited vertex, find its component
        if(!vis[u])
        {
            vector<int> comp;
            dfsGt(u, comp);
            comps.push_back(comp);
        }
    }
    return comps;
}