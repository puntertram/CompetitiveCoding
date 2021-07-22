#include <bits/stdc++.h>
#define FOR(i, a, b) for(long long i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
void solve() {
    long long n, p, q;
    cin >> n >> p >> q;
    vector<long long> arr(n);
    FORN(i, n) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<pair<long long, long long> > req(1);
    FORN(i, n) {
        req.push_back({req.back().first + (arr[i] & 1), req.back().second + (arr[i] / 2)});
    }
    for(long long i = n ; i >= 0 ; i--) {
        if((p < req[i].first)) {
            continue;
        }
        if(p - req[i].first + (q - req[i].second) * 2LL >= 0) {
            cout << i << endl;
            return;
        }
    }
}
int main() {
    long long t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}