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
const int maxn = 1e5 + 5;
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
map<string, int> mp;
int main() {
//FILEIN;
  mp["one"] = 1;
  mp["two"] = 2;
  mp["three"] = 3;
  mp["four"] = 4;
  mp["five"] = 5;
  mp["six"] = 6;
  mp["seven"] = 7;
  mp["eight"] = 8;
  mp["nine"] = 9;
  mp["ten"] = 10;
  mp["eleven"] = 11;
  mp["twelve"] = 12;
  mp["thirteen"] = 13;
  mp["fourteen"] = 14;
  mp["fifteen"] = 15;
  mp["sixteen"] = 16;
  mp["seventeen"] = 17;
  mp["eighteen"] = 18;
  mp["nineteen"] = 19;
  mp["twenty"] = 20;
  mp["thirty"] = 30;
  mp["forty"] = 40;
  mp["fifty"] = 50;
  mp["sixty"] = 60;
  mp["seventy"] = 70;
  mp["eighty"] = 80;
  mp["ninety"] = 90;
  int t;
  cin >> t;
  while (t--) {
    string s;
    char a = ' ';
    int ans = 0;
    int tmp = 0;
    while (a != '\n') {
      cin >> s;
      a = getchar();
      if (s == "million") {
        ans += tmp * 1000000;
        tmp = 0;
      }
      else if (s == "thousand"){
          ans += tmp * 1000;
          tmp = 0;
      }
      else if (s == "hundred"){
         tmp *= 100;
      }
      else if(s == "and") continue;
      else{
          tmp+=mp[s];
      }
    }
    ans+=tmp;
    cout << ans << endl;

  }
}
