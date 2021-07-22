#include <bits/stdc++.h>
using namespace std;
 
// minCost maxFlow
 
template <class Cap, class Cost> struct mcf_graph {
  public:
    mcf_graph() {}
    mcf_graph(int n) : _n(n), g(n) {}
 
    int add_edge(int from, int to, Cap cap, Cost cost) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap, cost});
        g[to].push_back(_edge{from, from_id, 0, -cost});
        return m;
    }
 
    struct edge {
        int from, to;
        Cap cap, flow;
        Cost cost;
    };
 
    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{
            pos[i].first, _e.to, _e.cap + _re.cap, _re.cap, _e.cost,
        };
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result(m);
        for (int i = 0; i < m; i++) {
            result[i] = get_edge(i);
        }
        return result;
    }
 
    std::pair<Cap, Cost> flow(int s, int t) {
        return flow(s, t, std::numeric_limits<Cap>::max());
    }
    std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {
        return slope(s, t, flow_limit).back();
    }
    std::vector<std::pair<Cap, Cost>> slope(int s, int t) {
        return slope(s, t, std::numeric_limits<Cap>::max());
    }
    std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);
        std::vector<Cost> dual(_n, 0), dist(_n);
        std::vector<int> pv(_n), pe(_n);
        std::vector<bool> vis(_n);
        auto dual_ref = [&]() {
            std::fill(dist.begin(), dist.end(),
                      std::numeric_limits<Cost>::max());
            std::fill(pv.begin(), pv.end(), -1);
            std::fill(pe.begin(), pe.end(), -1);
            std::fill(vis.begin(), vis.end(), false);
            struct Q {
                Cost key;
                int to;
                bool operator<(Q r) const { return key > r.key; }
            };
            std::priority_queue<Q> que;
            dist[s] = 0;
            que.push(Q{0, s});
            while (!que.empty()) {
                int v = que.top().to;
                que.pop();
                if (vis[v]) continue;
                vis[v] = true;
                if (v == t) break;
                for (int i = 0; i < int(g[v].size()); i++) {
                    auto e = g[v][i];
                    if (vis[e.to] || !e.cap) continue;
                    Cost cost = e.cost - dual[e.to] + dual[v];
                    if (dist[e.to] - dist[v] > cost) {
                        dist[e.to] = dist[v] + cost;
                        pv[e.to] = v;
                        pe[e.to] = i;
                        que.push(Q{dist[e.to], e.to});
                    }
                }
            }
            if (!vis[t]) {
                return false;
            }
 
            for (int v = 0; v < _n; v++) {
                if (!vis[v]) continue;
                dual[v] -= dist[t] - dist[v];
            }
            return true;
        };
        Cap flow = 0;
        Cost cost = 0, prev_cost_per_flow = -1;
        std::vector<std::pair<Cap, Cost>> result;
        result.push_back({flow, cost});
        while (flow < flow_limit) {
            if (!dual_ref()) break;
            Cap c = flow_limit - flow;
            for (int v = t; v != s; v = pv[v]) {
                c = std::min(c, g[pv[v]][pe[v]].cap);
            }
            for (int v = t; v != s; v = pv[v]) {
                auto& e = g[pv[v]][pe[v]];
                e.cap -= c;
                g[v][e.rev].cap += c;
            }
            Cost d = -dual[s];
            flow += c;
            cost += c * d;
            if (prev_cost_per_flow == d) {
                result.pop_back();
            }
            result.push_back({flow, cost});
            prev_cost_per_flow = d;
        }
        return result;
    }
 
  private:
    int _n;
 
    struct _edge {
        int to, rev;
        Cap cap;
        Cost cost;
    };
 
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};
 
// var declarations and helper functions 
 
int n;
int cost;
int cost_up,cost_down,cost_left,cost_right;
vector<int> parity_nodes[2];
int node_rep[51][51];
int x_rep[51*51],y_rep[51*51];
int stop_x[51][51],stop_y[51][51];
vector<string> direction;
bool visited[51][51],in_cycle[51][51];
map<char,int> price;
 
bool is_part_of_cycle(int i, int j)
{
    if(stop_x[i][j] == i && stop_y[i][j] == j)
        return true;
    else
        return false;
}
 
bool has_same_stop(int i, int j, int x, int y)
{
    if(stop_x[i][j] == stop_x[x][y] && stop_y[i][j] == stop_y[x][y])
        return true;
    else
        return false;
}
 
// Directed MST
 
const int N = 100005;
const int E = 1000000;
const int inf = 2139062143;
 
struct edge {
  int u, v, len, id;
}e[N];
int chosen[E];
int pre[N], inwei[N], innum[N], id[N], vis[N];
int inc[E], decr[E], pos;
 
inline int mst(int n, int m, int root) {
  int ans = 0, eg = m;
  pos = m;
  while (true) {
    memset(inwei, 127, sizeof(int) * (n + 2));
    memset(id, 0, sizeof(int) * (n + 2));
    memset(vis, 0, sizeof(int) * (n + 2));
    for (int i = 1; i <= m; i++)
      if (e[i].len < inwei[e[i].v]) {
    inwei[e[i].v] = e[i].len;
    pre[e[i].v] = e[i].u;
    innum[e[i].v] = e[i].id;
      }
    inwei[root] = 0;
    for (int i = 1; i <= n; i++)
      if (inwei[i] == inf) return -1;
    int tot = 0;
    for (int i = 1; i <= n; i++) {
      ans += inwei[i];
      if (i != root) chosen[innum[i]]++;
      int j = i;
      while (vis[j] != i && j != root && !id[j])
    vis[j] = i, j = pre[j];
      if (j != root && !id[j]) {
    id[j] = ++tot;
    for (int k = pre[j]; k != j; k = pre[k]) id[k] = tot;
      }
    }
    if (!tot) break;
    for (int i = 1; i <= n; i++)
      if (!id[i]) id[i] = ++tot;
    n = tot;
    for (int i = 1; i <= m; i++) {
      int v = e[i].v;
      e[i].v = id[e[i].v];
      e[i].u = id[e[i].u];
      if (e[i].v != e[i].u) {
    e[i].len -= inwei[v];
    pos ++;
    inc[pos] = e[i].id;
    decr[pos] = innum[v];
    e[i].id = pos;
      }
      else swap(e[i--], e[m--]);
    }
    root = id[root];
  }
  while (pos > eg) {
    if (chosen[pos] > 0) {
      chosen[inc[pos]]++;
      chosen[decr[pos]]--;
    }
    pos--;
  }
  return ans;
}
bool bad[N];
char orientation[N];
int x_coord[N],y_coord[N];
int edge_cnt = 0;
int vertices = 0;
map<pair<int,int>,int> mp;
 
void put_edge(int s,int t,int i,int j,char d)
{
    edge_cnt++;
    bad[edge_cnt] = 1;
    if(!mp[make_pair(s,t)])
        mp[make_pair(s,t)] = ++vertices;
    if(!mp[make_pair(i,j)])
        mp[make_pair(i,j)] = ++vertices;
    e[edge_cnt].u = mp[make_pair(s,t)];
    e[edge_cnt].v = mp[make_pair(i,j)];
    e[edge_cnt].len = price[d];
    e[edge_cnt].id = edge_cnt;
    x_coord[edge_cnt] = i;
    y_coord[edge_cnt] = j;
    orientation[edge_cnt] = d;
}
 
void form_graph(int i,int j)
{
    if(visited[i][j]) return;
    visited[i][j] = true;
    if(i >= 2 && has_same_stop(i,j,i-1,j))
    {
        put_edge(i,j,i-1,j,'D');
        form_graph(i-1,j);
    }
    if(i <= n-1 && has_same_stop(i,j,i+1,j))
    {
        put_edge(i,j,i+1,j,'U');
        form_graph(i+1,j);
    }
    if(j >= 2 && has_same_stop(i,j,i,j-1))
    {
        put_edge(i,j,i,j-1,'R');
        form_graph(i,j-1);
    }
    if(j <= n-1 && has_same_stop(i,j,i,j+1))
    {
        put_edge(i,j,i,j+1,'L');
        form_graph(i,j+1);
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
 
    cin >> n;
    cin >> cost_up >> cost_left >> cost_down >> cost_right;
    price['U'] = cost_up;
    price['L'] = cost_left;
    price['D'] = cost_down;
    price['R'] = cost_right;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> stop_x[i][j] >> stop_y[i][j];
 
    direction.resize(n+1);
    for(int i = 1; i <= n; ++i)
        for(int j =1; j <= n; ++j)
            direction[i].push_back('N');
 
    int node_cnt = 0;
 
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(is_part_of_cycle(i,j))
            {
                node_rep[i][j] == ++node_cnt;
                x_rep[node_cnt] = i;
                y_rep[node_cnt] = j;
                parity_nodes[(i+j)%2].push_back(node_cnt);
                form_graph(i,j);
                int tmp = edge_cnt;
                cost += mst(vertices,edge_cnt,mp[make_pair(i,j)]);
                for(int k = 1; k <= tmp; ++k)
                    if (chosen[k] && bad[k]) direction[x_coord[k]][y_coord[k]] = orientation[k]; 
 
                edge_cnt = pos = vertices = 0;
                mp.clear();
                for(int k = 0; k <= 10000; ++k)
                {
                    x_coord[k] = y_coord[k] = 0;
                    pre[k] = inwei[k] = innum[k] = id[k] = vis[k] = 0;
                    chosen[k] = bad[k] = 0;
                    orientation[k] = 'N';
                    e[k].u = e[k].v = e[k].len = e[k].id = 0;
                    inc[k] = decr[k] = 0;
                }
            }
        }
    }
 
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
        {
            if(!visited[i][j])
            {
                // cout << "didn't get allocated a path leading to cycle" << endl;
                cout << "-1" << "\n";
                return 0;
            }
        }
    }
 
    if((int)parity_nodes[0].size() != (int)parity_nodes[1].size())
    {
        // cout << "parity mismatch" << endl;
        cout << "-1" << "\n";
        return 0;
    }
 
    mcf_graph<int, long long> g(node_cnt + 2);
    int s = 0, t = node_cnt + 1;
 
    for(auto u:parity_nodes[0])
        g.add_edge(s,u,1,0);
    for(auto v:parity_nodes[1])
        g.add_edge(v,t,1,0);
 
    for(auto u:parity_nodes[0])
    {
        for(auto v:parity_nodes[1])
        {
            if(x_rep[u] == x_rep[v])
            {
                if(abs(y_rep[u]-y_rep[v]) == 1)
                    g.add_edge(u,v,1,cost_left+cost_right);
            }
            if(y_rep[u] == y_rep[v])
            {
                if(abs(x_rep[u]-x_rep[v]) == 1)
                    g.add_edge(u,v,1,cost_up+cost_down);
            }
        }
    }
 
    auto result = g.flow(s, t);
    // cout << "flow done : " << result.first << " " << result.second << "\n";
    if(result.first != (int)parity_nodes[0].size())
        cout << "-1" << "\n";
    else
    {
        auto edges = g.edges();
        for (auto e : edges) {
            if (e.from == s || e.to == t || e.flow == 0) continue;
 
            auto u = e.from;
            auto v = e.to;
            if(x_rep[u] == x_rep[v])
            {
                if(y_rep[u] == y_rep[v]+1)
                    swap(u,v);
                direction[x_rep[u]][y_rep[u]] = 'R';
                direction[x_rep[v]][y_rep[v]] = 'L';
            }
            else
            {
                if(x_rep[u] == x_rep[v]+1)
                    swap(u,v);
                direction[x_rep[u]][y_rep[u]] = 'D';
                direction[x_rep[v]][y_rep[v]] = 'U';
            }
        }
 
        cout << result.second+cost << endl;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
                cout << direction[i][j];
            cout << "\n";
        }
 
    }
    return 0;
}