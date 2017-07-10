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
int a[maxn],b[maxn];
int main()
{
    int n,m;
    cin >> n >> m;
    int maxx=-inf;
    int maxy=-inf;

    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<m;i++) cin >> b[i];
    for(int i=1;i<n-1;i++) maxx = max(maxx,a[i]);
    for(int i=1;i<m-1;i++) maxy = max(maxy,b[i]);
    int ans1 = min(a[0],min(a[n-1],maxy));
    int ans2 = min(b[0],min(b[m-1],maxx));
    int ans3 = min(a[0],b[m-1]);
    int ans4 = min(b[0],a[n-1]);
    //cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << endl;
    if(maxx!=-inf&&maxy!=-inf)
    cout << max(max(max(ans1,ans2),ans3),ans4);
    if(maxx == -inf&&maxy!=-inf)
    cout << max(ans1,max(ans3,ans4));
    if(maxx!=-inf&&maxy==-inf)
    cout << max(ans2,max(ans3,ans4));
    if(maxx==-inf&&maxy==-inf)
    cout << max(ans3,ans4);
    cout << endl;

    
}
