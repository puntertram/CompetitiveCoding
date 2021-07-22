#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
int n;
vector<int> A;
int solve(vector<int> A, int bit) {
    if(bit < 0) {
        return 0;
    }
    vector<int> L, R;
    for(int &a : A) {
        if((a >> bit) & 1)R.push_back(a);
        else L.push_back(a);
    }
    if(L.empty())return solve(R, bit - 1);
    if(R.empty())return solve(L, bit - 1);
    return min(solve(L, bit - 1), solve(R, bit - 1)) + (1LL << bit);
}
int main() {
    cin >> n;
    A.resize(n);
    for(int &a : A) {
        cin >> a;
    }
    cout << solve(A, 30) << endl;
    return 0;
}