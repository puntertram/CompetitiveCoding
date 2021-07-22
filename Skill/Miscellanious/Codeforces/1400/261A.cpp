#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define read(x) cin >> x
using namespace std;
void solve() {
    int m;
    read(m);
    vti q(m);
    FORN(i, m) {
        read(q[i]);
    }
    int n;
    read(n);
    vti arr(n);
    FORN(i, n) {
        read(arr[i]);
    }
    sort(q.begin(), q.end());
    sort(arr.begin(), arr.end(), greater<int>());
    int val = q[0];
    int ans = 0;
    int sum = accumulate(arr.begin(), arr.end(), 0);
    FORN(i, n) {
        int ind = i % (val + 2);
        if(ind >= val)sum -= arr[i];
    }
    cout << sum << endl;

}
int main() {
    int t = 1;
    while(t--) {
        solve();
    }
    return 0;
}