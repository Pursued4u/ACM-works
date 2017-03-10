#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#include<climits>
#define FILEIN freopen("tt.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizoef(a))
#define eps 1e-8
#define scf(x) scanf("%d",&x)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define db double
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl


using namespace std;
const int maxn = 2e2+5;
typedef long long ll;
const int inf = ((1ll<<29)-10);
const ll mod = 1000000007;
int mul(int x,int y){return 1LL*x*y%mod;}
int qpow(int x , int y){int res=1;while(y){if(y&1) res=mul(res,x) ; y>>=1 ; x=mul(x,x);} return res;}
int Read() {
    int x = 0, F = 1; char C = getchar();
    while (C < '0' || C > '9') { if (C == '-') F = -F; C = getchar(); }
    while (C >= '0' && C <= '9') { x = x * 10 - '0' + C, C = getchar(); }
    return x * F;
}

struct sho{
    ll in, tot, tim;
} q[maxn];

struct pos{
    ll l, t;
} ql[maxn];

bool cmp(const pos &a, const pos &b) {
    return a.t < b.t;
}

vector<int> G[maxn];

void solve() {
    ll n, m, need, l[maxn], t[maxn], vis[maxn], viss[maxn];

    memset(vis, 0, sizeof(vis));
    memset(viss, 0, sizeof(viss));
    cin >> n >> m >> need;
    for (int i = 1; i <= m; i++) G[i].clear();
    for (int i = 1; i <= n; i++) {
        cin >> ql[i].l >> ql[i].t;
    }
    sort(ql+1, ql+1+n, cmp);
    for (int i = 1; i <= m; i++) {
        int num;
        cin >> q[i].in >> num;
        while (num--) {
            int x; cin >> x;
            G[i].push_back(x);
        }
    }
    ll to = 0, ans;
    for (int i = 1; i <= n; i++) {
        vis[i] = 1; ans = ql[i].t;
        for (int j = 1; j <= m; j++) {
            if (viss[j]) continue;
            ll tot = 0, flag = 1;
            for (int k = 0; k < G[j].size(); k++) {
                int u = G[j][k];
                if (vis[u] == 0) {
                    flag = 0; break;
                }
                if (vis[u] == 1) {
                    tot += ql[u].l;
                }
            }
            if (q[j].in - tot >= 0 && flag) {
                to += q[j].in - tot;
                for (int k = 0; k < G[j].size(); k++) {
                    int u = G[j][k];
                    vis[u] = 2;
                }
                viss[j] = 1;
            }
        }
        if (to >= need && ql[i+1].t != ql[i].t) {
            break;
        }
    }
   // cout << to << endl;
    if (to < need) cout << "impossible\n";
    else cout << ans << ' ' << to << endl;
}

int main()
{
    FILEIN;
    int t, cas = 1;

    cin >> t;
    while (t--) {
        printf("Case #%d: ", cas++);
        solve();
    }

}
