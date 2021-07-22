#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;

void solve() {
    string s;
    cin >> s;
    if(count(all(s), 'a') == s.length()) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    bool found = false;
    FORN(i, s.length() / 2) {
        if(s[i] != s[s.length() - i - 1]) {
            s.insert(next(s.begin(), i + 1), 'a');
            found = true;
            break;
        }
    }
    if(!found) {
        s.insert(s.begin(), 'a');
    }
    cout << s << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}