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
const int maxn = 1e5+5;
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
    void input()
    {
        scanf("%lf %lf",&x,&y);
    }
};
int sgn(db x)
{
    return x<-eps?-1:x>eps?1:0;
}
typedef point line;

line operator +(line a,line b)
{
    return line(a.x+b.x,a.y+b.y);
}
line operator -(line a,line b)
{
    return line(a.x-b.x,a.y-b.y);
}
line operator *(line b,db a)
{
    return line(b.x*a,b.y*a);
}

line operator /(line b,db a)
{
    return line(b.x/a,b.y/a);
}
bool operator <(line a,line b)
{
    return (a.x<b.x)||a.x==b.x&&a.y<b.y;
}
bool operator ==(line a,line b)
{
    return !sgn(a.x-b.x)&&!sgn(a.y-b.y);
}
line Rotate(line a,db rad)//rad是弧度 负数表示顺时针 正数表示逆时针
{
    return line(a.x*cos(rad)-a.y*sin(rad),a.x*sin(rad)+a.y*cos(rad));
}

db Dot(line a,line b)
{
    return a.x*b.x+a.y*b.y;
}
db Cross(line a,line b)
{
    return a.x*b.y-a.y*b.x;
}
db area2(point a,point b,point c)
{
    return Cross(b-a,c-a);
}
db len(line a)
{
    return sqrt(Dot(a,a));
}
db Angle(line a,line b)
{
    return acos(Dot(a,b)/len(a)/len(b));
}

point GetlineIntersection(point p,line v,point q,line w)
{
    line tmp = p-q;
    db t = Cross(w,tmp)/Cross(v,w);
    return p+v*t;
}


int main()
{

#ifdef _ixvii0iv
    FILEIN;
#endif
    int t = Read();
    point a,b,c,d,e,f;
    while(t--)
    {
        a.input();
        b.input();
        c.input();
        d = get(a,b,c);
        e = get(b,c,a);
        f = get(c,a,b);
        printf("%.6f %.6f %.6f %.6f %.6f %.6f\n",e.x,e.y,f.x,f.y,d.x,d.y);



    }


}
