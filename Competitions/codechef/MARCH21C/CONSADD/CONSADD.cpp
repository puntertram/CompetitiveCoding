#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int A[n][m], B[n][m];
    FORN(i, n) {
        FORN(j, m) {
            cin >> A[i][j];
        }
    }
    FORN(i, n) {
        FORN(j, m) {
            cin >> B[i][j];
        }
    }
    long long val = (n * n + m * m + n + m - n * m);
    if(k * (n + m) < val) {
        cout << "No\n";
    } else {
        // detect if the system of equations is inconsistent or not
        
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