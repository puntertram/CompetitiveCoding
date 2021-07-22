#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
void solve() {
    int n, m;
    read(n);
    read(m);
    vt(vti) mat(m), B(n + 1);
    FORN(i, m) {
        int k, v;
        read(k);
        FORN(j, k) {
            read(v);
            mat[i].push_back(v);
        }
        // sort(all(mat[i]));
    } 
    vti cnt(n + 1, ceil(m / 2.0));

    vti assi(m);
    FORN(i, m) {
        if(mat[i].size() == 1) {
            cnt[mat[i][0]]--;
            assi[i] = mat[i][0];
        } else {
            FORN(j, mat[i].size()) {
                B[mat[i][j]].push_back(i);
            }
        }
    }
    FORN(i, n) {
        if(cnt[i + 1] < 0){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for(int i = n ; i >= 1 ; i--) {
        FORN(j, B[i].size()) {
            if(assi[B[i][j]])continue;
            assi[B[i][j]] = i;
            --cnt[i];
            if(!cnt[i])break;
        }
    }
    for(int it : assi) {
        cout << it << " ";
    }
    cout << endl;
}
int main() {
    int t;
    read(t);
    while(t--) {
        solve();
    }
    return 0;
}