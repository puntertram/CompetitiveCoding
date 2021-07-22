/*
  *
  * Solution by Puneeth N Naik
  * I thank God, Mom, Dad for always supporting me throughout times good and bad
  * I love you from the bottom of my heart, I would be nothing without you
  * Thank you Gugan Sir, Chethan CT Sir, Daniel Imms without whom I would not be where i am now
  * I will always value your lessons
  *       
*/
#include <bits/stdc++.h>
#define FOR(a, b) for(ll i = a ; i < b; i++)
#define FORI(i, a, b) for(i = a; i < b ; i++)
#define all(x) x.begin(), x.end()
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;

void solve(){
    ll n;
    cin >> n;
    vector<ll> arr(n);
    FOR(0, n) {
        cin >> arr[i];
    }
    ll q;
    cin >> q;
    ll ans1 = 0;
    arr.push_back(0);
    pair<int, int> pos = {-1, -1};
    vector<ll> pref(arr.size());
    if(arr[0] == 1) {
        // ++n;
        arr.push_back(1);
        arr.erase(arr.begin());
        if(arr.size() == 2) {
            pos = {0, 4};
        } else {
            pos = {0, 3};
        }
    } else {
        FOR(0, n) {
            if(arr[i] == 1) {
                if(arr[i + 1] == 0) {
                    pos = {i, 2};
                } else {
                    pos = {i, 1};
                }
            }
        }
        if(pos.first == -1) {
            pos = {-1, 0};
        }
    }
    // cout << "The type is" << pos.first << " " << pos.second << endl;
    FOR(0, n) {
        if(!i)pref[i] = (arr[i] / 2LL) * 2LL;
        else {
            pref[i] = pref[i - 1] + (arr[i] / 2LL) * 2LL;
            if(pref[i] >= mod)pref[i] -= mod;
        }
    }
    if(pos.second == 1) {
        //size 1
        bool flg1 = arr[pos.first - 1] & 1;
        bool flg2 = arr[n - 1] & 1;
        ans1 = pref[n - 1];
        if(!flg1 && !flg2) {
            ans1 -= 2;
        } else if(!flg1 && flg2) {
        } else if(flg1 && !flg2) {
        } else if(flg1 && flg2) {
            ans1 += 2;
        }
    } else if (pos.second == 2) {
        ans1 = pref[n - 1] + 1; 
    } else if (pos.second == 3) {

    } else if (pos.second == 4) {

    } else if (pos.second == 0) {
        ans1 = pref[n - 1];
        if(arr[n - 1] & 1) {
            ans1++;
        } else {
            ans1--;
        }
    }
    // assert(pos.second != 0);
    while(q--) {
        ll r;
        cin >> r;
        --r;
        ll Q = r / n;
        ll R = r % n;
        ll ans = ((ans1 % mod) * (Q % mod)) % mod;
        ll ans2 = 0;
        if(pos.second == 1) {
                if(R < pos.first) {
                    ans2 = pref[R];
                    if(arr[R] & 1) {
                        ans2++;
                    }
                } else if(R == pos.first) {
                    ans2 = pref[R];
                    ans2++;
                } else if (R > pos.first) {
                    ans2 = pref[R];
                    if(arr[pos.first - 1] & 1)ans2++;
                    else ans2--;
                    if(arr[R] & 1) {
                        ans2++;
                    }
                } 
            ans = (ans + (ans2 % mod)) % mod;
        } else if (pos.second == 2) {
            ans2 = pref[R];
            if(arr[R] & 1) {
                ans2++;
            }
            ans = (ans + (ans2 % mod)) % mod;
        } else if(pos.second == 3) {
            // cout << "Q = " << Q << ", R = " << R << endl;
            if(!r) {
                ans = 1;
            } else {
                if(!R) {
                    ans = Q;
                } else {
                    ans = Q + 1;
                }
            }
        } else if(pos.second == 4) {
            ans = r + 1;
        } else if(pos.second == 0) {
            ans2 = pref[R];
            if(arr[R] & 1) ++ans2;
            ans2 %= mod;
            ans = (ans + (ans2 % mod)) % mod;
        }
        cout << ans << endl;
    }
}
int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}