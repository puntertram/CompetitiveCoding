#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int cnt_people = languages.size();
        vector<vector<bool>> knows(cnt_people, vector<bool>(n));
        for(int who = 0; who < cnt_people; ++who) {
            for(int x : languages[who]) {
                knows[who][x-1] = true;
            }
        }
        vector<int> req(n);
        set<int> s;
        for(vector<int> edge : friendships) {
            int a = edge[0] - 1;
            int b = edge[1] - 1;
            bool yes = false;
            for(int x : languages[a]) {
                if(knows[b][x-1]) {
                    yes = true;
                }
            }
            if(yes) {
                continue;
            }
            s.insert(a);
            s.insert(b);
        }
        int best = INT_MAX;
        for(int i = 0; i < n; ++i) {
            int needed = 0;
            for(int person : s) {
                if(!knows[person][i]) {
                    needed++;
                }
            }
            best = min(best, needed);
        }
        return best;
        // return *min_element(req.begin(), req.end());
    }
};

int main() {
    Solution S;
       
    return 0;
}