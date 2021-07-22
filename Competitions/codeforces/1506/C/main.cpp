#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
void solve() {
	string a, b;
	read(a);
	read(b);
	if(a.length() < b.length())swap(a, b);
	int ans = a.length() + b.length();
	FORN(i, b.length()) {
		FOR(j, i, b.length()) {
			string tmp = b.substr(i, j - i + 1);
			FORN(k, a.length()) {
				string tmx = a.substr(k, min((int)a.length(), k + (int)tmp.length()) - k);

				if(tmx == tmp) {
					ans = min(ans, (int)a.length() + (int)b.length() - 2 * (int)tmp.length());
				} 
			} 
		}
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
