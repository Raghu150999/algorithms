#include <bits/stdc++.h>

using namespace std;

class FordFulkerson
{
    /// n: Number of vertices m: Number of edges
    int n, m;
    
    /// s: source, t: sink
    int s, t;

    /// adjacency for network graph
    vector<int> *graph;

    /// graph: G, capacity[u][v] = capacity
    vector<vector<int>> capacity;

    /// flow graph, fgraph[u][v] = flow
    vector<vector<int>> fgraph;

    /// residual graph, rgraph[u][v] = residual flow
    vector<vector<int>> rgraph;

    /// parent array, helper data structure
    vector<int> parent;

    /// helper visited array
    vector<bool> vis;

    /// helper to maintain bottle neck
    vector<int> bottleNeck;

    /// performs one augument step. returns false if no path available
    bool augument();

    /// increment flow if forward edge, decrement otherwise
    void incrementFlow(int u, int v, int flow);

    /// clear visited array
    void clearVis();

public:

    /// Constructor for initialising memory for graph
    FordFulkerson(int n, int s, int t);

    /// Function to add direct edge (u, v) with capactiy c, returns false if invalid edge added
    bool addEdge(int u, int v, int c);

    /// runs ford-fulkerson and returns the max flow (side effect: updates the flow graph)
    int getMaxFlow();

    /// get flow for (u, v)
    int getFlow(int u, int v);

    /// get capacity for (u, v)
    int getCapacity(int u, int v);

    /// get residual flow for (u, v)
    int getResidualFlow(int u, int v);

    /// get min s-t cut. returns edges from A -> B
    vector<pair<int, int>> getMinSTCut();
};