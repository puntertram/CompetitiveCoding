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
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int low = 0, high = n * n - 1;
        while(low < high) {
            int mid = low + (high - low) / 2;
            if(isConnected(grid, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
    }
    bool isConnected(vector<vector<int> >& grid, int waterHeight) {
        int n = grid.size();
        vector<vector<int> > visited(n, vector<int> (n, 0));
        vector<int> dir({-1, 0, 1, 0, -1});
        if(max(grid[0][0], waterHeight) > waterHeight) {
            return false;
        }
        return dfs(grid, visited, dir, waterHeight, 0, 0, n);
    }
    bool valid(int r, int c, int n) {
        return (r >= 0) and (r < n) and (c >= 0) and (c < n);
    }
    bool dfs(vector<vector<int> >& grid, vector<vector<int> >& visited, vector<int> &dir, int waterHeight, int row, int col, int n) {
        if(row == (n - 1) and col == (n - 1))return true;
        visited[row][col] = 1;
        for(int i = 0 ; i < 4 ; i++) {
            int r = row + dir[i];
            int c = col + dir[i + 1];
            if(valid(r, c, n) and visited[r][c] == 0 and max(grid[r][c], waterHeight) <= waterHeight) {
                if(dfs(grid, visited, dir, waterHeight, r, c, n)) return true;
            }
        }
        return false;
    }
};

int main() {
    Solution *S = new Solution();
    vector<vector<int> > grid;
    grid.push_back(vector<int> ({0, 2}));
    grid.push_back(vector<int> ({1, 3}));

    int ans = S->swimInWater(grid);
    cout << "ans : " << ans << endl;
    return 0;
}