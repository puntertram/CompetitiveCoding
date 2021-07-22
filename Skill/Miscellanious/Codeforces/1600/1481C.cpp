#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
void solve() {
    int n,m ;
    cin >> n >> m;
    vti a(n), b(n), p(m), g;
    FORN(i, n) {
        cin >> a[i];
    }
    FORN(i, n) {
        cin >> b[i];
        if(b[i] != a[i]) {
            g[b[i]].push_back(i);
        }
    }
    FORN(i, m) {
        cin >> p[i];
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