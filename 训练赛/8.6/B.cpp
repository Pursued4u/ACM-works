#include<cstdio>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
#include<cstring>
#include<queue>
#include<set>
#include<string>
#include<map>
#define inf 9223372036854775807
#define INF 9e7+5
#define PI acos(-1)
using namespace std;
typedef long long ll;
typedef double db;
const int maxn = 1e6 + 5;
const int mod = 1e9 + 7;
const db eps = 1e-9;
int n, a[maxn], be, cas = 1, c[maxn];

int lowbit(int x) {
    return x & (-x);
}

int getsum(int x) {
    int ans = 0;
    while (x) {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}

void updata(int x) {
    while (x <= maxn) {
        c[x] += 1;
        x += lowbit(x);
    }
}

void solve() {
    cin >> n;
    memset(c, 0, sizeof(c));
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
    }
    int ans = 0;
    for (int i = n; i >= 1; i--) {
        int tmp = getsum(a[i]);
        if (tmp) ans++;
        updata(a[i]);
    }
    printf("Case #%d: %d\n", cas++, ans);
}

int main(){
    //cin.sync_with_stdio(false);
    //freopen("tt.txt", "r", stdin);
    //freopen("isharp.out", "w", stdout);

    int t; cin >> t;
    while (t--)
        solve();


    return 0;
}
