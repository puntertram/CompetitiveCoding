#include <bits/stdc++.h>
using namespace std;
const int C = 1e6 + 1;
bool exists(vector<int> obs) {
    int n = obs.size();
    for(int i = 1 ; i < n; i++) {
        if(abs(obs[i] - obs[i - 1]) > 1) return true;
    }
    return false;
}
bool line(vector<int> obs) {
    int n = obs.size();
    for(int i = 1 ; i < n ; i++) {
        if(obs[i] != obs[i - 1]) return false;
    }
    return true;
}  
void solve() {
    int n, u, v;
    cin >> n >> u >> v;
    vector<int> obs(n);
    for(int i = 0 ; i < n ; i++) {
        cin >> obs[i];
    }
    if(exists(obs)) {
        cout << "0\n";
    } else {
        int ans;
        if(line(obs)) {
            ans = v + min(u, v);
        } else {
            ans = min(u, v);
        }
        cout << ans << endl;
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