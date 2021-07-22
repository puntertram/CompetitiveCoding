#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
const int MAXN = 1e4 + 4;
const int MAXK = 1e2 + 5;
void solve() {
    int n, k;
    cin >> n >> k;
    vti H(n);
    FORN(i, n) {
        cin >> H[i];
    }
    // sort H in non decreasing order
    sort(all(H));
    vti suffix(n + 1);
    for(int i = n - 1 ; i >= 0 ; i--) {
        suffix[i] = suffix[i + 1] + H[i];
    }
    vt(vti) dp(n + 1, vti(k + 1, INT_MAX));
    dp[n][0] = 0;
    for(int i = n - 1 ; i >= 0 ; i--) {
        for(int j = k ; j >= 0 ; j--) {
            if(j < H[i]) {
                dp[i][j] = H[i];
                continue;
            }
            if(dp[i + 1][j - H[i]] == INT_MAX)dp[i][j] = INT_MAX;
            else dp[i][j] = min(dp[i + 1][j], dp[i + 1][j - H[i]] + H[i]);
        }
        if(suffix[i] - dp[i][k] >= k) {
            cout << n - i << endl;
            return;
        }
    }

    // for(int i = n - 1 ; i >= 0 ; i--) {
    //     if(suffix[i] - dp[i][k] >= k) {
    //         cout << n - i << endl;
    //         return;
    //     }
    // }
    cout << "-1\n";


    
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}