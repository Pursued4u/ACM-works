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
const int maxn = 1e6+5;
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
ll a,b,c,d;
ll x[maxn],y[maxn];
int n;
inline ll abss(ll x){
    return x>=0?x:-x;
}
inline void solve(){
    ll minn = INF;
    n =Read();
    for(int i=0;i<n;i++){
        scanf("%I64d%I64d",&x[i],&y[i]);
    }
    ll maxx = 0;
    ll ac = a*c;
    ll t1 = b*c+a*d;
    ll bd = b*d;
    ll t2 = a*d-b*c;
    for(int i=0;i<n;i++){
        ll tmp = ac*x[i]*x[i]+t1*x[i]*y[i]+bd*y[i]*y[i];
        if(tmp<minn) minn = tmp;
        if(tmp>maxx) maxx = tmp;
    }
    //cout << maxx <<" "<< minn <<endl;
    db ans = (1.0*maxx-minn)/t2;
    ans = fabs(ans);
    printf("%I64d\n",ll(ans+0.5));
}
int main(){
    int t = 1;
    int ca = 1;
    while(~scanf("%I64d%I64d%I64d%I64d",&a,&b,&c,&d)) solve();
    return 0;
}
