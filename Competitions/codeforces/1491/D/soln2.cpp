#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
void solve() {
    int x, y;
    cin >> x >> y;
    bool ok = (x <= y);
    int z = 0;
    FORN(i, 30) {
        if((x >> i) & 1)++z;
        if((y >> i) & 1)--z;
        if(z < 0)ok = false;
    }
    if(ok) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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