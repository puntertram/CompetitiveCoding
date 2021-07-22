#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> A(k);
    vector<vector<int> > g(n);
    for(int &a : A) {
        cin >> a;
        --a;
    }
    FORN(i, m) {
        int x, y;
        cin >> x >> y;
        --x, --y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<vector<int> > dist(2, vector<int> (n, -1));
    auto f = [&](int i, int s) {
        queue<int> Q;
        dist[i][s] = 0;
        Q.push(s);
        while(!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for(int v : g[u]) {
                if(dist[i][v] == -1) {
                    dist[i][v] = dist[i][u] + 1;
                    Q.push(v);
                }
            }
        }
    };
    FORN(i, 2) {
        f(i, i ? n - 1 : 0);
    }
    int Max = INT_MIN, best = 0;
    vector<pair<int, int> > data;
    FORN(i, k) {
        data.emplace_back(dist[0][A[i]] - dist[1][A[i]], A[i]);
    }
    sort(all(data));
    for(auto d : data) {
        int a = d.second;
        best = max(best, dist[1][a] + Max);
        Max = max(Max, dist[0][a]);
    }
    cout << min(dist[0][n - 1], best + 1) << endl;
    return 0;
}