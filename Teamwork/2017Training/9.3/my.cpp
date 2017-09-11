#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<set>
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
#define endl '\n'
using namespace std;
const int maxn = 1e5+6e4;
typedef long long ll;
typedef double db;
const int inf = INT_MAX;
const ll INF = LLONG_MAX;
const ll mod = 1e9 + 7;
ll mul(ll x,ll y){return x*y%mod;}
ll q_mul(ll a, ll b){ ll ans = 0;while(b){if(b & 1){ans=(ans+a)%mod;} b>>=1;a=(a+a) % mod;}return ans;}
ll q_pow(ll x , ll y){ll res=1;while(y){if(y&1) res=q_mul(res,x) ; y>>=1 ; x=q_mul(x,x);} return res;}
ll inv(ll x) { return q_pow(x, mod-2); }
inline ll Read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct Point{
    int x, y, c;
    Point(){}
    Point(int x, int y, int c=0)
    :x(x), y(y), c(c){}
};
struct Rect{
    int l, r, s, h;
    Rect(int l=0, int r=0, int s=0, int h=0)
    :l(l),r(r),s(s),h(h){}
    bool in(Point p) {
        return l<=p.x&&p.x<=r&&s<=p.y&&p.y<=h;
    }
    bool have(Rect rt) {
        return l<=rt.l&&rt.r<=r&&s<=rt.s&&rt.h<=h;
    }
    bool cross(Rect rt) {
        Point p[4] = {Point(l, s), Point(l, h), Point(r, s), Point(r,h)};
        Point q[4] = {Point(rt.l, rt.s), Point(rt.l, rt.h), Point(rt.r, rt.s), Point(rt.r,rt.h)};
        for(int i=0; i<4; ++i) {
            if(rt.in(p[i])) return true;
            if(in(q[i])) return true;
        }
        return false;
    }
};
struct PaneTree{
    Rect rect[5];
    vector<Point> p;
    long long st;
    int ch[4], psz;
    PaneTree(){}
    PaneTree(Rect r) {
        p.reserve(0);
        rect[0]=r;
        int xmid=r.l+r.r>>1;
        int ymid=r.s+r.h>>1;
        rect[1]=Rect(r.l, xmid, r.s, ymid);
        rect[2]=Rect(r.l, xmid, ymid+1, r.h);
        rect[3]=Rect(xmid+1, r.r, r.s, ymid);
        rect[4]=Rect(xmid+1, r.r, ymid+1, r.h);
        p.clear();
        st=psz=0;
        CLR(ch);
    }
    int l() {
        return rect[0].l;
    int r() {
        return rect[0].r;
    }
    int s() {
        return rect[0].s;
    }
    int h() {
        return rect[0].h;
    }
    bool atom() {
        return l()==r()&&s()==h();
    }
}node[maxn*16];
int tot;
void init() {
    tot=1;
    node[1]=PaneTree(Rect(1, 1e6, 1, 1e6));
}

void Add(int o, Point p);
void push_down(int o) {
    int m=node[o].p.size();
    for(int i=0; i<m; ++i)
        Add(o, node[o].p[i]);
    node[o].psz=16;
    node[o].p.clear();
}
void Add(int o, Point p) {
    if(node[o].psz<16||node[o].atom()) {
        node[o].p.push_back(p);
        ++node[o].psz;
        node[o].st|=1ll<<p.c;
        if(node[o].psz==16&&!node[o].atom()) push_down(o);
    }
    else {
        ++node[o].psz;
        node[o].st|=1ll<<p.c;
        for(int i=1; i<5; ++i) {
            if(node[o].rect[i].in(p)) {
                int &u=node[o].ch[i-1];
                if(!u) node[u=++tot]=PaneTree(node[o].rect[i]);
                Add(u, p);
            }
        }
    }
}
void Add(int x, int y, int c) {
    Add(1, Point(x,y,c));
}
ll Ask(int o, Rect rect) {
    if(rect.have(node[o].rect[0]))
        return node[o].st;
    else if(node[o].psz<16||node[o].atom()) {
        int m=node[o].psz;
        ll ret=0;
        for(int i=0; i<m; ++i) {
            if(rect.in(node[o].p[i])) ret|= 1ll<<node[o].p[i].c;
        }
        return ret;
    }
    else {
        ll ret=0;
        for(int i=1; i<5; ++i) {
            if(rect.cross(node[o].rect[i])) {
                int nu=node[o].ch[i-1];
                if(nu) ret |= Ask(nu, rect);
            }
        }
    }
}
int Ask(int x, int y1, int y2) {
    Rect rect=Rect(1,x,y1, y2);
    long long res=Ask(1, rect);
    int ret=0;
    while(res) {
        if(res&1) ++ret;
        res>>=1;
    }
    return ret;
}
int main(){
    int cmd;
    while(~scanf("%d", &cmd)) {
        if(cmd==0) init();
        else if(cmd==3) break;
        else {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            if(cmd==1) Add(a,b,c);
            else printf("%d\n", Ask(a, b, c));
        }
    }
    return 0;
}
