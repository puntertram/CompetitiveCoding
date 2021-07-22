#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    FORN(i, n) {
        cin >> arr[i];
    }
    FORN(i, n) {
        int ex = (i);
        if(arr[i] < ex) {
            cout << "NO\n";
            return;
        }
        if(i + 1 < n)
            arr[i + 1] += arr[i] - ex;
    }

    cout << "YES\n";

}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}