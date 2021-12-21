#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;

typedef long long ll;
int main() {
    int m;
    cin >> m;
    vti Q(m);
    FORN(i, m) {
        cin >> Q[i];
    }
    int n;
    cin >> n;
    vti A(n);
    FORN(i, n) {
        cin >> A[i];
    }
    // find distict items in Q and form a new Q
    set<int> S;
    FORN(i, m) {
        S.insert(Q[i]);
    }
    Q.clear();
    for(auto it = S.begin(); it != S.end(); it++) {
        Q.push_back(*it);
    }
    Q.resize(min((int)Q.size(), 1));
    m = Q.size();
    // sort A in nondecreasing order
    sort(all(A));

    vt(ll) dp(n + 1);
    vt(ll) pref(n + 1);
    pref[0] = 0;
    FORN(i, n + 1) {
        if(!i)continue;
        pref[i] = pref[i - 1] + A[i - 1];
    }

    dp[0] = 0;
    FORN(i, n + 1) {
        if(!i)continue;
        dp[i] = pref[i];
        FORN(j, m) {
            FORN(type, 3) {
                if(i - Q[j] - type >= 0) {
                    ll value = pref[i] - pref[i - Q[j]] + dp[i - Q[j] - type];
                    dp[i] = min(dp[i], value);
                }
                
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}