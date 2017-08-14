#include <bits/stdc++.h>
using namespace std;
#define maxn 307
#define inf INT_MAX
#define INF LLONG_MAX
#define eps 1e-7
#define CLR(x) memset(x, 0, sizeof(x))
#define ll long long
#define db double

db sgn(db x) { return x > eps ? 1 : x < -eps ? -1 : 0; }
struct node {
  db x, y;
  db vx, vy;
} a[maxn];
db dis(db ax, db ay, db bx, db by) {
  return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}
int n;
db check(db t) {
  db maxx = -inf;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      db ax = a[i].x + t * a[i].vx;
      db ay = a[i].y + t * a[i].vy;
      db bx = a[j].x + t * a[j].vx;
      db by = a[j].y + t * a[j].vy;
      db dist = dis(ax, ay, bx, by);

      maxx = max(dist, maxx);
    }
  }
  return maxx;
}
int main() {
  int t;
  cin >> t;
  int ca = 1;
  while (t--) {
    printf("Case #%d: ", ca++);
    cin >> n;
    for (int i = 0; i < n; i++) {
      scanf("%lf%lf%lf%lf", &a[i].x, &a[i].y, &a[i].vx, &a[i].vy);
    }
    db l = 0;
    db r = 1e7;

    while (1) {
      db mid = (l + r) / 2.0;
      db midd = (mid + r) / 2.0;
      // cout << check(mid) << " " << check(midd) <<endl;
      if ((check(midd) - check(mid)) > eps) {
        r = midd;
      } else
        l = mid;
      if (!sgn(r - l))
        break;
    }
    printf("%.2f %.2f\n", l, check(l));
  }
}