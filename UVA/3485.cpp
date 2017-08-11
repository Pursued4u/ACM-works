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
#define MEM(a,x) memset(a,x,sizeof(a))
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
#define _ixvii0iv
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
db a,w;

int num;
int sgn(db x){
	return x<-eps?-1:x>eps?1:0;
}
bool eq(db a,db b){
	return fabs(a-b)<=10*eps;
}
inline db F(db x){
	return sqrt(1+4*a*a*x*x);
}
inline db simpson(db a, db b){
	db c = a+(b-a)/2;
	return (F(a)+F(b)+4*F(c))*(b-a)/6;
}
inline db asr(db a,db b,db A){
	db c = a+(b-a)/2;
	db L = simpson(a,c); db R = simpson(c,b);
	if(eq(L+R,A)) return L+R+(L+R-A)/10.0;
	return asr(a,c,L)+asr(c,b,R);

}
inline db get(db mid){
	a = 4*mid/(w*w);
	return db(num)*2*asr(0,w/2.0,simpson(0,w/2.0));
}
int main(){
    db d,h,b,l;
    int ca = 1;
    int t = Read();
    while(t--){
		scanf("%lf %lf %lf %lf",&d,&h,&b,&l);
		num = (b+d-1)/d;
		w = b/db(num);
		db L = 0;
		db R = l;
		while(R-L>eps){
			db mid = L+(R-L)/2.0;
			if(get(mid)<l) L = mid;
			else R = mid;
		}
		printf("Case %d:\n",ca++);
		printf("%.2f\n",h-L);
		if(t) puts("");
    }

}
