// https://www.geeksforgeeks.org/next-greater-element/

// Simple C++ program to print
// next greater elements in a
// given array
/*

1. prove that in a stack, at any point of time, we have a decreasing order of elements in it.

*/
#include <bits/stdc++.h>
#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)

#define vti vector<int>
#define vt(x) vector<x>
#define all(x) x.begin(), x.end()
#define read(x) cin >> x
using namespace std;
int main() {
    int n;
    cin >> n;
    vti arr(n);
    FORN(i, n) {
        cin >> arr[i];
    }
    stack<int> S;
    vti ans(n);
    // TODO
    for(int a : arr) {
        if(S.empty())S.push(a);
        else {
            if(a > S.top()) {
                while(!S.empty()) {
                    if(S.top() < a) {

                    }
                }
            } else {

            }
        }
    }
    return 0;
}