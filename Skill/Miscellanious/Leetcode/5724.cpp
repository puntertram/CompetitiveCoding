#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
class Solution {
public:
    int impact(int A, int B, int C) {
        int d = abs(A - B);
        if(C >= A - d and C <= A + d) {
            return d - abs(A - C);
        } else {
            return -1;
        }
    }
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> A(nums1);
        sort(A.begin(), A.end());
        vector<pair<int, int> > diff;
        for(int i = 0 ; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            auto it = lower_bound(A.begin(), A.end(), nums2[i]);
            int val = INT_MIN;
            if(*it == nums2[i]) {
                val = impact(nums2[i], nums1[i], *it);
            } else {
                if(it != A.end())
                    val = max(val, impact(nums2[i], nums1[i], *it));
                if(it != A.begin())
                    val = max(val, impact(nums2[i], nums1[i], *prev(it)));
            }
            if(val <= 0)continue;
            cout << i << " " << val << endl;
            diff.push_back({val, i});
        }
        int ans = 0;
        sort(diff.begin(), diff.end());
        for(int i = 0 ; i < nums1.size(); i++) {
            ans += abs(nums1[i] - nums2[i]);
        }
            
        if(!diff.empty()) {
            ans -= diff.back().first;  
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> A({1, 7}), B({9, 20});
    cout << s.minAbsoluteSumDiff(A, B);
    return 0;
}