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
    map<int, int> M;
    vti A(n), B(n);
    FORN(i, n) {
        cin >> A[i];
        M[A[i]]++;
    }
    FORN(i, n) {
        cin >> B[i];
        M[B[i]]++;
    }
    for(auto m : M) {
        if(m.second & 1) {
            cout << "-1\n";
            return;
        }
    }
    long long ans = 0;
    map<int, int> MA;
    for(auto a : A) MA[a]++;
    // int val = M.begin()->first;
    // M.erase(M.begin());
    vti v1, v2;
    int mi = M.begin()->first;
    for(auto m : M) {
        int v = (m.second / 2 - MA[m.first]);
        if(!v)continue;
        if(v < 0) {
            FORN(i, -v) {
                v1.push_back(m.first);
            }
        } else {
            FORN(i, v) {
                v2.push_back(m.first);
            }
        }
    }
    sort(v2.rbegin(), v2.rend());
    FORN(i, v1.size()) {
        ans += min(2 * mi, min(v1[i], v2[i]));
    }
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}