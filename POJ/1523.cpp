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
const int maxn = 1e3+5;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;
ll mul(ll x,ll y)
{
    return x*y%mod;
}
ll q_mul(ll a, ll b)
{
    ll ans = 0;
    while(b)
    {
        if(b & 1)
        {
            ans=(ans+a)%mod;
        }
        b>>=1;
        a=(a+a) % mod;
    }
    return ans;
}
ll q_pow(ll x, ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1) res=q_mul(res,x) ;
        y>>=1 ;
        x=q_mul(x,x);
    }
    return res;
}
ll inv(ll x)
{
    return q_pow(x, mod-2);
}
int Read()
{
    int x = 0, F = 1;
    char C = getchar();
    while (C < '0' || C > '9')
    {
        if (C == '-') F = -F;
        C = getchar();
    }
    while (C >= '0' && C <= '9')
    {
        x = x * 10 - '0' + C, C = getchar();
    }
    return x * F;
}
vector<int>G[maxn];
int low[maxn];
int dfn[maxn];
int num;
int id,n;
bool vis[maxn];
bool bj[maxn];

void dfs(int u)
{
    low[u] = dfn[u] = ++id;
    int ch = 0;
    for(int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i];
        if(!dfn[v])
        {
            dfs(v);
            ch++;
            if(low[v]>=dfn[u]&&u!=1) vis[u] = 1;
            low[u] = min(low[v],low[u]);
        }
        else low[u] = min(low[u],dfn[v]);

    }
    if(u==1&&ch>=2) vis[1] = true;
}
void init(int n)
{
    for(int i=1; i<=n; i++) G[i].clear();
    CLR(dfn);
    CLR(low);
    CLR(vis);
    CLR(bj);
}
void check(int u,int fa)
{
    bj[u] = 1;
    for(int i=0; i<G[u].size(); i++)
    {
        int v = G[u][i];
        if(!bj[v])
        {
            if(u==fa) num++;
            check(v,fa);
        }
    }
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    FILEIN;
#endif
    int a;
    int ss = 0;
    int ca = 1;
    init(n);
    while(~scanf("%d",&a))
    {
        if(!a)
        {
            if(!ss) break;
            dfs(1);
            int flag=0;

            printf("Network #%d\n",ca++);
            for(int i=1; i<=n; i++)
            {
                if(vis[i])
                {
                    flag = 1;
                    num = 0;
                    check(i,i);
                    printf("  SPF node %d leaves %d subnets\n",i,num);
                    CLR(bj);
                }
            }

            if(!flag||n==2)cout << "  No SPF nodes" <<"\n";
            ss = 0;
            init(n);
            cout << "\n";
        }
        else
        {
            int b = Read();
            G[a].push_back(b);
            G[b].push_back(a);
            n = max(n,max(a,b));
            ss = 1;
        }

    }
}
