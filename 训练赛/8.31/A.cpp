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
#define MEM(a,x) memset(a,x,sizoef(a))
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
db diss(db x1,db y1,db x2,db y2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}
int main()
{
    FILEIN;
     int t=Read();
     int ca=1;
     while(t--)
     {


     db rx,ry,r;
     db x,y,dirx,diry;
     db ex,ey;
     scanf("%lf %lf %lf",&rx,&ry,&r);
     scanf("%lf %lf %lf %lf",&x,&y,&dirx,&diry);
     scanf("%lf %lf",&ex,&ey);
     db k1,k2;
     db dis;
     db a=rx;
     db b=ry;
     printf("Case #%d: ",ca++);
     int RA_x = x - rx, RA_y = y - ry;
     int RB_x = ex - rx, RB_y = ey - ry;
     int tt;
     if (RA_x == 0) swap(RA_x, RA_y);
     if (RB_x == 0) swap(RB_x, RB_y);
     tt = AO_x / AB_x;
     if (td*RB_y == RA_y && tt >= 0) flag = 1;
     if(diry==0)
     {
         k1=0;
         db c=y;
         db aa=k1*k1+1;
         db bb=2*k1*c-2*a-2*k1*b;
         db cc=rx*rx+ry*ry+c*c-r*r;
         if((bb*bb-4*aa*cc)<=0)
         {
            db k2=(ey-y)/(ex-x);
            if(k1==k2)
            cout << "Yes" << endl;
            else
            cout << "No" << endl;
         }
         else
         {
            db exx;
            db eyy;
            db xx;db yy;

            db x1=((-bb+sqrt(bb*bb-4*aa*cc))/(2*aa));
            db y1=sqrt(r*r-(x1-rx)*(x1-rx))+ry;
            db x2=((-bb-sqrt(bb*bb-4*aa*cc))/(2*aa));
            db y2=sqrt(r*r-(x2-rx)*(x2-rx))+ry;
            if(diss(x1,y1,x,y)<=diss(x2,y2,x,y))
            {
                xx=x1;
                yy=y1;
            }
            else
            {
                xx=x2;
                yy=y2;
            }
            if((xx-rx)==0)
            {
                    exx=xx+xx-x;
                    eyy=y;

            }
            else if((yy-ry)==0)
            {
                    exx=x;
                    eyy=2*yy-y;
            }
            else
            {

            db k3=(yy-ry)/(xx-rx);
            db c3=yy-k3*xx;
            db exx=x-2*k3*(k3*x+y+c3)/(1+k3*k3);
            db eyy=y-2*(k3*x+y+c3)/(1+k3*k3);
            }
            // xx yy为中点坐
            // exx eyy
            // x,y
            int AB_x = ex - x, AB_y = ey - y;
            int AO_x = xx - x, AO_y = yy - x;
            int OC_x = exx - xx, OC_y = eyy - yy;
            int OB_x = ex - xx, OB_y = ey - yy;
            int flag = 0;
            int td;
            if (AB_x == 0) swap(AB_x, AB_y);
            if (OB_x == 0) swap(OB_x, OB_y);
            td = AO_x / AB_x;
            if (td*AB_y == AO_y && td >= 1) flag = 1;
            td = OC_x / OB_x;
            if (td*OB_y == OC_y && td >= 0) flag = 1;
            if(flag)
            cout << "Yes" << endl;
            else
            cout << "No" << endl;


     }
     }
     else if(dirx==0)
     {
         if(x<rx-r||x>rx+r)
         {
                cout << "No" << endl;
         }
         else
         {
            db exx;
            db eyy;
            db xx;db yy;
            db x1=x;
            db y1=sqrt((r*r-(x-rx)*(x-rx)))+b;
            db x2=x;
            db y2=-sqrt((r*r-(x-rx)*(x-rx)))+b;
            if(diss(x1,y1,x,y)<=diss(x2,y2,x,y))
            {
                xx=x1;
                yy=y1;
            }
            else
            {
                xx=x2;
                yy=y2;
            }
            if((xx-rx)==0)
            {
                    exx=xx+xx-x;
                    eyy=y;

            }
            else if((yy-ry)==0)
            {
                    exx=x;
                    eyy=2*yy-y;
            }
            else
            {

            db k3=(yy-ry)/(xx-rx);
            db c3=yy-k3*xx;
            db exx=x-2*k3*(k3*x+y+c3)/(1+k3*k3);
            db eyy=y-2*(k3*x+y+c3)/(1+k3*k3);
            }
            // xx yy为中点坐
            // exx eyy
            // x,y

            int AB_x = ex - x, AB_y = ey - y;
            int AO_x = xx - x, AO_y = yy - x;
            int OC_x = exx - xx, OC_y = eyy - yy;
            int OB_x = ex - xx, OB_y = ey - yy;
            int flag = 0;
            int td;
            if (AB_x == 0) swap(AB_x, AB_y);
            if (OB_x == 0) swap(OB_x, OB_y);
            td = AO_x / AB_x;
            if (td*AB_y == AO_y && td >= 1) flag = 1;
            td = OC_x / OB_x;
            if (td*OB_y == OC_y && td >= 0) flag = 1;
            if(flag)
            cout << "Yes" << endl;
            else
            cout << "No" << endl;
     }
     }
     else
     {
         k1=diry/dirx;
         db c=y-k1*x;
         db aa=k1*k1+1;
         db bb=2*k1*c-2*a-2*k1*b;
         db cc=rx*rx+ry*ry+c*c-r*r;
         if((bb*bb-4*aa*cc)<=0)
         {
            db k2=(ey-y)/(ex-x);
            if(k1==k2)
            cout << "Yes" << endl;
            else
            cout << "No" << endl;
         }
         else
         {
            db exx;
            db eyy;
            db xx;db yy;
            db x1=((-bb+sqrt(bb*bb-4*aa*cc))/(2*aa));
            db y1=sqrt(r*r-(x1-rx)*(x1-rx))+ry;
            db x2=((-bb-sqrt(bb*bb-4*aa*cc))/(2*aa));
            db y2=sqrt(r*r-(x2-rx)*(x2-rx))+ry;
            if(diss(x1,y1,x,y)<=diss(x2,y2,x,y))
            {
                xx=x1;
                yy=y1;
            }
            else
            {
                xx=x2;
                yy=y2;
            }
            if((xx-rx)==0)
            {
                    exx=xx+xx-x;
                    eyy=y;

            }
            else if((yy-ry)==0)
            {
                    exx=x;
                    eyy=2*yy-y;
            }

            else
            {

            db k3=(yy-ry)/(xx-rx);
            db c3=yy-k3*xx;
            db exx=x-2*k3*(k3*x+y+c3)/(1+k3*k3);
            db eyy=y-2*(k3*x+y+c3)/(1+k3*k3);
            }
            // xx yy为中点坐
            // exx eyy
            // x,y
            dbg(exx);
            dbg(eyy);
            int AB_x = ex - x, AB_y = ey - y;
            int AO_x = xx - x, AO_y = yy - x;
            int OC_x = exx - xx, OC_y = eyy - yy;
            int OB_x = ex - xx, OB_y = ey - yy;
            int flag = 0;
            int td;
            dbg(OC_x);
            dbg(OC_y);
            if (AB_x == 0) swap(AB_x, AB_y);
            if (OB_x == 0) swap(OB_x, OB_y);
            td = AO_x / AB_x;
            if (td*AB_y == AO_y && td >= 1) flag = 1;
            td = OC_x / OB_x;
            if (td*OB_y == OC_y && td >= 0) flag = 1;
            if(flag)
            cout << "Yes" << endl;
            else
            cout << "No" << endl;
         }
     }

     }


}
