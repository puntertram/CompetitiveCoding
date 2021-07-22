#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	vector<int> arr(n);
	for(int i = 0 ; i < n ; i++) {
		cin >> arr[i];
	}
	int prev;
	if(arr[0] < arr[1]) {
		prev = 0;
	} else if (arr[0] == arr[1]) {
		prev = 1;
	} else {
		prev = 2;
	}
	int cnt = 1;
	vector<pair<int, int> > ds;
	for(int i = 1 ; i < n - 1 ; i++) {
		int type;
		if (arr[i] < arr[i + 1]) {
			type = 0;
		} else if(arr[i] == arr[i + 1]) {
			type = 1;
		} else {
			type = 2;
		}
		if (prev == -1) {
			// ds.push_back({type, cnt});
			prev = type;
			// ++cnt;
		} else {
			if (prev != type) {
				ds.push_back({prev, cnt});
				cnt = 1;
				prev = type;
			} else {
				++cnt;
			}
		}
	}
	ds.push_back({prev, cnt});
	for(auto it : ds) {
		cout << it.first << " " << it.second << endl;
	}
	if(ds[0].first == 0) {
		ds.erase(ds.begin());
	}
	int ans = 0;
	for(int i = 0 ; i < ds.size(); i++) {
		if(ds[i].first == 1) {
			int pre, post;
			if(!i) {
				pre = 0;
			} else {
				pre = ds[i - 1].first;
			}
			if(i == ds.size() - 1) {
				post = -1;
			} else {
				post = ds[i + 1].first;
			}
			if(post == -1) {
				ans += ds[i].second;
			} else {
				if(ds[i].second & 1) {
					if(pre != post) {
						ds[i].second--;
					}
				} else {
					if(pre == post) {
						ds[i].second--;
					}
				}
				ans += ds[i].second;
			}
		} else if (ds[i].first == 2 or ds[i].first == 0) {
			++ans;
		}
	}
	cout << ans + 1 << endl;
	return 0;
}