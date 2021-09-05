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
    int minSwaps(string S) {
        int cnt = 0, ret = 0;
        for(char ch : S) {
            if(ch == '[') {
                cnt++;
            }
            else {
                if(cnt == 0) {
                    // the prefix [0..i] is a balanced prefix
                    // here we have string like B] where B is a balanced expression
                    // this ] has no matching [ since B is balanced  so a swap is a must
                    ++cnt;
                    ++ret;
                }
                else {
                    --cnt;
                }
            }
        }
        return ret;
    }
};
int main() {
    Solution S;
    cout << S.minSwaps("][][") << endl;
    return 0;
}