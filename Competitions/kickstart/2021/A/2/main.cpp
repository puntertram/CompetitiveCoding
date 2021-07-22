#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
bool check(pair<int, pair<int, int> > A, pair<int, pair<int, int> > B) {
    int la = A.second.second - A.second.first + 1;
    int lb = B.second.second - B.second.first+ 1;
    if(la >= 2 and lb >= 2) {
            if(A.first >= B.second.first and A.first <= B.second.second and B.first >= A.second.first and B.first <= A.second.second) {
                return true;
            } else return false;
    } else return false;
}
void pr(pair<int, pair<int, int> > P) {
    cout << P.first  <<  ", <" << P.second.first << ", " << P.second.second << ">\n";
}
int f(int l1, int l2) {
    return min(l1, l2 / 2) + min(l2, l1 / 2) - 2;
}

pair<int, int> inter(pair<int, pair<int, int> > A, pair<int, pair<int, int> > B) {
    return {A.first, B.first};
}
void solve() {
    static int ca = 0;
    int ans = 0;
    vector<pair<int, pair<int, int> > > H, V;
    int n, m;
    cin >> n >> m;
    vector<vector<int> > M(n + 2, vector<int>(m + 2));
    // int x;
    FORN(i, n) {
        FORN(j, m) {
          cin >> M[i + 1][j + 1];
        //   M[]  
        }
    }
    // FORN(i, n + 1) {
    //     FORN(j, m + 1) {
    //         cout << M[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    FOR(i, 1, n + 1) {
        int st = -1, en = -1;
        FORN(j, m + 1) {
            if(M[i][j] == 0 and M[i][j + 1] == 0) {
                st = -1, en = -1;
            } else if(M[i][j] == 0 and M[i][j + 1] == 1){
                st = j + 1;
            } else if(M[i][j] == 1 and M[i][j + 1] == 0) {
                en = j;
                H.push_back({i, {st, en} });
                st = -1, en = -1;
            } else if(M[i][j] == 1 and M[i][j + 1] == 1) {

            }
        }
    }
    FOR(i, 1, m + 1) {
        int st = -1, en = -1;
        FORN(j, n + 1) {
            if(M[j][i] == 0 and M[j + 1][i] == 0) {
                st = -1, en = -1;
            } else if(M[j][i] == 0 and M[j + 1][i] == 1){
                st = j + 1;
            } else if(M[j][i] == 1 and M[j + 1][i] == 0) {
                en = j;
                V.push_back({i, {st, en} });
                st = -1, en = -1;
            } 
        }
    }
    FORN(i, H.size()) {
        FORN(j, V.size()) {
            if(check(H[i], V[j])) {
                //cout << "cons\n" ;
                // pr(H[i]) ;
                // //cout <<  " and \n";
                //  pr(V[j])  ;
                int la = H[i].second.second - H[i].second.first + 1;
                int lb = V[j].second.second - V[j].second.first+ 1;
                if(la > lb)swap(la, lb);
                
                auto p = inter(H[i], V[j]);
                int l1 = abs(p.first - V[j].second.first) + 1, l2 = abs(p.second - H[i].second.first) + 1;
                int l3 = abs(p.first - V[j].second.second) + 1, l4 = abs(p.second - H[i].second.second) + 1;
                //cout << "point of intersection is " << p.first << " " << p.second << endl;;
                //cout << "The lengths are" << l1 << " " << l2 << " " << l3 << " " << l4 << endl;
                int val = 0;
                if(l1 >= 2 and l2 >= 2) {
                    val += f(l1, l2);
                } if(l1 >= 2 and l4 >= 2) {
                    val += f(l1, l4);
                } if(l3 >= 2 and l2 >= 2) {
                    val += f(l2, l3);
                }if(l3 >= 2 and l4 >= 2) {
                    val += f(l3, l4);
                }
                //cout << "add " << val << endl;
                ans += val;
                //cout << "-----\n";
                // ans += (min(2 * la, lb) / 2) - 1;
            }
        }
    }
    // cout << "f(4, 4) = " << f(4, 4) << endl;
    cout << "Case #" << ++ca << ": " << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}