#include <bits/stdc++.h>

#define MOD (1000000007)
#define EPS (1e-9)
#define INF (2117117117)
#define LLINF (2117117117117117117LL)
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define sqr(a) ((a) * (a))
#define sz(a) ((int) (a).size())
const double PI = acos(-1.0);

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

typedef unsigned int uint;
typedef long long llong;
typedef long double ldouble;
typedef unsigned long long ullong;

#define TASK "task"

using namespace std;

const int MAXN = 500117, MAXLN = 20;

int n, m, q, a, b, fup[MAXN], d[MAXN], 
    comp[MAXN], comp2[MAXN], cn, p[MAXLN][MAXN], timer, tin[MAXN], tout[MAXN];
bool h[MAXN];
pair<int, int> qa[MAXN];
vector<int> g[MAXN], gt[MAXN];
vector<pair<int, int> > qv[MAXN];

void calc(int v, int cid, int depth = 0, int par = -1)
{
    h[v] = true;
    d[v] = depth;
    fup[v] = d[v];
    comp[v] = cid;
    for (auto u : g[v])
    {
        if (h[u])
        {
            if (u != par)
                fup[v] = min(fup[v], d[u]);
            else
                par = -1;
            continue;
        }
        calc(u, cid, d[v] + 1, v);
        fup[v] = min(fup[v], fup[u]);
    }
}

void compress(int v, int cid)
{
    h[v] = true;
    comp2[v] = cid;
    for (auto u : g[v])
    {
        if (h[u])
            continue;
        if (fup[u] > d[v])
        {
            gt[comp2[v]].pb(cn);
            p[0][cn] = cid;
            compress(u, cn++);
        }
        else
            compress(u, comp2[v]);
    }
}

void build_lca(int v, int par, int depth = 0)
{
    tin[v] = timer++;
    d[v] = depth;
    p[0][v] = par;
    for (int i = 1; i < MAXLN; i++)
        p[i][v] = p[i - 1][p[i - 1][v]];
    for (auto u : gt[v])
        build_lca(u, v, d[v] + 1);
    tout[v] = timer++;
}

bool is_par(int v, int u) { return tin[v] < tin[u] && tout[u] < tout[v]; }

int get_lca(int v, int u)
{
    if (is_par(v, u))
        return v;
    if (is_par(u, v))
        return u;
    for (int i = MAXLN - 1; i >= 0; i--)
        if (!is_par(p[i][v], u))
            v = p[i][v];
    return p[0][v];
}

pair<int, int> dfs(int v)
{
    int dir = -1, up = d[p[0][v]];
    for (auto qq : qv[v])
    {
        if (dir == -1)
        {
            dir = qq.first;
            up = qq.second;
        }
        else if (dir == qq.first)
            up = min(up, qq.second);
        else
        {
            printf("No\n");
            exit(0);
        }
    }
    for (auto u : gt[v])
    {
        pair<int, int> tmp = dfs(u);
        int dir_u = tmp.first, up_u = tmp.second;
        if (up_u < d[v])
        {
            if (dir == -1)
            {
                dir = dir_u;
                up = up_u;
            }
            else if (dir == dir_u)
                up = min(up, up_u);
            else
            {
                printf("No\n");
                exit(0);
            }
        }
    }
    return mp(dir, up);
}

int main()
{
#ifdef lordf
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#else
    //freopen(TASK".in", "r", stdin);
    //freopen(TASK".out", "w", stdout);
#endif

    scanf("%d %d %d", &n, &m, &q);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &a, &b);
        a--;
        b--;
        g[a].pb(b);
        g[b].pb(a);
    }
    for (int i = 0; i < q; i++)
    {
        scanf("%d %d", &qa[i].first, &qa[i].second);
        qa[i].first--;
        qa[i].second--;
    }

    memset(h, false, sizeof(h));
    cn = 0;
    for (int i = 0; i < n; i++)
        if (!h[i])
            calc(i, cn++);
    
    memset(h, false, sizeof(h));
    cn = 0;
    for (int i = 0; i < n; i++)
        if (!d[i])
        {
            p[0][cn] = cn;
            compress(i, cn++);
        }

    timer = 0;
    for (int i = 0; i < cn; i++)
        if (p[0][i] == i)
            build_lca(i, i);

    for (int i = 0; i < q; i++)
    {
        int v = qa[i].first, 
            u = qa[i].second;
        if (comp[v] != comp[u])
        {
            printf("No\n");
            return 0;
        }
        v = comp2[v];
        u = comp2[u];
        if (v == u)
            continue;
        int l = get_lca(v, u);
        if (v != l)
            qv[v].pb(mp(0, d[l]));
        if (u != l)
            qv[u].pb(mp(1, d[l]));
    }

    for (int i = 0; i < cn; i++)
        if (!d[i])
            dfs(i);

    printf("Yes\n");

    return 0;
}