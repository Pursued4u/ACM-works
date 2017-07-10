#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
#define inf INT_MAX
#define INF LLONG_MAX
#define eps 1e-7
#define CLR(x) memset(x, 0, sizeof(x))
#define ll long long
#define db double

db sgn(db x) { return x > eps ? 1 : x < -eps ? -1 : 0}

int main() {
  int t;
  cin >> t;
  int ca = 1;
  while (t--) {
    int a[maxn];
    printf("Case #%d: ", ca++);
    int n;
    cin >> n;
    int flag = 0;
    for (int i = 1; i <= n; i++)
      scanf("%d", &a[i]);
    for (int i = 2; i <= n; i++) {
      if (a[i] - a[i - 1] != 1) {
        cout << i << endl;
        flag = 1;
        break;
      }
    }
    if (!flag)
      cout << 1 << endl;
  }
}