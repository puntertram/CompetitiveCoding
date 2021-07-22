#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
vector<int> arr;
void merge(int st, int mid, int en) {
    //merge arr[st:mid + 1] and arr[mid + 1:en + 1] to a single list
    vector<int> tmp;
    int i = 0, j = 0;
    int p = mid - st + 1;
    int q = en - mid;
    while(i < p and j < q) {
        if(arr[st + i] < arr[mid + 1 + j]) {
            tmp.push_back(arr[st + i]);
            ++i;
        } else if(arr[st + i] == arr[mid + 1 + j]) {
            tmp.push_back(arr[st + i]);
            tmp.push_back(arr[mid + 1 + j]);
            ++i;
            ++j;
        } else {
            tmp.push_back(arr[mid + 1 + j]);
            ++j;
        }
    }
    while(i < p) {
        tmp.push_back(arr[st + i]);
        i++;
    }
    while(j < q) {
        tmp.push_back(arr[mid + 1 + j]);
        j++;
    }
    FOR(i, st, en + 1) { 
        arr[st + i] = tmp[i];
    }
}
void mergeSort(int st, int en) {
    if(st >= en) {
        return;
    }
    cout << st << " " << en << endl;
    int mid = st + (en - st) / 2;
    mergeSort(st, mid);
    mergeSort(mid + 1, en);
    merge(st, mid, en);
}
int main() {
    int n;
    cin >> n;
    arr.resize(n);
    FORN(i, n) {
        cin >> arr[i];
    }
    mergeSort(0, n - 1);
    FORN(i, n) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}