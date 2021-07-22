#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)
using namespace std;
#define pii pair<int, int> 
#define f first
#define s second
vector<vector<int> > M;
int dx[] = {1, -1, 0, 0}, dy[] = {0, 0, -1, 1};
bool valid(int x, int y) {
    return x >= 0 and x < M.size() and y >= 0 and y < M[0].size();
}
int ans = 0;
void dfs(int x, int y, int val) {    
    if(val > M[x][y])
        ans += val - M[x][y];
    cout << "vis" << x << " " << y << " " << val << " " << M[x][y] << endl;
    int valt = INT_MIN;
    M[x][y] = INT_MIN;
    
    FORN(i, 4) {
        int xx = x + dx[i], yy = y + dy[i];
        if(valid(xx, yy) and M[xx][yy] != INT_MIN) {
            valt = max(valt, M[xx][yy]);
        }
    }
    if(valt == M[x][y]) {

    } else {
        valt = M[x][y] - 1;
    }
    FORN(i, 4) {
        int xx = x + dx[i], yy = y + dy[i];
        if(valid(xx, yy) and M[xx][yy] != INT_MIN) {
            dfs(xx, yy, valt);
        }
    }
}
void solve() {
    static int ca = 0;
    // int ans = 0;
    int n, m;
    cin >> n >> m;
    M.clear();
    M.assign(n, vector<int> (m));
    ans = 0;
    pii pos = {-1, -1};
    int val = INT_MIN;
    FORN(i, n) {
        FORN(j, m) {
            cin >> M[i][j];
            if(M[i][j] > val) {
                val = M[i][j];
                pos = {i, j};
            }
        }
    }
    dfs(pos.f, pos.s, val);
    cout << "Case #" << ++ca << ": " << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}