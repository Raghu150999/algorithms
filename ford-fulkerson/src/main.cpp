#include <bits/stdc++.h>
#include "ff.hpp"

using namespace std;

int main()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    FordFulkerson ff(n, s, t);
    for(int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        ff.addEdge(u, v, c);
    }
    cout << "MaxFlow: ";
    cout << ff.getMaxFlow() << endl;
    cout << "Min S-T cut:" << endl;
    for(auto &p: ff.getMinSTCut())
        cout << p.first << " " << p.second << endl;
}