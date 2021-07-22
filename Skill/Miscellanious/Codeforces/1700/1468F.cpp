#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define in(x) cin >> x
using namespace std;
void solve() {
    int n;
    cin >> n;
    map<pair<int, int> , int > M;
    FORN(i, n) {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        int A = x - u;
        int B = y - v;
        int t = __gcd(abs(A), abs(B));
        A /= t;
        B /= t;
        M[{A, B}]++;
    }
    for(auto u : M) {
        if(M.find(make_pair(-u.first.first, -u.first.second)) != M.end()) {
            ans += u.second * 
        } else {

        }
        
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