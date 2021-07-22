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
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int, int> > arr;
        for(int a : nums) {
            arr.push_back({a, 0});
        }
        mSort(arr, 0, arr.size() - 1);    
    }
    void mSort(vector<pair<int, int> > arr, int l, int r) {
        if(l >= r) {
            return;
        }
        int mid = l + (r - l) / 2;
        mSort(arr, l, mid);
        mSort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
    void merge(vector<pair<int, int> > arr, int l, int mid, int r) {
        vector<pair<int, int> > A, B;
        for(int i = l; i <= mid; i++) {
            A.push_back(arr[i]);
        }
        for(int i = mid + 1; i <= r; i++) {
            B.push_back(arr[i]);
        }

        int i = 0, j = 0, k = 0;
        while(i < A.size() and j < B.size()) {
            if(A[i].first < B[j].first) {
                arr[k] = {A[i].first, k + l};
                ++k;
                ++i;
            } else if(A[i].first == B[j].first){
                arr[k] = {A[i].first, k + l};
                ++k;
                ++i;
                arr[k] = {B[j].first, k + l};
                ++k;
                ++j;
            } else {
                arr[k] = {B[j].first, k + l};
                ++k;
                ++j;
            }
        }
        
    }
};

int main() {
    vector<int> arr({5, 2, 6, 1});
    Solution s;
    vector<int> ans = s.countSmaller(arr);

    return 0;
}