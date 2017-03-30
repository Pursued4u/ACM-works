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
const int maxn = 1e2 + 5;
const int mod = 1e9 + 7;
const db eps = 1e-9;

void solve() {
    int n, m, mapp[maxn][maxn];

    cin >> n >> m; memset(mapp, 0, sizeof(mapp));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++)
            scanf("%d", &mapp[i][j]);
    }
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
        if (mapp[i][j]) ans++;
        if (mapp[i][j] > mapp[i-1][j]) ans += mapp[i][j] - mapp[i-1][j];
        if (mapp[i][j] > mapp[i+1][j]) ans += mapp[i][j] - mapp[i+1][j];
        if (mapp[i][j] > mapp[i][j+1]) ans += mapp[i][j] - mapp[i][j+1];
        if (mapp[i][j] > mapp[i][j-1]) ans += mapp[i][j] - mapp[i][j-1];
        }
    }
    cout << ans << endl;
}

int main(){
    //cin.sync_with_stdio(false);
    //freopen("tt.txt", "r", stdin);
    //freopen("isharp.out", "w", stdout);
    int t;

    cin >> t;
    while (t--) solve();

    return 0;
}
