#include <bits/stdc++.h>
#define FOR(i, a, b) for(long long i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
void solve() {
    long long n;
    cin >> n;
    vector<long long> c(n);
    FORN(i, n) {
        cin >> c[i];
    }
    long long ans = 0;
    FORN(i, 2) {
        if(!i) {
            vector<long long> R, U;
            FORN(j, n) {
                if(j & 1) {
                    R.push_back(c[j]);
                } else {
                    U.push_back(c[j]);
                }
            }
            auto um = min_element(U.begin(), U. end());
            auto rm = min_element(R.begin(), R.end());
            vector<long long> UV(U), RV(R);
            for(auto it = U.begin(); it != U.end(); it++) {
                if(it > um) {
                    UV[it - U.begin()] = 0;
                } else if(it == um) {
                    UV[it - U.begin()] = n - (it - U.begin());
                } else {
                    UV[it - U.begin()] = 1;
                }
                
            }
            for(auto it = R.begin(); it != R.end(); it++) {
                if(it > rm) {
                    RV[it - R.begin()] = 0;
                } else if(it == rm) {
                    RV[it - R.begin()] = n - (it - R.begin());
                } else {
                    RV[it - R.begin()] = 1;
                }
            }

            long long cost = 0;
            FORN(j, U.size()) {
                cost += U[j] * UV[j];
            }
            FORN(j, R.size()) {
                cost += R[j] * RV[j];
            }
            ans = cost;
        } else {
            vector<long long> R, U;
            FORN(j, n) {
                if(j & 1) {
                    U.push_back(c[j]);
                } else {
                    R.push_back(c[j]);
                }
            }

            auto um = min_element(U.begin(), U. end());
            auto rm = min_element(R.begin(), R.end());
            vector<long long> UV(U), RV(R);
            for(auto it = U.begin(); it != U.end(); it++) {
                if(it > um) {
                    UV[it - U.begin()] = 0;
                } else if(it == um) {
                    UV[it - U.begin()] = n - (it - U.begin());
                } else {
                    UV[it - U.begin()] = 1;
                }
                
            }
            for(auto it = R.begin(); it != R.end(); it++) {
                if(it > rm) {
                    RV[it - R.begin()] = 0;
                } else if(it == rm) {
                    RV[it - R.begin()] = n - (it - R.begin());
                } else {
                    RV[it - R.begin()] = 1;
                }
            }

            long long cost = 0;
            FORN(j, U.size()) {
                cost += U[j] * UV[j];
            }
            FORN(j, R.size()) {
                cost += R[j] * RV[j];
            }
            ans = min(ans, cost);
        }
    }
    cout << ans << endl;
}
int main() {
    int  t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}