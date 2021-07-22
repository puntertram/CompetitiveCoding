#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    string ans;
    for(int i = 0 ; i < (n - ceil(n / 4.0)); i++) {
        ans += '9';
    }
    for(int i = 0 ; i < ceil(n / 4.0); i++) {
        ans += '8';
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