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
        // int n = a.size();
        long long even = 0, odd = 0;
        for(int x : a) {
            long long new_even = max(even, odd - x);
            odd = max(odd, even + x);
            even = new_even;
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