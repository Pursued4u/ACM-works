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
int p[maxn], n, m;
struct edge{
    int u, v, w;
} q[maxn];
int Find(int x) {return p[x]==x?x:p[x]=Find(p[x]);}
ll d[maxn];
bool cmp(edge a, edge b) {
    return a.w < b.w;
}

struct pos{
    int dis, num;
};

struct nod{
    int v, w;
};

vector <nod> G[maxn];

void init() {
    memset(d, 0, sizeof(d));
    for (int i = 1 ;i <= n; i++) {
        p[i] = i;
        G[i].clear();
    }
}

int dfs(int x, int fa) {
    int node = 1;
    for (int i = 0; i < G[x].size(); i++) {
        nod u = G[x][i];
        if (u.v == fa) continue;
        int tmp = dfs(u.v, x);
        node += tmp;
        //cout << u.w << endl;
        d[x] += d[fa];
        d[x] += (tmp)*u.w + d[u.v];
    }
    return node;
}


int main(){
    //cin.sync_with_stdio(false);
    freopen("tt.txt", "r", stdin);
    //freopen("isharp.out", "w", stdout);
    int t;

    cin >> t;
    while (t--) {
        cin >> n >> m;
        init();
        for (int i = 1; i <= m; i++) {
            scanf("%d%d%d", &q[i].u, &q[i].v, &q[i].w);
        }
        sort(q+1, q+1+m, cmp);
        ll ans = 0;
        for (int i = 1; i <= m; i++) {
            int fx = Find(q[i].u), fy = Find(q[i].v);
            if (fx != fy) {
                G[q[i].u].push_back((nod){q[i].v, q[i].w});
                G[q[i].v].push_back((nod){q[i].u, q[i].w});
                p[fx] = fy;
                ans += q[i].w;
            }
        }
        for (int i = 1; i <= n; i++) {
           // cout << G[i].size() << endl;
            if (G[i].size() == 1) {
              //  cout << "OK\n";
               // cout << i << endl;
                dfs(i, 0);
                break;
            }
        }
        db pri = 0;
        for (int i = 1; i <= n; i++) {
            cout << d[i] << endl;
            pri += d[i];
        }
        cout << pri << endl;
        printf("%I64d %.2lf\n", ans, pri/(double)(n*(n-1)/2));
    }

    return 0;
}
