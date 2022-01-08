#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;


class Solution {
public:
    bool valid(int i, int j, int n) {
        return (i >= 0) and (i < n) and (j >= 0) and (j < n);
    }
    int dfs(vector<vector<int> > &grid, vector<int> &dir, int i, int j, int index, int n) {
        int ans = 1;
        grid[i][j] = index;
        for(int k = 0 ; k < 4 ; k++) {
            int ni = i + dir[k];
            int nj = j + dir[k + 1];
            if(valid(ni, nj, n) and grid[ni][nj] == 1) {
                ans += dfs(grid, dir, ni, nj, index, n);
            }
        }
        return ans;
    }
    int largestIsland(vector<vector<int>>& grid) {
        map<int, int> Area;
        int index = 2;
        int n = grid.size();
        vector<int> dir({-1, 0, 1, 0, -1});
        int ans = 0;
        for(int i = 0 ; i < n; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j] == 1) {
                    Area[index] = dfs(grid, dir, i, j, index, n);
                    ans = max(ans, Area[index]);
                    index++;

                }
            }
        }

        for(int i = 0 ; i < n ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(grid[i][j] == 0) {
                    set<int> neighbors;
                    for(int k = 0 ; k < 4 ; k++) {
                        int ni = i + dir[k];
                        int nj = j + dir[k + 1];
                        if(valid(ni, nj, n))
                            neighbors.insert(grid[ni][nj]);
                    }
                    int cand = 1;
                    for(int neighbor : neighbors) {
                        cand += Area[neighbor];
                    }
                    ans = max(ans, cand);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution * S = new Solution();
    vector<vector<int> > grid(5, vector<int> (5, 0));
    grid[0] = vector<int> ({0, 0, 1, 1, 0});
    int ans = S->largestIsland(grid);  
    cout << ans << endl;
    return 0;
}