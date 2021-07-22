#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
bool check(string s, char ch) {
    int cnt = 0;
    bool flg = false;
    for(char c : s) {
        if(c == ch){
            flg = true;
            break;
        }
    }
    if(!flg)return false;
    for(char c : s) {
        if(c == ch) {
            if(cnt > 1)return false;
            cnt = 0;      
        } else {
            cnt++;
        }
    }
    if(cnt > 1)return false;
    return true;
}
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    bool done = false;
    FORN(i, n - 1) {
        if(s[i] == '0' and s[i + 1] == '1') continue;
        bool val = check(s.substr(0, i + 1), '0') and check(s.substr(i + 1, n - 1 - i), '1');
        if(val) {
            done = true;
            break;
        }
    }
    if(check(s, '0') or check(s, '1')) {
        done = true;
    }
    
    if(done) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }

}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}