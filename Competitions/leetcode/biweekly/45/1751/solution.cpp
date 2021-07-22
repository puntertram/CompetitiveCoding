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
        vector<int> pos;
        for (auto& v : a) {
            pos.push_back(v[0]);
            pos.push_back(v[1]);
        }
        sort(pos.begin(), pos.end());
        pos.erase(unique(pos.begin(), pos.end()), pos.end());
        int n = pos.size();
        vector<vector<ii>> b(n);
        for (auto& v : a) {
            v[0] = lower_bound(pos.begin(), pos.end(), v[0]) - pos.begin();
            v[1] = lower_bound(pos.begin(), pos.end(), v[1]) - pos.begin();
            b[v[1]].push_back({v[0], v[2]});
        }
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));
        for (int i = 0; i < n; ++i) {
            dp[i + 1] = dp[i];
            for (int j = 1; j <= m; ++j) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i + 1][j - 1]);
                for (auto& [start, val] : b[i]) {
                    dp[i + 1][j] = max(dp[i + 1][j], dp[start][j - 1] + val);
                }
            }
        }
        return dp[n][m];
    }
};

int main() {
    vt(vti) events{{1, 2, 4}, {3, 4, 3}, {2, 3, 1}};
    Solution S;
    int k = 2;
    cout << S.maxValue(events, k) << endl;
    return 0;
}