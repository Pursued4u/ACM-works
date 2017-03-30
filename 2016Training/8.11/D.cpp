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
#define sf(x) scanf("%d",&x)
#define PB(x) push_back(x)
#define MP(x, y) make_pair(x, y)
#define lowbit(x) x&(-x)
#define db double
#define rep(a,b,c) for(int (a)=(b);(a)<(c);(a)++)
#define drep(a,b,c) for(int (a)=(b);(a)>(c);--(a))
#define dbg(x) cout << #x << "=" << x << endl


using namespace std;
const int maxn = 1e4+5;
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

struct pos
{
    int v;
    int id;
}a[maxn];

bool cmp(const pos &a,const pos &b)
{
    return a.id<b.id;
}

int vis[maxn];
int b[maxn];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m,n;
        CLR(vis);
        scanf("%d %d",&m,&n);
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&a[i].v);
        }
        for(int i=1;i<=m;i++)
        {
            scanf("%d",&b[i]);
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(!vis[j]&&a[i].v==b[j])
                {
                    vis[j]=1;
                    a[i].id=j;
                    break;
                }

            }
        }
        while(n--)
        {
            int l,r;
            scanf("%d %d",&l,&r);
            sort(a+l,+a+r+1,cmp);
        }
        bool flag=true;
        for(int i=1;i<=m;i++)
        {
            if(b[i]!=a[i].v)
            {
                flag=false;
            }
        }
        if(flag)
        cout << "Yes" << endl;
        else
        cout << "No" << endl;

    }

}
