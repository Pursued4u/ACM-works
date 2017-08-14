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
const int maxn = 1e2 + 5;
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
struct Matrix {
  db mat[25][25];
};

int m, n;
db num[maxn];
db ans[maxn];
Matrix operator*(Matrix A, Matrix B) {
  Matrix c;
  CLR(c.mat);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        c.mat[j][i] += A.mat[j][k] * B.mat[k][i];
      }
    }
  }
  return c;
}
Matrix operator^(Matrix A, ll b) {
  Matrix c;
  CLR(c.mat);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      c.mat[i][j] = (i == j);
    }
  }
  while (b) {
    if (b & 1)
      c = A * c;

    b >>= 1;
    A = A * A;
  }
  return c;
}
int main() {
  // FILEIN;
  int t;
  cin >> t;
  while (t--) {
    cin >> n;
    for (int i = 0; i < n; i++)
      scanf("%lf", &num[i]);
    for (int i = 0; i < n; i++)
      ans[i] = 0.0;
    Matrix F;
    CLR(F.mat);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x == 0)
        F.mat[i][i] = 1.0;
      for (int j = 0; j < x; j++) {
        int y;
        cin >> y;
        F.mat[i][y - 1] = 1.0 / (db)x;
      }
    }
    ll k;
    cin >> k;

    Matrix E;
    CLR(E.mat);
    E = F ^ k;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ans[i] += num[j] * E.mat[j][i];
      }
    }
    for (int i = 0; i < n; i++) {
      if (i != n - 1)
        printf("%.2f ", ans[i]);
      else
        printf("%.2f\n", ans[i]);
    }
  }
}
