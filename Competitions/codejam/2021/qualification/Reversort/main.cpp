#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;

void solve() {
    static int ca = 0;
    int ans = 0;
    int n;
    read(n);
    vti arr(n);
    FORN(i, n) {
        read(arr[i]);
    }
    FORN(i, n - 1) {
        int mn = arr[i];
        int pos = i;
        FOR(j, i + 1, n) {
            if(arr[j] < mn) {
                pos = j;
                mn = arr[j];
            }
        }
        ans += pos - i + 1;
        reverse(next(arr.begin(), i), next(arr.begin(), pos + 1));
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