#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
const int MOD = 1e9 + 7;
vector<int> id;
void init() {
    FORN(i, id.size()) {
        id[i] = i;
    }
}
int get(int x) {
    if(id[x] == x)return x;
    return id[x] = get(id[x]);
}
bool Union(int x, int y) {
    int A = get(x);
    int B = get(y);
    id[A] = B;
    return A != B;
}
int main() {
    int n, m;
    
    cin >> n >> m;
    id.resize(m + 1);
    init();
    vector<int> ans;
    FORN(i, n) {
        int k;
        cin >> k;
        int A, B = m;
        cin >> A;
        --A;
        if(k > 1) {
            cin >> B;
            --B;
        }
        if(Union(A, B)) {
            ans.push_back(i + 1);
        }
    }
    int res = 1;
    FORN(i, ans.size()) {
        res = (res + res) % MOD;
        if(res < 0)res += MOD;
    }
    cout << res << " " << ans.size() << endl;
    for(int a : ans) {
        cout << a << " ";
    }
    cout << endl;
    return 0;
}