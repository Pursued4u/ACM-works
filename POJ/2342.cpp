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
const int maxn = 6e3+5;
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
struct Edge{
    int to,next;
}edge[maxn];
int tot;
int dp[maxn][2];
int vis[maxn];
int head[maxn];
void addedge(int u,int v){
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void dfs(int x){
    for(int i= head[x];~i;i=edge[i].next){
        int v = edge[i].to;
        dfs(v);
        dp[x][0] += max(dp[v][1],dp[v][0]);
        dp[x][1] += dp[v][0];
    }
}
void init(){
    MEM(head,-1);
    tot = 0;
    CLR(dp);
    CLR(vis);
}
int main(){
    #ifdef ONLINE_JUDGE
    #else
        FILEIN;
    #endif
    int n,m;
    while(scanf("%d",&n)!=EOF){
        init();
        for(int i=1;i<=n;i++){
            dp[i][1] = Read();
        }
        int u,v;
        while(scanf("%d %d",&u,&v)&&u+v){
            addedge(v,u);
            vis[u] = 1;
        }
        int root;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                root = i;
                break;
            }
        }
        dfs(root);
        cout << max(dp[root][0],dp[root][1]) << endl;
    }
}
