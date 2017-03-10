#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizoef(a))
#define eps 1e-8
#define scf(x) scanf("%d",&x)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define db double
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl


using namespace std;
const int maxn = 5e4+5;
typedef long long ll;
const int INF = ((1ll<<29)-10);
const ll mod = 1000000007;
int mul(int x,int y)
{
    return 1LL*x*y%mod;
}
int qpow(int x , int y)
{
    int res=1;
    while(y)
    {
        if(y&1) res=mul(res,x) ;
        y>>=1 ;
        x=mul(x,x);
    }
    return res;
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
    int from, to, cap, flow, cost;
    Edge(int u, int v, int c, int f, int w):from(u),to(v),cap(c),flow(f),cost(w) {}
};
struct MCMF
{
    int n, m;
    vector<Edge> edges;
    vector<int> G[maxn];
    int inq[maxn];         //是否在队列中
    int d[maxn];           //Bellman-Ford
    int p[maxn];           //上一条弧
    int a[maxn];           //可改进量
    void init(int n)
    {
        this->n = n;
        for(int i = 0; i < n; i++) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from, int to, int cap, int cost)
    {
        edges.push_back(Edge(from, to, cap, 0, cost));
        edges.push_back(Edge(to, from, 0, 0, -cost));
        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    bool BellmanFord(int s, int t, int& flow, long long& cost)
    {
        for(int i = 0; i < n; i++) d[i] = INF;
        memset(inq, 0, sizeof(inq));
        d[s] = 0;
        inq[s] = 1;
        p[s] = 0;
        a[s] = INF;
        queue<int> Q;
        Q.push(s);
        while(!Q.empty())
        {
            int u = Q.front();
            Q.pop();
            inq[u] = 0;
            for(int i = 0; i < G[u].size(); i++)
            {
                Edge& e = edges[G[u][i]];
                if(e.cap > e.flow && d[e.to] > d[u] + e.cost)
                {
                    d[e.to] = d[u] + e.cost;
                    p[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if(!inq[e.to])
                    {
                        Q.push(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }
        if(d[t] == INF) return false;
        flow += a[t];
        cost += (long long)d[t] * (long long)a[t];
        for(int u = t; u != s; u = edges[p[u]].from)
        {
            edges[p[u]].flow += a[t];
            edges[p[u]^1].flow -= a[t];
        }
        //cout << "**"<<endl;
        return true;
    }
    //需要保证初始网络中没有负权圈
    int MincostMaxflow(int s, int t, long long& cost)
    {
        int flow = 0;
        cost = 0;
        while(BellmanFord(s, t, flow, cost));
        return flow;
    }
};

int aa[maxn], bb[maxn];

void solve()
{
    int n, m, L;
    MCMF road;
    cin >> n >> m >> L;
    road.init(n+1);
    for(int i=1; i<=n; i++)
    {
        road.AddEdge(0, i, INF, 0);
        road.AddEdge(i, n+1, INF, 0);
    }
    for(int i=1; i<=n; i++)
    {
        scanf("%d%d", aa+i, bb+i);
        //road.AddEdge(i, i, INF, bb[i]);
       // road.AddEdge(i, i, INF, bb[i]);
    }
    for(int i=1; i<=m; i++)
    {
        int a, k;
        int b[300];
        scanf("%d%d", &a, &k);
        for(int j=0; j<k; j++)
        {
            scanf("%d", b+j);
            if(j)
            {
                road.AddEdge(b[j-1], b[j], a-(aa[b[j]]+aa[b[j+1]]), max(bb[b[j]],bb[b[j+1]]));
            }
        }
    }
    ll cost = 0;
    int ans = road.MincostMaxflow(0, n+1, cost);
    if(ans >= L) cout << cost << ' ' << ans << endl;
    else puts("impossible");
}

int main()
{
    int t, cas = 1;
    cin >> t;
    while (t--)
    {
        printf("Case #%d: ", cas++);
        solve();
    }

}
