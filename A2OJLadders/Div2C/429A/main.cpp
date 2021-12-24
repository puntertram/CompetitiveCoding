#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
vector<vector<int> > g;
vector<int> res, init, goal;
void dfs(int v, int par, int curpar, int apar) {
    if(init[v - 1] ^ goal[v - 1] != curpar) {
        // flip the node v
        curpar ^= 1;
        res.push_back(v);
    }
    for(int u : g[v]) {
        if(u != par) {
            dfs(u, v, apar, curpar);
        }
    }
}
int main() {
    int n;
    cin >> n;
    g.resize(n + 1);
    init.resize(n);
    goal.resize(n);
    FORN(i, n - 1) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    FORN(i, n) {
        cin >> init[i];
    }
    FORN(i, n) {
        cin >> goal[i];
    }
    dfs(1, -1, 0, 0);
    cout << res.size() << endl;
    FORN(i, res.size()) {
        cout << res[i] << endl;
    }
    return 0;
}