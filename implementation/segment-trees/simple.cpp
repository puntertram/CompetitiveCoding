#include <bits/stdc++.h>
#define FOR(a, b) for(int i = a ; i < b; i++)
#define FORI(i, a, b) for(i = a; i < b ; i++)
#define all(x) x.begin(), x.end()
using namespace std;
const int maxn = 1e5 + 5;
int t[4 * maxn];
int n;
vector<int> a;
void build(int v, int tl, int tr) {
    if(tl == tr) {
        t[v] = a[tl];
    } else {
        int tm = (tl + tr) / 2;
        build(v * 2, tl, tm);
        build(v * 2 + 1, tm + 1, tr);
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}
int sum(int v, int tl, int tr, int l, int r) {
    if(l > r)
        return 0;
    if(l == tl and r == tr) {
        return t[v];
    }
    int tm = (tl + tr) / 2;
    return sum(v * 2, tl, tm, l, min(tm, r)) + sum(v * 2 + 1, tm + 1, tr, max(tm + 1, l), r);
}

void update(int v, int tl, int tr, int pos, int new_val) {
    if(tl == tr) {
        t[v] = new_val;
    } else {
        int tm = (tl + tr) / 2;
        if(pos <= tm) {
            update(v * 2, tl, tm, pos, new_val);
        } else {
            update(v * 2 + 1, tm + 1, tr, pos, new_val);
        }
        t[v] = t[v * 2] + t[v * 2 + 1];
    }
}
void solve(){
    cin >> n;
    a.resize(n);
    FOR(0, n) {
        cin >> a[i];
    }
    build(1, 0, n - 1);
    int q;
    cin >> q;
    while(q--) {
        int l, r;
        cin >> l >> r;
        cout << sum(1, 0, n - 1, l, r) << endl;
    }
}
int main() {
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}