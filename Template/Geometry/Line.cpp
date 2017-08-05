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
#define _ixvii0iv
using namespace std;
const int maxn = 3e2+5;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;

int Read()
{
    int x = 0, F = 1;
    char C = getchar();
    while (C < '0' || C > '9')
    {
        if (C == '-') F = -F;
        C = getchar();
    }
    while (C >= '0' && C <= '9')
    {
        x = x * 10 - '0' + C, C = getchar();
    }
    return x * F;

}

struct point
{
    db x,y;
    point() {};
    point (db _x,db _y)
    {
        x = _x;
        y = _y;
    }
    inline void input()
    {
        scanf("%lf %lf",&x,&y);
    }
};
point p[maxn],v[maxn*maxn];
inline int sgn(db x)
{
    return x<-eps?-1:x>eps?1:0;
}
typedef point line;

inline line operator +(line a,line b)
{
    return line(a.x+b.x,a.y+b.y);
}
inline line operator -(line a,line b)
{
    return line(a.x-b.x,a.y-b.y);
}
inline line operator *(line b,db a)
{
    return line(b.x*a,b.y*a);
}

inline line operator /(line b,db a)
{
    return line(b.x/a,b.y/a);
}
inline bool operator <(line a,line b)
{
    return (a.x<b.x)||a.x==b.x&&a.y<b.y;
}
inline bool operator ==(line a,line b)
{
    return !sgn(a.x-b.x)&&!sgn(a.y-b.y);
}
inline line Rotate(line a,db rad)//rad是弧度 负数表示顺时针 正数表示逆时针
{
    return line(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}

inline db Dot(line a,line b)
{
    return a.x*b.x+a.y*b.y;
}
inline db Cross(line a,line b)
{
    return a.x*b.y-a.y*b.x;
}
inline db area2(point a,point b,point c)
{
    return Cross(b-a,c-a);
}
inline db len(line a)
{
    return sqrt(Dot(a,a));
}
inline db Angle(line a,line b)
{
    return acos(Dot(a,b)/len(a)/len(b));
}

inline point GetlineIntersection(point p,line v,point q,line w) //两条直线的交点
{
    line tmp = p-q;
    db t = Cross(w,tmp)/Cross(v,w);
    return p+v*t;
}
inline db Distoline(point p,point a,point b){
	line v1 = b-a, v2 = p -a;
	return fabs(Cross(v1,v2))/len(v1);
}
inline db Distosegment(point p,point a,point b){
	if(a==b) return len(p-a);
	line v1 = b-a,v2 = p-a,v3 = p-b;
	if(sgn(Dot(v1,v2)) > 0) return len(v2);
	else if(sgn(Dot(v1,v3)) > 0) return len(v3);
	else return fabs(Cross(v1,v2))/len(v1);
}
inline bool SegmentIntersection(point a1,point a2,point b1,point b2){
	db c1 = Cross(a2-a1,b1-a1); db c2 = Cross(a2-a1,b2-a1);
	db c3 = Cross(b2-b1,a1-b1); db c4 = Cross(b2-b1,a2-b1);
	return sgn(c1)*sgn(c2)<0&&sgn(c3)*sgn(c4)<0;
}
inline bool OnSegment(point a,point p1,point p2){
	return !sgn(Cross(p1-a,p2-a))&&sgn(Dot(p1-a,p2-a))<0;
}

