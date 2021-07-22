#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;

const int maxn = 1e3 + 5;
vector<vector<int> > g;
vector<bool> used;
vector<int> ord;
bitset<maxn> bs[maxn];
vector<int> qu, qt, qx, o;
void dfs(int u) {
    used[u] = true;
    for(int v: g[u]) {
        if(!used[v]) {
            dfs(v);
        }
    }
    ord.push_back(u);
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    ord.clear();
    g.resize(n);
    used.resize(n);
    qu.resize(q);
    qt.resize(q);
    qx.resize(q);
    FORN(i, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].push_back(v);
    }
    FORN(i, n) {
        if(!used[i]) {
            dfs(i);
        }
    }
    FORN(id, q) {
        int t, u, x = -1;
        cin >> t >> u;
        if(t == 3) {
            cin >> x;
        }
        qu[id] = u - 1;
        qt[id] = t;
        qx[id] = x;
    }

    o.clear();
    

    return 0;
}