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
    cin >> n;
    string s;
    cin >> s;
    if((count(all(s), '0') & 1) or (count(all(s), '1') & 1) or s[0] == '0' or s[n - 1] == '0') {
        cout << "NO\n";
        return;
    }
    string A(s);
    string B(s);
    int k = count(all(s), '1');
    k /= 2;
    int cnt = 0;
    FORN(i, n) {
        if(s[i] == '1') {
            if(k) {
                A[i] = '(';
                B[i] = '(';
                --k;
            } else {
                A[i] = ')';
                B[i] = ')';
            }
        } else {
            if(cnt & 1) {
                A[i] = ')';
                B[i] = '(';
            } else {
                A[i] = '(';
                B[i] = ')';
            }
            cnt ^= 1;
        }
    }
    cout << "YES\n";
    cout << A << endl << B << endl;
    
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}