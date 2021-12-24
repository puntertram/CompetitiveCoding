#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
 
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <vector>
#include <string>
#include <deque>
#include <bitset>
#include <algorithm>
#include <utility>
                  
#include <functional>
#include <limits>
#include <numeric>
#include <complex>
 
#include <cassert>
#include <cmath>
#include <memory.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>   
 
using namespace std;
 
typedef long long li;
typedef long double ld;
typedef pair<int,int> pt;
typedef pair<ld, ld> ptd;
typedef unsigned long long uli;
 
#define pb push_back
#define mp make_pair
#define mset(a, val) memset(a, val, sizeof (a))
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ft first
#define sc second
#define sz(a) int((a).size())
#define x first
#define y second
 
template<typename X> inline X abs(const X& a) { return (a < 0 ? -a : a); }
template<typename X> inline X sqr(const X& a) { return (a * a); }
template<typename T> inline string toStr(T x) { stringstream st; st << x; string s; st >> s; return s; }
template<typename T> inline int hasBit(T mask, int b) { return (b >= 0 && (mask & (T(1) << b)) != 0) ? 1 : 0; }
template<typename X, typename T>inline ostream& operator<< (ostream& out, const pair<T, X>& p) { return out << '(' << p.ft << ", " << p.sc << ')'; }
 
inline int nextInt() { int x; if (scanf("%d", &x) != 1) throw; return x; }
inline li nextInt64() { li x; if (scanf("%I64d", &x) != 1) throw; return x; }
inline double nextDouble() { double x; if (scanf("%lf", &x) != 1) throw; return x; }
 
#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fore(i, a, b) for(int i = int(a); i <= int(b); i++)
#define ford(i, n) for(int i = int(n - 1); i >= 0; i--)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
 
const int INF = int(1e9);
const li INF64 = li(INF) * li(INF);
const ld EPS = 1e-9;
const ld PI = ld(3.1415926535897932384626433832795);
 
string s;
int n, p;
int d[1003][27][26][3];  
 
 
inline bool read() {
	return (cin >> n >> p >> s);
}
 
inline int go(int pos, int lst1, int lst2, int changed) {
	int &ans = d[pos][lst1][lst2][changed];
 
	if (ans != -1) return ans;
 
	if (!changed && pos == n) {
		return ans = false;
	}
 
	if (changed && pos == n) {
	 	return ans = true;
	}
 
	ans = 0;
 
	if (!changed) {
		ans |= go(pos + 1, lst2, s[pos] - 'a', changed);
		
		if (ans) return ans;
 
		for(int j = s[pos] - 'a' + 1; j < p; j++) {
			if (lst1 == j || j == lst2) 
				continue;
 
		   	ans |= go(pos + 1, lst2, j, 1);
	   	}
 
	   	if (ans) 
	   		return ans;
	}	
 
	if (changed) {
	 	for(int j = 0; j < p; j++) {
			if (lst1 == j || j == lst2) 
				continue;
 
		   	ans |= go(pos + 1, lst2, j, 1);
	   	}
                   
	}
 
	return ans;
}
 
 
inline void restore(int pos, int lst1, int lst2, int changed) {
	int ans = false;
	
	if (pos == n) {
	 	exit(0);
	}
 
	if (!changed) {
		ans |= go(pos + 1, lst2, s[pos] - 'a', changed);
		
		if (ans) {
		    printf("%c", s[pos]);
			restore(pos + 1, lst2, s[pos] - 'a', changed);
			return;
		}
		
		for(int j = s[pos] - 'a' + 1; j < p; j++) {
			if (lst1 == j || j == lst2) 
				continue;
 
		   	ans |= go(pos + 1, lst2, j, 1);
 
		   	if (ans) {
		   		printf("%c", char(j + 'a'));
		   		restore(pos + 1, lst2, j, 1);
		   		return;
		   	}
	   	}
 
	}	
    
    if (changed) {
	 	for(int j = 0; j < p; j++) {
			if (lst1 == j || j == lst2) 
				continue;
 
		   	ans |= go(pos + 1, lst2, j, 1);
 
		   	if (ans) {
		   		printf("%c", char(j + 'a'));
		   		restore(pos + 1, lst2, j, 1);
		   		return;
		   	}	
	   	}
                   
	}                 
}
 
 
inline void solve() {
	memset(d, -1, sizeof d);
 
	// cerr << go(0, 26, 26, 0) << endl;
 
	if (!go(0, 26, 26, 0)) {
	 	puts("NO");
	 	return;
	}
	else {
	 	restore(0, 26, 26, 0);
	}
 
}
 
int main() 
{
    
	srand(time(NULL));
 
	cout << setprecision(10) << fixed;
	cerr << setprecision(5) << fixed;
	
	assert(read());
	solve();
 
} 