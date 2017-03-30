#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define eps 1e-8
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
using namespace std;
const int maxn = 1000500;
typedef long long LL;
typedef double DB;
const int inf = ((1LL<<29)-10);
const LL mod = 1000000007;
int tol;
int par[maxn];
int n,m;
LL ans;
DB ans2;
vector<pair<int,int> > G[maxn];
int findset(int x)
{
    return par[x] == x ? x : par[x]=findset(par[x]);
}
struct edge
{
    int u,v;
    int w;
};
edge es[maxn];
void init()
{
    ans2=0;
    ans=0;
    tol=1;
    for(int i=0;i<maxn;i++)
    {
    par[i]=i;
    G[i].clear();
    }
}

bool cmp(edge e1, edge e2)
{
    return e1.w < e2.w;
}
void addedge(int u,int v,int w)
{
    es[tol].u=u;
    es[tol].v=v;
    es[tol++].w=w;
}
int dfs(int x,int y)
{
    int sz=0;

    for(int i=0;i<G[x].size();i++)
    {
        int v=G[x][i].first;
        if(v==y)
        continue;
        int tmp=dfs(v,x);
        sz+=tmp;
        ans2=ans2+1.0*tmp*(m-tmp)*G[x][i].second;
    }
    return sz+1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    scanf("%d %d",&m,&n);

    init();

    for(int i=0;i<n;i++)
    {

        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        addedge(a,b,c);
    }

    sort(es+1,es+n+1,cmp);
    for(int i=1;i<=n;i++)
    {
        int u=es[i].u;
        int v=es[i].v;
        int w=es[i].w;
        int fx=findset(u);
        int fy=findset(v);
        if(fx!=fy)
        {
            ans+=w;
            par[fy]=fx;
            G[u].PB(MP(v,w));
            G[v].PB(MP(u,w));
        }
    }

    dfs(1,0);

    ans2 = ans2 * 2.0  / (1.0* m)  / (m - 1.0);
    printf("%I64d %.2lf\n",ans,ans2);

    }
}


