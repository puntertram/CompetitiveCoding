#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
vector<vector<pair<int, int> > > g;
int D(int s) {
    vector<int> dist(g.size(), INT_MAX);
    vector<bool> visi(g.size());
    dist[s] = 1;
    multiset<pair<int, int> > M;
    while(!M.empty()) {
        auto u = *M.begin();
        M.erase(M.begin());
        if(visi[u.second])continue;
        visi[u.second] = true;
        // auto u = g.back();
        for(auto p : g[u.second]) {
            int v = p.second;
            int w = p.first;
            if(dist[u.second] + w < dist[v]) {
                dist[v] = dist[u.second] + w;
                M.insert({dist[v], v});
            }
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    FORN(i, m) {
        int u, v, c;
        cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }
    return 0;
}