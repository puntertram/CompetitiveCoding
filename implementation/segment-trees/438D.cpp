    #include "bits/stdc++.h"
    using namespace std;
    #ifdef ONLINE_JUDGE
    #define trace(...)
    #endif
     
    using LL = long long;
    using PII = pair<int, int>;
    #define VAL first
    #define IDX second
     
    class SegmentTree {
    	vector<PII> tree;
    	vector<LL> total;
    	int sz;
     
    	PII query_max(int l, int r, int node, int x, int y) {
    		if (l >= y || r <= x) return {0, -1};
    		if (l <= x && y <= r) return tree[node];
    		return max(query_max(l, r, 2 * node, x, (x + y) / 2),
    			query_max(l, r, 2 * node + 1, (x + y) / 2, y));
    	}
    	LL query_sum(int l, int r, int node, int x, int y) {
    		if (l >= y || r <= x) return 0;
    		if (l <= x && y <= r) return total[node];
    		return query_sum(l, r, 2 * node, x, (x + y) / 2)
    			+ query_sum(l, r, 2 * node + 1, (x + y) / 2, y);
    	}
    public:
    	SegmentTree(int n) {
    		for (sz = 1; sz < n; sz <<= 1);
    		tree.resize(2 * sz, {0, -1});
    		total.resize(2 * sz);
    	}
    	
    	void set(int idx, int val) {
    		int node = sz + idx;
    		tree[node] = {val, idx};
    		total[node] = val;
    		for (node /= 2; node >= 1; node >>= 1) {
    			tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    			total[node] = total[2 * node] + total[2 * node + 1];
    		}
    	}
    	PII getmax(int l, int r) {
    		return query_max(l, r, 1, 0, sz);
    	}
    	LL sum(int l, int r) {
    		return query_sum(l, r, 1, 0, sz);
    	}
    };
     
    int main() {
    	ios_base::sync_with_stdio(false); cin.tie(NULL);
    	int n, m; cin >> n >> m;
    	SegmentTree tree(n);
    	for (int i = 0; i < n; i++) {
    		int a; cin >> a;
    		tree.set(i, a);
    	}
    	while (m--) {
    		int ty; cin >> ty;
    		if (ty == 1) {
    			int l, r; cin >> l >> r;
    			cout << tree.sum(l - 1, r) << '\n';
    		} else if (ty == 2) {
    			int l, r, x; cin >> l >> r >> x;
    			while (true) {
    				auto res = tree.getmax(l - 1, r);
    				if (res.IDX == -1) break;
    				if (res.VAL < x) break;
    				tree.set(res.IDX, res.VAL % x);
    			}
    		} else if (ty == 3) {
    			int i, x; cin >> i >> x;
    			tree.set(i - 1, x);
    		}
    	}
    	return 0;
    }