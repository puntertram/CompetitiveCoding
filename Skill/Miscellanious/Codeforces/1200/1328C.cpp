#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
void solve() {
    int n;
    cin >> n;
    string x;
    cin >> x;
    bool cond = false;
    string ans[2];
    for(auto ch : x) {
        if(ch == '1') {
            if(cond) {
                ans[!cond] += '1';
                ans[cond] += '0';
            } else {
                ans[0] += '0';
                ans[1] += '1';
                cond = true;
            }
        } else if(ch == '2') {
            if(cond) {
                ans[!cond] += '2';
                ans[cond] += '0';
            } else {
                ans[0] += '1';
                ans[1] += '1';
            }
        } else {
            ans[0] += '0';
            ans[1] += '0';
        }
    }
    cout << ans[0] << "\n" << ans[1] << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}