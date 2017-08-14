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
const int maxn = 1e3+5;
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
/*
db diss(db x1,db y1,db x2,db y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
struct pos
{
    db x,y;
    int va;
}a[maxn];
int main()
{
    int t=Read();
    while(t--)
    {
        CLR(a);
        int n=Read();
        for(int i=0;i<n;i++)
        {
            int x;
            scanf("%d",&x);
            scanf("%lf %lf",&a[x].x,&a[x].y);
            a[x].va=1;
        }
        db maxx=0;
        for(int i=1;i<=maxn;i++)
        {
            if(a[i].va==1&&a[i-1].va==1)
            {
                db ans=diss(a[i].x,a[i].y,a[i-1].x,a[i-1].y);
                maxx=max(ans,maxx);
            }
        }
        printf("%.12f\n",maxx);
    }
}*/

struct pos {
    int id;
    ll x, y;
} q[maxn];

bool cmp(const pos &a, const pos &b) {
    return a.id < b.id;
}

db dis(db x1, db x2, db y1, db y2) {
    return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void solve() {
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d%lld%lld", &q[i].id, &q[i].x, &q[i].y);
    db ans = 0;
    for (int i = 2; i <= n; i++) {
        ans = max(ans, dis(q[i-1].x, q[i].x, q[i-1].y, q[i].y)/(db)(q[i].id-q[i-1].id));
    }
    printf("%.10f\n", ans);
}

int main() {
    int t; cin >> t;
    while (t--) {
        solve();
    }
}
