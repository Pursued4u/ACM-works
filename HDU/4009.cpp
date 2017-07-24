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
const int maxm = 1e3+5;
const int maxn = 1e6+maxm;
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
struct Edge
{
    int u,v,cost;
    Edge (){}
    Edge (int _u,int _v,int _cost){
        u = _u;
        v = _v;
        cost = _cost;
    }
};
Edge edge[maxn];
struct point{
    int x,y,z;
}po[maxm];
int dis(point a,point b){
    return abs(a.x-b.x)+abs(a.y-b.y)+abs(a.z-b.z);
}
int pre[maxm],id[maxm],vis[maxm],in[maxm];
int ZL(int root,int n,int m,Edge edge[])
{
    int res = 0,u,v;
    while(1)
    {
        for(int i=0; i<n; i++) in[i] = inf;
        for(int i=0; i<m; i++)
            if(edge[i].u!=edge[i].v&&edge[i].cost<in[edge[i].v])
            {
                pre[edge[i].v] = edge[i].u;
                in[edge[i].v] = edge[i].cost;
            }
        for(int i=0; i<n; i++)
        {
            if(i!=root&&in[i]==inf)
            {
                return -1;
            }
        }
        int cnt = 0;
        MEM(vis,-1);
        MEM(id,-1);
        in[root] = 0;
        for(int i=0; i<n; i++)
        {
            res+= in[i];
            v = i;
            while(vis[v]!=i&&id[v]==-1&&v!=root)
            {
                vis[v] = i;
                v = pre[v];
            }
            if(v!=root&&id[v]==-1)
            {
                for(int u = pre[v]; u!=v; u=pre[u]) id[u] = cnt;
                id[v] = cnt++;
            }
        }
        if(!cnt) break;
        for(int i=0; i<n; i++)
        {
            if(id[i]==-1) id[i] = cnt++;
        }
        for(int i=0; i<m; i++)
        {
            v = edge[i].v;
            edge[i].u = id[edge[i].u];
            edge[i].v = id[edge[i].v];
            if(edge[i].v!=edge[i].u)
            {
                edge[i].cost -=in[v];
            }
        }
        n = cnt;
        root = id[root];
    }
    return res;
}
int main()
{
#ifdef ONLINE_JUDGE
#else
    FILEIN;
#endif
    int n,x,y,z;
    while(scanf("%d %d %d %d",&n,&x,&y,&z)&&n)
    {
        int k = 0;
        for(int i=1; i<=n; i++)
        {
            scanf("%d %d %d",&po[i].x,&po[i].y,&po[i].z);
            edge[k++]=Edge(0,i,po[i].z*x);
        }
        for(int i=1;i<=n;i++){
            int tt = Read();
            for(int j=0;j<tt;j++){
                int x = Read();
                if(x==i) continue;
                int w = dis(po[i],po[x])*y;
                if(po[x].z>po[i].z) w+=z;
                edge[k++] = Edge(i,x,w);
            }
        }
        int ans = ZL(0,n+1,k,edge);
        if(~ans) printf("%d\n",ans);


    }
}
