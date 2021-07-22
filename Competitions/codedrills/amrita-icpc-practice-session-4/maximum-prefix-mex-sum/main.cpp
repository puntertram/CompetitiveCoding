#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)
typedef long long ll;

using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;
vector<ll> fact(maxn, 1);
ll multiply(ll a, ll b) {
    a = (a % mod) * (b % mod);
    a %= mod;
    if(a < 0) {
        a += mod;
    }
    return a;
}
void pre() {
    FOR(i, 1, maxn) {
        fact[i] = multiply(fact[i - 1], i);
    }
}

void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    FORN(i, n) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    int pos = n;
    int cur = 0;
    FORN(i, n) {
        if(arr[i] != cur and arr[i] != cur - 1) {
            pos = i;
            break;
        }
        cur = arr[i] + 1;
    }
    int cnt = 1;
    long long ans = 1;
    vector<int> C;
    FOR(i, 1, pos) {
        if(arr[i] == arr[i - 1]) {
            cnt++;
        } else {
            // ans = multiply(ans, fact[cnt]);
            C.push_back(cnt);
            cnt = 1;
        }
    }
    C.push_back(cnt);
    for(auto &c : C) {
        ans = multiply(ans, c);
        c--;
    }
    ans = multiply(ans, fact[accumulate(C.begin(), C.end(), 0) + n - pos]);
    // ans = multiply(ans, fact[cnt]);
    // ans = multiply(ans, fact[]);
    cout << ans << endl;
}
int main() {
    pre();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}