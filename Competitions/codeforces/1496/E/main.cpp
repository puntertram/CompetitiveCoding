#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> arr(n);
    FORN(i, n) {
        cin >> arr[i];
    }
    for(int i = 1 ; i < m ; i += 3) {
        FORN(j, n) {
            arr[j][i] = 'X';
        }
    }
    if(m % 3 == 1) {
        FORN(i, n) {
            arr[i][m - 1] = 'X';
        }
    }
    FORN(i, n) {
        cout << arr[i] << endl;
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