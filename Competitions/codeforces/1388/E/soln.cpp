#include <bits/stdc++.h>

#define pb push_back
#define x first
#define y second

using namespace std;

const int N = 1e5 + 10;
const double eps = 1e-9;

double xl[N], xr[N], y[N], pi = acos(-1), mn_x, mx_x;
int ind_l, ind_r;

double point_pr(double x, double y, double ctg) {
    return x - y * ctg;
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    vector<pair<double, int> > q;
    vector<pair<double, pair<int, int> > > events, prom_left, prom_right;
    cin >> n;
    pair<double, double> mx, mn;
    mx = {-1.0, -1.0};
    mn = {2e9, 2e9};
    mn_x = 2e9;
    mx_x = -2e9;
    for(int i = 0; i < n; ++i) {
        cin >> xl[i] >> xr[i] >> y[i];

        if(xl[i] < mn_x) {
            mn_x = xl[i];
        }
        if(xr[i] > mx_x) {
            mx_x = xr[i];
        }

        if(mx.y < y[i]) {
            mx.y = y[i];
            mx.x = xl[i];
            ind_l = i;
        }
        else if(mx.y == y[i] && mx.x > xl[i]) {
            mx.y = y[i];
            mx.x = xl[i];
            ind_l = i;
        }

        if(mn.y > y[i]) {
            mn.y = y[i];
            mn.x = xl[i];
            ind_r = i;
        }
        else if(mn.y == y[i] && mn.x < xl[i]) {
            mn.y = y[i];
            mn.x = xl[i];
            ind_r = i;
        }
    }
    double a1, a2;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            if(y[i] > y[j]) {
                a1 = (xr[i] - xl[j]) / (y[i] - y[j]);
                a2 = (xl[i] - xr[j]) / (y[i] - y[j]);
                q.pb({a1, 1});
                q.pb({a2, 2});

                a1 = (xl[i] - xl[j]) / (y[i] - y[j]);
                a2 = (xr[i] - xr[j]) / (y[i] - y[j]);
                events.pb({a1, {i, j}});
                events.pb({a2, {-i - 1, j}});
            }
        }
    }

    if(q.empty()) {
        cout << fixed << setprecision(9) << mx_x - mn_x << endl;
        return 0;
    }

    sort(q.rbegin(), q.rend());
    int cnt = 0;
    double last = 0;
    for(auto i : q) {
        if(i.y == 2) {
            --cnt;
            if(!cnt) {
                events.pb({i.x, {-1e9, -1e9}});
            }
        }
        else {
            if(!cnt) {
                events.pb({i.x, {-1e9, -1e9}});
            }
            ++cnt;
        }
    }
    sort(events.rbegin(), events.rend());
    double ans = 1e18, ang;
    last = -1e18;
    for(auto i : events) {
        if(i.y.x == i.y.y) {
            unordered_set<int> s;
            vector<int> to_check;
            for(auto j : prom_left) {
                s.insert(j.y.x);
                if(j.y.x == ind_l) {
                    to_check.pb(j.y.y);
                }
            }
            prom_left.clear();
            for(auto j : to_check) {
                if(!s.count(j)) {
                    ind_l = j;
                    break;
                }
            }
            s.clear();
            to_check.clear();

            for(auto j : prom_right) {
                s.insert(j.y.y);
                if(j.y.y == ind_r) {
                    to_check.pb(-j.y.x - 1);
                }
            }
            prom_right.clear();
            for(auto j : to_check) {
                if(!s.count(j)) {
                    ind_r = j;
                    break;
                }
            }
            s.clear();
            to_check.clear();

            double res = point_pr(xr[ind_r], y[ind_r], i.x) - point_pr(xl[ind_l], y[ind_l], i.x);
            if(ans > res) {
                ans = res;
                ang = i.x;
                cout << "#" << ang << " " << ind_l << " " << ind_r << endl;
            }
        }
        else if(i.y.x < 0) {
            if(abs(i.x - last) > eps) {
                unordered_set<int> s;
                vector<int> to_check;
                for(auto j : prom_right) {
                    s.insert(j.y.y);
                    if(j.y.y == ind_r) {
                        to_check.pb(-j.y.x - 1);
                    }
                }
                prom_right.clear();
                for(auto j : to_check) {
                    if(!s.count(j)) {
                        ind_r = j;
                        break;
                    }
                }
                s.clear();
                to_check.clear();
            }
            prom_right.pb(i);
        }
        else {
            if(abs(i.x - last) > eps) {
                unordered_set<int> s;
                vector<int> to_check;
                for(auto j : prom_left) {
                    s.insert(j.y.x);
                    if(j.y.x == ind_l) {
                        to_check.pb(j.y.y);
                    }
                }
                prom_left.clear();
                for(auto j : to_check) {
                    if(!s.count(j)) {
                        ind_l = j;
                        break;
                    }
                }
                s.clear();
                to_check.clear();
            }
            prom_left.pb(i);
        }
        last = i.x;
    }
    cout << fixed << setprecision(9) << ans << " " << ang << endl;
    return 0;
}