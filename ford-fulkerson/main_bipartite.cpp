#include <bits/stdc++.h>
#include "bipartite.hpp"

using namespace std;

int main()
{
    int n, m, s, t;
    cin >> n >> m;
    Bipartite bp(n);
    for(int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        bp.addEdge(u, v);
    }
    cout << "Max Matching:" << endl;
    for(auto &p: bp.getMaxMatch())
        cout << p.first << " " << p.second << endl;
}