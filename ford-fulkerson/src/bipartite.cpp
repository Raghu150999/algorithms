#include "bipartite.hpp"

Bipartite::Bipartite(int n)
{
    // dummy source 0, dummy sink n+1
    ff = new FordFulkerson(n, 0, n+1);
    vis  = vector<bool> (n+2, 0);
    this->n = n;
}

void Bipartite::addEdge(int u, int v)
{
    // add edges with capacity 1
    ff->addEdge(u, v, 1);
    if(!vis[u])
        sA.push_back(u);
    vis[u] = 1;
    if(!vis[v])
        sB.push_back(v);
    vis[v] = 1;
    edges.push_back({u, v});
}

vector<pair<int, int>> Bipartite::getMaxMatch()
{
    for(int &v: sA)
        ff->addEdge(0, v, 1);
    for(int &v: sB)
        ff->addEdge(v, n+1, 1);
    int flow = ff->getMaxFlow();
    vector<pair<int, int>> matching;
    for(auto &p: edges)
        if(ff->getFlow(p.first, p.second))
            matching.push_back(p);
    return matching;
}