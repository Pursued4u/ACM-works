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
const int maxn = 1e2+5;
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
ll n, m, a, b,v1,v2, ma[maxn][maxn], vis[maxn], dis[maxn], dd[maxn], hh[maxn][maxn];

void dijkstra(int s)
{
    memset(vis,0,sizeof(vis));
    int cur=s;
    for(int i=1; i<=n; i++)
        dis[i] = INT_MAX;
    memset(dd, 0, sizeof(dd));
    dis[cur]=0;
    vis[cur]=1;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            //cout << dis[cur] + ma[cur][j] << endl;
            if(!vis[j] && dis[cur] + ma[cur][j] < dis[j]) {
                dis[j] = dis[cur] + ma[cur][j];
               // dd[j] = dd[cur] + ma[cur][j];
                if (ma[cur][j] == 0) dd[j] = dd[cur] + hh[cur][j];
                else dd[j] = dd[cur] + ma[cur][j];
            }
        }
        ll mini=INT_MAX;
        for(int j=1; j<=n; j++)
            if(!vis[j] && dis[j] < mini)
                mini=dis[cur=j];
        vis[cur]=true;
    }
  //  for (int i = 1; i <= n; i++)
      //  cout << i << ' ' << dis[i] << endl;
}

void init() {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ma[i][j] = INT_MAX;
            hh[i][j] = INT_MAX;
        }
    }
}

void solve() {
    scanf("%I64d%I64d", &n, &m);

    init();
    for (int i = 1; i <= m; i++) {
        ll u, v, x, op; scanf("%I64d%I64d%I64d%I64d", &u, &v, &x, &op);
        if (op == 1) {
            if (x < ma[u][v]) {
                ma[v][u] = ma[u][v] = x;
            }
        }
        else {
            if (x < hh[u][v]) {
                hh[u][v] = hh[v][u] = x;
            }
            ma[u][v] = ma[v][u] = 0;
           // cout << u << ' ' << v << endl;
        }
    }
  //  cout << ma[1][3] << endl;
    int s, p; scanf("%d%d", &s, &p);
    dijkstra(s);
    if (dis[p] != INT_MAX) printf("%I64d %I64d\n", dis[p], dd[p]);
    else cout << -1 << endl;
}

int main()
{
    int t; cin >> t;
    while (t--) solve();

}
