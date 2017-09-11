#include<bits/stdc++.h>
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
const int maxn = 1e5+5;
const int maxm = 1e6+5;
typedef long long ll;
typedef double db;
const ll inf =  LLONG_MAX;
const ll mod = 1e9 + 7;
ll mul(ll x,ll y){return x*y%mod;}
ll q_mul(ll a, ll b){ ll ans = 0;while(b){if(b & 1){ans=(ans+a)%mod;} b>>=1;a=(a+a) % mod;}return ans;}
ll q_pow(ll x , ll y){ll res=1;while(y){if(y&1) res=q_mul(res,x) ; y>>=1 ; x=q_mul(x,x);} return res;}
ll inv(ll x) { return q_pow(x, mod-2); }
int Read() {
    int x = 0, F = 1; char C = getchar();
    while (C < '0' || C > '9') { if (C == '-') F = -F; C = getchar(); }
    while (C >= '0' && C <= '9') { x = x * 10 - '0' + C, C = getchar(); }
    return x * F;
}
struct edge{
	int d,u,v,c;
	bool operator<(const edge&t)const{
		return d<t.d;
	}
}e[maxn];
int n,m,k;
ll a[maxm*2],b[maxm*2];
int dis[maxn],d[maxn];
int main(){
	n=Read();
    m=Read();
    k=Read();
	int maxx=-1;
	for(int i=1;i<=m;i++){
		e[i].d=Read();
        e[i].u=Read();
        e[i].v=Read();
		e[i].c=Read();
		maxx=max(maxx,e[i].d);
	}
	sort(e+1,e+1+m);
	ll now=inf;
	int cnt=n;
	for(int i=1;i<=m;i++){
		int cur=e[i].d;
        int u = e[i].u;
		if(u)
        {
			if(!dis[u]){
				dis[u]=e[i].c;
                cnt--;
				if(!cnt){
					now=0;
					for(int i=1;i<=n;i++){
                        now+=dis[i];
                    }
					a[cur]=now;
				}
			}
			else if(dis[u]>e[i].c){
				if(!cnt) {
					now-=dis[u];
				    dis[u]=e[i].c;
				    now+=e[i].c;
				    a[cur]=now;
				}
				else dis[u]=e[i].c;
			}
		}
	}
	now=inf;
    cnt=n;
	for(int i=m;i>=1;i--){
		int cur=e[i].d;
        int v = e[i].v;
		if(v){
			if(!d[v]){
				d[v]=e[i].c;
                cnt--;
				if(!cnt){
					now=0;
					for(int i=1;i<=n;i++){
                        now+=d[i];
                    }
					b[cur]=now;
				}
			}
			else if(d[v]>e[i].c){
				if(!cnt){
				    now-=d[v];
				    d[v]=e[i].c;
				    now+=e[i].c;
				    b[cur]=now;
				}
				else d[v]=e[i].c;;
			}
		}
	}
	ll ans=inf;
    for(int i=1;i<=maxx;i++){
        if(!a[i]) a[i]=a[i-1];
        else if(a[i-1]) a[i]=min(a[i],a[i-1]);
    }
	for(int i=maxx;i>=1;i--){
        if(!b[i])   b[i]=b[i+1];
        else if(b[i+1]) b[i]=min(b[i],b[i+1]);
    }

	for(int i=1;i<=maxx-k-1;i++){
		if(a[i]&&b[i+k+1])
            ans=min(ans,a[i]+b[i+k+1]);
	}
	if(ans!=inf)cout<<ans<<endl;
	else cout<<-1<<endl;
}
