#include <bits/stdc++.h>

using namespace std;

class Kosaraju
{
    /// n: Number of vertices
    int n;
    
    /// m: Number of edges
    int m;

    /// graph: G
    vector<int> *graph;

    /// grapht: Gt (transpose graph)
    vector<int> *grapht;
    
    /// ft: finish times
    vector<int> ft;

    /// st: start times
    vector<int> st;

    /// Visited array for dfs
    vector<bool> vis;

    /**
     * @brief Performs DFS to compute start and finish times
     * 
     * @param u 
     */
    void dfsG(int u);

    /**
     * @brief Computes strongly connected component by DFS on transpose graph Gt
     * 
     * @param u current node
     * @param comp list of nodes in the strongly connect component
     */
    void dfsGt(int u, vector<int> &comp);

public:

    /**
     * @brief Construct a new Graph object
     * 
     * @param n number of nodes
     * @param m number of edges
     */
    Kosaraju(int n, int m);

    /**
     * @brief Add directed edge from u -> v
     * 
     * @param u 
     * @param v 
     */
    void addEdge(int u, int v);

    /**
     * @brief Computes all strongly connected components of G
     * 
     * @return vector<vector<int>> 
     */
    vector<vector<int>> computeSCCs(void);
};