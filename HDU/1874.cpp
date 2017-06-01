#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<vector>
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
#define sf(x) scanf("%d",&x)

using namespace std;
const int maxn = 2e2+5;
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
int m,n;
int mapp[maxn][maxn];
void init()
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            mapp[i][j]=(i==j?0:inf);
        }
    }
    for(int i=0;i<n;i++)
    {

        int a,b,v;
        scanf("%d %d %d",&a,&b,&v);
        mapp[a][b]=mapp[b][a]=min(v,mapp[a][b]);
    }
}
void floyd(int a,int b)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<m;j++)
        {
            for(int k=0;k<m;k++)
            {
                mapp[j][k]=min(mapp[j][k],mapp[j][i]+mapp[i][k]);
            }
        }
    }
    printf("%d\n",mapp[a][b]==inf?-1:mapp[a][b]);
}
int main()
{
    while(scanf("%d %d",&m,&n)!=EOF)
    {
        init();
        int a,b;
        scanf("%d %d",&a,&b);
        floyd(a,b);

    }

}
