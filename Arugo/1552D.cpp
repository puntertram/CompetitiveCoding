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
    vti A(n);
    FORN(i, n) {
        cin >> A[i];
    }
    int num = 1;
    FORN(i, n) {
        num *= 3;
    }
    bool found = false;
    FOR(i, 1, num) {
        int tmp = i;
        int sum = 0;
        FORN(j, n) {
            int dig = tmp % 3;
            if(dig == 1) {
                sum += A[j];
            } else if(dig == 2) {
                sum -= A[j];
            }
            tmp /= 3;
        }
        if(sum == 0) {
            found = true;
            break;
        }
    }
    if(found) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}