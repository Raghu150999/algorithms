#include <bits/stdc++.h>
#include "ff.hpp"

using namespace std;

class Bipartite
{
    /// use ford-fulkerson for finding max matching
    FordFulkerson *ff;

    /// number of vertices
    int n;

    /// set A and B of biparite graph
    vector<int> sA, sB;

    /// edges in biparite graph
    vector<pair<int, int>> edges;
    
    /// vis array
    vector<bool> vis;
    
public:

    /// Constructor
    Bipartite(int n);

    /// add edge (u, v)
    void addEdge(int u, int v);

    /// get maximum matching
    vector<pair<int, int>> getMaxMatch();
};