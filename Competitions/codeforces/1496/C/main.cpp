#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
void solve() {
    int n;
    cin >> n;
    vector<long long> X, Y;
    FORN(i, 2 * n) {
        int x, y;
        cin >> x >> y;
        if(x < 0)x = -x;
        if(y < 0)y = -y;
        if(x == 0) {
            Y.push_back(y);
        } else if (y == 0) {
            X.push_back(x);
        }
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    double ans = 0.0;
    FORN(i, n) {
        // cout << "considering (" << X[i] << ", 0) and (0, " << Y[i] << ")\n";
        ans += sqrt(X[i] * X[i] +  Y[i] * Y[i]);
    }
    cout << fixed << setprecision(18) << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}