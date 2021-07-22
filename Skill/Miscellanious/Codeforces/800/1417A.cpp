#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    vti arr(n);
    FORN(i, n) {
        cin >> arr[i];
    }
    sort(all(arr));
    int ans = 0;
    FORN(i, n - 1) {
        ans += (k - arr[i + 1]) / arr[0];
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