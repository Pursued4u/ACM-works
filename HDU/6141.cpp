#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<set>
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
#define endl '\n'
#define _ixvii0iv
using namespace std;
const int maxn = 1e3+5;
const int maxm = 1e4+5;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;
ll mul(ll x,ll y){return x*y%mod;}
ll q_mul(ll a, ll b){ ll ans = 0;while(b){if(b & 1){ans=(ans+a)%mod;} b>>=1;a=(a+a) % mod;}return ans;}
ll q_pow(ll x , ll y){ll res=1;while(y){if(y&1) res=q_mul(res,x) ; y>>=1 ; x=q_mul(x,x);} return res;}
ll inv(ll x) { return q_pow(x, mod-2); }
inline ll Read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct node{
    db x,y;
};
node po[maxm];
struct Edge{
    int u,v;
    int cost;
}edge[maxn];

int pre[maxm],id[maxm],visit[maxm];
int in[maxm];
int ZL(int root,int n,int m,Edge edge[]){
    db res = 0;
    int u,v;
    while(1){
        for(int i=0;i<n;i++) in[i] = inf;
        for(int i=0;i<m;i++){
            if(edge[i].u!=edge[i].v&&edge[i].cost<in[edge[i].v]){
                pre[edge[i].v] = edge[i].u;
                in[edge[i].v] = edge[i].cost;
            }
        }
        for(int i=0;i<n;i++){
            if(i!=root&&in[i]==inf)
                return -1;
        }
        int cnt = 0;
        MEM(id,-1);
        MEM(visit,-1);
        in[root] = 0;
        for(int i=0;i<n;i++){
            res+=in[i];
            v = i;
            while(visit[v]!=i&&id[v]==-1&&v!=root){
                visit[v] = i;
                v = pre[v];
            }
            if(v!=root &&id[v]==-1){
                for(u=pre[v];u!=v;u = pre[u]) id[u] = cnt;
                id[v] = cnt++;
            }
        }
        if(cnt==0) break;
        for(int i=0;i<n;i++)
            if(id[i]==-1) id[i] = cnt++;
        for(int i=0;i<m;){
            v = edge[i].v;
            edge[i].u = id[edge[i].u];
            edge[i].v = id[edge[i].v];
            if(edge[i].u!=edge[i].v) edge[i++].cost-=in[v];
            else swap(edge[i],edge[--m]);
        }
        n = cnt;
        root = id[root];
    }
    return res;
}
void solve(){
    int n = Read();
    int m = Read();
    for(int i=0;i<m;i++){
        int x,y,w;
        x = Read();
        y = Read();
        w = Read();
        edge[i].u = x-1;
        edge[i].v = y-1;
        edge[i].cost = -w*n;
        if(y==n){
            edge[i].cost += x-y;
        }
    }
    int res = ZL(0,n,m,edge);
    //cout <<res << endl;
    cout << (-res)/n << " " << n-((-res)%n) << endl;

}

int main(){
    int t = Read();
    int ca = 1;
    while(t--) solve();
    return 0;
}
