#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
int convert(string S) {
    int ans = 0;
    for(char ch : S) {
        ans = ans * 10 + (ch - '0');
    }
    return ans;
}
vector<string> TS;
vector<int> cs({0, 1, 2, 5, 8});

bool valid(string T, int h, int m) {
    int H = convert(T.substr(0, 2)), M = convert(T.substr(3, 2));
    return (H >= 0 and H < h and M >= 0 and M < m);
}
string reflection(string T) {
    string ans;
    for(char ch : T) {
        if(ch != ':') {
            switch(ch) {
                case '0': ans += '0';break;
                case '1': ans += '1';break;
                case '2': ans += '5';break;
                case '5': ans += '2';break;
                case '8': ans += '8';break;
            }
        } else {
            ans += ':';
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
void f(string S, int cnt) {
    if(cnt == 4) {
        TS.push_back(S);
        return;
    }
    for(int u : cs) {
        string ns = S + (char)(u + '0');
        if(ns.length() == 2)ns += ':';
        f(ns, cnt + 1);
    }
}
int diff(string orig, string fin, int h, int m) {
    int orr = convert(orig.substr(0, 2)) * m + convert(orig.substr(3, 2));
    int fi = convert(fin.substr(0, 2)) * m + convert(fin.substr(3, 2));
    if(orr <= fi) {
        return fi - orr;
    } else {
        // return orr - fi;
        return fi - orr + h * m;
    }
}
void solve() {
    int h, m;
    cin >> h >> m;
    string T;
    cin >> T;
    string ans;
    int val = INT_MAX;
    // cout << TS.size() << endl;
    for(auto u : TS) {
        if(valid(u, h, m) and valid(reflection(u), h, m)) {
            if(val > diff(T, u, h, m)) {
                val = diff(T, u, h, m);
                ans = u;
            }
            // cout << u << " diff " << diff(T, u, h, m) << endl;
        }
    }
    cout << ans << endl;
}
int main() {
    f("", 0);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}