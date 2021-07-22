#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
map<long long, long long> factorize(long long N) {
    map<long long, long long> ans;
    long long cnt = 0;
    while(!(N & 1)) {
        ++cnt;
        N /= 2LL;
    }
    ans[2] = cnt;
    for(long long i = 3 ; i * i <= N; i += 2) {
        cnt = 0;
        while(N % i == 0) {
            ++cnt;
            N /= i;
        }
        ans[i] = cnt;
    }
    if(N > 2)
        ans[N] = 1;
    return ans;
}

void solve() {
    long long p, q;
    cin >> p >> q;
    map<long long, long long> fp = factorize(p), fq = factorize(q);
    long long ans = 1;
    bool smallest = false;
    set<long long> primes;
    for(auto u : fp) {
        primes.insert(u.first);
    }
    for(auto u : primes) {
        if(fp[u] < fq[u]) {
            ans = p;
            break;
        }
    }
    if(ans != p) {
        vector<long long> val;
        for(auto u: primes) {
            val.push_back(pow(u, fp[u] - fq[u] + 1));
        }
        sort(val.begin(), val.end());
        ans = p / val[0];
    }
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}