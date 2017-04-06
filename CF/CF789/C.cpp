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
#include<set>
#include<queue>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("out.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizoef(a))
#define eps 1e-5
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
const long long maxn = 1e6+5;
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
// C
int fa[maxn*3];
int Find(int x){
    return fa[x]==x?x:fa[x]=Find(fa[x]);
}

ll a[maxn];
ll b[maxn];
ll sum[maxn];
ll sum2[maxn];
int main(){
    int n;
    cin >> n;
    for(int i=0;i<n;i++) scanf("%I64d",&a[i]);
    for(int i=0;i<n-1;i++){
        b[i]=abs(a[i]-a[i+1]);
        if((i%2)) b[i]*=-1;
    }
    ll ans = -INF ;
    ll last = -INF;
    //for(int i=0;i<n-1;i++) cout <<b[i];
    for ( int i = 0 ; i < n-1 ; i++ )
    {
    last = max((ll)0,last)+b[i];
    ans = max(ans,last);
    }

    for(int i=0;i<n-1;i++){
        b[i]*=-1;
    }
    ll ans1=-INF;
    last = -INF;
    for ( int i = 0 ; i < n-1 ; i++ )
    {
    last = max((ll)0,last)+b[i];
    ans1= max(ans1,last);
    }
    cout << max(ans1,ans) <<endl;
