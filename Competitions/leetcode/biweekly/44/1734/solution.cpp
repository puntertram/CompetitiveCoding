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
    vector<int> decode(vector<int>& encoded) {
        int n = (int) encoded.size() + 1;
        vector<int> pref{0};
        for(int x : encoded) {
            pref.push_back(pref.back() ^ x);
        }
        // sort(pref.begin(), pref.end());
        int start = 0;
        
        for(int b = 0; b < 20; ++b) {
            int cnt = 0;
            for(int x : pref) {
                if(x & (1 << b)) {
                    ++cnt;
                }
            }
            int should = 0;
            for(int i = 1; i <= n; ++i) {
                if(i & (1 << b)) {
                    should++;
                }
            }
            if(should != cnt) {
                start ^= (1 << b);
            }
        }
        vector<int> answer;
        for(int x : pref) {
            answer.push_back(x ^ start);
        }
        return answer;
    }
};

int main() {
    Solution S;
    vti d({3, 1});
    auto ans = S.decode(d);
    for(auto a : ans) {
        cout << a << endl;
    }
    return 0;
}