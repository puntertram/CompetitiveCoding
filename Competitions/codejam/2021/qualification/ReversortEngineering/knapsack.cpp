#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
vti arr;
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
    if(arr[n] > S) {
        return (dp[n][S] = f(n - 1, S));
    } else {
        R r1 = f(n - 1, S - arr[n]);
        R r2 = f(n - 1, S);
        if(r1.st or r2.st) {
            vti rep = r1.con;
            rep.push_back(arr[n]);
            R ret = {1, r1.st ? rep : r2.con};
            return (dp[n][S] = ret);
        } else {
            vti rep;
            R ret = {0, rep};
            return (dp[n][S] = ret);
        }
    }

}
int main() {
    int W, n;
    read(n);
    read(W);
    arr.resize(n + 1);
    dp.assign(n + 1, vt(R)(1000, {-1, vti(1, -1)}));
    FORN(i, n) {
        read(arr[i + 1]);
    }
    R ans = f(n, W);
    cout << ans.st << endl;

    return 0;
}