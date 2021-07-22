#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vti cnt(26);
    for(char ch : s) {
        cnt[ch - 'a']++;
    }
    for(int len = n; len > 0; len--) {
        vti cycles, used(len);
        FORN(i, len) {
            if(used[i])continue;
            int cur = 1;
            used[i] = true;
            int j = (i + k) % len;
            while(!used[j]) {
                ++cur;
                used[j] = true;
                j = (j + k) % len;
            }
            cycles.push_back(cur);
        }
        vti tmp_cnt(cnt);
        sort(all(tmp_cnt));
        sort(all(cycles));
        bool ok = true;
        while(!cycles.empty()) {
            if(cycles.back() > tmp_cnt.back()) {
                ok = false;
                break;
            }
            tmp_cnt.back() -= cycles.back();
            cycles.pop_back();
            sort(all(tmp_cnt));
        }
        if(ok) {
            cout << len << endl;
            return;
        }
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