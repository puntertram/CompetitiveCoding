#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
class Solution {
    vector<int> stones;
public:
    bool canCross(vector<int>& stones) {
        this->stones = stones;
        if(stones.size() == 1)return true;
        if(stones.size() >= 2 and stones[1] == stones[0] + 1) return f(1, 1);
        else return false;
    }
    bool f(int ind, int k) {
        cout << ind << " " << k << endl;
        if(ind == stones.size() - 1) {
            return true;
        } 
        if(ind > stones.size() - 1)return false;
        auto it = lower_bound(stones.begin(), stones.end(), stones[ind] + k);
        bool ans = false;
        if(it == stones.end()) {
            --it;
            if(*it == stones[ind] + k - 1) {
                return true;
            } else {
                return false;
            }
        } else {
            
            if(*it == stones[ind] + k) {
                ans |= f(it - stones.begin(), k);
                if(*next(it) == stones[ind] + k + 1)ans |= f(it - stones.begin() + 1, k + 1);
            }  else {
                if(*it == stones[ind] + k + 1)ans |= f(it - stones.begin(), k + 1);
            }
            
            if(it != stones.begin() and k != 1 and *prev(it) == stones[ind] + k - 1)ans |= f(it - stones.begin() - 1, k - 1);
        }
        return ans;
    }
};
int main() {
    Solution s;
    vector<int> stones({0,1,3,6,10,13,14});
    cout << s.canCross(stones) << endl;
    return 0;
}