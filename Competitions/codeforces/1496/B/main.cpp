#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> S(n);
    FORN(i, n) {
        cin >> S[i];
    }
    sort(S.begin(), S.end());
    int mex = 0;
    FORN(i, n) {
        if(S[i] != mex) {
            break;
        } else {
            mex++;
        }
    }
    int max = *max_element(S.begin(), S.end());
    if(mex == max + 1) {
        cout << n + k << endl;
    } else {
        int val = ceil((max + mex) / 2.0);
        if(k == 0) {
            cout << n << endl;
            return;
        }
        bool found = false;
        FORN(i, n) {
            if(S[i] == val)found = true;
        }
        if(!found) {
            cout << n + 1 << endl;
        } else {
            cout << n << endl;
        }
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