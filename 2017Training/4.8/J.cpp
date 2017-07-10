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
int n,m,c;
struct node{
    int to,co;
    node(int x,int v){
        to = x;
        co = v;
    }
    node() {}
    bool operator<(const node&a) const {
        return a.co<co;
    }
}; 
vector<node>E[maxn*2];
vector<int>dep[maxn];
bool vis[maxn*2];
int dis[maxn];
void spfa(){
    priority_queue<node>que;    
    CLR(vis);
    for(int i=1;i<=n*2;i++){
        dis[i]=mod;
    }
    dis[1]=0;
    que.push(node(1,0));
    while(que.size()){
        node tmp = que.top(); que.pop();
        if(vis[tmp.to]) continue; 
        vis[tmp.to]=1;
        for(int i=0;i<E[tmp.to].size();i++){
            node ne = E[tmp.to][i];
            if(dis[ne.to]>dis[tmp.to]+ne.co){
                dis[ne.to]=dis[tmp.to]+ne.co;
                que.push(node(ne.to,dis[ne.to]));
            }
        }
     }
}
int main()
{
    int t;
    int ca = 1;
    cin >> t;
    while(t--){
        for(int i=1;i<=n;i++) dep[i].clear();
        for(int i=1;i<=2*n;i++) E[i].clear();
        scanf("%d %d %d",&n,&m,&c);
        for(int i=1;i<=n;i++){
            int x;scanf("%d",&x);
            dep[x].PB(i);
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<dep[i].size();j++){
                int x = dep[i][j];
                if(i>1){
                    E[x].PB(node(n+i-1,c));
                }
                if(i<n){
                    E[x].PB(node(n+i+1,c));
                }
                E[n+i].PB(node(x,0));
            }
            
        }
        for(int i=0;i<m;i++){
            int u,v,w;
            scanf("%d %d %d",&u,&v,&w);
            E[u].PB(node(v,w));
            E[v].PB(node(u,w)); 
        }
        spfa();
        printf("Case #%d: ",ca++);
        if(dis[n]==mod){
            cout << -1 << endl;
            
        }
        else cout << dis[n] <<endl;
    }

}
