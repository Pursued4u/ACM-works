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

inline db Dot(line a,line b)
{
    return a.x*b.x+a.y*b.y;
}
inline db len(line a)
{
    return sqrt(Dot(a,a));
}
inline line Normal(line a){
	double l = len(a);
	return line(-a.y/l,a.x/l);
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

inline db Cross(line a,line b)
{
    return a.x*b.y-a.y*b.x;
}
inline db area2(point a,point b,point c)
{
    return Cross(b-a,c-a);
}
inline db ang(line a){
	return atan2(a.y,a.x);
}

inline db Angle(line a,line b)
{
    return acos(Dot(a,b)/len(a)/len(b));
}
struct Vector{
	point a,v;
	Vector(){}
	Vector(point _a,point _v){
		a = _a;
		v = _v;
	}
	inline void input(){
		point t1,t2;
		t1.input();
		t2.input();
		a = t1;
		v = t2-t1;
	}
};

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
inline db real(db x){
	if(sgn(x)<0) x = x+PI;
	return x*180.0/PI;
}
struct circle{
	point c;
	double r;
	circle() {}
	circle(point _c,double _r){
		c = _c;
		r = _r;
	}
	point p(double a){
		return point(c.x +cos(a)*r,c.y+sin(a)*r);
	}
	inline void input(){
		c.input();
		scanf("%lf",&r);
	}
};

db v[maxn];
int getTangents(point p,circle c){
	line u = c.c-p;
	double dist = len(u);
	if(dist<c.r) return 0;
	else if(!sgn(dist-c.r)){
		v[0] = real(ang(Rotate(u,-PI/2)));
		return 1;
	}
	else {
		double an = asin(c.r/dist);
		v[0] = real(ang(Rotate(u, -an)));
		v[1] = real(ang(Rotate(u, +an)));
		return 2;
	}
}
void CircumscribedCircle(){
	point a,b,c;
	a.input();
	b.input();
	c.input();
	db a1 = b.x-a.x ,b1 = b.y-a.y,c1 = (a1*a1+b1*b1)/2;
	db a2 = c.x-a.x, b2 = c.y-a.y,c2 = (a2*a2+b2*b2)/2;
	db d = a1*b2 -a2*b1;
	point p = point(a.x+(c1*b2-c2*b1)/d,a.y+(a1*c2-a2*c1)/d);
	printf("(%.6f,%.6f,%.6f)\n",p.x,p.y,len(p-a));
}
void InscribedCircle(){
	point a,b,c;
	a.input();
	b.input();
	c.input();
	db a1 = len(b-c);
	db a2 = len(c-a);
	db a3 = len(a-b);
	point p = (a*a1+b*a2+c*a3)/(a1+a2+a3);
	printf("(%.6f,%.6f,%.6f)\n",p.x,p.y,Distoline(p,a,b));
}

void TanentLineThroughPoint(){
	circle c; c.input();
	point p; p.input();
	int num = getTangents (p,c);
	sort(v,v+num);
	putchar('[');
	for(int i=0;i<num;i++){
		printf("%.6f",(v[i]));
		if(i!=num-1) cout << ",";
	}
	puts("]");

}
void circlelineIntersection(circle c,Vector l,vector<point>&ve){
	db e = Dot(l.v,l.v);
	db f = Dot(l.a-c.c,l.v)*2;
	db g = Dot(l.a-c.c,l.a-c.c)-c.r*c.r;
	db delta = f*f-4*e*g;
	if(sgn(delta)<0) return;
	else if(!sgn(delta)){
		db t = -f/(2*e);
		ve.PB(l.v*t+l.a);
	}
	else{
		delta = sqrt(delta);
		db t1 = (-f+delta)/(2*e);
		db t2 = (-f-delta)/(2*e);
		ve.PB(l.v*t1+l.a);
		ve.PB(l.v*t2+l.a);
	}

}
void CircleThroughAPointAndTangentToALineWithRadius(){
	point p; p.input();
	Vector l; l.input();
	db r; scanf("%lf",&r);
	vector<point>ve;
	point v = Normal(l.v);
	circlelineIntersection(circle(p,r),Vector(l.a+v*r,l.v),ve);
	circlelineIntersection(circle(p,r),Vector(l.a-v*r,l.v),ve);
	sort(ve.begin(),ve.end());
	cout << "[";
	for(int i=0;i<ve.size();i++){
		printf("(%.6f,%.6f)",ve[i].x,ve[i].y);
		if(i!=ve.size()-1) cout <<",";
	}
	cout << "]\n";
}
void linelineIntersect(Vector l1, Vector l2, vector<point>&ve){
	db t = Cross((l2.a-l1.a),l2.v)/Cross(l1.v,l2.v);
	ve.PB(l1.a+l1.v*t);
}
void CircleTangentTotwoLinesWithRadius(){
	vector<point>ve;
	Vector l1,l2;
	db r;
	l1.input(); l2.input();
	scanf("%lf",&r);
	point p1 = Normal(l1.v);
	point p2 = Normal(l2.v);
	linelineIntersect(Vector(l1.a+p1*r,l1.v),Vector(l2.a+p2*r,l2.v),ve);
	linelineIntersect(Vector(l1.a+p1*r,l1.v),Vector(l2.a-p2*r,l2.v),ve);
	linelineIntersect(Vector(l1.a-p1*r,l1.v),Vector(l2.a+p2*r,l2.v),ve);
	linelineIntersect(Vector(l1.a-p1*r,l1.v),Vector(l2.a-p2*r,l2.v),ve);
	sort(ve.begin(),ve.end());
	cout << "[";
	for(int i=0;i<ve.size();i++){
		printf("(%.6f,%.6f)",ve[i].x,ve[i].y);
		if(i!=ve.size()-1) cout <<",";
	}
	cout << "]\n";


}
void circirIntersect(circle c1, circle c2,vector<point>&ve){
	point v = c2.c-c1.c;
	double d = len(v);
	if(sgn(d-c1.r-c2.r)>0) return;
	db ct = ang(v), alf = acos((c1.r*c1.r+d*d-c2.r*c2.r)/(2*c1.r*d));
	ve.PB(c1.p(ct+alf));
	if(sgn(alf)) ve.PB(c1.p(ct-alf));
}
void circletangentToTwoDisJointCirclesWithRadius(){
	vector<point>ve;
	circle c1,c2;db r;
	c1.input(); c2.input(); scanf("%lf",&r);
	circirIntersect(circle(c1.c,c1.r+r),circle(c2.c,c2.r+r),ve);
	sort(ve.begin(),ve.end());
	cout << "[";
	for(int i=0;i<ve.size();i++){
		printf("(%.6f,%.6f)",ve[i].x,ve[i].y);
		if(i!=ve.size()-1) cout <<",";
	}
	cout << "]\n";

}
int main(){
	string s;
	while(cin >> s){
			if(s=="CircumscribedCircle") CircumscribedCircle();
			else if(s=="InscribedCircle") InscribedCircle();
			else if(s=="TangentLineThroughPoint") TanentLineThroughPoint();
			else if(s=="CircleThroughAPointAndTangentToALineWithRadius") CircleThroughAPointAndTangentToALineWithRadius();
			else if(s=="CircleTangentToTwoLinesWithRadius") CircleTangentTotwoLinesWithRadius();
			else circletangentToTwoDisJointCirclesWithRadius();
	}
}
