#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
const int N = 1e7;

int minp[N + 1];
vector<int> primes;
void precalc() {
    for(int i = 2 ; i <= N; i++) {
        if(!minp[i]) {
            // i is a prime
            minp[i] = i;
            primes.push_back(i);
        }
        for(int p : primes) {
            // we index i * p
            if(i * p >  N)break;
            minp[i * p] = p;
            if(i % p == 0)break;
        }
    }
}
int main() {
    precalc();
    int n;
    cin >> n;
    vector<int> d1(n, -1), d2(n, -1);
    FORN(i, n) {
        int A;
        cin >> A;
        vector<int> factorization;
        int _A = A;
        while(A > 1) {
            factorization.push_back(minp[A]);
            A /= minp[A];
        }
        // for example if A = 24, factorization = [2, 2, 2, 3]
        int _d1 = 1;
        int j = 0;
        while((j < factorization.size()) and (factorization[0] == factorization[j])) {
            ++j;
            _d1 *= factorization[0];
        }
        int _d2 = _A / _d1;
        if(_d1 > 1 and _d2 > 1) {
            d1[i] = _d1;
            d2[i] = _d2;
        }
        
    }
    FORN(i, n) {
        cout << d1[i] << " \n"[i == n - 1];
    }
    FORN(i, n) {
        cout << d2[i] << " \n"[i == n - 1];
    }
    return 0;
}