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
    int longestValidParentheses(string s) {
        stack <pair<char, int> > S;
        int N = s.length();
        S.push({')', 0});
        int ans = 0;
        int cnt = 0;
        for(int i = 0 ; i < N ; i++) {
            if(s[i] == '(') {
                S.push({'(', 0});
            } else {
                if(!S.empty() and S.top().first == '(') { 
                    auto it = S.top();
                    // ans = max(ans, it.second + 2);
                    S.pop();
                    if(!S.empty() and S.top().first == '(') {
                        auto ij = S.top();
                        S.pop();
                        S.push({'(', ij.second + it.second + 2});
                        cnt = ij.second + it.second + 2;
                    } else {
                        cnt = it.second + 2;
                        ans = max(ans, cnt);
                        cnt = 0;
                    }
                }
                else  {
                    S.push({')', 0});
                    //  boundary
                    ans = max(ans, cnt);
                    cnt = 0;
                }
            }
            
        }
        ans = max(ans, cnt);
        return ans;
    }
};
int main() {
    
    Solution S;
    cout << S.longestValidParentheses("(()");
    return 0;
}