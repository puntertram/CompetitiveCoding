#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)
#define all(v) v.begin(), v.end()

using namespace std;
vector<long long> a;
vector<int> b, used;
int n;
vector<vector<int> > g;
long long ans;
vector<int> ord[2];
void dfs(int u) {
    used[u] = true;
    for(int v : g[u]) {
        if(!used[v]) {
            dfs(v);
        }
    }
    ans += a[u];
    if(b[u] != -1 and a[u] >= 0) {
        a[b[u]] += a[u];
    }
    if(a[u] >= 0) {
        ord[0].push_back(u);
    } else {
        ord[1].push_back(u);
    }
}
int main() {
    cin >> n;
    a.resize(n);
    b.resize(n);
    g.resize(n);

    used.resize(n);
    FORN(i, n) {
        cin >> a[i];
    }
    FORN(i, n) {
        cin >> b[i];
        if(b[i] != -1) {
            --b[i];
            g[b[i]].push_back(i);
        }
    }
    
    FORN(i, n) {
        if(!used[i]) {
            dfs(i);
        }
    }

    cout << ans << endl;
    for(int u : ord[0]) {
        cout << u + 1 << " ";
    }
    reverse(all(ord[1]));
    for(int u : ord[1]) {
        cout << u + 1 << " ";
    }
    return 0;
}