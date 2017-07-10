#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool chk(long long x) {
  long long s = 0;
  while (x) {
    s += x % 10;
    x /= 10;
  }
  return (s % 10 == 0);
}

ll cal(long long x) {
  if (x < 0)
    return 0;
  while (!chk(x))
    x--;
  return x / 10 + 1;
}

int main() {
  // fun();
  long long ans = 0;
  int t;
  cin >> t;
  int ca = 1;
  while (t--) {
    printf("Case #%d: ", ca++);
    ll a, b;
    cin >> a >> b;
    cout << cal(b) - cal(a - 1) << endl;
  }
}