#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
int main() {
    int k, b, n, t;
    cin >> k >> b >> n >> t;
    long long x = 1;
    int y = 0;
    while(x <= t) {
        ++y;
        x = k * x + b;
    }
    cout << max(n - y + 1, 0) << endl;

    return 0;
}