#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;

void solve() {
    static int ca = 0;
    int ans = 0;
    string s;
    int k;
    int n;
    cin >> n >> k;
    cin >> s;
    int cnt = 0;
    FORN(i, n / 2) {
        if(s[i] != s[n - i - 1])++cnt;
    }
    if(cnt > k) {
        ans = cnt - k;
    } else if (cnt == k) {
        ans = 0;
    } else {
        ans = k - cnt;
    }
    cout << "Case #" << ++ca << ": " << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}