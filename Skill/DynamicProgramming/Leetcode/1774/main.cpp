#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
class Solution {
vector<int> bs, ts;
int T;
public:
    int closestCost(vector<int>& bs, vector<int>& ts, int T) {
        this->bs = vector<int> (bs);
        this->ts = vector<int> (ts);
        this->T = T;
        int n = bs.size();
        int m = ts.size();
        int ans = INT_MAX;
        int mindiff = INT_MAX;
        for(auto b : bs) {
            int closest = f(b, 0);
            if(mindiff > abs(closest - T)) {
                mindiff = abs(closest - T);
                ans = closest;
            } else if(mindiff == abs(closest - T)) {
                ans = min(ans, closest);
            }
        }
        return ans;
    }
    int f(int cur, int ind) {
        if(cur > T) {
            return cur;
        }
        if(ind == ts.size()) {
            return cur;
        }
        int ans = INT_MAX;
        int mindiff = INT_MAX;
        FORN(i, 3) {
            int closest = f(cur + i * ts[ind], ind + 1);
            if(mindiff > abs(closest - T)) {
                mindiff = abs(closest - T);
                ans = closest;
            } else if(mindiff == abs(closest - T)) {
                ans = min(ans, closest);
            }
        }
        return ans;
    }
};
int main() {
    Solution S;
    vti base_costs{1, 7, 9}, topping_costs{3, 4, 10};
    int target = 19;
    cout << S.closestCost(base_costs, topping_costs, target) << endl;  
    return 0;
}