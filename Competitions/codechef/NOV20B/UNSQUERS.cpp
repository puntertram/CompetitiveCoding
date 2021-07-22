#include <bits/stdc++.h>
#define FOR(a, b) for(int i = a ; i < b; i++)
#define FORI(i, a, b) for(i = a; i < b ; i++)
#define all(x) x.begin(), x.end()
using namespace std;
void solve(){
    int N, Q, s;
    cin >> N >> Q >> s;
    vector<int> H(N + 1);
    FOR(0, N) {
        cin >> H[i + 1];
    }
    vector<vector<int> > dp(N + 1, vector<int> (N + 1));
    for(int i = 1 ; i <= N ; i++) {
        int cur = 0, mx = 0;
        for(int j = i ; j <= N ; j++) {
            if(mx < H[j]) {
                mx = H[j];
                ++cur;
            }
            dp[i][j] = cur;
        }
    }

    for(int sz = 2 ; sz <= N ; ++sz) {
        for(int i = 1 ; i + sz - 1 <= N ; i++) {
            int j = i + sz - 1;
            dp[i][j] = max(dp[i][j], dp[i + 1][j]);
        }
    }
    int last = 0;
    while(Q--) {
        int x, y;
        cin >> x >> y;
        int L = (x + s * last - 1) % N + 1;
        int R = (y + s * last - 1) % N + 1;
        if(L > R) {
            swap(L, R);
        }
        cout << (last = dp[L][R]) << "\n";
    }
}
int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}