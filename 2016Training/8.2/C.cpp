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

using namespace std;
const int maxn = 1e6+5;
typedef long long ll;
const int inf = ((1ll<<29)-10);
const ll mod = 1000000007;
int mul(int x,int y){return 1LL*x*y%mod;}
int qpow(int x , int y){int res=1;while(y){if(y&1) res=mul(res,x) ; y>>=1 ; x=mul(x,x);} return res;}

ll a[maxn];
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {


    for(int i=1;i<=n;i++)
    {
        scanf("%I64d",&a[i]);

    }
    int flag=0;
    ll ans=0;
    ll sum=0;
    for(int i=n;i>0;i--)
    {
        if(!flag&&a[i]>=0)
        {
            ans++;
            flag=0;
        }
        else if(!flag&&a[i]<0)
        {
            ans++;
            flag=1;
            sum+=a[i];
        }
        if(flag)
        {
            sum+=a[i];
            if(sum>=0)
            {
                flag=0;
                sum=0;
            }
        }
    }
    cout << ans << endl;
}
}
