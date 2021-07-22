#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
bool sign(int N) {
    return N > 0;
}
void solve() {
    int n;
    cin >> n;
    vti arr(n);
    FORN(i, n) {
        cin >> arr[i];
    }
    long long ans = 0;
    int ele = arr[0];
    FORN(i, n - 1) {
        if(sign(arr[i]) != sign(arr[i + 1])) {
            ele = max(ele, arr[i]);
            ans += 1LL * ele;
            ele = arr[i + 1];
        } else {
            ele = max(ele, arr[i]);
        }
    }
    ele = max(ele, arr.back());
    ans += 1LL * ele;
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