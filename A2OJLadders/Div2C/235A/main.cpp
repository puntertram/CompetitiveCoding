#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
long long lcm(long long a, long long b, long long c) {
    long long d = (a * b) / __gcd(a, b);
    long long e = (c * d) / __gcd(c, d);
    return e;
}
int main() {
    long long n;
    cin >> n;
    if(n < 3) {
        cout << n << endl;
        return 0;
    }
    if(n & 1) {
        cout << n * (n - 1) * (n - 2) << endl;
    } else {
        int c = 50;
        long long ans = 0;
        FOR(i, n - c, n + 1) {
            FOR(j, n - c, n + 1) {
                FOR(k, n - c, n + 1) {
                    if(i < 1 or j < 1 or k < 1)continue;
                    ans = max(ans, lcm(i, j, k));
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}