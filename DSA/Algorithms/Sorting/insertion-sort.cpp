#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
void insertion_sort(vector<int> &arr) {
    int n = arr.size();
    FOR(i, 1, n) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 and arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    FORN(i, n) {
        cin >> arr[i];
    }
    insertion_sort(arr);
    FORN(i, n) {
        cout << arr[i] << " ";
    }
    return 0;
}