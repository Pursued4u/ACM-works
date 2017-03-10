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
int main()
{
    int t=Read();
    int ca=1;
    int a[5];
    int b[5];
    while(t--)
    {
        rep(i,1,5) a[i]=Read();
        rep(i,1,5) b[i]=Read();
        int flag=0;
        if(b[1]==a[1]&&b[2]==a[2]&&b[3]==a[3]&&b[4]==a[4])
        flag=1;
        else if(b[2]==a[1]&&b[4]==a[2]&&b[1]==a[3]&&b[3]==a[4])
        flag=1;
        else if(b[4]==a[1]&&b[3]==a[2]&&b[2]==a[3]&&b[1]==a[4])
        flag=1;
        else if(b[3]==a[1]&&b[1]==a[2]&&b[4]==a[3]&&b[2]==a[4])
        flag=1;
        printf("Case #%d: ",ca++);
        if(flag)
        cout << "POSSIBLE" <<endl;
        else
        cout << "IMPOSSIBLE" << endl;

    }
}
