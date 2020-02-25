#include <bits/stdc++.h>

using namespace std;

class Graph
{
    /// n: Number of vertices, m: Number of edges
    int n, m;

    /// graph: G, grapht: Gt (transpose graph)
    vector<int> *graph, *grapht;
    
    /// Component Number to seperate induced graphs
    vector<int> cno;

    /// Visited array for the two dfs calls
    vector<bool> vis, vist;
    
    /// Perform DFS on G to compute start and finish times
    void dfsG(int u, int currcno, vector<bool> &vis);

    /**
     * @brief Computes component by performing DFS on Gt
     * 
     * @param u current node 
     * @param currcno component number of the induced graph it belongs
     * @param vis visited array
     */
    void dfsGt(int u, int currcno, vector<bool> &vis);

    /**
     * @brief DCSC Algorithm to compute strong components
     * 
     * @param currcno defines current component number of the induced graph
     * @param nodes vector of nodes of the induced graph
     * @param comps all strong components
     */
    void dcsc(int currcno, vector<int> &nodes, vector<vector<int>> &comps);

public:

    /// Constructor for initialising data structures
    Graph(int n, int m);

    /// Add a directed edge from u ~> v
    void addEdge(int u, int v);

    /// Compute all strongly connected components
    vector<vector<int>> computeSCCs(void);
};