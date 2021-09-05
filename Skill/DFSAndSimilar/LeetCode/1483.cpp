#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;

class TreeAncestor {
public:
    vector<vector<int> > par;
    TreeAncestor(int n, vector<int>& parent) {
        par.resize(n, vector<int> (20, -1));
        for(int i = 0 ; i < n ; i++) {
            par[i][0] = parent[i];
        }
        for(int level = 1 ; level < 20; level++) {
            for(int node = 0; node < n; node++) {
                if(par[node][level - 1] != -1) {
                    par[node][level] = par[par[node][level - 1]][level - 1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        for(int i = 0 ; i < 20 ; i++) {
            if((k >> i) & 1) {
                node = par[node][i];
                if(node == -1)return node;
            }
        }
        return node;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */



int main() {
    int n = 9;
    vector<int> parent{-1, 0, 0, 2, 2, 3, 3, 4, 4};
    int node = 8;
    int k = 5;
    TreeAncestor* obj = new TreeAncestor(n, parent);
    cout << obj->getKthAncestor(node,k) << endl;
    return 0;
}