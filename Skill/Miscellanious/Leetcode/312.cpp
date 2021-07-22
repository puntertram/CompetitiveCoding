#include <bits/stdc++.h>
#define FOR(a, b) for(int i = a ; i < b; i++)
#define FORI(i, a, b) for(i = a; i < b ; i++)
#define all(x) x.begin(), x.end()
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> A(n);
    FOR(0, n) {
        cin >> A[i];
    }
    vector<vector<int> > dp(n, vector<int>(n));
    for(int L = n - 1; L >= 0 ; L--) {
        for(int R = L; R < n; R++) {
            for(int i = L ; i <= R ; i++) {
                dp[L][R] = max(dp[L][R], A[i] * (L? A[L - 1] : 1) * (R == n - 1 ? 1 : A[R + 1]) + (L <= i - 1 ? dp[L][i - 1] : 0) + (i + 1 <= R ? dp[i + 1][R]: 0));
            }
        }
    }
    for(int i = 0 ; i < n ; i++) {
        for(int j = 0 ; j < n ; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[0][n - 1] << endl;
}
int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}