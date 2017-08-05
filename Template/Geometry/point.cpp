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
int sgn(db x){ return x<-eps?-1:x>eps?1:0 ;}

struct point{
    int x,y;
    point(int _x = 0,int _y = 0){
        x = _x;
        y = _y;
    }
    point operator -(const point &b){
        return point(x-b.x,y-b.y);
    }
    ll operator ^(const point &b){
        return (x*b.y-y*b.x);
    }
    ll operator *(const point &b){
        return (x*b.x+y*b.y);
    }
	bool operator == (const point &b){
		return !sgn(b.x-x)&&!sgn(b.y-y);
	}
};
db Dis(point a,point b){
    return (a-b)*(a-b);
}

bool cmp(point a,point b){
	return a.x<b.x||(a.x==b.x&&a.y<b.y);
}


int main(){
	point a,b;
	a.x = 1;
	a.y = 1;
	b.x = 2;
	b.y = 2;
	line c = b-a;
	cout << c.x << " " << c.y << endl;
}


