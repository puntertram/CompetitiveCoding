#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

class Solution {
    vector<vector<char> > board;
public:
    bool valid(int i, int j) {
        return (i >= 0 and i < board.size()) and (j >= 0 and j < board[0].size());
    }
    void DFS(int i, int j) {
        board[i][j] = '#';
        for(int dir = 0 ; dir < 4; dir++) {
            int ni = i + dx[dir];
            int nj = j + dy[dir];
            if(valid(ni, nj) and board[ni][nj] == '0') {
                DFS(ni, nj);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        this->board = board;
        for(int j = 0 ; j < n ; j++) {
            if(this->board[0][j] == 'O') {
                DFS(0, j);
            } 
            if(this->board[m - 1][j] == 'O') {
                DFS(m - 1, j);
            }
        }
        
        for(int i = 0 ; i < m ; i++) {
            if(this->board[i][0] == 'O') {
                DFS(i, 0);        
            }
            if(this->board[i][n - 1] == 'O') {
                DFS(i, n - 1);
            }
        }
        
        for(int i = 0 ; i < m ; i++) {
            for(int j = 0 ; j < n ; j++) {
                if(this->board[i][j] == '#') {
                    board[i][j] = 'O';
                } else if(this->board[i][j] == '0') {
                    board[i][j] = 'X';
                }
            }
        }
        
    }
};

int main() {
    Solution *S = new Solution();
    int m = 4, n = 4;
    vector<vector<char> > board;
    for(int i = 0 ; i < m ; i++) {
        vector<
    }
    // S->solve();

    return 0;
}