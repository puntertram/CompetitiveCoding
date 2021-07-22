#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
int main() {
    int n;
    cin >> n;
    // vector<pair<int, int> > P;
    cout << "YES\n";
    FORN(i, n) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        // P.emplace_back(min(a, x), min(b, y));
        pair<int, int> A = {min(a, x), min(b, y)};
        if((A.first & 1) and (A.second & 1)) {
            cout << "1\n";
        } else if((A.first & 1) and !(A.second & 1)) {
            cout << "2\n";
        } else if(!(A.first & 1) and (A.second & 1)) {
            cout << "3\n";
        } else if(!(A.first & 1) and !(A.second & 1)) {
            cout << "4\n";
        }
    }
    
    return 0;
}