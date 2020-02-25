#include <bits/stdc++.h>

using namespace std;

class Graph
{
    /// n: Number of vertices, m: Number of edges
    int n, m;

    /// graph: G, grapht: Gt (transpose graph)
    vector<int> *graph, *grapht;
    
    /// ft: finish times, st: start times
    vector<int> ft, st;

    /// Visited array for dfs
    vector<bool> vis;

    /// Perform DFS on G to compute start and finish times
    void dfsG(int u);

    /// Computes component by performing DFS on Gt
    void dfsGt(int u, vector<int> &comp);

public:

    /// Constructor for initialising data structures
    Graph(int n, int m);

    /// Add a directed edge from u ~> v
    void addEdge(int u, int v);

    /// Compute all strongly connected components
    vector<vector<int>> computeSCCs(void);
};