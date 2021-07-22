#include <bits/stdc++.h>
#define FOR(a, b) for(int i = a ; i < b; i++)
#define FORI(i, a, b) for(i = a; i < b ; i++)
#define all(x) x.begin(), x.end()
using namespace std;
void solve(){
    int n, x, p, k;
    cin >> n >> x >> p >> k;
    vector<int> arr(n);
    FOR(0, n) {
        cin >> arr[i];
    }
    sort(all(arr));
    --p, --k;
    int ix = upper_bound(all(arr), x) - arr.begin();
    if(p > k) {
        if(ix <= k) {
            cout << "-1\n";
        } else {
            // cout << 
        }
    } else if(p == k) {
        
    } else {

    }

}
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}