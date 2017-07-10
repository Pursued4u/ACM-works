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
const int maxn = 1e6+5;
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
ll c[maxn];
int R;
ll getsum(int x)
{
    ll ans=0;
    while(x>0)
    {
        ans+=c[x];
        x-=lowbit(x);

    }
    return ans;
}
void update(int x,int h)
{
    while(x<=maxn)
    {
        c[x]+=h;
        x+=lowbit(x);
    }
}
ll ansr(ll j)
{
    return getsum(j)-getsum(j-1);
}



void solve() {
    CLR(c);
    scanf("%d",&R);
    int n;
    scanf("%d",&n);
    ll ans=0;
    while(n--)
    {
        ll x,y,w,h;
        scanf("%I64d %I64d %I64d %I64d",&x,&y,&w,&h);
        ans+=w*h;
        for(int i=x;i<x+w;i++)
        update(i+1,h);
    }
    ll sum=0;
    int j;
    for(int i=1;i<=R;i++)
    {
        sum=getsum(i);
       //cout << i <<" "<< sum << " " << ans <<endl;
        if(sum*2>=ans)
        {
            for(j=i+1;j<=R&&getsum(j)==sum;j++);
            cout << j-1 <<endl;
            break;
        }

    }
}

int main()
{
    FILEIN;
    int t;
    scanf("%d",&t);
    while(t--)
    {
        solve();
    }
}
