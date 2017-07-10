#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
#define inf INT_MAX
#define INF LLONG_MAX
#define eps 1e-7
#define CLR(x) memset(x, 0, sizeof(x))
#define ll long long
#define db double

int numa[11];
int numb[11];
int ans[maxn];
char a[maxn];
char b[maxn];
int main() {
  int ca = 1;
  int t;
  cin >> t;
  while (t--) {
    CLR(numa);
    CLR(numb);
    printf("Case #%d: ", ca++);
    scanf("%s", a);
    scanf("%s", b);
    int len = strlen(a);
    if (len == 1) {
      cout << (a[0] - '0' + b[0] - '0') % 10 << endl;
      continue;
    }
    for (int i = 0; i < len; i++)
      numa[a[i] - '0']++;
    for (int i = 0; i < len; i++)
      numb[b[i] - '0']++;
    int tmp = -1;
    int x, y;
    for (int i = 1; i <= 9; i++) {
      for (int j = 1; j <= 9; j++) {

        if (numa[i] && numb[j]) {
          int k = (i + j) % 10;
          if (k > tmp) {
            x = i;
            y = j;
            tmp = k;
          }
        }
      }
    }
    numa[x]--;
    numb[y]--;
    int p = 0;
    int flagg = 0;

    if (tmp) {
      ans[p++] = tmp;
      flagg = 1;
    }

    for (int i = 9; i >= 0; i--) {
      for (int j = 0; j <= 9; j++) {
        if (i - j >= 0) {
          int k = i - j;
          int kk = min(numa[j], numb[k]);
          int mm = kk;

          while (kk--) {
            ans[p++] = i;
          }
          numa[j] -= mm;
          numb[k] -= mm;

        } else {
          int k = i + 10 - j;
          int kk = min(numa[j], numb[k]);
          int mm = kk;

          while (kk--) {
            ans[p++] = i;
          }
          numa[j] -= mm;
          numb[k] -= mm;
        }
      }
    }

    for (int i = 0; i < p; i++) {
      if (!flagg && !ans[i])
        continue;
      else {
        printf("%d", ans[i]);
        flagg = 1;
      }
    }
    if (!flagg)
      cout << 0;

    puts("");
  }
}