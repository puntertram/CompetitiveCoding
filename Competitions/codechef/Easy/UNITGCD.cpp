#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
void solve() {
    int n;
    cin >> n;
    int D = n / 2;
    
    if(n == 1) {
        cout << "1\n1 1\n";
        return;
    }
    cout << D << "\n";
    if(n & 1) {
        cout << 3 << " " << 1 << " " << 2 << " " << n << "\n";
    } else {
        cout << 2 << " " << 1 << " " << 2 << "\n";
    }
    FORN(i, D - 1) {
        cout << 2 << " " << 2 * (i + 1) + 1 << " " << 2 * (i + 2) << "\n";
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}