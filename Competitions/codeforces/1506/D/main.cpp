#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
void solve() {
	int n;
	read(n);
	priority_queue<int> S;
	map<int, int> fre;
	int x;
	FORN(i, n) {
		read(x);
		fre[x]++;
	}
	for(auto u : fre) {
		S.push(u.second);
	}
	while(S.size() > 1) {
		int f, s;
		f = S.top();
		S.pop();
		s = S.top();
		S.pop();
		S.push(f - s);
		//cout << f << s << endl;
	}
	cout << S.top() << endl;
	
}
int main() {
    	int t;
    	read(t);
    	while(t--) {
		solve();
	}
    	return 0;
}
