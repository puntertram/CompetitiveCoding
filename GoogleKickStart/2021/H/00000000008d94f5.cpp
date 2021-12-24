//start of jonathanirvings' template v3.0.3 (BETA)

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef pair<int,int> pii;
typedef pair<LL,LL> pll;
typedef pair<string,string> pss;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef vector<LL> vl;
typedef vector<vl> vvl;

double EPS = 1e-9;
int INF = 1000000005;
long long INFF = 1000000000000000005LL;
double PI = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};


#define FOR(a,b,c) for (int (a)=(b);(a)<(c);++(a))
#define FORN(a,b,c) for (int (a)=(b);(a)<=(c);++(a))
#define FORD(a,b,c) for (int (a)=(b);(a)>=(c);--(a))
#define FORSQ(a,b,c) for (int (a)=(b);(a)*(a)<=(c);++(a))
#define FORC(a,b,c) for (char (a)=(b);(a)<=(c);++(a))
#define FOREACH(a,b) for (auto &(a) : (b))
#define REP(i,n) FOR(i,0,n)
#define REPN(i,n) FORN(i,1,n)
#define MAX(a,b) a = max(a,b)
#define MIN(a,b) a = min(a,b)
#define SQR(x) ((LL)(x) * (x))
#define RESET(a,b) memset(a,b,sizeof(a))
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define ALLA(arr,sz) arr,arr+sz
#define SIZE(v) (int)v.size()
#define SORT(v) sort(ALL(v))
#define REVERSE(v) reverse(ALL(v))
#define SORTA(arr,sz) sort(ALLA(arr,sz))
#define REVERSEA(arr,sz) reverse(ALLA(arr,sz))
#define PERMUTE next_permutation
#define TC(t) while(t--)

inline string IntToString(LL a){
  char x[100];
  sprintf(x,"%lld",a); string s = x;
  return s;
}

inline LL StringToInt(string a){
  char x[100]; LL res;
  strcpy(x,a.c_str()); sscanf(x,"%lld",&res);
  return res;
}

inline string GetString(void){
  char x[1000005];
  scanf("%s",x); string s = x;
  return s;
}

inline string uppercase(string s){
  int n = SIZE(s); 
  REP(i,n) if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';
  return s;
}

inline string lowercase(string s){
  int n = SIZE(s); 
  REP(i,n) if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
  return s;
}

inline void OPEN (string s) {
  #ifndef TESTING
  freopen ((s + ".in").c_str (), "r", stdin);
  freopen ((s + ".out").c_str (), "w", stdout);
  #endif
}

//end of jonathanirvings' template v3.0.3 (BETA)

int Tcases;
int n;
string s;
int l[500005];
int r[500005];
set<int> ada[10];
int num[500005];

void process(int x)
{
  int y = r[x];
  if (l[x] >= 0)
  {
    if (num[x] == (num[l[x]] + 1) % 10) ada[num[l[x]]].erase(l[x]);
  }
  if (r[y] < n)
  {
    if (num[r[y]] == (num[y] + 1) % 10) ada[num[y]].erase(y);
  }

  num[x] = (num[y] + 1) % 10;
  r[x] = r[y];
  if (r[y] < n) l[r[y]] = x;

  if (l[x] >= 0)
  {
    if (num[x] == (num[l[x]] + 1) % 10) ada[num[l[x]]].insert(l[x]);
  }
  if (r[x] < n)
  {
    if (num[r[x]] == (num[x] + 1) % 10) ada[num[x]].insert(x);
  }
}

int main()
{
  scanf("%d",&Tcases);
  REPN(cases,Tcases)
  {
    REP(i,10) ada[i].clear();

    scanf("%d",&n);
    s = GetString();
    REP(i,n) num[i] = s[i] - '0';

    REP(i,n)
    {
      l[i] = i - 1;
      r[i] = i + 1;
    }
    REP(i,n-1)
    {
      if (num[i+1] == (num[i] + 1) % 10) ada[num[i]].insert(i);
    }
    while (1)
    {
      bool ok = 0;
      REP(i,10)
      {
        while (SIZE(ada[i]) > 0)
        {
          int x = *ada[i].begin();
          ada[i].erase(ada[i].begin());
          process(x);
          ok = 1;
        }
      }
      if (!ok) break;
    }

    string risan = "";
    int now = 0;
    while (now < n)
    {
      risan += (char)(num[now] + '0');
      now = r[now];
    }

    printf("Case #%d: %s\n",cases,risan.c_str());
  }
  return 0;
}








