#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x

typedef long long ll;

const ll mod = 1e9 + 7;


using namespace std;

ll mul(ll a, ll b) {
    ll c = ((a % mod) * (b % mod)) % mod;
    if(c < 0) {
        c += mod;
    }
    return c;
}

ll qp(ll a, ll b) {
    ll res = 1;
    ll expo = a;
    while(b) {
        int dig = b & 1;
        if(dig) {
            res = mul(res, expo);
        }
        expo = mul(expo, expo);
        b /= 2;
    }
    return res;
}


int main() {
    ll n, x;
    cin >> n >> x;
    vt(ll) A(n);
    FORN(i, n) {
        cin >> A[i];
    }   
    ll sum = accumulate(all(A), 0LL);
    priority_queue<ll, vector<ll>, greater<ll> > pq;
    FORN(i, n) {
        pq.push(sum - A[i]);
    }
    ll t = 0;
    while(!pq.empty()) {
        t = pq.top();
        ll cnt = 0;
        while((!pq.empty()) and (pq.top() == t)) {
            cnt++;
            pq.pop();
        }
        if(cnt % x)break;
        while(cnt % x == 0) {
            ++t;
            cnt /= x;
        }
        FORN(j, cnt) {
            pq.push(t);
        }
    }
    cout << qp(x, min(t, sum)) << endl;
    return 0;
}