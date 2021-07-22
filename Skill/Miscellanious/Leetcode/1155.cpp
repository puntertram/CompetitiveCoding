#include <bits/stdc++.h>
#define FOR(a, b) for(int i = a ; i < b; i++)
#define FORI(i, a, b) for(i = a; i < b ; i++)
#define all(x) x.begin(), x.end()
using namespace std;
const int mod = 1e9 + 7;
void solve(){
    int target, f, d;
    cin >> d >> f >> target;
    vector<int> ways(target + 1);
    ways[0] = 1;
    for(int rep = 1; rep <= d; rep++) {
        vector<int> new_ways(target + 1);
        for(int already = 0; already <= target; ++already) {
            for(int k = 1; k <= f; k++) {
                if(already + k > target)continue;
                int &tmp = new_ways[already + k];
                tmp += ways[already];
                if(tmp >= mod) {
                    tmp -= mod;
                }
            }
        }
        ways = new_ways;
    }
    cout << ways[target] << endl;
}
int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}