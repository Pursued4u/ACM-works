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
int n, q;
int d[maxn];
int a[maxn], b[maxn], c[maxn];
int ia[maxn], ib[maxn], ic[maxn];
void solve(){
    a[0]=ia[0]=-1;
    for(int i=1; i<n+1; ++i) {
        scanf("%d", d+i);
        a[i]=a[i-1]&d[i];
        b[i]=b[i-1]|d[i];
        c[i]=c[i-1]^d[i];
    }
    for(int i=1; i<n+1; ++i) {
        ia[i] = ia[i-1]&d[n-i+1];
        ib[i] = ib[i-1]|d[n-i+1];
        ic[i] = ic[i-1]^d[n-i+1];
    }
    while(q--) {
        int x; scanf("%d", &x);
        int ans[3];
        ans[0] = a[x-1]&ia[n-x];
        ans[1] = b[x-1]|ib[n-x];
        ans[2] = c[x-1]^ic[n-x];
        printf("%d %d %d\n", ans[0], ans[1], ans[2]);
    }
}
int main(){
    while(~scanf("%d%d", &n, &q)) solve();
    return 0;
}
