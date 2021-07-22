#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> S(n);
    FORN(i, n) {
        cin >> S[i];
    }
    vector<int> curr(n + 1);
    long long ans = 0;
    FORN(i, n) {
        int temp = curr[i];
        if(temp < S[i] - 1) {
            ans += S[i] - 1 - temp;
            temp = S[i] - 1;
        }
        curr[i + 1] += temp - (S[i] - 1);
        if(i + 2 < n) {
            FOR(j, i + 2, min(n, i + S[i] + 1)) {
                ++curr[j];
            }
        }
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