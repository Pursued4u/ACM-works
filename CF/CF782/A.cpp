#include<bits/stdc++.h>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("out.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizoef(a))
#define eps 1e-7
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
const int maxn = 2e5+5;
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
map<int,int>mp;
struct node{
    double l,v;
};

double nmax(double x,double y){
    if(x-y>eps) return x;
    else return y;
}
int n;
node a[maxn];
double minn;
double check(double x){
    minn = 0;
    for(int i=0;i<n;i++){
        double tmp = fabs(x-a[i].l)/a[i].v;
        minn = nmax(minn,tmp);
    }
    return minn;
}
int cnt = 0;
void  trible(double l,double r){

    while(r-l>eps){
        
        double mid = (l+r)/2.0;
        //cout << mid << endl;
        double midd = (mid+r)/2.0;
        if(check(midd)-check(mid)>=eps) r = midd;
        else l = mid;
        cnt++;
        if(cnt>=50000)
        break;
    }
    
}
int main(){
    cin >> n;
    double ll,rr;
    ll = inf;
    rr = 0;
    for(int i=0;i<n;i++){
        scanf("%lf",&a[i].l);
        ll = min(ll,a[i].l);
        rr = nmax(rr,a[i].l);
    }
    for(int i=0;i<n;i++){
        scanf("%lf",&a[i].v);
    }
    //cout << ll << rr << endl;
    trible(ll,rr);
    printf("%.8f\n",minn);
}