#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
void solve() {
    int x, y;
    cin >> x >> y;
    int v = sqrt(x);
    long long ans = 0;
    FORN(k, v) {
        ans += max(0, min(y, (x / (k + 1)) - 1) - (k + 1));
    }
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}