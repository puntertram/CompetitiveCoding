#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
vector<vector<int> > g;
vector<bool> visi;
vector<int> low, tin;
int timer;
void dfs(int u, int p = -1) {
    visi[u] = true;
    low[u] = tin[u] = timer++;
    for(int v : g[u]) {
        if(v == p)continue;
        if(visi[v]) {
            // back edge
            low[u] = min(low[u], tin[v]);
        } else {
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(low[v] > tin[u]) {
                cout << u << "->" << v << "is a bridge\n";
            }
        }
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n + 1);
    visi.resize(n + 1);
    tin.resize(n + 1);
    low.resize(n + 1);
    FORN(i, m) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    FORN(i, n) {
        if(!visi[i + 1]) {
            dfs(i + 1);
        }
    }
    return 0;
}