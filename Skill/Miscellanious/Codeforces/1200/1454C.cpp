#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
void solve() {
    int n;
    cin >> n;
    int ans = INT_MAX;
    vector<int> arr(n);
    for(int &a : arr) {
        cin >> a;
    }
    vector<int> cnt(n + 1, 1);
    n = unique(arr.begin(), arr.end()) - arr.begin();
    
    arr.resize(n);
    for(int a : arr) {
        cnt[a]++;
    }
    cnt[arr[0]]--;
    cnt[arr[n - 1]]--;
    for(int a : arr) {
        ans = min(ans, cnt[a]);
    }
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}