#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& a) {
       long long even = 0, odd = 0;
       for(auto x : a) {
           long long nodd = max(odd, even + x);
           even = max(even, odd - x);
           odd = nodd;
       }
       return max(even, odd);
    }
};

int main() {
    Solution S;
    vector<int> A{4, 2, 5, 3};
    cout << S.maxAlternatingSum(A) << endl;  
    return 0;
}