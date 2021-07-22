#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
void solve() {
    long long n, m, x;
    cin >> n >> m >> x;
    long long i = x % n;
    long long j = (x / n);
    if(i)++j;
    else i = n;
    long long val = 1LL * m * (max(0LL, i - 1)) + j;
    cout << val << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}