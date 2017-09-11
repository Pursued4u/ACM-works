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
#define MEM(a,x) memset(a,x,sizeof(a))
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
#define _ixvii0iv
using namespace std;
const int maxn = 1e5+1e3;
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
const int maxm=1e7;
int tr[maxm][2], sz, rt[maxn];
int fa[maxn], deg[maxn], a[maxn];
int q[maxn];
int n, m;
void Mytran(int *d, int x) {
    for(int i=31; i>-1; --i) {
        d[i]=x&1;
        x>>=1;
    }
}
inline int newnode() {
    ++sz;
    tr[sz][0]=tr[sz][1]=0;
    return sz;
}
void Add(int& rt, int x) {
    static int d[32];
    Mytran(d, x);
    if(!rt) rt=newnode();
    int u=rt;
    for(int i=0; i<32; ++i) {
        if(!tr[u][d[i]])
            tr[u][d[i]]=newnode();
        u=tr[u][d[i]];
    }
}
int Ask(int u, int x) {
    static int d[32];
    int ret=0;
    Mytran(d, x);
    for(int i=0; i<32; ++i) {
        if(tr[u][1^d[i]]) {
            u=tr[u][1^d[i]];
            ret = ret<<1|1;
        }
        else {
            u=tr[u][d[i]];
            ret = ret<<1;
        }
    }
    return ret;
}
bool Mymerge(int p, int &o) {
    if(!p)
        return true;
    else if(!o) {
        o=p;
        return false;
    }
        int nu=newnode();
        tr[nu][0]=tr[o][0];
        tr[nu][1]=tr[o][1];
        bool res0 = Mymerge(tr[p][0], tr[nu][0]);
        bool res1 = Mymerge(tr[p][1], tr[nu][1]);
        if(res0&&res1) {
            --sz;
            return true;
        }
        o = nu;
        return false;
}
void solve() {
        sz=0;
        CLR(deg);
        CLR(rt);
    for(int i=1; i<n+1; ++i) {
        scanf("%d", a+i);
        Add(rt[i], a[i]);
    }
    fa[1]=0;
    for(int i=2; i<n+1; ++i) {
        scanf("%d", fa+i);
        ++deg[fa[i]];
    }

    int l=0, r=0;
    for(int i=1; i<n+1; ++i)
        if(!deg[i]) q[r++]=i;
    while (l<r) {
        int u=q[l++];
        if(fa[u]) {
        Mymerge(rt[u], rt[fa[u]]);
        if(--deg[fa[u]]==0) {
            q[r++] = fa[u];
        }
        }
    }
    /*for(int i=1; i<n+1; ++i)
        printf("rt(%d):\t%d\n", i, rt[i]);
    for(int i=1; i<=sz; ++i)
        printf("%d %d\n", tr[i][0], tr[i][1]);*/
    while (m--) {
        int u, x;
        scanf("%d%d", &u, &x);
        printf("%d\n", Ask(rt[u], x));
    }
}
int main(){
    while (~scanf("%d%d", &n, &m)) {
        solve();
    }
    return 0;
}
