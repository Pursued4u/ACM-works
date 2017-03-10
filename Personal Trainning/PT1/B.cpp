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

double sgn(double x){
    return x<-eps?-1:x<eps?0:1;
}
struct node{
    ll x,y;
};

ll ab(ll x){
    return x<0?-x:x;
}
ll cx(node a,node b){
    return a.x*b.y-a.y*b.x;
}
node po[5];
int main()
{
    //FILEIN;
    int t;
    cin >> t;
    int ca = 1;
    while(t--){

        for(int i=0;i<4;i++){
            cin >> po[i].x>>po[i].y;
        }
        for(int i=1;i<4;i++){
            po[i].x -=po[0].x;
            po[i].y -=po[0].y;
        }
        ll pr;
        scanf("%lld",&pr);
        ll area= ab(cx(po[1],po[2]))+(cx(po[2],po[3]));
        double ans = (double)pr*2/area;
        printf("Case #%d: ",ca++);
        printf("%.2f\n",ans);
    }
}
