#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
vt(vti) g;
vt(bool) visi;
bool dfs(int v, vti S) {
    // cout << v << endl;
    if(!visi[v]) {
        visi[v] = true;
        S[v] = true;
        for(int u : g[v]) {
            if(S[u]) {
                return true;
            }
            if(!visi[u] and dfs(u, S))return true;
        }
        S[v] = false;
        return false;
    } else {
        S[v] = false;
        return false;
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    g.resize(n);
    visi.resize(n);
    FORN(i, m) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    FORN(i, n) {
        if(!visi[i]) {
            vti S(n);
            if(dfs(i, S)) {
                cout << "cycle detected\n";
            }
        }
    }
    cout << endl;
    return 0;
}