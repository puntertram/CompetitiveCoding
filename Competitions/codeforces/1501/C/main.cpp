#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

using namespace std;
const int maxs = 5e6 + 5;

int LOG[maxs][2];
void solve() {
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<pair<int, int> > ele;
    FORN(i, n) {
        cin >> arr[i];
        ele.push_back({arr[i], i + 1});
    }
    sort(ele.begin(), ele.end());
    FORN(i, n) {
        arr[i] = ele[i].first;
    }
    FORN(i, n) {
        FOR(j, 0, i) {
            if(LOG[arr[i] + arr[j]][0]) {
                if(LOG[arr[i] + arr[j]][0] == j)continue;
                if(LOG[arr[i] + arr[j]][1] == j)continue;
                cout << "YES\n";
                cout << ele[j].second << " " << ele[i].second << " " << ele[LOG[arr[i] + arr[j]][0]].second << " " << ele[LOG[arr[i] + arr[j]][1]].second << endl;
                return;
            }
        }
        FOR(j, 0, i) {
            LOG[arr[i] + arr[j]][0] = j;
            LOG[arr[i] + arr[j]][1] = i;
        }
    }
    cout << "NO\n";
}
int main() {
    solve();
    return 0;
}