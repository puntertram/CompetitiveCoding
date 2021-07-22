#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
vector< vti > g;
vti vis;
void dfs(int u) {
    vis[u] = true;
    for(int v : g[u]) {
        if(!vis[v]) {
            dfs(v);
        }
    }
}
int main() {
    int n, m, q;
    cin >> n >> m >> q;
    g.resize(n + m + 1);
    vis.resize(n + m + 1);
    FORN(i, q) {
        int x, y;
        cin >> x >> y;
        y += n;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = -1;
    FORN(i, n + m) {
        if(!vis[i + 1]) {
            ++ans;
            dfs(i + 1);
        }
    }
    cout << ans << endl;
    return 0;
}