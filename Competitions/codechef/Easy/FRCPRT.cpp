#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;

void processForce(vector<string> &grid, int force) {
    int n = grid.size();
    int m = grid[0].length();
    if(force == 'L') {
        FORN(i, n) {
            int cnt = count(all(grid[i]), '1');
            grid[i] = string(cnt, '1') + string(m - cnt, '0');
        }

    } else if (force == 'R') {
        FORN(i, n) {
            int cnt = count(all(grid[i]), '1');
            grid[i] = string(m - cnt, '0') + string(cnt, '1');
        }
    } else if(force == 'U') {
        FORN(i, m) {
            string S;
            FORN(j, n) {
                S += grid[j][i];
            }
            int cnt = count(all(S), '1');
            FORN(j, n) {
                if(cnt-- > 0) {
                    grid[j][i] = '1';
                } else {
                    grid[j][i] = '0';
                }
            }
        }
    } else {
        FORN(i, m) {
            string S;
            FORN(j, n) {
                S += grid[j][i];
            }
            int cnt = count(all(S), '0');
            FORN(j, n) {
                if(cnt-- > 0) {
                    grid[j][i] = '0';
                } else {
                    grid[j][i] = '1';
                }
            }
        }
    }
}

void displayGrid(vector<string> grid) {
    for(auto gr : grid) {
        cout << gr << endl;
    }
}
void solve() {
    int n, m;
    cin >> n >> m ;
    vt(string) grid(n);
    FORN(i, n) {
        cin >> grid[i];
    }
    string _forces, forces;
    cin >> _forces;
    forces += _forces[0];
    _forces.erase(_forces.begin());
    if(_forces.length() > 1) {
        char lastA = '$', lastB = '$';
        for(char force : _forces) {
            if(force == 'L' or force == 'R') {
                lastA = force;
            } else {
                lastB = force;
            }
        }
        if(_forces.back() == lastA) {
            if(lastB != '$') {
                forces += lastB;
            }
            forces += lastA;
        } else {
            if(lastA != '$') {
                forces += lastA;
            }
            forces += lastB;
        }
    }
    
    for(char force : forces) {
        processForce(grid, force);
    }
    displayGrid(grid);
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}