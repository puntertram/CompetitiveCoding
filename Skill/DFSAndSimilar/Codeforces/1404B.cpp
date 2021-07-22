#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
vector< vti > g;
vti d;
int dia;
int dfs(int u, int p) {
    int len = 0;
    for(int v : g[u]) {
        if(v != p) {
            d[v] = d[u] + 1;
            int cur = 1 + dfs(v, u);
            dia = max(dia, len + cur);
            len = max(len, cur);
        }
    }
    return len;
}
void solve() {
    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    g.resize(n + 1);
    FORN(i, n + 1) {
        g[i].clear();
    }
    FORN(i, n - 1) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dia = 0;
    d.resize(n + 1);
    d[a] = 0;
    dfs(a, -1);
    cout << (d[b] <= da || 2 * da >= min(dia, db) ? "Alice" : "Bob") << endl; 
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}