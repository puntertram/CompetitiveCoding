#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
typedef long long ll;
ll C[20][20];
ll pw[] = {1, 9, 81, 729};
void precalc() {
    C[0][0] = 1;
    FOR(i, 1, 20) {
        C[i][0] = 1;
        FOR(j, 1, 20) {
            C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
        }
    }
}
ll ncr(int N, int R) {
    if(R > N) return 0;
    return C[N][R];
}
ll get(int n, int nz) {
    ll tot = 0;
    FORN(i, nz + 1) {
        tot += ncr(n, i) * pw[i];
    }
    return tot;
}
ll calc(ll N) {
    ll res = 0;
    string s = to_string(N);
    int n = s.length();
    int nz = 3;
    FORN(i, n) {
        if(s[i] == '0')continue;
        res += get(n - i - 1, nz);
        --nz;
        if(nz == -1)break;
        res += get(n - i - 1, nz) * (s[i] - '1');
    }
    return res;
}
void solve() {
    ll L, R;
    cin >> L >> R;
    cout << calc(R + 1) - calc(L) << endl;
}
int main() {
    precalc();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}