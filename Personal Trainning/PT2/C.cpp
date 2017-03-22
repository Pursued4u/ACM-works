#include <algorithm>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("out.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a, 0, sizeof(a))
#define MEM(a, x) memset(a, x, sizoef(a))
#define eps 1e-8
#define sf(x) scanf("%d", &x)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x &(-x)
#define fi first
#define se second
#define rep(a, b, c) for (int(a) = (b); (a) < (c); (a)++)
#define drep(a, b, c) for (int(a) = (b); (a) > (c); --(a))
#define dbg(x) cout << #x << "=" << x << endl
using namespace std;
const int maxn = 1e6 + 5;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;
ll mul(ll x, ll y) { return x * y % mod; }
ll q_mul(ll a, ll b) {
  ll ans = 0;
  while (b) {
    if (b & 1) {
      ans = (ans + a) % mod;
    }
    b >>= 1;
    a = (a + a) % mod;
  }
  return ans;
}
ll q_pow(ll x, ll y) {
  ll res = 1;
  while (y) {
    if (y & 1)
      res = q_mul(res, x);
    y >>= 1;
    x = q_mul(x, x);
  }
  return res;
}
ll inv(ll x) { return q_pow(x, mod - 2); }
int Read() {
  int x = 0, F = 1;
  char C = getchar();
  while (C < '0' || C > '9') {
    if (C == '-')
      F = -F;
    C = getchar();
  }
  while (C >= '0' && C <= '9') {
    x = x * 10 - '0' + C, C = getchar();
  }
  return x * F;
}
struct Po {
  int v;
  ll tot;
} node[maxn];
bool cmp(Po a, Po b) {
  if (a.tot == b.tot) {
    return a.v > b.v;
  }
  return a.tot > b.tot;
}
ll vis[maxn];
int ans[maxn];
int main() {
  int t;
  cin >> t;
  while (t--) {
    int m, n;
    ll sum = 0;
    int minn = inf;
    CLR(vis);
    CLR(ans);
    int maxx = 0;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
      int x = Read();
      vis[x]++;
      maxx = max(maxx, x);
      minn = min(minn, x);
      sum += x;
    }
    if (sum < n) {
      cout << "a"
           << "\n";
      continue;
    }
    int k = 0;
    for (ll i = minn; i <= maxx; i++) {
      if (vis[i]) {
        node[k].v = i;
        // node[k].num = vis[i]
        node[k++].tot = vis[i] * i;
      }
    }
    sort(node, node + k, cmp);
    ll cnt = 0;
    int tmp = 0;
    for (int i = 0; i < k; i++) {
      ans[tmp++] = node[i].v;
      cnt += node[i].tot;
      if (cnt >= n) {
        break;
      }
    }
    sort(ans, ans + tmp);
    for (int i = 0; i < tmp; i++) {
      if (i != tmp - 1)
        cout << ans[i] << " ";
      else
        cout << ans[i] << "\n";
    }
  }
}
