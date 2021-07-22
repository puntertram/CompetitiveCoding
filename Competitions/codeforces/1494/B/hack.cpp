//*//
 
#include<bits/stdc++.h>
using namespace std;
 
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define int long long int
const int mod=1000000007;
 
int power(int x,int y){int res=1; x=x%mod;if(x==0)return 0;
while(y>0){if(y&1)res=(res*x)%mod;y=y>>1;x=(x*x)%mod;}return res;} 
 
int ad(int a,int b){return((a%mod+b%mod)%mod);}
int sub(int a  ,int b){return((a%mod-b%mod+mod)%mod);}
int mul(int a,int b){return (((a%mod)*(b%mod))%mod); }
int row[] = { -1, 0, 0, 1 };
int col[] = { 0, -1, 1, 0 };
 
// -.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.
 
void solve(){
	int n;
	cin>>n;
	int u,r,d,l;
	cin>>u>>r>>d>>l;
	if(u<=n-2&&l<=n-2&&r<=n-2&&d<=n-2){
		cout<<"YES\n";
		return;
	}
	if(l<=n-1&&d<=n-1&&l>=1&&d>=1&&u<=n-2&&r<=n-2){
		cout<<"YES\n";
		return;
	}
	if(r>=1&&r<=n-1&&d<=n-1&&d>=1&&u<=n-2&&l<=n-2){
		cout<<"YES\n";
		return;
	}
	if(l>=1&&d>=2&&r>=1&&l<=n-1&&u<=n-2&&r<=n-1){
		cout<<"YES\n";
		return;
	}
	if(u<=n-1&&u>=1&&l<=n-2&&r<=n-1&&r>=1&&d<=n-2){
		cout<<"YES\n";
		return;
	}
	if(l<=n-1&&d<=n-1&&l>=1&&d>=1&&u<=n-1&&u>=1&&r<=n-1&&r>=1){
		cout<<"YES\n";
		return;
	}
	if(r>=2&&d<=n-1&&d>=1&&u<=n-1&&u>=1&&l<=n-2){
		cout<<"YES\n";
		return;
	}
	if(l>=1&&d>=2&&r>=2&&l<=n-1&&u<=n-1&&u>=1){
		cout<<"YES\n";
		return;
	}
 
 
	if(u<=n-1&&u>=1&&l<=n-1&&l>=1&&r<=n-2&&d<=n-2){
		cout<<"YES\n";
		return;
	}
	if(l>=2&&d<=n-1&&u>=1&&d>=1&&u<=n-1&&r<=n-2){
		cout<<"YES\n";
		return;
	}
	if(r>=1&&r<=n-1&&d<=n-1&&d>=1&&u<=n-1&&u>=1&&l>=1&&l<=n-2){
		cout<<"YES\n";
		return;
	}
	if(l>=2&&d>=2&&r>=1&&u<=n-1&&u>=1&&r<=n-1){
		cout<<"YES\n";
		return;
	}
	if(u>=2&&u>=1&&l<=n-1&&l>=1&&r<=n-1&&r>=1&&d<=n-2){
		cout<<"YES\n";
		return;
	}
	if(d>=1&&d<=n-1&&l>=2&&u>=2&&r<=n-1&&r>=1){
		cout<<"YES\n";
		return;
	}
	if(r>=2&&d<=n-1&&d>=1&&u>=2&&l<=n-1&&l>=1){
		cout<<"YES\n";
		return;
	}
	if(l>=2&&d>=2&&r>=2&&u>=2){
		cout<<"YES\n";
		return;
	}
	cout<<"NO\n";
}
	
 
// -.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.-.~.
 
signed main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
 
	int t=1; cin>>t;
	while(t--)
	{
		solve();
	}
    return 0;
}