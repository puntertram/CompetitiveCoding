#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;


const int nax = 10123;
int C[nax][15];
class Solution {
public:
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        const int mod = 1'000'000'007;
        if(C[1][1] == 0) {
            for(int i = 0; i < nax; ++i) {
                C[i][0] = 1;
                if(i < 15) {
                    C[i][i] = 1;
                }
                for(int j = 1; j < i && j < 15; ++j) {
                    C[i][j] = (C[i-1][j-1] + C[i-1][j]) % mod;
                }
            }
        }
        vector<int> answer;
        for(vector<int> query : queries) {
            int n = query[0];
            int k = query[1];
            int total = 1;
            auto consider = [&](int cnt) {
                total = (long long) total * C[n+cnt-1][cnt] % mod; //C(N+cnt-1, cnt);
            };
            for(int i = 2; i * i <= k; ++i) {
                if(k % i == 0) {
                    int cnt = 0;
                    while(k % i == 0) {
                        k /= i;
                        cnt++;
                    }
                    consider(cnt);
                }
            }
            if(k != 1) {
                consider(1);
            }
            answer.push_back(total);
        }
        return answer;
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