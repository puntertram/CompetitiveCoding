#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n + 1);
    FORN(i, n) {
        int x;
        cin >> x;
        if(x) {
            arr[max(0, i + 1 - x)] += -1;
            arr[i + 1] += 1;
        }
    }
    // FORN(i, n + 1) {
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    for(int i = n - 1 ; i >= 0; i--) {
        arr[i] += arr[i + 1];
        // cout << arr[i] << " ";
    }
    // cout << endl;
    FORN(i, n) {
        cout << (arr[i + 1] != 0) << " ";
    }
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}