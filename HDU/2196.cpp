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
const int maxn = 1e4+5;
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

int head[maxn];
int dp[maxn][3];
struct Edge{
    int to,next,w;
}edge[maxn];
int tot;
void addedge(int u,int v,int w){
    edge[tot].to = v;
    edge[tot].next = head[u];
    edge[tot].w = w;
    head[u] = tot++;
}
void init(){
    MEM(head,-1);
    tot = 0;
    CLR(dp);
}
void dfs1(int x){
    int max1 = 0;
    int max2 = 0;
    for(int i = head[x];~i;i=edge[i].next){
        int v = edge[i].to;
        dfs1(v);
        int cnt = dp[v][0]+edge[i].w;
        if(cnt>=max1){
            max2 = max1;
            max1 = cnt;
        }
        else if(max2<cnt){
            max2 = cnt;
        }

    }
    dp[x][0] = max1;
    dp[x][1] = max2;
}

void dfs2(int x){
    for(int i=head[x];~i;i=edge[i].next){
        int v = edge[i].to;
        dp[v][2] = max(dp[x][2],dp[v][0]+edge[i].w==dp[x][0]?dp[x][1]:dp[x][0])+edge[i].w;
        dfs2(v);
    }
}
int main(){
    #ifdef ONLINE_JUDGE
    #else
        FILEIN;
    #endif
    int n;
    while(scanf("%d",&n)!=EOF){
        init();
        for(int i=2;i<=n;i++){
            int v = Read();
            int w = Read();
            addedge(v,i,w);;
        }
        dfs1(1);
        dfs2(1);
        for(int i=1;i<=n;i++){
            printf("%d\n",max(dp[i][0],dp[i][2]));
        }
    }
}
