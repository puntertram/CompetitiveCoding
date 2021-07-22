#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<pair<int, int> > T(n + 1);
    vector<int> tm(n + 1);
    FORN(i, n) {
        cin >> T[i + 1].first >> T[i + 1].second;
    }
    FORN(i, n) {
        cin >> tm[i + 1];
    }
    int in = 0;
    FOR(i, 1, n + 1) {
        int arr = in + T[i].first - T[i - 1].second + tm[i];
        int dep = max(T[i].second, arr + (int)ceil((T[i].second - T[i].first) / 2.0));
        in = dep;
        // cout << arr << " " << dep << endl;
        if(i == n) {
            cout << arr << endl;
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