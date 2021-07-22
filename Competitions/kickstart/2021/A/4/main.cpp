#include <bits/stdc++.h>

#define FOR(i, a, b) for(int i = a ; i < b ; i++)
#define FORN(i, n) FOR(i, 0, n)
#define vti vector<int>
#define vt(x) vector<x>
#define read(x) cin >> x
using namespace std;

const int MAX=5505;
int id[MAX];
int e;
void init(){
	for(int i=0;i<MAX;i++){
		id[i]=i;
	}
}
int get(int x){
	while(id[x]!=x){
		id[x]=id[id[x]];
		x=id[x];
	}
	return x;
}
void Union(int x,int y){
	int a=get(x);
	int b=get(y);
	id[a]=id[b];
}

void solve() {
    init();
    static int ca = 0;
    int ans = 0;
    int n;
    read(n);
    vt(vector<int>) A(n, vt(int)(n));
    FORN(i, n) {
        FORN(j, n) {
            read(A[i][j]);
        }
    }
    FORN(i, n) {
        int prev = -1;
        FORN(j, n) {
            if(A[i][j] == -1) {
                if(prev == -1) {
                    prev = j;
                } else {
                    if(get(i * n + j) == get(i * n + prev)) {
                        
                    }
                }
                
            }
        }
    }
    int x;
    FORN(i, n)read(x);
    FORN(i, n)read(x);
    
    cout << "Case #" << ++ca << ": " << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}