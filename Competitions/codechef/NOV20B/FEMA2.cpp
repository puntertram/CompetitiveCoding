#include <bits/stdc++.h>
#define FOR(a, b) for(int i = a ; i < b; i++)
#define FORI(i, a, b) for(i = a; i < b ; i++)
#define all(x) x.begin(), x.end()
using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    string arr;
    cin >> arr;
    int ans = 0;
    //step 1: create I, M, X arrays
    vector<int> I, M, X;
    FOR(0, n) {
        if(arr[i] == 'I') {
            I.push_back(i);
        } else if(arr[i] == 'M'){
            M.push_back(i);
        } else if(arr[i] == 'X') {
            X.push_back(i);
        }
    }
    // step 2: check for the farthest left and then the closest right
    FOR(0, n) {
        if(arr[i] != 'M')continue;
        //farthest left
        int lval;
        auto il1 = lower_bound(all(X), i);
        if(il1 == X.begin()) {
            lval = -1;
        } else {
            lval = *prev(il1);
        }
        int l2 = max({lval, i - k, 0});
        auto il2 = lower_bound(all(I), l2);
        int l1;
        if(il2 == I.end()) {
            l1 = -1;
        } else {
            l1 = *il2;
            if(l1 > i) {
                l1 = -1;
            } else {
                I.erase(il2);
            }
        }
         
        // cout << "The farthest iron to the left is at position" << l1 << "||";
        
        if(l1 != -1){
            ++ans;
            continue; 
        }
        //closest right
        auto ir1 = lower_bound(all(I), i + 1);
        int r1;
        if(ir1 == I.end()) {
            r1 = -1;
            // cout << "The closest iron to the rigt is at position " << r1 << endl;
        } else {
            r1 = *ir1;
            int rval;
            auto ir2 = lower_bound(all(X), i + 1);
            if(ir2 == X.end()) {
                rval = n + 1;
            } else {
                rval = *ir2;
            }
            int r2 = min({rval, i + k, n - 1});
            if(r1 <= r2) {
                I.erase(ir1);
                ++ans;
            }
            // cout << "The closest iron to the rigt is at position " << r1 << " " << r2 << endl;
        }  
    }
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}