#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vt(vti) g;
    vti visi;
    g.resize(n);
    visi.resize(n);

    FORN(i, m) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
    }
    queue<int> Q;
    int x;
    cin >> x;
    Q.push(x);
    while(!Q.empty()) {
        
        int u = Q.front();
        cout << u << " ";
        Q.pop();
        visi[u] = true;
        for(int v : g[u]) {
            if(!visi[v]) {
                Q.push(v);
            }
        }
    }
    cout << endl;
    return 0;
}