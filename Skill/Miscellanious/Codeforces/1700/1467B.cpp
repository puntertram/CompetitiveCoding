#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)
 
#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
void solve() {
    int n;
    read(n);
    vti arr(n);
    FORN(i, n) {
        read(arr[i]);
    }
    vt(int) st(n);
    FOR(i, 1, n - 1) {
        if(arr[i] > arr[i - 1] and arr[i] > arr[i + 1])st[i] = 1;
        if(arr[i] < arr[i - 1] and arr[i] < arr[i + 1])st[i] = 1;
    }
    int val = accumulate(all(st), 0);
    FOR(i, 1, n - 1) {
        if(st[i - 1] and st[i] and st[i + 1]) {
            cout << val - 3 << endl;
            return;
        }
    }
    FOR(i, 1, n - 1) {
        if((st[i - 1] and st[i]) or (st[i] and st[i + 1])) {
            cout << val - 2 << endl;
            return;
        }
    }
    FORN(i, n) {
        if(st[i]) {
            cout << val - 1 << endl;
            return;
        }
    }
    cout << val << endl;
}
int main() {
    int t;
    read(t);
    while(t--) {
        solve();
    }
    return 0;
}