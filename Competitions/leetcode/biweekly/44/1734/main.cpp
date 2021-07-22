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
    vector<int> decode(vector<int> & encoded) {
        vector<int> pref{0};
        int n = encoded.size() + 1;
        for(int i = 0 ; i < n - 1 ; i++) {
            pref.push_back(pref.back() ^ encoded[i]);
        }
        int start = 0;
        for(int b = 0 ; b < 20; b++) {
            int cnt = 0;
            for(auto x : pref) {
                if(x & (1 << b))++cnt;
            }
            int should = 0;
            for(int i = 1 ; i <= n ; i++) {
                if(i & (1 << b))++should;
            }
            if(cnt != should) {
                // p0 has bth bit set
                start |= (1 << b);
            }
        }
        vector<int> ans;
        for(auto x : pref) {
            ans.push_back(start ^ x);
        }
        return ans;
    }
};

int main() {
    Solution S;
    vti d({6,5,4,6});
    auto ans = S.decode(d);
    for(auto a : ans) {
        cout << a << endl;
    }
    return 0;
}