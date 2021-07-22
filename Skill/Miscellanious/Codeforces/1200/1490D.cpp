#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
vector<int> D;
vector<int> arr;
void dfs(int st, int en, int d) {
    if(st > en) {
        return;
    }
    // cout << st << " " << en << endl;
    int pos = -1;
    int val = INT_MIN;
    FOR(i, st, en + 1) {
        if(val < arr[i]) {
            val = arr[i];
            pos = i;
        }
    }
    D[val] = d;
    dfs(st, pos - 1, d + 1);
    dfs(pos + 1, en, d + 1);

}
void solve() {
    int n;
    cin >> n;
    arr.resize(n);
    D.resize(n + 1);
    FORN(i, n) {
        cin >> arr[i];
    }
    dfs(0, n - 1, 0);
    FORN(i, n) {
        cout << D[arr[i]] << " ";
    }
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}