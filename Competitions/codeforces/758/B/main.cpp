#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;

int main() {
    string s;
    cin >> s;
    map<int, char> M;
    FORN(i, s.length()) {
        if(s[i] != '!'){
            M[i % 4] = s[i];
        }
    }
    map<char, int> ans;
    FORN(i, s.length()) {
        if(s[i] == '!') {
            ans[M[i % 4]]++;
        }
    }
    cout << ans['R'] << " " << ans['B'] << " " << ans['Y'] << " " << ans['G'] << endl;
    return 0;
}