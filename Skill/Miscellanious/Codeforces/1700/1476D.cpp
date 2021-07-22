#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
using namespace std;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<vector<int> > dp;
    dp.resize(2, vector<int> (n + 1, 0));
    FORN(i, n + 1) {
        dp[0][i] = dp[1][i] = i;
    }
    FORD(i, n, 0) {
        if(i < n) {
            if(s[i] == 'R') {
                dp[1][i] = i + 1;
            }
        }
        if(i + 1 < n) {
            if(s[i] == 'R' and s[i + 1] == 'L') {
                dp[1][i] = dp[1][i + 2];
            }
        }  
    }
    FOR(i, 0, n + 1) {
        if(i - 1 >= 0) {
            if(s[i - 1] == 'L') {
                dp[0][i] = i - 1;
            }
        }
        if(i - 2 >= 0) {
            if(s[i - 1] == 'L' and s[i - 2] == 'R') {
                dp[0][i] = dp[0][i - 2];
            }
        } 
    }
    FORN(i, n + 1) {
        cout << dp[1][i] - dp[0][i] + 1 << " ";
    }
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}