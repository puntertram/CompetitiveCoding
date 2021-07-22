#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
void print(string ans, int ca) {
    cout << "Case #" << ca << ": " << ans << endl;
}
const int maxn = 101;
vti A;
struct R {
    int st;
    vti con;
};
vt(vt(R)) dp;
R f(int n, int S) {
    if(n == 0) {
        vti rep;
        if(S) {
            R res = {0, rep};
            return res;
        } else {
            R res = {1, rep};
            return res;
        }
    }
    if(dp[n][S].st != -1) {
        return dp[n][S];
    }
    if(A[n] > S) {
        return (dp[n][S] = f(n - 1, S));
    } else {
        R r1 = f(n - 1, S - A[n]);
        R r2 = f(n - 1, S);
        if(r1.st or r2.st) {
            vti rep = r1.con;
            rep.push_back(A[n]);
            R ret = {1, r1.st ? rep : r2.con};
            return (dp[n][S] = ret);
        } else {
            vti rep;
            R ret = {0, rep};
            return (dp[n][S] = ret);
        }
    }
}

vti construct(vti arr, int n) {
    vti A(n);
    FORN(i, n) {
        A[i] = i + 1;
    }
    for(auto ar : arr) {
        reverse(next(A.begin(), n - ar), A.end());
    }
    return A;
}
void solve() {
    static int ca = 0;
    string ans;
    int n;
    int C;
    
    read(n);
    read(C);
    vti arr;
    dp.assign(n + 1, vt(R)(1000, {-1, vti(1, -1)}));
    A.resize(n);
    FORN(i, n - 1) {
        A[i] = i + 2;
    }
    if(C > 3 * n - 4 or C < n - 1) {
        print("IMPOSSIBLE", ca);
        ++ca;
        return;
    } else {
        FORN(i, n) {
            R config = f(n, C - i);
            cout << config.st << " "  << endl;
            if(config.st) {
                
                for(int it : config.con) {
                    cout << it << " ";
                }
                cout << "end\n";
                arr = construct(config.con, n);
                for(auto ar : arr) {
                    ans += to_string(ar);
                    ans += " ";
                }
                print(ans, ca);
                ++ca;
                return;
            }
        }
        print("IMPOSSIBLE", ca);
        ++ca;
        return;
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