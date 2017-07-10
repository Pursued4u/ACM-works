#include <bits/stdc++.h>
using namespace std;
#define maxn 307
#define inf INT_MAX
#define INF LLONG_MAX
#define eps 1e-7
#define CLR(x) memset(x, 0, sizeof(x))
#define ll long long
#define db double

db rx, ry;
db ax, ay, bx, by, cx, cy;
db nx, ny;
db dis(db ax, db ay, db bx, db by) {
  return sqrt((ax - bx) * (ax - bx) + (ay - by) * (ay - by));
}
void waixin() {
  db a1 = bx - ax, b1 = by - ay, c1 = (a1 * a1 + b1 * b1) / 2.0;
  db a2 = cx - ax, b2 = cy - ay, c2 = (a2 * a2 + b2 * b2) / 2.0;
  db d = a1 * b2 - a2 * b1;
  rx = ax + (c1 * b2 - c2 * b1) / d;
  ry = ay + (a1 * c2 - a2 * c1) / d;
}

int main() {
  int ca = 1;
  int t;
  cin >> t;
  while (t--) {
    printf("Case #%d: ", ca++); 
    scanf("%lf %lf", &ax, &ay);
    scanf("%lf %lf", &bx, &by);
    scanf("%lf %lf", &cx, &cy);
    scanf("%lf %lf", &nx, &ny);
    waixin();
    db dab = dis(ax, ay, bx, by);
    db rab = dab / 2.0;
    db x = (ax + bx) / 2.0;
    db y = (ay + by) / 2.0;
    int flag = 0;
    db rr;
    if (!flag && dis(rx, ry, ax, ay) - rab > eps &&
        rab - dis(cx, cy, x, y) > -eps) {
      rx = x;
      ry = y;
      flag = 1;
      rr = rab;
    }
    db dac = dis(ax, ay, cx, cy);
    db rac = dac / 2.0;
    x = (ax + cx) / 2.0;
    y = (ay + cy) / 2.0;
    if (!flag && dis(rx, ry, bx, by) - rac > eps &&
        rac - dis(bx, by, x, y) > -eps) {
      rx = x;
      ry = y;
      flag = 1;
      rr = rac;
    }
    db dbc = dis(bx, by, cx, cy);
    db rbc = dbc / 2.0;
    x = (bx + cx) / 2.0;
    y = (by + cy) / 2.0;
    if (!flag && dis(rx, ry, ax, ay) - rbc > eps &&
        rbc - dis(ax, ay, x, y) > -eps) {
      rx = x;
      ry = y;
      flag = 1;
      rr = rbc;
    }
    if (flag) {
      if (dis(nx, ny, x, y) - rr > eps)
        cout << "Safe" << endl;
      else
        cout << "Danger" << endl;
    } else {
      if (dis(nx, ny, rx, ry) - dis(rx, ry, ax, ay) > eps) {
        cout << "Safe" << endl;

      } else
        cout << "Danger" << endl;
    }
  }
}