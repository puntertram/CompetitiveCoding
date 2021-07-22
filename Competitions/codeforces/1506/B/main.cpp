#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
void solve() {
    int n, k;
    // cin >> n >> k;
    read(n);
    read(k);
    string s;
    read(s);
    vti arr;
    FORN(i, n) {
	if(s[i] == '*') {
		arr.push_back(i);
	}
    }
    if(arr.size() == 1) {
	cout << "1\n";
	return;
    }
    int ans = 0;
    for(int i = 0 ; i < n; ){
	ans++;
	auto it  = upper_bound(all(arr), arr[i] + k);
	if(it == arr.end()) {
		++ans;
		break;
	}
	it--;
	i = (it - arr.begin());
    }
    cout << ans << endl;
}
int main() {
    int t;
    read(t);
    while(t--) {
        solve();
    }
    return 0;
}
