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
#include<ctime>
#include<queue>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("out.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizoef(a))
#define eps 1e-8
#define sf(x) scanf("%d",&x)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define fi first
#define se second
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl
using namespace std;
const int maxn = 2e3+5;
typedef long long ll;
typedef double db;
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
    char v; int x;
};
vector<int> G[maxn];
//vector<pos> mapp[maxn][maxn];
int ans, x[maxn], y[maxn], link[maxn];
bool vis[maxn];
string b[maxn];

void init() {
    ans = 0;
    memset(link, -1, sizeof(link));
    //memset(pri, 0, sizeof(pri));
    //memset(w, 0, sizeof(w));
    for (int i = 0; i < maxn; i++) {
        G[i].clear();
    }
}

bool Find(int x) {
    for (int i = 0; i < G[x].size(); i++) {
        int u = G[x][i];
       // if (u == fa) continue;
        if (vis[u]) continue;
        vis[u] = 1;
        if (link[u] == -1 || Find(link[u])) {
            link[u] = x;
            return true;
        }
    }
    return false;
}

bool ju(int st1, int st2, string a, string b) {
    bool liv[maxn]; char ma[maxn];
    memset(liv, 0, sizeof(liv));
    for (int i = st1; i < a.length()+st1; i++) {
        liv[i] = 1;
        ma[i] = a[i-st1];
    }
    for (int i = st2; i < b.length()+st2; i++) {
        if (liv[i]) {
            if (ma[i] != b[i-st2]) return true;
        }
    }
    return false;
}

void solve() {
    int h, v; scanf("%d%d", &h, &v);
    init();
    for (int i = 1; i <= h; i++) {
        scanf("%d%d", x+i, y+i);
        cin >> b[i];
    }
    for (int i = h+1; i <= v+h; i++) {
        scanf("%d%d", x+i, y+i);
        cin >> b[i];
    }
    for (int i = 1; i <= v+h; i++) {
        for (int j = i+1; j <= h+v; j++) {
            if (i <= h && j <= h) {
                if (y[i] != y[j]) continue;
                if (ju(x[i], x[j], b[i], b[j])) G[i].push_back(j);
            }
            else if (i <= h && j > h) {
                if (x[i] > x[j] || x[i] + b[i].length() <= x[j]) continue;
                if (y[j] > y[i] || y[j] + b[j].length() <= y[i]) continue;
                if (b[i][x[j]-x[i]] != b[j][y[i]-y[j]]) G[i].push_back(j);
            }
            else {
                if (x[i] != x[j]) continue;
                if (ju(y[i], y[j], b[i], b[j])) G[i].push_back(j);
            }
        }
    }
    for (int i = 1; i <= v+h; i++) {
        memset(vis, 0, sizeof(vis));
        if (Find(i)) {
           // cout << i << endl;
            ans++;
        }
    }
    cout << v+h - ans << endl;
}

int main()
{
    int t; cin >> t;
    while (t--) solve();
}
