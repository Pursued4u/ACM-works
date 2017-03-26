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
const int maxn = 1e5+5;
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
ll n, k, a[maxn], c[maxn], res;
int du[maxn];
vector<int> G[maxn];
vector<ll> cnt;
/*
ll lowbit(ll x) {
    return x & (-x);
}

void update(ll x, ll p) {
    while (x < maxn) {
        c[x] += p;
        x += lowbit(x);
    }
}

ll getsum(ll x) {
    ll ans = 0;
    while (x) {
        ans += c[x];
        x -= lowbit(x);
    }
    return ans;
}*/

void dfs(int x) {
    for (int i = 0; i < G[x].size(); i++) {
        int u = G[x][i];
        dfs(u);
    }
    ll tmp = k / a[x];
    ll hh = upper_bound(cnt.begin(), cnt.end(), tmp) - cnt.begin();
    //for (int j = 0; j < cnt.size(); j++) cout << cnt[j] << endl;
    res += hh;
    cnt.push_back(a[x]);
}

void init() {
    //memset(c, 0, sizeof(c);
    cnt.clear(); res = 0;
    memset(du, 0, sizeof(du));
    for (int i = 1; i <= n; i++)
        G[i].clear();
}

void solve() {
    cin >> n >> k;
    init();
    for (int i = 1; i <= n; i++) {
        scanf("%I64d", a+i);
    }
    for (int i = 1; i < n; i++) {
        int u, v; scanf("%d%d", &u, &v);
        du[v]++;
        G[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) {
        if (!du[i]) {
            dfs(i);
            break;
        }
    }
    cout << res << endl;
}

int main()
{
    int t; cin >> t;
    while (t--) solve();
}
