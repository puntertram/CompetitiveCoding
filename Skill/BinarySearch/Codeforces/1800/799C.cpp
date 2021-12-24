#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
int main() {
    int n, c, d;
    scanf("%d %d %d", &n, &c, &d);
    vector<pair<int, int> > C, D;
    FORN(i, n) {
        int b, c;
        char t;
        scanf("%d %d %c", &b, &c, &t);
        if(t == 'C') {
            C.push_back({c, b});
        } else {
            D.push_back({c, b});
        }
    }
    int maxC = -1e9, maxD = -1e9;
    FORN(i, C.size()) {
        if(C[i].first <= c) {
            maxC = max(maxC, C[i].second);
        }
    }
    FORN(i, D.size()) {
        if(D[i].first <= d) {
            maxD = max(maxD, D[i].second);
        }
    }
    sort(all(C));
    sort(all(D));
    int res = 0;
    res = max(res, maxC + maxD);
    n = C.size();
    int m = D.size();
    int j = -1;
    int mxA = -1e9, mxB = -1e9;
    for(int i = n - 1 ; i >= 0 ; i--) {
        while(j + 1 < n and (C[j + 1].first + C[i].first <= c)) {
            j++;
            int x = C[j].second;
            if(x > mxA) {
                swap(x, mxA);
            }
            if(x > mxB) {
                swap(x, mxB);
            }
        }
        if(mxA != C[i].second) {
            res = max(res, mxA + C[i].second);
        } else {
            res = max(res, mxB + C[i].second);
        }
    }
    j = -1;
    mxA = -1e9, mxB = -1e9;
    for(int i = m - 1 ; i >= 0 ; i--) {
        while(j + 1 < m and (D[i].first + D[j + 1].first <= d)) {
            j++;
            int x = D[j].second;
            if(x > mxA) {
                swap(x, mxA);
            }
            if(x > mxB) {
                swap(x, mxB);
            }
        }
        if(mxA != D[i].second) {
            res = max(res, mxA + D[i].second);
        } else {
            res = max(res, D[i].second + mxB);
        }
    }
    cout << res << endl;
    return 0;

}