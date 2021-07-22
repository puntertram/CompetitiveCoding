#include <bits/stdc++.h>
#define FOR(a, b) for(ll i = a ; i < b; i++)
#define FORI(i, a, b) for(i = a; i < b ; i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
void solve(){
    ll n;
    cin >> n;
    vector<ll> A(n);
    FOR(0, n) {
        cin >> A[i];
    }
    ll sz = n / 2;
    if(!(n & 1)) {
        sz--;
    }
    FOR(0, sz) {
        ll val = A[i] / 2;
        A[i + 1] += val;
        A[i] = (A[i] & 1);
    }
    for(ll i = n - 1 ; i > sz + 1; i--) {
        ll val = A[i] / 2;
        A[i - 1] += val;
        A[i] = (A[i] & 1);
    }
    // FOR(0, n) {
    //     cout << A[i] << " ";
    // }
    if(A[sz] > A[sz + 1]) {
        swap(A[sz], A[sz + 1]);
    }
    ll ans = A[sz + 1] + (A[sz] / 2);
    cout << ans << endl;

}
int main() {
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
    return 0;
}