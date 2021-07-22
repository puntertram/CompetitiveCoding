#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
typedef pair<double, pair<int, int> >  pdii;
typedef pair<double, int>  pii;
const double eps = 1e-9;
double calc(double x, double y, double angle) {
    return x - angle * y;
}
int main() {
    int n;
    cin >> n;
    vector<double> xl(n), xr(n), y(n);
    pair<int, int> mn = {INT_MAX, INT_MAX}, mx = {INT_MIN, INT_MIN};
    double mx_x = INT_MIN, mn_x = INT_MAX;
    int ind_l = -1, ind_r = -1;
    FORN(i, n) {
        cin >> xl[i] >> xr[i] >> y[i];
        
        if(mn_x > xl[i]) {
            mn_x = xl[i];
        } 
        if(mx_x < xr[i]) {
            mx_x = xr[i];
        }
        
        if(mx.second < y[i]) {
            mx = {xl[i], y[i]};
            ind_l = i;
        } else if(mx.second == y[i] and xl[i] < mx.first) {
            mx = {xl[i], y[i]};
            ind_l = i;
        }

        if(mn.second > y[i]) {
            mn = {xr[i], y[i]};
            ind_r = i;
        } else if(mn.second == y[i] and mn.first< xr[i]) {
            mn = {xr[i], y[i]};
            ind_r = i;
        }
    }
    vector<pii> q;
    vector<pdii> events;
    FORN(i, n) {
        FORN(j, n) {
            if(y[i] > y[j]) {
                double A = (xr[i] - xl[j]) / (y[i] - y[j]);
                double B = (xl[i] - xr[j]) / (y[i] - y[j]);
                q.emplace_back(A, 1);
                q.emplace_back(B, 2);
                A = (xr[i] - xr[j]) / (y[i] - y[j]);
                B = (xl[i] - xl[j]) / (y[i] - y[j]);
                events.push_back({A, {-i-1, j}});
                events.push_back({B, {i, j}});
            }
        }
    }
    if(q.empty()) {
        cout << fixed << setprecision(12) << mx_x - mn_x << endl;
        return 0;
    }
    int cnt = 0;
    sort(all(q));
    reverse(all(q));
    
    for(auto i : q) {
        if(i.second == 1) {
            if(cnt == 0) {
                events.push_back({i.first, {INT_MIN, INT_MIN}});
            }
            ++cnt;
        } else {
            --cnt;
            if(cnt == 0) {
                events.push_back({i.first, {INT_MIN, INT_MIN}});
            }
        }
    }
    double last, ang, ans = 1e18;
    sort(all(events));
    reverse(all(events));
    vector<pdii> prom_left, prom_right;
    for(auto e : events) {
        if(e.second.first == e.second.second) {
            set<int> S;
            vector<int> to_check;
            for(auto j : prom_right) {
                S.insert(j.second.second);
                if(j.second.second == ind_r) {
                    to_check.push_back(-j.second.first - 1);
                }
            }
            for(auto j : to_check) {
                if(!S.count(j)) {
                    ind_r = j;
                    break;
                }
            }
            prom_right.clear();
            S.clear();
            to_check.clear();

            for(auto j : prom_left) {
                S.insert(j.second.first);
                if(j.second.first == ind_l) {
                    to_check.push_back(j.second.second);
                }
            }

            for(auto j : to_check) {
                if(!S.count(j)) {
                    ind_l = j;
                    break;
                }
            }

            prom_left.clear();

            double res = calc(xr[ind_r], y[ind_r], e.first) - calc(xl[ind_l], y[ind_l], e.first);
            if(ans > res) {
                ans = res;
                ang = e.first;
                // cout << "#" << ang << " " << ind_l << " " << ind_r << endl;
            }
        } else if(e.second.first < 0) {
            if(abs(e.first - last) > eps) {
                set<int> S;
                vector<int> to_check;
                for(auto j : prom_right) {
                    S.insert(j.second.second);
                    if(j.second.second == ind_r) {
                        to_check.push_back(-j.second.first - 1);
                    }
                }
                for(auto j : to_check) {
                    if(!S.count(j)) {
                        ind_r = j;
                        break;
                    }
                }
                prom_right.clear();
            }
            prom_right.push_back(e);
        } else {
            if(abs(last - e.first) > eps) {
                set<int> S;
                vector<int> to_check;
                for(auto j : prom_left) {
                    S.insert(j.second.first);
                    if(j.second.first == ind_l) {
                        to_check.push_back(j.second.second);
                    }
                }
                for(auto j : to_check) {
                    if(!S.count(j)) {
                        ind_l = j;
                        break;
                    }
                }
                prom_left.clear();
            }
            prom_left.push_back(e);
        }
        last = e.first;
    }
    cout << fixed << setprecision(15);
    cout << ans << endl;
    return 0;
}