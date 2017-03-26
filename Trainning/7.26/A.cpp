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
//1007
int n, maxx, ans;
vector<int> G[maxn];

void dfs(int x, int fa, int deep) {
    if (deep > maxx) {
        ans = x; maxx = deep;
    }
    for (int i = 0; i < G[x].size(); i++) {
        int u = G[x][i];
        if (u == fa) continue;
        dfs(u, x, deep+1);
    }
}


int main(){
    //cin.sync_with_stdio(false);
    //freopen("tt.txt", "r", stdin);
    //freopen("isharp.out", "w", stdout);
    int t;

    cin >> t;
    while (t--) {
        scanf("%d", &n);
        ans = 0, maxx = 0;
        for (int i = 1; i <= n; i++) G[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v; scanf("%d%d", &u, &v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1, -1, 0);
        maxx = 0;
        dfs(ans, -1, 0);
        cout << maxx + (n-maxx-1)*2 << endl;
    }

    return 0;
}
