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
#include<climits>
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
const int maxn = 30+5;
typedef long long ll;
const int inf = ((1ll<<29)-10);
const ll mod = 1000000007;
int mul(int x,int y){return 1LL*x*y%mod;}
int qpow(int x , int y){int res=1;while(y){if(y&1) res=mul(res,x) ; y>>=1 ; x=mul(x,x);} return res;}
int Read() {
    int x = 0, F = 1; char C = getchar();
    while (C < '0' || C > '9') { if (C == '-') F = -F; C = getchar(); }
    while (C >= '0' && C <= '9') { x = x * 10 - '0' + C, C = getchar(); }
    return x * F;
}
ll n, m, a, b,v1,v2, w[maxn][maxn], vis[maxn], dis[maxn], ans, ma[maxn][maxn];

void dijkstra(int s, int jup)
{
    memset(vis,0,sizeof(vis));
    int cur=s;
    for(int i=1; i<=n; i++)
        dis[i] = INT_MAX;
    dis[cur]=0;
    vis[cur]=1;
    for(int i=1; i<=n; i++)
    {
        if (i == jup) continue;
        for(int j=1; j<=n; j++)
        {
            if (j == jup) continue;
            if(!vis[j] && dis[cur] + ma[cur][j] < dis[j])
                dis[j] = dis[cur] + ma[cur][j] ;
        }
        int mini=INT_MAX;
        for(int j=1; j<=n; j++) {
            if (j == jup) continue;
            if(!vis[j] && dis[j] < mini)
                mini=dis[cur=j];
        }
        vis[cur]=true;
    }
   // for (int i = 1; i <= n; i++)
     //   cout << i << "  +++++ " << dis[i] << endl;
}


void init() {
    memset(vis, 0, sizeof(vis)); ans = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            ma[i][j] = INT_MAX;
    }
}


void solve() {
    while (cin >> n >> m) {
        if (!n && !m) break;
        init();
        for (int i = 1; i <= m; i++) {
            ll u, v, va; scanf("%I64d%I64d%I64d", &u, &v, &va);
            ma[u][v] = min(va, ma[u][v]);
            ma[v][u] = ma[u][v];
        }
        for (int i = 2; i <= n-1; i++) {
            dijkstra(1, i);
            ans = max(ans, dis[n]);
           // cout << i << ' ' << dis[n] << endl;
        }
        if (ans == INT_MAX) cout << "Inf\n";
        else cout << ans << endl;
    }
}

int main()
{
    solve();
}
