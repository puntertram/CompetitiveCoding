/*template created by */
#include <bits/stdc++.h>
#define SI set<int>
#define VI vector<int>
#define ull unsigned long long
#define inint(a) scanf("%d",&a)
#define input(a) cin>>a
#define ll long long
#define print(a) cout<<a
#define printn(a) cout<<a<<"\n"
#define f first
#define s second
#define len(s) s.length()
#define range(a,b,n) for(int i=a;i<b;i+=n)
using namespace std;
int id[300005];
int e;
const int MAX=300005;
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
ll kruskal(pair<ll,pair<int,int> > p[]){
	ll mC=0;
	for(int i=0;i<e;i++){
		int x=p[i].s.f;
		int y=p[i].s.s;
		int c=p[i].f;
		if(get(x)!=get(y)){
			mC+=c;
			Union(x,y);
		}
	}
	return mC;
}
int main()
{
	int t;
	inint(t);
	while(t--){
		int pr;
		init();
		inint(pr);
		int n;
		inint(n);
		inint(e);
		pair<ll,pair<int,int> > p[e];
		for(int i=0;i<e;i++){
			int x,y,c;
			scanf("%d%d%d",&x,&y,&c);
			p[i]=make_pair(c,make_pair(x,y));
		}
		sort(p,p+e);
		cout<<kruskal(p)*pr<<"\n";
	}
	return 0;
}