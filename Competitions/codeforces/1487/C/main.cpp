#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n;
    cin >> n;
    int w = (n - 1) / 2;
    int l = w;
    int d = (n - 1) & 1;
    for(int i = 0 ; i < (n * (n - 1)) / 2; i++) {
        if(w) {
            --w;
            cout << "1 ";
        } else if (l) {
            --l;
            cout << "-1 ";
        } else if(d) {
            --d;
            cout << "0 ";
        }
    }
    cout << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}