#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
int main() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> ps(n + 1), mvexp(n);
    int bl = -1, br = -1, bv = -1;
    FORN(i, n) {
        ps[i + 1] = ps[i] + (s[i] == '[' ? 1 : 0);
    }
    stack<int> S;
    auto match = [&](char A, char B) {
        return (A == '[' and B == ']') or (A == '(' and B == ')');
    };
    FORN(i, n) {
        if(s[i] == '[' or s[i] == '(') {
            S.push(i);
            mvexp[i] = -1;
        } else {
            if(S.empty() or !match(s[S.top()], s[i])) {
                mvexp[i] = -1;
                while(!S.empty())S.pop();
            } else {
                if((S.top() != 0) and (mvexp[S.top() - 1] != -1)) {
                    mvexp[i] = mvexp[S.top() - 1];
                } else {
                    mvexp[i] = S.top();
                }
                if(ps[i + 1] - ps[mvexp[i]] > bv) {
                    bl = mvexp[i];
                    br = i;
                    bv = ps[i + 1] - ps[mvexp[i]];
                }
                S.pop();
            }
            
        }
    }
    if(bv >= 0) {
        cout << bv << endl;
        FOR(i, bl, br + 1) {
            cout << s[i];
        }
        cout << endl;
    } else {
        cout << "0\n";
    }
    return 0;
}