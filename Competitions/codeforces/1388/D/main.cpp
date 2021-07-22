#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
vector<vector<int> > g;
vti a, b;

vti order[2];
void solve() {
    int n;
    cin >> n;

    a.resize(n);
    b.resize(n);
    g.resize(n);
    FORN(i, n) {
        cin >> a[i];
    }

}
int main() {
    solve();
    return 0;
}