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
const int maxn = 4e4+5;
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

std::vector<pair<int,int> > G[maxn];

inline void solve(){
    int n,m;n = Read(),m = Read();
    for(int i = 0;i < n+1;++i) G[i].clear();
    for(int i = 0;i < n-1;++i){
        int u,v,w;
        u = Read(),v = Read(),w =  Read();
        G[u].push_back({v,w});
        G[v].push_back({u,w});
    }
    for(int i =0;i < m;++i){
        int op,x,y,z;op = Read();
        if(op == 0){
            x = Read();
            int cnt = 0;
            for(int j = 0;j < G[x].size();++j){
                cnt += G[x][j].second;
            }
            if(cnt&1) puts("Girls win!");
            else puts("Boys win!");
        }
        else {
            x = Read(),y = Read(),z = Read();
            for(int j = 0;j < G[x].size();j++){
                if(G[x][j].first == y){
                    G[x][j].second = z;
                }
            }
            for(int j = 0;j < G[y].size();j++){
                if(G[y][j].first == x){
                    G[y][j].second = z;
                }
            }
        }
    }
}
int main(){
    int t = Read();
    int ca = 1;
    while(t--) solve();
    return 0;
}
