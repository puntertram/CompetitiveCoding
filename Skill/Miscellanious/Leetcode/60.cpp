#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;

class Solution {
    vector<int> fact;
    vector<int> pool;
public:
    string getPermutation(int n, int k) {
        calc();
        pool.resize(n);
        for(int i = 0 ; i < n ; i++) {
            pool[i] = i + 1;
        }
        --k;
        string ans;
        for(int i = 0 ; i < n ; i++) {
            int val = k / (fact[n - (i + 1)]);
            // int rem = k % fact[n - (i + 1)];
            ans += (char)(pool[val] + '0');
            pool.erase(next(pool.begin(), val));
            k -= val * (fact[n - (i + 1)]);
        }
        return ans;
    }
    void calc() {
        fact.resize(10);
        fact[0] = 1;
        for(int i = 1 ; i < 10; i++) {
            fact[i]= fact[i - 1] * i;
        }
    }
};
int main() {
    Solution S;
    // vector<int> coins({1, 1, 1, 4});
    // vector<int> coins({1, 1, 1, 2, 2, 4, 9});

    int n, k;
    cin >> n >> k;
    cout << S.getPermutation(n, k) << endl;
    return 0;
}