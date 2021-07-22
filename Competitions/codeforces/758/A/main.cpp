#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> arr(n);
    FORN(i, n) {
        cin >> arr[i];
    }
    long long mx = *max_element(arr.begin(), arr.end());
    long long ans = n * mx - (accumulate(arr.begin(), arr.end(), 0LL)) ;
    cout << ans << endl;
    return 0;
}