#include <bits/stdc++.h>
#define FOR(a, b) for(int i = a ; i < b; i++)
#define FORI(i, a, b) for(i = a; i < b ; i++)
#define all(x) x.begin(), x.end()
using namespace std;
struct Req {
    int st, en;
    Req(int sta, int end) {
        st = sta;
        en = end;
    }
};
void solve(){
    int n;
    cin >> n;
    vector<Req> requests;
    FOR(0 ,n) {
        int m;
        cin >> m;
        int j = 0;
        FORI(j, 0, m) {
            int st, en;
            cin >> st >> en;
            requests.push_back(Req(st, en));
        }
    }
    /*

    while(l < r) {
        ll mid = (l + r) / 2;
        int cnt = 0;
        for(Req req: requests) {
            if(mid >= req.st and mid <= req.en) {
                cnt++;
            }
        }
        if(cnt)
    }

    */
    for(int i = 1 ; i < 1000; i++) {
        int cnt = 0;
        for(Req req: requests) {
            if(i >= req.st and i <= req.en) {
                cnt++;
            }
        }
        if(!cnt) {
            
        }
    }
    cout << "-1\n";
}
int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}