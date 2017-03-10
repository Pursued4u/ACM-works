#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
#include<stack>
#include<queue>
#define FILEIN freopen("in.txt", "r", stdin)
#define FILEOUT freopen("output.txt", "w", stdout)
#define CLOSEIO ios::sync_with_stdio(false)
#define PI acos(-1)
#define CLR(a) memset(a,0,sizeof(a))
#define MEM(a,x) memset(a,x,sizoef(a))
#define eps 1e-8
#define scf(x) scanf("%d",&x)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define db double
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl


using namespace std;
const int maxn = 5e4+5;
typedef long long ll;
const int inf = ((1ll<<29)-10);
const ll mod = 1000000007;
int mul(int x,int y){return 1LL*x*y%mod;}
int qpow(int x , int y){int res=1;while(y){if(y&1) res=mul(res,x) ; y>>=1 ; x=mul(x,x);} return res;}
int Read() {
    int x = 0, F = 1; char C = getchar();
    while (C < '0' || C > '9') { if (C == '-') F = -F; C = getchar(); }
    while (C >= '0' && C <= '9') { x = x * 10 - '0' + C, C = getchar(); }
    return x * F;
}
int a[maxn];

struct pos
{
    double x,y,z;
}b[maxn];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF&&n)
    {


    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    db ans=0;
    int p=1;
    for(int i=n-1;i>=0;)
    {
        if(a[i]>=a[i-1]+a[i-2])
        {
            i--;
        }
        else
        {

            b[p].x=a[i];
            b[p].y=a[i-1];
            b[p].z=a[i-2];
            i-=3;
            p++;
        }
    }
    for(int i=1;i<p;i++)
    {
        double x=b[i].x,y=b[i].y,z=b[i].z;

        ans+=0.5*x*y*sin(acos((x*x+y*y-z*z)/(2.0*x*y)));


    }
    printf("%.2f\n",ans);
    }
    }

