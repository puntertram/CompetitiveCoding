#include <bits/stdc++.h>
#define FOR(a, b) for(int i = a ; i < b; i++)
#define FORI(i, a, b) for(i = a; i < b ; i++)
#define all(x) x.begin(), x.end()
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> A(n), B(n), C(n);
    FOR(0, n) {
        cin >> A[i];
    }
    FOR(0, n) {
        cin >> B[i];
    }
    FOR(0, n) {
        cin >> C[i];
    }
    vector<int> ans;
    FOR(0, n) {
        if(i == n - 1) {
            bool a = false, b = false, c = false;
            if(ans[i - 1] == A[i]) {
                a = true;
            } else if(ans[i - 1] == B[i]) {
                b = true;
            } else if(ans[i - 1] == C[i]) {
                c = true;
            }

            if(ans[0] == A[i]) {
                a = true;
            } else if(ans[0] == B[i]) {
                b = true;
            } else if(ans[0] == C[i]) {
                c = true;
            }
            

            if(!a) {
                ans.push_back(A[i]);
                continue;
            }

            if(!b) {
                ans.push_back(B[i]);
                continue;
            }

            if(!c) {
                ans.push_back(C[i]);
                continue;
            }
        } else if(i == 0){
            ans.push_back(A[i]);
        } else {
            bool a = false, b = false, c = false;
            if(ans[i - 1] == A[i]) {
                a = true;
            } else if(ans[i - 1] == B[i]) {
                b = true;
            } else if(ans[i - 1] == C[i]) {
                c = true;
            }
            if(!a) {
                ans.push_back(A[i]);
                continue;
            }

            if(!b) {
                ans.push_back(B[i]);
                continue;
            }

            if(!c) {
                ans.push_back(C[i]);
                continue;
            }
        }
    }
    for(int it : ans) {
        cout << it << " ";
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