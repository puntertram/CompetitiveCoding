#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
int m;
const int N = 1e5 + 5;
vector<int> c(N);
// bit[x] = max(bit[x], y)
void update(int x, int y) {
    for(; x <= m; x += x & -x) {
        c[x] = max(c[x], y);
    }
}
// give the range max of dp_i from 0 to x
int query(int x) {
    int ret = 0;
    for(; x > 0; x -= x & -x) {
        ret = max(ret, c[x]);
    }
    return ret;
}
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> unique_obstacles(obstacles);
        sort(unique_obstacles.begin(), unique_obstacles.end());
        unique_obstacles.erase(unique(unique_obstacles.begin(), unique_obstacles.end()), unique_obstacles.end());
        for(auto &obstacle: obstacles) {
            obstacle = lower_bound(unique_obstacles.begin(), unique_obstacles.end(), obstacle) - unique_obstacles.begin() + 1;
        } 
        int n = obstacles.size();
        m = unique_obstacles.size();
        c.assign(N, 0);
        vector<int> dp(n);
        // time to calculate dp
        for(int i = 0 ; i < n ; i++) {
            int cur = query(obstacles[i]);
            dp[i] = cur + 1;
            update(obstacles[i], dp[i]);
        }
        return dp;
    }
};
int main() {
    Solution S;
    vector<int> obstacles{2, 2, 1};
    auto sol = S.longestObstacleCourseAtEachPosition(obstacles);
    for(auto s : sol) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}