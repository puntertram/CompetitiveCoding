#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
bool issorted(vti arr) {
    int ele = arr[0];
    FOR(i, 1, arr.size()) {
        if(arr[i] <= ele) {
            return false;
        }
        ele = arr[i];
    }
    return true;
}
void solve() {
    int n;
    cin >> n;
    vti arr(n);
    FORN(i, n) {
        cin >> arr[i];
    }
    int mi = *min_element(all(arr)), ma = *max_element(all(arr));
    if(issorted(arr)) {
        cout << "0\n";
    } else if(arr[0] == mi or arr.back() == ma) {
        cout << "1\n";
    } else if(arr[0] == ma and arr.back() == mi) {
        cout << "3\n";
    } else {
        cout << "2\n";
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