#include <bits/stdc++.h>
#define FOR(a, b) for(int i = a ; i < b; i++)
#define FORI(i, a, b) for(i = a; i < b ; i++)
#define all(x) x.begin(), x.end()
using namespace std;
vector<int> parent;
vector<int> cc_rank;
void make_set(int v) {
    parent[v] = v;
    cc_rank[v] = 0;
}
int find_set(int v) {
    if(v == parent[v]) {
        return v;
    }
    return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if(a != b) {
        if(cc_rank[a] < cc_rank[b]) {
            swap(a, b);
        }
        parent[b] = a;
        if(cc_rank[a] == cc_rank[b]) {
            cc_rank[a]++;
        }
    }
}
struct Edge {
    int u, v, weight;
    Edge(int u, int v, int w) {
        this->u = u;
        this->v = v;
        this->weight = w;
    }
    bool operator<(Edge const& other) {
        return weight > other.weight;
    }
};
int n, m;
vector<Edge> edges;
int cost = 0;
void solve(){
    cin >> n >> m;
    for(int i = 0 ; i < m ; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(Edge(u, v, w));
    }
    parent.resize(n);
    cc_rank.resize(n);
    for(int i = 0 ; i < n ; i++) {
        make_set(i);
    } 
    sort(all(edges));
    for(Edge e: edges) {
        if(find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            union_sets(e.u, e.v);
        }
    }
    if(cost & 1) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
int main() {
    int t = 1;
    while(t--){
        solve();
    }
    return 0;
}