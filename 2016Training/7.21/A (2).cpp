#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<map>
#include<vector>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define eps 1e-8
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
using namespace std;
const int maxn = 1e2+5;
typedef long long LL;
const int inf = ((1LL<<29)-10);
const LL mod = 1000000007;

int main()
{
    //FILEIN;
    //FILEOUT;
    //CLOSEIO;
    int t, vis[maxn];

    cin >> t;
    while (t--) {
        memset(vis, 0 , sizeof(vis));
        int n, m; scanf("%d%d", &n, &m);
        int p = 0, q = 0;
        while (m--) {
            int x, y; scanf("%d%d", &x, &y);
            vis[x] = y;
        }
        if (vis[1]) {
            p += vis[1];
            if (vis[2]) p += vis[2];
            else p += vis[1];
        }
        else {
            p += 100;
            if (vis[2]) p += vis[2];
            else p += 100;
        }
        q += p;
        int s = 2;
        for (int i = 3; i <= n; i++) {
            if (vis[i]) {
                q += (i - s) * vis[i];
                s = i;
            }
        }
       // cout << p << ' ' << q << endl;
        int gd = __gcd(p, q);
        p /= gd, q /= gd;
        printf("%d/%d\n", p, q);
    }


}
