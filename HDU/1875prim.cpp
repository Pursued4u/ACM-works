#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define eps 1e-8
#define maxn 107

struct node {

  int to;
  db v;
  
  node(int u, db x) : to(u), v(x) {}
  node() {}
  bool operator<(const node &a) const { return a.v < v; }
};
struct point {
  db x, y;
  point(db a, db b) : x(a), y(b) {}
  point() {}
} p[maxn];
db dis(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
bool ck(db x) { return x > 10 - eps && x < 1000 + eps; }
int vis[maxn];
vector<node> G[maxn];
priority_queue<node> que;
int m;
db res;
db prim() {
  res = 0;
  for (int i = 0; i < G[1].size(); i++)
    que.push(G[1][i]);
  vis[1] = 1;
  while (que.size()) {
    node tmp = que.top();
    que.pop();
    if (vis[tmp.to])
      continue;
    vis[tmp.to] = 1;
    res += tmp.v;
    for (int i = 0; i < G[tmp.to].size(); i++) {
      que.push(G[tmp.to][i]);
    }
  }
  return res;
}

void init() {
  while (que.size())que.pop();
  for (int i = 1; i <= m; i++)G[i].clear();
  memset(vis, 0, sizeof(vis));
}
int main() {
  int t;
  while (cin >> t) {
    while (t--) {
      init();
      cin >> m;
      for (int i = 1; i <= m; i++) {
        db a, b;
        scanf("%lf %lf", &a, &b);
        p[i] = point(a, b);
      }
      for (int i = 1; i <= m; i++) {
        for (int j = i + 1; j <= m; j++) {
            if(ck(dis(p[i],p[j]))){
          G[i].push_back(node(j, dis(p[i], p[j])));
          G[j].push_back(node(i, dis(p[i], p[j])));
            }
        }
      }
      int flag = 0;
      prim();
      for (int i = 1; i <= m; i++) {
        if (!vis[i]) {
          flag = 1;
          break;
        }
      }
      if (flag)
        cout << "oh!" << endl;
      else
        printf("%.1f\n", res*100);
    }
  }
}