#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
bool check(vector<int> arr, int l) {
    int n = arr.size();
    map<int, int> M;
    FORN(i, l) {
        M[arr[i]]++;
    }
    FORN(i, l) {
        if(M.find(i + 1) == M.end()) {
            return false;
        }
    }
    M.clear();
    FOR(i, l, n) {
        M[arr[i]]++;
    }
    FORN(i, n - l) {
        if(M.find(i + 1) == M.end()) {
            return false;
        }
    }
    return true;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    FORN(i, n) {
        cin >> a[i];
    }
    int mx = *max_element(a.begin(), a.end());
    vector<int> ans;
    if(mx == n) {
        cout << "0\n";
        return;
    }
    if(check(a, mx)) {
        ans.push_back(mx);
    }
    if(mx != n - mx) {
        if(check(a, n - mx)) {
            ans.push_back(n - mx);
        }
    }
    
    cout << ans.size() << endl;
    for(int l : ans) {
        cout << l << " " << n - l << endl;
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