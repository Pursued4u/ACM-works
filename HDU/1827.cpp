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
using namespace std;
const int maxn = 1e3+5;

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
    int from,to,next;
}edge[maxn*2];
int head[maxn];
int tot;
int low[maxn],dfn[maxn],belong[maxn];
int index;
int scc;
bool vis[maxn];
int num[maxn];
int cost[maxn];
int in[maxn];
void addedge(int u,int v){
    edge[tot].from = u;
    edge[tot].to = v;
    edge[tot].next = head[u];
    head[u] = tot++;
}
stack<int>st;
int totcost[maxn];
void tarjan(int u){
    int v;
    low[u] = dfn[u] = ++index;
    st.push(u);
    for(int i=head[u];i!=-1;i = edge[i].next){
        v = edge[i].to;
        if(!dfn[v]){
            tarjan(v);
            low[u] = min(low[u],low[v]);
        }
        else if(!belong[v])
            low[u] = min(dfn[v],low[u]);

    }
    if(low[u] == dfn[u]){
        scc++;
        while(1){
            v = st.top();
            st.pop();
            belong[v] = scc;
            if(u==v) break;
        }
    }
}
void init(){
    tot = 0;
    MEM(head,-1);
    CLR(dfn);
    CLR(belong);
    MEM(totcost,0x3f);
    scc = index = 0;
    while(st.size()){
        st.pop();
    }
}
int main(){
    #ifdef ONLINE_JUDGE
    #else
        FILEIN;
    #endif
    int m,n;
    while(scanf("%d %d",&m,&n)!=EOF){
        init();
        for(int i=1;i<=m;i++){
            scanf("%d",&cost[i]);
        }

        for(int i=0;i<n;i++){
            int u,v;
            scanf("%d %d",&u,&v);
            addedge(u,v);
        }
        for(int i=1;i<=m;i++){
            if(!dfn[i]) tarjan(i);
        }
        for(int i=0;i<=scc;i++){
            in[i] = 1;
        }
        for(int i=0;i<tot;i++){
            int u = edge[i].from;
            int v = edge[i].to;
            if(belong[v]!=belong[u]){
                in[belong[v]]=0;
            }

        }
        for(int i=1;i<=m;i++){
            totcost[belong[i]] = min(totcost[belong[i]],cost[i]);
        }
        int ans = 0;
        int numm = 0;
        for(int i=1;i<=scc;i++){
            if(in[i]){
                numm++;
                ans+=totcost[i];
            }
        }
        cout << numm << " " << ans <<endl;
    }

}
