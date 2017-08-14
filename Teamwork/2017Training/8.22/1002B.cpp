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
const int MAXV = (1<<30)-1;
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
struct Edge{
    int to, next;
}edge[maxn*2];
int head[maxn], tot;
int top[maxn], fa[maxn];
int dep[maxn], num[maxn];
int p[maxn], fp[maxn];
int son[maxn], pos;
void init() {
    tot=0;
    MEM(head, -1);
    pos=1;
    MEM(son, -1);
}
void addedge(int u, int v) {
    edge[tot].to=v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
void dfs1(int u, int pre, int d) {
    dep[u] = d;
    fa[u]=pre;
    num[u]=1;
    for(int p=head[u]; ~p; p=edge[p].next) {
        int v=edge[p].to;
        if(v!=pre) {
            dfs1(v, u, d+1);
            num[u] += num[v];
            if(son[u]==-1||num[v]>num[son[u]]) {
                son[u] = v;
            }
        }
    }
}
void getpos(int u, int sp) {
    top[u]=sp;
    p[u]=pos++;
    fp[p[u]]=u;
    if(son[u]==-1) return;
    getpos(son[u], sp);
    for(int p=head[u]; ~p; p=edge[p].next) {
        int v=edge[p].to;
        if(v!=son[u]&&v!=fa[u]) {
            getpos(v,v);
        }
    }
}
ll c[maxn];
int n, q;
int rt[maxn];
struct Node{
    int ch[2];
    ll v;
}node[maxn*32];
int nodesz;
void add(int p, int& o, ll v, int l, int r) {

    node[o=++nodesz]=node[p];
    node[o].v += v;
    //printf("%d %d %d %lld %lld\n", o, l, r, node[o].v, v);
    if(l<r) {
        int mid=(l+r)>>1;
        if(mid<v) {
            add(node[p].ch[1], node[o].ch[1], v, mid+1, r);
        }
        else {
            add(node[p].ch[0], node[o].ch[0], v, l, mid);
        }
    }
}
ll query(int p, int o, int l, int r, int al, int ar) {
    if(al<=l&&r<=ar) return node[o].v-node[p].v;
    ll ret=0;
    if(l<r&&o!=p) {
        int mid=(l+r)>>1;
        if(al<=mid&&ar>=l) ret += query(node[p].ch[0], node[o].ch[0], l, mid, al, ar);
        if(al<=r&&ar>mid) ret += query(node[p].ch[1], node[o].ch[1], mid+1, r, al, ar);
    }
    //printf("%d %d %d %d\n", l, r, al, ar, ret);
    return ret;
}
ll Ask(int u, int v, int a, int b) {
    int f1=top[u], f2=top[v];
    ll tmp=0;
    ll ret=0;
    while(f1!=f2) {
        if(dep[f1]<dep[f2]) {
            swap(f1, f2);
            swap(u, v);
        }
        //printf("%d %d %d %d\n", u, f1, v, f2);
        //printf("%d %d\n", p[f1], p[u]);
        tmp = query(rt[p[f1]-1], rt[p[u]], 1, MAXV, a, b);
        ret += tmp;
        //dbg(tmp);
        u=fa[f1];
        f1=top[u];
    }
    if(dep[u]>dep[v]) swap(u,v);
    ret += query(rt[p[u]-1], rt[p[v]], 1, MAXV, a, b);
    //dbg(u);
    return ret;
}
int main(){
    //FILEIN;
    while (~scanf("%d%d", &n, &q)) {
        init();
        for(int i=1; i<n+1; ++i)
            scanf("%I64d", c+i);
        for(int i=1; i<n; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            addedge(u,v);
            addedge(v,u);
        }
        dfs1(1, 0, 0);
        getpos(1, 1);
        nodesz=0;
        CLR(rt);
        for(int i=1; i<n+1; ++i)
            add(rt[i-1], rt[i], c[fp[i]], 1, MAXV);
        while (q--) {
            int s, t, a, b;
            scanf("%d%d%d%d", &s, &t, &a, &b);
            printf("%lld%c", Ask(s,t,a,b), " \n"[q==0]);
        }
    }
    return 0;
}
