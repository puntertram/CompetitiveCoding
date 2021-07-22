#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
class Solution {
    vti cost, time;
    multiset<vti> S;
    vector<vector<vector<int>>> g;
    vti fee;
    int maxTime;
public:
    int dijkstra(int d) {
        S.clear();
        S.insert({cost[0], time[0], 0});
        while(!S.empty()) {
            auto src = *S.begin();
            S.erase(S.begin());
            int c = src[0];
            int t = src[1];
            int u = src[2];
            for(auto v : g[u]) {
                if(t + v[1] <= maxTime) {
                    // consider this path
                    if(c + v[2] < cost[v[0]]) {
                        cost[v[0]] = c + v[2];
                        time[v[0]] = t + v[1];
                        S.insert({cost[v[0]], time[v[0]], v[0]});
                    }
                    else if(t + v[1] < time[v[0]]) {
                        time[v[0]] = t + v[1];
                        S.insert({c + v[2], time[v[0]], v[0]});
                    }
                }
            }
        }
        return cost[d];
    }
    int minCost(int maxTime, vector<vector<int>> edges, vector<int> fee) {
        this->fee = fee;
        this->maxTime = maxTime;
        g.resize(1001);
        cost.assign(1001, INT_MAX);
        time.assign(1001, INT_MAX);
        for(auto edge : edges) {
            g[edge[0]].push_back({edge[1], edge[2], fee[edge[1]]});
            g[edge[1]].push_back({edge[0], edge[2], fee[edge[0]]});
        }
        cost[0] = fee[0];
        time[0] = 0;
        int cost = dijkstra(fee.size() - 1);
        if(cost == INT_MAX) {
            return -1;
        } else {
            return cost;
        }
    }
};
int main() {
    Solution s;
    vector<vector<int>> edges{{0, 1, 10}, {1, 2, 10}, {2, 5, 10}, {0, 3, 1}, {3, 4, 10}, {4, 5, 15}};
    vector<int> fee{5, 1, 2, 20, 20, 3};
    int maxTime = 30;
    cout << s.minCost(maxTime, edges, fee) << endl;  
    return 0;
}