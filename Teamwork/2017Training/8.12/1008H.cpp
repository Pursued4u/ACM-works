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
#define pi acos(-1)
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
#define N 1005
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
double area[maxn];


int dcmp(double x) {
    if (x < -eps) return -1; else return x > eps?1:0;
}
db xx[maxn];
db yy[maxn];
db zz[maxn];
db mid;
int n,k;
db w,s;

struct cp {
    double x, y, r, angle;
    int d;
    cp(){}
    cp(double xx, double yy, double ang = 0, int t = 0) {
        x = xx;  y = yy;  angle = ang;  d = t;
    }
    void get(int i,db midd) {
        db ll = sqrt(xx[i]*xx[i]+yy[i]*yy[i]+midd*midd);
        x = xx[i];
        y = yy[i];
        r = w/(ll*zz[i]);
        d = 1;//
    }
}cir[maxn], tp[N * 2];

db sqr(db x){
	return x*x;
}
double dis(cp a, cp b) {
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

double cross(cp p0, cp p1, cp p2) {
    return (p1.x - p0.x) * (p2.y - p0.y) - (p1.y - p0.y) * (p2.x - p0.x);
}


int CirCrossCir(cp p1, double r1, cp p2, double r2, cp &cp1, cp &cp2) {
    double mx = p2.x - p1.x, sx = p2.x + p1.x, mx2 = mx * mx;
    double my = p2.y - p1.y, sy = p2.y + p1.y, my2 = my * my;
    double sq = mx2 + my2, d = -(sq - sqr(r1 - r2)) * (sq - sqr(r1 + r2));
    if (d + eps < 0) return 0; if (d < eps) d = 0; else d = sqrt(d);
    double x = mx * ((r1 + r2) * (r1 - r2) + mx * sx) + sx * my2;
    double y = my * ((r1 + r2) * (r1 - r2) + my * sy) + sy * mx2;
    double dx = mx * d, dy = my * d; sq *= 2;
    cp1.x = (x - dy) / sq; cp1.y = (y + dx) / sq;
    cp2.x = (x + dy) / sq; cp2.y = (y - dx) / sq;
    if (d > eps) return 2; else return 1;
}

bool circmp(const cp& u, const cp& v) {
    return dcmp(u.r - v.r) < 0;
}

bool cmp(const cp& u, const cp& v) {
    if (dcmp(u.angle - v.angle)) return u.angle < v.angle;
    return u.d > v.d;
}

double calc(cp cir, cp cp1, cp cp2) {
    double ans = (cp2.angle - cp1.angle) * sqr(cir.r)
        - cross(cir, cp1, cp2) + cross(cp(0, 0), cp1, cp2);
    return ans / 2;
}

void CirUnion(cp cir[], int n) {
    cp cp1, cp2;
    sort(cir, cir + n, circmp);
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (dcmp(dis(cir[i], cir[j]) + cir[i].r - cir[j].r) <= 0)
                cir[i].d++;
    for (int i = 0; i < n; ++i) {
        int tn = 0, cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            if (CirCrossCir(cir[i], cir[i].r, cir[j], cir[j].r,
                cp2, cp1) < 2) continue;
            cp1.angle = atan2(cp1.y - cir[i].y, cp1.x - cir[i].x);
            cp2.angle = atan2(cp2.y - cir[i].y, cp2.x - cir[i].x);
            cp1.d = 1;    tp[tn++] = cp1;
            cp2.d = -1;   tp[tn++] = cp2;
            if (dcmp(cp1.angle - cp2.angle) > 0) cnt++;
        }
        tp[tn++] = cp(cir[i].x - cir[i].r, cir[i].y, pi, -cnt);
        tp[tn++] = cp(cir[i].x - cir[i].r, cir[i].y, -pi, cnt);
        sort(tp, tp + tn, cmp);
        int p, s = cir[i].d + tp[0].d;
        for (int j = 1; j < tn; ++j) {
            p = s;  s += tp[j].d;
            area[p] += calc(cir[i], tp[j - 1], tp[j]);
        }
    }
}

bool check(db x)
{
    for (int i = 0; i < n; ++i)
	cir[i].get(i,x);
    memset(area, 0, sizeof(area));
    CirUnion(cir, n);
    //去掉重复计算的
    //area[i]为重叠了i次的面积
    return dcmp(area[k]-s)>=0;
    //tot 为总面积

}

int main(){
	int t = Read();
	while(t--){
		scanf("%d%lf%d%lf",&n,&w,&k,&s);
		db l = 0;
		db r = 1000;
		int tm = 0;
		for(int i=0;i<n;i++){
			scanf("%lf%lf%lf",&xx[i],&yy[i],&zz[i]);
		}
		if(!check(0)) {
			cout << "No solution!" <<endl;
			continue;
		}
		if(check(500)){
			cout << "Oops!" <<endl;
			continue;
		}

		while(r-l>eps){
			if(tm>100) break;
			mid = (l+r)/2.0;
			if(check(mid))l = mid;
			else r = mid;
			tm++;
		}
		printf("%.4f\n",l);
	}
}
