#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
int main() {
    int n;
    cin >> n;
    vti A(n);
    FORN(i, n) {
        cin >> A[i];
    }
    vti pref(n + 1, 0);
    FORN(i, n) {
        pref[i + 1] = pref[i] ^ (i + 1);
    }
    long long ans = 0;
    FORN(i, n) {
        ans ^= A[i];
        int I = (i + 1);
        int x  = (n / I);
        if(x & 1) {
            ans ^= pref[I - 1];
        }
        x = n % I;
        ans ^= pref[x];
    }
    cout << ans << endl;
    return 0;
}