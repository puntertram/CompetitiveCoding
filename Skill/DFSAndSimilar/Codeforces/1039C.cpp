// Thanks Um_Nik, from which this is inspired
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
map<int, int> toId;
vti id, sz;
int n, m, k;
int getId(int u) {
    if(toId.find(u) != toId.end())return toId[u];
    toId[u] = m;
    id[m] = m;
    sz[m] = 1;
    return m++;
}
int getPar(int u) {
    if(id[u] == u)return u;
    return (id[u] = getPar(id[u]));
}
bool Union(int u, int v) {
    int A = getPar(u);
    int B = getPar(v);
    if(A == B)return false;
    if(sz[A] < sz[B])swap(A, B);
    sz[A] += sz[B];
    id[B] = A;
    return true;
}
typedef long long ll;

map<ll, vector<pair<int, int> > >  G;
const int MOD = 1e9 + 7;
ll add(ll a, ll b) {
    a = ((a % MOD) + (b % MOD));
    a %= MOD;
    if(a < 0)a += MOD;
    return a;
}
ll sub(ll a, ll b) {
    a = ((a % MOD) - (b % MOD));
    a %= MOD;
    if(a < 0)a += MOD;
    return a;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    id.resize(n + 1);
    sz.resize(n + 1);
    
    vt(ll) a(n + 1);
    vector<ll> p(n + k + 1);
    p[0] = 1;
    FORN(i, n + k) {
        p[i + 1] = add(p[i], p[i]); 
    }
    FORN(i, n) {
        cin >> a[i + 1];
    }
    FORN(i, m) {
        int x, y;
        cin >> x >> y;
        G[a[x] ^ a[y]].push_back({x, y});
    }
    ll ans = p[n + k];
    for(auto g : G) {
        m = 0;
        toId.clear();
        int C = n;
        for(auto t : g.second) {
            int u = getId(t.first);
            int v = getId(t.second);
            if(Union(u, v))--C;
        }
        ans = sub(ans, p[n]);
        ans = add(ans, p[C]);
    }
    cout << ans << endl;
    return 0;
}