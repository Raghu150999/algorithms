#include "ff.hpp"

FordFulkerson::FordFulkerson(int n, int s, int t)
{
    this->n = n;
    this->s = s;
    this->t = t;
    graph = new vector<int>[n+5];
    capacity = vector<vector<int>> (n+5, vector<int> (n+5, 0));
    fgraph = vector<vector<int>> (n+5, vector<int> (n+5, 0));
    rgraph = vector<vector<int>> (n+5, vector<int> (n+5, 0));
    parent = vector<int> (n+5);
    vis = vector<bool> (n+5, 0);
    bottleNeck = vector<int> (n+5);
}

bool FordFulkerson::addEdge(int u, int v, int c)
{
    // handle multi-edge graphs
    if(capacity[u][v] <= 0)
    {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    capacity[u][v] += c;
    rgraph[u][v] += c;
    return true;
}

int FordFulkerson::getFlow(int u, int v)
{
    return fgraph[u][v];
}

int FordFulkerson::getResidualFlow(int u, int v)
{
    return rgraph[u][v];
}

int FordFulkerson::getCapacity(int u, int v)
{
    return capacity[u][v];
}

void FordFulkerson::incrementFlow(int u, int v, int flow)
{
    rgraph[u][v] -= flow;
    rgraph[v][u] += flow;
    // (u, v) is a forward edge
    if(capacity[u][v])
        fgraph[u][v] += flow;
    else
        fgraph[v][u] -= flow;
}

void FordFulkerson::clearVis()
{
    for(int i = 0; i <= n+4; i++)
        vis[i] = 0;
}

bool FordFulkerson::augument()
{
    clearVis();
    queue<int> q;
    q.push(s);
    // init to infinity
    bottleNeck[s] = 1e9;
    parent[s] = s;
    vis[s] = true;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int &v: graph[u])
        {
            if(vis[v] || rgraph[u][v] <= 0)
                continue;
            q.push(v);
            vis[v] = true;
            parent[v] = u;
            bottleNeck[v] = min(bottleNeck[u], rgraph[u][v]);
        }
    }
    // no augument path found
    if(!vis[t])
        return false;
    // update flows
    int bottleneck = bottleNeck[t];
    int u = parent[t], v = t;
    while(u != v)
    {
        incrementFlow(u, v, bottleneck);
        v = u;
        u = parent[u];
    }
    return true;
}

int FordFulkerson::getMaxFlow()
{
    // perform augument steps as long as possible
    while(augument());
    // compute max flow
    int maxFlow = 0;
    for(int &v: graph[s])
        maxFlow += fgraph[s][v];
    return maxFlow;
}

vector<pair<int, int>> FordFulkerson::getMinSTCut()
{
    // run ford fulkerson
    getMaxFlow();

    clearVis();
    queue<int> q;
    q.push(s);
    vis[s] = true;
    vector<pair<int, int>> mincut;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int &v: graph[u])
        {
            if(vis[v])
                continue;
            if(rgraph[u][v] == 0)
            {
                // report all edges from A to B
                if(capacity[u][v])
                    mincut.push_back({u, v});
                continue;
            }
            q.push(v);
            vis[v] = true;
        }
    }
    return mincut;    
}