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
const int maxn = 1e6+5;
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
ll a[maxn];
ll b[maxn];
ll cnta[maxn];
ll cntb[maxn];
ll suma[maxn];
ll sumb[maxn];
int main()
{
    int n,m;
    int cas = 1;
    while (scanf("%d %d",&n,&m)!=EOF)
    {
        ll numa = 0;
        ll numb = 0;
        CLR(cnta);
        CLR(cntb);
        CLR(suma);
        CLR(sumb);
        for (int i = 0; i<n; i++)
        {
            scanf("%d",&a[i]);
        }
        for (int i = 0; i<m;i++)
        {
            scanf("%d",&b[i]);
        }
        for (int i =0 ;i<n;i++)
        {
            if (cnta[i]) continue;
            if (i==a[i]) numa++;
            else {
                int cnt = 1;
                int t = i;
                while (i!=a[t]) {t = a[t];cnt++;cnta[t] = 1;}
                suma[cnt]++;
            }
        }
        for (int i =0 ;i<m;i++)
        {
            if (cntb[i]) continue;
            if (i==b[i]) numb++;
            else {
                int cnt = 1;
                int t = i;
                while (i!=b[t]) {t = b[t];cnt++;cntb[t] = 1;}
                sumb[cnt]++;
            }
        }
        printf("Case #%d: ",cas++);
        ll ans = q_pow(numb,numa);
        ans%=mod;
        if (!numa) ans = 1;
        for (int i = 2; i<=n; i++)
        {
            if (suma[i]!=0) ans = (ans * (((((long long)i)*q_pow(sumb[i],suma[i]) % mod) + q_pow(numb,suma[i])) % mod)  )% mod;
        }
        printf("%I64d\n", ans);

    }
    return 0;
}
