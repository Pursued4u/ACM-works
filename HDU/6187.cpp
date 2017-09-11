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
inline ll Read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n,m;
struct edge{
    int w,u,v;
}e[maxn*2]; int fa[maxn];
inline int Find(int x){
    return fa[x] == x?x:fa[x] = Find(fa[x]);
}
bool cmp(edge a,edge b){
    return a.w>b.w;
}
void solve(){
    for(int i=0;i<n;i++){
        int x,y;
        x = Read();y=Read();
    }
    ll ans = 0;
    for(int i=0;i<=n;i++) fa[i] = i;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
        ans+=e[i].w;
    }
    ll cnt = 0;
    ll cnt1 = 0;
    sort(e,e+m,cmp);
    for(int i=0;i<m;i++){
        int faa = Find(e[i].v);
        int fab = Find(e[i].u);
        if(faa!=fab){
            fa[faa] = fab;
            cnt+=e[i].w;
            cnt1++;
        }
    }
    //cout << cnt << endl;
    cout << m-cnt1 << " " << ans-cnt << endl;
}
int main(){
    int t = 1;
    int ca = 1;
    while(scanf("%d %d",&n,&m)!=EOF) solve();
    return 0;
}
