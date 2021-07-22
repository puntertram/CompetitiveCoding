#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;

int main() {
    int n, b;
    cin >> n >> b;
    vector<int> arr(n);
    FORN(i, n) {
        cin >> arr[i];
    }
    pair<int, int> P = {1, 2001};
    FORN(i, n) {
        FOR(j, i + 1, n) {
            if(1LL * arr[j] * P.second > 1LL * arr[i] * P.first) {
                P = {arr[j], arr[i]};
            }
        }
    }
    if(P != make_pair(1, 2001)) {
        cout << max(b, (b / P.second) * P.first) + (b % P.second) << endl;
    } else {
        cout << b << endl;
    }
    return 0;
}