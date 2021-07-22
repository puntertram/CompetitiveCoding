#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;


typedef pair<int, int> ii;

class Solution {
public:
    int maxValue(vector<vector<int>>& a, int m) {
        vti pos;
        for(auto x : a) {
            pos.push_back(x[0]);
            pos.push_back(x[1]);
        }
        sort(all(pos));
        pos.erase(unique(all(pos)), pos.end());
        int n = pos.size();
        vector<vector<ii> > b(n);
        for(auto &x : a) {
            x[0] = lower_bound(all(pos), x[0]) - pos.begin();
            x[1] = lower_bound(all(pos), x[1]) - pos.begin();
            b[x[1]].push_back({x[0], x[2]});
        }
        vector<vector<int> > dp(n + 1, vti(m + 1));
        for(int i = 0 ; i < n ; i++) {
            dp[i + 1] = dp[i];
            for(int j = 1 ; j <= m ; j++) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i + 1][j - 1]);
                for(auto x : b[i]) {
                    dp[i + 1][j] = max(dp[i + 1][j], dp[x.first][j - 1] + x.second);
                }
            }
        }
        return dp[n][m];
    }
};

int main() {
    vt(vti) events{{1, 2, 4}, {3, 4, 3}, {2, 3, 1}};
    Solution S;
    int k = 1;
    cout << S.maxValue(events, k) << endl;
    return 0;
}