#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
vector<vector<int> > g;
vector<int> id;
vector<int> sz;
vector<int> visi;
void init(int N) {
    id.resize(N);
    sz.assign(N, 0);
    FORN(i, N) {
        id[i] = i;
    }
}
int getParent(int x) {
    return id[x] == x ? x : (id[x]=getParent(id[x])); 
}
bool merge(int u, int v) {
    int x = getParent(u);
    int y = getParent(v);
    if(x == y) {
        return false;
    }
    if(sz[x] < sz[y]) {
        id[x] = y;
        sz[y] += sz[x];
    } else {
        id[y] = x;
        sz[x] += sz[y];
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    FORN(i, n) {
        cin >> a[i];
    }
    int m;
    cin >> m;
    
    return 0;
}