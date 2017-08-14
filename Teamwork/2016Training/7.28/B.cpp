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
const int maxn = 1e3 + 5;
const int mod = 1e9 + 7;
const db eps = 1e-9;

struct pos {
    int a, ord;
} q[maxn];
int cas = 1;

bool cmp(const pos &a, const pos &b) {
    return a.a < b.a;
}

void solve() {
    int n; cin >> n;

    for (int i = 1; i <= n; i++) {
        scanf("%d", &q[i].a);
        q[i].ord = i;
    }
    printf("Case #%d: ", cas++);
    vector<int> G[maxn];
    sort(q+1, q+1+n, cmp);
    bool flag = true; ll ans = 0;
    for (int i = 1; i <= n; i++) {
        if (q[i].a >= i) flag = false;
        ans += q[i].a;
        int tmp = q[i].a;
        for (int j = 1; j <= tmp; j++) {
            G[q[i].ord].push_back(q[j].ord);
        }
    }
    if (flag) {
        cout << "Yes\n";
        cout << ans << endl;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < G[i].size(); j++)
                printf("%d %d\n", i, G[i][j]);
        }
    }
    else cout << "No\n";
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
