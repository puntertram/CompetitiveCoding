#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
typedef pair<int, int> pii;
vector<vector<pii> > g;
vector<int> visi;
bool good;
void dfs(int u, int color) {
    if(visi[u]) {
        if(visi[u] != color)good = 0;
        return;
    }
    visi[u] = color;
    for(auto v : g[u]) {
        dfs(v.first, color * v.second);
    }
}

void solve() {
    int n;
    cin >> n;
    g.clear();
    visi.clear();
    g.resize(n);
    visi.assign(n, 0);
    vector<vector<int> > A(n, vector<int> (n, 0)), B(n, vector<int> (n, 0));
    FORN(i, n) {
        FORN(j, n) {
            cin >> A[i][j];
        }
    }

    FORN(i, n) {
        FORN(j, n) {
            cin >> B[i][j];
        }
    }

    FORN(i, n) {
        FORN(j, n) {
            if(A[i][j] == A[j][i] and B[i][j] == B[j][i] and A[i][j] == B[i][j]) {
                continue;
            }
            if(A[i][j] == B[i][j] and A[j][i] == B[j][i]) {
                g[i].push_back({j, 1});
                g[j].push_back({i, 1});
                continue;
            }
            if(A[i][j] == B[j][i] and A[j][i] == B[i][j]) {
                g[i].push_back({j, -1});
                g[j].push_back({i, -1});
                continue;
            }
            cout << "No\n";
            return;
        }
    }
    good = 1;
    FORN(i, n) {
        if(!visi[i]) {
            dfs(i, 1);
        }
    }
    if(good) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}