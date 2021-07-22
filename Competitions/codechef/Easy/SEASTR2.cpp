#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
const int mod = 1e9 + 7;
vt(ll) fact(N, 1), ifact(N, 1);
int modpow(ll a, int b) {
    ll ans = 1;
    a %= mod;
    if(a == 0) {
        return 0;
    }
    while(b) {
        if(b % 2 == 1) {
            ans = (ans * a) % mod;
            if(ans < 0)ans += mod;
        }
        a = (a * a) % mod;
        if(a < 0)a += mod;
        b /= 2;
    }
    return ans;
}


ll add(ll A, ll B) {
    A = (A + B) % mod;
    if(A < 0)A += mod;
    return A;
}
ll mul(ll A, ll B) {
    ll C = (1LL * A * B) % mod;
    if(C < 0)C += mod;
    return C;
}
ll C(ll N) {
    // calculate NC2
    ll ans = (1LL * (N * (N - 1)) / 2LL) % mod;
    if(ans < 0)ans += mod;
    return ans;

}
ll sub(ll A, ll B) {
    ll C = (A - B) % mod;
    if(C < 0)C += mod;
    return C;
}



void init() {
    // calculate fact and ifact
    FOR(i, 1, N) {
        fact[i] = mul(fact[i - 1], (i % mod));
        // fact[i] = (fact[i - 1] * (i % mod)) % mod;
        // if(fact[i] < 0)fact[i] += mod;
        ifact[i] = mul(ifact[i - 1], modpow(i, mod - 2));
        // ifact[i] = ifact[i - 1] * modpow(i, mod - 2);
        // ifact[i] %= mod;
        // if(ifact[i] < 0)ifact[i] += mod;
    }
}
int mult(int N, vti A) {
    ll ans = fact[N];
    for(int cnt : A) {
        ans = mul(ans, ifact[cnt]);
        // ans = (ans) * (ifact[cnt]);
        // ans %= mod;
        // if(ans < 0)ans += mod;
    }
    return ans;
}

void solve() {
    string s;
    cin >> s;
    int N = s.length();
    vti A(26);
    for(char ch : s) {
        A[ch - 'a']++;
    }
    ll P = mult(N, A);
    ll T;
    T = 1; //no swap
    ll cnt = 0;
    FORN(i, 26) {
        FOR(j, i + 1, 26) {
            cnt = add(cnt, mul(A[i], A[j]));
        }
    }
    T = add(T, cnt);
    cnt = 0;
    FORN(i, 26) {
        FOR(j, i + 1, 26) {
            FOR(k, j + 1, 26) {
                cnt = add(cnt, mul(A[i], mul(A[j], mul(A[k], 2))));
            }
        }
    }
    T = add(T, cnt);
    cnt = 0;
    FORN(i, 26) {
        FOR(j, i + 1, 26) {
            FOR(k, j + 1, 26) {
                FOR(l, k + 1, 26) {
                    cnt = add(cnt, mul(A[i], mul(A[j], mul(A[k], mul(A[l], 3)))));
                }
            }
        }
    }
    T = add(T, cnt);
    cnt = 0;
    FORN(i, 26) {
        FORN(j, 26) {
            if(i != j)
                FOR(k, j + 1, 26) {
                    if(i != k)
                        cnt = add(cnt, mul(A[j], mul(A[i], mul(A[i] - 1, A[k]))));
                }
        }
    }
    T = add(T, cnt);
    cnt = 0;
    FORN(i, 26) {
        FOR(j, i + 1, 26) {
            cnt = add(cnt, mul(C(A[i]), C(A[j])));
        }
    }
    T = add(T, cnt);
    ll S = mul(T, P);
    P = modpow(P, 2);
    cout << sub(P, S) << endl;
    
}
int main() {
    init();
    // cout << (fact[5] * ifact[4]) % mod  << " " << ifact[2] << " " << modpow(2, mod - 2)<< endl;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}