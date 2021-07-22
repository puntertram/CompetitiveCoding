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
    vt(long long) arr(n);
    FORN(i, n) {
        read(arr[i]);
    }
    if(n == 1) {
        cout << "0\n";
        return;
    }
    map<long long, int> D;
    FORN(i, n - 1) {
        D[arr[i + 1] - arr[i]]++;
    }
    if(D.size() > 2) {
        cout << "-1\n";
    } else if(D.size() == 1){
        cout << "0\n";
    } else {
        auto a = *(D.begin()), b = *(D.rbegin());
        int M = -a.first + b.first;
        if(M <= *max_element(all(arr))) {
            cout << "-1\n";
        } else {
            cout << M << " " << b.first << endl;
        }
    }
}
int main() {
    int t;
    read(t);
    while(t--) {
        solve();
    }
    return 0;
}