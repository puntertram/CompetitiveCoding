#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
typedef long long ll;
int S(ll N) {
    int ans = 0;
    while(N) {
        ans += (N % 10);
        N /= 10;
    }
    return ans;
}
void solve() {  
    ll N;
    cin >> N;
    int s = S(N);
    FORN(i, 4) {
        // cout << N + i << " " <<  S(N + i) << " " << __gcd(N + i, 1LL * S(N + i)) << endl;
        if(__gcd(N + i, 1LL * S(N + i)) != 1) {
            
            // cout << __gcd(N + i + 1, 1LL * S(N + i + 1)) << endl;
            cout << N + i << endl;
            return;
        }
    }
    cout << "NP\n";
    
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}