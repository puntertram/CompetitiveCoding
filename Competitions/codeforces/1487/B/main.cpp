#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    int N, C;
    C = (k - 1) / (n / 2) + 1;
    N = k - 1;
    if(n & 1) {
        cout << ((N + C) % n ? (N + C) % n : n) << endl;
    } else {
        cout << (k % n ? k % n : n) << endl;
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