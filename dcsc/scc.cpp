#include "scc.hpp"

Graph::Graph(int n, int m)
{
    this->n = n;
    this->m = m;
    graph = new vector<int>[n+1];
    grapht = new vector<int>[n+1];
    cno.resize(n+1, 1);
    vis.resize(n+1, false);
    vist.resize(n+1, false);
    srand(time(NULL));
}

void Graph::addEdge(int u, int v)
{
    graph[u].push_back(v);
    grapht[v].push_back(u);
}

void Graph::dfsG(int u, int currcno, vector<bool> &vis)
{
    vis[u] = true;
    for(int &v: graph[u])
    {
        if(cno[v] != currcno || vis[v])
            continue;
        dfsG(v, currcno, vis);
    }
}

void Graph::dfsGt(int u, int currcno, vector<bool> &vis)
{
    vis[u] = true;
    for(int &v: grapht[u])
    {
        if(cno[v] != currcno || vis[v])
            continue;
        dfsGt(v, currcno, vis);
    }
}

void Graph::dcsc(int currcno, vector<int> &nodes, vector<vector<int>> &comps)
{
    if(nodes.size() == 0)
        return;
    if(nodes.size() == 1)
    {
        comps.push_back(nodes);
        return;
    }
    int idx = rand() % nodes.size();
    int v = nodes[idx];
    dfsG(v, currcno, vis);
    dfsGt(v, currcno, vist);
    vector<int> scc, pmc, dmc, rem;
    int cp = 3 * currcno, cd = 3 * currcno + 1, cr = 3 * currcno + 2;
    for(int &u: nodes)
    {
        /// Intersection nodes
        if(vis[u] && vist[u])
        {
            scc.push_back(u);
            continue;
        }
        /// Descendants / SCC
        else if(vis[u] && !vist[u])
        {
            dmc.push_back(u);
            cno[u] = cd;
        }
        /// Predecessor / SCC
        else if(!vis[u] && vist[u])
        {
            pmc.push_back(u);
            cno[u] = cp;
        }
        /// Remaining
        else
        {
            rem.push_back(u);
            cno[u] = cr;
        }
        vis[u] = false;
        vist[u] = false;
    }
    nodes.clear();
    dcsc(cp, pmc, comps);
    dcsc(cd, dmc, comps);
    dcsc(cr, rem, comps);
    comps.push_back(scc);
}

vector<vector<int>> Graph::computeSCCs(void)
{
    vector<vector<int>> comps;
    vector<int> nodes;
    for(int i = 1; i <= n; i++)
        nodes.push_back(i);
    dcsc(1, nodes, comps);
    return comps;
}