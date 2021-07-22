#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
bool valid(string S) {
    stack<char> st;
    for(char c : S) {
        if(st.empty()) {
            st.push(c);
        } else {
            char top = st.top();
            if(top == '(' and c == ')')st.pop();
            else if(top == '(' and c == '(')st.push(c);
        }
    }
    return st.empty();
}
string con(string S, map<char, char> M) {
    string ret;
    for(char c : S) {
        ret += M[c];
    }
    return ret;
}
char C[] = {'A', 'B', 'C'};
void solve() {
    string s;
    cin >> s;
    FORN(i, 8) {
        map<char, char> M;
        FORN(j, 3) {
            if((i + 1) & (1 << j)) {
                M[C[j]] = '(';
            } else {
                M[C[j]] = ')';
            }
        }
        if(valid(con(s, M))) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}