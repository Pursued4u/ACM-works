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
inline line Rotate(line a,db rad)//rad�ǻ��� ������ʾ˳ʱ�� ������ʾ��ʱ��
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

inline point GetlineIntersection(point p,line v,point q,line w) //����ֱ�ߵĽ���
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

/***********���ַ�������ֵ*************/
void solve()
{
    double L, R, m, mm, mv, mmv;
    while (L + eps < R)
    {
        m = (L + R) / 2;
        mm = (m + R) / 2;
        mv = calc(m);
        mmv = calc(mm);
        if (mv <= mmv) R = mm; //���ַ������ֵʱ��Ϊmv>=mmv
        else L = m;
    }
}
/*************����***********/
int dcmp(double x) {
  if(fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;
}
struct Point {
  double x, y;
  Point(double x=0, double y=0):x(x),y(y) { }
};

typedef Point Vector;

Vector operator + (Vector A, Vector B) { return Vector(A.x+B.x, A.y+B.y); }
Vector operator - (Point A, Point B) { return Vector(A.x-B.x, A.y-B.y); }
Vector operator * (Vector A, double p) { return Vector(A.x*p, A.y*p); }
Vector operator / (Vector A, double p) { return Vector(A.x/p, A.y/p); }

bool operator < (const Point& a, const Point& b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool operator == (const Point& a, const Point &b) {
  return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;
}

double Dot(Vector A, Vector B) { return A.x*B.x + A.y*B.y; }
double Length(Vector A) { return sqrt(Dot(A, A)); }
double Angle(Vector A, Vector B) { return acos(Dot(A, B) / Length(A) / Length(B)); }
double angle(Vector v) { return atan2(v.y, v.x); }
double Cross(Vector A, Vector B) { return A.x*B.y - A.y*B.x; }
/*
�������
�� P �� Q > 0 , ��P��Q��˳ʱ�뷽��
�� P �� Q < 0 , ��P��Q����ʱ�뷽��
�� P �� Q = 0 , ��P��Q���ߣ�������ͬ��Ҳ���ܷ���
*/
Vector vecunit(Vector x){ return x / Length(x);} //��λ����
Vector Normal(Vector x) { return Point(-x.y, x.x) / Length(x);} //��ֱ������
Vector Rotate(Vector A, double rad) {
  return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}
double Area2(const Point A, const Point B, const Point C) { return Length(Cross(B-A, C-A)); }

/****************ֱ�����߶�**************/

//��ֱ��p+tv��q+tw�Ľ��� Cross(v, w) == 0�޽���
Point GetLineIntersection(Point p, Vector v, Point q, Vector w)
{
    Vector u = p-q;
    double t = Cross(w, u) / Cross(v, w);
    return p + v*t;
}

//��p��ֱ��ab��ͶӰ
Point GetLineProjection(Point P, Point A, Point B) {
  Vector v = B-A;
  return A+v*(Dot(v, P-A) / Dot(v, v));
}

//�㵽ֱ�߾���
double DistanceToLine(Point P, Point A, Point B) {
  Vector v1 = B - A, v2 = P - A;
  return fabs(Cross(v1, v2)) / Length(v1); // �����ȡ����ֵ���õ������������
}
//����p�߶���
bool OnSegment(Point p, Point a1, Point a2) {
  return dcmp(Cross(a1-p, a2-p)) == 0 && dcmp(Dot(a1-p, a2-p)) < 0; //�߶ΰ����̵�ʱ�ĳ�<=
}
// ������p1, p2��ֱ��һ�㷽��ax+by+c=0
// (x2-x1)(y-y1) = (y2-y1)(x-x1)
void getLineGeneralEquation(const Point& p1, const Point& p2, double& a, double& b, double &c) {
  a = p2.y-p1.y;
  b = p1.x-p2.x;
  c = -a*p1.x - b*p1.y;
}
//�㵽�߶ξ���
double DistanceToSegment(Point p, Point a, Point b)
{
    if(a == b) return Length(p-a);
    Vector v1 = b-a, v2 = p-a, v3 = p-b;
    if(dcmp(Dot(v1, v2)) < 0) return Length(v2);
    else if(dcmp(Dot(v1, v3)) > 0) return Length(v3);
    else return fabs(Cross(v1, v2)) / Length(v1);
}
//���߶��������
double dis_pair_seg(Point p1, Point p2, Point p3, Point p4)
{
    return min(min(DistanceToSegment(p1, p3, p4), DistanceToSegment(p2, p3, p4)),
     min(DistanceToSegment(p3, p1, p2), DistanceToSegment(p4, p1, p2)));
}
//�߶��ཻ�ж�
bool SegmentItersection(Point a1, Point a2, Point b1, Point b2)
{
    double c1 = Cross(a2-a1, b1-a1), c2 = Cross(a2-a1, b2-a1),
    c3 = Cross(b2-b1, a1-b1), c4 = Cross(b2-b1, a2-b1);
    return dcmp(c1)*dcmp(c2) < 0 && dcmp(c3)*dcmp(c4) < 0;
}
// ����ֱ�ߡ�������߾��Ƕ�Ӧ�İ�ƽ��
struct Line {
  Point P;    // ֱ��������һ��
  Vector v;   // ��������
  double ang; // ���ǣ�����x��������ת������v����Ҫ�Ľǣ����ȣ�
  Line() {}
  Line(Point P, Vector v):P(P),v(v){ ang = atan2(v.y, v.x); }
   Point point(double a){
        return p+(v*a);
    }
  bool operator < (const Line& L) const {
    return ang < L.ang;
  }
};
//��ֱ�߽���
Point GetLineIntersection(Line a, Line b) {
  return GetLineIntersection(a.p, a.v, b.p, b.v);
}

// ��p������ֱ��L����ߣ����ϲ��㣩
bool OnLeft(const Line& L, const Point& p) {
  return Cross(L.v, p-L.P) > 0;
}

// ��ֱ�߽��㣬�ٶ�����Ωһ����
Point GetLineIntersection(const Line& a, const Line& b) {
  Vector u = a.P-b.P;
  double t = Cross(b.v, u) / Cross(a.v, b.v);
  return a.P+a.v*t;
}

// ��ƽ�潻������
vector<Point> HalfplaneIntersection(vector<Line> L) {
  int n = L.size();
  sort(L.begin(), L.end()); // ����������

  int first, last;         // ˫�˶��еĵ�һ��Ԫ�غ����һ��Ԫ�ص��±�
  vector<Point> p(n);      // p[i]Ϊq[i]��q[i+1]�Ľ���
  vector<Line> q(n);       // ˫�˶���
  vector<Point> ans;       // ���

  q[first=last=0] = L[0];  // ˫�˶��г�ʼ��Ϊֻ��һ����ƽ��L[0]
  for(int i = 1; i < n; i++) {
    while(first < last && !OnLeft(L[i], p[last-1])) last--;
    while(first < last && !OnLeft(L[i], p[first])) first++;
    q[++last] = L[i];
    if(fabs(Cross(q[last].v, q[last-1].v)) < eps) { // ������ƽ����ͬ��ȡ�ڲ��һ��
      last--;
      if(OnLeft(q[last], L[i].P)) q[last] = L[i];
    }
    if(first < last) p[last-1] = GetLineIntersection(q[last-1], q[last]);
  }
  while(first < last && !OnLeft(q[first], p[last-1])) last--; // ɾ������ƽ��
  if(last - first <= 1) return ans; // �ռ�
  p[last] = GetLineIntersection(q[last], q[first]); // ������β������ƽ��Ľ���

  // ��deque���Ƶ������
  for(int i = first; i <= last; i++) ans.push_back(p[i]);
  return ans;
}

/***********�����**************/
//������������
double PolygonArea(vector<Point> p) {
  int n = p.size();
  double area = 0;
  for(int i = 1; i < n-1; i++)
    area += Cross(p[i]-p[0], p[i+1]-p[0]);
  return area/2;
}

//��������� �㼯��ʱ�����
Point PolyGravity(Point *p, int n) {
    Point tmp, g = Point(0, 0);
    double sumArea = 0, area;
    for (int i=2; i<n; ++i) {
        area = Cross(p[i-1]-p[0], p[i]-p[0]);
        sumArea += area;
        tmp.x = p[0].x + p[i-1].x + p[i].x;
        tmp.y = p[0].y + p[i-1].y + p[i].y;
        g.x += tmp.x * area;
        g.y += tmp.y * area;
    }
    g.x /= (sumArea * 3.0); g.y /= (sumArea * 3.0);
    return g;
}

// �㼯͹��
// �����ϣ����͹���ı���������㣬������ <= �ĳ� <
// ע�⣺����㼯�ᱻ�޸�
vector<Point> ConvexHull(vector<Point>& p) {
  // Ԥ����ɾ���ظ���
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());

  int n = p.size();
  int m = 0;
  vector<Point> ch(n+1);
  for(int i = 0; i < n; i++) {
    while(m > 1 && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
    ch[m++] = p[i];
  }
  int k = m;
  for(int i = n-2; i >= 0; i--) {
    while(m > k && Cross(ch[m-1]-ch[m-2], p[i]-ch[m-2]) <= 0) m--;
    ch[m++] = p[i];
  }
  if(n > 1) m--;
  ch.resize(m);
  return ch;
}
//�жϵ��Ƿ��ڶ������
int isPointInPolygon(Point p, Polygon poly)
{
    int wn = 0;
    int n = poly.size();
    for (int i = 0; i < n; i++)
    {
        if (OnSegment(p, poly[i], poly[(i + 1) % n])) return -1;    //�߽�
        int k = dcmp(Cross(poly[(i + 1) % n] - poly[i], p - poly[i]));
        int d1 = dcmp(poly[i].y - p.y);
        int d2 = dcmp(poly[(i + 1) % n].y - p.y);
        if (k > 0 && d1 <= 0 && d2 > 0) wn++;
        if (k < 0 && d2 <= 0 && d1 > 0) wn--;
    }
    if (wn != 0) return 1;  //�ڲ�
    return 0;   //�ⲿ
}
// ͹��ֱ������ �㼯ֱ����ƽ��
int diameter2(vector<Point>& points) {
  vector<Point> p = ConvexHull(points);
  int n = p.size();
  if(n == 1) return 0;
  if(n == 2) return Dist2(p[0], p[1]);
  p.push_back(p[0]); // ���ȡģ
  int ans = 0;
  for(int u = 0, v = 1; u < n; u++) {
    // һ��ֱ����ס��p[u]-p[u+1]
    for(;;) {
      int diff = Cross(p[u+1]-p[u], p[v+1]-p[v]);
      if(diff <= 0) {
        ans = max(ans, Dist2(p[u], p[v])); // u��v�Ƕ����
        if(diff == 0) ans = max(ans, Dist2(p[u], p[v+1])); // diff == 0ʱu��v+1Ҳ�Ƕ����
        break;
      }
      v = (v + 1) % n;
    }
  }
  return ans;
}
//��͹���������
double RC_Distance(Point *ch1, Point *ch2, int n, int m)
{
    int q=0, p=0;
    REP(i, n) if(ch1[i].y-ch1[p].y < -eps) p=i;
    REP(i, m) if(ch2[i].y-ch2[q].y > eps) q=i;
    ch1[n]=ch1[0];  ch2[m]=ch2[0];

    double tmp, ans=1e100;
    REP(i, n)
    {
        while((tmp = Cross(ch1[p+1]-ch1[p], ch2[q+1]-ch1[p]) - Cross(ch1[p+1]-ch1[p], ch2[q]- ch1[p])) > eps)
            q=(q+1)%m;
        if(tmp < -eps) ans = min(ans,DistanceToSegment(ch2[q],ch1[p],ch1[p+1]));
        else ans = min(ans,dis_pair_seg(ch1[p],ch1[p+1],ch2[q],ch2[q+1]));
        p=(p+1)%n;
    }
    return ans;
}
//͹������ڽ�������
double RC_Triangle(Point* res,int n)// ͹������ڽ�������
{
     if(n<3)    return 0;
     double ans=0, tmp;
     res[n] = res[0];
     int j, k;
     REP(i, n)
     {
         j = (i+1)%n;
         k = (j+1)%n;
         while((j != k) && (k != i))
         {
              while(Cross(res[j] - res[i], res[k+1] - res[i]) > Cross(res[j] - res[i], res[k] - res[i])) k= (k+1)%n;
              tmp = Cross(res[j] - res[i], res[k] - res[i]);if(tmp > ans) ans = tmp;
              j = (j+1)%n;
         }
     }
     return ans;
}
//ģ���˻������� ������ptres��
double fermat_point(Point *pt, int n, Point& ptres)
{
    Point u, v;
    double step = 0.0, curlen, explen, minlen;
    int i, j, k, idx;
    bool flag;
    u.x = u.y = v.x = v.y = 0.0;
    REP(i, n)
    {
        step += fabs(pt[i].x) + fabs(pt[i].y);
        u.x += pt[i].x;
        u.y += pt[i].y;
    }
    u.x /= n;
    u.y /= n;
    flag = 0;
    while(step > eps)
    {
        for(k = 0; k < 10; step /= 2, ++k)
            for(i = -1; i <= 1; ++i)
                for(j = -1; j <= 1; ++j)
                {
                    v.x = u.x + step*i;
                    v.y = u.y + step*j;
                    curlen = explen = 0.0;
                        REP(idx, n)
                    {
                        curlen += dist(u, pt[idx]);
                        explen += dist(v, pt[idx]);
                    }
                    if(curlen > explen)
                    {
                        u = v;
                        minlen = explen;
                        flag = 1;
                    }
                }
    }
    ptres = u;
    return flag ? minlen : curlen;
}
//������
bool cmpxy(const Point& a, const Point& b)
{
    if(a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}
bool cmpy(const int& a, const int& b)
{
    return point[a].y < point[b].y;
}
double Closest_Pair(int left, int right)
{
    double d = INF;
    if(left==right)
        return d;
    if(left + 1 == right)
        return dis(left, right);
    int mid = (left+right)>>1;
    double d1 = Closest_Pair(left,mid);
    double d2 = Closest_Pair(mid+1,right);
    d = min(d1,d2);
    int i,j,k=0;
    //��������Ϊd������
    for(i = left; i <= right; i++)
    {
        if(fabs(point[mid].x-point[i].x) <= d)
            tmpt[k++] = i;
    }
    sort(tmpt,tmpt+k,cmpy);
    //����ɨ��
    for(i = 0; i < k; i++)
    {
        for(j = i+1; j < k && point[tmpt[j]].y-point[tmpt[i]].y<d; j++)
        {
            double d3 = dis(tmpt[i],tmpt[j]);
            if(d > d3)
                d = d3;
        }
    }
    return d;
}

/************Բ************/
struct Circle
{
    Point c;
    double r;
    Circle(){}
    Circle(Point c, double r):c(c), r(r){}
    Point point(double a) //����Բ�Ľ��������
    {
        return Point(c.x+cos(a)*r, c.y+sin(a)*r);
    }
};
//��a�㵽b��(��ʱ��)�ڵ�Բ�ϵ�Բ������
double D(Point a,Point b,int id)
{
    double ang1,ang2;
    Vector v1,v2;
    v1=a-Point(C[id].c.x,C[id].c.y);
    v2=b-Point(C[id].c.x,C[id].c.y);
    ang1=atan2(v1.y,v1.x);
    ang2=atan2(v2.y,v2.x);
    if(ang2<ang1) ang2+=2*pi;
    return C[id].r*(ang2-ang1);
}
//ֱ����Բ���� ���ظ���
int getLineCircleIntersection(Line L, Circle C, double& t1, double& t2, vector<Point>& sol){
  double a = L.v.x, b = L.p.x - C.c.x, c = L.v.y, d = L.p.y - C.c.y;
  double e = a*a + c*c, f = 2*(a*b + c*d), g = b*b + d*d - C.r*C.r;
  double delta = f*f - 4*e*g; // �б�ʽ
  if(dcmp(delta) < 0) return 0; // ����
  if(dcmp(delta) == 0) { // ����
    t1 = t2 = -f / (2 * e); sol.push_back(L.point(t1));
    return 1;
  }
  // �ཻ
  t1 = (-f - sqrt(delta)) / (2 * e); sol.push_back(L.point(t1));
  t2 = (-f + sqrt(delta)) / (2 * e); sol.push_back(L.point(t2));
  return 2;
}
//��Բ���� ���ظ���
int getCircleCircleIntersection(Circle C1, Circle C2, vector<Point>& sol) {
  double d = Length(C1.c - C2.c);
  if(dcmp(d) == 0) {
    if(dcmp(C1.r - C2.r) == 0) return -1; // �غϣ�����ཻ��
    return 0;
  }
  if(dcmp(C1.r + C2.r - d) < 0) return 0;
  if(dcmp(fabs(C1.r-C2.r) - d) > 0) return 0;

  double a = angle(C2.c - C1.c);
  double da = acos((C1.r*C1.r + d*d - C2.r*C2.r) / (2*C1.r*d));
  Point p1 = C1.point(a-da), p2 = C1.point(a+da);

  sol.push_back(p1);
  if(p1 == p2) return 1;
  sol.push_back(p2);
  return 2;
}
//P��Բ������
//v[i]�ǵ�i�����ߵ�����, ����������
int getTangents(Point p, Circle C, Vector* v)
{
    Vector u = C.c - p;
    double dist = Length(u);
    if (dist < C.r) return 0;
    else if (dcmp(dist - C.r) == 0)
    {
        //P��Բ��,ֻ��һ������
        v[0] = Rotate(u, PI / 2);
        return 1;
    }
    else
    {
        double ang = asin(C.r / dist);
        v[0] = Rotate(u, -ang);
        v[1] = Rotate(u, +ang);
        return 2;
    }
}

//��Բ�Ĺ�����, -1��ʾ����������
int getTangents(Circle A, Circle B, Point* a, Point* b)
{
    int cnt = 0;
    if (A.r < B.r) swap(A, B), swap(a, b);
    ///****************************
    int d2 = (A.c.x - B.c.x) * (A.c.x - B.c.x) + (A.c.y - B.c.y) * (A.c.y - B.c.y);
    int rdiff = A.r - B.r;
    int rsum = A.r + B.r;
    if (d2 < rdiff * rdiff) return 0;   //�ں�

    ///***************************************
    double base = atan2(B.c.y - A.c.y, B.c.x - A.c.x);
    if (d2 == 0 && A.r == B.r) return -1;    //���߶�������
    if (d2 == rdiff * rdiff)    //����, 1������
    {
        ///**********************
        a[cnt] = A.point(base); b[cnt] = B.point(base); cnt++;
        return 1;
    }
    //���⹫����
    double ang = acos((A.r - B.r) / sqrt(d2));
    a[cnt] = A.point(base + ang); b[cnt] = B.point(base + ang); cnt++;
    a[cnt] = A.point(base - ang); b[cnt] = B.point(base - ang); cnt++;
    if (d2 == rsum * rsum)  //һ���ڹ�����
    {
        a[cnt] = A.point(base); b[cnt] = B.point(PI + base); cnt++;
    }
    else if (d2 > rsum * rsum)  //�����ڹ�����
    {
        double ang = acos((A.r + B.r) / sqrt(d2));
        a[cnt] = A.point(base + ang); b[cnt] = B.point(PI + base + ang); cnt++;
        a[cnt] = A.point(base - ang); b[cnt] = B.point(PI + base - ang); cnt++;
    }
    return cnt;
}

//���������Բ
Circle CircumscribedCircle(Point p1, Point p2, Point p3) {
  double Bx = p2.x-p1.x, By = p2.y-p1.y;
  double Cx = p3.x-p1.x, Cy = p3.y-p1.y;
  double D = 2*(Bx*Cy-By*Cx);
  double cx = (Cy*(Bx*Bx+By*By) - By*(Cx*Cx+Cy*Cy))/D + p1.x;
  double cy = (Bx*(Cx*Cx+Cy*Cy) - Cx*(Bx*Bx+By*By))/D + p1.y;
  Point p = Point(cx, cy);
  return Circle(p, Length(p1-p));
}

//����������Բ
Circle InscribedCircle(Point p1, Point p2, Point p3) {
  double a = Length(p2-p3);
  double b = Length(p3-p1);
  double c = Length(p1-p2);
  Point p = (p1*a+p2*b+p3*c)/(a+b+c);
  return Circle(p, DistanceToLine(p, p1, p2));
}

// ����p��ԲC�����ߡ�v[i]�ǵ�i�����ߵ�������������������
int getTangents(Point p, Circle C, Vector* v) {
  Vector u = C.c - p;
  double dist = Length(u);
  if(dist < C.r) return 0;
  else if(dcmp(dist - C.r) == 0) { // p��Բ�ϣ�ֻ��һ������
    v[0] = Rotate(u, PI/2);
    return 1;
  } else {
    double ang = asin(C.r / dist);
    v[0] = Rotate(u, -ang);
    v[1] = Rotate(u, +ang);
    return 2;
  }
}

//���о�����p �뾶Ϊr ����ֱ��L���е�Բ��
vector<Point> CircleThroughPointTangentToLineGivenRadius(Point p, Line L, double r) {
  vector<Point> ans;
  double t1, t2;
  getLineCircleIntersection(L.move(-r), Circle(p, r), t1, t2, ans);
  getLineCircleIntersection(L.move(r), Circle(p, r), t1, t2, ans);
  return ans;
}

//�뾶Ϊr ��a b��ֱ�����е�Բ��
vector<Point> CircleTangentToLinesGivenRadius(Line a, Line b, double r) {
  vector<Point> ans;
  Line L1 = a.move(-r), L2 = a.move(r);
  Line L3 = b.move(-r), L4 = b.move(r);
  ans.push_back(GetLineIntersection(L1, L3));
  ans.push_back(GetLineIntersection(L1, L4));
  ans.push_back(GetLineIntersection(L2, L3));
  ans.push_back(GetLineIntersection(L2, L4));
  return ans;
}

//����Բ���� �뾶Ϊr������Բ��
vector<Point> CircleTangentToTwoDisjointCirclesWithRadius(Circle c1, Circle c2, double r) {
  vector<Point> ans;
  Vector v = c2.c - c1.c;
  double dist = Length(v);
  int d = dcmp(dist - c1.r -c2.r - r*2);
  if(d > 0) return ans;
  getCircleCircleIntersection(Circle(c1.c, c1.r+r), Circle(c2.c, c2.r+r), ans);
  return ans;
}

//�������Բ�ཻ���
Point GetIntersection(Line a, Line b) //�߶ν���
{
    Vector u = a.p-b.p;
    double t = Cross(b.v, u) / Cross(a.v, b.v);
    return a.p + a.v*t;
}
bool InCircle(Point x, Circle c) { return dcmp(c.r - Length(c.c - x)) >= 0;}
bool OnCircle(Point x, Circle c) { return dcmp(c.r - Length(c.c - x)) == 0;}
//�߶���Բ�Ľ���
int getSegCircleIntersection(Line L, Circle C, Point* sol)
{
    Vector nor = normal(L.v);
    Line pl = Line(C.c, nor);
    Point ip = GetIntersection(pl, L);
    double dis = Length(ip - C.c);
    if (dcmp(dis - C.r) > 0) return 0;
    Point dxy = vecunit(L.v) * sqrt(sqr(C.r) - sqr(dis));
    int ret = 0;
    sol[ret] = ip + dxy;
    if (OnSegment(sol[ret], L.p, L.point(1))) ret++;
    sol[ret] = ip - dxy;
    if (OnSegment(sol[ret], L.p, L.point(1))) ret++;
    return ret;
}
double SegCircleArea(Circle C, Point a, Point b) //�߶��и�Բ
{
    double a1 = angle(a - C.c);
    double a2 = angle(b - C.c);
    double da = fabs(a1 - a2);
    if (da > PI) da = PI * 2.0 - da;
    return dcmp(Cross(b - C.c, a - C.c)) * da * sqr(C.r) / 2.0;
}

double PolyCiclrArea(Circle C, Point *p, int n)//�������Բ�ཻ���
{
    double ret = 0.0;
    Point sol[2];
    p[n] = p[0];
    REP(i, n)
    {
        double t1, t2;
        int cnt = getSegCircleIntersection(Line(p[i], p[i+1]-p[i]), C, sol);
        if (cnt == 0)
        {
            if (!InCircle(p[i], C) || !InCircle(p[i+1], C)) ret += SegCircleArea(C, p[i], p[i+1]);
            else ret += Cross(p[i+1] - C.c, p[i] - C.c) / 2.0;
        }
        if (cnt == 1)
        {
            if (InCircle(p[i], C) && !InCircle(p[i+1], C)) ret += Cross(sol[0] - C.c, p[i] - C.c) / 2.0, ret += SegCircleArea(C, sol[0], p[i+1]);
            else ret += SegCircleArea(C, p[i], sol[0]), ret += Cross(p[i+1] - C.c, sol[0] - C.c) / 2.0;
        }
        if (cnt == 2)
        {
            if ((p[i] < p[i + 1]) ^ (sol[0] < sol[1])) swap(sol[0], sol[1]);
            ret += SegCircleArea(C, p[i], sol[0]);
            ret += Cross(sol[1] - C.c, sol[0] - C.c) / 2.0;
            ret += SegCircleArea(C, sol[1], p[i+1]);
        }
    }
    return fabs(ret);
}

/*********����ģ��*********/
//����ģ���������ϣ���δʹ�ù�
//pick����
LL x_mult(cpoint a,cpoint b,cpoint p)
{
    return (a.x-p.x)*(b.y-p.y)-(a.y-p.y)*(b.x-p.x);
}
LL pick()
{
    LL s =0, e = 0;
    for(int i=0;i<n;i++)
    {
        s += x_mult(re[i],re[i+1],re[0]);
        e += gcd(abs(re[i].y-re[i+1].y),abs(re[i].x-re[i+1].x));
    }e/=2;s/=2;
    return Abs(s)+1-e;
}

//�����жϵ��Ƿ���͹����
struct POINT{
    double x,y;
    POINT(double _x = 0, double _y = 0):x(_x),y(_y){};
    void show(){
        cout<<x<<" "<<y<<endl;
    }
};
POINT p[MAXN],wp[MAXN];
double multiply(POINT sp,POINT ep,POINT op){ //���
    return (sp.x-op.x) * (ep.y-op.y) - (ep.x-op.x) * (sp.y-op.y);
}
bool onseg(POINT a,POINT s,POINT e){   // �жϵ��Ƿ����߶���
    if(multiply(a,s,e) == 0 && a.x <= max(s.x,e.x) && a.x >= min(s.x,e.x)
       && a.y <= max(s.y,e.y) && a.y >= min(s.y,e.y))
        return true;
    return false;
}
bool inside(POINT pp,POINT sp,POINT ep,POINT op){ //�жϵ�pp�Ƿ�����������(������)
    if(onseg(pp,sp,ep) || onseg(pp,sp,op) || onseg(pp,ep,op)) //�������������
        return true;
    if(multiply(sp,ep,pp) > 0 && multiply(ep,op,pp) > 0
       && multiply(sp,op,pp) < 0)  //�������������
           return true;
    return false;
}
bool bsearch(POINT a,int len)
{    //�����������������
    int l = 1,r = len,m;
    while(l < r){
        m = (l + r) / 2;
        if(inside(a,p[0],p[m],p[m+1]) == true) return true;
        if(multiply(p[0],p[m],a) >= 0 && multiply(p[0],p[m+1],a) <= 0
            && multiply(p[m],p[m+1],a) < 0) return false;
        if(multiply(p[0],p[m],a) > 0 && multiply(p[0],p[m+1],a) > 0)
            l = m + 1;
        else r = m;
    }
    return false;
}
int main()
{
    int n,m,k,tmp = 0,cnt = 0;
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 0 ; i < n ; i++)
        scanf("%lf%lf",&p[i].x,&p[i].y);
    p[n] = p[0];
    for(int i = 0 ; i < m ; i++){
        scanf("%lf%lf",&wp[i].x,&wp[i].y);
        if(bsearch(wp[i],n-1) == true) cnt++;
    }
    if(cnt >= k) printf("YES\n");
    else printf("NO\n");
    return 0;
}

//Բ�������
//Բ�������
//
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#define sqr(x) ((x)*(x))
using namespace std;

const int N = 1010;
const double eps = 1e-8;
const double pi = acos(-1.0);
double area[N];
int n;

int dcmp(double x) {
    if (x < -eps) return -1; else return x > eps;
}

struct cp {
    double x, y, r, angle;
    int d;
    cp(){}
    cp(double xx, double yy, double ang = 0, int t = 0) {
        x = xx;  y = yy;  angle = ang;  d = t;
    }
    void get() {
        scanf("%lf%lf%lf", &x, &y, &r);
        d = 1;//
    }
}cir[N], tp[N * 2];

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

void solve()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
        cir[i].get();
    memset(area, 0, sizeof(area));
    CirUnion(cir, n);
    //ȥ���ظ������
    for (int i = 1; i <= n; ++i) {
        area[i] -= area[i + 1];
    }
    //area[i]Ϊ�ص���i�ε����
    //tot Ϊ�����
    double tot = 0;
    for(int i=1; i<=n; i++) tot += area[i];
    printf("%f\n", tot);
}

//����������
#define PDI pair<double,int>
#define point pair<double,double>
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define zero 1e-8
#define maxN 502
#define maxp 5
point operator +(point a,point b) { return mp(a.x+b.x,a.y+b.y); }
point operator -(point a,point b) { return mp(a.x-b.x,a.y-b.y); }
double operator *(point a,point b) { return a.x*b.y-b.x*a.y; }
double operator ^(point a,point b) { return a.x*b.x+a.y*b.y; }
inline double cross(point o,point a,point b) { return (a-o)*(b-o); }
inline int cmp(double x) { if (fabs(x)<zero) return 0; return x>0? 1:-1; }

class Polygon
{
    private: int i; double s;
    public: int n; point p[maxp];
    point& operator[] (int idx) { return p[idx]; }
    void input() { for (i=0;i<n;i++) scanf("%lf %lf",&p[i].x,&p[i].y); p[n]=p[0]; }
    double Area() { for (s=0,i=0;i<n;i++) s+=p[i]*p[i+1]; return s/2; }
};

PDI s[maxN*maxp*2];
Polygon P[maxN];
double S,ts;
int N;
inline double seg(point o,point a,point b)
{
    if (cmp(b.x-a.x)==0) return (o.y-a.y)/(b.y-a.y);
    return (o.x-a.x)/(b.x-a.x);
}

double PolygonUnion()
{
    int M,c1,c2; double s1,s2,ret=0;
    for (int i=0;i<N;i++)
    for (int ii=0;ii<P[i].n;ii++)
    {
        M=0;
        s[M++]=mp(0.00,0);
        s[M++]=mp(1.00,0);
        for (int j=0;j<N;j++) if (i!=j)
        for (int jj=0;jj<P[j].n;jj++)
        {
            c1=cmp(cross(P[i][ii],P[i][ii+1],P[j][jj]));
            c2=cmp(cross(P[i][ii],P[i][ii+1],P[j][jj+1]));
            if (c1==0 && c2==0)
            {
                if (((P[i][ii+1]-P[i][ii])^(P[j][jj+1]-P[j][jj]))>0 && i>j)
                {
                    s[M++]=mp(seg(P[j][jj],P[i][ii],P[i][ii+1]),1);
                    s[M++]=mp(seg(P[j][jj+1],P[i][ii],P[i][ii+1]),-1);
                }
            }
            else
            {
                s1=cross(P[j][jj],P[j][jj+1],P[i][ii]);
                s2=cross(P[j][jj],P[j][jj+1],P[i][ii+1]);
                if (c1>=0 && c2<0) s[M++]=mp(s1/(s1-s2),1);
                else if (c1<0 && c2>=0) s[M++]=mp(s1/(s1-s2),-1);
            }
        }
        sort(s,s+M);
        double pre=min(max(s[0].x,0.0),1.0),now;
        double sum=0;
        int cov=s[0].y;
        for (int j=1;j<M;j++)
        {
            now=min(max(s[j].x,0.0),1.0);
            if (!cov) sum+=now-pre;
            cov+=s[j].y;
            pre=now;
        }
        ret+=P[i][ii]*P[i][ii+1]*sum;
    }
    return ret/2;
}

int main()
{
    scanf("%d\n",&N);
    for (int i=0;i<N;i++)
    {
        P[i].n=4;
        P[i].input();
        ts=P[i].Area();
        if (cmp(ts<0))
        {
            reverse(P[i].p,P[i].p+P[i].n);
            P[i][P[i].n]=P[i][0];
            ts=-ts;
        }
        S+=ts;
    }
    printf("%.9lf\n",S/PolygonUnion());
}

//��άƽ��һ��n���ڵ�ļ򵥶���Σ����������һ�����ݣ������������
const double eps = 1e-8;
const double pi = acos(-1.);
using namespace std;
int dblcmp( double x )
{
    if( fabs(x) < eps )    return 0;
    return x > 0 ? 1 : -1;
}
double nowAng;
struct point
{
    double x, y, a;
    point(){}
    point( double _x, double _y ) : x(_x), y(_y)
    {
        a = atan2(y, x);
    }
    bool operator<( const point p )    const
    {
        if( dblcmp(a-p.a) == 0 )
            return x*x+y*y < p.x*p.x+p.y*p.y;
        return a < p.a;
    }
} p[60000], O;
inline double dis( point a, point b )
{
    double dx = a.x-b.x;
    double dy = a.y-b.y;
    return sqrt(dx*dx+dy*dy);
}
inline double cross( point k, point a, point b )
{
    return (a.x-k.x)*(b.y-k.y) - (a.y-k.y)*(b.x-k.x);
}
point inter( point a1, point a2, double ang )
{
    point b1 = point(0, 0), b2 = point(cos(ang), sin(ang));
    double u = cross(a1, a2, b1), v = cross(a2, a1, b2);
    return point((b1.x*v+b2.x*u)/(v+u), (b1.y*v+b2.y*u)/(v+u));
}
struct line
{
    point a, b;
    line(){};
    line( point _a, point _b ) : a(_a), b(_b){};
    bool operator<( const line p )    const
    {
        if( fabs(a.x-p.a.x) < eps && fabs(a.y-p.a.y) < eps )
            return cross(a, b, p.b) < 0;
        point d1 = inter(a, b, nowAng);
        point d2 = inter(p.a, p.b, nowAng);
        return d1.x*d1.x+d1.y*d1.y < d2.x*d2.x+d2.y*d2.y;
    }
};
struct Event
{
    double ang;
    int id, st;
    line L;
    bool operator<( const Event p )    const
    {
        if( dblcmp(ang-p.ang) == 0 )
            return st > p.st;
        return ang < p.ang;
    }
} E[200000];
int c;
void add( point a, point b, int k )
{
    if( b < a )
        swap(a, b);
    E[c].ang = a.a, E[c].st = 1, E[c].L = line(a, b), E[c++].id = k;
    E[c].ang = b.a, E[c].st = 0, E[c++].id = k;
}
multiset<line> S;
multiset<line>::iterator itArr[100000];
inline double cal( line L, double d1, double d2 )
{
    point a = inter(L.a, L.b, d1);
    point b = inter(L.a, L.b, d2);
    return fabs(0.5*cross(O, a, b));
}
int main()
{
    int i, j, k, n;
    double d, t, ans, pre;
    while( scanf("%lf %lf", &O.x, &O.y) != EOF )
    {
        c = 0;
        scanf("%d", &n);
        for( i = 0; i < n; ++i )
        {
            scanf("%lf %lf", &p[i].x, &p[i].y);
            p[i].x -= O.x, p[i].y -= O.y;
            p[i].a = atan2(p[i].y, p[i].x);
        }
        O.x = O.y = 0;
        p[n] = p[0];
        for( i = k = 0; i < n; ++i )
        {
            d = fabs(p[i+1].a-p[i].a);
            if( d < pi )
                add(p[i], p[i+1], k++);
            else
            {
                point tmp = inter(p[i], p[i+1], pi);
                tmp.a = pi*dblcmp(p[i].a);
                add(p[i], tmp, k++);
                tmp.a = pi*dblcmp(p[i+1].a);
                add(p[i+1], tmp, k++);
            }
        }
        sort(E, E+c);
        S.clear();
        ans = 0;    pre = -pi;
        for( i = 0; i < c; ++i )
        {
            nowAng = E[i].ang;
            if( E[i].st )
            {
                if( S.size() > 0 )
                    ans += cal(*S.begin(), pre, E[i].ang);
                itArr[E[i].id] = S.insert(E[i].L);
            }
            else
            {
                ans += cal(*S.begin(), pre, E[i].ang);
                S.erase(itArr[E[i].id]);
            }
            pre = E[i].ang;
        }
        printf("%.10lf\n", ans);
    }
    return 0;
}
//��άƽ����n(0 < n <= 50000)���߶Σ�Ҫ���ж�n���߶��Ƿ���ڽ��㣬����У�����ཻ�߶εı�š�
#define MP make_pair
#define PI pair
#define FI first
#define SE second
#define PB push_back
#define SZ size()
const double eps = 1e-10;
const double pi = acos(-1.);
const int mod = 1000000007;
const int maxn = 50100;
const int INF = 99999999;
struct point
{
    int x, y;
    bool operator<( const point p )    const
    {
        if( x == p.x )    return y < p.y;
        return x < p.x;
    }
} L[maxn][2];
int tim;
struct eve
{
    int x, id, st;
    eve(){}
    eve( int _x, int _id, int _st ) : x(_x), id(_id), st(_st) {}
    bool operator<( const eve p )     const
    {
        if( p.x == x )    return st > p.st;
        return x < p.x;
    }
} E[maxn*2];

void getLine( point x, point y, double& a, double& b, double& c )
{
    a = y.y - x.y;
    b = x.x - y.x;
    c = y.x*x.y - x.x*y.y;
}
struct ele
{
    int id;
    double k, c;
    ele( int _id )
    {
        id = _id;
        if( L[id][0].x == L[id][1].x )
            k = 0, c = L[id][0].y;
        else
        {
            double A, B, C;
            getLine(L[id][0], L[id][1], A, B, C);
            k = -A/B, c = -C/B;
        }
    }
    bool operator<( const ele p )    const
    {
        return tim*k+c < tim*p.k+p.c;
    }
};
set<ele> S;
set<ele>::iterator itArr[maxn];
inline set<ele>::iterator preIt( set<ele>::iterator it )
{
    return it == S.begin() ? S.end() : --it;
}

inline set<ele>::iterator nxtIt( set<ele>::iterator it )
{
    return it == S.end() ? S.end() : ++it;
}

int cross( point& k, point& a, point& b )
{
    return (a.x-k.x)*(b.y-k.y) - (a.y-k.y)*(b.x-k.x);
}

int dot( point& k, point& a, point& b )
{
    return (a.x-k.x)*(b.x-k.x) + (a.y-k.y)*(b.y-k.y);
}

inline int sgn( int x )
{
    if( x > 0 )    return 1;
    if( x < 0 )    return -1;
    return x;
}

bool inter( int a, int b )
{
    int d1 = sgn(cross(L[a][0], L[a][1], L[b][0]));
    int d2 = sgn(cross(L[a][0], L[a][1], L[b][1]));
    int d3 = sgn(cross(L[b][0], L[b][1], L[a][0]));
    int d4 = sgn(cross(L[b][0], L[b][1], L[a][1]));
    if( (d1^d2)==-2 && (d3^d4)==-2 )    return 1;
    if( d1 == 0 && dot(L[b][0], L[a][0], L[a][1]) <= 0 )    return 1;
    if( d2 == 0 && dot(L[b][1], L[a][0], L[a][1]) <= 0 )    return 1;
    if( d3 == 0 && dot(L[a][0], L[b][0], L[b][1]) <= 0 )    return 1;
    if( d4 == 0 && dot(L[a][1], L[b][0], L[b][1]) <= 0 )    return 1;
    return 0;
}

bool solve( int n )
{
    sort(E, E+n);
    S.clear();
    for( int i = 0; i < n; ++i )
    {
        tim = E[i].x;
        int id = E[i].id;

        if( E[i].st == 1 )
        {
            ele t = ele(id);
            set<ele>::iterator nxt = S.lower_bound(t), pre = preIt(nxt);
            if( nxt != S.end() && inter((*nxt).id, id) )
            {
                printf("YES\n%d %d\n", (*nxt).id, id);
                return 1;
            }
            if( pre != S.end() && inter((*pre).id, id) )
            {
                printf("YES\n%d %d\n", (*pre).id, id);
                return 1;
            }
            itArr[id] = S.insert(nxt, t);
        }
        else
        {
            set<ele>::iterator pre = preIt( itArr[id] ), nxt = nxtIt( itArr[id] );
            if( pre != S.end() && nxt != S.end() && inter((*pre).id, (*nxt).id) )
            {
                printf("YES\n%d %d\n", (*pre).id, (*nxt).id);
                return 1;
            }
            S.erase(itArr[id]);
        }
    }

    return 0;
}

int main()
{
    srand(4);
    int T, cases = 1;
    int i, j, k, e;
    double A, B, C;
    int N, M;
    scanf("%d", &N);
    for( i = 1; i <= N; ++i )
    {
        scanf("%d %d %d %d", &L[i][0].x, &L[i][0].y, &L[i][1].x, &L[i][1].y);
        if( L[i][1] < L[i][0] )
            swap(L[i][0], L[i][1]);
    }
    for( i = 1, e = 0; i <= N; ++i )
    {
        E[e++] = eve(L[i][0].x, i, +1);
        E[e++] = eve(L[i][1].x, i, -1);
    }
    if( !solve(e) )
        puts("NO");
    return 0;
}


/*******��ά����*******/
#include <iostream>
#include <cstdio>
#include <cmath>
#define zero( x ) ( ( ( x ) > 0 ? ( x ) : -( x ) ) < eps )
const double eps = 1e-8;
struct point3
{
    double x, y, z;
};
struct line3
{
    point3 a, b;
};
struct plane3
{
    point3 a, b, c;
};
//���� Cross Product U * V
point3 xmult( point3 u, point3 v )
{
    point3 ret;
    ret.x = u.y * v.x - v.y * u.z;
    ret.y = u.z * v.x - u.x * v.z;
    ret.z = u.x * v.y - u.y * v.x;
    return ret;
}
//���� Dot Product U ? V
double dmult( point3 u, point3 v )
{
    return u.x * v.x + u.y * v.y + u.z * v.z;
}
//ʸ���� U - V
point3 subt( point3 u, point3 v )
{
    point3 ret;
    ret.x = u.x - v.x;
    ret.y = u.y - v.y;
    ret.z = u.z - v.z;
    return ret;
}
//ȡƽ�淨����
point3 pvec( plane3 s )
{
    return xmult( subt( s.a, s.b ), subt( s.b, s.c ) );
}
point3 pvec( point3 s1, point3 s2, point3 s3 )
{
    return xmult( subt( s1, s2 ), subt( s2, s3 ) );
}
//������룬������ȡ������С
double distance( point3 p1, point3 p2 )
{
    return sqrt( ( p1.x - p2.x ) * ( p1.x - p2.x ) + ( p1.y - p2.x ) * ( p1.y - p2.y ) + ( p1.z - p2.z ) * ( p1.z - p2.z ) );
}
//������С
double vlen( point3 p )
{
    return sqrt( p.x * p.x + p.y * p.y + p.z * p.z );
}
//�ж����㹲��
int dots_inline( point3 p1, point3 p2, point3 p3 )
{
    return vlen( xmult( subt( p1, p2 ), subt( p2, p3 ) ) ) < eps;
}
//�ж��ĵ㹲��
int dots_onplane( point3 a, point3 b, point3 c, point3 d )
{
    return zero( dmult( pvec( a, b, c ), subt( d, a ) ) );
}
//�ж����Ƿ����߶��ϣ������˵�͹���
int dot_online_in( point3 p, line3 l )
{
    return zero( vlen( xmult( subt( p, l.a ), subt( p, l.b ) ) ) ) && ( l.a.x - p.x ) * ( l.b.x - p.x ) < eps && ( l.a.y - p.y ) * ( l.b.y - p.y ) < eps && ( l.a.z - p.z ) * ( l.b.z - p.z ) < eps;
}
int dot_online_in( point3 p, point3 l1, point3 l2 )
{
    return zero( vlen( xmult( subt( p, l1 ), subt( p, l2 ) ) ) ) && ( l1.x - p.x ) * ( l2.x - p.x ) < eps && ( l1.y - p.y ) * ( l2.y - p.y ) < eps && ( l1.z - p.z ) * ( l2.z - p.z ) < eps;
}
//�ж����Ƿ����߶��ϣ��������˵�
int dot_online_ex( point3 p, line3 l )
{
    return dot_online_in( p, l ) && ( !zero( p.x - l.a.x ) || ! zero( p.y - l.a.y ) || !zero( p.z - l.a.z ) ) && ( !zero( p.x - l.b.x ) || !zero( p.y - l.b.y ) || !zero( p.z - l.b.z ) );
}
int dot_online_ex( point3 p, point3 l1, point3 l2 )
{
    return dot_online_in( p, l1, l2 ) && ( !zero( p.x - l1.x ) || !zero( p.y - l1.y ) || !zero( p.z - l1.z ) ) && ( !zero( p.x - l2.x ) || !zero( p.y - l2.y ) || !zero( p.z - l2.z ) );
}
//�ж����Ƿ��ڿռ��������ϣ������߽磬���㹲��������
int dot_inplane_in( point3 p, plane3 s )
{
    return zero( vlen( xmult( subt( s.a, s.b ), subt( s.a, s.c ) ) ) - vlen( xmult( subt( p, s.a ), subt( p, s.b ) ) ) - vlen( xmult( subt( p, s.b ), subt( p, s.c ) ) ) - vlen( xmult( subt( p, s.c ), subt( p, s.a ) ) ) );
}
int dot_inplane_in( point3 p, point3 s1, point3 s2, point3 s3 )
{
    return zero( vlen( xmult( subt( s1, s2 ), subt( s1, s3 ) ) ) - vlen( xmult( subt( p, s1 ), subt( p, s2 ) ) ) - vlen( xmult( subt( p, s2 ), subt( p, s3 ) ) ) - vlen( xmult( subt( p, s3 ), subt( p, s1 ) ) ) );
}
//�ж����Ƿ��ڿռ��������ϣ��������߽磬���㹲��������
int dot_inplane_ex( point3 p, plane3 s )
{
    return dot_inplane_in( p, s ) && vlen( xmult( subt( p, s.a ), subt( p, s.b ) ) ) > eps && vlen( xmult( subt( p, s.b ), subt( p, s.c ) ) ) > eps && vlen( xmult( subt( p, s.c ), subt( p, s.a ) ) ) > eps;
}
int dot_inplane_ex( point3 p, point3 s1, point3 s2, point3 s3 )
{
    return dot_inplane_in( p, s1, s2, s3 ) && vlen( xmult( subt( p, s1 ), subt( p, s2 ) ) ) > eps && vlen( xmult( subt( p, s2 ), subt( p, s3 ) ) ) > eps && vlen( xmult( subt( p, s3 ), subt( p, s1 ) ) ) > eps;
}
//�ж��������߶�ͬ�࣬�����߶��Ϸ���0��������������
int same_side( point3 p1, point3 p2, line3 l )
{
    return dmult( xmult( subt( l.a, l.b ), subt( p1, l.b ) ), xmult( subt( l.a, l.b ), subt( p2, l.b ) ) ) > eps;
}
int same_side( point3 p1, point3 p2, point3 l1, point3 l2 )
{
    return dmult( xmult( subt( l1, l2 ), subt( p1, l2 ) ), xmult( subt( l1, l2 ), subt( p2, l2 ) ) ) > eps;
}
//�ж��������߶���࣬����ƽ���Ϸ���0
int opposite_side( point3 p1, point3 p2, line3 l )
{
    return dmult( xmult( subt( l.a, l.b ), subt( p1, l.b ) ), xmult( subt( l.a, l.b ), subt( p2, l.b ) ) ) < -eps;

}  int opposite_side( point3 p1, point3 p2, point3 l1, point3 l2 )
{
    return dmult( xmult( subt( l1, l2 ), subt( p1, l2 ) ), xmult( subt( l1, l2 ), subt( p2, l2 ) ) ) < -eps;
}
//�ж�������ƽ��ͬ�࣬����ƽ���Ϸ���0
int same_side( point3 p1, point3 p2, plane3 s )
{
    return dmult( pvec( s ), subt( p1, s.a ) ) * dmult( pvec( s ), subt( p2, s.a ) ) > eps;
}
int same_side( point3 p1, point3 p2, point3 s1, point3 s2, point3 s3 )
{
    return dmult( pvec( s1, s2, s3 ), subt( p1, s1 ) ) * dmult( pvec( s1, s2, s3 ), subt( p2, s1 ) ) > eps;
}
//�ж�������ƽ����࣬����ƽ���Ϸ���0
int opposite_side( point3 p1, point3 p2, plane3 s )
{
    return dmult( pvec( s ), subt( p1, s.a ) ) * dmult( pvec( s ), subt( p2, s.a ) ) < -eps;
}
int opposite_side( point3 p1, point3 p2, point3 s1, point3 s2, point3 s3 )
{
    return dmult( pvec( s1, s2, s3 ), subt( p1, s1 ) ) * dmult( pvec( s1, s2, s3 ), subt( p2, s1 ) ) < eps;
}
//�ж���ֱ��ƽ��
int parallel( line3 u, line3 v )
{
    return vlen( xmult( subt( u.a, u.b ), subt( v.a, v.b ) ) ) < eps;
}
int parallel( point3 u1, point3 u2, point3 u3, point3 v1, point3 v2, point3 v3 )
{
    return vlen( xmult( pvec( u1, u2, u3 ), pvec( v1, v2, v3 ) ) ) < eps;
}
//�ж�ֱ����ƽ��ƽ��
int parallel( line3 l, plane3 s )
{
    return zero( dmult( subt( l.a, l.b ), pvec( s ) ) );
}
int parallel( point3 l1, point3 l2, point3 s1, point3 s2, point3 s3 )
{
    return zero( dmult( subt( l1, l2 ), pvec( s1, s2, s3 ) ) );
}
//�ж���ֱ�ߴ�ֱ
int perpendicular( line3 u, line3 v )
{
    return zero( dmult( subt( u.a, u.b ), subt( v.a, v.b ) ) );
}
int perpendicular( point3 u1, point3 u2, point3 v1, point3 v2 )
{
    return zero( dmult( subt( u1, u2 ), subt( v1, v2 ) ) );
}
//�ж���ƽ�洹ֱ
int perpendicular( plane3 u, plane3 v )
{
    return zero( dmult( pvec( u ), pvec( v ) ) );
}
int perpendicular( point3 u1, point3 u2, point3 u3, point3 v1, point3 v2, point3 v3 )
{
    return zero( dmult( pvec( u1, u2, u3 ), pvec( v1, v2, v3 ) ) );
}
//�ж�ֱ����ƽ��ƽ��
int perpendicular( line l, plane3 s )
{
    return vlen( xmult( subt( l.a, l.b ), pvec( s ) ) ) < eps;
}
int perpendicular( point3 l1, point3 l2, point3 s1, point3 s2, point3 s3 )
{
    return vlen( xmult( subt( l1, l2 ), pvec( s1, s2, s3 ) ) ) < eps;
}
//�ж���ֱ���ཻ�������˵�Ͳ����غ�
int intersect_in( line3 u, line3 v )
{
    if( !dots_onplane( u.a, u.b, v.a, v.b ) )
    return 0;
    if( !dotsinline( u.a, u.b, v.a ) || !dots_inline( u.a, u.b, v.b ) )
    return !same_side( u.a, u.b, v ) && !same_side( v.a, v.b, u );
    return dot_online_in( u.a, v ) || dot_online_in( u.b, v ) || dot_online_in( v.a, u ) || dot_online_in( v.b, u );
}
int intersect_in( point3 u1, point3 u2, opint3 v1, point3 v2 )
{

    if( !dots_onplane( u1, u2, v1, v2 ) )
    return 0;
    if( !dots_inline( u1, u2, v1 ) || !dots_inline( u1, u2, v2 ) )
    return !same_side( u1, u2, v1, v2 ) && !same_side( v1, v2, u1, u2 );
    return dot_online_in( u1, v1, v2 ) || dot_online_in( u2, v1, v2 ) || dot_online_in( v1, u1, u2 ) || dot_online_in( v2, u1, u2 );
}
//�ж����߶��ཻ���������˵�Ͳ����غ�
int intersect_ex( line3 u, line3 v )
{
    return dots_onplane( u.a, u.b, v.a, v.b ) && opposite_side( u.a, u.b, v ) && opposite_side( v.a, v.b, u );
}
int intersect_ex( point3 u1, point3 u2, point3 v1, point3 v2 )
{
    return dots_onplane( u1, u2, v1, v2 ) && opposite_side( u1, u2, v1, v2 ) && opposite_side( v1, v2, u1, u2 );
}
//�ж��߶���ռ��������ཻ���������ڱ߽�ͣ����֣�����
int intersect_in( line3 l, plane3 s )
{
    return !same_side( l.a, l.b, s ) && !same_side( s.a, s.b, l.a, l.b, s.c ) && !same_side( s.b, s.c, l.a, l.b, s.a ) && !same_side( s.c, s.a, l.a, l.b, s.b );
}

int intersect_in( point3 l1, point3 l2, point3 s1, point3 s2, point3 s3 )

{

    return !same_side( l1, l2, s1, s2, s3 ) && !same_side( s1, s2, l1, l2, s3 ) && !same_side( s2, s3, l1, l2, s1 ) && !same_side( s3, s1, l1, l2, s2 );

}

//�ж��߶���ռ��������ཻ�����������ڱ߽�ͣ����֣�����

int intersect_ex( line3 l, plane3 s )

{

    return opposite_side( l.a, l.b, s ) && opposite_side( s.a, s.b, l.a, l.b, s.c ) && opposite_side( s.b, s.c, l.a, l.b, s.a ) && opposite_side( s.c, s.a, l.a, l.b, s.b );

}

int intersect_ex( point3 l1, point3 l2, point3 s1, point3 s2, point3 s3 )

{

    return opposite_side( l1, l2, s1, s2, s3 ) && opposite_side( s1, s2, l1, l2, s3 ) && opposite_side( s2, s3, l1, l2, s1 ) && opposite_side( s3, s1, l1, l2, s2 );

}
//������ֱ�߽��㣬ע�������ж�ֱ���Ƿ����ƽ��
//�߶ν��������ж��߶��ཻ��ͬʱ����Ҫ�ж��Ƿ�ƽ�У�
point3 intersection( line3 u, line3 v )
{
    point3 ret = u.a;
    double t = ( ( u.a.x - v.a.x ) * ( v.a.y - v.b.y ) - ( u.a.y - v.a.y ) * ( v.a.x - v.b.x ) ) / ( ( u.a.x - u.b.x ) * ( v.a.y - v.b.y ) - ( u.a.y - u.b.y ) * ( v.a.x - v.b.x ) );
    ret.x += ( u.b.x - u.a.x ) * t;
    ret.y += ( u.b.y - u.a.y ) * t;
    ret.z += ( u.b.z - u.a.z ) * t;
    return ret;
}
point3 intersection( point3 u1, point3 u2, point3 v1, point3 v2 )
{
    point3 ret = u1;
    double t = ( ( u1.x - v1.x ) * ( v1.y - v2.y ) - ( u1.y - v1.y ) * ( v1.x - v2.x ) ) / ( ( u1.x - u2.x ) * ( v1.y - v2.y ) - ( u1.y - u2.y ) * ( v1.x - v2.x ) );
    ret.x += ( u2.x - u1.x ) * t;
    ret.y += ( u2.y - u1.y ) * t;
    ret.z += ( u2.z - u1.z ) * t;
    return ret;
}
//����ֱ����ƽ�潻�㣬ע�������ж��Ƿ�ƽ�У�����֤���㲻����
//�߶κͿռ������ν��������ж�
point3 intersection( line3 l, plane3 s )
{
    point3 ret = pvec( s );
    double t = ( ret.x * ( s.a.x - l.a.x ) + ret.y * ( s.a.y - l.a.y ) + ret.z * ( s.a.z - l.a.z ) ) / ( ret.x * ( l.b.x - l.a.x ) + ret.y * ( l.b.y - l.a.y ) + ret.z * ( l.b.z - l.a.z ) );
    ret.x = l.a.x + ( l.b.x - l.a.x ) * t;
    ret.y = l.a.y + ( l.b.y - l.a.y ) * t;
    ret.z = l.a.z + ( l.b.z - l.a.z ) * t;
    return ret;
}
point3 intersection( point3 l1, point3 l2, point3 s1, point3 s2, point3 s3 )
{
    point3 ret = pvec( s1, s2, s3 );
    double t = ( ret.x * ( s1.x - l1.x ) + ret.y * ( s1.y - l1.y ) + ret.z * ( s1.z - l1.z ) ) / ( ret.x * ( l2.x - l1.x ) + ret.y * ( l2.y - l1.y ) + ret.z * ( l2.z - l1.z ) );
    ret.x = l1.x + ( l2.x - l1.x ) * t;
    ret.y = l1.y + ( l2.y - l1.y ) * t;
    ret.z = l1.z + ( l2.z - l1.z ) * t;
    return ret;
}
//������ƽ�潻�ߣ�ע�������ж��Ƿ�ƽ�У�����֤���㲻����
line3 intersection( plane3 u, plane3 v )
{
    line3 ret;
    ret.a = parallel( v.a, v.b, u.a, u.b, u.c ) ? intersection( v.b, v.c, u.a, u.b, u.c ) : intersection( v.a, v.b, u.a, u.b, u.c );
    ret.b = parallel( v.c, v.a, u.a, u.b, u.c ) ? intersection( v.b, v.c, u.a, u.b, u.c ) : intersection( v.c, v.a, u.a, u.b, u.c );
    return ret;
}
line3 intersection( point3 u1, point3 u2, point3 u3, point3 v1, point3 v2, point3 v3 )
{
    line3 ret;
    ret.a = parallel( v1, v2, u1, u2, u3 ) ? intersection( v2, v3, u1, u2, u3 ) : intersection( v1, v2, u1, u2, u3 );
    ret.b = parallel( v3, v1, u1, u2, u3 ) ? intersection( v2, v3, u1, u2, u3 ) : intersection( v3, v1, u1, u2, u3 );
    return ret;
}
//�㵽ֱ�߾���
double ptoline( point3 p, line3 l )
{
    return vlen( xmult( subt( p, l.a ), subt( l.b, l.a ) ) ) / distance( l.a, l.b );
}
double ptoline( point3 p, opint3 l1, point3 l2 )
{
    return vlen( xmult( subt( p, l1 ), subt( l2, l1 ) ) ) / distance( l1, l2 );
}
//�㵽ƽ�����
double ptoplane( point3 p, plane3 s )
{
    return fabs( dmult( pvec( s ), subt( p, s.a ) ) ) / vlen( pvec( s ) );
}
double ptoplane( point3 p, point3 s1, point3 s2, point3 s3 )
{
    return fabs( dmult( pvec( s1, s2, s3 ), subt( p, s1 ) ) ) / vlen( pvec( s1, s2, s3 ) );
}
//ֱ�ߵ�ֱ�߾���
double linetoline( lien3 u, line3 v )
{
    point3 n = xmult( subt( u.a, u.b ), subt( v.a, v.b ) );
    return fabs( dmult( subt( u.a, v.a ), n ) ) / vlen( n );
}
double linetoline( point3 u1, point3 u2, point3 v1, point3 v2 )
{
    point3 n = xmult( subt( u1, u2 ), subt( v1, v2 ) );
    return fabs( dmult( subt( u1, v1 ), n ) ) / vlen( n );
}
//��ֱ�߼н� cos ֵ
double angle_cos( line3 u, line3 v )
{
    return dmult( subt( u.a, u.b ), subt( v.a, v.b ) ) / vlen( subt( u.a, u.b ) ) / vlen( subt( v.a, v.b ) );
}
double angle_cos( point3 u1, point3 u2, point3 v1, point3 v2 )
{
    return dmult( subt( u1, u2 ), subt( v1, v2 ) ) / vlen( sut( u1, u2 ) ) / vlen( subt( v1, v2 ) );
}
//��ƽ��н� cos ֵ
double angle_cos( plane3 u, plane3 v )
{
    return dmult( pvec( u ), pvec( v ) ) / vlen( pvec( u ) ) / vlen( pvec( v ) );
}
double angle_cos( point3 u1, point3 u2, point3 v1, point3 v2, point3 v3 )
{
    return dmult( pvec( u1, u2, u3 ), pvec( v1, v2, v3 ) ) / vlen( pvec( u1, u2, u3 ) ) / vlen( pvec( v1, v2, v3 ) );
}
//ֱ��ƽ��н� sin ֵ
double angle_sin( line3 l, plane3 s )

{
    return dmult( subt( l.a, l.b ), pvec( s ) ) / vlen( subt( l.a, l.b ) ) / vlen( pvec( s ) );
}
double angle_sin( point3 l1, point3 l2, point3 s1, point3 s2, point3 s3 )
{
    return dmult( subt( l1, l2 ), pvc( s1, s2, s3 ) ) / vlen( subt( l1, l2 ) ) / vlen( pvec( s1, s2, s3 ) );
}
