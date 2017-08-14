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
const int maxn = 1e2+5;
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
struct point{
    double x,y;
    point operator + (point a){ return {x + a.x, y + a.y}; }
    point operator - (point a){ return {x - a.x, y - a.y}; }
    point operator / (double z){ return { x/z, y/z}; }
    double len1() { return x * x + y * y; }
    double len() { return sqrt(len1()) ;}
};
int sgn(double x){
    return x>eps?1:x<-eps?-1:0;
}

double det(point a, point b){
    return a.x * b.y - a.y * b.x;
}
point waixin(point a,point b,point c){
   double a1 = b.x-a.x, b1 = b.y-a.y, c1 = (a1*a1+b1*b1)/2;
   double a2 = c.x-a.x, b2 = c.y-a.y, c2 = (a2*a2+b2*b2)/2;
   double d = a1*b2 - a2*b1;
   return point{a.x+(c1*b2-c2*b1)/d,a.y-(a1*c2-a2*c1)/d/2};
}

int in[maxn];
int n;
point po[maxn];
int type[maxn];
bool check(point x, double r){
    for(int i=1;i<=n;i++){
        int tmp = sgn((po[i]-x).len() - r);
        if(in[i] && tmp>0) return true;
        if(!in[i] && tmp<0) return true;
    }
    return false;
}

int main()
{
    n = Read();
    int cnt = 0;
    for(int i=1;i<=n;i++){
        char a[2];
        scanf("%lf %lf %s",&po[i].x,&po[i].y,a);
        in[i] = a[0]=='I'?1:0;
        if(a[0]=='I') cnt++;
    }
    if(n<=2||cnt<=1){
        puts("No");
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            for(int k=j+1;k<=n;k++){
                if(sgn(det(po[i]-po[j],po[i]-po[k]))){
                    point yx = waixin(po[i],po[j],po[k]);
                    db r = (po[i] - yx).len();
                    if(!check(yx,r))
                    {
                        cout << "No\n";
                        return 0;
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            point yx = (po[i]+po[j])/2;
            double r = (po[i]-yx).len();
            if(!check(yx,r))
            {
                cout << "No\n";
                return 0;
            }
        }
    }
    puts("Yes");
}


