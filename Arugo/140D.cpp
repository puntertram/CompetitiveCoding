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
    sort(all(A));
    int count = 10;
    int penalty = 0;
    int cnt = 0;
    for(; cnt < n; ++cnt) {
        count += A[cnt];
        if(count > 720) break;
        if(count > 360)penalty += count - 360;
    }
    cout << cnt << " " << penalty << endl;
    return 0;
}