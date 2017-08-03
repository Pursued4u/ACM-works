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
ll mul(ll x,ll y)
{
    return x*y%mod;
}
ll q_mul(ll a, ll b)
{
    ll ans = 0;
    while(b)
    {
        if(b & 1)
        {
            ans=(ans+a)%mod;
        }
        b>>=1;
        a=(a+a) % mod;
    }
    return ans;
}
ll q_pow(ll x, ll y)
{
    ll res=1;
    while(y)
    {
        if(y&1) res=q_mul(res,x) ;
        y>>=1 ;
        x=q_mul(x,x);
    }
    return res;
}
ll inv(ll x)
{
    return q_pow(x, mod-2);
}
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


struct Point
{
    int x, y;
} p[maxn];

int n, q, c;
int s;
ll a[15][105][105];
ll sum[11][105][105];
ll getsum(int t, int x1, int y1, int x2, int y2)
{
    ll res = 0;
    t %= (c + 1);
    for(int i=0;i<=c;i++){
        res+=((i+t)%(c+1))*(sum[i][x2][y2]-sum[i][x1-1][y2]+sum[i][x1-1][y1-1]-sum[i][x2][y1-1]);
    }
    return res;
}


int main()
{
    scanf("%d%d%d", &n, &q, &c);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d%d", &p[i].x, &p[i].y, &s);
        a[s][p[i].x][p[i].y]++;
    }
    for(int i = 0; i <= c; i++)
    {
        for(int ii = 1; ii <= 100; ii++)
        {
            for(int jj = 1; jj <= 100; jj++)
            {
                sum[i][ii][jj] = sum[i][ii][jj - 1] + sum[i][ii - 1][jj]-sum[i][ii-1][jj-1] + a[i][ii][jj];
            }
        }
    }
    for(int i = 1; i <= q; i++)
    {
        int t, x1, y1, x2, y2;
        t = Read();
        x1 = Read();
        y1 = Read();
        x2 = Read();
        y2= Read();
        printf("%I64d\n", getsum(t, x1, y1, x2, y2));
    }
    return 0;
}
