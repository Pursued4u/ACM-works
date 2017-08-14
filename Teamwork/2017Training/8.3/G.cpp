#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<set>
#include<stack>
#include<climits>
#include<ctime>
#include<queue>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("out.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizoef(a))
#define eps 1e-8
#define sf(x) scanf("%d",&x)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define fi first
#define se second
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl
using namespace std;
const int maxn = 1e6+5;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 998244353;
ll mul(ll x,ll y){return x*y%mod;}
ll q_mul(ll a, ll b){ ll ans = 0;while(b){if(b & 1){ans=(ans+a)%mod;} b>>=1;a=(a+a) % mod;}return ans;}
ll q_pow(ll x , ll y){ll res=1;while(y){if(y&1) res=q_mul(res,x) ; y>>=1 ; x=q_mul(x,x);} return res;}
ll inv(ll x) { return q_pow(x, mod-2); }

const int MAXN = 1000000+7;

struct edge{
	int to,val,next;
};

int head[MAXN*2];
edge e[MAXN*2];
int esz,tot;
int val[MAXN*2];
bool vis[MAXN*2];

void add_edge(int from,int to,int val){
	e[esz].to = to,e[esz].val = val,e[esz].next = head[from];
	head[from] = esz++;
}

void DFS(int x){
	vis[x] = true;
	//-printf("%d " ,x);
	for(int i = head[x];i != -1;i = e[i].next){
		int v = e[i].to;
		if(vis[v])  continue;
		val[tot++] = e[i].val;
		DFS(v);
	}
}

void solve(){
	memset(head,-1,sizeof(head));
	memset(vis,false,sizeof(vis));
	esz = 0;
	int n;scanf("%d",&n);
	for(int i = 0;i < n;++i){
		int u = i+1,v,w;
		scanf("%d%d",&v,&w);
		v += n+1;
		add_edge(u,v,w);
		add_edge(v,u,w);
		scanf("%d%d",&v,&w);
		v += n+1;
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	long long ans = 1;
	for(int i = 1;i < n+1;++i){
		if(!vis[i]){
			tot = 0;
			DFS(i);
			val[tot++] = e[e[head[i]].next].val;
			ll a = 1,b = 1;
//			for(int j = 0;j < tot;++j){
//				printf("%d ",val[j]);
//			}
//			puts("");
			for(int j = 0;j < tot;++j){
				if(j&1)  b= (b*val[j])%mod;
				else a=(a*val[j])%mod;
			}
			ans = ans*(a+b)%mod;
		}
	}
	printf("%I64d\n",ans);
}

int main()
{
	int t;scanf("%d",&t);
	while(t--)solve();
	return 0;
}
