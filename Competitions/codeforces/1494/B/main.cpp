#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
int N, U, R, D, L;

bool run() {
    FOR(i, 0, 16) {
        int n = N;
        vector<int> val({U, R, D, L});
        bool cond = true;
        FORN(j, 4) {
            int b2 = (i & (1 << j));
            int b1 = (i & (1 << ((j + 1) % 4)));
            int temp = val[(j + 1) % 4];
            if(!b1 and !b2) {
                if(temp >= N - 1) {cond = false;break;}
            } else if(!b1 and b2) {
                if(!(temp >= 1 and temp <= N - 1)) {cond = false;break;}
            } else if(b1 and !b2) {
                if(!(temp >= 1 and temp <= N - 1)) {cond = false;break;}
            } else {
                if(!(temp >= 2)) {cond = false;break;}
            }
        }
        if(cond)return true;
    } 
    return false;;
}

void solve() {
    
    cin >> N >> U >> R >> D >> L;
    int val = run();
    if(val) {
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