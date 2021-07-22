#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
ll f(string s, int v) {
    
}
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    ll val = f(s, 0);
    while(!mex(s, val))++val;
    cout << f(val, 1) << endl;

}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}