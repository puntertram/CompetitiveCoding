#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    if(2 * k + 1 > n) {
        cout << "NO\n";
    } else {
        for(int i = 0 ; i < k ; i++) {
            if(s[i] != s[n - 1 - i]) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
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