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
ll q_pow(ll x , ll y)
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
ll ans1;
ll ans2;
ll tot;
int abss(int x)
{
    return x>=0?x:-x;
}
int a[maxn];
int main()
{
    int t=Read();
    while(t--)
    {
        int n=Read();
        ans1=0;
        ans2=0;
        ll flag=1;
        ll res=15;
        int p=1;
        tot=15*8+7+6+5+4+3+2;
        for(int i=1; i<=n; i++) a[i]=Read();
        for(int i=1; i<=n; i++)
        {

            if(tot<=0)
            {
                if(a[i]!=0)
                {
                    p=i;
                    break;
                }
            }
            else
            {

                if(res>0)
                {
                    if(!a[i])
                    {
                        flag*=-1;
                        tot=res*8+27;
                    }
                    if(a[i])
                    {
                        if(flag==1)
                        {
                            ans1+=a[i];
                            if(a[i]==1)
                            {
                                res--;
                                tot-=a[i];
                            }
                            else
                            {
                                tot=res*8+27;

                            }
                        }
                        else if(flag==-1)
                        {
                            ans2+=a[i];
                            if(a[i]==1)
                            {
                                res--;
                                tot-=a[i];
                            }
                            else
                            {
                                tot=res*8+27;
                            }
                        }
                    }
                }
                else
                {
                    if(flag==1)
                    {
                        ans1+=a[i];
                        tot-=a[i];

                    }
                    else
                    {
                        ans2+=a[i];
                        tot-=a[i];
                    }

                }
                dbg(tot);
                cout << i << " " << tot << " " << res << " "<< ans1 << " " << ans2 << endl;



            }




        }
        cout << p << endl;
    }
}
