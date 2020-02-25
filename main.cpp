#include <bits/stdc++.h>
#include <sys/resource.h>
#include "scc.hpp"

#define endl "\n"

using namespace std;

map<string, int> mp;
int cnt = 0;
int getval(string u)
{
    if(!mp[u])
    {
        cnt++;
        mp[u] = cnt;
    }
    return mp[u];
}

int main()
{
    // Allocate larger stack size
    const rlim_t kStackSize = 160 * 1024 * 1024;   // min stack size = 16 MB
    struct rlimit rl;
    int result;

    result = getrlimit(RLIMIT_STACK, &rl);
    if (result == 0)
    {
        if (rl.rlim_cur < kStackSize)
        {
            rl.rlim_cur = kStackSize;
            result = setrlimit(RLIMIT_STACK, &rl);
            if (result != 0)
            {
                fprintf(stderr, "setrlimit returned result = %d\n", result);
                return 0;
            }
        }
    }
    int n, m;
    cin >> n >> m;
    Graph g(n, m);
    for(int i = 1; i <= m; i++)
    {
        string u, v;
        cin >> u >> v;
        g.addEdge(getval(u), getval(v));
    }
    
    // Sorting output for fixed format output
    vector<vector<int>> comps = g.computeSCCs();
    for(auto &comp: comps)
        sort(comp.begin(), comp.end());
    sort(comps.begin(), comps.end());
    for(auto &comp: comps)
    {
        cout << comp.size() << endl;
        for(int &u: comp)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
