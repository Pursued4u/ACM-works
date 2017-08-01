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
int Read() {
    int x = 0, F = 1; char C = getchar();
    while (C < '0' || C > '9') { if (C == '-') F = -F; C = getchar(); }
    while (C >= '0' && C <= '9') { x = x * 10 - '0' + C, C = getchar(); }
    return x * F;
}


vector<int> g[maxn], ve;
int dep[maxn], dfn[maxn], lg[2*maxn];
pair<int, int> ance[20][2*maxn];

void dfs(int u, int fa) {
  dep[u] = dep[fa] + 1;
  dfn[u] = ve.size();
  ve.push_back(u);
  for (int i=0;i<g[u].size();i++) {
    int v = g[u][i];
    if (v != fa) {
      dfs(v, u);
      ve.push_back(u);
    }
  }
}

void RMQ_init() {
  int n = ve.size();
  for (int i = 1, j = 0; i <= n; i++) {
    if (i == (1 << (j + 1))) j++;
    lg[i] = j;
  }
  for (int i = 0; i < n; i++) {
    ance[0][i].first = dfn[ve[i]];
    ance[0][i].second= ve[i];
  }
  for (int j = 1; (1 << j) <= n; j++) {
    for (int i = 0; i + (1 << j) - 1 < n; i++) {
      ance[j][i] = min(ance[j - 1][i], ance[j - 1][i + (1 << (j - 1))]);
    }
  }
}

int lca(int u, int v) {
  int l = dfn[u], r = dfn[v];
  if (l > r) {
    swap(l, r);
  }
  int j = lg[r - l + 1];
  return min(ance[j][l], ance[j][r - (1 << j) + 1]).second;
}

int query(int a, int b, int c) {
  int x = lca(a, b), y = lca(a, c);
  if (x == y) {
    int d = dep[a] - dep[x] + 1;
    int z = lca(b, c);
    return d+dep[z]-dep[x];
  }
  else {
    return dep[a] - max(dep[x], dep[y]) + 1;
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  for (int i = 2; i <= n; i++) {
    int u = Read();
    g[u].push_back(i);
    g[i].push_back(u);
  }
  dfs(1, 0);
  RMQ_init();
  while (q--) {
    int a, b, c;
    cin >> a >> b >> c;
    cout << max(query(a, b, c), max(query(b, a, c), query(c, a, b))) << endl;
  }
  return 0;
