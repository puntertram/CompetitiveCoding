#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()

#define x first
#define y second

typedef long long li;
typedef pair<int, int> pt;

template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
	return out << "(" << p.x << ", " << p.y << ")";
}
template<class A> ostream& operator <<(ostream& out, const vector<A> &v) {
	fore(i, 0, sz(v)) {
		if(i) out << " ";
		out << v[i];
	}
	return out;
}

const int INF = int(1e9);
const li INF64 = li(1e18);

int n, m, k;
vector<int> x, y;
vector<pt> ps;

inline bool read() {
	if(!(cin >> n >> m >> k))
		return false;
	x.resize(n);
	fore (i, 0, n)
		cin >> x[i];
	y.resize(m);
	fore (i, 0, m)
		cin >> y[i];
	ps.resize(k);
	fore (i, 0, k)
		cin >> ps[i].x >> ps[i].y;
	
	return true;
}

inline void solve() {
	li ans = 0;
	
	fore (_i, 0, 2) {
		vector<int> cntY(m, 0);
		sort(all(ps));
		
		vector<pt> bord(k);
		
		int u = 0;
		while (u < k) {
			int v = u;
			while (v < k && ps[v].x == ps[u].x)
				v++;
			
			fore (i, u, v) {
				int r = int(lower_bound(all(y), ps[i].y) - y.begin());
				int l = r;
				if (y[l] > ps[i].y)
					l--;
				assert(y[l] <= ps[i].y && ps[i].y <= y[r]);
				
				bord[i] = {l, r};
			}
			
			fore (i, u, v) if (bord[i].x < bord[i].y)
				ans += cntY[bord[i].x];
			
			fore (i, u, v) if (bord[i].x < bord[i].y)
				cntY[bord[i].x]++;
			
			u = v;
		}
		
		
		fore (i, 0, k)
			swap(ps[i].x, ps[i].y);
		swap(x, y);
		swap(n, m);
	}
	
	cout << ans << endl;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	int t; cin >> t;
	while (t--) {
		read();
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}