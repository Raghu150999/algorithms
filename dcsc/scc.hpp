#include <bits/stdc++.h>

using namespace std;

class DCSC
{
    /// n: Number of vertices
    int n;
    
    /// m: Number of edges
    int m;

    /// graph: G
    vector<int> *graph;

    /// grapht: Gt (transpose graph)
    vector<int> *grapht;
    
    /// Component Number to seperate induced graphs
    vector<int> cno;

    /// Visited array for G
    vector<bool> vis;

    /// Visited array for Gt
    vector<bool> vist;
    
    /**
     * @brief Perform DFS on G to find sucessors
     * 
     * @param u current node
     * @param currcno id number of the induced graph u belongs
     * @param vis visited array
     */
    void dfsG(int u, int currcno, vector<bool> &vis);

    /**
     * @brief Perform DFS to find predecessors
     * 
     * @param u current node 
     * @param currcno id number of the induced graph u belongs
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

    /**
     * @brief Construct a new Graph object
     * 
     * @param n number of nodes
     * @param m number of edges
     */
    DCSC(int n, int m);

    /**
     * @brief insert a new directed edges u -> v
     * 
     * @param u 
     * @param v 
     */
    void addEdge(int u, int v);

    /**
     * @brief Computes strongly connected components of G
     * 
     * @return vector<vector<int>> 
     */
    vector<vector<int>> computeSCCs(void);
};