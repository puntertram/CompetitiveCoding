#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;


void pad(string &S) {
    while(S.length() < 5) {
        S.insert(S.begin(), '0');
    }
}
void split(int N, int &a, int &b) {
    string S = to_string(N);
    pad(S);
    int l = S.length();
    string B = S.substr(l - 3, 3);
    string A = S.substr(l - 5, 2);
    a = stoi(A) * 1000  ;
    b = stoi(B);
}
void transform(int &N) {
    string S = to_string(N);
    pad(S);
    string nS(S);
    nS[0] = S[0];
    nS[1] = S[2];
    nS[2] = S[4];
    nS[3] = S[3];
    nS[4] = S[1];
    N = stoi(nS);
}
void multiply(int &a, int &b, int c, int d) {
    int res = a * d + b * c + b * d;
    split(res, a, b);
}
int main() {
    int N;
    cin >> N;
    int c, d;
    transform(N);
    split(N, c, d);
    int a, b;
    a = 0, b = 1;
    FORN(i, 5)
        multiply(a, b, c, d);
    string S = to_string(a + b);
    pad(S);
    cout << S << endl;
    return 0;
}