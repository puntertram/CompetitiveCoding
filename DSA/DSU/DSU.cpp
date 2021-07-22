#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
const int MAXN = 1e5 + 5;
vector<int> id(MAXN);
void init() {
    FORN(i, MAXN) {
        id[i] = i;
    }
}
int get(int x) {
    while(id[x] != x) {
        x = id[id[x]];
        x = id[x];
    }
    return x;
}
void Union(int x, int y) {
    id[x] = id[y];
}
vector<pair<int, pair<int, int> > > p;

// int kruskal() {
//     int mC = 0;
//     for(auto u : p) {
//         if(get(u.second.first) != get(u.second.second)) {
//             Union(u.second.first, u.second.second);
//             mC += u.first;
//         }
//     }
//     return mC;
// }
int main() {
    int n;
    cin >> n;

    return 0;
}