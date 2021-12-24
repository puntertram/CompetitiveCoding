#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
const int N = 2e5 + 10;
int maxp[N];
void precalc() {
    FOR(i, 2, N + 1) {
        if(!maxp[i]) {
            maxp[i] = i;
            for(int j = i; j <= N; j += i) {
                maxp[j] = i;
            }
        }
        
    }
}
vector<vector<int> > g;
vector<int> A;
map<int, int> chain[N], path[N];
int dfs(int u, int p, int f) {
    if(A[u] % f != 0) {
        return 0;
    }
    if(chain[u].count(f) != 0)return chain[u][f];
    int &ch = chain[u][f];
    ch = 1;
    int mx[2] = {0};
    for(auto v : g[u]) {
        if(v == p)continue;
        int _ch = dfs(v, u, f);
        ch = max(ch, 1 + _ch);
        if(_ch > mx[0]) {
            swap(_ch, mx[0]);
        }
        if(_ch > mx[1]) {
            swap(_ch, mx[1]);
        }
    }
    path[u][f] = 1 + mx[0] + mx[1];
    return ch;
}
int main() {
    precalc();
    int n;
    cin >> n;
    g.resize(n);
    A.resize(n);
    FORN(i, n) {
        cin >> A[i];
    }
    FORN(i, n - 1) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = 0;
    FORN(i, n) {
        for(int x = A[i]; x > 1; x /= maxp[x]) {
            dfs(i, -1, maxp[x]);
            ans = max(ans, path[i][maxp[x]]);
        }
    }
    cout << ans << endl;
    return 0;
}