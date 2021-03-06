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

int color[maxn];
vector<int>G[maxn];
bool bfs(int v,int cur){
    color[v] = 1;
    queue<int>que;que.push(v);
    while(que.size()){
        int cur = que.front(); que.pop();
        for(int i=0;i<G[cur].size();i++){
            int u = G[cur][i];
            if(color[u]==color[cur]) return false;
            if(!color[u]){
                color[u] = -color[cur];
                que.push(u);
            }
        }
    }
    return true;

}
void init(int x){
    CLR(color);
    for(int i=1;i<=x;i++) G[i].clear();
}
int main(){
    #ifdef ONLINE_JUDGE
    #else 
        FILEIN;
    #endif
    int t;cin >> t;
    int ca = 1;
    while(t--){
        int m,n; cin >> m >> n;
        init(m);
        for(int i=1;i<=n;i++){
            int u,v;
            u = Read();
            v = Read();
            G[u].PB(v);
            G[v].PB(u);
        }
        int flag = 1;
        for(int i=1;i<=m;i++){
            if(flag&&!color[i]){
                flag = bfs(i,1);
            }
        }
        printf("Scenario #%d:\n",ca++);
        if(flag){
            cout << "No suspicious bugs found!" << endl;
        }
        else cout << "Suspicious bugs found!" << endl;
        cout << endl;
    }
}