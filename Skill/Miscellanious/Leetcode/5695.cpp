#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
class Solution {
public:
    int maxScore(vector<int>& nums) {
        int N = nums.size();
        int n = N / 2;
        sort(nums.begin(), nums.end());
        // reverse(nums.begin(), nums.end());
        int ans = 0;
        for(int i = N - 1 ; i >= 0 and n > 0; i--) {
           if(nums[i] != -1) {
               cout << "cons\n";
               bool done = false;
               for(int j = i - 1 ; j >= 0 ; j--) {
                   if(nums[j] != -1 and (nums[i] % nums[j] == 0)) {
                       cout << nums[i] << " " << nums[j] << "cons\n";
                        ans += n * nums[j];
                        nums[j] = -1;
                       --n;
                       done = true;
                       break;
                   }
               }
               if(done) {
                   nums[i] = -1;
               }
           } 
        }
        return ans;
    }
};
int main() {
    Solution S;
    // vector<int> coins({1, 1, 1, 4});
    // vector<int> coins({1, 1, 1, 2, 2, 4, 9});

    vector<int> coins({1, 2});
    cout << S.maxScore(coins) << endl;
    return 0;
}