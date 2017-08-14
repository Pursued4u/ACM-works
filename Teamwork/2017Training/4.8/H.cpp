#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
#define inf INT_MAX
#define INF LLONG_MAX
#define eps 1e-7
#define CLR(x) memset(x, 0, sizeof(x))
#define ll long long
#define db double
db dis(db ax, db ay, db bx, db by) {
  return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}
double aa[maxn];
double bb[maxn];
int main() {

  int t;
  cin >> t;
  int ca = 1;
  while (t--) {
    printf("Case #%d: ", ca++);
    db a, b;
    scanf("%lf %lf", &a, &b);
    int m, n;
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
      scanf("%lf", &aa[i]);
    }
    for (int i = 0; i < n; i++) {
      scanf("%lf", &bb[i]);
    }
    db ans = 0;
    ans += dis(aa[0], a, bb[0], b);
    int l = 0;
    int r = 0;
    while (1) {
      if (r == n - 1 || l == m - 1)
        break;
      db d1 = dis(aa[l + 1], a, bb[r], b);
      db d2 = dis(aa[l], a, bb[r + 1], b);
      if (d1 - d2 > eps) {
        ans += d2;
        r++;
      } else {
        ans += d1;
        l++;
      }
    }
    if (l != m - 1) {
      for (int i = l + 1; i < m; i++) {
        ans += dis(bb[r], b, aa[i], a);
      }
    }
    if (r != n - 1) {
      for (int i = r + 1; i < n; i++) {
        ans += dis(bb[i], b, aa[l], a);
      }
    }
    printf("%.2f\n", ans);
  }
}