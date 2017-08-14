#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
#define inf INT_MAX
#define INF LLONG_MAX
#define eps 1e-7
#define CLR(x) memset(x, 0, sizeof(x))
#define ll long long
#define db double

db sgn(db x) { return x > eps ? 1 : x < -eps ? -1 : 0; }

int main() {
  int t;
  cin >> t;
  int ca = 1;
  while (t--) {
    int a[maxn];
    printf("Case #%d:\n", ca++);
    int n;
    cin >> n;
    int tt = n / 10;
    int tm = 10 - tt;
    cout << "*------------*" << endl;
    for (int i = 0; i < tm; i++) {
      cout << "|............|" << endl;
    }
    for (int i = 0; i < tt; i++) {
      cout << "|------------|" << endl;
    }
    cout << "*------------*" << endl;
  }
}