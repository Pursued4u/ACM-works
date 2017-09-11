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
#define eps 1e-15
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
int dcmp(long double x) {
    if(x>eps) return 1;
    if(x<-eps) return -1;
    return 0;
}
inline ll Read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
long double a[maxn];
void solve(){
    long double one=1;
    int n=Read();
    for(int i=0; i<n; ++i) {
        double A, B;
        int la, lb;
        scanf("%lf:%lf", &A, &B);
        la = int(floor(A*1000));
        //cout <<la << endl; 
        lb = int(floor(B*1000));
        //cout << lb << endl;
        a[i]=1.0*la/(la+lb);
    }
    sort(a, a+n);
    int ans=0;
    for(int i=0; i<n; ++i) {
        if(i) a[i]+=a[i-1];
        if(a[i]>=1.0) break;
        ++ans;
    }
    printf("%d\n", ans);
}
int main(){
    int t = Read();
    int ca = 0;
    while(t--) {
        printf("Case #%d: ", ++ca);
        solve();
    }
    return 0;
}
