#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
void solve() {
    long long N, W;
    cin >> N >> W;
    map<long long, long long> M;
    FORN(i, N) {
        long long x;
        cin >> x;
        M[x]++;
    }
    long long val = 0;
    long long l = (long long)log2(M.begin()->first);
    val = (W >> l) << l;
    // cout << val << endl;
    long long S = 0;
    for(auto it : M) {
        S += 1LL * it.first * it.second;
    }
    cout << (long long)ceil(S / (1.0 * val)) << endl;

}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}