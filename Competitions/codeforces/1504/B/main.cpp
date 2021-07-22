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
    string A, B;
    cin >> A >> B;
    vector<int> pos(1, -1);
    int ones = 0, zeros = 0;
    // if(n == 1){
    //     if(A[0] == B[0]) {
    //         cout << "YES\n";
    //     } else {
    //         cout << "NO\n";
    //     }
    //     return;
    // }
    FORN(i, n) {
        if(A[i] == '1')++ones;
        else ++zeros;
        if(ones == zeros) {
            pos.push_back(i);
        }
    }
    if(pos.size() == 1) {
        if(A == B) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }
    auto check = [&](int i, int j) {
        bool cond = (A[i] == B[i]);
        FOR(k, i, j + 1) {
            if((A[k] == B[k]) ^ cond)return false;
        }
        return true;
    };
    if(ones == zeros)
        pos.push_back(n - 1);
    FORN(i, pos.size() - 1) {
        if(!check(pos[i] + 1, pos[i + 1])) {
            cout << "NO\n";
            return;
        }
    }
    FOR(i, pos.back() + 1, n) {
        if(A[i] != B[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}