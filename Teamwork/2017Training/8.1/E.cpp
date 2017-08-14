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
const int maxn = 1e5+5;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;
ll mul(ll x,ll y){return x*y%mod;}
ll q_mul(ll a, ll b){ ll ans = 0;while(b){if(b & 1){ans=(ans+a)%mod;} b>>=1;a=(a+a) % mod;}return ans;}
ll q_pow(ll x , ll y){ll res=1;while(y){if(y&1) res=q_mul(res,x) ; y>>=1 ; x=q_mul(x,x);} return res;}
ll inv(ll x) { return q_pow(x, mod-2); }

const int MAX_N = 1e6+7;

struct edge{
    int to,next;
    int from;
    long long val;
};

int n,m;
edge E[MAX_N*2];
int esz;
int head[MAX_N];
int b[MAX_N],pre[MAX_N];
long long dis[MAX_N];
bool vis[MAX_N];
long long ans;

void add_edge(int from,int to,int val){
    E[esz].from = from;
    E[esz].to = to,E[esz].val = val,E[esz].next = head[from];
    head[from] = esz;
    esz++;
}

ll son[MAX_N];
void dfs(int x,int fa)
{
    son[x]=1;
    for(int i=head[x];~i;i=E[i].next){
        int v = E[i].to;
        if(v!=fa){
            dfs(v,x);
            son[x]+=son[v];
        }
    }
}
void solve(){
    esz = 0;
    memset(head,-1,sizeof(head));
    memset(vis,0,sizeof(vis));
    for(int i = 0;i < n-1;++i){
        int u,v,w;  scanf("%d%d%d",&u,&v,&w);
        add_edge(u,v,w);add_edge(v,u,w);
    }
    ans = 0;
    dfs(1,-1);
    vis[1]= 1;
    for(int i=0;i<esz;i++){
        dbg(son[E[i].to]);
        if(son[E[i].to]>m&&!vis[E[i].to])
            ans+=E[i].val*m;
        else if(!vis[E[i].to]){
            ans+=E[i].val*(son[E[i].to]);
        }
        cout << ans <<endl;
        vis[E[i].to] = 1;
    }
    cout << ans <<endl;
}

int main()
{
    while(~scanf("%d%d",&n,&m))  solve();
    return 0;
}
