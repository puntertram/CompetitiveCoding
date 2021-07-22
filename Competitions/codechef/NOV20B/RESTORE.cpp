#include <bits/stdc++.h>
#define FOR(a, b) for(int i = a ; i < b; i++)
#define FORI(i, a, b) for(i = a; i < b ; i++)
#define all(x) x.begin(), x.end()
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> B(n);
    FOR(0, n) {
        cin >> B[i];
    }
    map<int, vector<int> > M;
    FOR(0, n) {
        M[B[i]].push_back(i);
    }
    int ele = 2;
    vector<int> A(n);
    for(auto it = M.rbegin(); it != M.rend(); ++it) {
        for(auto j : it->second) {
            A[j] = ele;
        }
        ele += 2;
    }
    FOR(0, n) {
        cout << A[i] << " ";
    }
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}