#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vt(pair<int, int>) A(n), B(m);
    FORN(i, n) {
        cin >> A[i];
    }

    FORN(i, m) {
        cin >> B[i];
    }
    sort(all(A));
    sort(all(B));
    
    FORN(i, m) {
        cout << 0 << " " << i << endl;
    }
    FOR(i, 1, n) {
        cout << i << " " << m - 1 << endl;
    }
    return 0;
}