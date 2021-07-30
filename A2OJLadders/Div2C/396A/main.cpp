#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;

typedef long long ll;
const int nax = 10123;
ll C[nax][40];
class Solution {
public:
    ll waysToFillArray(vector<ll> A, int n) {
        const int mod = 1'000'000'007;
        if(C[1][1] == 0) {
            for(int i = 0; i < nax; ++i) {
                C[i][0] = 1;
                if(i < 40) {
                    C[i][i] = 1;
                }
                for(int j = 1; j < i && j < 40; ++j) {
                    C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
                }
            }
        }
        ll total = 1;
        map<int, int> prime_powers;
        for(auto k : A) {
            for(ll i = 2; i * i <= k; ++i) {
                if(k % i == 0) {
                    int cnt = 0;
                    while(k % i == 0) {
                        k /= i;
                        cnt++;
                    }
                    prime_powers[i] += cnt;
                }
            }
            if(k != 1)prime_powers[k]++;
        }
        auto consider = [&](int cnt) {
            total = (long long) total * (C[n+cnt-1][cnt] % mod); //C(N+cnt-1, cnt);
            total %= mod;
            if(total < 0)total += mod;
        };
        for(auto pp : prime_powers) {
            consider(pp.second);
        }
        return total;
    }
};



int main() {
    Solution S;
    int n;
    cin >> n;
    vector<ll> A;
    FORN(i, n) {
        int x;
        cin >> x;
        A.push_back(x);
    }
    auto V = S.waysToFillArray(A, n);
    cout << V << endl;   
    return 0;
}