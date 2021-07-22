#include <bits/stdc++.h>
#define FOR(a, b) for(int i = a ; i < b; i++)
#define FORI(i, a, b) for(i = a; i < b ; i++)
#define all(x) x.begin(), x.end()
using namespace std;
void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    FOR(0, n) {
        cin >> arr[i];
    }
    int cnt = 1;
    int prev = arr[0];
    FOR(1, n) {
        if(arr[i] != arr[i - 1]) {
            ++cnt;
            prev = arr[i];
        } else {

        }
    }
    // --cnt;
    if(k == 1) {
        if(cnt == 1) {
            cout << "1\n";
        } else {
            cout << "-1\n";
        }
    } else {
        if(cnt == 1) {
            cout << "1\n";
        } else {
            cout << (int)ceil((double)(cnt - 1) / (double)(k - 1)) << endl;
        }
    }
}
int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}