#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int n = coins.size();
        vector<int> pref(n + 1);
        for(int i = 0 ; i < n ; i++) {
            pref[i + 1] = pref[i] + coins[i];
        }
        int Range = 1;
        for(int i = 0; i < n; ) {
            if(coins[i] > Range) {
                return Range;
            }
            Range = pref[i + 1] + 1;
            i = lower_bound(coins.begin(), coins.end(), Range) - coins.begin();
            if(i <= n){
                Range = pref[i] + 1;
            }
            else {
                Range = pref.back() + 1;
            }
        }
        return Range;
    }
};

int main() {
    Solution S;
    // vector<int> coins({1, 1, 1, 4});
    // vector<int> coins({1, 1, 1, 2, 2, 4, 9});

    vector<int> coins({1, 2, 2, 3, 3, 3, 25});
    cout << S.getMaximumConsecutive(coins) << endl;
    return 0;
}