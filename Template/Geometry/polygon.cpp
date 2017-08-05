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
#define LOCAL
const int maxn = 5e5+5;
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
const int MAXN=1800;
int m;
double r;
db area;
int cCnt,curCnt;//此时cCnt为最终切割得到的多边形的顶点数、暂存顶点个数
struct point
{
    double x,y;
};
point points[MAXN],p[MAXN],q[MAXN];//读入的多边形的顶点（顺时针）、p为存放最终切割得到的多边形顶点的数组、暂存核的顶点

void getline(point x,point y,double &a,double &b,double   &c){//两点x、y确定一条直线a、b、c为其系数
    a = y.y - x.y;
    b = x.x - y.x;
    c = y.x * x.y - x.x * y.y;
}
void initial(){
    for(int i = 1; i <= m; ++i)p[i] = points[i];
    p[m+1] = p[1];
    p[0] = p[m];
    cCnt = m;//cCnt为最终切割得到的多边形的顶点数，将其初始化为多边形的顶点的个数
}
point intersect(point x,point y,double a,double b,double c){//求x、y形成的直线与已知直线a、b、c、的交点
    double u = fabs(a * x.x + b * x.y + c);
    double v = fabs(a * y.x + b * y.y + c);
    point pt;
    pt.x=(x.x * v + y.x * u) / (u + v);
    pt.y=(x.y * v + y.y * u) / (u + v);
    return  pt;
}
void cut(double a,double b ,double c){
    curCnt = 0;
    for(int i = 1; i <= cCnt; ++i){
        if(a*p[i].x + b*p[i].y + c >= 0)q[++curCnt] = p[i];// c由于精度问题，可能会偏小，所以有些点本应在右侧而没在，
        //故应该接着判断
        else {
            if(a*p[i-1].x + b*p[i-1].y + c > 0){//如果p[i-1]在直线的右侧的话，
                //则将p[i],p[i-1]形成的直线与已知直线的交点作为核的一个顶点(这样的话，由于精度的问题，核的面积可能会有所减少)
                q[++curCnt] = intersect(p[i],p[i-1],a,b,c);
            }
            if(a*p[i+1].x + b*p[i+1].y + c > 0){//原理同上
                q[++curCnt] = intersect(p[i],p[i+1],a,b,c);
            }
        }
    }
    for(int i = 1; i <= curCnt; ++i)p[i] = q[i];//将q中暂存的核的顶点转移到p中
    p[curCnt+1] = q[1];p[0] = p[curCnt];
    cCnt = curCnt;
}
void solve(){
  //注意：默认点是顺时针，如果题目不是顺时针，规整化方向
    initial();
    /*for(int i = 1; i <= m; ++i){
        double a,b,c;
        getline(points[i],points[i+1],a,b,c);
        cut(a,b,c);
    }*/

//    如果要向内推进r，用该部分代替上个函数
    for(int i = 1; i <= m; ++i){
        point ta, tb, tt;
        tt.x = points[i+1].y - points[i].y;
        tt.y = points[i].x - points[i+1].x;
        double k = r / sqrt(tt.x * tt.x + tt.y * tt.y);
        tt.x = tt.x * k;
        tt.y = tt.y * k;
        ta.x = points[i].x + tt.x;
        ta.y = points[i].y + tt.y;
        tb.x = points[i+1].x + tt.x;
        tb.y = points[i+1].y + tt.y;
        double a,b,c;
        getline(ta,tb,a,b,c);
        cut(a,b,c);
    }
   //多边形核的面积
	area = 0;

    for(int i = 1; i <= curCnt; ++i){
        area += p[i].x * p[i + 1].y - p[i + 1].x * p[i].y;
}

    area = fabs(area / 2.0);

}
void GuiZhengHua(){
     //规整化方向，逆时针变顺时针，顺时针变逆时针
    for(int i = 1; i < (m+1)/2; i ++)
      swap(points[i], points[m-i]);
}
int main()
{
    int t;
	cin >> t;
	while(t--){
        cin>>m;
        for(int i=1;i<=m;i++)cin>>points[i].x>>points[i].y;
       // GuiZhengHua();
        points[m+1]=points[1];
        solve();
        printf("%.2f\n",area);
        }

}
