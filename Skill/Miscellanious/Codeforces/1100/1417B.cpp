#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
void solve() {
    int n, T;
    cin >> n >> T;
    vti arr(n);
    FORN(i, n) {
        cin >> arr[i];
    }
    map<int, vti> M;
    FORN(i, n) {
        M[arr[i]].push_back(i);
    }
    for(auto u : M) {
        if(u.first * 2 == T) {
            FORN(j, u.second.size()) {
                if(j >= u.second.size() / 2) {
                    arr[u.second[j]] = 1;
                } else {
                    arr[u.second[j]] = 0;
                }
            }
        } else {
            if(M.find(T - u.first) != M.end()) {
            for(auto it : M[T - u.first]) {
                    arr[it] = 1;
                }
                M.erase(T - u.first);
            } 
            
            for(auto it : u.second) {
                arr[it] = 0;
            }
        }
        
    }
    FORN(i, n) {
        cout << arr[i] << " ";
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