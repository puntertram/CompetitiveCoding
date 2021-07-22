#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    if(n == 1) {
        cout << "0\n\n";
        return;
    }
    vector<int> ans;
    int val = ceil(k / 2.0);
    FOR(i, val, k) {
        ans.push_back(i);
    }
    FORN(i, n - k) {
        ans.push_back(k + i + 1);
    }
    cout << ans.size() << endl;
    for(int a : ans) {
        cout << a << " ";
    }
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}