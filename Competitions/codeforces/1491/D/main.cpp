#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
string conv(int n) {
    string ans;
    while(n) {
        ans += char((n & 1) + '0');
        n /= 2;
    }
    // reverse(ans.begin(), ans.end());
    return ans;
}
void balance(string &s, string &t) {
    // cout << s << " " << t << endl;
    int N = abs((int)s.length() - (int)t.length());
    if(s.length() < t.length()) {
        FORN(i, N)s += '0';
    } else {
        FORN(i, N)t += '0';
    }
}
void solve() {
    int u, v;
    cin >> u >> v;
    if(u > v) {
        cout << "NO\n";
    } else {
        string s = conv(u);
        string t = conv(v);
        balance(s, t);
        int i = 0, j = 0;
        int N = s.length();
        while(i < N and j < N) {
            while(i < N and !(s[i] - '0'))++i;
            while(j < N and !(t[j] - '0'))++j;
            if(i >= N or j >= N) {
                if(i >= N and j >= N)break;
                cout << "NO\n";
                return;
            } else if(i > j) {
                cout << "NO\n";
                return;
            }
            ++i, ++j;
        }
        cout << "YES\n";
        // cout << s << " " << t << endl;
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