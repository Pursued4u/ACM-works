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
const int maxn = 1e5 + 5;
const int mod = 1e9 + 7;
const db eps = 1e-9;
// 1011

int abss(int x) {
    return x >= 0 ? x : -x;
}

int main(){
    //cin.sync_with_stdio(false);
    //freopen("tt.txt", "r", stdin);
    //freopen("isharp.out", "w", stdout);
    int t, x[maxn], y[maxn], vis[2*maxn];

    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", &x[i], &y[i]);
        }
        if (n >= 5e3) cout << "YES\n";
        else {
            bool flag = false;
            memset(vis, 0, sizeof(vis));
            for (int i = 1; i <= n; i++) {
                for (int j = i+1; j <= n; j++) {
                    int tmp = abs(x[i]-x[j]) + abs(y[i]-y[j]);
                    if (vis[tmp]) flag = true;
                    vis[tmp] = 1;
                }
            }
            if (flag) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}
