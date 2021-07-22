#include <bits/stdc++.h>
using namespace std;
bool dup(vector<int> arr) {
    int n = arr.size();
    for(int i = 0 ; i < n - 1 ; i++) {
        if(arr[i] == arr[i + 1])return true;
    }
    return false;
}
void solve() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0 ; i < n ; i++) {
		cin >> arr[i];
	}
    vector<int> brr(arr);
    sort(brr.begin(), brr.end());
	int cnt = 0;
	for(int i = 0 ; i < n ; i++) {
		if(arr[i] != brr[i])++cnt;
	}
	if(cnt == 2) {
		cout << "YES\n";
	} else if(cnt == 0) {
        if(dup(brr)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
	} else {
        cout << "NO\n";
    }
}
int main() {
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
	return  0;
}