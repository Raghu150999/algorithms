#include "dcsc/scc.hpp"

DCSC::DCSC(int n, int m)
{
    // Initialization
    this->n = n;
    this->m = m;
    graph = new vector<int>[n+1];
    grapht = new vector<int>[n+1];
    cno.resize(n+1, 1);
    vis.resize(n+1, false);
    vist.resize(n+1, false);
    srand(time(NULL));
}

void DCSC::addEdge(int u, int v)
{
    graph[u].push_back(v);
    grapht[v].push_back(u);
}

void DCSC::dfsG(int u, int currcno, vector<bool> &vis)
{
    vis[u] = true;
    // For all children which are part of the induced graph and not already visited perform DFS recursively
    for(int &v: graph[u])
    {
        if(cno[v] != currcno || vis[v])
            continue;
        dfsG(v, currcno, vis);
    }
}

void DCSC::dfsGt(int u, int currcno, vector<bool> &vis)
{
    vis[u] = true;
    // For all children which are part of the induced graph and not already visited perform DFS recursively
    for(int &v: grapht[u])
    {
        if(cno[v] != currcno || vis[v])
            continue;
        dfsGt(v, currcno, vis);
    }
}

void DCSC::dcsc(int currcno, vector<int> &nodes, vector<vector<int>> &comps)
{
    if(nodes.size() == 0)
        return;
    // Component of one node
    if(nodes.size() == 1)
    {
        comps.push_back(nodes);
        return;
    }
    // Randomly select next vertex from the induced graph (current subgraph)
    int idx = rand() % nodes.size();
    int v = nodes[idx];

    // Identify predecessors and successors of v
    dfsG(v, currcno, vis);
    dfsGt(v, currcno, vist);
    vector<int> scc, pmc, dmc, rem;
    int cp = 3 * currcno, cd = 3 * currcno + 1, cr = 3 * currcno + 2;
    for(int &u: nodes)
    {
        // Intersection nodes
        if(vis[u] && vist[u])
        {
            scc.push_back(u);
            continue;
        }
        // Descendants - SCC
        else if(vis[u] && !vist[u])
        {
            dmc.push_back(u);
            cno[u] = cd;
        }
        // Predecessor - SCC
        else if(!vis[u] && vist[u])
        {
            pmc.push_back(u);
            cno[u] = cp;
        }
        // Remaining
        else
        {
            rem.push_back(u);
            cno[u] = cr;
        }
        vis[u] = false;
        vist[u] = false;
    }
    nodes.clear();

    // Recursively solve for the subgraphs
    dcsc(cp, pmc, comps);
    dcsc(cd, dmc, comps);
    dcsc(cr, rem, comps);
    comps.push_back(scc);
}

vector<vector<int>> DCSC::computeSCCs(void)
{
    // All SCCs
    vector<vector<int>> comps;

    // Initial induced graph = G
    vector<int> nodes;
    for(int i = 1; i <= n; i++)
        nodes.push_back(i);
    
    // Compute all SCCs
    dcsc(1, nodes, comps);
    return comps;
}
