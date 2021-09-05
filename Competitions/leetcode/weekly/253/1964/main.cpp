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
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& o) {
        vector<int> uo(o);
        sort(uo.begin(), uo.end());
        uo.erase(unique(uo.begin(), uo.end()), uo.end());
        // replace o with relative ordering
        for(int &oo : o) {
            oo = lower_bound(uo.begin(), uo.end(), oo) - uo.begin() + 1;
        }
        // restore c to its original state
        c.assign(N, 0);
        m = uo.size();
        int n = o.size();
        vector<int> dp(n);
        for(int i = 0 ; i < n; i++) {
            int cur = query(o[i]);
            dp[i] = cur + 1;
            update(o[i], cur + 1);
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