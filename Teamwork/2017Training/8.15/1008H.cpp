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
#define _ixvii0iv
using namespace std;
const int maxn = 1e5+1e3;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;
const int DEBUG=1;
const double PI = acos(-1.0);
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
int dcmp(double x) {
    if(x>eps) return 1;
    if(x<-eps) return -1;
    return 0;
}
struct Point{
    int x, y, val;
    double rad;
    Point() {}
    Point(int xx, int yy, int vv) {
        x=xx, y=yy, val=vv;
        rad = atan2(1.0*y,1.0*x);
    }
    bool operator < (const Point& b) const {
        return dcmp(rad-b.rad)<0;
    }
    void print() {
        printf("%d\t%d\t%d\t%.3f\n", x, y, val,rad);
    }
}P[maxn];
int n, sum;
double cmprad(double x) {
    while(x<0) x+=2*PI;
    while(x>=2*PI) x-=2*PI;
    return x;
}
void solve() {
    scanf("%d", &n);
    int total = 0, sum=0;
    ll ans=0;
    for(int i=0; i<n; ++i) {
        int x, y, v;
        scanf("%d%d%d", &x, &y, &v);
        total += v;
        P[i]=Point(x,y,v);
    }
    sort(P, P+n);
    for(int i=0; i<n; ++i) {
        P[i+n]=P[i];
    }
    int j=0;
    for(int i=0; i<n; ++i) {
        j=max(j, i);
        while(j<n+i&&cmprad(P[j].rad-P[i].rad)<PI) {
            sum += P[j].val;
            ans = max(ans, 1ll*sum*(total-sum));
            ++j;
        }
        //printf("%d\t%d\n", i, j);
        sum -= P[i].val;
    }
    printf("%lld\n", ans);
}
int main(){
    int t; scanf("%d", &t);
    while (t--) {
        solve();
    }
    return 0;
}
