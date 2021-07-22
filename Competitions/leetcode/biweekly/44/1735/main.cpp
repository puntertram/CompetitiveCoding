#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
const int maxn = 1e4 + 1e3;
int C[maxn][15];
class Solution {

public:
    ll mul(ll a, ll b) {
        ll c = (a % mod) * (b % mod);
        c %= mod;
        if(c < 0) {
            c += mod;
        }
        return c;
    }
    ll add(ll a, ll b) {
        ll c = (a % mod) + (b % mod);
        c %= mod;
        if(c < 0){
            c += mod;
        }
        return c;
    }
    void init() {
        for(int i = 0 ; i < maxn; i++) {
            C[i][0] = 1;
            if(i < 15) {
                C[i][i] = 1;
            }
            for(int j = 1 ; j < i and j < 15; j++) {
                C[i][j] = add(C[i - 1][j - 1], C[i - 1][j]);
            }
        }
    }
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        init();
        vector<int> ans;
        for(auto q : queries) {
            int n = q[0], k = q[1];
            ll sum = 1;
            auto f = [&](int fpw) {
                sum = mul(sum, C[n + fpw - 1][fpw]);
            };
            for(int i = 2 ; i * i <= k; i++) {
                if(k % i == 0) {
                    int fpw = 0;
                    while(k % i == 0) {
                        k /= i;
                        ++fpw;
                    }
                    f(fpw);
                }
            }
            if(k != 1) {
                f(1);
            }
            ans.push_back(sum);
        }
        return ans;
    }
};

int main() {
    Solution S;
    vector<vector<int> > queries({{2, 6}, {5, 1}, {73, 660}});
    auto V = S.waysToFillArray(queries);
    for(auto v : V) {
        cout << v << endl;
    } 
    return 0;
}