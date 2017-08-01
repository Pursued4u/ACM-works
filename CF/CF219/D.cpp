#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<stack>
#include<climits>
#include<ctime>
#include<queue>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("out.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizeof(a))
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
const int maxn = 2e5+5;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
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
int tot;
struct Edge{
    int to,next,w;
}edge[maxn*2];
int head[maxn];
int sum[maxn];
void addedge(int u,int v,int w){
    edge[tot].to = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void dfs(int x,int fa){
    for(int i = head[x];~i;i=edge[i].next){
        int v = edge[i].to;
        int w = edge[i].w;

        if(v!=fa){
            if(w) sum[v] = 1;
            dfs(v,x);
            sum[x]+=sum[v];
        }
    }
}
void dfs1(int x,int fa){
    for(int i= head[x];~i;i=edge[i].next){
        int v = edge[i].to;
        if(v!=fa){
            int w = edge[i].w;
            if(w)sum[v] = sum[x]-1;
            else sum[v] = sum[x]+1;
            dfs1(v,x);
        }
    }
}
int main()
{
    int n = Read();
    MEM(head,-1);
    tot = 0;
    for(int i=1;i<n;i++){
        int u = Read();
        int v = Read();
        addedge(u,v,0);
        addedge(v,u,1);
    }
    dfs(1,-1);
    dfs1(1,-1);
    int ans = inf;
    for(int i=1;i<=n;i++) ans = min(ans,sum[i]);
    cout << ans <<endl;
    for(int i=1;i<=n;i++) if(sum[i] == ans){
        cout << i << " ";
    }
    cout <<endl;


}
