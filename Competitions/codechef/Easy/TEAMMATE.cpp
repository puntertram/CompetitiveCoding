#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int MAXN = 3e5 + 5;
vt(ll) fact(MAXN, 1), ifact(MAXN, 1), itwo(MAXN, 1);
ll mul(ll A, ll B) {
    ll C = (A % mod) * (B % mod);
    C %= mod;
    if(C < 0)C += mod;
    return C;
}
ll modpow(ll a, ll b) {
    ll ans = 1;
    while(b) {
        if(b & 1) {
            ans = mul(ans, a);
        }
        b >>= 1;
        a = mul(a, a);
    }
    return ans;
}
void init() {
    FOR(i, 1, MAXN) {
        fact[i] = mul(fact[i - 1], i);
        ifact[i] = mul(ifact[i - 1], modpow(i, mod - 2));
        itwo[i] = mul(itwo[i - 1], modpow(2, mod - 2));
    }
}
ll f(ll N) {
    ll ans = fact[N];
    ans = mul(ans, ifact[N / 2]);
    ans = mul(ans, itwo[N / 2]);
    return ans;
}
void solve() {
    int n;
    cin >> n;
    map<int, int> M;
    FORN(i, n) {
        int x; 
        cin >> x;
        M[x]++;
    }
    ll ans = 1;
    for(auto it = M.begin(); it != M.end(); it++) {
        if(it->second & 1) {
            auto ij = next(it);
            ans = mul(ans, mul(ij->second, it->second));
            it->second--;
            ans = mul(ans, f(it->second));
            ij->second--;

        } else {
            ans = mul(ans, f(it->second));
        }
    }
    cout << ans << endl;
}
int main() {
    init();
    // cout << fact[2] << " " << ifact[2] << " " << itwo[1] << endl;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}