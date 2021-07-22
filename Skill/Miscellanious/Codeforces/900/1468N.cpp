#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
void solve() {
    vector<int> c(3);
    vector<int> a(5);
    FORN(i, 3) {
        cin >> c[i];
    }
    FORN(i, 5) {
        cin >> a[i];
    }
    if(a[0] <= c[0] and a[1] <= c[1] and a[2] <= c[2]) {
        FORN(i, 3) {
            c[i] -= a[i];
        }
        if((a[3] <= c[0] + c[2])){
            c[2] -= a[3] - min(a[3], c[0]);
            if(a[4] <= c[1] + c[2]) {
                cout << "YES\n";
            } else {
                cout << "NO\n";
            }
            
        } else {
            cout << "NO\n";
        }
    } else {
        cout << "NO\n";
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