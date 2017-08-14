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
#define dbg(x) //cout << #x << "=" << x << endl
#define _ixvii0iv
using namespace std;
const int maxn = 1024;
const int maxm = 6144;
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
    int fr, to, next;
    bool operator < (const Edge& b) const {
        return fr==b.fr?to<b.to:fr<b.fr;
    }
    bool operator == (const Edge &b) const {
        return fr==b.fr&&to==b.to;
    }
}e[maxm];
int head[maxn], deg[maxn];
int n, m, dfs_clk, scc_cnt;
int pre[maxn], low[maxn], sccno[maxn];
stack<int> S;
void dfs(int u) {
    pre[u]=low[u]=++dfs_clk;
    S.push(u);
    for(int p=head[u]; ~p; p=e[p].next) {
        int v=e[p].to;
        if(!pre[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } else if(!sccno[v]) {
            low[u] = min(low[u], pre[v]);
        }
    }
    if(low[u]==pre[u]) {
        scc_cnt++;
        while (true) {
            int x=S.top();S.pop();
            sccno[x]=scc_cnt;
            if(x==u) break;
        }
    }
}
bool check() {
    queue<int> q;
    for(int i=1; i<=scc_cnt; ++i) {
        if(deg[i]==0) q.push(i);
    }
    while (!q.empty()) {
        int u=q.front(); q.pop();
        if(!q.empty()) return false;
        for(int p=head[u]; ~p; p=e[p].next) {
            int v=e[p].to;
            if(--deg[v]==0) q.push(v);
        }
    }
    return true;
}
int main(){
    //FILEIN;
    int t;t=Read();
    while (t--) {
        scanf("%d%d", &n, &m);
        MEM(head, -1);
        for(int i=0; i<m; ++i) {
            scanf("%d%d", &e[i].fr, &e[i].to);
            e[i].next=head[e[i].fr];
            head[e[i].fr]=i;
        }
        dfs_clk=scc_cnt=0;
        CLR(pre);
        CLR(sccno);
        for(int i=1; i<n+1; ++i) {
            if(!pre[i]) dfs(i);
        }
        for(int i=0; i<m; ++i) {
            e[i].fr = sccno[e[i].fr];
            e[i].to = sccno[e[i].to];
        }
        sort(e, e+m);
        m = unique(e, e+m)-e;
        MEM(head, -1);
        CLR(deg);
        for(int i=0; i<m; ++i) {
            dbg(e[i].fr);
            dbg(e[i].to);
            if(e[i].fr==e[i].to) continue;
            ++deg[e[i].to];
            e[i].next=head[e[i].fr];
            head[e[i].fr]=i;
        }
        if(check()) puts("I love you my love and our love save us!");
        else puts("Light my fire!");
    }
    return 0;
}
