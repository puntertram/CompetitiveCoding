#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
void solve() {
    int n, k1, k2;
    int w, b;
    cin >> n >> k1 >> k2 >> w >> b;
    if(k1 > k2)swap(k1, k2);
    
    pair<int, int> ans = {k1 + ((k2 - k1) / 2), n - k2 + ((k2 - k1) / 2)};
    // cout << ans << endl;
    if(w <= ans.first and b <= ans.second) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}