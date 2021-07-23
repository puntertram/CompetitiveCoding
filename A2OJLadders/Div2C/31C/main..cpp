#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
#define rem(x, n) (((x)%(n) + (n))%(n))
using namespace std;
int main() {
    int n;
    cin >> n;
    vti s(n), e(n);
    FORN(i, n) {
        cin >> s[i] >> e[i];
    }
    vector<vector<int> > d(n, vector<int> (n, 0)), a(n, vector<int> (n, 0));
    auto intersect = [&](int i, int j) {
        if(e[i] <= s[j]) return 0;
        if(e[j] <= s[i]) return 0;
        return 1;
    };
    FORN(i, n) {
        FORN(j, n) {
            if(intersect(i, j))a[i][j] = 1;
        }
    }
    FORN(l, n) {
       FORN(i, n) {
           int j = (i + l) % n;
           if(i == j)d[i][j] = 1;
           else
           d[i][j] = !a[i][j] and d[i][rem(j - 1, n)] and d[rem(i + 1, n)][j];
       } 
    }
    vti ans;
    FORN(i, n) {
        if(d[rem(i + 1, n)][rem(i - 1, n)]) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    for(auto a : ans) {
        cout << a + 1 << " ";
    }
    cout << endl;
    return 0;
}