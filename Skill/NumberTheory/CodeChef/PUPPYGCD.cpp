#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;


const int MAX = 6e6 + 5;
typedef long long ll;

ll store[MAX];
ll sievephi[MAX + 5];

void precalc() {
    FORN(i, MAX + 1) {
        sievephi[i] = i;
    }
    
    for(int i = 2 ; i <= MAX; i += 2) {
        sievephi[i] -= sievephi[i] / 2;
    }

    for(int i = 3; i <= MAX; i += 2) {
        if(sievephi[i] == i) {
            // i is a prime 
            for(int j = i; j <= MAX; j += i) {
                sievephi[j] -= sievephi[j] / i;
            }
        }
    }

    store[0] = 0;
    FOR(i, 1, MAX + 1) {
        store[i] = store[i - 1] + sievephi[i];
    }
}

ll phisum(ll N) {
    if(N < MAX) {
        return store[N];
    }
    ll ans = (N * (N + 1)) / 2;
    int d = 2;
    for(; d * d <= N; d++) {
        ans -= phisum(N / d);
    }
    int val = N / d;
    for(; val > 0; val--) {
        int low = ceil((double)N / (val + 1));
        if(N % (val + 1) == 0) low++;
        int high = N / val;
        ans -= (high - low + 1) * store[val];
    }
    return ans;
}
void solve() {
    int N, D;
    cin >> N >> D;
    cout << phisum(N / D) << endl;
}
int main() {
    precalc();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}