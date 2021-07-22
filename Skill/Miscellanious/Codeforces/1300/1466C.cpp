#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
const int INF = 1e9;
const int N = 1e5 + 7;
const int CHAR = 3;
int dp[N][CHAR][CHAR];
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    s += s[n - 1];
    for(int i = n - 1 ; i >= 0 ; i--) {
        s[i + 1] = s[i];
    }
    FOR(i, 2, n + 1) {
        FORN(j, CHAR) {
            FORN(k, CHAR) {
                dp[i][j][k] = INF;
            }
        }
    }
    FOR(i, 2, n + 1) {
        if(i == 2) {
            FORN(j, CHAR) {
                FORN(k, CHAR) {
                    int val = 0;
                    if(j == k) {
                        dp[i][j][k] = INF;
                    }
                    else {
                        if(j != (s[i - 1] - 'a'))++val;
                        if(k != (s[i] - 'a'))++val;
                        dp[i][j][k] = val;
                    }
                }
            }
        } else {
            FORN(j, CHAR) {
                FORN(k, CHAR) {
                    if(j == k) {
                        dp[i][j][k] = INF;
                    } else {
                        FORN(l, CHAR) {
                            dp[i][j][k] = min(dp[i][j][k], ((l == k) ? (dp[i - 1][l][j] + 1) : dp[i - 1][l][j]));
                        }
                        int val = 0;
                        if(j != (s[i - 1] - 'a'))++val;
                        if(k != (s[i] - 'a'))++val;
                        dp[i][j][k] += val;
                    }  
                }
            }
        }
    }
    int ans = INF;
    FORN(i, CHAR) {
        FORN(j, CHAR) {
            ans = min(ans, dp[n][i][j]);
        }
    }
    cout << ans << endl;

}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}