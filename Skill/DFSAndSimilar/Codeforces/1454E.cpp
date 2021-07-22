#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<set<int>> g(n + 1);
    FORN(i, n) {
        int x, y;
        cin >> x >> y;
        g[x].insert(y);
        g[y].insert(x);
    }
    vti val(n + 1, 1);
    queue<int> leaves;
    FORN(i, n) {
        if(g[i + 1].size() == 1) {
            leaves.push(i + 1);
        }
    }
    while(!leaves.empty()) {
        int u = leaves.front();
        leaves.pop();
        int v = *g[u].begin();
        val[v] += val[u];
        val[u] = 0;
        g[u].clear();
        g[v].erase(u);
        if(g[v].size() == 1) {
            leaves.push(v);
        }
    }
    long long ans = 0;
    FORN(i, n) {
        ans += val[i + 1] * 1LL * (val[i + 1] - 1) / 2;
        ans += val[i + 1] * 1LL * (n - val[i + 1]);
    }
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}