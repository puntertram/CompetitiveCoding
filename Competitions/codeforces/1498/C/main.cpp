#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
const int mod = 1e9 + 7;
vt(vt(vt(int))) dp;
int f(int k, int n, int l) {
    int ans = 1;
    if(k == 1) {
        return 1;
    }
    if(n == 0) {
        return 1;
    }
    if(dp[k][n][l] != -1) {
        return dp[k][n][l];
    }
    if(!l) {
        FORN(i, n) {
            ans += f(k- 1, i, !l);
        }
    } else {
        FORN(i, n) {
            ans += f(k - 1, n - (i + 1), !l);
        }
    }
    return (dp[k][n][l] = ans);
}
void solve() {
    int n, k;
    cin >> n >> k;
    dp.assign(k + 1, vt(vt(int)) (n + 1, vt(int) (2, -1)));
    cout << f(k, n, 0) << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}