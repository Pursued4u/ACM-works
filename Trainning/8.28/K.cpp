#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<stack>
#include<climits>
#include<queue>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizoef(a))
#define eps 1e-8
#define sf(x) scanf("%d",&x)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define db double
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl
using namespace std;
const int maxn = 2e5+5;
typedef long long ll;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;
ll mul(ll x,ll y){return x*y%mod;}
ll q_mul(ll a, ll b){ ll ans = 0;while(b){if(b & 1){ans=(ans+a)%mod;} b>>=1;a=(a+a) % mod;}return ans;}
ll q_pow(ll x , ll y){ll res=1;while(y){if(y&1) res=q_mul(res,x) ; y>>=1 ; x=q_mul(x,x);} return res;}
ll inv(ll x) { return q_pow(x, mod-2); }
int Read() {
    int x = 0, F = 1; char C = getchar();
    while (C < '0' || C > '9') { if (C == '-') F = -F; C = getchar(); }
    while (C >= '0' && C <= '9') { x = x * 10 - '0' + C, C = getchar(); }
    return x * F;
}

struct pos {
    int x, lv;
} q[maxn];
int d[maxn], maxx, n, m;
vector<int> G[maxn], ran[maxn];
int fa[maxn];
int Find(int x)           //查找根节点
{
    int r=x;              //用r去保存x，查找根节点，不然x值会改变
    while(fa[r]!=r)   //父节点不是自己是查找
        r=fa[r];      //将他的父节点赋给自己，继续查找父节点的父节点
    int i=x,j;            //下面是路径压缩
    while(fa[i]!=r){   //当父节点不是根节点时压缩
        j=fa[i];       //用j保存当前父节点
        fa[i]=r;       //将父节点改为根节点
        i=j;               //继续父节点的根节点
    }
    return r;
}

void init() {
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= n; i++) {
        q[i].lv = 0;
        fa[i] = i;
    }
    maxx = 0;
}

void dfs(int x, int lv) {
    maxx = max(maxx, lv);
    for (int i = 0; i < G[x].size(); i++) {
        int u = G[x][i];
        if (q[u].lv != 0 && q[u].lv <= lv) continue;
        q[u].lv = max(q[u].lv, lv);
        dfs(u, lv+1);
    }
}

int main()
{
    cin >> n >> m;
    init();

    for (int i = 1; i <= m; i++) {
        int x, y; scanf("%d%d", &x, &y);
        d[y]++;
        G[x].push_back(y);
       // int fx = Find(x), fy = Find(y);
      //  if (fx != fy) fa[fx] = fy;
    }
    for (int i = 1; i < n; i++) {
        G[i].push_back(i+1);
    }
    for (int i = n; i >= 1; i--) {
        if (!d[i]) {
            if (q[i].lv == 0) q[i].lv = 1;
            dfs(i, 2);
        }
      //  cout << q[2].lv << endl;
    }
    for (int i = 1; i <= n; i++) {
        int lv = q[i].lv;
        ran[lv].push_back(i);
    }
    for (int i = 1; i <= maxx; i++) {
        sort(ran[i].begin(), ran[i].end());
        for (int j = 0; j < ran[i].size(); j++)
            printf("%d ", ran[i][j]);
    }
    cout << endl;
}
