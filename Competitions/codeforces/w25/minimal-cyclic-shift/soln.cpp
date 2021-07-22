#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
#define forn(i,n) for (int i = 0; i < int(n); ++i)
typedef long long ll;
typedef long long i64;
typedef long double ld;
const int inf = int(1e9) + int(1e5);
const ll infl = ll(2e18) + ll(1e10);

const int mod = 998244353;
const int maxn = 200100;
int a[maxn], b[maxn], c[maxn];
int coef[maxn];
int n, k;

int add(int a, int b) {
    a += b;
    if (a >= mod)
        a -= mod;
    return a;
}

int sub(int a, int b) {
    return add(a, mod - b);
}

int mul(ll a, ll b) {
    return (a * b) % mod;
}

int binpow(int a, int deg) {
    int res = 1;
    while (deg) {
        if (deg & 1)
            res = mul(res, a);
        deg /= 2;
        a = mul(a, a);
    }
    return res;
}

int inv(int x) {
    assert(x != 0);
    return binpow(x, mod - 2);
}


const int root = 787603194;
const int LG = 19;

vector<int> ang[2][LG + 1];

void initFFT() {
    int rroot = inv(root);
    int x0 = 1, x1 = 1;
    ang[0][LG].resize(1 << LG);
    ang[1][LG].resize(1 << LG);
    forn (i, 1 << LG) {
        ang[0][LG][i] = x0;
        ang[1][LG][i] = x1;
        x0 = mul(x0, root);
        x1 = mul(x1, rroot);
    }
    for (int lg = LG - 1; lg >= 0; --lg) {
        forn (q, 2) {
            ang[q][lg].resize(1 << lg);
            forn (i, 1 << lg)
                ang[q][lg][i] = ang[q][lg + 1][i * 2];
        }
    }
}

void recFFT(int *a, int lg, bool inv) {
    if (lg == 0)
        return;
    int hlen = (1 << lg) >> 1;
    recFFT(a, lg - 1, inv);
    recFFT(a + hlen, lg - 1, inv);
    forn (i, hlen) {
        int u = a[i];
        int v = mul(ang[inv][lg][i], a[i + hlen]);
        a[i] = add(u, v);
        a[i + hlen] = sub(u, v);
    }
}

void FFT(int *a, int n, bool inv) {
    int lg = 0;
    while ((1 << lg) < n)
        ++lg;
    assert(n == (1 << lg));
    int j = 0, bit;
    for (int i = 1; i < n; ++i) {
        for (bit = n >> 1; j & bit; bit >>= 1)
            j ^= bit;
        j ^= bit;
        if (i < j)
            swap(a[i], a[j]);
    }
    recFFT(a, lg, inv);
    if (inv) {
        int rn = ::inv(n);
        forn (i, n)
            a[i] = mul(a[i], rn);
    }
}

void initCoef() {
    int p = 1;
    for (int i = 1; i <= k + 1; ++i)
        p = mul(p, i);
    int q = 1;
    for (int i = 1; i <= k; ++i)
        q = mul(q, mod - i);
    p = mul(p, inv(q));
    for (int i = 0; i <= k; ++i) {
        coef[i] = mul(p, inv(k + 1 - i));
        p = mul(p, mod - k + i);
        p = mul(p, inv(i + 1));
    }
}

int pi[maxn];

int A[1 << LG];
int B[1 << LG];
int C[1 << LG];
void pmul(int n, int m) {
    int N = 1 << LG;
    for (int i = n; i < N; ++i)
        A[i] = 0;
    for (int i = m; i < N; ++i)
        B[i] = 0;
    FFT(A, N, false);
    FFT(B, N, false);
    forn (i, N)
        C[i] = mul(A[i], B[i]);
    FFT(C, N, true);
}

int s[maxn];
int t[maxn];

int calcSym(int *a) {
    int val = 0;
    for (int j = 0; j <= k; ++j)
        val = add(val, mul(coef[j], a[j]));
    return sub(a[k + 1], val);
}

int main() {
    #ifdef LOCAL
    assert(freopen("test.in", "r", stdin));
    #endif
    cin >> n >> k;
    if (k + 1 >= n) {
        cout << 0 << '\n';
        return 0;
    }
    forn (i, n)
        cin >> a[i];
    forn (i, n) {
        cin >> b[i];
        b[i + n] = b[i];
    }
    initFFT();
    initCoef();

    forn (i, k + 1)
        A[i] = coef[k - i];
    forn (i, n)
        B[i] = a[i];
    pmul(k + 1, n);
    for (int i = 0; i + k + 1 < n; ++i)
        t[i] = sub(a[i + k + 1], C[i + k]);

    forn (i, k + 1)
        A[i] = coef[k - i];
    forn (i, 2 * n)
        B[i] = b[i];
    pmul(k + 1, 2 * n);
    forn (i, n)
        s[i + n] = s[i] = sub(b[i + k + 1], C[i + k]);

    int len = n - k - 1;

    //forn (i, len)
        //cerr << t[i] << ' ';
    //cerr << '\n';
    //forn (i, n)
        //cerr << s[i] << ' ';
    //cerr << '\n';

    for (int i = 1; i < len; ++i) {
        int q = pi[i - 1];
        while (q > 0 && t[q] != t[i])
            q = pi[q - 1];
        if (t[q] == t[i])
            ++q;
        pi[i] = q;
    }
    int q = 0;
    forn (i, 2 * n) {
        while (q > 0 && t[q] != s[i])
            q = pi[q - 1];
        if (t[q] == s[i])
            ++q;
        if (q == len) {
            cout << i - len + 1 << '\n';
            return 0;
        }
    }
    cout << -1 << '\n';
}