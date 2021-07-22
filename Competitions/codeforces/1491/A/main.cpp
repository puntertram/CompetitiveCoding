#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> A(n);
    int cnt[2] = {0, 0};
    for(int i = 0 ; i < n ; i++) {
        cin >> A[i];
        cnt[A[i]]++;
    }
    for(int i = 0 ; i < q; i++) {
        int t, x;
        cin >> t >> x;
        if(t == 1) {
            --x;
            cnt[A[x]]--;
            cnt[!A[x]]++;
            A[x] = !A[x];
        } else {
            if(x > cnt[1]) {
                cout << "0\n";
            } else {
                cout << "1\n";
            }
        }
    }
    return 0;
}